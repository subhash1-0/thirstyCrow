// Generated from /pastry-2.1/src/rice/pastry/testing/RoutingTableTest.java
#include <rice/pastry/testing/RoutingTableTest_finishNode_6.hpp>

#include <java/io/PrintStream.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/random/RandomSource.hpp>
#include <rice/pastry/PastryNode.hpp>
#include <rice/pastry/testing/RoutingTableTest_finishNode_6_6_1.hpp>
#include <rice/pastry/testing/RoutingTableTest.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::pastry::testing::RoutingTableTest_finishNode_6::RoutingTableTest_finishNode_6(RoutingTableTest *RoutingTableTest_this, ::rice::pastry::PastryNode* node)
    : super(*static_cast< ::default_init_tag* >(0))
    , RoutingTableTest_this(RoutingTableTest_this)
    , node(node)
{
    clinit();
    init();
    ctor();
}

void rice::pastry::testing::RoutingTableTest_finishNode_6::init()
{
    {
        npc(node)->addDestructable(new RoutingTableTest_finishNode_6_6_1(this));
    }
}

void rice::pastry::testing::RoutingTableTest_finishNode_6::run()
{
    if(npc(npc(RoutingTableTest_this->env)->getRandomSource())->nextInt(RoutingTableTest_this->meanSessionTime * int32_t(2)) == 0) {
        if(RoutingTableTest_this->printLiveness)
            npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"Destroying "_j)->append(static_cast< ::java::lang::Object* >(node))->toString());

        cancel();
        npc(node)->destroy();
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::testing::RoutingTableTest_finishNode_6::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::pastry::testing::RoutingTableTest_finishNode_6::getClass0()
{
    return class_();
}

