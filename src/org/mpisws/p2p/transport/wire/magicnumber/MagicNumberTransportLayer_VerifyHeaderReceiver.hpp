// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/wire/magicnumber/MagicNumberTransportLayer.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/nio/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/wire/magicnumber/fwd-pastry-2.1.hpp>
#include <rice/selector/TimerTask.hpp>
#include <org/mpisws/p2p/transport/P2PSocketReceiver.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::wire::magicnumber::MagicNumberTransportLayer_VerifyHeaderReceiver
    : public ::rice::selector::TimerTask
    , public virtual ::org::mpisws::p2p::transport::P2PSocketReceiver
{

public:
    typedef ::rice::selector::TimerTask super;

public: /* package */
    ::java::nio::ByteBuffer* buf {  };
    ::org::mpisws::p2p::transport::P2PSocket* socket {  };
protected:
    void ctor(::org::mpisws::p2p::transport::P2PSocket* s);

public:
    void receiveException(::org::mpisws::p2p::transport::P2PSocket* socket, ::java::lang::Exception* ioe) override;
    void receiveSelectResult(::org::mpisws::p2p::transport::P2PSocket* socket, bool canRead, bool canWrite) /* throws(IOException) */ override;
    void run() override;
    ::java::lang::String* toString() override;

    // Generated
    MagicNumberTransportLayer_VerifyHeaderReceiver(MagicNumberTransportLayer *MagicNumberTransportLayer_this, ::org::mpisws::p2p::transport::P2PSocket* s);
protected:
    MagicNumberTransportLayer_VerifyHeaderReceiver(MagicNumberTransportLayer *MagicNumberTransportLayer_this, const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    void init();
    MagicNumberTransportLayer *MagicNumberTransportLayer_this;
    virtual ::java::lang::Class* getClass0();
    friend class MagicNumberTransportLayer;
    friend class MagicNumberTransportLayer_openSocket_1;
    friend class MagicNumberTransportLayer_openSocket_1_receiveResult_1_1;
    friend class MagicNumberTransportLayer_openSocket_1_receiveResult_1_2;
    friend class MagicNumberTransportLayer_sendMessage_2;
};
