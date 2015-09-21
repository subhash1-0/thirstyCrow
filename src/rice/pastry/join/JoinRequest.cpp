// Generated from /pastry-2.1/src/rice/pastry/join/JoinRequest.java
#include <rice/pastry/join/JoinRequest.hpp>

#include <java/io/IOException.hpp>
#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Cloneable.hpp>
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
#include <rice/pastry/join/JoinAddress.hpp>
#include <rice/pastry/leafset/LeafSet.hpp>
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
typedef ::SubArray< ::java::lang::Cloneable, ObjectArray > CloneableArray;
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
typedef ::SubArray< ::rice::pastry::routing::RouteSetArray, ::java::lang::CloneableArray, ::java::io::SerializableArray > RouteSetArrayArray;
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

rice::pastry::join::JoinRequest::JoinRequest(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::join::JoinRequest::JoinRequest(::rice::pastry::NodeHandle* nh, int8_t rtBaseBitLength) 
    : JoinRequest(*static_cast< ::default_init_tag* >(0))
{
    ctor(nh,rtBaseBitLength);
}

rice::pastry::join::JoinRequest::JoinRequest(::rice::pastry::NodeHandle* nh, int8_t rtBaseBitLength, int64_t timestamp) 
    : JoinRequest(*static_cast< ::default_init_tag* >(0))
{
    ctor(nh,rtBaseBitLength,timestamp);
}

rice::pastry::join::JoinRequest::JoinRequest(::rice::pastry::NodeHandle* nh, ::java::util::Date* stamp, int8_t rtBaseBitLength) 
    : JoinRequest(*static_cast< ::default_init_tag* >(0))
{
    ctor(nh,stamp,rtBaseBitLength);
}

rice::pastry::join::JoinRequest::JoinRequest(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::pastry::NodeHandleFactory* nhf, ::rice::pastry::NodeHandle* sender, ::rice::pastry::PastryNode* localNode)  /* throws(IOException) */
    : JoinRequest(*static_cast< ::default_init_tag* >(0))
{
    ctor(buf,nhf,sender,localNode);
}

constexpr int8_t rice::pastry::join::JoinRequest::HAS_HANDLE;

constexpr int8_t rice::pastry::join::JoinRequest::HAS_JOIN_HANDLE;

constexpr int8_t rice::pastry::join::JoinRequest::HAS_LEAFSET;

constexpr int64_t rice::pastry::join::JoinRequest::serialVersionUID;

constexpr int16_t rice::pastry::join::JoinRequest::TYPE;

void rice::pastry::join::JoinRequest::ctor(::rice::pastry::NodeHandle* nh, int8_t rtBaseBitLength)
{
    ctor(nh, static_cast< ::java::util::Date* >(nullptr), rtBaseBitLength);
}

void rice::pastry::join::JoinRequest::ctor(::rice::pastry::NodeHandle* nh, int8_t rtBaseBitLength, int64_t timestamp)
{
    ctor(nh, static_cast< ::java::util::Date* >(nullptr), rtBaseBitLength);
    this->timestamp = timestamp;
}

void rice::pastry::join::JoinRequest::ctor(::rice::pastry::NodeHandle* nh, ::java::util::Date* stamp, int8_t rtBaseBitLength)
{
    super::ctor(JoinAddress::getCode(), stamp);
    handle = nh;
    initialize(rtBaseBitLength);
    setPriority(MAX_PRIORITY);
}

rice::pastry::NodeHandle* rice::pastry::join::JoinRequest::getHandle()
{
    return handle;
}

rice::pastry::NodeHandle* rice::pastry::join::JoinRequest::getJoinHandle()
{
    return joinHandle;
}

rice::pastry::leafset::LeafSet* rice::pastry::join::JoinRequest::getLeafSet()
{
    return leafSet;
}

bool rice::pastry::join::JoinRequest::accepted()
{
    return joinHandle != nullptr;
}

void rice::pastry::join::JoinRequest::acceptJoin(::rice::pastry::NodeHandle* nh, ::rice::pastry::leafset::LeafSet* ls)
{
    joinHandle = nh;
    leafSet = ls;
}

int32_t rice::pastry::join::JoinRequest::lastRow()
{
    return rowCount;
}

void rice::pastry::join::JoinRequest::pushRow(::rice::pastry::routing::RouteSetArray* row)
{
    rows->set(--rowCount, row);
}

rice::pastry::routing::RouteSetArray* rice::pastry::join::JoinRequest::getRow(int32_t i)
{
    return (*rows)[i];
}

int32_t rice::pastry::join::JoinRequest::numRows()
{
    return npc(rows)->length;
}

void rice::pastry::join::JoinRequest::initialize(int8_t rtBaseBitLength)
{
    joinHandle = nullptr;
    this->rtBaseBitLength = rtBaseBitLength;
    rowCount = static_cast< int16_t >((::rice::pastry::Id::IdBitLength / rtBaseBitLength));
    rows = new ::rice::pastry::routing::RouteSetArrayArray(rowCount);
}

java::lang::String* rice::pastry::join::JoinRequest::toString()
{
    return ::java::lang::StringBuilder().append(u"JoinRequest("_j)->append(static_cast< ::java::lang::Object* >((handle != nullptr ? npc(handle)->getNodeId() : static_cast< ::rice::pastry::Id* >(nullptr))))
        ->append(u","_j)
        ->append(static_cast< ::java::lang::Object* >((joinHandle != nullptr ? npc(joinHandle)->getNodeId() : static_cast< ::rice::pastry::Id* >(nullptr))))
        ->append(u","_j)
        ->append(timestamp)
        ->append(u")"_j)->toString();
}

int16_t rice::pastry::join::JoinRequest::getType()
{
    return TYPE;
}

void rice::pastry::join::JoinRequest::serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */
{
    npc(buf)->writeByte(static_cast< int8_t >(int32_t(1)));
    npc(buf)->writeLong(timestamp);
    npc(buf)->writeByte(static_cast< int8_t >(rtBaseBitLength));
    npc(handle)->serialize(buf);
    if(joinHandle != nullptr) {
        npc(buf)->writeBoolean(true);
        npc(joinHandle)->serialize(buf);
    } else {
        npc(buf)->writeBoolean(false);
    }
    npc(buf)->writeShort(static_cast< int16_t >(rowCount));
    auto maxIndex = ::rice::pastry::Id::IdBitLength / rtBaseBitLength;
    for (auto i = int32_t(0); i < maxIndex; i++) {
        auto thisRow = (*rows)[i];
        if(thisRow != nullptr) {
            npc(buf)->writeBoolean(true);
            for (auto j = int32_t(0); j < npc(thisRow)->length; j++) {
                if((*thisRow)[j] != nullptr) {
                    npc(buf)->writeBoolean(true);
                    npc((*thisRow)[j])->serialize(buf);
                } else {
                    npc(buf)->writeBoolean(false);
                }
            }
        } else {
            npc(buf)->writeBoolean(false);
        }
    }
    if(leafSet != nullptr) {
        npc(buf)->writeBoolean(true);
        npc(leafSet)->serialize(buf);
    } else {
        npc(buf)->writeBoolean(false);
    }
}

void rice::pastry::join::JoinRequest::ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::pastry::NodeHandleFactory* nhf, ::rice::pastry::NodeHandle* sender, ::rice::pastry::PastryNode* localNode) /* throws(IOException) */
{
    super::ctor(JoinAddress::getCode());
    auto version = npc(buf)->readByte();
    {
        int32_t numRows;
        int32_t numCols;
        switch (version) {
        case int32_t(1):
            timestamp = npc(buf)->readLong();
        case int32_t(0):
            setSender(sender);
            rtBaseBitLength = npc(buf)->readByte();
            initialize(rtBaseBitLength);
            handle = java_cast< ::rice::pastry::NodeHandle* >(npc(nhf)->readNodeHandle(buf));
            if(npc(buf)->readBoolean())
                joinHandle = java_cast< ::rice::pastry::NodeHandle* >(npc(nhf)->readNodeHandle(buf));

            rowCount = npc(buf)->readShort();
            numRows = ::rice::pastry::Id::IdBitLength / rtBaseBitLength;
            numCols = int32_t(1) << rtBaseBitLength;
            for (auto i = int32_t(0); i < numRows; i++) {
                ::rice::pastry::routing::RouteSetArray* thisRow;
                if(npc(buf)->readBoolean()) {
                    thisRow = new ::rice::pastry::routing::RouteSetArray(numCols);
                    for (auto j = int32_t(0); j < numCols; j++) {
                        if(npc(buf)->readBoolean()) {
                            thisRow->set(j, new ::rice::pastry::routing::RouteSet(buf, nhf, localNode));
                        } else {
                            thisRow->set(j, nullptr);
                        }
                    }
                } else {
                    thisRow = nullptr;
                }
                rows->set(i, thisRow);
            }
            if(npc(buf)->readBoolean())
                leafSet = ::rice::pastry::leafset::LeafSet::build(buf, nhf);

            break;
        default:
            throw new ::java::io::IOException(::java::lang::StringBuilder().append(u"Unknown Version: "_j)->append(version)->toString());
        }
    }

}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::join::JoinRequest::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.join.JoinRequest", 28);
    return c;
}

java::lang::Class* rice::pastry::join::JoinRequest::getClass0()
{
    return class_();
}

