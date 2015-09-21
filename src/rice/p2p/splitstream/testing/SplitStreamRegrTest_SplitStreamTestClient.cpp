// Generated from /pastry-2.1/src/rice/p2p/splitstream/testing/SplitStreamRegrTest.java
#include <rice/p2p/splitstream/testing/SplitStreamRegrTest_SplitStreamTestClient.hpp>

#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/commonapi/Node.hpp>
#include <rice/p2p/scribe/ScribeClient.hpp>
#include <rice/p2p/splitstream/Channel.hpp>
#include <rice/p2p/splitstream/ChannelId.hpp>
#include <rice/p2p/splitstream/SplitStream.hpp>
#include <rice/p2p/splitstream/Stripe.hpp>
#include <rice/p2p/splitstream/testing/SplitStreamRegrTest.hpp>
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
        } // splitstream
    } // p2p
} // rice

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::splitstream::testing::SplitStreamRegrTest_SplitStreamTestClient::SplitStreamRegrTest_SplitStreamTestClient(SplitStreamRegrTest *SplitStreamRegrTest_this, const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
    , SplitStreamRegrTest_this(SplitStreamRegrTest_this)
{
    clinit();
}

rice::p2p::splitstream::testing::SplitStreamRegrTest_SplitStreamTestClient::SplitStreamRegrTest_SplitStreamTestClient(SplitStreamRegrTest *SplitStreamRegrTest_this, ::rice::p2p::commonapi::Node* n, ::rice::p2p::splitstream::SplitStream* ss) 
    : SplitStreamRegrTest_SplitStreamTestClient(SplitStreamRegrTest_this, *static_cast< ::default_init_tag* >(0))
{
    ctor(n,ss);
}

void rice::p2p::splitstream::testing::SplitStreamRegrTest_SplitStreamTestClient::init()
{
    n = nullptr;
    numMesgsReceived = int32_t(0);
    policy = nullptr;
}

void rice::p2p::splitstream::testing::SplitStreamRegrTest_SplitStreamTestClient::ctor(::rice::p2p::commonapi::Node* n, ::rice::p2p::splitstream::SplitStream* ss)
{
    super::ctor();
    init();
    this->n = n;
    this->ss = ss;
    log(::java::lang::StringBuilder().append(u"Client Created "_j)->append(static_cast< ::java::lang::Object* >(n))->toString());
}

void rice::p2p::splitstream::testing::SplitStreamRegrTest_SplitStreamTestClient::destroy()
{
    npc(ss)->destroy();
}

rice::p2p::splitstream::Channel* rice::p2p::splitstream::testing::SplitStreamRegrTest_SplitStreamTestClient::getChannel()
{
    return this->channel;
}

void rice::p2p::splitstream::testing::SplitStreamRegrTest_SplitStreamTestClient::joinFailed(::rice::p2p::splitstream::Stripe* s)
{
    log(::java::lang::StringBuilder().append(u"Join Failed on "_j)->append(static_cast< ::java::lang::Object* >(s))->toString());
}

void rice::p2p::splitstream::testing::SplitStreamRegrTest_SplitStreamTestClient::deliver(::rice::p2p::splitstream::Stripe* s, ::int8_tArray* data)
{
    log(::java::lang::StringBuilder().append(u"Data recieved on "_j)->append(static_cast< ::java::lang::Object* >(s))->toString());
    numMesgsReceived++;
}

void rice::p2p::splitstream::testing::SplitStreamRegrTest_SplitStreamTestClient::createChannel(::rice::p2p::splitstream::ChannelId* cid)
{
    log(::java::lang::StringBuilder().append(u"Channel "_j)->append(static_cast< ::java::lang::Object* >(cid))
        ->append(u" created."_j)->toString());
    channel = npc(ss)->createChannel(cid);
}

void rice::p2p::splitstream::testing::SplitStreamRegrTest_SplitStreamTestClient::attachChannel(::rice::p2p::splitstream::ChannelId* cid)
{
    log(::java::lang::StringBuilder().append(u"Attaching to Channel "_j)->append(static_cast< ::java::lang::Object* >(cid))
        ->append(u"."_j)->toString());
    if(channel == nullptr)
        channel = npc(ss)->attachChannel(cid);

}

rice::p2p::splitstream::StripeArray* rice::p2p::splitstream::testing::SplitStreamRegrTest_SplitStreamTestClient::getStripes()
{
    log(u"Retrieving Stripes."_j);
    stripes = npc(channel)->getStripes();
    return stripes;
}

void rice::p2p::splitstream::testing::SplitStreamRegrTest_SplitStreamTestClient::subscribeStripes()
{
    log(u"Subscribing to all Stripes."_j);
    for (auto i = int32_t(0); i < npc(stripes)->length; i++) {
        npc((*stripes)[i])->subscribe(this);
    }
}

void rice::p2p::splitstream::testing::SplitStreamRegrTest_SplitStreamTestClient::publishAll(::int8_tArray* b)
{
    log(u"Publishing to all Stripes."_j);
    for (auto i = int32_t(0); i < npc(stripes)->length; i++) {
        publish(b, (*stripes)[i]);
    }
}

void rice::p2p::splitstream::testing::SplitStreamRegrTest_SplitStreamTestClient::publish(::int8_tArray* b, ::rice::p2p::splitstream::Stripe* s)
{
    log(::java::lang::StringBuilder().append(u"Publishing to "_j)->append(static_cast< ::java::lang::Object* >(s))->toString());
    npc(s)->publish(b);
}

int32_t rice::p2p::splitstream::testing::SplitStreamRegrTest_SplitStreamTestClient::getNumMesgs()
{
    return numMesgsReceived;
}

void rice::p2p::splitstream::testing::SplitStreamRegrTest_SplitStreamTestClient::reset()
{
    numMesgsReceived = 0;
}

rice::p2p::commonapi::Id* rice::p2p::splitstream::testing::SplitStreamRegrTest_SplitStreamTestClient::getId()
{
    return npc(channel)->getLocalId();
}

void rice::p2p::splitstream::testing::SplitStreamRegrTest_SplitStreamTestClient::log(::java::lang::String* s)
{
    if(npc(SplitStreamRegrTest_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(SplitStreamRegrTest_this->logger)->log(::java::lang::StringBuilder().append(u""_j)->append(static_cast< ::java::lang::Object* >(n))
            ->append(u" "_j)
            ->append(s)->toString());

}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::splitstream::testing::SplitStreamRegrTest_SplitStreamTestClient::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.splitstream.testing.SplitStreamRegrTest.SplitStreamTestClient", 70);
    return c;
}

java::lang::Class* rice::p2p::splitstream::testing::SplitStreamRegrTest_SplitStreamTestClient::getClass0()
{
    return class_();
}

