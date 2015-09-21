// Generated from /pastry-2.1/src/rice/p2p/util/EncryptedInputStream.java
#include <rice/p2p/util/EncryptedInputStream.hpp>

#include <java/io/DataInputStream.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/System.hpp>
#include <java/security/PrivateKey.hpp>
#include <rice/p2p/util/SecurityUtils.hpp>
#include <Array.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::util::EncryptedInputStream::EncryptedInputStream(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::util::EncryptedInputStream::EncryptedInputStream(::java::security::PrivateKey* privateKey, ::java::io::InputStream* stream)  /* throws(IOException) */
    : EncryptedInputStream(*static_cast< ::default_init_tag* >(0))
{
    ctor(privateKey,stream);
}

void rice::p2p::util::EncryptedInputStream::ctor(::java::security::PrivateKey* privateKey, ::java::io::InputStream* stream) /* throws(IOException) */
{
    super::ctor();
    this->privateKey = privateKey;
    this->stream = new ::java::io::DataInputStream(stream);
    readHeader();
}

void rice::p2p::util::EncryptedInputStream::readHeader() /* throws(IOException) */
{
    auto enckey = new ::int8_tArray(npc(stream)->readInt());
    npc(stream)->readFully(enckey);
    this->key = SecurityUtils::decryptAsymmetric(enckey, privateKey);
}

int32_t rice::p2p::util::EncryptedInputStream::read() /* throws(IOException) */
{
    if((buffer != nullptr) && (bufferLength < npc(buffer)->length)) {
        bufferLength++;
        return (*buffer)[bufferLength - int32_t(1)] & int32_t(255);
    } else {
        readBuffer();
        return read();
    }
}

int32_t rice::p2p::util::EncryptedInputStream::read(::int8_tArray* b, int32_t off, int32_t len) /* throws(IOException) */
{
    if((buffer != nullptr) && (bufferLength < npc(buffer)->length)) {
        auto l = (len > available() ? available() : len);
        ::java::lang::System::arraycopy(buffer, bufferLength, b, off, l);
        bufferLength += l;
        return l;
    } else {
        readBuffer();
        return read(b, off, len);
    }
}

void rice::p2p::util::EncryptedInputStream::readBuffer() /* throws(IOException) */
{
    auto encdata = new ::int8_tArray(npc(stream)->readInt());
    npc(stream)->readFully(encdata);
    this->buffer = SecurityUtils::decryptSymmetric(encdata, key);
    this->bufferLength = 0;
}

int32_t rice::p2p::util::EncryptedInputStream::available() /* throws(IOException) */
{
    if(buffer == nullptr)
        return 0;
    else
        return npc(buffer)->length - bufferLength;
}

void rice::p2p::util::EncryptedInputStream::close() /* throws(IOException) */
{
    npc(stream)->close();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::util::EncryptedInputStream::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.util.EncryptedInputStream", 34);
    return c;
}

int32_t rice::p2p::util::EncryptedInputStream::read(::int8_tArray* arg0)
{
    return super::read(arg0);
}

java::lang::Class* rice::p2p::util::EncryptedInputStream::getClass0()
{
    return class_();
}

