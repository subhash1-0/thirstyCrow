// Generated from /pastry-2.1/src/org/mpisws/p2p/testing/transportlayer/peerreview/PRInconsistent1.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/testing/transportlayer/peerreview/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/history/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <rice/p2p/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/history/SecureHistoryFactoryImpl.hpp>

struct default_init_tag;

class org::mpisws::p2p::testing::transportlayer::peerreview::PRInconsistent1_getPeerReview_1_getSecureHistoryFactory_1_1
    : public ::org::mpisws::p2p::transport::peerreview::history::SecureHistoryFactoryImpl
{

public:
    typedef ::org::mpisws::p2p::transport::peerreview::history::SecureHistoryFactoryImpl super;

public: /* protected */
    ::org::mpisws::p2p::transport::peerreview::history::SecureHistoryImpl* makeSecureHistory(::rice::p2p::util::RandomAccessFileIOBuffer* indexFile, ::rice::p2p::util::RandomAccessFileIOBuffer* dataFile, bool readOnly, ::org::mpisws::p2p::transport::peerreview::history::HashProvider* hashProv, ::org::mpisws::p2p::transport::peerreview::history::IndexEntryFactory* indexFactory, ::rice::environment::logging::Logger* logger) /* throws(IOException) */ override;

    // Generated

public:
    PRInconsistent1_getPeerReview_1_getSecureHistoryFactory_1_1(PRInconsistent1_getPeerReview_1 *PRInconsistent1_getPeerReview_1_this, ::rice::environment::Environment* env_, ::org::mpisws::p2p::transport::peerreview::history::HashProvider* hashProv, ::rice::environment::Environment* env);
    static ::java::lang::Class *class_();
    PRInconsistent1_getPeerReview_1 *PRInconsistent1_getPeerReview_1_this;
    ::rice::environment::Environment* env;

private:
    virtual ::java::lang::Class* getClass0();
    friend class PRInconsistent1;
    friend class PRInconsistent1_getPeerReview_1;
    friend class PRInconsistent1_getPeerReview_1_getSecureHistoryFactory_1_1_makeSecureHistory_1_1_1;
    friend class PRInconsistent1_getPeerReview_1_getSecureHistoryFactory_1_1_makeSecureHistory_1_1_1_appendEntry_1_1_1_1;
    friend class PRInconsistent1_ForkingSecureHistory;
    friend class PRInconsistent1_getBogusApp_2;
};
