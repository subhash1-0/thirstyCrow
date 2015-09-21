// Generated from /pastry-2.1/src/rice/p2p/past/PastImpl.java
#include <rice/p2p/past/PastImpl_PastDeserializer.hpp>

#include <java/io/IOException.hpp>
#include <java/lang/IllegalArgumentException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/p2p/commonapi/Endpoint.hpp>
#include <rice/p2p/past/PastImpl.hpp>
#include <rice/p2p/past/messaging/CacheMessage.hpp>
#include <rice/p2p/past/messaging/FetchHandleMessage.hpp>
#include <rice/p2p/past/messaging/FetchMessage.hpp>
#include <rice/p2p/past/messaging/InsertMessage.hpp>
#include <rice/p2p/past/messaging/LookupHandlesMessage.hpp>
#include <rice/p2p/past/messaging/LookupMessage.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::past::PastImpl_PastDeserializer::PastImpl_PastDeserializer(PastImpl *PastImpl_this, const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
    , PastImpl_this(PastImpl_this)
{
    clinit();
}

rice::p2p::past::PastImpl_PastDeserializer::PastImpl_PastDeserializer(PastImpl *PastImpl_this)
    : PastImpl_PastDeserializer(PastImpl_this, *static_cast< ::default_init_tag* >(0))
{
    ctor();
}

rice::p2p::commonapi::Message* rice::p2p::past::PastImpl_PastDeserializer::deserialize(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, int16_t type, int32_t priority, ::rice::p2p::commonapi::NodeHandle* sender) /* throws(IOException) */
{
    try {
        switch (type) {
        case ::rice::p2p::past::messaging::CacheMessage::TYPE:
            return ::rice::p2p::past::messaging::CacheMessage::build(buf, PastImpl_this->endpoint, PastImpl_this->contentDeserializer);
        case ::rice::p2p::past::messaging::FetchHandleMessage::TYPE:
            return ::rice::p2p::past::messaging::FetchHandleMessage::build(buf, PastImpl_this->endpoint, PastImpl_this->contentHandleDeserializer);
        case ::rice::p2p::past::messaging::FetchMessage::TYPE:
            return ::rice::p2p::past::messaging::FetchMessage::build(buf, PastImpl_this->endpoint, PastImpl_this->contentDeserializer, PastImpl_this->contentHandleDeserializer);
        case ::rice::p2p::past::messaging::InsertMessage::TYPE:
            return ::rice::p2p::past::messaging::InsertMessage::build(buf, PastImpl_this->endpoint, PastImpl_this->contentDeserializer);
        case ::rice::p2p::past::messaging::LookupHandlesMessage::TYPE:
            return ::rice::p2p::past::messaging::LookupHandlesMessage::build(buf, PastImpl_this->endpoint);
        case ::rice::p2p::past::messaging::LookupMessage::TYPE:
            return ::rice::p2p::past::messaging::LookupMessage::build(buf, PastImpl_this->endpoint, PastImpl_this->contentDeserializer);
        }

    } catch (::java::io::IOException* e) {
        if(npc(PastImpl_this->logger)->level <= ::rice::environment::logging::Logger::SEVERE)
            npc(PastImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Exception in deserializer in "_j)->append(npc(PastImpl_this->endpoint)->toString())
                ->append(u":"_j)
                ->append(PastImpl_this->instance)
                ->append(u" "_j)
                ->append(static_cast< ::java::lang::Object* >(e))->toString());

        throw e;
    }
    throw new ::java::lang::IllegalArgumentException(::java::lang::StringBuilder().append(u"Unknown type:"_j)->append(type)
        ->append(u" in "_j)
        ->append(PastImpl_this->toString())->toString());
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::past::PastImpl_PastDeserializer::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.past.PastImpl.PastDeserializer", 39);
    return c;
}

java::lang::Class* rice::p2p::past::PastImpl_PastDeserializer::getClass0()
{
    return class_();
}

