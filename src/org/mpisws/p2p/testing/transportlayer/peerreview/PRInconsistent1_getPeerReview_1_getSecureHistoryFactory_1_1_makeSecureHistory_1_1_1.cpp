// Generated from /pastry-2.1/src/org/mpisws/p2p/testing/transportlayer/peerreview/PRInconsistent1.java
#include <org/mpisws/p2p/testing/transportlayer/peerreview/PRInconsistent1_getPeerReview_1_getSecureHistoryFactory_1_1_makeSecureHistory_1_1_1.hpp>

#include <java/lang/Long.hpp>
#include <java/lang/NullPointerException.hpp>
#include <org/mpisws/p2p/testing/transportlayer/peerreview/PRInconsistent1_getPeerReview_1.hpp>
#include <org/mpisws/p2p/testing/transportlayer/peerreview/PRInconsistent1_getPeerReview_1_getSecureHistoryFactory_1_1.hpp>
#include <org/mpisws/p2p/testing/transportlayer/peerreview/PRInconsistent1_getPeerReview_1_getSecureHistoryFactory_1_1_makeSecureHistory_1_1_1_appendEntry_1_1_1_1.hpp>
#include <org/mpisws/p2p/testing/transportlayer/peerreview/PRInconsistent1.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/selector/SelectorManager.hpp>
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

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::testing::transportlayer::peerreview::PRInconsistent1_getPeerReview_1_getSecureHistoryFactory_1_1_makeSecureHistory_1_1_1::PRInconsistent1_getPeerReview_1_getSecureHistoryFactory_1_1_makeSecureHistory_1_1_1(PRInconsistent1_getPeerReview_1_getSecureHistoryFactory_1_1 *PRInconsistent1_getPeerReview_1_getSecureHistoryFactory_1_1_this, ::rice::environment::Environment* env, ::rice::p2p::util::RandomAccessFileIOBuffer* indexFile, ::rice::p2p::util::RandomAccessFileIOBuffer* dataFile, bool readOnly, ::org::mpisws::p2p::transport::peerreview::history::HashProvider* hashProv, ::org::mpisws::p2p::transport::peerreview::history::IndexEntryFactory* indexFactory, ::rice::environment::logging::Logger* logger)
    : super(PRInconsistent1_getPeerReview_1_getSecureHistoryFactory_1_1_this->PRInconsistent1_getPeerReview_1_this->PRInconsistent1_this, *static_cast< ::default_init_tag* >(0))
    , PRInconsistent1_getPeerReview_1_getSecureHistoryFactory_1_1_this(PRInconsistent1_getPeerReview_1_getSecureHistoryFactory_1_1_this)
    , env(env)
{
    clinit();
    init();
    ctor(indexFile, dataFile, readOnly, hashProv, indexFactory, logger);
}

void org::mpisws::p2p::testing::transportlayer::peerreview::PRInconsistent1_getPeerReview_1_getSecureHistoryFactory_1_1_makeSecureHistory_1_1_1::init()
{
    acks = int32_t(0);
}

void org::mpisws::p2p::testing::transportlayer::peerreview::PRInconsistent1_getPeerReview_1_getSecureHistoryFactory_1_1_makeSecureHistory_1_1_1::appendEntry(int16_t type, bool storeFullEntry, ::java::nio::ByteBufferArray*/*...*/ entry) /* throws(IOException) */
{
    super::appendEntry(type, storeFullEntry, entry);
    if(type == EVT_SIGN) {
        acks++;
        if(acks == 3) {
            auto const idx = findLastEntry(new ::int16_tArray({EVT_RECV}), ::java::lang::Long::MAX_VALUE - int32_t(10));
            npc(npc(env)->getSelectorManager())->invoke(new PRInconsistent1_getPeerReview_1_getSecureHistoryFactory_1_1_makeSecureHistory_1_1_1_appendEntry_1_1_1_1(this, idx));
        }
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::testing::transportlayer::peerreview::PRInconsistent1_getPeerReview_1_getSecureHistoryFactory_1_1_makeSecureHistory_1_1_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::testing::transportlayer::peerreview::PRInconsistent1_getPeerReview_1_getSecureHistoryFactory_1_1_makeSecureHistory_1_1_1::getClass0()
{
    return class_();
}

