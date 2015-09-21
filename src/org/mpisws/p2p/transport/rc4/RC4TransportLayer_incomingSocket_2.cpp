// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/rc4/RC4TransportLayer.java
#include <org/mpisws/p2p/transport/rc4/RC4TransportLayer_incomingSocket_2.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/System.hpp>
#include <java/nio/ByteBuffer.hpp>
#include <java/security/GeneralSecurityException.hpp>
#include <java/security/Key.hpp>
#include <java/security/MessageDigest.hpp>
#include <javax/crypto/Cipher.hpp>
#include <javax/crypto/SecretKey.hpp>
#include <javax/crypto/spec/SecretKeySpec.hpp>
#include <org/mpisws/p2p/transport/ErrorHandler.hpp>
#include <org/mpisws/p2p/transport/P2PSocket.hpp>
#include <org/mpisws/p2p/transport/rc4/RC4TransportLayer_incomingSocket_2_receiveSelectResult_2_1.hpp>
#include <org/mpisws/p2p/transport/rc4/RC4TransportLayer.hpp>
#include <rice/environment/random/RandomSource.hpp>
#include <Array.hpp>

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
org::mpisws::p2p::transport::rc4::RC4TransportLayer_incomingSocket_2::RC4TransportLayer_incomingSocket_2(RC4TransportLayer *RC4TransportLayer_this)
    : super(*static_cast< ::default_init_tag* >(0))
    , RC4TransportLayer_this(RC4TransportLayer_this)
{
    clinit();
    init();
    ctor();
}

void org::mpisws::p2p::transport::rc4::RC4TransportLayer_incomingSocket_2::init()
{
    encryptSeed = new ::int8_tArray(RC4TransportLayer_this->PW_SEED_LENGTH);
    encryptSeedBuffer = ::java::nio::ByteBuffer::wrap(encryptSeed);
}

void org::mpisws::p2p::transport::rc4::RC4TransportLayer_incomingSocket_2::receiveSelectResult(::org::mpisws::p2p::transport::P2PSocket* socket, bool canRead, bool canWrite) /* throws(IOException) */
{
    auto ret = npc(socket)->read(encryptSeedBuffer);
    if(ret < 0) {
        npc(socket)->close();
    }
    if(npc(encryptSeedBuffer)->hasRemaining()) {
        npc(socket)->register_(true, false, this);
        return;
    }
    auto encryptKeyBytes = new ::int8_tArray(RC4TransportLayer::KEY_LENGTH);
    {
        synchronized synchronized_0(RC4TransportLayer_this->md);
        {
            npc(RC4TransportLayer_this->md)->update(RC4TransportLayer_this->password);
            npc(RC4TransportLayer_this->md)->update(encryptSeed);
            ::java::lang::System::arraycopy(npc(RC4TransportLayer_this->md)->digest(), 0, encryptKeyBytes, 0, RC4TransportLayer::KEY_LENGTH);
        }
    }
    ::javax::crypto::SecretKey* encryptKey = new ::javax::crypto::spec::SecretKeySpec(encryptKeyBytes, RC4TransportLayer::ALGORITHM());
    try {
        auto const encryptCipher = ::javax::crypto::Cipher::getInstance(RC4TransportLayer::ALGORITHM());
        npc(encryptCipher)->init_(::javax::crypto::Cipher::ENCRYPT_MODE, static_cast< ::java::security::Key* >(encryptKey));
        auto const decryptSeed = new ::int8_tArray(RC4TransportLayer_this->PW_SEED_LENGTH);
        npc(RC4TransportLayer_this->random)->nextBytes(decryptSeed);
        auto decryptKeyBytes = new ::int8_tArray(RC4TransportLayer::KEY_LENGTH);
        {
            synchronized synchronized_1(RC4TransportLayer_this->md);
            {
                npc(RC4TransportLayer_this->md)->update(RC4TransportLayer_this->password);
                npc(RC4TransportLayer_this->md)->update(decryptSeed);
                ::java::lang::System::arraycopy(npc(RC4TransportLayer_this->md)->digest(), 0, decryptKeyBytes, 0, RC4TransportLayer::KEY_LENGTH);
            }
        }
        ::javax::crypto::SecretKey* decryptKey = new ::javax::crypto::spec::SecretKeySpec(decryptKeyBytes, RC4TransportLayer::ALGORITHM());
        auto const decryptCipher = ::javax::crypto::Cipher::getInstance(RC4TransportLayer::ALGORITHM());
        npc(decryptCipher)->init_(::javax::crypto::Cipher::DECRYPT_MODE, static_cast< ::java::security::Key* >(decryptKey));
        auto encryptedSeeds = new ::int8_tArray(RC4TransportLayer_this->PW_SEED_LENGTH * int32_t(2));
        npc(encryptCipher)->update(decryptSeed, 0, RC4TransportLayer_this->PW_SEED_LENGTH, encryptedSeeds, 0);
        npc(encryptCipher)->update(encryptSeed, 0, RC4TransportLayer_this->PW_SEED_LENGTH, encryptedSeeds, RC4TransportLayer_this->PW_SEED_LENGTH);
        auto const encryptedSeedsBuffer = ::java::nio::ByteBuffer::wrap(encryptedSeeds);
        (new RC4TransportLayer_incomingSocket_2_receiveSelectResult_2_1(this, encryptedSeedsBuffer, encryptCipher, decryptCipher))->receiveSelectResult(socket, false, true);
    } catch (::java::security::GeneralSecurityException* gse) {
        npc(socket)->close();
    }
}

void org::mpisws::p2p::transport::rc4::RC4TransportLayer_incomingSocket_2::receiveException(::org::mpisws::p2p::transport::P2PSocket* socket, ::java::lang::Exception* ioe)
{
    npc(RC4TransportLayer_this->errorHandler)->receivedException(java_cast< ::java::lang::Object* >(npc(socket)->getIdentifier()), ioe);
    npc(socket)->close();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::rc4::RC4TransportLayer_incomingSocket_2::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::rc4::RC4TransportLayer_incomingSocket_2::getClass0()
{
    return class_();
}

