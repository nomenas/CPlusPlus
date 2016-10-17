//
// Created by Naum Puroski on 17/10/2016.
//

#include <factory/ResourceFactory.h>

struct ConcreteResourceFactory {
    ConcreteResourceFactory() {
        ResourceFactory::SetFactory([](const ResourceConfig& config) -> Resource* {
            auto returnValue = new Resource(config.object);
            returnValue->name = config.name;
            return returnValue;
        });
    }
    ~ConcreteResourceFactory() {
        ResourceFactory::SetFactory(nullptr);
    }
};

static const ConcreteResourceFactory _concreteResourceFactory;