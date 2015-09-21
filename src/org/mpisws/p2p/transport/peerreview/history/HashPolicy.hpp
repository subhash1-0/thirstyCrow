// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/history/HashPolicy.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/history/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct org::mpisws::p2p::transport::peerreview::history::HashPolicy
    : public virtual ::java::lang::Object
{
    virtual bool hashEntry(int16_t type, ::int8_tArray* content) = 0;

    // Generated
    static ::java::lang::Class *class_();
};
