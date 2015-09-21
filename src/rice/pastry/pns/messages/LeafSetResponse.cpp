// Generated from /pastry-2.1/src/rice/pastry/pns/messages/LeafSetResponse.java
#include <rice/pastry/pns/messages/LeafSetResponse.hpp>

#include <java/lang/IllegalStateException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/p2p/commonapi/rawserialization/InputBuffer.hpp>
#include <rice/p2p/commonapi/rawserialization/OutputBuffer.hpp>
#include <rice/pastry/leafset/LeafSet.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::pastry::pns::messages::LeafSetResponse::LeafSetResponse(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::pns::messages::LeafSetResponse::LeafSetResponse(::rice::pastry::leafset::LeafSet* leafset, int32_t dest) 
    : LeafSetResponse(*static_cast< ::default_init_tag* >(0))
{
    ctor(leafset,dest);
}

constexpr int16_t rice::pastry::pns::messages::LeafSetResponse::TYPE;

void rice::pastry::pns::messages::LeafSetResponse::ctor(::rice::pastry::leafset::LeafSet* leafset, int32_t dest)
{
    super::ctor(dest);
    this->leafset = leafset;
    setPriority(HIGH_PRIORITY);
}

int16_t rice::pastry::pns::messages::LeafSetResponse::getType()
{
    return TYPE;
}

void rice::pastry::pns::messages::LeafSetResponse::serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */
{
    npc(buf)->writeByte(static_cast< int8_t >(int32_t(0)));
    npc(leafset)->serialize(buf);
}

rice::p2p::commonapi::Message* rice::pastry::pns::messages::LeafSetResponse::build(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::pastry::NodeHandleFactory* nhf, int32_t dest) /* throws(IOException) */
{
    clinit();
    auto version = npc(buf)->readByte();
    switch (version) {
    case int32_t(0):
        return new LeafSetResponse(::rice::pastry::leafset::LeafSet::build(buf, nhf), dest);
    }

    throw new ::java::lang::IllegalStateException(::java::lang::StringBuilder().append(u"Unknown version:"_j)->append(version)->toString());
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::pns::messages::LeafSetResponse::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.pns.messages.LeafSetResponse", 40);
    return c;
}

java::lang::Class* rice::pastry::pns::messages::LeafSetResponse::getClass0()
{
    return class_();
}

