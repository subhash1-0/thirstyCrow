// Generated from /pastry-2.1/src/rice/environment/Environment.java

#pragma once

#include <rice/environment/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/Runnable.hpp>

struct default_init_tag;

class rice::environment::Environment_destroy_1
    : public virtual ::java::lang::Object
    , public virtual ::java::lang::Runnable
{

public:
    typedef ::java::lang::Object super;
    void run() override;

    // Generated
    Environment_destroy_1(Environment *Environment_this);
    static ::java::lang::Class *class_();
    Environment *Environment_this;

private:
    virtual ::java::lang::Class* getClass0();
    friend class Environment;
};
