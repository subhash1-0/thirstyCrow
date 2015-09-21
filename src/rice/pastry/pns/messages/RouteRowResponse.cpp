// Generated from /pastry-2.1/src/rice/pastry/pns/messages/RouteRowResponse.java
#include <rice/pastry/pns/messages/RouteRowResponse.hpp>

#include <java/io/IOException.hpp>
#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/IllegalArgumentException.hpp>
#include <java/lang/Iterable.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/util/Observer.hpp>
#include <rice/p2p/commonapi/NodeHandleSet.hpp>
#include <rice/p2p/commonapi/rawserialization/InputBuffer.hpp>
#include <rice/p2p/commonapi/rawserialization/OutputBuffer.hpp>
#include <rice/pastry/NodeHandle.hpp>
#include <rice/pastry/NodeSetI.hpp>
#include <rice/pastry/PastryNode.hpp>
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

rice::pastry::pns::messages::RouteRowResponse::RouteRowResponse(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::pns::messages::RouteRowResponse::RouteRowResponse(::rice::pastry::NodeHandle* sender, int16_t index, ::rice::pastry::routing::RouteSetArray* row, int32_t address) 
    : RouteRowResponse(*static_cast< ::default_init_tag* >(0))
{
    ctor(sender,index,row,address);
}

rice::pastry::pns::messages::RouteRowResponse::RouteRowResponse(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::pastry::PastryNode* localNode, ::rice::pastry::NodeHandle* sender, int32_t dest)  /* throws(IOException) */
    : RouteRowResponse(*static_cast< ::default_init_tag* >(0))
{
    ctor(buf,localNode,sender,dest);
}

constexpr int16_t rice::pastry::pns::messages::RouteRowResponse::TYPE;

void rice::pastry::pns::messages::RouteRowResponse::ctor(::rice::pastry::NodeHandle* sender, int16_t index, ::rice::pastry::routing::RouteSetArray* row, int32_t address)
{
    super::ctor(address);
    if(sender == nullptr)
        throw new ::java::lang::IllegalArgumentException(u"sender == null!"_j);

    setSender(sender);
    this->index = index;
    this->row = row;
    setPriority(HIGH_PRIORITY);
}

java::lang::String* rice::pastry::pns::messages::RouteRowResponse::toString()
{
    return ::java::lang::StringBuilder().append(u"RRresp["_j)->append(index)
        ->append(u"]:"_j)
        ->append(static_cast< ::java::lang::Object* >(getSender()))->toString();
}

void rice::pastry::pns::messages::RouteRowResponse::serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */
{
    npc(buf)->writeByte(static_cast< int8_t >(int32_t(0)));
    npc(buf)->writeShort(index);
    npc(buf)->writeInt(npc(row)->length);
    for (auto i = int32_t(0); i < npc(row)->length; i++) {
        if((*row)[i] == nullptr) {
            npc(buf)->writeBoolean(false);
        } else {
            npc(buf)->writeBoolean(true);
            npc((*row)[i])->serialize(buf);
        }
    }
}

void rice::pastry::pns::messages::RouteRowResponse::ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::pastry::PastryNode* localNode, ::rice::pastry::NodeHandle* sender, int32_t dest) /* throws(IOException) */
{
    super::ctor(dest);
    auto version = npc(buf)->readByte();
    {
        int32_t numRouteSets;
        switch (version) {
        case int32_t(0):
            setSender(sender);
            index = npc(buf)->readShort();
            numRouteSets = npc(buf)->readInt();
            row = new ::rice::pastry::routing::RouteSetArray(numRouteSets);
            for (auto i = int32_t(0); i < numRouteSets; i++) {
                if(npc(buf)->readBoolean()) {
                    row->set(i, new ::rice::pastry::routing::RouteSet(buf, localNode, localNode));
                }
            }
            break;
        default:
            throw new ::java::io::IOException(::java::lang::StringBuilder().append(u"Unknown Version: "_j)->append(version)->toString());
        }
    }

}

int16_t rice::pastry::pns::messages::RouteRowResponse::getType()
{
    return TYPE;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::pns::messages::RouteRowResponse::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.pns.messages.RouteRowResponse", 41);
    return c;
}

java::lang::Class* rice::pastry::pns::messages::RouteRowResponse::getClass0()
{
    return class_();
}

