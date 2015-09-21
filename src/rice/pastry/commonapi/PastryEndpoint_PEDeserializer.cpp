// Generated from /pastry-2.1/src/rice/pastry/commonapi/PastryEndpoint.java
#include <rice/pastry/commonapi/PastryEndpoint_PEDeserializer.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/IllegalArgumentException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/p2p/commonapi/NodeHandle.hpp>
#include <rice/p2p/commonapi/rawserialization/MessageDeserializer.hpp>
#include <rice/pastry/NodeHandle.hpp>
#include <rice/pastry/commonapi/PastryEndpoint.hpp>
#include <rice/pastry/commonapi/PastryEndpointMessage.hpp>

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

rice::pastry::commonapi::PastryEndpoint_PEDeserializer::PastryEndpoint_PEDeserializer(PastryEndpoint *PastryEndpoint_this, const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
    , PastryEndpoint_this(PastryEndpoint_this)
{
    clinit();
}

rice::pastry::commonapi::PastryEndpoint_PEDeserializer::PastryEndpoint_PEDeserializer(PastryEndpoint *PastryEndpoint_this)
    : PastryEndpoint_PEDeserializer(PastryEndpoint_this, *static_cast< ::default_init_tag* >(0))
{
    ctor();
}

rice::p2p::commonapi::Message* rice::pastry::commonapi::PastryEndpoint_PEDeserializer::deserialize(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, int16_t type, int32_t priority, ::rice::p2p::commonapi::NodeHandle* sender) /* throws(IOException) */
{
    try {
        return new PastryEndpointMessage(PastryEndpoint_this->getAddress(), buf, PastryEndpoint_this->appDeserializer, type, priority, java_cast< ::rice::pastry::NodeHandle* >(sender));
    } catch (::java::lang::IllegalArgumentException* iae) {
        npc(PastryEndpoint_this->logger)->log(::java::lang::StringBuilder().append(u"Unable to deserialize message of type "_j)->append(type)
            ->append(u" "_j)
            ->append(static_cast< ::java::lang::Object* >(PastryEndpoint_this))
            ->append(u" "_j)
            ->append(static_cast< ::java::lang::Object* >(PastryEndpoint_this->appDeserializer))->toString());
        throw iae;
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::commonapi::PastryEndpoint_PEDeserializer::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.commonapi.PastryEndpoint.PEDeserializer", 51);
    return c;
}

java::lang::Class* rice::pastry::commonapi::PastryEndpoint_PEDeserializer::getClass0()
{
    return class_();
}

