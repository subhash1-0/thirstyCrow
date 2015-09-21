// Generated from /pastry-2.1/src/rice/environment/logging/AbstractLogManager.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/environment/params/ParameterChangeListener.hpp>

struct default_init_tag;

class rice::environment::logging::AbstractLogManager_AbstractLogManager_1
    : public virtual ::java::lang::Object
    , public virtual ::rice::environment::params::ParameterChangeListener
{

public:
    typedef ::java::lang::Object super;
    void parameterChange(::java::lang::String* paramName, ::java::lang::String* newVal) override;

    // Generated
    AbstractLogManager_AbstractLogManager_1(AbstractLogManager *AbstractLogManager_this);
    static ::java::lang::Class *class_();
    AbstractLogManager *AbstractLogManager_this;

private:
    virtual ::java::lang::Class* getClass0();
    friend class AbstractLogManager;
    friend class AbstractLogManager_NullOutputStream;
};
