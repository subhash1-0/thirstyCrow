// Generated from /pastry-2.1/src/org/mpisws/p2p/testing/transportlayer/BandwidthMeasuringTLTest.java
#include <org/mpisws/p2p/testing/transportlayer/BandwidthMeasuringTLTest_main_1_getWireTransportLayer_1_1.hpp>

#include <java/io/PrintStream.hpp>
#include <java/lang/Boolean.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Integer.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>
#include <java/net/InetSocketAddress.hpp>
#include <java/util/Iterator.hpp>
#include <java/util/Map.hpp>
#include <java/util/Set.hpp>
#include <org/mpisws/p2p/testing/transportlayer/BandwidthMeasuringTLTest_main_1.hpp>
#include <org/mpisws/p2p/transport/bandwidthmeasure/BandwidthMeasuringTransportLayer.hpp>
#include <rice/p2p/util/tuples/Tuple3.hpp>

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

org::mpisws::p2p::testing::transportlayer::BandwidthMeasuringTLTest_main_1_getWireTransportLayer_1_1::BandwidthMeasuringTLTest_main_1_getWireTransportLayer_1_1(BandwidthMeasuringTLTest_main_1 *BandwidthMeasuringTLTest_main_1_this, ::org::mpisws::p2p::transport::bandwidthmeasure::BandwidthMeasuringTransportLayer* ret2)
    : super(*static_cast< ::default_init_tag* >(0))
    , BandwidthMeasuringTLTest_main_1_this(BandwidthMeasuringTLTest_main_1_this)
    , ret2(ret2)
{
    clinit();
    ctor();
}

void org::mpisws::p2p::testing::transportlayer::BandwidthMeasuringTLTest_main_1_getWireTransportLayer_1_1::run()
{
    auto map = npc(ret2)->getBandwidthUsed();
    for (auto _i = npc(npc(map)->keySet())->iterator(); _i->hasNext(); ) {
        ::java::net::InetSocketAddress* addr = java_cast< ::java::net::InetSocketAddress* >(_i->next());
        {
            auto t = java_cast< ::rice::p2p::util::tuples::Tuple3* >(npc(map)->get(addr));
            npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"Bandwidth for "_j)->append(static_cast< ::java::lang::Object* >(addr))
                ->append(u" d:"_j)
                ->append(static_cast< ::java::lang::Object* >(java_cast< ::java::lang::Integer* >(npc(t)->a())))
                ->append(u" u:"_j)
                ->append(static_cast< ::java::lang::Object* >(java_cast< ::java::lang::Integer* >(npc(t)->b())))
                ->append(u" saturated:"_j)
                ->append(static_cast< ::java::lang::Object* >(java_cast< ::java::lang::Boolean* >(npc(t)->c())))->toString());
        }
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::testing::transportlayer::BandwidthMeasuringTLTest_main_1_getWireTransportLayer_1_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::testing::transportlayer::BandwidthMeasuringTLTest_main_1_getWireTransportLayer_1_1::getClass0()
{
    return class_();
}

