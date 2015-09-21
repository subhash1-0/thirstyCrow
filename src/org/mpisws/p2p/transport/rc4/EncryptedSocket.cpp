// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/rc4/EncryptedSocket.java
#include <org/mpisws/p2p/transport/rc4/EncryptedSocket.hpp>

#include <java/lang/Exception.hpp>
#include <java/lang/Math.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/nio/ByteBuffer.hpp>
#include <javax/crypto/Cipher.hpp>
#include <javax/crypto/ShortBufferException.hpp>
#include <org/mpisws/p2p/transport/ClosedChannelException.hpp>
#include <org/mpisws/p2p/transport/ErrorHandler.hpp>
#include <org/mpisws/p2p/transport/P2PSocket.hpp>
#include <org/mpisws/p2p/transport/P2PSocketReceiver.hpp>
#include <rice/environment/logging/Logger.hpp>
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
org::mpisws::p2p::transport::rc4::EncryptedSocket::EncryptedSocket(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::transport::rc4::EncryptedSocket::EncryptedSocket(::java::lang::Object* identifier, ::org::mpisws::p2p::transport::P2PSocket* socket, ::rice::environment::logging::Logger* logger, ::org::mpisws::p2p::transport::ErrorHandler* handler, ::java::util::Map* options, ::javax::crypto::Cipher* encryptCipher, ::javax::crypto::Cipher* decryptCipher, int32_t writeBufferSize) 
    : EncryptedSocket(*static_cast< ::default_init_tag* >(0))
{
    ctor(identifier,socket,logger,handler,options,encryptCipher,decryptCipher,writeBufferSize);
}

void org::mpisws::p2p::transport::rc4::EncryptedSocket::ctor(::java::lang::Object* identifier, ::org::mpisws::p2p::transport::P2PSocket* socket, ::rice::environment::logging::Logger* logger, ::org::mpisws::p2p::transport::ErrorHandler* handler, ::java::util::Map* options, ::javax::crypto::Cipher* encryptCipher, ::javax::crypto::Cipher* decryptCipher, int32_t writeBufferSize)
{
    super::ctor(identifier, socket, logger, handler, options);
    encryptedBytes = new ::int8_tArray(writeBufferSize);
    encryptedWriteBuffer = ::java::nio::ByteBuffer::wrap(encryptedBytes);
    npc(encryptedWriteBuffer)->limit(0);
    this->encryptCipher = encryptCipher;
    this->decryptCipher = decryptCipher;
}

int64_t org::mpisws::p2p::transport::rc4::EncryptedSocket::read(::java::nio::ByteBuffer* output) /* throws(IOException) */
{
    auto input = ::java::nio::ByteBuffer::allocate(npc(output)->remaining());
    auto ret = npc(socket)->read(input);
    if(ret < 0) {
        return ret;
    }
    npc(input)->flip();
    try {
        return npc(decryptCipher)->update(input, output);
    } catch (::javax::crypto::ShortBufferException* sbe) {
        npc(logger)->logException(::java::lang::StringBuilder().append(u"We got a short buffer exception reading. This indicates a bug in the implementation. "_j)->append(static_cast< ::java::lang::Object* >(this))->toString(), sbe);
        npc(socket)->close();
        return -int32_t(1);
    }
}

int64_t org::mpisws::p2p::transport::rc4::EncryptedSocket::write(::java::nio::ByteBuffer* srcs) /* throws(IOException) */
{
    int64_t ret;
    {
        synchronized synchronized_0(encryptedWriteBuffer);
        {
            if(npc(encryptedWriteBuffer)->limit() != 0) {
                return 0;
            }
            ret = writeHelper(srcs);
        }
    }
    if(ret < 0) {
        close();
    }
    return ret;
}

int64_t org::mpisws::p2p::transport::rc4::EncryptedSocket::writeHelper(::java::nio::ByteBuffer* srcs) /* throws(IOException) */
{
    int64_t ret;
    auto len = ::java::lang::Math::min(npc(encryptedBytes)->length - npc(encryptedWriteBuffer)->limit(), npc(srcs)->remaining());
    if(len == 0)
        return 0;

    try {
        npc(encryptCipher)->update(npc(srcs)->array(), npc(srcs)->position(), len, encryptedBytes, npc(encryptedWriteBuffer)->limit());
        npc(srcs)->position(npc(srcs)->position() + len);
        npc(encryptedWriteBuffer)->limit(npc(encryptedWriteBuffer)->limit() + len);
        ret = npc(socket)->write(encryptedWriteBuffer);
    } catch (::javax::crypto::ShortBufferException* sbe) {
        npc(logger)->logException(::java::lang::StringBuilder().append(u"We got a short buffer exception reading. This indicates a bug in the implementation. "_j)->append(static_cast< ::java::lang::Object* >(this))->toString(), sbe);
        return -int32_t(1);
    }
    if(ret < 0) {
        return ret;
    }
    if(npc(encryptedWriteBuffer)->hasRemaining()) {
        npc(socket)->register_(false, true, this);
        return len;
    } else {
        npc(encryptedWriteBuffer)->position(0);
        npc(encryptedWriteBuffer)->limit(0);
        if(npc(srcs)->hasRemaining()) {
            auto recursiveLen = writeHelper(srcs);
            if(recursiveLen < 0) {
                return recursiveLen;
            }
            return len + recursiveLen;
        }
        return len;
    }
}

void org::mpisws::p2p::transport::rc4::EncryptedSocket::receiveSelectResult(::org::mpisws::p2p::transport::P2PSocket* socket, bool canRead, bool canWrite) /* throws(IOException) */
{
    auto registerToWrite = false;
    {
        synchronized synchronized_1(encryptedWriteBuffer);
        {
            if(canWrite && npc(encryptedWriteBuffer)->hasRemaining()) {
                auto ret = npc(socket)->write(encryptedWriteBuffer);
                if(ret < 0) {
                    receiveException(static_cast< ::org::mpisws::p2p::transport::P2PSocket* >(socket), static_cast< ::java::lang::Exception* >(new ::org::mpisws::p2p::transport::ClosedChannelException(u"Socket was closed while writing buffered encrypted bytes."_j)));
                    return;
                }
                if(npc(encryptedWriteBuffer)->hasRemaining()) {
                    registerToWrite = true;
                    canWrite = false;
                } else {
                    npc(encryptedWriteBuffer)->position(0);
                    npc(encryptedWriteBuffer)->limit(0);
                    canWrite = (writer != nullptr);
                }
            }
        }
    }
    if(registerToWrite)
        npc(socket)->register_(false, true, this);

    if(canRead || canWrite)
        super::receiveSelectResult(static_cast< ::org::mpisws::p2p::transport::P2PSocket* >(socket), canRead, canWrite);

}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::rc4::EncryptedSocket::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.rc4.EncryptedSocket", 44);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::rc4::EncryptedSocket::getClass0()
{
    return class_();
}

