// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/PeerReviewCallback.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/replay/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/Destructable.hpp>
#include <org/mpisws/p2p/transport/peerreview/identity/IdentityTransportCallback.hpp>
#include <org/mpisws/p2p/transport/peerreview/infostore/StatusChangeListener.hpp>

struct org::mpisws::p2p::transport::peerreview::PeerReviewCallback
    : public virtual ::rice::Destructable
    , public virtual ::org::mpisws::p2p::transport::peerreview::identity::IdentityTransportCallback
    , public virtual ::org::mpisws::p2p::transport::peerreview::infostore::StatusChangeListener
{
    virtual void init_() = 0;
    virtual void storeCheckpoint(::rice::p2p::commonapi::rawserialization::OutputBuffer* buffer) /* throws(IOException) */ = 0;
    virtual bool loadCheckpoint(::rice::p2p::commonapi::rawserialization::InputBuffer* buffer) /* throws(IOException) */ = 0;
    virtual void getWitnesses(::java::lang::Object* subject, WitnessListener* callback) = 0;
    virtual ::java::util::Collection* getMyWitnessedNodes() = 0;
    virtual PeerReviewCallback* getReplayInstance(::org::mpisws::p2p::transport::peerreview::replay::Verifier* v) = 0;

    // Generated
    static ::java::lang::Class *class_();
};
