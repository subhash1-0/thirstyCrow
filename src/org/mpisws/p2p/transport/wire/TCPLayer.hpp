// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/wire/TCPLayer.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/net/fwd-pastry-2.1.hpp>
#include <java/nio/fwd-pastry-2.1.hpp>
#include <java/nio/channels/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/wire/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <rice/selector/SelectionKeyHandler.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::wire::TCPLayer
    : public ::rice::selector::SelectionKeyHandler
{

public:
    typedef ::rice::selector::SelectionKeyHandler super;

private:
    static ::java::util::Map* OPTIONS_;

public:
    int32_t MAX_OPEN_SOCKETS {  };
    int32_t SOCKET_BUFFER_SIZE {  };
    bool TCP_NO_DELAY {  };

public: /* package */
    WireTransportLayerImpl* wire {  };

private:
    ::java::nio::channels::SelectionKey* key {  };
    ::java::nio::ByteBuffer* buffer {  };

public: /* package */
    ::rice::environment::logging::Logger* logger {  };
protected:
    void ctor(WireTransportLayerImpl* wire, bool enableServer) /* throws(IOException) */;

public:
    virtual ::org::mpisws::p2p::transport::SocketRequestHandle* openSocket(::java::net::InetSocketAddress* destination, ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe, ::java::util::Map* options);

public: /* package */
    ::java::util::Collection* sockets {  };

public: /* protected */
    virtual void socketClosed(SocketManager* sm);

public:
    virtual void destroy();
    virtual void acceptSockets(bool b);
    void accept(::java::nio::channels::SelectionKey* key) override;
    virtual bool isDestroyed();

    // Generated
    TCPLayer(WireTransportLayerImpl* wire, bool enableServer);
protected:
    TCPLayer(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    static void clinit();

private:
    void init();

public:
    static ::java::util::Map*& OPTIONS();

private:
    virtual ::java::lang::Class* getClass0();
    friend class TCPLayer_acceptSockets_1;
};
