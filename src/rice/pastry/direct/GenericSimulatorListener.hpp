// Generated from /pastry-2.1/src/rice/pastry/direct/GenericSimulatorListener.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/pastry/direct/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct rice::pastry::direct::GenericSimulatorListener
    : public virtual ::java::lang::Object
{
    virtual void messageSent(::java::lang::Object* m, ::java::lang::Object* from, ::java::lang::Object* to, int32_t delay) = 0;
    virtual void messageReceived(::java::lang::Object* m, ::java::lang::Object* from, ::java::lang::Object* to) = 0;

    // Generated
    static ::java::lang::Class *class_();
};
