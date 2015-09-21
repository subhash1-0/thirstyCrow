// Generated from /pastry-2.1/src/org/mpisws/p2p/testing/transportlayer/replay/Recorder.java
#include <org/mpisws/p2p/testing/transportlayer/replay/Recorder_SubscribeInvokation.hpp>

#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Comparable.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/nio/Buffer.hpp>
#include <java/nio/ByteBuffer.hpp>
#include <java/util/Map.hpp>
#include <org/mpisws/p2p/testing/transportlayer/replay/MyEvents.hpp>
#include <org/mpisws/p2p/testing/transportlayer/replay/MyScribeClient.hpp>
#include <org/mpisws/p2p/testing/transportlayer/replay/Recorder.hpp>
#include <org/mpisws/p2p/transport/peerreview/replay/record/RecordLayer.hpp>
#include <rice/p2p/commonapi/Node.hpp>
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

org::mpisws::p2p::testing::transportlayer::replay::Recorder_SubscribeInvokation::Recorder_SubscribeInvokation(Recorder *Recorder_this, const ::default_init_tag&)
    : super(Recorder_this, *static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::testing::transportlayer::replay::Recorder_SubscribeInvokation::Recorder_SubscribeInvokation(Recorder *Recorder_this, MyScribeClient* app) 
    : Recorder_SubscribeInvokation(Recorder_this, *static_cast< ::default_init_tag* >(0))
{
    ctor(app);
}

void org::mpisws::p2p::testing::transportlayer::replay::Recorder_SubscribeInvokation::ctor(MyScribeClient* app)
{
    super::ctor(app);
}

void org::mpisws::p2p::testing::transportlayer::replay::Recorder_SubscribeInvokation::doIt() /* throws(IOException) */
{
    npc(java_cast< ::org::mpisws::p2p::transport::peerreview::replay::record::RecordLayer* >(npc(Recorder_this->recorders)->get(npc(app)->node)))->logEvent(MyEvents::EVT_SUBSCRIBE, new ::java::nio::ByteBufferArray());
    npc(app)->subscribe();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::testing::transportlayer::replay::Recorder_SubscribeInvokation::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.testing.transportlayer.replay.Recorder.SubscribeInvokation", 73);
    return c;
}

java::lang::Class* org::mpisws::p2p::testing::transportlayer::replay::Recorder_SubscribeInvokation::getClass0()
{
    return class_();
}

