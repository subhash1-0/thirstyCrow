// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/history/stub/NullHashProvider.java
#include <org/mpisws/p2p/transport/peerreview/history/stub/NullHashProvider.hpp>

#include <java/lang/IllegalArgumentException.hpp>
#include <java/lang/String.hpp>
#include <Array.hpp>

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

org::mpisws::p2p::transport::peerreview::history::stub::NullHashProvider::NullHashProvider(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::transport::peerreview::history::stub::NullHashProvider::NullHashProvider()
    : NullHashProvider(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

int8_tArray*& org::mpisws::p2p::transport::peerreview::history::stub::NullHashProvider::EMPTY_HASH()
{
    clinit();
    return EMPTY_HASH_;
}
int8_tArray* org::mpisws::p2p::transport::peerreview::history::stub::NullHashProvider::EMPTY_HASH_;

int8_tArray* org::mpisws::p2p::transport::peerreview::history::stub::NullHashProvider::hash(int64_t seq, int16_t type, ::int8_tArray* nodeHash, ::int8_tArray* contentHash)
{
    return EMPTY_HASH_;
}

int8_tArray* org::mpisws::p2p::transport::peerreview::history::stub::NullHashProvider::hash(::java::nio::ByteBufferArray*/*...*/ hashMe)
{
    return EMPTY_HASH_;
}

int8_tArray* org::mpisws::p2p::transport::peerreview::history::stub::NullHashProvider::build(::rice::p2p::commonapi::rawserialization::InputBuffer* buf)
{
    return EMPTY_HASH_;
}

int8_tArray* org::mpisws::p2p::transport::peerreview::history::stub::NullHashProvider::getEmptyHash()
{
    return EMPTY_HASH_;
}

int16_t org::mpisws::p2p::transport::peerreview::history::stub::NullHashProvider::getHashSizeBytes()
{
    return 0;
}

int8_tArray* org::mpisws::p2p::transport::peerreview::history::stub::NullHashProvider::build(::int8_tArray* hashBytes, int32_t start, int32_t length)
{
    if(length > 0)
        throw new ::java::lang::IllegalArgumentException(u"Length must equal 0"_j);

    return EMPTY_HASH_;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::peerreview::history::stub::NullHashProvider::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.peerreview.history.stub.NullHashProvider", 65);
    return c;
}

void org::mpisws::p2p::transport::peerreview::history::stub::NullHashProvider::clinit()
{
    super::clinit();
    static bool in_cl_init = false;
struct clinit_ {
    clinit_() {
        in_cl_init = true;
        EMPTY_HASH_ = new ::int8_tArray(int32_t(0));
    }
};

    if(!in_cl_init) {
        static clinit_ clinit_instance;
    }
}

java::lang::Class* org::mpisws::p2p::transport::peerreview::history::stub::NullHashProvider::getClass0()
{
    return class_();
}

