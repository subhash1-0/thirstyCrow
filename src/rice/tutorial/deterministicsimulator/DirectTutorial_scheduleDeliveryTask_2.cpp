// Generated from /pastry-2.1/src/rice/tutorial/deterministicsimulator/DirectTutorial.java
#include <rice/tutorial/deterministicsimulator/DirectTutorial_scheduleDeliveryTask_2.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/util/Iterator.hpp>
#include <java/util/Vector.hpp>
#include <rice/pastry/Id.hpp>
#include <rice/pastry/NodeIdFactory.hpp>
#include <rice/tutorial/deterministicsimulator/DirectTutorial.hpp>
#include <rice/tutorial/deterministicsimulator/MyApp.hpp>

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

rice::tutorial::deterministicsimulator::DirectTutorial_scheduleDeliveryTask_2::DirectTutorial_scheduleDeliveryTask_2(DirectTutorial *DirectTutorial_this, ::rice::pastry::NodeIdFactory* nidFactory)
    : super(*static_cast< ::default_init_tag* >(0))
    , DirectTutorial_this(DirectTutorial_this)
    , nidFactory(nidFactory)
{
    clinit();
    init();
    ctor();
}

void rice::tutorial::deterministicsimulator::DirectTutorial_scheduleDeliveryTask_2::init()
{
    i = int32_t(0);
}

void rice::tutorial::deterministicsimulator::DirectTutorial_scheduleDeliveryTask_2::run()
{
    auto appIterator = npc(DirectTutorial_this->apps)->iterator();
    while (npc(appIterator)->hasNext()) {
        auto app = java_cast< MyApp* >(java_cast< MyApp* >(npc(appIterator)->next()));
        ::rice::p2p::commonapi::Id* randId = npc(nidFactory)->generateNodeId();
        npc(app)->routeMyMsg(randId);
    }
    i++;
    if(i >= 10)
        cancel();

}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::tutorial::deterministicsimulator::DirectTutorial_scheduleDeliveryTask_2::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::tutorial::deterministicsimulator::DirectTutorial_scheduleDeliveryTask_2::getClass0()
{
    return class_();
}

