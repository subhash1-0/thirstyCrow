// Generated from /pastry-2.1/src/rice/p2p/past/gc/GCPastImpl.java
#include <rice/p2p/past/gc/GCPastImpl_GCPastDeserializer.hpp>

#include <java/io/IOException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/p2p/commonapi/Endpoint.hpp>
#include <rice/p2p/commonapi/Message.hpp>
#include <rice/p2p/past/gc/GCPastImpl.hpp>
#include <rice/p2p/past/gc/messaging/GCInsertMessage.hpp>
#include <rice/p2p/past/gc/messaging/GCLookupHandlesMessage.hpp>
#include <rice/p2p/past/gc/messaging/GCRefreshMessage.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::past::gc::GCPastImpl_GCPastDeserializer::GCPastImpl_GCPastDeserializer(GCPastImpl *GCPastImpl_this, const ::default_init_tag&)
    : super(GCPastImpl_this, *static_cast< ::default_init_tag* >(0))
    , GCPastImpl_this(GCPastImpl_this)
{
    clinit();
}

rice::p2p::past::gc::GCPastImpl_GCPastDeserializer::GCPastImpl_GCPastDeserializer(GCPastImpl *GCPastImpl_this)
    : GCPastImpl_GCPastDeserializer(GCPastImpl_this, *static_cast< ::default_init_tag* >(0))
{
    ctor();
}

rice::p2p::commonapi::Message* rice::p2p::past::gc::GCPastImpl_GCPastDeserializer::deserialize(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, int16_t type, int32_t priority, ::rice::p2p::commonapi::NodeHandle* sender) /* throws(IOException) */
{
    try {
        switch (type) {
        case ::rice::p2p::past::gc::messaging::GCInsertMessage::TYPE:
            return ::rice::p2p::past::gc::messaging::GCInsertMessage::buildGC(buf, GCPastImpl_this->endpoint, GCPastImpl_this->contentDeserializer);
        case ::rice::p2p::past::gc::messaging::GCLookupHandlesMessage::TYPE:
            return ::rice::p2p::past::gc::messaging::GCLookupHandlesMessage::buildGC(buf, GCPastImpl_this->endpoint);
        case ::rice::p2p::past::gc::messaging::GCRefreshMessage::TYPE:
            return ::rice::p2p::past::gc::messaging::GCRefreshMessage::build(buf, GCPastImpl_this->endpoint);
        }

    } catch (::java::io::IOException* e) {
        if(npc(GCPastImpl_this->logger)->level <= ::rice::environment::logging::Logger::SEVERE)
            npc(GCPastImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Exception in deserializer in "_j)->append(npc(GCPastImpl_this->endpoint)->toString())
                ->append(u":"_j)
                ->append(GCPastImpl_this->instance)
                ->append(u" "_j)
                ->append(static_cast< ::java::lang::Object* >(e))->toString());

        throw e;
    }
    return super::deserialize(buf, type, priority, sender);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::past::gc::GCPastImpl_GCPastDeserializer::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.past.gc.GCPastImpl.GCPastDeserializer", 46);
    return c;
}

java::lang::Class* rice::p2p::past::gc::GCPastImpl_GCPastDeserializer::getClass0()
{
    return class_();
}

