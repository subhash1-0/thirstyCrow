// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/rc4/RC4TransportLayer.java
#include <org/mpisws/p2p/transport/rc4/RC4TransportLayer_openSocket_1_receiveResult_1_1_receiveSelectResult_1_1_1.hpp>

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
#include <javax/security/sasl/AuthenticationException.hpp>
#include <org/mpisws/p2p/transport/ClosedChannelException.hpp>
#include <org/mpisws/p2p/transport/ErrorHandler.hpp>
#include <org/mpisws/p2p/transport/P2PSocket.hpp>
#include <org/mpisws/p2p/transport/SocketCallback.hpp>
#include <org/mpisws/p2p/transport/rc4/EncryptedSocket.hpp>
#include <org/mpisws/p2p/transport/rc4/RC4TransportLayer_openSocket_1.hpp>
#include <org/mpisws/p2p/transport/rc4/RC4TransportLayer_openSocket_1_receiveResult_1_1.hpp>
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
org::mpisws::p2p::transport::rc4::RC4TransportLayer_openSocket_1_receiveResult_1_1_receiveSelectResult_1_1_1::RC4TransportLayer_openSocket_1_receiveResult_1_1_receiveSelectResult_1_1_1(RC4TransportLayer_openSocket_1_receiveResult_1_1 *RC4TransportLayer_openSocket_1_receiveResult_1_1_this, ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe, ::org::mpisws::p2p::transport::util::SocketRequestHandleImpl* ret, ::java::lang::Object* i, ::javax::crypto::Cipher* decryptCipher, ::int8_tArray* decryptSeed, ::java::util::Map* options)
    : super(*static_cast< ::default_init_tag* >(0))
    , RC4TransportLayer_openSocket_1_receiveResult_1_1_this(RC4TransportLayer_openSocket_1_receiveResult_1_1_this)
    , deliverSocketToMe(deliverSocketToMe)
    , ret(ret)
    , i(i)
    , decryptCipher(decryptCipher)
    , decryptSeed(decryptSeed)
    , options(options)
{
    clinit();
    init();
    ctor();
}

void org::mpisws::p2p::transport::rc4::RC4TransportLayer_openSocket_1_receiveResult_1_1_receiveSelectResult_1_1_1::init()
{
    encryptedSeeds = ::java::nio::ByteBuffer::allocate(RC4TransportLayer_openSocket_1_receiveResult_1_1_this->RC4TransportLayer_openSocket_1_this->RC4TransportLayer_this->PW_SEED_LENGTH * int32_t(2));
}

void org::mpisws::p2p::transport::rc4::RC4TransportLayer_openSocket_1_receiveResult_1_1_receiveSelectResult_1_1_1::receiveSelectResult(::org::mpisws::p2p::transport::P2PSocket* socket, bool canRead, bool canWrite) /* throws(IOException) */
{
    auto bytesRead = npc(socket)->read(encryptedSeeds);
    if(bytesRead < 0) {
        npc(socket)->close();
        npc(deliverSocketToMe)->receiveException(ret, new ::org::mpisws::p2p::transport::ClosedChannelException(::java::lang::StringBuilder().append(u"Socket to "_j)->append(static_cast< ::java::lang::Object* >(i))
            ->append(u" closed by remote host. "_j)
            ->append(static_cast< ::java::lang::Object* >(ret))->toString()));
        return;
    }
    if(npc(encryptedSeeds)->hasRemaining()) {
        npc(socket)->register_(true, false, this);
        return;
    }
    auto decryptedSeeds = npc(decryptCipher)->update(npc(encryptedSeeds)->array());
    auto same = true;
    for (auto ctr = int32_t(0); ctr < RC4TransportLayer_openSocket_1_receiveResult_1_1_this->RC4TransportLayer_openSocket_1_this->RC4TransportLayer_this->PW_SEED_LENGTH; ctr++) {
        if((*decryptedSeeds)[ctr + RC4TransportLayer_openSocket_1_receiveResult_1_1_this->RC4TransportLayer_openSocket_1_this->RC4TransportLayer_this->PW_SEED_LENGTH] != (*decryptSeed)[ctr]) {
            same = false;
            break;
        }
    }
    if(!same) {
        npc(socket)->close();
        npc(deliverSocketToMe)->receiveException(ret, new ::javax::security::sasl::AuthenticationException(u"Counterpart failed to properly encrypt his encryptSeed in the message."_j));
        return;
    }
    auto encryptSeed = new ::int8_tArray(RC4TransportLayer_openSocket_1_receiveResult_1_1_this->RC4TransportLayer_openSocket_1_this->RC4TransportLayer_this->PW_SEED_LENGTH);
    ::java::lang::System::arraycopy(decryptedSeeds, 0, encryptSeed, 0, RC4TransportLayer_openSocket_1_receiveResult_1_1_this->RC4TransportLayer_openSocket_1_this->RC4TransportLayer_this->PW_SEED_LENGTH);
    auto encryptKeyBytes = new ::int8_tArray(RC4TransportLayer::KEY_LENGTH);
    {
        synchronized synchronized_0(RC4TransportLayer_openSocket_1_receiveResult_1_1_this->RC4TransportLayer_openSocket_1_this->RC4TransportLayer_this->md);
        {
            npc(RC4TransportLayer_openSocket_1_receiveResult_1_1_this->RC4TransportLayer_openSocket_1_this->RC4TransportLayer_this->md)->update(RC4TransportLayer_openSocket_1_receiveResult_1_1_this->RC4TransportLayer_openSocket_1_this->RC4TransportLayer_this->password);
            npc(RC4TransportLayer_openSocket_1_receiveResult_1_1_this->RC4TransportLayer_openSocket_1_this->RC4TransportLayer_this->md)->update(encryptSeed);
            ::java::lang::System::arraycopy(npc(RC4TransportLayer_openSocket_1_receiveResult_1_1_this->RC4TransportLayer_openSocket_1_this->RC4TransportLayer_this->md)->digest(), 0, encryptKeyBytes, 0, RC4TransportLayer::KEY_LENGTH);
        }
    }
    ::javax::crypto::SecretKey* encryptKey = new ::javax::crypto::spec::SecretKeySpec(encryptKeyBytes, RC4TransportLayer::ALGORITHM());
    try {
        auto encryptCipher = ::javax::crypto::Cipher::getInstance(RC4TransportLayer::ALGORITHM());
        npc(encryptCipher)->init_(::javax::crypto::Cipher::ENCRYPT_MODE, static_cast< ::java::security::Key* >(encryptKey));
        npc(deliverSocketToMe)->receiveResult(ret, new EncryptedSocket(i, socket, RC4TransportLayer_openSocket_1_receiveResult_1_1_this->RC4TransportLayer_openSocket_1_this->RC4TransportLayer_this->logger, RC4TransportLayer_openSocket_1_receiveResult_1_1_this->RC4TransportLayer_openSocket_1_this->RC4TransportLayer_this->errorHandler, options, encryptCipher, decryptCipher, RC4TransportLayer_openSocket_1_receiveResult_1_1_this->RC4TransportLayer_openSocket_1_this->RC4TransportLayer_this->WRITE_BUFFER_SIZE));
    } catch (::java::security::GeneralSecurityException* gse) {
        npc(socket)->close();
        npc(deliverSocketToMe)->receiveException(ret, gse);
    }
}

void org::mpisws::p2p::transport::rc4::RC4TransportLayer_openSocket_1_receiveResult_1_1_receiveSelectResult_1_1_1::receiveException(::org::mpisws::p2p::transport::P2PSocket* socket, ::java::lang::Exception* ioe)
{
    npc(deliverSocketToMe)->receiveException(ret, ioe);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::rc4::RC4TransportLayer_openSocket_1_receiveResult_1_1_receiveSelectResult_1_1_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::rc4::RC4TransportLayer_openSocket_1_receiveResult_1_1_receiveSelectResult_1_1_1::getClass0()
{
    return class_();
}

