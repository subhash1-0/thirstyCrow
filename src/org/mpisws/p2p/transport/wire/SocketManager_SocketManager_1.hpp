// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/wire/SocketManager.java

#pragma once

#include <java/net/fwd-pastry-2.1.hpp>
#include <java/nio/channels/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/wire/fwd-pastry-2.1.hpp>
#include <rice/selector/SelectionKeyHandler.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::wire::SocketManager_SocketManager_1
    : public ::rice::selector::SelectionKeyHandler
{

public:
    typedef ::rice::selector::SelectionKeyHandler super;
    void write(::java::nio::channels::SelectionKey* key) override;
    void read(::java::nio::channels::SelectionKey* key) override;
    void modifyKey(::java::nio::channels::SelectionKey* key) override;
    void connect(::java::nio::channels::SelectionKey* key) override;

    // Generated
    SocketManager_SocketManager_1(SocketManager *SocketManager_this, TCPLayer* tcp, ::java::net::InetSocketAddress* addr, ::org::mpisws::p2p::transport::SocketCallback* c);
    static ::java::lang::Class *class_();
    SocketManager *SocketManager_this;
    TCPLayer* tcp;
    ::java::net::InetSocketAddress* addr;
    ::org::mpisws::p2p::transport::SocketCallback* c;

private:
    virtual ::java::lang::Class* getClass0();
    friend class SocketManager;
    friend class SocketManager_close_2;
    friend class SocketManager_shutdownOutput_3;
};
