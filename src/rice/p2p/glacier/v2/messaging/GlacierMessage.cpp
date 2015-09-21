// Generated from /pastry-2.1/src/rice/p2p/glacier/v2/messaging/GlacierMessage.java
#include <rice/p2p/glacier/v2/messaging/GlacierMessage.hpp>

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

rice::p2p::glacier::v2::messaging::GlacierMessage::GlacierMessage(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::glacier::v2::messaging::GlacierMessage::GlacierMessage(int32_t id, ::rice::p2p::commonapi::NodeHandle* source, ::rice::p2p::commonapi::Id* dest, bool isResponse, char16_t tag) 
    : GlacierMessage(*static_cast< ::default_init_tag* >(0))
{
    ctor(id,source,dest,isResponse,tag);
}

rice::p2p::glacier::v2::messaging::GlacierMessage::GlacierMessage(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint)  /* throws(IOException) */
    : GlacierMessage(*static_cast< ::default_init_tag* >(0))
{
    ctor(buf,endpoint);
}

constexpr int64_t rice::p2p::glacier::v2::messaging::GlacierMessage::serialVersionUID;

void rice::p2p::glacier::v2::messaging::GlacierMessage::ctor(int32_t id, ::rice::p2p::commonapi::NodeHandle* source, ::rice::p2p::commonapi::Id* dest, bool isResponse, char16_t tag)
{
    super::ctor();
    this->id = id;
    this->source = source;
    this->dest = dest;
    this->isResponse_ = isResponse;
    this->tag = tag;
}

int32_t rice::p2p::glacier::v2::messaging::GlacierMessage::getPriority()
{
    return LOW_PRIORITY;
}

int32_t rice::p2p::glacier::v2::messaging::GlacierMessage::getUID()
{
    return id;
}

rice::p2p::commonapi::NodeHandle* rice::p2p::glacier::v2::messaging::GlacierMessage::getSource()
{
    return source;
}

rice::p2p::commonapi::Id* rice::p2p::glacier::v2::messaging::GlacierMessage::getDestination()
{
    return dest;
}

bool rice::p2p::glacier::v2::messaging::GlacierMessage::isResponse()
{
    return isResponse_;
}

char16_t rice::p2p::glacier::v2::messaging::GlacierMessage::getTag()
{
    return tag;
}

void rice::p2p::glacier::v2::messaging::GlacierMessage::serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */
{
    npc(buf)->writeInt(id);
    npc(buf)->writeChar(tag);
    npc(buf)->writeBoolean(isResponse_);
    npc(buf)->writeShort(npc(dest)->getType());
    npc(dest)->serialize(buf);
    npc(source)->serialize(buf);
}

void rice::p2p::glacier::v2::messaging::GlacierMessage::ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint) /* throws(IOException) */
{
    super::ctor();
    id = npc(buf)->readInt();
    tag = npc(buf)->readChar();
    isResponse_ = npc(buf)->readBoolean();
    dest = npc(endpoint)->readId(buf, npc(buf)->readShort());
    source = npc(endpoint)->readNodeHandle(buf);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::glacier::v2::messaging::GlacierMessage::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.glacier.v2.messaging.GlacierMessage", 44);
    return c;
}

java::lang::Class* rice::p2p::glacier::v2::messaging::GlacierMessage::getClass0()
{
    return class_();
}

