// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/wire/magicnumber/MagicNumberTransportLayer.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/nio/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/wire/magicnumber/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/MessageCallback.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::wire::magicnumber::MagicNumberTransportLayer_sendMessage_2
    : public virtual ::java::lang::Object
    , public virtual ::org::mpisws::p2p::transport::MessageCallback
{

public:
    typedef ::java::lang::Object super;
    void ack(::org::mpisws::p2p::transport::MessageRequestHandle* msg) override;
    void sendFailed(::org::mpisws::p2p::transport::MessageRequestHandle* msg, ::java::lang::Exception* ex) override;

    // Generated
    MagicNumberTransportLayer_sendMessage_2(MagicNumberTransportLayer *MagicNumberTransportLayer_this, ::org::mpisws::p2p::transport::util::MessageRequestHandleImpl* cancellable, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::lang::Object* i, ::java::nio::ByteBuffer* buf);
    static ::java::lang::Class *class_();
    MagicNumberTransportLayer *MagicNumberTransportLayer_this;
    ::org::mpisws::p2p::transport::util::MessageRequestHandleImpl* cancellable;
    ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe;
    ::java::lang::Object* i;
    ::java::nio::ByteBuffer* buf;

private:
    virtual ::java::lang::Class* getClass0();
    friend class MagicNumberTransportLayer;
    friend class MagicNumberTransportLayer_openSocket_1;
    friend class MagicNumberTransportLayer_openSocket_1_receiveResult_1_1;
    friend class MagicNumberTransportLayer_openSocket_1_receiveResult_1_2;
    friend class MagicNumberTransportLayer_VerifyHeaderReceiver;
};
