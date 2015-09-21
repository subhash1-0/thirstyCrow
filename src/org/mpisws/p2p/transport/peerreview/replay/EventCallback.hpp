// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/replay/EventCallback.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/replay/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct org::mpisws::p2p::transport::peerreview::replay::EventCallback
    : public virtual ::java::lang::Object
{
    virtual void replayEvent(int16_t type, ::rice::p2p::commonapi::rawserialization::InputBuffer* entry) = 0;

    // Generated
    static ::java::lang::Class *class_();
};
