// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/sourceroute/manager/SourceRouteManagerImpl.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/sourceroute/manager/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/SocketRequestHandle.hpp>
#include <org/mpisws/p2p/transport/SocketCallback.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::sourceroute::manager::SourceRouteManagerImpl_AddressManager_PendingSocket
    : public virtual ::java::lang::Object
    , public virtual ::org::mpisws::p2p::transport::SocketRequestHandle
    , public virtual ::org::mpisws::p2p::transport::SocketCallback
{

public:
    typedef ::java::lang::Object super;

private:
    ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe {  };
    ::java::util::Map* options {  };
    ::rice::p2p::commonapi::Cancellable* cancellable {  };
protected:
    void ctor(::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe, ::java::util::Map* options);

public:
    void receiveResult(::org::mpisws::p2p::transport::SocketRequestHandle* cancellable, ::org::mpisws::p2p::transport::P2PSocket* sock) override;
    void receiveException(::org::mpisws::p2p::transport::SocketRequestHandle* s, ::java::lang::Exception* ex) override;
    virtual void fail(::java::lang::Exception* ex);
    bool cancel() override;
    ::java::lang::Object* getIdentifier() override;
    ::java::util::Map* getOptions() override;

    // Generated
    SourceRouteManagerImpl_AddressManager_PendingSocket(SourceRouteManagerImpl_AddressManager *SourceRouteManagerImpl_AddressManager_this, ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe, ::java::util::Map* options);
protected:
    SourceRouteManagerImpl_AddressManager_PendingSocket(SourceRouteManagerImpl_AddressManager *SourceRouteManagerImpl_AddressManager_this, const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    SourceRouteManagerImpl_AddressManager *SourceRouteManagerImpl_AddressManager_this;

private:
    virtual ::java::lang::Class* getClass0();
    friend class SourceRouteManagerImpl;
    friend class SourceRouteManagerImpl_AddressManager;
    friend class SourceRouteManagerImpl_AddressManager_PendingMessage;
    friend class SourceRouteManagerImpl_AddressManager_sendMessage_1;
    friend class SourceRouteManagerImpl_AddressManager_openSocket_2;
};
