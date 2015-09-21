// Generated from /pastry-2.1/src/rice/pastry/commonapi/PastryEndpoint.java
#include <rice/pastry/commonapi/PastryEndpoint_networkNeighbors_3.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <rice/p2p/commonapi/NodeHandle.hpp>
#include <rice/pastry/NodeHandle.hpp>
#include <rice/pastry/PastryNode.hpp>
#include <rice/pastry/commonapi/PastryEndpoint.hpp>

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

rice::pastry::commonapi::PastryEndpoint_networkNeighbors_3::PastryEndpoint_networkNeighbors_3(PastryEndpoint *PastryEndpoint_this)
    : super(*static_cast< ::default_init_tag* >(0))
    , PastryEndpoint_this(PastryEndpoint_this)
{
    clinit();
    ctor();
}

int32_t rice::pastry::commonapi::PastryEndpoint_networkNeighbors_3::compare(::rice::p2p::commonapi::NodeHandle* a, ::rice::p2p::commonapi::NodeHandle* b)
{
    return npc(PastryEndpoint_this->thePastryNode)->proximity(java_cast< ::rice::pastry::NodeHandle* >(a)) - npc(PastryEndpoint_this->thePastryNode)->proximity(java_cast< ::rice::pastry::NodeHandle* >(b));
}

int32_t rice::pastry::commonapi::PastryEndpoint_networkNeighbors_3::compare(::java::lang::Object* arg0, ::java::lang::Object* arg1)
{ 
    return compare(dynamic_cast< ::rice::p2p::commonapi::NodeHandle* >(arg0), dynamic_cast< ::rice::p2p::commonapi::NodeHandle* >(arg1));
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::commonapi::PastryEndpoint_networkNeighbors_3::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

bool rice::pastry::commonapi::PastryEndpoint_networkNeighbors_3::equals(::java::lang::Object* arg0)
{
    return Object::equals(arg0);
}

java::lang::Class* rice::pastry::commonapi::PastryEndpoint_networkNeighbors_3::getClass0()
{
    return class_();
}

