// Generated from /pastry-2.1/src/rice/pastry/pns/PNSApplication.java
#include <rice/pastry/pns/PNSApplication_seekThroughRouteRows_13.hpp>

#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/Iterable.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/util/Observer.hpp>
#include <rice/Continuation.hpp>
#include <rice/p2p/commonapi/NodeHandleSet.hpp>
#include <rice/p2p/util/AttachableCancellable.hpp>
#include <rice/pastry/NodeSetI.hpp>
#include <rice/pastry/pns/PNSApplication_seekThroughRouteRows_13_receiveResult_13_1.hpp>
#include <rice/pastry/pns/PNSApplication.hpp>
#include <rice/pastry/routing/RouteSet.hpp>
#include <SubArray.hpp>
#include <ObjectArray.hpp>

template<typename ComponentType, typename... Bases> struct SubArray;
namespace java
{
    namespace io
    {
typedef ::SubArray< ::java::io::Serializable, ::java::lang::ObjectArray > SerializableArray;
    } // io

    namespace lang
    {
typedef ::SubArray< ::java::lang::Iterable, ObjectArray > IterableArray;
    } // lang

    namespace util
    {
typedef ::SubArray< ::java::util::Observer, ::java::lang::ObjectArray > ObserverArray;
    } // util
} // java

namespace rice
{
    namespace p2p
    {
        namespace commonapi
        {
typedef ::SubArray< ::rice::p2p::commonapi::NodeHandleSet, ::java::lang::ObjectArray, ::java::io::SerializableArray > NodeHandleSetArray;
        } // commonapi
    } // p2p

    namespace pastry
    {
typedef ::SubArray< ::rice::pastry::NodeSetI, ::java::lang::ObjectArray, ::rice::p2p::commonapi::NodeHandleSetArray > NodeSetIArray;

        namespace routing
        {
typedef ::SubArray< ::rice::pastry::routing::RouteSet, ::java::lang::ObjectArray, ::rice::pastry::NodeSetIArray, ::java::io::SerializableArray, ::java::util::ObserverArray, ::java::lang::IterableArray > RouteSetArray;
        } // routing
    } // pastry
} // rice

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::pastry::pns::PNSApplication_seekThroughRouteRows_13::PNSApplication_seekThroughRouteRows_13(PNSApplication *PNSApplication_this, ::rice::p2p::util::AttachableCancellable* ret, ::rice::pastry::NodeHandle* currentClosest, int16_t i, int16_t depth, ::rice::Continuation* returnToMe)
    : super(*static_cast< ::default_init_tag* >(0))
    , PNSApplication_this(PNSApplication_this)
    , ret(ret)
    , currentClosest(currentClosest)
    , i(i)
    , depth(depth)
    , returnToMe(returnToMe)
{
    clinit();
    ctor();
}

void rice::pastry::pns::PNSApplication_seekThroughRouteRows_13::receiveResult(::rice::pastry::routing::RouteSetArray* result)
{
    npc(ret)->attach(PNSApplication_this->closestToMe(currentClosest, result, static_cast< ::rice::Continuation* >(new PNSApplication_seekThroughRouteRows_13_receiveResult_13_1(this, i, depth, currentClosest, returnToMe))));
}

void rice::pastry::pns::PNSApplication_seekThroughRouteRows_13::receiveResult(::java::lang::Object* result)
{ 
    receiveResult(dynamic_cast< ::rice::pastry::routing::RouteSetArray* >(result));
}

void rice::pastry::pns::PNSApplication_seekThroughRouteRows_13::receiveException(::java::lang::Exception* exception)
{
    npc(returnToMe)->receiveException(exception);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::pns::PNSApplication_seekThroughRouteRows_13::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::pastry::pns::PNSApplication_seekThroughRouteRows_13::getClass0()
{
    return class_();
}

