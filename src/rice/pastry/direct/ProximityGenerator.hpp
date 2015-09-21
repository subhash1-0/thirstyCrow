// Generated from /pastry-2.1/src/rice/pastry/direct/ProximityGenerator.java

#pragma once

#include <rice/environment/random/fwd-pastry-2.1.hpp>
#include <rice/pastry/direct/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct rice::pastry::direct::ProximityGenerator
    : public virtual ::java::lang::Object
{
    virtual NodeRecord* generateNodeRecord() = 0;
    virtual void setRandom(::rice::environment::random::RandomSource* random) = 0;

    // Generated
    static ::java::lang::Class *class_();
};
