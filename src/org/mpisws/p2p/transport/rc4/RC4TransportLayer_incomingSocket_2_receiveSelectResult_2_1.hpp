// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/rc4/RC4TransportLayer.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/nio/fwd-pastry-2.1.hpp>
#include <javax/crypto/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/rc4/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/P2PSocketReceiver.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::rc4::RC4TransportLayer_incomingSocket_2_receiveSelectResult_2_1
    : public virtual ::java::lang::Object
    , public virtual ::org::mpisws::p2p::transport::P2PSocketReceiver
{

public:
    typedef ::java::lang::Object super;
    void receiveSelectResult(::org::mpisws::p2p::transport::P2PSocket* socket, bool canRead, bool canWrite) /* throws(IOException) */ override;
    void receiveException(::org::mpisws::p2p::transport::P2PSocket* socket, ::java::lang::Exception* ioe) override;

    // Generated
    RC4TransportLayer_incomingSocket_2_receiveSelectResult_2_1(RC4TransportLayer_incomingSocket_2 *RC4TransportLayer_incomingSocket_2_this, ::java::nio::ByteBuffer* encryptedSeedsBuffer, ::javax::crypto::Cipher* encryptCipher, ::javax::crypto::Cipher* decryptCipher);
    static ::java::lang::Class *class_();
    RC4TransportLayer_incomingSocket_2 *RC4TransportLayer_incomingSocket_2_this;
    ::java::nio::ByteBuffer* encryptedSeedsBuffer;
    ::javax::crypto::Cipher* encryptCipher;
    ::javax::crypto::Cipher* decryptCipher;

private:
    virtual ::java::lang::Class* getClass0();
    friend class RC4TransportLayer;
    friend class RC4TransportLayer_openSocket_1;
    friend class RC4TransportLayer_openSocket_1_receiveResult_1_1;
    friend class RC4TransportLayer_openSocket_1_receiveResult_1_1_receiveSelectResult_1_1_1;
    friend class RC4TransportLayer_incomingSocket_2;
};
