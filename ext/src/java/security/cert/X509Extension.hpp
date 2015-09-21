// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/security/cert/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct java::security::cert::X509Extension
    : public virtual ::java::lang::Object
{

    virtual ::java::util::Set* getCriticalExtensionOIDs() = 0;
    virtual ::int8_tArray* getExtensionValue(::java::lang::String* arg0) = 0;
    virtual ::java::util::Set* getNonCriticalExtensionOIDs() = 0;
    virtual bool hasUnsupportedCriticalExtension() = 0;

    // Generated
    static ::java::lang::Class *class_();
};
