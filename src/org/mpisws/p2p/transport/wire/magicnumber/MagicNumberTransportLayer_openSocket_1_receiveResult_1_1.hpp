// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/wire/magicnumber/MagicNumberTransportLayer.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/wire/magicnumber/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/p2p/commonapi/Cancellable.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::wire::magicnumber::MagicNumberTransportLayer_openSocket_1_receiveResult_1_1
    : public virtual ::java::lang::Object
    , public virtual ::rice::p2p::commonapi::Cancellable
{

public:
    typedef ::java::lang::Object super;
    bool cancel() override;

    // Generated
    MagicNumberTransportLayer_openSocket_1_receiveResult_1_1(MagicNumberTransportLayer_openSocket_1 *MagicNumberTransportLayer_openSocket_1_this, ::org::mpisws::p2p::transport::P2PSocket* result);
    static ::java::lang::Class *class_();
    MagicNumberTransportLayer_openSocket_1 *MagicNumberTransportLayer_openSocket_1_this;
    ::org::mpisws::p2p::transport::P2PSocket* result;

private:
    virtual ::java::lang::Class* getClass0();
    friend class MagicNumberTransportLayer;
    friend class MagicNumberTransportLayer_openSocket_1;
    friend class MagicNumberTransportLayer_openSocket_1_receiveResult_1_2;
    friend class MagicNumberTransportLayer_sendMessage_2;
    friend class MagicNumberTransportLayer_VerifyHeaderReceiver;
};
