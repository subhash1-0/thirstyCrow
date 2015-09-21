// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/sourceroute/manager/SourceRouteManagerImpl.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/sourceroute/manager/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/util/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/SocketCallback.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::sourceroute::manager::SourceRouteManagerImpl_AddressManager_openSocket_2
    : public virtual ::java::lang::Object
    , public virtual ::org::mpisws::p2p::transport::SocketCallback
{

public:
    typedef ::java::lang::Object super;
    void receiveResult(::org::mpisws::p2p::transport::SocketRequestHandle* cancellable, ::org::mpisws::p2p::transport::P2PSocket* sock) override;
    void receiveException(::org::mpisws::p2p::transport::SocketRequestHandle* s, ::java::lang::Exception* ex) override;

    // Generated
    SourceRouteManagerImpl_AddressManager_openSocket_2(SourceRouteManagerImpl_AddressManager *SourceRouteManagerImpl_AddressManager_this, ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe, ::org::mpisws::p2p::transport::util::SocketRequestHandleImpl* handle);
    static ::java::lang::Class *class_();
    SourceRouteManagerImpl_AddressManager *SourceRouteManagerImpl_AddressManager_this;
    ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe;
    ::org::mpisws::p2p::transport::util::SocketRequestHandleImpl* handle;

private:
    virtual ::java::lang::Class* getClass0();
    friend class SourceRouteManagerImpl;
    friend class SourceRouteManagerImpl_AddressManager;
    friend class SourceRouteManagerImpl_AddressManager_PendingSocket;
    friend class SourceRouteManagerImpl_AddressManager_PendingMessage;
    friend class SourceRouteManagerImpl_AddressManager_sendMessage_1;
};
