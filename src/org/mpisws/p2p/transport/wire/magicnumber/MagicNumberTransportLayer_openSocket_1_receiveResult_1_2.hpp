// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/wire/magicnumber/MagicNumberTransportLayer.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/nio/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/wire/magicnumber/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/P2PSocketReceiver.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::wire::magicnumber::MagicNumberTransportLayer_openSocket_1_receiveResult_1_2
    : public virtual ::java::lang::Object
    , public virtual ::org::mpisws::p2p::transport::P2PSocketReceiver
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    ::java::nio::ByteBuffer* buf {  };

public:
    void receiveSelectResult(::org::mpisws::p2p::transport::P2PSocket* socket, bool canRead, bool canWrite) /* throws(IOException) */ override;
    void receiveException(::org::mpisws::p2p::transport::P2PSocket* socket, ::java::lang::Exception* e) override;

    // Generated
    MagicNumberTransportLayer_openSocket_1_receiveResult_1_2(MagicNumberTransportLayer_openSocket_1 *MagicNumberTransportLayer_openSocket_1_this, ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe, ::org::mpisws::p2p::transport::util::SocketRequestHandleImpl* cancellable);
    static ::java::lang::Class *class_();

private:
    void init();
    MagicNumberTransportLayer_openSocket_1 *MagicNumberTransportLayer_openSocket_1_this;
    ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe;
    ::org::mpisws::p2p::transport::util::SocketRequestHandleImpl* cancellable;
    virtual ::java::lang::Class* getClass0();
    friend class MagicNumberTransportLayer;
    friend class MagicNumberTransportLayer_openSocket_1;
    friend class MagicNumberTransportLayer_openSocket_1_receiveResult_1_1;
    friend class MagicNumberTransportLayer_sendMessage_2;
    friend class MagicNumberTransportLayer_VerifyHeaderReceiver;
};
