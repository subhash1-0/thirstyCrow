// Generated from /pastry-2.1/src/rice/p2p/util/MRHAdapter.java
#include <rice/p2p/util/MRHAdapter.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/util/Map.hpp>
#include <org/mpisws/p2p/transport/MessageRequestHandle.hpp>
#include <rice/p2p/commonapi/Message.hpp>
#include <rice/p2p/commonapi/NodeHandle.hpp>
#include <rice/p2p/commonapi/rawserialization/RawMessage.hpp>
#include <rice/p2p/util/rawserialization/JavaSerializedMessage.hpp>

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

rice::p2p::util::MRHAdapter::MRHAdapter(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::util::MRHAdapter::MRHAdapter()
    : MRHAdapter(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

void rice::p2p::util::MRHAdapter::setInternal(::org::mpisws::p2p::transport::MessageRequestHandle* name)
{
    this->internal = name;
}

rice::p2p::commonapi::NodeHandle* rice::p2p::util::MRHAdapter::getIdentifier()
{
    return java_cast< ::rice::p2p::commonapi::NodeHandle* >(npc(internal)->getIdentifier());
}

rice::p2p::commonapi::Message* rice::p2p::util::MRHAdapter::getMessage()
{
    auto rawMessage = java_cast< ::rice::p2p::commonapi::rawserialization::RawMessage* >(npc(internal)->getMessage());
    if(npc(rawMessage)->getType() == 0) {
        return npc((java_cast< ::rice::p2p::util::rawserialization::JavaSerializedMessage* >(rawMessage)))->getMessage();
    }
    return rawMessage;
}

java::util::Map* rice::p2p::util::MRHAdapter::getOptions()
{
    return npc(internal)->getOptions();
}

bool rice::p2p::util::MRHAdapter::cancel()
{
    return npc(internal)->cancel();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::util::MRHAdapter::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.util.MRHAdapter", 24);
    return c;
}

java::lang::Class* rice::p2p::util::MRHAdapter::getClass0()
{
    return class_();
}

