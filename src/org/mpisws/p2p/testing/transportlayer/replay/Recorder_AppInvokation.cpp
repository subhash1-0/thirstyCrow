// Generated from /pastry-2.1/src/org/mpisws/p2p/testing/transportlayer/replay/Recorder.java
#include <org/mpisws/p2p/testing/transportlayer/replay/Recorder_AppInvokation.hpp>

#include <java/io/IOException.hpp>
#include <java/lang/Class.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/String.hpp>
#include <org/mpisws/p2p/testing/transportlayer/replay/MyScribeClient.hpp>
#include <org/mpisws/p2p/testing/transportlayer/replay/Recorder.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/LogManager.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/p2p/commonapi/Node.hpp>
#include <rice/pastry/boot/Bootstrapper.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::testing::transportlayer::replay::Recorder_AppInvokation::Recorder_AppInvokation(Recorder *Recorder_this, const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
    , Recorder_this(Recorder_this)
{
    clinit();
}

org::mpisws::p2p::testing::transportlayer::replay::Recorder_AppInvokation::Recorder_AppInvokation(Recorder *Recorder_this, MyScribeClient* app) 
    : Recorder_AppInvokation(Recorder_this, *static_cast< ::default_init_tag* >(0))
{
    ctor(app);
}

void org::mpisws::p2p::testing::transportlayer::replay::Recorder_AppInvokation::ctor(MyScribeClient* app)
{
    super::ctor();
    this->app = app;
}

void org::mpisws::p2p::testing::transportlayer::replay::Recorder_AppInvokation::run()
{
    try {
        doIt();
    } catch (::java::io::IOException* ioe) {
        npc(npc(npc(npc(npc(app)->node)->getEnvironment())->getLogManager())->getLogger(::rice::pastry::boot::Bootstrapper::class_(), nullptr))->logException(u"Error recording event"_j, ioe);
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::testing::transportlayer::replay::Recorder_AppInvokation::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.testing.transportlayer.replay.Recorder.AppInvokation", 67);
    return c;
}

java::lang::Class* org::mpisws::p2p::testing::transportlayer::replay::Recorder_AppInvokation::getClass0()
{
    return class_();
}

