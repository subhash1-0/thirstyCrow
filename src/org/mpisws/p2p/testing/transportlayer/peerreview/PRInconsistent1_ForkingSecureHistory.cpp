// Generated from /pastry-2.1/src/org/mpisws/p2p/testing/transportlayer/peerreview/PRInconsistent1.java
#include <org/mpisws/p2p/testing/transportlayer/peerreview/PRInconsistent1_ForkingSecureHistory.hpp>

#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <org/mpisws/p2p/testing/transportlayer/peerreview/PRInconsistent1.hpp>
#include <org/mpisws/p2p/transport/peerreview/history/IndexEntry.hpp>
#include <org/mpisws/p2p/transport/peerreview/history/IndexEntryFactory.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/p2p/util/RandomAccessFileIOBuffer.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::testing::transportlayer::peerreview::PRInconsistent1_ForkingSecureHistory::PRInconsistent1_ForkingSecureHistory(PRInconsistent1 *PRInconsistent1_this, const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
    , PRInconsistent1_this(PRInconsistent1_this)
{
    clinit();
}

org::mpisws::p2p::testing::transportlayer::peerreview::PRInconsistent1_ForkingSecureHistory::PRInconsistent1_ForkingSecureHistory(PRInconsistent1 *PRInconsistent1_this, ::rice::p2p::util::RandomAccessFileIOBuffer* indexFile, ::rice::p2p::util::RandomAccessFileIOBuffer* dataFile, bool readOnly, ::org::mpisws::p2p::transport::peerreview::history::HashProvider* hashProv, ::org::mpisws::p2p::transport::peerreview::history::IndexEntryFactory* indexFactory, ::rice::environment::logging::Logger* logger)  /* throws(IOException) */
    : PRInconsistent1_ForkingSecureHistory(PRInconsistent1_this, *static_cast< ::default_init_tag* >(0))
{
    ctor(indexFile,dataFile,readOnly,hashProv,indexFactory,logger);
}

void org::mpisws::p2p::testing::transportlayer::peerreview::PRInconsistent1_ForkingSecureHistory::ctor(::rice::p2p::util::RandomAccessFileIOBuffer* indexFile, ::rice::p2p::util::RandomAccessFileIOBuffer* dataFile, bool readOnly, ::org::mpisws::p2p::transport::peerreview::history::HashProvider* hashProv, ::org::mpisws::p2p::transport::peerreview::history::IndexEntryFactory* indexFactory, ::rice::environment::logging::Logger* logger) /* throws(IOException) */
{
    super::ctor(indexFile, dataFile, readOnly, hashProv, indexFactory, logger);
}

void org::mpisws::p2p::testing::transportlayer::peerreview::PRInconsistent1_ForkingSecureHistory::fork(int64_t entryIndex) /* throws(IOException) */
{
    auto entry = statEntry(entryIndex);
    npc(logger)->log(::java::lang::StringBuilder().append(u"forking at "_j)->append(entryIndex)
        ->append(u" "_j)
        ->append(static_cast< ::java::lang::Object* >(entry))->toString());
    npc(dataFile)->setLength(npc(entry)->getFileIndex());
    npc(indexFile)->setLength(entryIndex * npc(indexFactory)->getSerializedSize());
    numEntries = entryIndex;
    topEntry = statEntry(entryIndex - int32_t(1));
    /* assert((topEntry != nullptr)) */ ;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::testing::transportlayer::peerreview::PRInconsistent1_ForkingSecureHistory::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.testing.transportlayer.peerreview.PRInconsistent1.ForkingSecureHistory", 85);
    return c;
}

java::lang::Class* org::mpisws::p2p::testing::transportlayer::peerreview::PRInconsistent1_ForkingSecureHistory::getClass0()
{
    return class_();
}

