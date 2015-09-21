// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/history/SecureHistoryImpl.java
#include <org/mpisws/p2p/transport/peerreview/history/SecureHistoryImpl.hpp>

#include <java/io/IOException.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Comparable.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/IllegalArgumentException.hpp>
#include <java/lang/IllegalStateException.hpp>
#include <java/lang/Math.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/RuntimeException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/nio/Buffer.hpp>
#include <java/nio/ByteBuffer.hpp>
#include <java/util/ArrayList.hpp>
#include <java/util/Iterator.hpp>
#include <java/util/List.hpp>
#include <org/mpisws/p2p/transport/peerreview/audit/LogSnippet.hpp>
#include <org/mpisws/p2p/transport/peerreview/audit/SnippetEntry.hpp>
#include <org/mpisws/p2p/transport/peerreview/history/HashPolicy.hpp>
#include <org/mpisws/p2p/transport/peerreview/history/HashProvider.hpp>
#include <org/mpisws/p2p/transport/peerreview/history/HashSeq.hpp>
#include <org/mpisws/p2p/transport/peerreview/history/IndexEntry.hpp>
#include <org/mpisws/p2p/transport/peerreview/history/IndexEntryFactory.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/p2p/commonapi/rawserialization/OutputBuffer.hpp>
#include <rice/p2p/util/RandomAccessFileIOBuffer.hpp>
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

org::mpisws::p2p::transport::peerreview::history::SecureHistoryImpl::SecureHistoryImpl(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::transport::peerreview::history::SecureHistoryImpl::SecureHistoryImpl(::rice::p2p::util::RandomAccessFileIOBuffer* indexFile, ::rice::p2p::util::RandomAccessFileIOBuffer* dataFile, bool readOnly, HashProvider* hashProv, IndexEntryFactory* indexFactory, ::rice::environment::logging::Logger* logger)  /* throws(IOException) */
    : SecureHistoryImpl(*static_cast< ::default_init_tag* >(0))
{
    ctor(indexFile,dataFile,readOnly,hashProv,indexFactory,logger);
}

void org::mpisws::p2p::transport::peerreview::history::SecureHistoryImpl::ctor(::rice::p2p::util::RandomAccessFileIOBuffer* indexFile, ::rice::p2p::util::RandomAccessFileIOBuffer* dataFile, bool readOnly, HashProvider* hashProv, IndexEntryFactory* indexFactory, ::rice::environment::logging::Logger* logger) /* throws(IOException) */
{
    super::ctor();
    /* assert((indexFile != nullptr && dataFile != nullptr)) */ ;
    this->logger = logger;
    if(logger == nullptr)
        throw new ::java::lang::IllegalArgumentException(u"logger is null"_j);

    this->indexFactory = indexFactory;
    npc(indexFile)->seek(0);
    auto firstEntry = npc(indexFactory)->build(indexFile);
    baseSeq = npc(firstEntry)->seq;
    npc(indexFile)->seek(npc(indexFile)->length() - npc(indexFactory)->getSerializedSize());
    topEntry = npc(indexFactory)->build(indexFile);
    numEntries = static_cast< int32_t >((npc(indexFile)->length() / npc(indexFactory)->getSerializedSize()));
    npc(dataFile)->seek(npc(dataFile)->length());
    nextSeq = npc(topEntry)->seq + int32_t(1);
    pointerAtEnd = true;
    this->indexFile = indexFile;
    this->dataFile = dataFile;
    this->readOnly = readOnly;
    this->hashProv = hashProv;
}

int64_t org::mpisws::p2p::transport::peerreview::history::SecureHistoryImpl::getBaseSeq()
{
    return baseSeq;
}

int64_t org::mpisws::p2p::transport::peerreview::history::SecureHistoryImpl::getLastSeq()
{
    return npc(topEntry)->seq;
}

int64_t org::mpisws::p2p::transport::peerreview::history::SecureHistoryImpl::getNumEntries()
{
    return numEntries;
}

org::mpisws::p2p::transport::peerreview::history::HashSeq* org::mpisws::p2p::transport::peerreview::history::SecureHistoryImpl::getTopLevelEntry()
{
    return new HashSeq(npc(topEntry)->nodeHash, npc(topEntry)->seq);
}

void org::mpisws::p2p::transport::peerreview::history::SecureHistoryImpl::appendEntry(int16_t type, bool storeFullEntry, ::java::nio::ByteBufferArray*/*...*/ entry) /* throws(IOException) */
{
    /* assert((indexFile != nullptr && dataFile != nullptr)) */ ;
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
        npc(logger)->log(::java::lang::StringBuilder().append(u"appendEntry("_j)->append(type)
            ->append(u","_j)
            ->append(storeFullEntry)
            ->append(u","_j)
            ->append(npc(entry)->length)
            ->append(u","_j)
            ->append(npc((*entry)[int32_t(0)])->remaining())
            ->append(u"):"_j)
            ->append(nextSeq)->toString());

    if(readOnly)
        throw new ::java::lang::IllegalStateException(u"Cannot append entry to readonly history"_j);

    if(!pointerAtEnd) {
        npc(indexFile)->seek(npc(indexFile)->length());
        npc(dataFile)->seek(npc(dataFile)->length());
        pointerAtEnd = true;
    }
    auto e = new IndexEntry(nextSeq++);
    npc(e)->contentHash = npc(hashProv)->hash(entry);
    npc(e)->nodeHash = npc(hashProv)->hash(npc(e)->seq, type, npc(topEntry)->nodeHash, npc(e)->contentHash);
    npc(e)->type = type;
    npc(e)->fileIndex = npc(dataFile)->getFilePointer();
    if(storeFullEntry) {
        npc(e)->sizeInFile = 0;
        for(auto ent : *npc(entry)) {
            npc(e)->sizeInFile += npc(ent)->remaining();
            npc(dataFile)->write(npc(ent)->array(), npc(ent)->position(), npc(ent)->remaining());
        }
    } else {
        npc(e)->sizeInFile = -int32_t(1);
    }
    topEntry = e;
    npc(topEntry)->serialize(indexFile);
    numEntries++;
}

void org::mpisws::p2p::transport::peerreview::history::SecureHistoryImpl::appendHash(int16_t type, ::int8_tArray* hash) /* throws(IOException) */
{
    /* assert((indexFile != nullptr && dataFile != nullptr)) */ ;
    if(readOnly)
        throw new ::java::lang::IllegalStateException(u"Cannot append entry to readonly history"_j);

    if(!pointerAtEnd) {
        npc(indexFile)->seek(npc(indexFile)->length());
        npc(dataFile)->seek(npc(dataFile)->length());
        pointerAtEnd = true;
    }
    auto e = new IndexEntry(nextSeq++);
    npc(e)->contentHash = hash;
    npc(e)->nodeHash = npc(hashProv)->hash(npc(e)->seq, type, npc(topEntry)->nodeHash, npc(e)->contentHash);
    npc(e)->type = type;
    npc(e)->fileIndex = -int32_t(1);
    npc(e)->sizeInFile = -int32_t(1);
    topEntry = e;
    npc(topEntry)->serialize(indexFile);
    numEntries++;
}

bool org::mpisws::p2p::transport::peerreview::history::SecureHistoryImpl::setNextSeq(int64_t nextSeq)
{
    if(nextSeq < this->nextSeq)
        return false;

    this->nextSeq = nextSeq;
    return true;
}

void org::mpisws::p2p::transport::peerreview::history::SecureHistoryImpl::close() /* throws(IOException) */
{
    /* assert((indexFile != nullptr && dataFile != nullptr)) */ ;
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->logException(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(this))->append(u".close()"_j)->toString(), new ::java::lang::Exception(u"Stack Trace"_j));

    npc(indexFile)->close();
    npc(dataFile)->close();
    indexFile = nullptr;
    dataFile = nullptr;
}

int64_t org::mpisws::p2p::transport::peerreview::history::SecureHistoryImpl::findSeq(int64_t seq) /* throws(IOException) */
{
    return findSeqOrHigher(seq, false);
}

int64_t org::mpisws::p2p::transport::peerreview::history::SecureHistoryImpl::findSeqOrHigher(int64_t seq, bool allowHigher) /* throws(IOException) */
{
    /* assert((indexFile != nullptr && dataFile != nullptr)) */ ;
    if(seq > npc(topEntry)->seq)
        return -int32_t(1);

    if(allowHigher && (seq < baseSeq))
        return 0;

    if(seq == npc(topEntry)->seq)
        return numEntries - int32_t(1);

    pointerAtEnd = false;
    npc(indexFile)->seek(npc(indexFile)->length());
    int64_t rbegin = int32_t(1);
    auto rend = (npc(indexFile)->getFilePointer() / static_cast< int64_t >(npc(indexFactory)->getSerializedSize())) - int32_t(1);
    while (rbegin != rend) {
        /* assert((rend >= rbegin)) */ ;
        auto pivot = (rbegin + rend) / int32_t(2);
        npc(indexFile)->seek(pivot * npc(indexFactory)->getSerializedSize());
        auto ie = npc(indexFactory)->build(indexFile);
        if(npc(ie)->seq >= seq)
            rend = pivot;
        else
            rbegin = pivot + int32_t(1);
    }
    if(allowHigher)
        return rbegin;

    npc(indexFile)->seek(rbegin * npc(indexFactory)->getSerializedSize());
    auto ie = npc(indexFactory)->build(indexFile);
    if(npc(ie)->seq != seq)
        return -int32_t(1);

    return rbegin;
}

org::mpisws::p2p::transport::peerreview::audit::LogSnippet* org::mpisws::p2p::transport::peerreview::history::SecureHistoryImpl::serializeRange(int64_t idxFrom, int64_t idxTo, HashPolicy* hashPolicy) /* throws(IOException) */
{
    /* assert(((0 < idxFrom) && (idxFrom <= idxTo) && (idxTo < numEntries))) */ ;
    IndexEntry* ie;
    pointerAtEnd = false;
    npc(indexFile)->seek((idxFrom - int32_t(1)) * npc(indexFactory)->getSerializedSize());
    ie = npc(indexFactory)->build(indexFile);
    auto baseHash = npc(ie)->nodeHash;
    auto entryList = new ::java::util::ArrayList();
    int64_t previousSeq = -int32_t(1);
    for (auto idx = idxFrom; idx <= idxTo; idx++) {
        ie = npc(indexFactory)->build(indexFile);
        if(ie == nullptr)
            throw new ::java::io::IOException(u"History read error"_j);

        /* assert(((previousSeq == -int32_t(1)) || (npc(ie)->seq > previousSeq))) */ ;
        ::int8_tArray* buffer = nullptr;
        if(npc(ie)->sizeInFile > 0) {
            buffer = new ::int8_tArray(static_cast< int32_t >(npc(ie)->sizeInFile));
            /* assert((npc(ie)->fileIndex >= 0)) */ ;
            npc(dataFile)->seek(npc(ie)->fileIndex);
            npc(dataFile)->read(buffer);
        }
        auto hashIt = (npc(ie)->sizeInFile < 0) || (hashPolicy != nullptr && npc(hashPolicy)->hashEntry(npc(ie)->type, buffer));
        if(hashIt) {
            buffer = npc(ie)->contentHash;
        }
        auto entry = new ::org::mpisws::p2p::transport::peerreview::audit::SnippetEntry(static_cast< int8_t >(npc(ie)->type), npc(ie)->seq, hashIt, buffer);
        npc(entryList)->add(static_cast< ::java::lang::Object* >(entry));
    }
    auto ret = new ::org::mpisws::p2p::transport::peerreview::audit::LogSnippet(baseHash, static_cast< ::java::util::List* >(entryList));
    return ret;
}

bool org::mpisws::p2p::transport::peerreview::history::SecureHistoryImpl::serializeRange2(int64_t idxFrom, int64_t idxTo, HashPolicy* hashPolicy, ::rice::p2p::commonapi::rawserialization::OutputBuffer* outfile) /* throws(IOException) */
{
    /* assert(((0 < idxFrom) && (idxFrom <= idxTo) && (idxTo < numEntries))) */ ;
    IndexEntry* ie;
    pointerAtEnd = false;
    npc(indexFile)->seek((idxFrom - int32_t(1)) * npc(indexFactory)->getSerializedSize());
    ie = npc(indexFactory)->build(indexFile);
    npc(outfile)->write(npc(ie)->nodeHash, 0, npc(npc(ie)->nodeHash)->length);
    int64_t previousSeq = -int32_t(1);
    for (auto idx = idxFrom; idx <= idxTo; idx++) {
        ie = npc(indexFactory)->build(indexFile);
        if(ie == nullptr)
            throw new ::java::io::IOException(u"History read error"_j);

        /* assert(((previousSeq == -int32_t(1)) || (npc(ie)->seq > previousSeq))) */ ;
        if(previousSeq >= 0) {
            if(npc(ie)->seq == (previousSeq + int32_t(1))) {
                npc(outfile)->writeByte(static_cast< int8_t >(int32_t(0)));
            } else {
                auto dhigh = (npc(ie)->seq / int32_t(1000)) - (previousSeq / int32_t(1000));
                if((dhigh < 255) && ((npc(ie)->seq % int32_t(1000)) == 0)) {
                    npc(outfile)->writeByte(static_cast< int8_t >((dhigh & int32_t(255))));
                } else {
                    npc(outfile)->writeByte(static_cast< int8_t >(int32_t(255)));
                    npc(outfile)->writeLong(npc(ie)->seq);
                }
            }
        }
        previousSeq = npc(ie)->seq;
        npc(outfile)->writeShort(npc(ie)->type);
        ::int8_tArray* buffer = nullptr;
        if(npc(ie)->sizeInFile > 0) {
            buffer = new ::int8_tArray(static_cast< int32_t >(npc(ie)->sizeInFile));
            /* assert((npc(ie)->fileIndex >= 0)) */ ;
            npc(dataFile)->seek(npc(ie)->fileIndex);
            npc(dataFile)->read(buffer);
        }
        auto hashIt = (npc(ie)->sizeInFile < 0) || (hashPolicy != nullptr && npc(hashPolicy)->hashEntry(npc(ie)->type, buffer));
        if(hashIt) {
            npc(outfile)->writeByte(static_cast< int8_t >(int32_t(0)));
            npc(outfile)->write(npc(ie)->contentHash, 0, npc(npc(ie)->contentHash)->length);
        } else if(npc(ie)->sizeInFile < 255) {
            npc(outfile)->writeByte(static_cast< int8_t >((npc(ie)->sizeInFile & int32_t(255))));
        } else if(npc(ie)->sizeInFile < 65536) {
            npc(outfile)->writeByte(static_cast< int8_t >(int32_t(255)));
            npc(outfile)->writeShort(static_cast< int16_t >((npc(ie)->sizeInFile & int32_t(65535))));
        } else {
            npc(outfile)->writeByte(static_cast< int8_t >(int32_t(254)));
            npc(outfile)->writeLong(npc(ie)->sizeInFile);
        }
        if(!hashIt) {
            npc(outfile)->write(buffer, 0, npc(buffer)->length);
        }
    }
    return true;
}

org::mpisws::p2p::transport::peerreview::history::IndexEntry* org::mpisws::p2p::transport::peerreview::history::SecureHistoryImpl::statEntry(int64_t idx) /* throws(IOException) */
{
    if((idx < 0) || (idx >= numEntries))
        return nullptr;

    IndexEntry* ie;
    pointerAtEnd = false;
    npc(indexFile)->seek(idx * npc(indexFactory)->getSerializedSize());
    ie = npc(indexFactory)->build(indexFile);
    return ie;
}

int8_tArray* org::mpisws::p2p::transport::peerreview::history::SecureHistoryImpl::getEntry(int64_t idx, int32_t maxSizeToRead) /* throws(IOException) */
{
    return getEntry(statEntry(idx), maxSizeToRead);
}

int8_tArray* org::mpisws::p2p::transport::peerreview::history::SecureHistoryImpl::getEntry(IndexEntry* ie, int32_t maxSizeToRead) /* throws(IOException) */
{
    if(ie == nullptr)
        return nullptr;

    if(npc(ie)->sizeInFile < 0)
        return nullptr;

    try {
        npc(dataFile)->seek(npc(ie)->fileIndex);
    } catch (::java::io::IOException* ioe) {
        npc(logger)->log(::java::lang::StringBuilder().append(u"fileIndex:"_j)->append(npc(ie)->fileIndex)
            ->append(u" "_j)
            ->append(static_cast< ::java::lang::Object* >(ie))->toString());
        throw ioe;
    }
    auto bytesToRead = (maxSizeToRead >= npc(ie)->sizeInFile) ? npc(ie)->sizeInFile : maxSizeToRead;
    auto ret = new ::int8_tArray(bytesToRead);
    npc(dataFile)->read(ret);
    return ret;
}

bool org::mpisws::p2p::transport::peerreview::history::SecureHistoryImpl::upgradeHashedEntry(int32_t idx, ::java::nio::ByteBuffer* entry) /* throws(IOException) */
{
    if(readOnly)
        throw new ::java::lang::IllegalStateException(u"Cannot upgrade hashed entry in readonly history"_j);

    if((idx < 0) || (idx >= numEntries))
        return false;

    pointerAtEnd = false;
    npc(indexFile)->seek(idx * npc(indexFactory)->getSerializedSize());
    auto ie = npc(indexFactory)->build(indexFile);
    if(ie == nullptr)
        return false;

    if(npc(ie)->sizeInFile >= 0)
        return false;

    npc(dataFile)->seek(npc(dataFile)->length());
    npc(ie)->fileIndex = npc(dataFile)->getFilePointer();
    npc(ie)->sizeInFile = npc(entry)->remaining();
    npc(dataFile)->write(npc(entry)->array(), npc(entry)->position(), npc(entry)->remaining());
    npc(indexFile)->seek(idx * npc(indexFactory)->getSerializedSize());
    npc(ie)->serialize(indexFile);
    return true;
}

int64_t org::mpisws::p2p::transport::peerreview::history::SecureHistoryImpl::findLastEntry(::int16_tArray* types, int64_t maxSeq) /* throws(IOException) */
{
    auto maxIdx = findSeqOrHigher(::java::lang::Math::min(maxSeq, npc(topEntry)->seq), true);
    auto currentIdx = maxIdx;
    while (currentIdx >= 0) {
        auto ie = statEntry(currentIdx);
        if(ie == nullptr)
            throw new ::java::lang::IllegalStateException(::java::lang::StringBuilder().append(u"Cannot stat history entry #"_j)->append(currentIdx)
                ->append(u" (num="_j)
                ->append(numEntries)
                ->append(u")"_j)->toString());

        for (auto i = int32_t(0); i < npc(types)->length; i++) 
                        if(npc(ie)->type == (*types)[i])
                return currentIdx;


        currentIdx--;
    }
    return -int32_t(1);
}

void org::mpisws::p2p::transport::peerreview::history::SecureHistoryImpl::appendSnippetToHistory(::org::mpisws::p2p::transport::peerreview::audit::LogSnippet* snippet) /* throws(IOException) */
{
    for (auto _i = npc(npc(snippet)->entries)->iterator(); _i->hasNext(); ) {
        ::org::mpisws::p2p::transport::peerreview::audit::SnippetEntry* sEntry = java_cast< ::org::mpisws::p2p::transport::peerreview::audit::SnippetEntry* >(_i->next());
        {
            if(npc(sEntry)->seq > getLastSeq()) {
                if(!setNextSeq(npc(sEntry)->seq))
                    throw new ::java::lang::RuntimeException(u"Audit: Cannot set history sequence number?!?"_j);

                if(!npc(sEntry)->isHash) {
                    appendEntry(static_cast< int16_t >(npc(sEntry)->type), true, new ::java::nio::ByteBufferArray({::java::nio::ByteBuffer::wrap(npc(sEntry)->content)}));
                } else {
                    appendHash(static_cast< int16_t >(npc(sEntry)->type), npc(sEntry)->content);
                }
            } else {
            }
        }
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::peerreview::history::SecureHistoryImpl::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.peerreview.history.SecureHistoryImpl", 61);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::peerreview::history::SecureHistoryImpl::getClass0()
{
    return class_();
}

