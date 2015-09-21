// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/wire/BogusUDPLayerImpl.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/net/fwd-pastry-2.1.hpp>
#include <java/nio/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/wire/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/wire/UDPLayer.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::wire::BogusUDPLayerImpl
    : public virtual ::java::lang::Object
    , public virtual UDPLayer
{

public:
    typedef ::java::lang::Object super;
    ::org::mpisws::p2p::transport::MessageRequestHandle* sendMessage(::java::net::InetSocketAddress* destination, ::java::nio::ByteBuffer* m, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options) override;
    void destroy() override;
    void acceptMessages(bool b) override;

    // Generated
    BogusUDPLayerImpl();
protected:
    BogusUDPLayerImpl(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
