// Generated from /pastry-2.1/src/rice/pastry/testing/LeafSetTest.java
#include <rice/pastry/testing/LeafSetTest_MyObserver.hpp>

#include <java/io/PrintStream.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>
#include <rice/pastry/NodeHandle.hpp>
#include <rice/pastry/NodeSetEventSource.hpp>
#include <rice/pastry/leafset/LeafSet.hpp>
#include <rice/pastry/leafset/SimilarSet.hpp>
#include <rice/pastry/testing/LeafSetTest.hpp>

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

rice::pastry::testing::LeafSetTest_MyObserver::LeafSetTest_MyObserver(LeafSetTest *LeafSetTest_this, const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
    , LeafSetTest_this(LeafSetTest_this)
{
    clinit();
}

rice::pastry::testing::LeafSetTest_MyObserver::LeafSetTest_MyObserver(LeafSetTest *LeafSetTest_this, ::rice::pastry::leafset::LeafSet* ls) 
    : LeafSetTest_MyObserver(LeafSetTest_this, *static_cast< ::default_init_tag* >(0))
{
    ctor(ls);
}

void rice::pastry::testing::LeafSetTest_MyObserver::ctor(::rice::pastry::leafset::LeafSet* ls)
{
    super::ctor();
    this->ls = ls;
}

void rice::pastry::testing::LeafSetTest_MyObserver::nodeSetUpdate(::rice::pastry::NodeSetEventSource* set, ::rice::pastry::NodeHandle* handle, bool added)
{
    ::rice::pastry::leafset::SimilarSet* caller;
    if(dynamic_cast< ::rice::pastry::leafset::SimilarSet* >(set) != nullptr) {
        caller = java_cast< ::rice::pastry::leafset::SimilarSet* >(set);
    }
    if(npc(ls)->overlaps() && (npc(ls)->ccwSize() != npc(ls)->cwSize())) {
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"FAILURE: overlaps and different size"_j)->append(static_cast< ::java::lang::Object* >(ls))->toString());
    }
    if(added) {
        auto consistent = !npc(ls)->directTest(handle);
        if(!consistent) {
            npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"FAILURE:"_j)->append(static_cast< ::java::lang::Object* >(handle))
                ->append(u" was added, but ls is inconsistent."_j)->toString());
            npc(::java::lang::System::out())->println(static_cast< ::java::lang::Object* >(ls));
        } else {
            npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"OK:"_j)->append(static_cast< ::java::lang::Object* >(handle))
                ->append(u" was added"_j)->toString());
        }
    } else {
        auto consistent = !npc(ls)->member(npc(handle)->getNodeId());
        if(!consistent) {
            npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"FAILURE:"_j)->append(static_cast< ::java::lang::Object* >(handle))
                ->append(u" was removed, but ls is inconsistent."_j)->toString());
            npc(::java::lang::System::out())->println(static_cast< ::java::lang::Object* >(ls));
        } else {
            npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"OK:"_j)->append(static_cast< ::java::lang::Object* >(handle))
                ->append(u" was removed"_j)->toString());
        }
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::testing::LeafSetTest_MyObserver::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.testing.LeafSetTest.MyObserver", 42);
    return c;
}

java::lang::Class* rice::pastry::testing::LeafSetTest_MyObserver::getClass0()
{
    return class_();
}

