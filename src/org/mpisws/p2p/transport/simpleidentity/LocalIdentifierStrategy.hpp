// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/simpleidentity/LocalIdentifierStrategy.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/simpleidentity/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct org::mpisws::p2p::transport::simpleidentity::LocalIdentifierStrategy
    : public virtual ::java::lang::Object
{
    virtual ::int8_tArray* getLocalIdentifierBytes() /* throws(IOException) */ = 0;

    // Generated
    static ::java::lang::Class *class_();
};
