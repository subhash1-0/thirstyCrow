// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/history/hasher/SHA1HashProvider.java
#include <org/mpisws/p2p/transport/peerreview/history/hasher/SHA1HashProvider.hpp>

#include <java/io/IOException.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/Comparable.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/RuntimeException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/Throwable.hpp>
#include <java/nio/Buffer.hpp>
#include <java/nio/ByteBuffer.hpp>
#include <java/security/MessageDigest.hpp>
#include <rice/p2p/util/rawserialization/SimpleOutputBuffer.hpp>
#include <Array.hpp>
#include <SubArray.hpp>
#include <ObjectArray.hpp>

template<typename ComponentType, typename... Bases> struct SubArray;
namespace java
{
    namespace lang
    {
typedef ::SubArray< ::java::lang::Comparable, ObjectArray > ComparableArray;
    } // lang

    namespace nio
    {
typedef ::SubArray< ::java::nio::Buffer, ::java::lang::ObjectArray > BufferArray;
typedef ::SubArray< ::java::nio::ByteBuffer, BufferArray, ::java::lang::ComparableArray > ByteBufferArray;
    } // nio
} // java

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::transport::peerreview::history::hasher::SHA1HashProvider::SHA1HashProvider(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::transport::peerreview::history::hasher::SHA1HashProvider::SHA1HashProvider()  /* throws(NoSuchAlgorithmException) */
    : SHA1HashProvider(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

void org::mpisws::p2p::transport::peerreview::history::hasher::SHA1HashProvider::ctor() /* throws(NoSuchAlgorithmException) */
{
    super::ctor();
    md = ::java::security::MessageDigest::getInstance(u"SHA"_j);
}

int8_tArray* org::mpisws::p2p::transport::peerreview::history::hasher::SHA1HashProvider::getEmptyHash()
{
    return new ::int8_tArray(getHashSizeBytes());
}

int16_t org::mpisws::p2p::transport::peerreview::history::hasher::SHA1HashProvider::getHashSizeBytes()
{
    return 20;
}

int8_tArray* org::mpisws::p2p::transport::peerreview::history::hasher::SHA1HashProvider::hash(int64_t seq, int16_t type, ::int8_tArray* nodeHash, ::int8_tArray* contentHash)
{
    try {
        auto sob = new ::rice::p2p::util::rawserialization::SimpleOutputBuffer();
        npc(sob)->writeLong(seq);
        npc(sob)->writeShort(type);
        npc(sob)->write(nodeHash);
        npc(sob)->write(contentHash);
        return hash(new ::java::nio::ByteBufferArray({npc(sob)->getByteBuffer()}));
    } catch (::java::io::IOException* ioe) {
        throw new ::java::lang::RuntimeException(static_cast< ::java::lang::Throwable* >(ioe));
    }
}

int8_tArray* org::mpisws::p2p::transport::peerreview::history::hasher::SHA1HashProvider::hash(::java::nio::ByteBufferArray*/*...*/ hashMe)
{
    for(auto bb : *npc(hashMe)) {
        auto pos = npc(bb)->position();
        npc(md)->update(bb);
        npc(bb)->position(pos);
    }
    auto ret = npc(md)->digest();
    return ret;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::peerreview::history::hasher::SHA1HashProvider::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.peerreview.history.hasher.SHA1HashProvider", 67);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::peerreview::history::hasher::SHA1HashProvider::getClass0()
{
    return class_();
}

