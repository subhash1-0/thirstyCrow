// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/audit/SnippetEntry.java
#include <org/mpisws/p2p/transport/peerreview/audit/SnippetEntry.hpp>

#include <java/io/IOException.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/IllegalArgumentException.hpp>
#include <java/lang/Integer.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/RuntimeException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/util/Arrays.hpp>
#include <rice/p2p/commonapi/rawserialization/InputBuffer.hpp>
#include <rice/p2p/commonapi/rawserialization/OutputBuffer.hpp>
#include <rice/p2p/util/MathUtils.hpp>
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

org::mpisws::p2p::transport::peerreview::audit::SnippetEntry::SnippetEntry(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::transport::peerreview::audit::SnippetEntry::SnippetEntry(int8_t type, int64_t seq, bool isHash, ::int8_tArray* content) 
    : SnippetEntry(*static_cast< ::default_init_tag* >(0))
{
    ctor(type,seq,isHash,content);
}

org::mpisws::p2p::transport::peerreview::audit::SnippetEntry::SnippetEntry(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, int32_t hashSize, SnippetEntry* prev)  /* throws(IOException) */
    : SnippetEntry(*static_cast< ::default_init_tag* >(0))
{
    ctor(buf,hashSize,prev);
}

org::mpisws::p2p::transport::peerreview::audit::SnippetEntry::SnippetEntry(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, int64_t seq, int32_t hashSize)  /* throws(IOException) */
    : SnippetEntry(*static_cast< ::default_init_tag* >(0))
{
    ctor(buf,seq,hashSize);
}

void org::mpisws::p2p::transport::peerreview::audit::SnippetEntry::init()
{
    isHash = false;
}

constexpr int32_t org::mpisws::p2p::transport::peerreview::audit::SnippetEntry::NUM_INDEXES;

void org::mpisws::p2p::transport::peerreview::audit::SnippetEntry::ctor(int8_t type, int64_t seq, bool isHash, ::int8_tArray* content)
{
    super::ctor();
    init();
    if(npc(content)->length == 0)
        throw new ::java::lang::IllegalArgumentException(u"Content can't be zero-length"_j);

    this->type = type;
    this->seq = seq;
    this->isHash = isHash;
    this->content = content;
}

void org::mpisws::p2p::transport::peerreview::audit::SnippetEntry::ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, int32_t hashSize, SnippetEntry* prev) /* throws(IOException) */
{
    ctor(buf, decodeSeq(buf, npc(prev)->seq), hashSize);
}

bool org::mpisws::p2p::transport::peerreview::audit::SnippetEntry::equals(::java::lang::Object* o)
{
    auto that = java_cast< SnippetEntry* >(o);
    if(this->type != npc(that)->type)
        return false;

    if(this->seq != npc(that)->seq)
        return false;

    if(this->isHash != npc(that)->isHash)
        return false;

    return ::java::util::Arrays::equals(content, content);
}

void org::mpisws::p2p::transport::peerreview::audit::SnippetEntry::ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, int64_t seq, int32_t hashSize) /* throws(IOException) */
{
    super::ctor();
    init();
    type = npc(buf)->readByte();
    this->seq = seq;
    auto size = decodeSize(buf);
    isHash = false;
    if(size == 0) {
        isHash = true;
        size = hashSize;
    }
    content = new ::int8_tArray(size);
    npc(buf)->read(content);
}

java::lang::String* org::mpisws::p2p::transport::peerreview::audit::SnippetEntry::toString()
{
    return ::java::lang::StringBuilder().append(u"SEntry type:"_j)->append(type)
        ->append(u" seq:"_j)
        ->append(seq)
        ->append(u" "_j)
        ->append((isHash ? u"hash"_j : u"not hash"_j))
        ->append(u" len:"_j)
        ->append(npc(content)->length)->toString();
}

void org::mpisws::p2p::transport::peerreview::audit::SnippetEntry::serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf, SnippetEntry* prev) /* throws(IOException) */
{
    if(prev != nullptr) {
        encodeSeq(buf, npc(prev)->seq);
    }
    npc(buf)->writeByte(type);
    encodeSize(buf);
    npc(buf)->write(content, 0, npc(content)->length);
}

int64_t org::mpisws::p2p::transport::peerreview::audit::SnippetEntry::decodeSeq(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, int64_t prevSeq) /* throws(IOException) */
{
    clinit();
    auto b = npc(buf)->readByte();
    if(b == static_cast< int8_t >(int32_t(0)))
        return prevSeq + int32_t(1);

    if(b == static_cast< int8_t >(int32_t(255)))
        return npc(buf)->readLong();

    int64_t howMuchBigger = ::rice::p2p::util::MathUtils::uByteToInt(b) * NUM_INDEXES;
    auto prevSeqMS = ((prevSeq / NUM_INDEXES) * NUM_INDEXES);
    return prevSeqMS + howMuchBigger;
}

void org::mpisws::p2p::transport::peerreview::audit::SnippetEntry::encodeSeq(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf, int64_t prevSeq) /* throws(IOException) */
{
    if(seq == prevSeq + int32_t(1)) {
        npc(buf)->writeByte(static_cast< int8_t >(int32_t(0)));
        return;
    }
    if((seq % NUM_INDEXES == 0)) {
        auto foo = ((seq / NUM_INDEXES) - (prevSeq / NUM_INDEXES));
        if(foo < 255) {
            if(foo < 0)
                throw new ::java::io::IOException(::java::lang::StringBuilder().append(u"bug in encodeSeq.  foo:"_j)->append(foo)
                    ->append(u" seq:"_j)
                    ->append(seq)
                    ->append(u" prevSeq:"_j)
                    ->append(prevSeq)->toString());

            npc(buf)->writeByte(static_cast< int8_t >(foo));
            return;
        }
    }
    npc(buf)->writeByte(static_cast< int8_t >(int32_t(255)));
    npc(buf)->writeLong(seq);
}

int8_t org::mpisws::p2p::transport::peerreview::audit::SnippetEntry::getSizeCode()
{
    if(isHash)
        return 0;

    if(npc(content)->length < 254) {
        return static_cast< int8_t >(npc(content)->length);
    }
    if(npc(content)->length < 65535)
        return static_cast< int8_t >(int32_t(255));

    if(npc(content)->length > ::java::lang::Integer::MAX_VALUE)
        throw new ::java::lang::RuntimeException(::java::lang::StringBuilder().append(u"content is too long:"_j)->append(npc(content)->length)->toString());

    return static_cast< int8_t >(int32_t(254));
}

void org::mpisws::p2p::transport::peerreview::audit::SnippetEntry::encodeSize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */
{
    if(isHash) {
        npc(buf)->writeByte(static_cast< int8_t >(int32_t(0)));
        return;
    }
    if(npc(content)->length < 254) {
        npc(buf)->writeByte(static_cast< int8_t >(npc(content)->length));
        return;
    }
    if(npc(content)->length < 65535) {
        npc(buf)->writeByte(static_cast< int8_t >(int32_t(255)));
        npc(buf)->writeShort(static_cast< int16_t >(npc(content)->length));
        return;
    }
    if(npc(content)->length > ::java::lang::Integer::MAX_VALUE)
        throw new ::java::lang::RuntimeException(::java::lang::StringBuilder().append(u"content is too long:"_j)->append(npc(content)->length)->toString());

    npc(buf)->writeByte(static_cast< int8_t >(int32_t(254)));
    npc(buf)->writeInt(npc(content)->length);
}

int32_t org::mpisws::p2p::transport::peerreview::audit::SnippetEntry::decodeSize(::rice::p2p::commonapi::rawserialization::InputBuffer* buf) /* throws(IOException) */
{
    auto b = npc(buf)->readByte();
    if(b == static_cast< int8_t >(int32_t(255))) {
        return ::rice::p2p::util::MathUtils::uShortToInt(npc(buf)->readShort());
    }
    if(b == static_cast< int8_t >(int32_t(254))) {
        return npc(buf)->readInt();
    }
    return ::rice::p2p::util::MathUtils::uByteToInt(b);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::peerreview::audit::SnippetEntry::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.peerreview.audit.SnippetEntry", 54);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::peerreview::audit::SnippetEntry::getClass0()
{
    return class_();
}

