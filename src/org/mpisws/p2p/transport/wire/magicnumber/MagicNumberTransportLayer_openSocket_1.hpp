// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/wire/magicnumber/MagicNumberTransportLayer.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/wire/magicnumber/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/SocketCallback.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::wire::magicnumber::MagicNumberTransportLayer_openSocket_1
    : public virtual ::java::lang::Object
    , public virtual ::org::mpisws::p2p::transport::SocketCallback
{

public:
    typedef ::java::lang::Object super;
    void receiveResult(::org::mpisws::p2p::transport::SocketRequestHandle* c, ::org::mpisws::p2p::transport::P2PSocket* result) override;
    void receiveException(::org::mpisws::p2p::transport::SocketRequestHandle* c, ::java::lang::Exception* exception) override;

    // Generated
    MagicNumberTransportLayer_openSocket_1(MagicNumberTransportLayer *MagicNumberTransportLayer_this, ::org::mpisws::p2p::transport::util::SocketRequestHandleImpl* cancellable, ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe);
    static ::java::lang::Class *class_();
    MagicNumberTransportLayer *MagicNumberTransportLayer_this;
    ::org::mpisws::p2p::transport::util::SocketRequestHandleImpl* cancellable;
    ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe;

private:
    virtual ::java::lang::Class* getClass0();
    friend class MagicNumberTransportLayer;
    friend class MagicNumberTransportLayer_openSocket_1_receiveResult_1_1;
    friend class MagicNumberTransportLayer_openSocket_1_receiveResult_1_2;
    friend class MagicNumberTransportLayer_sendMessage_2;
    friend class MagicNumberTransportLayer_VerifyHeaderReceiver;
};
