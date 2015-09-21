// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/sourceroute/manager/SourceRouteManagerImpl.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/nio/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/sourceroute/manager/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/MessageRequestHandle.hpp>
#include <org/mpisws/p2p/transport/MessageCallback.hpp>
#include <java/nio/ByteBuffer.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::sourceroute::manager::SourceRouteManagerImpl_AddressManager_PendingMessage
    : public virtual ::java::lang::Object
    , public virtual ::org::mpisws::p2p::transport::MessageRequestHandle
    , public virtual ::org::mpisws::p2p::transport::MessageCallback
{

public:
    typedef ::java::lang::Object super;

private:
    ::java::nio::ByteBuffer* message {  };
    ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe {  };
    ::java::util::Map* options {  };
    ::rice::p2p::commonapi::Cancellable* cancellable {  };
protected:
    void ctor(::java::nio::ByteBuffer* message, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options);

public:
    bool cancel() override;
    ::java::util::Map* getOptions() override;
    ::java::lang::Object* getIdentifier() override;
    ::java::nio::ByteBuffer* getMessage() override;
    void ack(::org::mpisws::p2p::transport::MessageRequestHandle* msg) override;
    void sendFailed(::org::mpisws::p2p::transport::MessageRequestHandle* msg, ::java::lang::Exception* reason) override;
    virtual void fail(::java::lang::Exception* reason);

    // Generated
    SourceRouteManagerImpl_AddressManager_PendingMessage(SourceRouteManagerImpl_AddressManager *SourceRouteManagerImpl_AddressManager_this, ::java::nio::ByteBuffer* message, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options);
protected:
    SourceRouteManagerImpl_AddressManager_PendingMessage(SourceRouteManagerImpl_AddressManager *SourceRouteManagerImpl_AddressManager_this, const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    SourceRouteManagerImpl_AddressManager *SourceRouteManagerImpl_AddressManager_this;

private:
    virtual ::java::lang::Class* getClass0();
    friend class SourceRouteManagerImpl;
    friend class SourceRouteManagerImpl_AddressManager;
    friend class SourceRouteManagerImpl_AddressManager_PendingSocket;
    friend class SourceRouteManagerImpl_AddressManager_sendMessage_1;
    friend class SourceRouteManagerImpl_AddressManager_openSocket_2;
};
