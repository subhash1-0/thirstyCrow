// Generated from /pastry-2.1/src/rice/pastry/direct/DirectPastryNodeFactory.java
#include <rice/pastry/direct/DirectPastryNodeFactory_getNodeHandleAdapter_2.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/util/ArrayList.hpp>
#include <java/util/List.hpp>
#include <org/mpisws/p2p/transport/proximity/ProximityListener.hpp>
#include <rice/pastry/NodeHandle.hpp>
#include <rice/pastry/PastryNode.hpp>
#include <rice/pastry/direct/DirectNodeHandle.hpp>
#include <rice/pastry/direct/DirectPastryNodeFactory.hpp>
#include <rice/pastry/direct/NetworkSimulator.hpp>

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

rice::pastry::direct::DirectPastryNodeFactory_getNodeHandleAdapter_2::DirectPastryNodeFactory_getNodeHandleAdapter_2(DirectPastryNodeFactory *DirectPastryNodeFactory_this, ::rice::pastry::PastryNode* pn)
    : super(*static_cast< ::default_init_tag* >(0))
    , DirectPastryNodeFactory_this(DirectPastryNodeFactory_this)
    , pn(pn)
{
    clinit();
    init();
    ctor();
}

void rice::pastry::direct::DirectPastryNodeFactory_getNodeHandleAdapter_2::init()
{
    proxListeners = new ::java::util::ArrayList();
}

int32_t rice::pastry::direct::DirectPastryNodeFactory_getNodeHandleAdapter_2::proximity(::rice::pastry::NodeHandle* i, ::java::util::Map* options)
{
    return static_cast< int32_t >(npc(DirectPastryNodeFactory_this->simulator)->proximity(java_cast< DirectNodeHandle* >(npc(pn)->getLocalHandle()), java_cast< DirectNodeHandle* >(i)));
}

int32_t rice::pastry::direct::DirectPastryNodeFactory_getNodeHandleAdapter_2::proximity(::java::lang::Object* i, ::java::util::Map* options)
{ 
    return proximity(dynamic_cast< ::rice::pastry::NodeHandle* >(i), options);
}

void rice::pastry::direct::DirectPastryNodeFactory_getNodeHandleAdapter_2::addProximityListener(::org::mpisws::p2p::transport::proximity::ProximityListener* name)
{
    npc(proxListeners)->add(static_cast< ::java::lang::Object* >(name));
}

bool rice::pastry::direct::DirectPastryNodeFactory_getNodeHandleAdapter_2::removeProximityListener(::org::mpisws::p2p::transport::proximity::ProximityListener* name)
{
    return npc(proxListeners)->remove(static_cast< ::java::lang::Object* >(name));
}

void rice::pastry::direct::DirectPastryNodeFactory_getNodeHandleAdapter_2::clearState(::rice::pastry::NodeHandle* i)
{
}

void rice::pastry::direct::DirectPastryNodeFactory_getNodeHandleAdapter_2::clearState(::java::lang::Object* i)
{ 
    clearState(dynamic_cast< ::rice::pastry::NodeHandle* >(i));
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::direct::DirectPastryNodeFactory_getNodeHandleAdapter_2::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::pastry::direct::DirectPastryNodeFactory_getNodeHandleAdapter_2::getClass0()
{
    return class_();
}

