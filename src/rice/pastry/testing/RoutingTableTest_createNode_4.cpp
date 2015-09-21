// Generated from /pastry-2.1/src/rice/pastry/testing/RoutingTableTest.java
#include <rice/pastry/testing/RoutingTableTest_createNode_4.hpp>

#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/util/HashMap.hpp>
#include <java/util/Vector.hpp>
#include <rice/pastry/PastryNode.hpp>
#include <rice/pastry/testing/RoutingTableTest.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::pastry::testing::RoutingTableTest_createNode_4::RoutingTableTest_createNode_4(RoutingTableTest *RoutingTableTest_this, ::rice::pastry::PastryNode* node)
    : super(*static_cast< ::default_init_tag* >(0))
    , RoutingTableTest_this(RoutingTableTest_this)
    , node(node)
{
    clinit();
    ctor();
}

void rice::pastry::testing::RoutingTableTest_createNode_4::destroy()
{
    npc(RoutingTableTest_this->nodes)->remove(static_cast< ::java::lang::Object* >(node));
    npc(RoutingTableTest_this->apps)->remove(static_cast< ::java::lang::Object* >(node));
    try {
        RoutingTableTest_this->createNode();
    } catch (::java::lang::Exception* ie) {
        npc(ie)->printStackTrace();
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::testing::RoutingTableTest_createNode_4::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::pastry::testing::RoutingTableTest_createNode_4::getClass0()
{
    return class_();
}

