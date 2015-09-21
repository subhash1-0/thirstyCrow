// Generated from /pastry-2.1/src/org/mpisws/p2p/testing/transportlayer/peerreview/PRInconsistent1.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/nio/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/testing/transportlayer/peerreview/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/history/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <rice/p2p/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/testing/transportlayer/peerreview/PRInconsistent1_ForkingSecureHistory.hpp>

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

struct default_init_tag;

class org::mpisws::p2p::testing::transportlayer::peerreview::PRInconsistent1_getPeerReview_1_getSecureHistoryFactory_1_1_makeSecureHistory_1_1_1
    : public PRInconsistent1_ForkingSecureHistory
{

public:
    typedef PRInconsistent1_ForkingSecureHistory super;

public: /* package */
    int32_t acks {  };

public:
    void appendEntry(int16_t type, bool storeFullEntry, ::java::nio::ByteBufferArray*/*...*/ entry) /* throws(IOException) */ override;

    // Generated
    PRInconsistent1_getPeerReview_1_getSecureHistoryFactory_1_1_makeSecureHistory_1_1_1(PRInconsistent1_getPeerReview_1_getSecureHistoryFactory_1_1 *PRInconsistent1_getPeerReview_1_getSecureHistoryFactory_1_1_this, ::rice::environment::Environment* env, ::rice::p2p::util::RandomAccessFileIOBuffer* indexFile, ::rice::p2p::util::RandomAccessFileIOBuffer* dataFile, bool readOnly, ::org::mpisws::p2p::transport::peerreview::history::HashProvider* hashProv, ::org::mpisws::p2p::transport::peerreview::history::IndexEntryFactory* indexFactory, ::rice::environment::logging::Logger* logger);
    static ::java::lang::Class *class_();

private:
    void init();
    PRInconsistent1_getPeerReview_1_getSecureHistoryFactory_1_1 *PRInconsistent1_getPeerReview_1_getSecureHistoryFactory_1_1_this;
    ::rice::environment::Environment* env;
    virtual ::java::lang::Class* getClass0();
    friend class PRInconsistent1;
    friend class PRInconsistent1_getPeerReview_1;
    friend class PRInconsistent1_getPeerReview_1_getSecureHistoryFactory_1_1;
    friend class PRInconsistent1_getPeerReview_1_getSecureHistoryFactory_1_1_makeSecureHistory_1_1_1_appendEntry_1_1_1_1;
    friend class PRInconsistent1_ForkingSecureHistory;
    friend class PRInconsistent1_getBogusApp_2;
};
