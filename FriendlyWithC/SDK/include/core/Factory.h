//
// Created by Naum Puroski on 16/10/2016.
//

#ifndef FRIENDLYWITHC_FACTORY_H
#define FRIENDLYWITHC_FACTORY_H

#include <functional>

template <typename Product, typename Config>
class Factory {
    using Type = std::function<Product*(const Config&)>;

public:
    static Product* Create(const Config& config, Object::Observer observer = Object::Observer()) {
        Product* returnValue = instance().FactoryMethod(config);

        if (returnValue && observer) {
            returnValue->addObserver(observer);
            observer(Object::Created, -1, nullptr);
        }
        return returnValue;
    }

    static void SetFactory(Type factoryMethod) {
        instance().FactoryMethod = factoryMethod;
    }

private:
    static Factory<Product, Config>& instance() {
        static Factory<Product, Config> _instance;
        return _instance;
    }

    Type FactoryMethod;
};

#endif //FRIENDLYWITHC_FACTORY_H
