// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/sourceroute/manager/SourceRouteManagerImpl.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/sourceroute/manager/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/util/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/MessageCallback.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::sourceroute::manager::SourceRouteManagerImpl_AddressManager_sendMessage_1
    : public virtual ::java::lang::Object
    , public virtual ::org::mpisws::p2p::transport::MessageCallback
{

public:
    typedef ::java::lang::Object super;
    void ack(::org::mpisws::p2p::transport::MessageRequestHandle* msg) override;
    void sendFailed(::org::mpisws::p2p::transport::MessageRequestHandle* msg, ::java::lang::Exception* ex) override;

    // Generated
    SourceRouteManagerImpl_AddressManager_sendMessage_1(SourceRouteManagerImpl_AddressManager *SourceRouteManagerImpl_AddressManager_this, ::org::mpisws::p2p::transport::util::MessageRequestHandleImpl* handle, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe);
    static ::java::lang::Class *class_();
    SourceRouteManagerImpl_AddressManager *SourceRouteManagerImpl_AddressManager_this;
    ::org::mpisws::p2p::transport::util::MessageRequestHandleImpl* handle;
    ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe;

private:
    virtual ::java::lang::Class* getClass0();
    friend class SourceRouteManagerImpl;
    friend class SourceRouteManagerImpl_AddressManager;
    friend class SourceRouteManagerImpl_AddressManager_PendingSocket;
    friend class SourceRouteManagerImpl_AddressManager_PendingMessage;
    friend class SourceRouteManagerImpl_AddressManager_openSocket_2;
};
