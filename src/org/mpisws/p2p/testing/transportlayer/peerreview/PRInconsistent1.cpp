// Generated from /pastry-2.1/src/org/mpisws/p2p/testing/transportlayer/peerreview/PRInconsistent1.java
#include <org/mpisws/p2p/testing/transportlayer/peerreview/PRInconsistent1.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/Integer.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/System.hpp>
#include <java/util/Map.hpp>
#include <org/mpisws/p2p/testing/transportlayer/peerreview/PRInconsistent1_getPeerReview_1.hpp>
#include <org/mpisws/p2p/testing/transportlayer/peerreview/PRInconsistent1_getBogusApp_2.hpp>
#include <org/mpisws/p2p/testing/transportlayer/peerreview/PRRegressionTest_HandleImpl.hpp>
#include <org/mpisws/p2p/testing/transportlayer/peerreview/PRRegressionTest_HandleSerializer.hpp>
#include <org/mpisws/p2p/testing/transportlayer/peerreview/PRRegressionTest_IdExtractor.hpp>
#include <org/mpisws/p2p/testing/transportlayer/peerreview/PRRegressionTest_IdImpl.hpp>
#include <org/mpisws/p2p/testing/transportlayer/peerreview/PRRegressionTest_IdSerializer.hpp>
#include <org/mpisws/p2p/testing/transportlayer/peerreview/PRRegressionTest_MyIdTL.hpp>
#include <org/mpisws/p2p/testing/transportlayer/peerreview/PRRegressionTest_Player.hpp>
#include <org/mpisws/p2p/transport/peerreview/PeerReview.hpp>
#include <org/mpisws/p2p/transport/peerreview/PeerReviewImpl.hpp>
#include <org/mpisws/p2p/transport/peerreview/infostore/StatusChangeListener.hpp>
#include <rice/environment/logging/Logger.hpp>

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

org::mpisws::p2p::testing::transportlayer::peerreview::PRInconsistent1::PRInconsistent1(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::testing::transportlayer::peerreview::PRInconsistent1::PRInconsistent1()  /* throws(Exception) */
    : PRInconsistent1(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

void org::mpisws::p2p::testing::transportlayer::peerreview::PRInconsistent1::ctor() /* throws(Exception) */
{
    super::ctor(int32_t(45000));
}

org::mpisws::p2p::transport::peerreview::PeerReviewImpl* org::mpisws::p2p::testing::transportlayer::peerreview::PRInconsistent1::getPeerReview(PRRegressionTest_Player* player, PRRegressionTest_MyIdTL* transport, ::rice::environment::Environment* env)
{
    if(npc(npc(npc(player)->localHandle)->id)->id == 2) {
        return new PRInconsistent1_getPeerReview_1(this, transport, env, new PRRegressionTest_HandleSerializer(), new PRRegressionTest_IdSerializer(), new PRRegressionTest_IdExtractor(), getIdStrTranslator());
    } else {
        return java_cast< ::org::mpisws::p2p::transport::peerreview::PeerReviewImpl* >(super::getPeerReview(player, transport, env));
    }
}

void org::mpisws::p2p::testing::transportlayer::peerreview::PRInconsistent1::finish()
{
    try {
        if((npc(java_cast< ::java::lang::Integer* >(npc(java_cast< ::java::util::Map* >(npc(recordedStatus)->get(aliceHandle)))->get(npc(bobHandle)->id))))->intValue() != ::org::mpisws::p2p::transport::peerreview::infostore::StatusChangeListener::STATUS_EXPOSED) {
            npc(logger)->log(u"Alice Didn't expose bob"_j);
            ::java::lang::System::exit(1);
        }
        if((npc(java_cast< ::java::lang::Integer* >(npc(java_cast< ::java::util::Map* >(npc(recordedStatus)->get(carolHandle)))->get(npc(bobHandle)->id))))->intValue() != ::org::mpisws::p2p::transport::peerreview::infostore::StatusChangeListener::STATUS_EXPOSED) {
            npc(logger)->log(u"Carol Didn't expose bob"_j);
            ::java::lang::System::exit(1);
        }
    } catch (::java::lang::Exception* e) {
        npc(logger)->logException(u"Failure"_j, e);
        ::java::lang::System::exit(1);
    }
    npc(logger)->log(u"Success"_j);
    ::java::lang::System::exit(0);
}

org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_BogusApp* org::mpisws::p2p::testing::transportlayer::peerreview::PRInconsistent1::getBogusApp(PRRegressionTest_Player* player, ::org::mpisws::p2p::transport::peerreview::PeerReview* pr, ::rice::environment::Environment* env)
{
    return new PRInconsistent1_getBogusApp_2(this, player, pr, env);
}

void org::mpisws::p2p::testing::transportlayer::peerreview::PRInconsistent1::main(::java::lang::StringArray* args) /* throws(Exception) */
{
    clinit();
    new PRInconsistent1();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::testing::transportlayer::peerreview::PRInconsistent1::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.testing.transportlayer.peerreview.PRInconsistent1", 64);
    return c;
}

java::lang::Class* org::mpisws::p2p::testing::transportlayer::peerreview::PRInconsistent1::getClass0()
{
    return class_();
}

