// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/IdentifierExtractor.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct org::mpisws::p2p::transport::peerreview::IdentifierExtractor
    : public virtual ::java::lang::Object
{
    virtual ::java::lang::Object* extractIdentifier(::java::lang::Object* h) = 0;

    // Generated
    static ::java::lang::Class *class_();
};
