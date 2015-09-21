// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/audit/LogSnippet.java
#include <org/mpisws/p2p/transport/peerreview/audit/LogSnippet.hpp>

#include <java/io/IOException.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Comparable.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/nio/Buffer.hpp>
#include <java/nio/ByteBuffer.hpp>
#include <java/util/ArrayList.hpp>
#include <java/util/Arrays.hpp>
#include <java/util/Iterator.hpp>
#include <java/util/List.hpp>
#include <org/mpisws/p2p/transport/peerreview/audit/SnippetEntry.hpp>
#include <org/mpisws/p2p/transport/peerreview/history/HashProvider.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/p2p/commonapi/rawserialization/InputBuffer.hpp>
#include <rice/p2p/commonapi/rawserialization/OutputBuffer.hpp>
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

org::mpisws::p2p::transport::peerreview::audit::LogSnippet::LogSnippet(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::transport::peerreview::audit::LogSnippet::LogSnippet(::int8_tArray* baseHash, ::java::util::List* entries) 
    : LogSnippet(*static_cast< ::default_init_tag* >(0))
{
    ctor(baseHash,entries);
}

org::mpisws::p2p::transport::peerreview::audit::LogSnippet::LogSnippet(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, int32_t hashSize)  /* throws(IOException) */
    : LogSnippet(*static_cast< ::default_init_tag* >(0))
{
    ctor(buf,hashSize);
}

void org::mpisws::p2p::transport::peerreview::audit::LogSnippet::ctor(::int8_tArray* baseHash, ::java::util::List* entries)
{
    super::ctor();
    this->baseHash = baseHash;
    this->entries = entries;
}

java::lang::String* org::mpisws::p2p::transport::peerreview::audit::LogSnippet::toString()
{
    return ::java::lang::StringBuilder().append(u"LogSnippet["_j)->append(npc(java_cast< SnippetEntry* >(npc(entries)->get(0)))->seq)
        ->append(u"-"_j)
        ->append(npc(java_cast< SnippetEntry* >(npc(entries)->get(npc(entries)->size() - int32_t(1))))->seq)
        ->append(u"]"_j)->toString();
}

bool org::mpisws::p2p::transport::peerreview::audit::LogSnippet::equals(::java::lang::Object* o)
{
    auto that = java_cast< LogSnippet* >(o);
    if(!::java::util::Arrays::equals(this->baseHash, npc(that)->baseHash))
        return false;

    if(npc(java_cast< ::java::util::List* >(this->entries))->size() != npc(npc(that)->entries)->size())
        return false;

    auto i1 = npc(java_cast< ::java::util::List* >(this->entries))->iterator();
    auto i2 = npc(npc(that)->entries)->iterator();
    while (npc(i1)->hasNext()) {
        if(!npc(java_cast< SnippetEntry* >(npc(i1)->next()))->equals(static_cast< ::java::lang::Object* >(java_cast< SnippetEntry* >(npc(i2)->next()))))
            return false;

    }
    return true;
}

void org::mpisws::p2p::transport::peerreview::audit::LogSnippet::serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */
{
    npc(buf)->writeLong(npc(java_cast< SnippetEntry* >(npc(entries)->get(0)))->seq);
    npc(buf)->writeByte(static_cast< int8_t >(int32_t(0)));
    npc(buf)->write(baseHash, 0, npc(baseHash)->length);
    auto i = npc(entries)->iterator();
    auto prev = java_cast< SnippetEntry* >(npc(i)->next());
    npc(prev)->serialize(buf, nullptr);
    while (npc(i)->hasNext()) {
        auto cur = java_cast< SnippetEntry* >(npc(i)->next());
        npc(cur)->serialize(buf, prev);
        prev = cur;
    }
}

void org::mpisws::p2p::transport::peerreview::audit::LogSnippet::ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, int32_t hashSize) /* throws(IOException) */
{
    super::ctor();
    auto firstSeq = npc(buf)->readLong();
    if(npc(buf)->readByte() != 0)
        throw new ::java::io::IOException(u"Unexpected extInfo"_j);

    baseHash = new ::int8_tArray(hashSize);
    npc(buf)->read(baseHash);
    entries = new ::java::util::ArrayList();
    auto prev = new SnippetEntry(buf, firstSeq, hashSize);
    npc(entries)->add(static_cast< ::java::lang::Object* >(prev));
    while (npc(buf)->bytesRemaining() == -int32_t(2) || npc(buf)->bytesRemaining() > 0) {
        prev = new SnippetEntry(buf, hashSize, prev);
        npc(entries)->add(static_cast< ::java::lang::Object* >(prev));
    }
}

int8_tArray* org::mpisws::p2p::transport::peerreview::audit::LogSnippet::getBaseHash()
{
    return baseHash;
}

int64_t org::mpisws::p2p::transport::peerreview::audit::LogSnippet::getFirstSeq()
{
    return npc(java_cast< SnippetEntry* >(npc(entries)->get(0)))->seq;
}

java::lang::Object* org::mpisws::p2p::transport::peerreview::audit::LogSnippet::getExtInfo()
{
    return nullptr;
}

bool org::mpisws::p2p::transport::peerreview::audit::LogSnippet::checkHashChainContains(::int8_tArray* keyNodeHash, int64_t keyNodeSeq, ::org::mpisws::p2p::transport::peerreview::history::HashProvider* transport, ::rice::environment::logging::Logger* logger)
{
    /* assert((keyNodeHash != nullptr && (keyNodeSeq >= 0))) */ ;
    auto currentNodeHash = baseHash;
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(::java::lang::StringBuilder().append(u"Checking whether hash chain in snippet contains node #"_j)->append(keyNodeSeq)->toString());

    for (auto _i = npc(entries)->iterator(); _i->hasNext(); ) {
        SnippetEntry* entry = java_cast< SnippetEntry* >(_i->next());
        {
            if(npc(entry)->seq > keyNodeSeq)
                break;

            if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
                npc(logger)->log(::java::lang::StringBuilder().append(u"Entry "_j)->append(static_cast< ::java::lang::Object* >(entry))->toString());

            ::int8_tArray* contentHash;
            if(npc(entry)->isHash) {
                contentHash = npc(entry)->content;
            } else {
                contentHash = npc(transport)->hash(new ::java::nio::ByteBufferArray({::java::nio::ByteBuffer::wrap(npc(entry)->content)}));
            }
            currentNodeHash = npc(transport)->hash(npc(entry)->seq, npc(entry)->type, currentNodeHash, contentHash);
            if(npc(entry)->seq == keyNodeSeq) {
                if(::java::util::Arrays::equals(currentNodeHash, keyNodeHash)) {
                    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
                        npc(logger)->log(u"Yes, the node was found and has the specified hash"_j);

                    return true;
                } else {
                    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
                        npc(logger)->log(u"No, the node was found but has a different hash"_j);

                    return false;
                }
            }
        }
    }
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
        npc(logger)->log(u"No, a node with this sequence number was not found"_j);

    return false;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::peerreview::audit::LogSnippet::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.peerreview.audit.LogSnippet", 52);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::peerreview::audit::LogSnippet::getClass0()
{
    return class_();
}

