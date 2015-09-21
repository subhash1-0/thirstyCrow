// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/SocketRequestHandle.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/Cancellable.hpp>

struct org::mpisws::p2p::transport::SocketRequestHandle
    : public virtual ::rice::p2p::commonapi::Cancellable
{
    virtual ::java::lang::Object* getIdentifier() = 0;
    virtual ::java::util::Map* getOptions() = 0;

    // Generated
    static ::java::lang::Class *class_();
};
