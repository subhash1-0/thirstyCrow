// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/commitment/Authenticator.java
#include <org/mpisws/p2p/transport/peerreview/commitment/Authenticator.hpp>

#include <java/io/IOException.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/RuntimeException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/Throwable.hpp>
#include <java/nio/ByteBuffer.hpp>
#include <java/util/Arrays.hpp>
#include <rice/p2p/commonapi/rawserialization/InputBuffer.hpp>
#include <rice/p2p/commonapi/rawserialization/OutputBuffer.hpp>
#include <rice/p2p/util/MathUtils.hpp>
#include <rice/p2p/util/rawserialization/SimpleOutputBuffer.hpp>
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

org::mpisws::p2p::transport::peerreview::commitment::Authenticator::Authenticator(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::transport::peerreview::commitment::Authenticator::Authenticator(int64_t seq, ::int8_tArray* hash, ::int8_tArray* signature) 
    : Authenticator(*static_cast< ::default_init_tag* >(0))
{
    ctor(seq,hash,signature);
}

org::mpisws::p2p::transport::peerreview::commitment::Authenticator::Authenticator(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, int32_t hashSize, int32_t signatureSize)  /* throws(IOException) */
    : Authenticator(*static_cast< ::default_init_tag* >(0))
{
    ctor(buf,hashSize,signatureSize);
}

void org::mpisws::p2p::transport::peerreview::commitment::Authenticator::init()
{
    hashCode_ = int32_t(0);
}

void org::mpisws::p2p::transport::peerreview::commitment::Authenticator::ctor(int64_t seq, ::int8_tArray* hash, ::int8_tArray* signature)
{
    super::ctor();
    init();
    this->seq = seq;
    this->hash = hash;
    this->signature = signature;
    hashCode_ = static_cast< int32_t >((seq ^ (static_cast<int64_t>(static_cast<uint64_t>(seq) >> int32_t(32))))) ^ ::java::util::Arrays::hashCode(hash) ^ ::java::util::Arrays::hashCode(signature);
}

java::nio::ByteBuffer* org::mpisws::p2p::transport::peerreview::commitment::Authenticator::getPartToHashThenSign()
{
    auto sob = new ::rice::p2p::util::rawserialization::SimpleOutputBuffer();
    try {
        npc(sob)->writeLong(seq);
        npc(sob)->write(hash);
    } catch (::java::io::IOException* ioe) {
        throw new ::java::lang::RuntimeException(static_cast< ::java::lang::Throwable* >(ioe));
    }
    return npc(sob)->getByteBuffer();
}

void org::mpisws::p2p::transport::peerreview::commitment::Authenticator::ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, int32_t hashSize, int32_t signatureSize) /* throws(IOException) */
{
    super::ctor();
    init();
    seq = npc(buf)->readLong();
    hash = new ::int8_tArray(hashSize);
    npc(buf)->read(hash);
    signature = new ::int8_tArray(signatureSize);
    npc(buf)->read(signature);
    hashCode_ = static_cast< int32_t >((seq ^ (static_cast<int64_t>(static_cast<uint64_t>(seq) >> int32_t(32))))) ^ ::java::util::Arrays::hashCode(hash) ^ ::java::util::Arrays::hashCode(signature);
}

void org::mpisws::p2p::transport::peerreview::commitment::Authenticator::serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */
{
    npc(buf)->writeLong(seq);
    npc(buf)->write(hash, 0, npc(hash)->length);
    npc(buf)->write(signature, 0, npc(signature)->length);
}

int32_t org::mpisws::p2p::transport::peerreview::commitment::Authenticator::hashCode()
{
    return hashCode_;
}

bool org::mpisws::p2p::transport::peerreview::commitment::Authenticator::equals(::java::lang::Object* o)
{
    auto that = java_cast< Authenticator* >(o);
    if(seq == npc(that)->seq) {
        if(::java::util::Arrays::equals(hash, npc(that)->hash)) {
            if(::java::util::Arrays::equals(signature, npc(that)->signature)) {
                return true;
            }
        }
    }
    return false;
}

int32_t org::mpisws::p2p::transport::peerreview::commitment::Authenticator::compareTo(Authenticator* that)
{
    if(this->seq > npc(that)->seq)
        return -int32_t(1);

    if(this->seq < npc(that)->seq)
        return 1;

    if(this->hash == nullptr) {
        return 1;
    }
    if(npc(that)->hash == nullptr) {
        return -int32_t(1);
    }
    if(this->hashCode_ == npc(that)->hashCode_) {
        if(this->equals(static_cast< ::java::lang::Object* >(that))) {
            return 0;
        }
    }
    auto ret = npc(::java::nio::ByteBuffer::wrap(hash))->compareTo(::java::nio::ByteBuffer::wrap(npc(that)->hash));
    if(ret == 0) {
        return npc(::java::nio::ByteBuffer::wrap(signature))->compareTo(::java::nio::ByteBuffer::wrap(npc(that)->signature));
    }
    return ret;
}

int32_t org::mpisws::p2p::transport::peerreview::commitment::Authenticator::compareTo(::java::lang::Object* o)
{ 
    return compareTo(dynamic_cast< Authenticator* >(o));
}

int64_t org::mpisws::p2p::transport::peerreview::commitment::Authenticator::getSeq()
{
    return seq;
}

java::lang::String* org::mpisws::p2p::transport::peerreview::commitment::Authenticator::toString()
{
    return ::java::lang::StringBuilder().append(seq)->append(u" "_j)
        ->append(::rice::p2p::util::MathUtils::toHex(hash))
        ->append(u" "_j)
        ->append(::rice::p2p::util::MathUtils::toHex(signature))->toString();
}

int8_tArray* org::mpisws::p2p::transport::peerreview::commitment::Authenticator::getHash()
{
    return hash;
}

int8_tArray* org::mpisws::p2p::transport::peerreview::commitment::Authenticator::getSignature()
{
    return signature;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::peerreview::commitment::Authenticator::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.peerreview.commitment.Authenticator", 60);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::peerreview::commitment::Authenticator::getClass0()
{
    return class_();
}

