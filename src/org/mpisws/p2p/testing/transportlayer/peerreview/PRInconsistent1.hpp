// Generated from /pastry-2.1/src/org/mpisws/p2p/testing/transportlayer/peerreview/PRInconsistent1.java

#pragma once

#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/testing/transportlayer/peerreview/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/testing/transportlayer/peerreview/PRRegressionTest.hpp>

template<typename ComponentType, typename... Bases> struct SubArray;
namespace java
{
    namespace io
    {
typedef ::SubArray< ::java::io::Serializable, ::java::lang::ObjectArray > SerializableArray;
    } // io

    namespace lang
    {
typedef ::SubArray< ::java::lang::CharSequence, ObjectArray > CharSequenceArray;
typedef ::SubArray< ::java::lang::Comparable, ObjectArray > ComparableArray;
typedef ::SubArray< ::java::lang::String, ObjectArray, ::java::io::SerializableArray, ComparableArray, CharSequenceArray > StringArray;
    } // lang
} // java

struct default_init_tag;

class org::mpisws::p2p::testing::transportlayer::peerreview::PRInconsistent1
    : public PRRegressionTest
{

public:
    typedef PRRegressionTest super;
protected:
    void ctor() /* throws(Exception) */;

public: /* protected */
    ::org::mpisws::p2p::transport::peerreview::PeerReviewImpl* getPeerReview(PRRegressionTest_Player* player, PRRegressionTest_MyIdTL* transport, ::rice::environment::Environment* env) override;

public:
    void finish() override;
    PRRegressionTest_BogusApp* getBogusApp(PRRegressionTest_Player* player, ::org::mpisws::p2p::transport::peerreview::PeerReview* pr, ::rice::environment::Environment* env) override;
    static void main(::java::lang::StringArray* args) /* throws(Exception) */;

    // Generated
    PRInconsistent1();
protected:
    PRInconsistent1(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
    friend class PRInconsistent1_getPeerReview_1;
    friend class PRInconsistent1_getPeerReview_1_getSecureHistoryFactory_1_1;
    friend class PRInconsistent1_getPeerReview_1_getSecureHistoryFactory_1_1_makeSecureHistory_1_1_1;
    friend class PRInconsistent1_getPeerReview_1_getSecureHistoryFactory_1_1_makeSecureHistory_1_1_1_appendEntry_1_1_1_1;
    friend class PRInconsistent1_ForkingSecureHistory;
    friend class PRInconsistent1_getBogusApp_2;
};
