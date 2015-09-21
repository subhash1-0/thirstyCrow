// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/security/fwd-pastry-2.1.hpp>
#include <java/io/Serializable.hpp>

struct java::security::Key
    : public virtual ::java::io::Serializable
{
    static constexpr int64_t serialVersionUID { int64_t(6603384152749567654LL) };

    virtual ::java::lang::String* getAlgorithm() = 0;
    virtual ::int8_tArray* getEncoded() = 0;
    virtual ::java::lang::String* getFormat() = 0;

    // Generated
    static ::java::lang::Class *class_();
};
