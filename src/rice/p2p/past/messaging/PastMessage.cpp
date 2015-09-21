// Generated from /pastry-2.1/src/rice/p2p/past/messaging/PastMessage.java
#include <rice/p2p/past/messaging/PastMessage.hpp>

#include <java/lang/NullPointerException.hpp>
#include <rice/p2p/commonapi/Endpoint.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/commonapi/NodeHandle.hpp>
#include <rice/p2p/commonapi/rawserialization/InputBuffer.hpp>
#include <rice/p2p/commonapi/rawserialization/OutputBuffer.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::past::messaging::PastMessage::PastMessage(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::past::messaging::PastMessage::PastMessage(int32_t id, ::rice::p2p::commonapi::NodeHandle* source, ::rice::p2p::commonapi::Id* dest) 
    : PastMessage(*static_cast< ::default_init_tag* >(0))
{
    ctor(id,source,dest);
}

rice::p2p::past::messaging::PastMessage::PastMessage(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint)  /* throws(IOException) */
    : PastMessage(*static_cast< ::default_init_tag* >(0))
{
    ctor(buf,endpoint);
}

constexpr int64_t rice::p2p::past::messaging::PastMessage::serialVersionUID;

void rice::p2p::past::messaging::PastMessage::ctor(int32_t id, ::rice::p2p::commonapi::NodeHandle* source, ::rice::p2p::commonapi::Id* dest)
{
    super::ctor();
    this->id = id;
    this->source = source;
    this->dest = dest;
    isResponse_ = false;
}

int32_t rice::p2p::past::messaging::PastMessage::getPriority()
{
    return MEDIUM_HIGH_PRIORITY;
}

int32_t rice::p2p::past::messaging::PastMessage::getUID()
{
    return id;
}

rice::p2p::commonapi::NodeHandle* rice::p2p::past::messaging::PastMessage::getSource()
{
    return source;
}

rice::p2p::commonapi::Id* rice::p2p::past::messaging::PastMessage::getDestination()
{
    return dest;
}

void rice::p2p::past::messaging::PastMessage::setResponse()
{
    isResponse_ = true;
}

bool rice::p2p::past::messaging::PastMessage::isResponse()
{
    return isResponse_;
}

void rice::p2p::past::messaging::PastMessage::addHop(::rice::p2p::commonapi::NodeHandle* handle)
{
}

void rice::p2p::past::messaging::PastMessage::ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint) /* throws(IOException) */
{
    super::ctor();
    id = npc(buf)->readInt();
    dest = npc(endpoint)->readId(buf, npc(buf)->readShort());
    source = npc(endpoint)->readNodeHandle(buf);
    isResponse_ = npc(buf)->readBoolean();
}

void rice::p2p::past::messaging::PastMessage::serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */
{
    npc(buf)->writeInt(id);
    npc(buf)->writeShort(npc(dest)->getType());
    npc(dest)->serialize(buf);
    npc(source)->serialize(buf);
    npc(buf)->writeBoolean(isResponse_);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::past::messaging::PastMessage::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.past.messaging.PastMessage", 35);
    return c;
}

java::lang::Class* rice::p2p::past::messaging::PastMessage::getClass0()
{
    return class_();
}

