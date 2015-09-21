// Generated from /pastry-2.1/src/rice/pastry/testing/RoutingTableTest.java
#include <rice/pastry/testing/RoutingTableTest_createNode_5.hpp>

#include <java/lang/Boolean.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <rice/pastry/JoinFailedException.hpp>
#include <rice/pastry/PastryNode.hpp>
#include <rice/pastry/testing/RoutingTableTest.hpp>

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

rice::pastry::testing::RoutingTableTest_createNode_5::RoutingTableTest_createNode_5(RoutingTableTest *RoutingTableTest_this, ::rice::pastry::PastryNode* node)
    : super(*static_cast< ::default_init_tag* >(0))
    , RoutingTableTest_this(RoutingTableTest_this)
    , node(node)
{
    clinit();
    ctor();
}

void rice::pastry::testing::RoutingTableTest_createNode_5::update(::java::util::Observable* o, ::java::lang::Object* arg)
{
    if(dynamic_cast< ::java::lang::Boolean* >(arg) != nullptr) {
        if(!npc((java_cast< ::java::lang::Boolean* >(arg)))->booleanValue())
            return;

        npc(node)->deleteObserver(this);
        RoutingTableTest_this->finishNode(node);
    } else if(dynamic_cast< ::rice::pastry::JoinFailedException* >(arg) != nullptr) {
        npc(node)->destroy();
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::testing::RoutingTableTest_createNode_5::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::pastry::testing::RoutingTableTest_createNode_5::getClass0()
{
    return class_();
}

