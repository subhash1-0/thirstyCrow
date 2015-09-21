// Generated from /pastry-2.1/src/rice/pastry/leafset/BroadcastLeafSet.java
#include <rice/pastry/leafset/BroadcastLeafSet.hpp>

#include <java/io/IOException.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/IllegalArgumentException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/p2p/commonapi/rawserialization/InputBuffer.hpp>
#include <rice/p2p/commonapi/rawserialization/OutputBuffer.hpp>
#include <rice/pastry/NodeHandle.hpp>
#include <rice/pastry/NodeHandleFactory.hpp>
#include <rice/pastry/leafset/LeafSet.hpp>
#include <rice/pastry/leafset/LeafSetProtocolAddress.hpp>

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

rice::pastry::leafset::BroadcastLeafSet::BroadcastLeafSet(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::leafset::BroadcastLeafSet::BroadcastLeafSet(::rice::pastry::NodeHandle* from, LeafSet* leafSet, int32_t type, int64_t requestTimeStamp) 
    : BroadcastLeafSet(*static_cast< ::default_init_tag* >(0))
{
    ctor(from,leafSet,type,requestTimeStamp);
}

rice::pastry::leafset::BroadcastLeafSet::BroadcastLeafSet(::java::util::Date* stamp, ::rice::pastry::NodeHandle* from, LeafSet* leafSet, int32_t type, int64_t requestTimeStamp) 
    : BroadcastLeafSet(*static_cast< ::default_init_tag* >(0))
{
    ctor(stamp,from,leafSet,type,requestTimeStamp);
}

rice::pastry::leafset::BroadcastLeafSet::BroadcastLeafSet(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::pastry::NodeHandleFactory* nhf)  /* throws(IOException) */
    : BroadcastLeafSet(*static_cast< ::default_init_tag* >(0))
{
    ctor(buf,nhf);
}

constexpr int16_t rice::pastry::leafset::BroadcastLeafSet::TYPE;

constexpr int32_t rice::pastry::leafset::BroadcastLeafSet::Update;

constexpr int32_t rice::pastry::leafset::BroadcastLeafSet::JoinInitial;

constexpr int32_t rice::pastry::leafset::BroadcastLeafSet::JoinAdvertise;

constexpr int32_t rice::pastry::leafset::BroadcastLeafSet::Correction;

void rice::pastry::leafset::BroadcastLeafSet::ctor(::rice::pastry::NodeHandle* from, LeafSet* leafSet, int32_t type, int64_t requestTimeStamp)
{
    ctor(nullptr, from, leafSet, type, requestTimeStamp);
}

void rice::pastry::leafset::BroadcastLeafSet::ctor(::java::util::Date* stamp, ::rice::pastry::NodeHandle* from, LeafSet* leafSet, int32_t type, int64_t requestTimeStamp)
{
    super::ctor(LeafSetProtocolAddress::getCode(), stamp);
    if(leafSet == nullptr)
        throw new ::java::lang::IllegalArgumentException(u"Leafset is null"_j);

    fromNode = from;
    theLeafSet = npc(leafSet)->copy();
    theType = type;
    this->requestTimeStamp = requestTimeStamp;
    setPriority(MAX_PRIORITY);
}

rice::pastry::NodeHandle* rice::pastry::leafset::BroadcastLeafSet::from()
{
    return fromNode;
}

rice::pastry::leafset::LeafSet* rice::pastry::leafset::BroadcastLeafSet::leafSet()
{
    return theLeafSet;
}

int32_t rice::pastry::leafset::BroadcastLeafSet::type()
{
    return theType;
}

java::lang::String* rice::pastry::leafset::BroadcastLeafSet::toString()
{
    auto s = ::java::lang::StringBuilder().append(u"BroadcastLeafSet("_j)->append(static_cast< ::java::lang::Object* >(theLeafSet))
        ->append(u","_j)
        ->append(requestTimeStamp)
        ->append(u")"_j)->toString();
    return s;
}

int16_t rice::pastry::leafset::BroadcastLeafSet::getType()
{
    return TYPE;
}

void rice::pastry::leafset::BroadcastLeafSet::serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */
{
    npc(buf)->writeByte(static_cast< int8_t >(int32_t(0)));
    npc(fromNode)->serialize(buf);
    npc(theLeafSet)->serialize(buf);
    npc(buf)->writeByte(static_cast< int8_t >(theType));
    npc(buf)->writeLong(requestTimeStamp);
}

void rice::pastry::leafset::BroadcastLeafSet::ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::pastry::NodeHandleFactory* nhf) /* throws(IOException) */
{
    super::ctor(LeafSetProtocolAddress::getCode());
    auto version = npc(buf)->readByte();
    switch (version) {
    case int32_t(0):
        fromNode = java_cast< ::rice::pastry::NodeHandle* >(npc(nhf)->readNodeHandle(buf));
        theLeafSet = LeafSet::build(buf, nhf);
        theType = npc(buf)->readByte();
        requestTimeStamp = npc(buf)->readLong();
        break;
    default:
        throw new ::java::io::IOException(::java::lang::StringBuilder().append(u"Unknown Version: "_j)->append(version)->toString());
    }

}

int64_t rice::pastry::leafset::BroadcastLeafSet::getTimeStamp()
{
    return requestTimeStamp;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::leafset::BroadcastLeafSet::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.leafset.BroadcastLeafSet", 36);
    return c;
}

java::lang::Class* rice::pastry::leafset::BroadcastLeafSet::getClass0()
{
    return class_();
}

