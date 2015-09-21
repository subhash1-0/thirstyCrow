// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/TransportLayer.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <rice/Destructable.hpp>

struct org::mpisws::p2p::transport::TransportLayer
    : public virtual ::rice::Destructable
{
    virtual SocketRequestHandle* openSocket(::java::lang::Object* i, SocketCallback* deliverSocketToMe, ::java::util::Map* options) = 0;
    virtual MessageRequestHandle* sendMessage(::java::lang::Object* i, ::java::lang::Object* m, MessageCallback* deliverAckToMe, ::java::util::Map* options) = 0;
    virtual ::java::lang::Object* getLocalIdentifier() = 0;
    virtual void acceptSockets(bool b) = 0;
    virtual void acceptMessages(bool b) = 0;
    virtual void setCallback(TransportLayerCallback* callback) = 0;
    virtual void setErrorHandler(ErrorHandler* handler) = 0;

    // Generated
    static ::java::lang::Class *class_();
};
