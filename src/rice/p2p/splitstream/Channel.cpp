// Generated from /pastry-2.1/src/rice/p2p/splitstream/Channel.java
#include <rice/p2p/splitstream/Channel.hpp>

#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/Math.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>
#include <java/math/BigInteger.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/commonapi/IdFactory.hpp>
#include <rice/p2p/scribe/ScribeClient.hpp>
#include <rice/p2p/splitstream/ChannelId.hpp>
#include <rice/p2p/splitstream/SplitStreamScribePolicy.hpp>
#include <rice/p2p/splitstream/Stripe.hpp>
#include <rice/p2p/splitstream/StripeId.hpp>
#include <Array.hpp>
#include <ObjectArray.hpp>
#include <SubArray.hpp>

template<typename ComponentType, typename... Bases> struct SubArray;
namespace rice
{
    namespace p2p
    {
        namespace scribe
        {
typedef ::SubArray< ::rice::p2p::scribe::ScribeClient, ::java::lang::ObjectArray > ScribeClientArray;
        } // scribe

        namespace splitstream
        {
typedef ::SubArray< ::rice::p2p::splitstream::Stripe, ::java::lang::ObjectArray, ::rice::p2p::scribe::ScribeClientArray > StripeArray;
typedef ::SubArray< ::rice::p2p::splitstream::StripeId, ::java::lang::ObjectArray > StripeIdArray;
        } // splitstream
    } // p2p
} // rice

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::splitstream::Channel::Channel(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::splitstream::Channel::Channel(ChannelId* channelId, ::rice::p2p::scribe::Scribe* scribe, ::java::lang::String* instance, ::rice::p2p::commonapi::IdFactory* factory, ::rice::p2p::commonapi::Id* localId, int32_t stripeBase, int32_t maxFailedSubscriptions) 
    : Channel(*static_cast< ::default_init_tag* >(0))
{
    ctor(channelId,scribe,instance,factory,localId,stripeBase,maxFailedSubscriptions);
}

void rice::p2p::splitstream::Channel::ctor(ChannelId* channelId, ::rice::p2p::scribe::Scribe* scribe, ::java::lang::String* instance, ::rice::p2p::commonapi::IdFactory* factory, ::rice::p2p::commonapi::Id* localId, int32_t stripeBase, int32_t maxFailedSubscriptions)
{
    super::ctor();
    this->stripeBase = stripeBase;
    this->channelId = channelId;
    this->localId = localId;
    auto stripeIds = generateStripeIds(channelId, factory);
    stripes = new StripeArray(npc(stripeIds)->length);
    for (auto i = int32_t(0); i < npc(stripeIds)->length; i++) {
        stripes->set(i, new Stripe((*stripeIds)[i], scribe, instance, this, maxFailedSubscriptions));
    }
}

rice::p2p::commonapi::Id* rice::p2p::splitstream::Channel::getLocalId()
{
    return localId;
}

rice::p2p::splitstream::ChannelId* rice::p2p::splitstream::Channel::getChannelId()
{
    return channelId;
}

rice::p2p::splitstream::StripeArray* rice::p2p::splitstream::Channel::getStripes()
{
    return stripes;
}

rice::p2p::splitstream::Stripe* rice::p2p::splitstream::Channel::getPrimaryStripe()
{
    for (auto i = int32_t(0); i < npc(stripes)->length; i++) {
        if(SplitStreamScribePolicy::getPrefixMatch(this->localId, npc(npc((*stripes)[i])->getStripeId())->getId(), stripeBase) > 0)
            return (*stripes)[i];

    }
    return nullptr;
}

int32_t rice::p2p::splitstream::Channel::getStripeBase()
{
    return stripeBase;
}

rice::p2p::splitstream::StripeIdArray* rice::p2p::splitstream::Channel::generateStripeIds(ChannelId* id, ::rice::p2p::commonapi::IdFactory* factory)
{
    auto num = static_cast< int32_t >(::java::lang::Math::pow(2, stripeBase));
    auto stripeIds = new StripeIdArray(num);
    for (auto i = int32_t(0); i < num; i++) {
        auto array = npc(npc(id)->getId())->toByteArray_();
        stripeIds->set(i, new StripeId(npc(factory)->buildId(process(array, stripeBase, i))));
    }
    return stripeIds;
}

int8_tArray* rice::p2p::splitstream::Channel::process(::int8_tArray* array, int32_t base, int32_t num)
{
    clinit();
    auto length = npc(array)->length * int32_t(8);
    auto bNum = new ::java::math::BigInteger(::java::lang::StringBuilder().append(num)->append(u""_j)->toString());
    bNum = npc(bNum)->shiftLeft(length - base);
    auto bArray_ = new ::java::math::BigInteger(int32_t(1), switchEndian(array));
    for (auto i = length - int32_t(1); i > length - base - int32_t(1); i--) {
        if(npc(bNum)->testBit(i)) {
            bArray_ = npc(bArray_)->setBit(i);
        } else {
            bArray_ = npc(bArray_)->clearBit(i);
        }
    }
    auto newArray_ = npc(bArray_)->toByteArray_();
    auto result = new ::int8_tArray(npc(array)->length);
    if(npc(newArray_)->length <= npc(array)->length) {
        ::java::lang::System::arraycopy(newArray_, 0, result, npc(result)->length - npc(newArray_)->length, npc(newArray_)->length);
    } else {
        ::java::lang::System::arraycopy(newArray_, npc(newArray_)->length - npc(array)->length, result, 0, npc(array)->length);
    }
    return switchEndian(result);
}

int8_tArray* rice::p2p::splitstream::Channel::switchEndian(::int8_tArray* array)
{
    clinit();
    auto result = new ::int8_tArray(npc(array)->length);
    for (auto i = int32_t(0); i < npc(result)->length; i++) {
        (*result)[i] = (*array)[npc(result)->length - int32_t(1) - i];
    }
    return result;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::splitstream::Channel::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.splitstream.Channel", 28);
    return c;
}

java::lang::Class* rice::p2p::splitstream::Channel::getClass0()
{
    return class_();
}

