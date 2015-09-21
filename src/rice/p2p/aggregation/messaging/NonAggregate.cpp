// Generated from /pastry-2.1/src/rice/p2p/aggregation/messaging/NonAggregate.java
#include <rice/p2p/aggregation/messaging/NonAggregate.hpp>

#include <java/io/IOException.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/commonapi/rawserialization/InputBuffer.hpp>
#include <rice/p2p/commonapi/rawserialization/OutputBuffer.hpp>
#include <rice/p2p/past/PastContent.hpp>
#include <rice/p2p/past/PastContentHandle.hpp>
#include <rice/p2p/past/rawserialization/JavaSerializedPastContent.hpp>
#include <rice/p2p/past/rawserialization/PastContentDeserializer.hpp>
#include <rice/p2p/past/rawserialization/RawPastContent.hpp>

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

rice::p2p::aggregation::messaging::NonAggregate::NonAggregate(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::aggregation::messaging::NonAggregate::NonAggregate(::rice::p2p::past::PastContent* content) 
    : NonAggregate(*static_cast< ::default_init_tag* >(0))
{
    ctor(content);
}

rice::p2p::aggregation::messaging::NonAggregate::NonAggregate(::rice::p2p::past::rawserialization::RawPastContent* subContent) 
    : NonAggregate(*static_cast< ::default_init_tag* >(0))
{
    ctor(subContent);
}

rice::p2p::aggregation::messaging::NonAggregate::NonAggregate(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint, ::rice::p2p::past::rawserialization::RawPastContent* subContent, ::rice::p2p::past::rawserialization::PastContentDeserializer* pcd)  /* throws(IOException) */
    : NonAggregate(*static_cast< ::default_init_tag* >(0))
{
    ctor(buf,endpoint,subContent,pcd);
}

constexpr int16_t rice::p2p::aggregation::messaging::NonAggregate::TYPE;

void rice::p2p::aggregation::messaging::NonAggregate::ctor(::rice::p2p::past::PastContent* content)
{
    ctor(dynamic_cast< ::rice::p2p::past::rawserialization::RawPastContent* >(content) != nullptr ? java_cast< ::rice::p2p::past::rawserialization::RawPastContent* >(content) : static_cast< ::rice::p2p::past::rawserialization::RawPastContent* >(new ::rice::p2p::past::rawserialization::JavaSerializedPastContent(content)));
}

void rice::p2p::aggregation::messaging::NonAggregate::ctor(::rice::p2p::past::rawserialization::RawPastContent* subContent)
{
    super::ctor();
    this->content = subContent;
}

rice::p2p::past::PastContent* rice::p2p::aggregation::messaging::NonAggregate::checkInsert(::rice::p2p::commonapi::Id* id, ::rice::p2p::past::PastContent* existingContent) /* throws(PastException) */
{
    content = java_cast< ::rice::p2p::past::rawserialization::RawPastContent* >(npc(content)->checkInsert(id, npc((java_cast< NonAggregate* >(existingContent)))->content));
    return this;
}

rice::p2p::past::PastContentHandle* rice::p2p::aggregation::messaging::NonAggregate::getHandle(::rice::p2p::past::Past* local)
{
    return npc(content)->getHandle(local);
}

rice::p2p::commonapi::Id* rice::p2p::aggregation::messaging::NonAggregate::getId()
{
    return npc(content)->getId();
}

bool rice::p2p::aggregation::messaging::NonAggregate::isMutable()
{
    return npc(content)->isMutable();
}

int16_t rice::p2p::aggregation::messaging::NonAggregate::getType()
{
    return TYPE;
}

void rice::p2p::aggregation::messaging::NonAggregate::serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */
{
    npc(buf)->writeByte(static_cast< int8_t >(int32_t(0)));
    npc(buf)->writeShort(npc(content)->getType());
    npc(content)->serialize(buf);
}

void rice::p2p::aggregation::messaging::NonAggregate::ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint, ::rice::p2p::past::rawserialization::RawPastContent* subContent, ::rice::p2p::past::rawserialization::PastContentDeserializer* pcd) /* throws(IOException) */
{
    super::ctor();
    auto version = npc(buf)->readByte();
    {
        int16_t subType;
        ::rice::p2p::past::PastContent* temp;
        switch (version) {
        case int32_t(0):
            subType = npc(buf)->readShort();
            temp = npc(pcd)->deserializePastContent(buf, endpoint, subType);
            if(subType == 0) {
                this->content = new ::rice::p2p::past::rawserialization::JavaSerializedPastContent(temp);
            } else {
                this->content = java_cast< ::rice::p2p::past::rawserialization::RawPastContent* >(temp);
            }
            break;
        default:
            throw new ::java::io::IOException(::java::lang::StringBuilder().append(u"Unknown Version: "_j)->append(version)->toString());
        }
    }

}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::aggregation::messaging::NonAggregate::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.aggregation.messaging.NonAggregate", 43);
    return c;
}

java::lang::Class* rice::p2p::aggregation::messaging::NonAggregate::getClass0()
{
    return class_();
}

