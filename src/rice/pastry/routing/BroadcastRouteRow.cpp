// Generated from /pastry-2.1/src/rice/pastry/routing/BroadcastRouteRow.java
#include <rice/pastry/routing/BroadcastRouteRow.hpp>

#include <java/io/IOException.hpp>
#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Iterable.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/util/Date.hpp>
#include <java/util/Observer.hpp>
#include <rice/p2p/commonapi/NodeHandleSet.hpp>
#include <rice/p2p/commonapi/rawserialization/InputBuffer.hpp>
#include <rice/p2p/commonapi/rawserialization/OutputBuffer.hpp>
#include <rice/pastry/Id.hpp>
#include <rice/pastry/NodeHandle.hpp>
#include <rice/pastry/NodeHandleFactory.hpp>
#include <rice/pastry/NodeSetI.hpp>
#include <rice/pastry/routing/RouteProtocolAddress.hpp>
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

rice::pastry::routing::BroadcastRouteRow::BroadcastRouteRow(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::routing::BroadcastRouteRow::BroadcastRouteRow(::java::util::Date* stamp, ::rice::pastry::NodeHandle* from, RouteSetArray* r) 
    : BroadcastRouteRow(*static_cast< ::default_init_tag* >(0))
{
    ctor(stamp,from,r);
}

rice::pastry::routing::BroadcastRouteRow::BroadcastRouteRow(::rice::pastry::NodeHandle* from, RouteSetArray* r) 
    : BroadcastRouteRow(*static_cast< ::default_init_tag* >(0))
{
    ctor(from,r);
}

rice::pastry::routing::BroadcastRouteRow::BroadcastRouteRow(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::pastry::NodeHandleFactory* nhf, ::rice::pastry::PastryNode* localNode)  /* throws(IOException) */
    : BroadcastRouteRow(*static_cast< ::default_init_tag* >(0))
{
    ctor(buf,nhf,localNode);
}

constexpr int16_t rice::pastry::routing::BroadcastRouteRow::TYPE;

void rice::pastry::routing::BroadcastRouteRow::ctor(::java::util::Date* stamp, ::rice::pastry::NodeHandle* from, RouteSetArray* r)
{
    super::ctor(RouteProtocolAddress::getCode(), stamp);
    fromNode = from;
    row = r;
    setPriority(MAX_PRIORITY);
}

void rice::pastry::routing::BroadcastRouteRow::ctor(::rice::pastry::NodeHandle* from, RouteSetArray* r)
{
    ctor(static_cast< ::java::util::Date* >(nullptr), from, r);
}

rice::pastry::NodeHandle* rice::pastry::routing::BroadcastRouteRow::from()
{
    return fromNode;
}

rice::pastry::routing::RouteSetArray* rice::pastry::routing::BroadcastRouteRow::getRow()
{
    return row;
}

java::lang::String* rice::pastry::routing::BroadcastRouteRow::toString()
{
    auto s = u""_j;
    s = ::java::lang::StringBuilder(s).append(::java::lang::StringBuilder().append(u"BroadcastRouteRow(of "_j)->append(static_cast< ::java::lang::Object* >(npc(fromNode)->getNodeId()))
        ->append(u")"_j)->toString())->toString();
    return s;
}

java::lang::String* rice::pastry::routing::BroadcastRouteRow::toStringFull()
{
    auto s = ::java::lang::StringBuilder().append(u"BRR{"_j)->append(static_cast< ::java::lang::Object* >(fromNode))
        ->append(u"}:"_j)->toString();
    for (auto i = int32_t(0); i < npc(row)->length; i++) {
        s = ::java::lang::StringBuilder(s).append(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >((*row)[i]))->append(u"|"_j)->toString())->toString();
    }
    return s;
}

int16_t rice::pastry::routing::BroadcastRouteRow::getType()
{
    return TYPE;
}

void rice::pastry::routing::BroadcastRouteRow::serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */
{
    npc(buf)->writeByte(static_cast< int8_t >(int32_t(0)));
    npc(fromNode)->serialize(buf);
    npc(buf)->writeByte(static_cast< int8_t >(npc(row)->length));
    for (auto i = int32_t(0); i < npc(row)->length; i++) {
        if((*row)[i] != nullptr) {
            npc(buf)->writeBoolean(true);
            npc((*row)[i])->serialize(buf);
        } else {
            npc(buf)->writeBoolean(false);
        }
    }
}

void rice::pastry::routing::BroadcastRouteRow::ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::pastry::NodeHandleFactory* nhf, ::rice::pastry::PastryNode* localNode) /* throws(IOException) */
{
    super::ctor(RouteProtocolAddress::getCode(), nullptr);
    auto version = npc(buf)->readByte();
    switch (version) {
    case int32_t(0):
        fromNode = java_cast< ::rice::pastry::NodeHandle* >(npc(nhf)->readNodeHandle(buf));
        row = new RouteSetArray(npc(buf)->readByte());
        for (auto i = int32_t(0); i < npc(row)->length; i++) 
                        if(npc(buf)->readBoolean()) {
                row->set(i, new RouteSet(buf, nhf, localNode));
            }

        break;
    default:
        throw new ::java::io::IOException(::java::lang::StringBuilder().append(u"Unknown Version: "_j)->append(version)->toString());
    }

}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::routing::BroadcastRouteRow::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.routing.BroadcastRouteRow", 37);
    return c;
}

java::lang::Class* rice::pastry::routing::BroadcastRouteRow::getClass0()
{
    return class_();
}

