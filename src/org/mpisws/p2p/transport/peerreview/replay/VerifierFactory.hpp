// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/replay/VerifierFactory.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/history/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/replay/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct org::mpisws::p2p::transport::peerreview::replay::VerifierFactory
    : public virtual ::java::lang::Object
{
    virtual Verifier* getVerifier(::org::mpisws::p2p::transport::peerreview::history::SecureHistory* history, ::rice::p2p::commonapi::rawserialization::RawSerializable* localHandle, int64_t firstEntryToReplay, int64_t initialTime, ::java::lang::Object* extInfo) /* throws(IOException) */ = 0;

    // Generated
    static ::java::lang::Class *class_();
};
