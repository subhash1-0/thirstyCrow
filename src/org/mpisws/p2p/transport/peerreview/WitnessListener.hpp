// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/WitnessListener.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct org::mpisws::p2p::transport::peerreview::WitnessListener
    : public virtual ::java::lang::Object
{
    virtual void notifyWitnessSet(::java::lang::Object* subject, ::java::util::Collection* witnesses) = 0;

    // Generated
    static ::java::lang::Class *class_();
};
