// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/rc4/RC4TransportLayer.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/nio/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <javax/crypto/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/rc4/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/util/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/P2PSocketReceiver.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::rc4::RC4TransportLayer_openSocket_1_receiveResult_1_1_receiveSelectResult_1_1_1
    : public virtual ::java::lang::Object
    , public virtual ::org::mpisws::p2p::transport::P2PSocketReceiver
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    ::java::nio::ByteBuffer* encryptedSeeds {  };

public:
    void receiveSelectResult(::org::mpisws::p2p::transport::P2PSocket* socket, bool canRead, bool canWrite) /* throws(IOException) */ override;
    void receiveException(::org::mpisws::p2p::transport::P2PSocket* socket, ::java::lang::Exception* ioe) override;

    // Generated
    RC4TransportLayer_openSocket_1_receiveResult_1_1_receiveSelectResult_1_1_1(RC4TransportLayer_openSocket_1_receiveResult_1_1 *RC4TransportLayer_openSocket_1_receiveResult_1_1_this, ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe, ::org::mpisws::p2p::transport::util::SocketRequestHandleImpl* ret, ::java::lang::Object* i, ::javax::crypto::Cipher* decryptCipher, ::int8_tArray* decryptSeed, ::java::util::Map* options);
    static ::java::lang::Class *class_();

private:
    void init();
    RC4TransportLayer_openSocket_1_receiveResult_1_1 *RC4TransportLayer_openSocket_1_receiveResult_1_1_this;
    ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe;
    ::org::mpisws::p2p::transport::util::SocketRequestHandleImpl* ret;
    ::java::lang::Object* i;
    ::javax::crypto::Cipher* decryptCipher;
    ::int8_tArray* decryptSeed;
    ::java::util::Map* options;
    virtual ::java::lang::Class* getClass0();
    friend class RC4TransportLayer;
    friend class RC4TransportLayer_openSocket_1;
    friend class RC4TransportLayer_openSocket_1_receiveResult_1_1;
    friend class RC4TransportLayer_incomingSocket_2;
    friend class RC4TransportLayer_incomingSocket_2_receiveSelectResult_2_1;
};
