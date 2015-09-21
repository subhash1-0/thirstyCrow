// Generated from /pastry-2.1/src/rice/p2p/splitstream/SplitStreamImpl.java
#include <rice/p2p/splitstream/SplitStreamImpl.hpp>

#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/util/Collection.hpp>
#include <java/util/Hashtable.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/params/Parameters.hpp>
#include <rice/p2p/commonapi/Node.hpp>
#include <rice/p2p/scribe/Scribe.hpp>
#include <rice/p2p/scribe/ScribeImpl.hpp>
#include <rice/p2p/scribe/ScribePolicy.hpp>
#include <rice/p2p/splitstream/Channel.hpp>
#include <rice/p2p/splitstream/ChannelId.hpp>
#include <rice/p2p/splitstream/SplitStreamImpl_SplitStreamImpl_1.hpp>
#include <rice/p2p/splitstream/SplitStreamImpl_SplitStreamImpl_2.hpp>
#include <rice/p2p/splitstream/SplitStreamScribePolicy.hpp>
#include <rice/p2p/splitstream/SplitStreamScribePolicyFactory.hpp>
#include <ObjectArray.hpp>
#include <SubArray.hpp>

template<typename ComponentType, typename... Bases> struct SubArray;
namespace rice
{
    namespace p2p
    {
        namespace splitstream
        {
typedef ::SubArray< ::rice::p2p::splitstream::Channel, ::java::lang::ObjectArray > ChannelArray;
        } // splitstream
    } // p2p
} // rice

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

rice::p2p::splitstream::SplitStreamImpl::SplitStreamImpl(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::splitstream::SplitStreamImpl::SplitStreamImpl(::rice::p2p::commonapi::Node* node, ::java::lang::String* instance) 
    : SplitStreamImpl(*static_cast< ::default_init_tag* >(0))
{
    ctor(node,instance);
}

rice::p2p::splitstream::SplitStreamImpl::SplitStreamImpl(::rice::p2p::commonapi::Node* node, ::java::lang::String* instance, SplitStreamScribePolicyFactory* factory) 
    : SplitStreamImpl(*static_cast< ::default_init_tag* >(0))
{
    ctor(node,instance,factory);
}

void rice::p2p::splitstream::SplitStreamImpl::ctor(::rice::p2p::commonapi::Node* node, ::java::lang::String* instance)
{
    ctor(node, instance, new SplitStreamImpl_SplitStreamImpl_1(this));
}

void rice::p2p::splitstream::SplitStreamImpl::ctor(::rice::p2p::commonapi::Node* node, ::java::lang::String* instance, SplitStreamScribePolicyFactory* factory)
{
    super::ctor();
    this->instance = instance;
    auto environment = npc(node)->getEnvironment();
    auto p = npc(environment)->getParameters();
    defaultMaxChildren = npc(p)->getInt(u"p2p_splitStream_policy_default_maximum_children"_j);
    maxFailedSubscriptions = npc(p)->getInt(u"p2p_splitStream_stripe_max_failed_subscription"_j);
    stripeBaseBitLength = npc(p)->getInt(u"p2p_splitStream_stripeBaseBitLength"_j);
    this->scribe = new ::rice::p2p::scribe::ScribeImpl(node, instance);
    npc(scribe)->setContentDeserializer(new SplitStreamImpl_SplitStreamImpl_2(this));
    this->node = node;
    this->channels = new ::java::util::Hashtable();
    npc(scribe)->setPolicy(npc(factory)->getSplitStreamScribePolicy(scribe, this));
}

rice::p2p::splitstream::Channel* rice::p2p::splitstream::SplitStreamImpl::createChannel(ChannelId* id)
{
    return attachChannel(id);
}

rice::p2p::splitstream::Channel* rice::p2p::splitstream::SplitStreamImpl::attachChannel(ChannelId* id)
{
    auto channel = java_cast< Channel* >(java_cast< Channel* >(npc(channels)->get(static_cast< ::java::lang::Object* >(id))));
    if(channel == nullptr) {
        channel = new Channel(id, scribe, instance, npc(node)->getIdFactory(), npc(this->node)->getId(), stripeBaseBitLength, maxFailedSubscriptions);
        npc(channels)->put(static_cast< ::java::lang::Object* >(id), static_cast< ::java::lang::Object* >(channel));
    }
    npc((java_cast< SplitStreamScribePolicy* >(npc(scribe)->getPolicy())))->setMaxChildren(id, defaultMaxChildren);
    return channel;
}

rice::p2p::splitstream::ChannelArray* rice::p2p::splitstream::SplitStreamImpl::getChannels()
{
    return java_cast< ChannelArray* >(java_cast< ChannelArray* >(npc(npc(channels)->values())->toArray_(new ChannelArray(int32_t(0)))));
}

rice::p2p::splitstream::SplitStreamScribePolicy* rice::p2p::splitstream::SplitStreamImpl::getPolicy()
{
    return java_cast< SplitStreamScribePolicy* >((npc(scribe)->getPolicy()));
}

int32_t rice::p2p::splitstream::SplitStreamImpl::getStripeBaseBitLength()
{
    return stripeBaseBitLength;
}

rice::environment::Environment* rice::p2p::splitstream::SplitStreamImpl::getEnvironment()
{
    return npc(scribe)->getEnvironment();
}

void rice::p2p::splitstream::SplitStreamImpl::destroy()
{
    npc(scribe)->destroy();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::splitstream::SplitStreamImpl::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.splitstream.SplitStreamImpl", 36);
    return c;
}

java::lang::Class* rice::p2p::splitstream::SplitStreamImpl::getClass0()
{
    return class_();
}

