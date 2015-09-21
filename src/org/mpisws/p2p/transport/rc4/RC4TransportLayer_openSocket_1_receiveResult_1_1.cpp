// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/rc4/RC4TransportLayer.java
#include <org/mpisws/p2p/transport/rc4/RC4TransportLayer_openSocket_1_receiveResult_1_1.hpp>

#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>
#include <java/nio/ByteBuffer.hpp>
#include <java/security/GeneralSecurityException.hpp>
#include <java/security/Key.hpp>
#include <java/security/MessageDigest.hpp>
#include <javax/crypto/Cipher.hpp>
#include <javax/crypto/SecretKey.hpp>
#include <javax/crypto/spec/SecretKeySpec.hpp>
#include <org/mpisws/p2p/transport/ClosedChannelException.hpp>
#include <org/mpisws/p2p/transport/P2PSocket.hpp>
#include <org/mpisws/p2p/transport/P2PSocketReceiver.hpp>
#include <org/mpisws/p2p/transport/SocketCallback.hpp>
#include <org/mpisws/p2p/transport/rc4/RC4TransportLayer_openSocket_1.hpp>
#include <org/mpisws/p2p/transport/rc4/RC4TransportLayer_openSocket_1_receiveResult_1_1_receiveSelectResult_1_1_1.hpp>
#include <org/mpisws/p2p/transport/rc4/RC4TransportLayer.hpp>
#include <org/mpisws/p2p/transport/util/SocketRequestHandleImpl.hpp>
#include <Array.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

extern void lock(::java::lang::Object *);
extern void unlock(::java::lang::Object *);

namespace
{
    struct synchronized
    {
        synchronized(::java::lang::Object *o) : o(o) { ::lock(o); }
        ~synchronized() { ::unlock(o); }
    private:
        synchronized(const synchronized&); synchronized& operator=(const synchronized&);
        ::java::lang::Object *o;
    };
}
org::mpisws::p2p::transport::rc4::RC4TransportLayer_openSocket_1_receiveResult_1_1::RC4TransportLayer_openSocket_1_receiveResult_1_1(RC4TransportLayer_openSocket_1 *RC4TransportLayer_openSocket_1_this, ::int8_tArray* decryptSeed, ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe, ::org::mpisws::p2p::transport::util::SocketRequestHandleImpl* ret, ::java::lang::Object* i, ::java::util::Map* options)
    : super(*static_cast< ::default_init_tag* >(0))
    , RC4TransportLayer_openSocket_1_this(RC4TransportLayer_openSocket_1_this)
    , decryptSeed(decryptSeed)
    , deliverSocketToMe(deliverSocketToMe)
    , ret(ret)
    , i(i)
    , options(options)
{
    clinit();
    init();
    ctor();
}

void org::mpisws::p2p::transport::rc4::RC4TransportLayer_openSocket_1_receiveResult_1_1::init()
{
    dsBB = ::java::nio::ByteBuffer::wrap(decryptSeed);
}

void org::mpisws::p2p::transport::rc4::RC4TransportLayer_openSocket_1_receiveResult_1_1::receiveSelectResult(::org::mpisws::p2p::transport::P2PSocket* socket, bool canRead, bool canWrite) /* throws(IOException) */
{
    auto bytesWritten = npc(socket)->write(dsBB);
    if(bytesWritten < 0) {
        npc(socket)->close();
        npc(deliverSocketToMe)->receiveException(ret, new ::org::mpisws::p2p::transport::ClosedChannelException(::java::lang::StringBuilder().append(u"Socket to "_j)->append(static_cast< ::java::lang::Object* >(i))
            ->append(u" closed by remote host. "_j)
            ->append(static_cast< ::java::lang::Object* >(ret))->toString()));
        return;
    }
    if(npc(dsBB)->hasRemaining()) {
        npc(socket)->register_(false, true, this);
        return;
    }
    auto decryptKeyBytes = new ::int8_tArray(RC4TransportLayer::KEY_LENGTH);
    {
        synchronized synchronized_0(RC4TransportLayer_openSocket_1_this->RC4TransportLayer_this->md);
        {
            npc(RC4TransportLayer_openSocket_1_this->RC4TransportLayer_this->md)->update(RC4TransportLayer_openSocket_1_this->RC4TransportLayer_this->password);
            npc(RC4TransportLayer_openSocket_1_this->RC4TransportLayer_this->md)->update(decryptSeed);
            ::java::lang::System::arraycopy(npc(RC4TransportLayer_openSocket_1_this->RC4TransportLayer_this->md)->digest(), 0, decryptKeyBytes, 0, RC4TransportLayer::KEY_LENGTH);
        }
    }
    ::javax::crypto::SecretKey* decryptKey = new ::javax::crypto::spec::SecretKeySpec(decryptKeyBytes, RC4TransportLayer::ALGORITHM());
    try {
        auto const decryptCipher = ::javax::crypto::Cipher::getInstance(RC4TransportLayer::ALGORITHM());
        npc(decryptCipher)->init_(::javax::crypto::Cipher::DECRYPT_MODE, static_cast< ::java::security::Key* >(decryptKey));
        ::org::mpisws::p2p::transport::P2PSocketReceiver* readEncryptSeedReceiver = new RC4TransportLayer_openSocket_1_receiveResult_1_1_receiveSelectResult_1_1_1(this, deliverSocketToMe, ret, i, decryptCipher, decryptSeed, options);
        npc(readEncryptSeedReceiver)->receiveSelectResult(socket, true, false);
    } catch (::java::security::GeneralSecurityException* gse) {
        npc(socket)->close();
        npc(deliverSocketToMe)->receiveException(ret, gse);
    }
}

void org::mpisws::p2p::transport::rc4::RC4TransportLayer_openSocket_1_receiveResult_1_1::receiveException(::org::mpisws::p2p::transport::P2PSocket* socket, ::java::lang::Exception* ioe)
{
    npc(deliverSocketToMe)->receiveException(ret, ioe);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::rc4::RC4TransportLayer_openSocket_1_receiveResult_1_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::rc4::RC4TransportLayer_openSocket_1_receiveResult_1_1::getClass0()
{
    return class_();
}

