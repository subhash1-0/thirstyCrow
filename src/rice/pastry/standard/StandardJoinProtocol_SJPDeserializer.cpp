// Generated from /pastry-2.1/src/rice/pastry/standard/StandardJoinProtocol.java
#include <rice/pastry/standard/StandardJoinProtocol_SJPDeserializer.hpp>

#include <java/lang/ClassCastException.hpp>
#include <rice/p2p/commonapi/Message.hpp>
#include <rice/pastry/NodeHandle.hpp>
#include <rice/pastry/PastryNode.hpp>
#include <rice/pastry/join/JoinRequest.hpp>

template<typename T, typename U>
static T java_cast(U* u)
{
    if(!u) return static_cast<T>(nullptr);
    auto t = dynamic_cast<T>(u);
    if(!t) throw new ::java::lang::ClassCastException();
    return t;
}

rice::pastry::standard::StandardJoinProtocol_SJPDeserializer::StandardJoinProtocol_SJPDeserializer(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::standard::StandardJoinProtocol_SJPDeserializer::StandardJoinProtocol_SJPDeserializer(::rice::pastry::PastryNode* pn) 
    : StandardJoinProtocol_SJPDeserializer(*static_cast< ::default_init_tag* >(0))
{
    ctor(pn);
}

void rice::pastry::standard::StandardJoinProtocol_SJPDeserializer::ctor(::rice::pastry::PastryNode* pn)
{
    super::ctor(pn);
}

rice::pastry::messaging::Message* rice::pastry::standard::StandardJoinProtocol_SJPDeserializer::deserialize(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, int16_t type, int32_t priority, ::rice::pastry::NodeHandle* sender) /* throws(IOException) */
{
    switch (type) {
    case ::rice::pastry::join::JoinRequest::TYPE:
        return new ::rice::pastry::join::JoinRequest(buf, pn, java_cast< ::rice::pastry::NodeHandle* >(sender), pn);
    }

    return nullptr;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::standard::StandardJoinProtocol_SJPDeserializer::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.standard.StandardJoinProtocol.SJPDeserializer", 57);
    return c;
}

rice::p2p::commonapi::Message* rice::pastry::standard::StandardJoinProtocol_SJPDeserializer::deserialize(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, int16_t type, int32_t priority, ::rice::p2p::commonapi::NodeHandle* sender)
{
    return super::deserialize(buf, type, priority, sender);
}

java::lang::Class* rice::pastry::standard::StandardJoinProtocol_SJPDeserializer::getClass0()
{
    return class_();
}

