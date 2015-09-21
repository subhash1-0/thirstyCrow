// Generated from /pastry-2.1/src/rice/pastry/direct/NodeRecord.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <rice/pastry/direct/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct rice::pastry::direct::NodeRecord
    : public virtual ::java::lang::Object
{
    virtual float networkDelay(NodeRecord* nrb) = 0;
    virtual float proximity(NodeRecord* nrb) = 0;
    virtual void markDead() = 0;

    // Generated
    static ::java::lang::Class *class_();
};
