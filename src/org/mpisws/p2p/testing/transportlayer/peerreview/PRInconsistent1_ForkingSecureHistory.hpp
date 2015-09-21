// Generated from /pastry-2.1/src/org/mpisws/p2p/testing/transportlayer/peerreview/PRInconsistent1.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/testing/transportlayer/peerreview/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/history/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <rice/p2p/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/history/SecureHistoryImpl.hpp>

struct default_init_tag;

class org::mpisws::p2p::testing::transportlayer::peerreview::PRInconsistent1_ForkingSecureHistory
    : public ::org::mpisws::p2p::transport::peerreview::history::SecureHistoryImpl
{

public:
    typedef ::org::mpisws::p2p::transport::peerreview::history::SecureHistoryImpl super;
protected:
    void ctor(::rice::p2p::util::RandomAccessFileIOBuffer* indexFile, ::rice::p2p::util::RandomAccessFileIOBuffer* dataFile, bool readOnly, ::org::mpisws::p2p::transport::peerreview::history::HashProvider* hashProv, ::org::mpisws::p2p::transport::peerreview::history::IndexEntryFactory* indexFactory, ::rice::environment::logging::Logger* logger) /* throws(IOException) */;

public:
    virtual void fork(int64_t entryIndex) /* throws(IOException) */;

    // Generated
    PRInconsistent1_ForkingSecureHistory(PRInconsistent1 *PRInconsistent1_this, ::rice::p2p::util::RandomAccessFileIOBuffer* indexFile, ::rice::p2p::util::RandomAccessFileIOBuffer* dataFile, bool readOnly, ::org::mpisws::p2p::transport::peerreview::history::HashProvider* hashProv, ::org::mpisws::p2p::transport::peerreview::history::IndexEntryFactory* indexFactory, ::rice::environment::logging::Logger* logger);
protected:
    PRInconsistent1_ForkingSecureHistory(PRInconsistent1 *PRInconsistent1_this, const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    PRInconsistent1 *PRInconsistent1_this;

private:
    virtual ::java::lang::Class* getClass0();
    friend class PRInconsistent1;
    friend class PRInconsistent1_getPeerReview_1;
    friend class PRInconsistent1_getPeerReview_1_getSecureHistoryFactory_1_1;
    friend class PRInconsistent1_getPeerReview_1_getSecureHistoryFactory_1_1_makeSecureHistory_1_1_1;
    friend class PRInconsistent1_getPeerReview_1_getSecureHistoryFactory_1_1_makeSecureHistory_1_1_1_appendEntry_1_1_1_1;
    friend class PRInconsistent1_getBogusApp_2;
};
