// Generated from /pastry-2.1/src/rice/p2p/util/EncryptedOutputStream.java
#include <rice/p2p/util/EncryptedOutputStream.hpp>

#include <java/io/DataOutputStream.hpp>
#include <java/lang/IndexOutOfBoundsException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/System.hpp>
#include <java/security/PublicKey.hpp>
#include <rice/p2p/util/SecurityUtils.hpp>
#include <Array.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::util::EncryptedOutputStream::EncryptedOutputStream(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::util::EncryptedOutputStream::EncryptedOutputStream(::java::security::PublicKey* publicKey, ::java::io::OutputStream* stream, int32_t bufferSize)  /* throws(IOException) */
    : EncryptedOutputStream(*static_cast< ::default_init_tag* >(0))
{
    ctor(publicKey,stream,bufferSize);
}

void rice::p2p::util::EncryptedOutputStream::ctor(::java::security::PublicKey* publicKey, ::java::io::OutputStream* stream, int32_t bufferSize) /* throws(IOException) */
{
    super::ctor();
    BUFFER_SIZE = bufferSize;
    this->publicKey = publicKey;
    this->stream = new ::java::io::DataOutputStream(stream);
    this->key = SecurityUtils::generateKeySymmetric();
    this->buffer = new ::int8_tArray(BUFFER_SIZE);
    this->bufferLength = 0;
    writeHeader();
}

void rice::p2p::util::EncryptedOutputStream::writeHeader() /* throws(IOException) */
{
    auto enckey = SecurityUtils::encryptAsymmetric(key, publicKey);
    npc(stream)->writeInt(npc(enckey)->length);
    npc(stream)->write(enckey);
}

void rice::p2p::util::EncryptedOutputStream::write(int32_t b) /* throws(IOException) */
{
    write(new ::int8_tArray({static_cast< int8_t >((b & int32_t(255)))}));
}

void rice::p2p::util::EncryptedOutputStream::write(::int8_tArray* b, int32_t off, int32_t len) /* throws(IOException) */
{
    if(b == nullptr) {
        throw new ::java::lang::NullPointerException();
    } else if((off < 0) || (off > npc(b)->length) || (len < 0)|| ((off + len) > npc(b)->length)|| ((off + len) < 0)) {
        throw new ::java::lang::IndexOutOfBoundsException();
    } else if(len == 0) {
        return;
    }
    if(len <= BUFFER_SIZE - bufferLength) {
        ::java::lang::System::arraycopy(b, off, buffer, bufferLength, len);
        bufferLength += len;
    } else {
        auto l = BUFFER_SIZE - bufferLength;
        ::java::lang::System::arraycopy(b, off, buffer, bufferLength, l);
        bufferLength += l;
        writeBuffer();
        write(b, off + l, len - l);
    }
}

void rice::p2p::util::EncryptedOutputStream::writeBuffer() /* throws(IOException) */
{
    auto encdata = SecurityUtils::encryptSymmetric(buffer, key, 0, bufferLength);
    npc(stream)->writeInt(npc(encdata)->length);
    npc(stream)->write(encdata);
    this->bufferLength = 0;
}

void rice::p2p::util::EncryptedOutputStream::flush() /* throws(IOException) */
{
    writeBuffer();
    npc(stream)->flush();
}

void rice::p2p::util::EncryptedOutputStream::close() /* throws(IOException) */
{
    flush();
    npc(stream)->close();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::util::EncryptedOutputStream::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.util.EncryptedOutputStream", 35);
    return c;
}

void rice::p2p::util::EncryptedOutputStream::write(::int8_tArray* arg0)
{
    super::write(arg0);
}

java::lang::Class* rice::p2p::util::EncryptedOutputStream::getClass0()
{
    return class_();
}

