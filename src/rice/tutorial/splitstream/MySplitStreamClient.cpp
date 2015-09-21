// Generated from /pastry-2.1/src/rice/tutorial/splitstream/MySplitStreamClient.java
#include <rice/tutorial/splitstream/MySplitStreamClient.hpp>

#include <java/io/PrintStream.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/RuntimeException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuffer.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/random/RandomSource.hpp>
#include <rice/p2p/commonapi/CancellableTask.hpp>
#include <rice/p2p/commonapi/Endpoint.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/commonapi/Message.hpp>
#include <rice/p2p/commonapi/Node.hpp>
#include <rice/p2p/commonapi/NodeHandle.hpp>
#include <rice/p2p/scribe/ScribeClient.hpp>
#include <rice/p2p/splitstream/Channel.hpp>
#include <rice/p2p/splitstream/ChannelId.hpp>
#include <rice/p2p/splitstream/SplitStream.hpp>
#include <rice/p2p/splitstream/SplitStreamImpl.hpp>
#include <rice/p2p/splitstream/Stripe.hpp>
#include <rice/pastry/commonapi/PastryIdFactory.hpp>
#include <rice/tutorial/splitstream/MySplitStreamClient_PublishContent.hpp>
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
        } // splitstream
    } // p2p
} // rice

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::tutorial::splitstream::MySplitStreamClient::MySplitStreamClient(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::tutorial::splitstream::MySplitStreamClient::MySplitStreamClient(::rice::p2p::commonapi::Node* node) 
    : MySplitStreamClient(*static_cast< ::default_init_tag* >(0))
{
    ctor(node);
}

void rice::tutorial::splitstream::MySplitStreamClient::init()
{
    seqNum = int32_t(0);
}

constexpr int32_t rice::tutorial::splitstream::MySplitStreamClient::DATA_LENGTH;

constexpr int32_t rice::tutorial::splitstream::MySplitStreamClient::NUM_PUBLISHES;

void rice::tutorial::splitstream::MySplitStreamClient::ctor(::rice::p2p::commonapi::Node* node)
{
    super::ctor();
    init();
    this->endpoint = npc(node)->buildEndpoint(this, u"myinstance"_j);
    this->random = npc(npc(endpoint)->getEnvironment())->getRandomSource();
    mySplitStream = new ::rice::p2p::splitstream::SplitStreamImpl(node, u"splitStreamTutorial"_j);
    auto temp = (new ::rice::pastry::commonapi::PastryIdFactory(npc(node)->getEnvironment()))->buildId(u"my channel"_j);
    myChannelId = new ::rice::p2p::splitstream::ChannelId(temp);
    npc(endpoint)->register_();
}

void rice::tutorial::splitstream::MySplitStreamClient::subscribe()
{
    myChannel = npc(mySplitStream)->attachChannel(myChannelId);
    myStripes = npc(myChannel)->getStripes();
    for (auto curStripe = int32_t(0); curStripe < npc(myStripes)->length; curStripe++) {
        npc((*myStripes)[curStripe])->subscribe(this);
    }
}

void rice::tutorial::splitstream::MySplitStreamClient::startPublishTask()
{
    publishTask = npc(endpoint)->scheduleMessage(new MySplitStreamClient_PublishContent(this), 5000, 5000);
}

void rice::tutorial::splitstream::MySplitStreamClient::deliver(::rice::p2p::commonapi::Id* id, ::rice::p2p::commonapi::Message* message)
{
    if(dynamic_cast< MySplitStreamClient_PublishContent* >(message) != nullptr) {
        publish();
    }
}

void rice::tutorial::splitstream::MySplitStreamClient::publish()
{
    for (int8_t curStripe = int32_t(0); curStripe < npc(myStripes)->length; curStripe++) {
        auto data = new ::int8_tArray(DATA_LENGTH);
        npc(random)->nextBytes(data);
        (*data)[int32_t(0)] = seqNum;
        (*data)[int32_t(1)] = curStripe;
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"Node "_j)->append(static_cast< ::java::lang::Object* >(npc(endpoint)->getLocalNodeHandle()))
            ->append(u" publishing "_j)
            ->append(seqNum)
            ->append(u" "_j)
            ->append(printData(data))->toString());
        npc((*myStripes)[curStripe])->publish(data);
    }
    seqNum++;
    if(seqNum >= NUM_PUBLISHES)
        npc(publishTask)->cancel();

}

java::lang::String* rice::tutorial::splitstream::MySplitStreamClient::printData(::int8_tArray* data)
{
    auto sb = new ::java::lang::StringBuffer();
    for (auto i = int32_t(0); i < npc(data)->length - int32_t(1); i++) {
        npc(sb)->append(static_cast< int32_t >((*data)[i]));
        npc(sb)->append(u',');
    }
    npc(sb)->append(static_cast< int32_t >((*data)[npc(data)->length - int32_t(1)]));
    return npc(sb)->toString();
}

void rice::tutorial::splitstream::MySplitStreamClient::deliver(::rice::p2p::splitstream::Stripe* s, ::int8_tArray* data)
{
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(npc(endpoint)->getId()))->append(u" deliver("_j)
        ->append(static_cast< ::java::lang::Object* >(s))
        ->append(u"):seq:"_j)
        ->append((*data)[int32_t(0)])
        ->append(u" stripe:"_j)
        ->append((*data)[int32_t(1)])
        ->append(u" "_j)
        ->append(printData(data))
        ->append(u")"_j)->toString());
}

void rice::tutorial::splitstream::MySplitStreamClient::joinFailed(::rice::p2p::splitstream::Stripe* s)
{
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"joinFailed("_j)->append(static_cast< ::java::lang::Object* >(s))
        ->append(u")"_j)->toString());
}

bool rice::tutorial::splitstream::MySplitStreamClient::forward(::rice::p2p::commonapi::RouteMessage* message)
{
    throw new ::java::lang::RuntimeException(u"Cant happen."_j);
}

void rice::tutorial::splitstream::MySplitStreamClient::update(::rice::p2p::commonapi::NodeHandle* handle, bool joined)
{
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::tutorial::splitstream::MySplitStreamClient::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.tutorial.splitstream.MySplitStreamClient", 45);
    return c;
}

java::lang::Class* rice::tutorial::splitstream::MySplitStreamClient::getClass0()
{
    return class_();
}

