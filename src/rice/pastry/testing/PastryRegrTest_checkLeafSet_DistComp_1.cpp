// Generated from /pastry-2.1/src/rice/pastry/testing/PastryRegrTest.java
#include <rice/pastry/testing/PastryRegrTest_checkLeafSet_DistComp_1.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <rice/p2p/commonapi/Id_Distance.hpp>
#include <rice/pastry/Id_Distance.hpp>
#include <rice/pastry/Id.hpp>
#include <rice/pastry/testing/PastryRegrTest.hpp>

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

rice::pastry::testing::PastryRegrTest_checkLeafSet_DistComp_1::PastryRegrTest_checkLeafSet_DistComp_1(PastryRegrTest *PastryRegrTest_this, const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
    , PastryRegrTest_this(PastryRegrTest_this)
{
    clinit();
}

rice::pastry::testing::PastryRegrTest_checkLeafSet_DistComp_1::PastryRegrTest_checkLeafSet_DistComp_1(PastryRegrTest *PastryRegrTest_this, ::rice::pastry::Id* id) 
    : PastryRegrTest_checkLeafSet_DistComp_1(PastryRegrTest_this, *static_cast< ::default_init_tag* >(0))
{
    ctor(id);
}

void rice::pastry::testing::PastryRegrTest_checkLeafSet_DistComp_1::ctor(::rice::pastry::Id* id)
{
    super::ctor();
    this->id = id;
}

int32_t rice::pastry::testing::PastryRegrTest_checkLeafSet_DistComp_1::compare(::rice::pastry::Id* o1, ::rice::pastry::Id* o2)
{
    auto nid1 = java_cast< ::rice::pastry::Id* >(o1);
    auto nid2 = java_cast< ::rice::pastry::Id* >(o2);
    return npc(npc(nid1)->distance(id))->compareTo(static_cast< ::rice::p2p::commonapi::Id_Distance* >(npc(nid2)->distance(id)));
}

int32_t rice::pastry::testing::PastryRegrTest_checkLeafSet_DistComp_1::compare(::java::lang::Object* arg0, ::java::lang::Object* arg1)
{ 
    return compare(dynamic_cast< ::rice::pastry::Id* >(arg0), dynamic_cast< ::rice::pastry::Id* >(arg1));
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::testing::PastryRegrTest_checkLeafSet_DistComp_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

bool rice::pastry::testing::PastryRegrTest_checkLeafSet_DistComp_1::equals(::java::lang::Object* arg0)
{
    return Object::equals(arg0);
}

java::lang::Class* rice::pastry::testing::PastryRegrTest_checkLeafSet_DistComp_1::getClass0()
{
    return class_();
}

