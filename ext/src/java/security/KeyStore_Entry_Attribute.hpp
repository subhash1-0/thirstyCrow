// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/security/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct java::security::KeyStore_Entry_Attribute
    : public virtual ::java::lang::Object
{

    virtual ::java::lang::String* getName() = 0;
    virtual ::java::lang::String* getValue() = 0;

    // Generated
    static ::java::lang::Class *class_();
};
