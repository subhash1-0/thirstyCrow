// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/rc4/RC4TransportLayer.java
#include <org/mpisws/p2p/transport/rc4/RC4TransportLayer_incomingSocket_2_receiveSelectResult_2_1.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/nio/ByteBuffer.hpp>
#include <org/mpisws/p2p/transport/ClosedChannelException.hpp>
#include <org/mpisws/p2p/transport/ErrorHandler.hpp>
#include <org/mpisws/p2p/transport/P2PSocket.hpp>
#include <org/mpisws/p2p/transport/TransportLayerCallback.hpp>
#include <org/mpisws/p2p/transport/rc4/EncryptedSocket.hpp>
#include <org/mpisws/p2p/transport/rc4/RC4TransportLayer_incomingSocket_2.hpp>
#include <org/mpisws/p2p/transport/rc4/RC4TransportLayer.hpp>

template<typename T, typename U>
static T java_cast(U* u)
{
    if(!u) return static_cast<T>(nullptr);
    auto t = dynamic_cast<T>(u);
    if(!t) throw new ::java::lang::ClassCastException();
    return t;
}

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::transport::rc4::RC4TransportLayer_incomingSocket_2_receiveSelectResult_2_1::RC4TransportLayer_incomingSocket_2_receiveSelectResult_2_1(RC4TransportLayer_incomingSocket_2 *RC4TransportLayer_incomingSocket_2_this, ::java::nio::ByteBuffer* encryptedSeedsBuffer, ::javax::crypto::Cipher* encryptCipher, ::javax::crypto::Cipher* decryptCipher)
    : super(*static_cast< ::default_init_tag* >(0))
    , RC4TransportLayer_incomingSocket_2_this(RC4TransportLayer_incomingSocket_2_this)
    , encryptedSeedsBuffer(encryptedSeedsBuffer)
    , encryptCipher(encryptCipher)
    , decryptCipher(decryptCipher)
{
    clinit();
    ctor();
}

void org::mpisws::p2p::transport::rc4::RC4TransportLayer_incomingSocket_2_receiveSelectResult_2_1::receiveSelectResult(::org::mpisws::p2p::transport::P2PSocket* socket, bool canRead, bool canWrite) /* throws(IOException) */
{
    auto ret = npc(socket)->write(encryptedSeedsBuffer);
    if(ret < 0) {
        receiveException(socket, static_cast< ::java::lang::Exception* >(new ::org::mpisws::p2p::transport::ClosedChannelException(::java::lang::StringBuilder().append(u"Channel closed while establishing crypto. "_j)->append(static_cast< ::java::lang::Object* >(socket))->toString())));
        return;
    }
    if(npc(encryptedSeedsBuffer)->hasRemaining()) {
        npc(socket)->register_(false, true, this);
        return;
    }
    npc(RC4TransportLayer_incomingSocket_2_this->RC4TransportLayer_this->callback)->incomingSocket(new EncryptedSocket(java_cast< ::java::lang::Object* >(npc(socket)->getIdentifier()), socket, RC4TransportLayer_incomingSocket_2_this->RC4TransportLayer_this->logger, RC4TransportLayer_incomingSocket_2_this->RC4TransportLayer_this->errorHandler, npc(socket)->getOptions(), encryptCipher, decryptCipher, RC4TransportLayer_incomingSocket_2_this->RC4TransportLayer_this->WRITE_BUFFER_SIZE));
}

void org::mpisws::p2p::transport::rc4::RC4TransportLayer_incomingSocket_2_receiveSelectResult_2_1::receiveException(::org::mpisws::p2p::transport::P2PSocket* socket, ::java::lang::Exception* ioe)
{
    npc(RC4TransportLayer_incomingSocket_2_this->RC4TransportLayer_this->errorHandler)->receivedException(java_cast< ::java::lang::Object* >(npc(socket)->getIdentifier()), ioe);
    npc(socket)->close();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::rc4::RC4TransportLayer_incomingSocket_2_receiveSelectResult_2_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::rc4::RC4TransportLayer_incomingSocket_2_receiveSelectResult_2_1::getClass0()
{
    return class_();
}

