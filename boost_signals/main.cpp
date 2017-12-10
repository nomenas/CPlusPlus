#include <iostream>
#include <thread>
#include <chrono>

#include <gtest/gtest.h>

#include <boost/signals2/signal.hpp>

using std::chrono_literals::operator""s;

static decltype(0s) update_sleep = 0s;

struct Foo
{
    boost::signals2::signal<void()> sig;
    boost::signals2::connection connection;

    Foo() {}

    Foo(Foo* parent) : Foo() {
        connection = parent->sig.connect([this](){update();});
    }

    ~Foo() {
        connection.disconnect();
    }

    void update() {
        std::this_thread::sleep_for(update_sleep);
    }
};

class BoostSignals : public ::testing::Test {
protected:
    virtual void SetUp() {
        update_sleep = 0s;
    }
};

TEST_F(BoostSignals, test_destory_parent_before_child) {
    std::unique_ptr<Foo> parent = std::make_unique<Foo>();
    std::unique_ptr<Foo> clone = std::make_unique<Foo>(parent.get());

    parent.reset();
    clone.reset();
}

TEST_F(BoostSignals, test_destory_child_before_parent) {
    std::unique_ptr<Foo> parent = std::make_unique<Foo>();
    std::unique_ptr<Foo> clone = std::make_unique<Foo>(parent.get());

    clone.reset();
    parent.reset();
}

TEST_F(BoostSignals, test_handle_message) {
    std::unique_ptr<Foo> parent = std::make_unique<Foo>();
    std::unique_ptr<Foo> clone = std::make_unique<Foo>(parent.get());

    parent->sig();
}

TEST_F(BoostSignals, test_destoy_child_while_processing_signal) {
    std::unique_ptr<Foo> parent = std::make_unique<Foo>();
    std::unique_ptr<Foo> clone = std::make_unique<Foo>(parent.get());

    update_sleep = 2s;

    std::thread thread([parent = parent.get()]() {
        parent->sig();
    });

    std::this_thread::sleep_for(1s);
    clone.reset();

    thread.join();
}

TEST_F(BoostSignals, test_destoy_parent_while_notifying_child) {
    std::unique_ptr<Foo> parent = std::make_unique<Foo>();
    std::unique_ptr<Foo> clone = std::make_unique<Foo>(parent.get());

    update_sleep = 2s;

    std::thread thread([parent = parent.get()]() {
        parent->sig();
    });

    std::this_thread::sleep_for(1s);
    parent.reset();

    thread.join();
}

TEST_F(BoostSignals, test_stress_update) {
    std::vector<std::unique_ptr<Foo>> parents;
    std::vector<std::unique_ptr<Foo>> children;

    for (int i = 0; i < 1000; ++i) {
        parents.emplace_back(new Foo{});
        children.emplace_back(new Foo{parents[i].get()});
    }

    std::thread parents_working_thread([&](){
        for (auto&& parent : parents) {
            parent->update();
            parent.reset();
        }
    });

    std::thread children_working_thread([&](){
        for (auto&& child : children) {
            child.reset();
        }
    });

    parents_working_thread.join();
    children_working_thread.join();
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
