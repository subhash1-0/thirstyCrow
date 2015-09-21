// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/security/fwd-pastry-2.1.hpp>
#include <javax/security/auth/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct java::security::Principal
    : public virtual ::java::lang::Object
{

    /*virtual bool equals(::java::lang::Object* arg0); (already declared) */
    virtual ::java::lang::String* getName() = 0;
    /*virtual int32_t hashCode(); (already declared) */
    virtual bool implies(::javax::security::auth::Subject* arg0);
    /*virtual ::java::lang::String* toString(); (already declared) */

    // Generated
    static ::java::lang::Class *class_();
};
