// Generated from /pastry-2.1/src/org/mpisws/p2p/testing/transportlayer/replay/Recorder.java
#include <org/mpisws/p2p/testing/transportlayer/replay/Recorder_Recorder_1_getBootstrapper_1_1.hpp>

#include <java/io/IOException.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/Class.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Comparable.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/nio/Buffer.hpp>
#include <java/nio/ByteBuffer.hpp>
#include <java/util/Collection.hpp>
#include <java/util/Map.hpp>
#include <org/mpisws/p2p/testing/transportlayer/replay/MyEvents.hpp>
#include <org/mpisws/p2p/testing/transportlayer/replay/Recorder_Recorder_1.hpp>
#include <org/mpisws/p2p/testing/transportlayer/replay/Recorder.hpp>
#include <org/mpisws/p2p/transport/peerreview/replay/record/RecordLayer.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/LogManager.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/pastry/PastryNode.hpp>
#include <rice/pastry/boot/Bootstrapper.hpp>
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

org::mpisws::p2p::testing::transportlayer::replay::Recorder_Recorder_1_getBootstrapper_1_1::Recorder_Recorder_1_getBootstrapper_1_1(Recorder_Recorder_1 *Recorder_Recorder_1_this, ::rice::pastry::PastryNode* pn, ::rice::pastry::boot::Bootstrapper* internal)
    : super(*static_cast< ::default_init_tag* >(0))
    , Recorder_Recorder_1_this(Recorder_Recorder_1_this)
    , pn(pn)
    , internal(internal)
{
    clinit();
    ctor();
}

void org::mpisws::p2p::testing::transportlayer::replay::Recorder_Recorder_1_getBootstrapper_1_1::boot(::java::util::Collection* bootaddresses)
{
    try {
        npc(java_cast< ::org::mpisws::p2p::transport::peerreview::replay::record::RecordLayer* >(npc(Recorder_Recorder_1_this->Recorder_this->recorders)->get(pn)))->logEvent(MyEvents::EVT_BOOT, new ::java::nio::ByteBufferArray());
    } catch (::java::io::IOException* ioe) {
        npc(npc(npc(npc(pn)->getEnvironment())->getLogManager())->getLogger(::rice::pastry::boot::Bootstrapper::class_(), nullptr))->logException(u"Error recording EVT_BOOT"_j, ioe);
    }
    npc(internal)->boot(bootaddresses);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::testing::transportlayer::replay::Recorder_Recorder_1_getBootstrapper_1_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::testing::transportlayer::replay::Recorder_Recorder_1_getBootstrapper_1_1::getClass0()
{
    return class_();
}

