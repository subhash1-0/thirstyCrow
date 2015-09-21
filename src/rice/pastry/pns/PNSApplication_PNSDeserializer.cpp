// Generated from /pastry-2.1/src/rice/pastry/pns/PNSApplication.java
#include <rice/pastry/pns/PNSApplication_PNSDeserializer.hpp>

#include <java/lang/ClassCastException.hpp>
#include <rice/p2p/commonapi/Message.hpp>
#include <rice/p2p/commonapi/NodeHandle.hpp>
#include <rice/pastry/NodeHandle.hpp>
#include <rice/pastry/PastryNode.hpp>
#include <rice/pastry/pns/PNSApplication.hpp>
#include <rice/pastry/pns/messages/LeafSetRequest.hpp>
#include <rice/pastry/pns/messages/LeafSetResponse.hpp>
#include <rice/pastry/pns/messages/RouteRowRequest.hpp>
#include <rice/pastry/pns/messages/RouteRowResponse.hpp>

template<typename T, typename U>
static T java_cast(U* u)
{
    if(!u) return static_cast<T>(nullptr);
    auto t = dynamic_cast<T>(u);
    if(!t) throw new ::java::lang::ClassCastException();
    return t;
}

rice::pastry::pns::PNSApplication_PNSDeserializer::PNSApplication_PNSDeserializer(PNSApplication *PNSApplication_this, const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
    , PNSApplication_this(PNSApplication_this)
{
    clinit();
}

rice::pastry::pns::PNSApplication_PNSDeserializer::PNSApplication_PNSDeserializer(PNSApplication *PNSApplication_this)
    : PNSApplication_PNSDeserializer(PNSApplication_this, *static_cast< ::default_init_tag* >(0))
{
    ctor();
}

rice::p2p::commonapi::Message* rice::pastry::pns::PNSApplication_PNSDeserializer::deserialize(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, int16_t type, int32_t priority, ::rice::p2p::commonapi::NodeHandle* sender) /* throws(IOException) */
{
    switch (type) {
    case ::rice::pastry::pns::messages::LeafSetRequest::TYPE:
        return ::rice::pastry::pns::messages::LeafSetRequest::build(buf, java_cast< ::rice::pastry::NodeHandle* >(sender), PNSApplication_this->getAddress());
    case ::rice::pastry::pns::messages::LeafSetResponse::TYPE:
        return ::rice::pastry::pns::messages::LeafSetResponse::build(buf, PNSApplication_this->thePastryNode, PNSApplication_this->getAddress());
    case ::rice::pastry::pns::messages::RouteRowRequest::TYPE:
        return ::rice::pastry::pns::messages::RouteRowRequest::build(buf, java_cast< ::rice::pastry::NodeHandle* >(sender), PNSApplication_this->getAddress());
    case ::rice::pastry::pns::messages::RouteRowResponse::TYPE:
        return new ::rice::pastry::pns::messages::RouteRowResponse(buf, PNSApplication_this->thePastryNode, java_cast< ::rice::pastry::NodeHandle* >(sender), PNSApplication_this->getAddress());
    }

    return nullptr;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::pns::PNSApplication_PNSDeserializer::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.pns.PNSApplication.PNSDeserializer", 46);
    return c;
}

java::lang::Class* rice::pastry::pns::PNSApplication_PNSDeserializer::getClass0()
{
    return class_();
}

