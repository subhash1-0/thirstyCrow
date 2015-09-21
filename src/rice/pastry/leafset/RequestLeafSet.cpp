// Generated from /pastry-2.1/src/rice/pastry/leafset/RequestLeafSet.java
#include <rice/pastry/leafset/RequestLeafSet.hpp>

#include <java/io/IOException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/p2p/commonapi/rawserialization/InputBuffer.hpp>
#include <rice/p2p/commonapi/rawserialization/OutputBuffer.hpp>
#include <rice/pastry/NodeHandle.hpp>
#include <rice/pastry/leafset/LeafSetProtocolAddress.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::pastry::leafset::RequestLeafSet::RequestLeafSet(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::leafset::RequestLeafSet::RequestLeafSet(::rice::pastry::NodeHandle* nh, int64_t timeStamp) 
    : RequestLeafSet(*static_cast< ::default_init_tag* >(0))
{
    ctor(nh,timeStamp);
}

rice::pastry::leafset::RequestLeafSet::RequestLeafSet(::java::util::Date* stamp, ::rice::pastry::NodeHandle* nh, int64_t timeStamp) 
    : RequestLeafSet(*static_cast< ::default_init_tag* >(0))
{
    ctor(stamp,nh,timeStamp);
}

rice::pastry::leafset::RequestLeafSet::RequestLeafSet(::rice::pastry::NodeHandle* sender, ::rice::p2p::commonapi::rawserialization::InputBuffer* buf)  /* throws(IOException) */
    : RequestLeafSet(*static_cast< ::default_init_tag* >(0))
{
    ctor(sender,buf);
}

constexpr int16_t rice::pastry::leafset::RequestLeafSet::TYPE;

void rice::pastry::leafset::RequestLeafSet::ctor(::rice::pastry::NodeHandle* nh, int64_t timeStamp)
{
    ctor(nullptr, nh, timeStamp);
}

void rice::pastry::leafset::RequestLeafSet::ctor(::java::util::Date* stamp, ::rice::pastry::NodeHandle* nh, int64_t timeStamp)
{
    super::ctor(LeafSetProtocolAddress::getCode(), stamp);
    setSender(nh);
    this->timeStamp = timeStamp;
    setPriority(MAX_PRIORITY);
}

rice::pastry::NodeHandle* rice::pastry::leafset::RequestLeafSet::returnHandle()
{
    return getSender();
}

java::lang::String* rice::pastry::leafset::RequestLeafSet::toString()
{
    auto s = u""_j;
    s = ::java::lang::StringBuilder(s).append(::java::lang::StringBuilder().append(u"RequestLeafSet("_j)->append(static_cast< ::java::lang::Object* >(getSender()))
        ->append(u","_j)
        ->append(timeStamp)
        ->append(u")"_j)->toString())->toString();
    return s;
}

int16_t rice::pastry::leafset::RequestLeafSet::getType()
{
    return TYPE;
}

void rice::pastry::leafset::RequestLeafSet::serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */
{
    npc(buf)->writeByte(static_cast< int8_t >(int32_t(0)));
    npc(buf)->writeLong(timeStamp);
}

void rice::pastry::leafset::RequestLeafSet::ctor(::rice::pastry::NodeHandle* sender, ::rice::p2p::commonapi::rawserialization::InputBuffer* buf) /* throws(IOException) */
{
    super::ctor(LeafSetProtocolAddress::getCode());
    setSender(sender);
    auto version = npc(buf)->readByte();
    switch (version) {
    case int32_t(0):
        timeStamp = npc(buf)->readLong();
        break;
    default:
        throw new ::java::io::IOException(::java::lang::StringBuilder().append(u"Unknown Version: "_j)->append(version)->toString());
    }

}

int64_t rice::pastry::leafset::RequestLeafSet::getTimeStamp()
{
    return timeStamp;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::leafset::RequestLeafSet::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.leafset.RequestLeafSet", 34);
    return c;
}

java::lang::Class* rice::pastry::leafset::RequestLeafSet::getClass0()
{
    return class_();
}

