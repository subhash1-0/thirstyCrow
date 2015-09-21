// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/history/IndexEntry.java
#include <org/mpisws/p2p/transport/peerreview/history/IndexEntry.hpp>

#include <java/lang/NullPointerException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/p2p/commonapi/rawserialization/OutputBuffer.hpp>
#include <Array.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::transport::peerreview::history::IndexEntry::IndexEntry(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::transport::peerreview::history::IndexEntry::IndexEntry(int64_t seq) 
    : IndexEntry(*static_cast< ::default_init_tag* >(0))
{
    ctor(seq);
}

org::mpisws::p2p::transport::peerreview::history::IndexEntry::IndexEntry(int64_t seq, int64_t index, int16_t type, int32_t size, ::int8_tArray* contentHash, ::int8_tArray* nodeHash) 
    : IndexEntry(*static_cast< ::default_init_tag* >(0))
{
    ctor(seq,index,type,size,contentHash,nodeHash);
}

void org::mpisws::p2p::transport::peerreview::history::IndexEntry::ctor(int64_t seq)
{
    super::ctor();
    this->seq = seq;
}

void org::mpisws::p2p::transport::peerreview::history::IndexEntry::ctor(int64_t seq, int64_t index, int16_t type, int32_t size, ::int8_tArray* contentHash, ::int8_tArray* nodeHash)
{
    super::ctor();
    this->seq = seq;
    this->fileIndex = index;
    this->type = type;
    this->sizeInFile = size;
    this->contentHash = contentHash;
    this->nodeHash = nodeHash;
}

void org::mpisws::p2p::transport::peerreview::history::IndexEntry::serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */
{
    npc(buf)->writeLong(seq);
    npc(buf)->writeLong(fileIndex);
    npc(buf)->writeInt(sizeInFile);
    npc(buf)->writeShort(type);
    npc(buf)->write(contentHash, 0, npc(contentHash)->length);
    npc(buf)->write(nodeHash, 0, npc(nodeHash)->length);
}

int8_tArray* org::mpisws::p2p::transport::peerreview::history::IndexEntry::getContentHash()
{
    return contentHash;
}

int64_t org::mpisws::p2p::transport::peerreview::history::IndexEntry::getFileIndex()
{
    return fileIndex;
}

int8_tArray* org::mpisws::p2p::transport::peerreview::history::IndexEntry::getNodeHash()
{
    return nodeHash;
}

int64_t org::mpisws::p2p::transport::peerreview::history::IndexEntry::getSeq()
{
    return seq;
}

int32_t org::mpisws::p2p::transport::peerreview::history::IndexEntry::getSizeInFile()
{
    return sizeInFile;
}

int16_t org::mpisws::p2p::transport::peerreview::history::IndexEntry::getType()
{
    return type;
}

java::lang::String* org::mpisws::p2p::transport::peerreview::history::IndexEntry::toString()
{
    return ::java::lang::StringBuilder().append(u"IE{#"_j)->append(seq)
        ->append(u" t:"_j)
        ->append(type)
        ->append(u" s:"_j)
        ->append(sizeInFile)
        ->append(u"}"_j)->toString();
}

bool org::mpisws::p2p::transport::peerreview::history::IndexEntry::isHashed()
{
    return sizeInFile < 0;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::peerreview::history::IndexEntry::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.peerreview.history.IndexEntry", 54);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::peerreview::history::IndexEntry::getClass0()
{
    return class_();
}

