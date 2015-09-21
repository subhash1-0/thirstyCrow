// Generated from /pastry-2.1/src/rice/pastry/messaging/PJavaSerializedDeserializer.java
#include <rice/pastry/messaging/PJavaSerializedDeserializer.hpp>

#include <java/lang/ClassCastException.hpp>
#include <rice/p2p/commonapi/Message.hpp>
#include <rice/p2p/commonapi/NodeHandle.hpp>
#include <rice/pastry/NodeHandle.hpp>
#include <rice/pastry/messaging/Message.hpp>

template<typename T, typename U>
static T java_cast(U* u)
{
    if(!u) return static_cast<T>(nullptr);
    auto t = dynamic_cast<T>(u);
    if(!t) throw new ::java::lang::ClassCastException();
    return t;
}

rice::pastry::messaging::PJavaSerializedDeserializer::PJavaSerializedDeserializer(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::messaging::PJavaSerializedDeserializer::PJavaSerializedDeserializer(::rice::pastry::PastryNode* pn) 
    : PJavaSerializedDeserializer(*static_cast< ::default_init_tag* >(0))
{
    ctor(pn);
}

void rice::pastry::messaging::PJavaSerializedDeserializer::ctor(::rice::pastry::PastryNode* pn)
{
    super::ctor(pn);
}

rice::p2p::commonapi::Message* rice::pastry::messaging::PJavaSerializedDeserializer::deserialize(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, int16_t type, int32_t priority, ::rice::p2p::commonapi::NodeHandle* sender) /* throws(IOException) */
{
    ::rice::p2p::commonapi::Message* ret = deserialize(buf, type, priority, java_cast< ::rice::pastry::NodeHandle* >(sender));
    if(ret == nullptr)
        return super::deserialize(buf, type, priority, sender);

    return ret;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::messaging::PJavaSerializedDeserializer::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.messaging.PJavaSerializedDeserializer", 49);
    return c;
}

java::lang::Class* rice::pastry::messaging::PJavaSerializedDeserializer::getClass0()
{
    return class_();
}

