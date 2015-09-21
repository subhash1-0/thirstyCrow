// Generated from /pastry-2.1/src/org/mpisws/p2p/testing/transportlayer/replay/Recorder.java
#include <org/mpisws/p2p/testing/transportlayer/replay/Recorder_Recorder_2.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/net/InetSocketAddress.hpp>
#include <java/util/ArrayList.hpp>
#include <java/util/Collections.hpp>
#include <java/util/Set.hpp>
#include <org/mpisws/p2p/testing/transportlayer/replay/MyScribeClient.hpp>
#include <org/mpisws/p2p/testing/transportlayer/replay/Recorder.hpp>
#include <rice/pastry/PastryNode.hpp>
#include <rice/pastry/boot/Bootstrapper.hpp>
#include <rice/pastry/socket/SocketPastryNodeFactory.hpp>

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

org::mpisws::p2p::testing::transportlayer::replay::Recorder_Recorder_2::Recorder_Recorder_2(Recorder *Recorder_this, ::rice::pastry::socket::SocketPastryNodeFactory* factory, ::java::util::ArrayList* nodeContainer, ::java::net::InetSocketAddress* bootaddress)
    : super(*static_cast< ::default_init_tag* >(0))
    , Recorder_this(Recorder_this)
    , factory(factory)
    , nodeContainer(nodeContainer)
    , bootaddress(bootaddress)
{
    clinit();
    ctor();
}

void org::mpisws::p2p::testing::transportlayer::replay::Recorder_Recorder_2::run()
{
    auto node = java_cast< ::rice::pastry::PastryNode* >(npc(factory)->newNode());
    npc(nodeContainer)->add(static_cast< ::java::lang::Object* >(node));
    auto app = new MyScribeClient(node);
    npc(Recorder_this->apps)->add(static_cast< ::java::lang::Object* >(app));
    npc(npc(node)->getBootstrapper())->boot(::java::util::Collections::singleton(bootaddress));
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::testing::transportlayer::replay::Recorder_Recorder_2::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::testing::transportlayer::replay::Recorder_Recorder_2::getClass0()
{
    return class_();
}

