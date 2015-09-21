// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/wire/UDPLayerImpl.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/net/fwd-pastry-2.1.hpp>
#include <java/nio/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/wire/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/MessageRequestHandle.hpp>
#include <java/net/InetSocketAddress.hpp>
#include <java/nio/ByteBuffer.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::wire::UDPLayerImpl_Envelope
    : public virtual ::java::lang::Object
    , public virtual ::org::mpisws::p2p::transport::MessageRequestHandle
{

public:
    typedef ::java::lang::Object super;

public: /* protected */
    ::java::net::InetSocketAddress* destination {  };
    ::java::nio::ByteBuffer* msg {  };
    ::org::mpisws::p2p::transport::MessageCallback* continuation {  };

public: /* package */
    ::java::util::Map* options {  };
protected:
    void ctor(::java::net::InetSocketAddress* destination, ::java::nio::ByteBuffer* msg, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options);

public:
    bool cancel() override;
    ::java::net::InetSocketAddress* getIdentifier() override;
    ::java::nio::ByteBuffer* getMessage() override;
    ::java::util::Map* getOptions() override;

    // Generated
    UDPLayerImpl_Envelope(UDPLayerImpl *UDPLayerImpl_this, ::java::net::InetSocketAddress* destination, ::java::nio::ByteBuffer* msg, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options);
protected:
    UDPLayerImpl_Envelope(UDPLayerImpl *UDPLayerImpl_this, const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    UDPLayerImpl *UDPLayerImpl_this;

private:
    virtual ::java::lang::Class* getClass0();
    friend class UDPLayerImpl;
    friend class UDPLayerImpl_destroy_1;
    friend class UDPLayerImpl_acceptMessages_2;
};
