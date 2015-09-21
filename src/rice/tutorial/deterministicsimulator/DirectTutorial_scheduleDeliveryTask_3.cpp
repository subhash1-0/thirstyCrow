// Generated from /pastry-2.1/src/rice/tutorial/deterministicsimulator/DirectTutorial.java
#include <rice/tutorial/deterministicsimulator/DirectTutorial_scheduleDeliveryTask_3.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/util/Iterator.hpp>
#include <java/util/Vector.hpp>
#include <rice/p2p/commonapi/Node.hpp>
#include <rice/pastry/NodeHandle.hpp>
#include <rice/pastry/PastryNode.hpp>
#include <rice/pastry/leafset/LeafSet.hpp>
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

rice::tutorial::deterministicsimulator::DirectTutorial_scheduleDeliveryTask_3::DirectTutorial_scheduleDeliveryTask_3(DirectTutorial *DirectTutorial_this)
    : super(*static_cast< ::default_init_tag* >(0))
    , DirectTutorial_this(DirectTutorial_this)
{
    clinit();
    init();
    ctor();
}

void rice::tutorial::deterministicsimulator::DirectTutorial_scheduleDeliveryTask_3::init()
{
    appIterator = npc(DirectTutorial_this->apps)->iterator();
}

void rice::tutorial::deterministicsimulator::DirectTutorial_scheduleDeliveryTask_3::run()
{
    if(npc(appIterator)->hasNext()) {
        auto app = java_cast< MyApp* >(java_cast< MyApp* >(npc(appIterator)->next()));
        auto node = java_cast< ::rice::pastry::PastryNode* >(npc(app)->getNode());
        auto leafSet = npc(node)->getLeafSet();
        for (auto i = -npc(leafSet)->ccwSize(); i <= npc(leafSet)->cwSize(); i++) {
            if(i != 0) {
                auto nh = npc(leafSet)->get(i);
                npc(app)->routeMyMsgDirect(nh);
            }
        }
    } else {
        cancel();
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::tutorial::deterministicsimulator::DirectTutorial_scheduleDeliveryTask_3::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::tutorial::deterministicsimulator::DirectTutorial_scheduleDeliveryTask_3::getClass0()
{
    return class_();
}

