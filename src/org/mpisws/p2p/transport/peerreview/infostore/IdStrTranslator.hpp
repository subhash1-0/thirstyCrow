// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/infostore/IdStrTranslator.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/infostore/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct org::mpisws::p2p::transport::peerreview::infostore::IdStrTranslator
    : public virtual ::java::lang::Object
{
    virtual ::java::lang::Object* readIdentifierFromString(::java::lang::String* s) = 0;
    virtual ::java::lang::String* toString(::java::lang::Object* id) = 0;

    // Generated
    static ::java::lang::Class *class_();
    virtual ::java::lang::String* toString();
};
