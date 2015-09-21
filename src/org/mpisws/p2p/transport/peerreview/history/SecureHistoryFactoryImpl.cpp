// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/history/SecureHistoryFactoryImpl.java
#include <org/mpisws/p2p/transport/peerreview/history/SecureHistoryFactoryImpl.hpp>

#include <java/io/File.hpp>
#include <java/io/IOException.hpp>
#include <java/lang/Class.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/RuntimeException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <org/mpisws/p2p/transport/peerreview/history/HashProvider.hpp>
#include <org/mpisws/p2p/transport/peerreview/history/IndexEntry.hpp>
#include <org/mpisws/p2p/transport/peerreview/history/SecureHistory.hpp>
#include <org/mpisws/p2p/transport/peerreview/history/SecureHistoryImpl.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/LogManager.hpp>
#include <rice/environment/random/RandomSource.hpp>
#include <rice/environment/time/TimeSource.hpp>
#include <rice/p2p/commonapi/rawserialization/InputBuffer.hpp>
#include <rice/p2p/util/RandomAccessFileIOBuffer.hpp>
#include <Array.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::transport::peerreview::history::SecureHistoryFactoryImpl::SecureHistoryFactoryImpl(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::transport::peerreview::history::SecureHistoryFactoryImpl::SecureHistoryFactoryImpl(HashProvider* hashProv, ::rice::environment::Environment* env) 
    : SecureHistoryFactoryImpl(*static_cast< ::default_init_tag* >(0))
{
    ctor(hashProv,env);
}

void org::mpisws::p2p::transport::peerreview::history::SecureHistoryFactoryImpl::ctor(HashProvider* hashProv, ::rice::environment::Environment* env)
{
    super::ctor();
    this->hashProv = hashProv;
    this->environment = env;
}

org::mpisws::p2p::transport::peerreview::history::SecureHistory* org::mpisws::p2p::transport::peerreview::history::SecureHistoryFactoryImpl::create(::java::lang::String* name, int64_t baseSeq, ::int8_tArray* baseHash) /* throws(IOException) */
{
    ::rice::p2p::util::RandomAccessFileIOBuffer* indexFile;
    ::rice::p2p::util::RandomAccessFileIOBuffer* dataFile;
    if(name == nullptr) {
        name = ::java::lang::StringBuilder().append(u"peerReview."_j)->append(npc(npc(environment)->getTimeSource())->currentTimeMillis())
            ->append(u"."_j)
            ->append(npc(npc(environment)->getRandomSource())->nextInt())->toString();
    }
    auto indexName = ::java::lang::StringBuilder().append(name)->append(u".index"_j)->toString();
    auto dataName = ::java::lang::StringBuilder().append(name)->append(u".data"_j)->toString();
    auto f = new ::java::io::File(indexName);
    if(npc(f)->exists()) {
        throw new ::java::lang::RuntimeException(::java::lang::StringBuilder().append(u"File "_j)->append(static_cast< ::java::lang::Object* >(f))
            ->append(u" already exists."_j)->toString());
    }
    f = new ::java::io::File(dataName);
    if(npc(f)->exists()) {
        throw new ::java::lang::RuntimeException(::java::lang::StringBuilder().append(u"File "_j)->append(static_cast< ::java::lang::Object* >(f))
            ->append(u" already exists."_j)->toString());
    }
    indexFile = new ::rice::p2p::util::RandomAccessFileIOBuffer(indexName, u"rw"_j);
    try {
        dataFile = new ::rice::p2p::util::RandomAccessFileIOBuffer(dataName, u"rw"_j);
    } catch (::java::io::IOException* ioe) {
        npc(indexFile)->close();
        throw ioe;
    }
    auto entry = new IndexEntry(baseSeq, static_cast< int64_t >(int32_t(0)), EVT_INIT, -int32_t(1), npc(hashProv)->getEmptyHash(), baseHash);
    npc(entry)->serialize(indexFile);
    auto history = makeSecureHistory(indexFile, dataFile, false, hashProv, this, npc(npc(environment)->getLogManager())->getLogger(SecureHistoryImpl::class_(), name));
    return history;
}

org::mpisws::p2p::transport::peerreview::history::SecureHistoryImpl* org::mpisws::p2p::transport::peerreview::history::SecureHistoryFactoryImpl::makeSecureHistory(::rice::p2p::util::RandomAccessFileIOBuffer* indexFile, ::rice::p2p::util::RandomAccessFileIOBuffer* dataFile, bool readOnly, HashProvider* hashProv, IndexEntryFactory* indexFactory, ::rice::environment::logging::Logger* logger) /* throws(IOException) */
{
    return new SecureHistoryImpl(indexFile, dataFile, readOnly, hashProv, indexFactory, logger);
}

org::mpisws::p2p::transport::peerreview::history::SecureHistory* org::mpisws::p2p::transport::peerreview::history::SecureHistoryFactoryImpl::open(::java::lang::String* name, ::java::lang::String* mode) /* throws(IOException) */
{
    auto readOnly = false;
    if(npc(mode)->equals(static_cast< ::java::lang::Object* >(u"r"_j))) {
        readOnly = true;
    } else if(!npc(mode)->equals(static_cast< ::java::lang::Object* >(u"w"_j))) {
        return nullptr;
    }
    ::java::lang::String* fileMode;
    if(readOnly) {
        fileMode = u"r"_j;
    } else {
        fileMode = u"rw"_j;
    }
    auto f = new ::java::io::File(::java::lang::StringBuilder().append(name)->append(u".index"_j)->toString());
    if(!npc(f)->exists()) {
        return nullptr;
    }
    auto f2 = new ::java::io::File(::java::lang::StringBuilder().append(name)->append(u".data"_j)->toString());
    if(!npc(f2)->exists()) {
        return nullptr;
    }
    auto indexFile = new ::rice::p2p::util::RandomAccessFileIOBuffer(::java::lang::StringBuilder().append(name)->append(u".index"_j)->toString(), fileMode);
    ::rice::p2p::util::RandomAccessFileIOBuffer* dataFile;
    try {
        dataFile = new ::rice::p2p::util::RandomAccessFileIOBuffer(::java::lang::StringBuilder().append(name)->append(u".data"_j)->toString(), fileMode);
    } catch (::java::io::IOException* ioe) {
        npc(indexFile)->close();
        throw ioe;
    }
    return makeSecureHistory(indexFile, dataFile, readOnly, hashProv, this, npc(npc(environment)->getLogManager())->getLogger(SecureHistoryImpl::class_(), name));
}

org::mpisws::p2p::transport::peerreview::history::IndexEntry* org::mpisws::p2p::transport::peerreview::history::SecureHistoryFactoryImpl::build(::rice::p2p::commonapi::rawserialization::InputBuffer* buf) /* throws(IOException) */
{
    auto seq = npc(buf)->readLong();
    auto fileIndex = npc(buf)->readLong();
    auto sizeInFile = npc(buf)->readInt();
    auto type = npc(buf)->readShort();
    auto contentHash = new ::int8_tArray(npc(hashProv)->getHashSizeBytes());
    npc(buf)->read(contentHash);
    auto nodeHash = new ::int8_tArray(npc(hashProv)->getHashSizeBytes());
    npc(buf)->read(nodeHash);
    return new IndexEntry(seq, fileIndex, type, sizeInFile, contentHash, nodeHash);
}

int32_t org::mpisws::p2p::transport::peerreview::history::SecureHistoryFactoryImpl::getSerializedSize()
{
    return int32_t(8) + int32_t(8) + int32_t(4)+ int32_t(2)+ npc(hashProv)->getHashSizeBytes() * int32_t(2);
}

org::mpisws::p2p::transport::peerreview::history::SecureHistory* org::mpisws::p2p::transport::peerreview::history::SecureHistoryFactoryImpl::createTemp(int64_t baseSeq, ::int8_tArray* baseHash) /* throws(IOException) */
{
    return create(static_cast< ::java::lang::String* >(nullptr), baseSeq, baseHash);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::peerreview::history::SecureHistoryFactoryImpl::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.peerreview.history.SecureHistoryFactoryImpl", 68);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::peerreview::history::SecureHistoryFactoryImpl::getClass0()
{
    return class_();
}

