// Generated from /pastry-2.1/src/rice/pastry/standard/ConsistentJoinProtocol.java
#include <rice/pastry/standard/ConsistentJoinProtocol_CJPDeserializer.hpp>

#include <java/lang/ClassCastException.hpp>
#include <rice/p2p/commonapi/Message.hpp>
#include <rice/pastry/NodeHandle.hpp>
#include <rice/pastry/NodeHandleFactory.hpp>
#include <rice/pastry/PastryNode.hpp>
#include <rice/pastry/messaging/Message.hpp>
#include <rice/pastry/standard/ConsistentJoinMsg.hpp>

template<typename T, typename U>
static T java_cast(U* u)
{
    if(!u) return static_cast<T>(nullptr);
    auto t = dynamic_cast<T>(u);
    if(!t) throw new ::java::lang::ClassCastException();
    return t;
}

rice::pastry::standard::ConsistentJoinProtocol_CJPDeserializer::ConsistentJoinProtocol_CJPDeserializer(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::standard::ConsistentJoinProtocol_CJPDeserializer::ConsistentJoinProtocol_CJPDeserializer(::rice::pastry::PastryNode* pn) 
    : ConsistentJoinProtocol_CJPDeserializer(*static_cast< ::default_init_tag* >(0))
{
    ctor(pn);
}

void rice::pastry::standard::ConsistentJoinProtocol_CJPDeserializer::ctor(::rice::pastry::PastryNode* pn)
{
    super::ctor(pn);
}

rice::pastry::messaging::Message* rice::pastry::standard::ConsistentJoinProtocol_CJPDeserializer::deserialize(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, int16_t type, int32_t priority, ::rice::pastry::NodeHandle* sender) /* throws(IOException) */
{
    switch (type) {
    case ConsistentJoinMsg::TYPE:
        return new ConsistentJoinMsg(buf, static_cast< ::rice::pastry::NodeHandleFactory* >(pn), java_cast< ::rice::pastry::NodeHandle* >(sender));
    }

    return super::deserialize(buf, type, priority, sender);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::standard::ConsistentJoinProtocol_CJPDeserializer::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.standard.ConsistentJoinProtocol.CJPDeserializer", 59);
    return c;
}

rice::p2p::commonapi::Message* rice::pastry::standard::ConsistentJoinProtocol_CJPDeserializer::deserialize(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, int16_t type, int32_t priority, ::rice::p2p::commonapi::NodeHandle* sender)
{
    return super::deserialize(buf, type, priority, sender);
}

java::lang::Class* rice::pastry::standard::ConsistentJoinProtocol_CJPDeserializer::getClass0()
{
    return class_();
}

