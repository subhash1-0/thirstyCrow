// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/infostore/StatusChangeListener.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/infostore/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/StatusConstants.hpp>

struct org::mpisws::p2p::transport::peerreview::infostore::StatusChangeListener
    : public virtual ::org::mpisws::p2p::transport::peerreview::StatusConstants
{
    virtual void notifyStatusChange(::java::lang::Object* id, int32_t newStatus) = 0;

    // Generated
    static ::java::lang::Class *class_();
};
