// Generated from /pastry-2.1/src/rice/p2p/splitstream/testing/MySplitStreamClient.java
#include <rice/p2p/splitstream/testing/MySplitStreamClient.hpp>

#include <java/io/PrintStream.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/time/TimeSource.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/commonapi/IdRange.hpp>
#include <rice/p2p/commonapi/NodeHandle.hpp>
#include <rice/p2p/commonapi/RangeCannotBeDeterminedException.hpp>
#include <rice/p2p/scribe/ScribeClient.hpp>
#include <rice/p2p/splitstream/Channel.hpp>
#include <rice/p2p/splitstream/ChannelId.hpp>
#include <rice/p2p/splitstream/SplitStream.hpp>
#include <rice/p2p/splitstream/SplitStreamImpl.hpp>
#include <rice/p2p/splitstream/Stripe.hpp>
#include <rice/p2p/splitstream/StripeId.hpp>
#include <rice/p2p/splitstream/testing/MySplitStreamClient_startPublishTask_1.hpp>
#include <rice/p2p/util/MathUtils.hpp>
#include <rice/pastry/Id.hpp>
#include <rice/pastry/IdRange.hpp>
#include <rice/pastry/PastryNode.hpp>
#include <rice/pastry/leafset/LeafSet.hpp>
#include <rice/selector/SelectorManager.hpp>
#include <rice/selector/Timer.hpp>
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

rice::p2p::splitstream::testing::MySplitStreamClient::MySplitStreamClient(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::splitstream::testing::MySplitStreamClient::MySplitStreamClient(::rice::pastry::PastryNode* n, ::java::lang::String* instance) 
    : MySplitStreamClient(*static_cast< ::default_init_tag* >(0))
{
    ctor(n,instance);
}

void rice::p2p::splitstream::testing::MySplitStreamClient::init()
{
    n = nullptr;
    numMesgsReceived = int32_t(0);
    policy = nullptr;
    curSeq = int32_t(0);
}

int32_t& rice::p2p::splitstream::testing::MySplitStreamClient::SEND_PERIOD()
{
    clinit();
    return SEND_PERIOD_;
}
int32_t rice::p2p::splitstream::testing::MySplitStreamClient::SEND_PERIOD_;

int32_t& rice::p2p::splitstream::testing::MySplitStreamClient::msgSize()
{
    clinit();
    return msgSize_;
}
int32_t rice::p2p::splitstream::testing::MySplitStreamClient::msgSize_;

void rice::p2p::splitstream::testing::MySplitStreamClient::ctor(::rice::pastry::PastryNode* n, ::java::lang::String* instance)
{
    super::ctor();
    init();
    this->n = n;
    this->instance = instance;
    this->ss = new ::rice::p2p::splitstream::SplitStreamImpl(n, instance);
}

void rice::p2p::splitstream::testing::MySplitStreamClient::attachChannel(::rice::p2p::splitstream::ChannelId* cid)
{
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"Attaching to Channel "_j)->append(static_cast< ::java::lang::Object* >(cid))
        ->append(u" at "_j)
        ->append(npc(npc(npc(n)->getEnvironment())->getTimeSource())->currentTimeMillis())->toString());
    if(channel == nullptr)
        channel = npc(ss)->attachChannel(cid);

    getStripes();
}

void rice::p2p::splitstream::testing::MySplitStreamClient::subscribeToAllChannels()
{
    for (auto i = int32_t(0); i < npc(stripes)->length; i++) {
        npc((*stripes)[i])->subscribe(this);
    }
}

rice::p2p::splitstream::StripeArray* rice::p2p::splitstream::testing::MySplitStreamClient::getStripes()
{
    stripes = npc(channel)->getStripes();
    return stripes;
}

bool rice::p2p::splitstream::testing::MySplitStreamClient::shouldPublish()
{
    try {
        ::rice::p2p::commonapi::IdRange* range = npc(npc(n)->getLeafSet())->range(npc(n)->getLocalHandle(), 0);
        return npc(range)->containsId(::rice::pastry::Id::build());
    } catch (::rice::p2p::commonapi::RangeCannotBeDeterminedException* rcbde) {
        return true;
    }
}

void rice::p2p::splitstream::testing::MySplitStreamClient::publishNext()
{
    if(shouldPublish()) {
        publish(npc(n)->getId(), curSeq);
        curSeq++;
    }
}

void rice::p2p::splitstream::testing::MySplitStreamClient::publish(::rice::p2p::commonapi::Id* id, int32_t seq)
{
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"MSSC.publish("_j)->append(static_cast< ::java::lang::Object* >(id))
        ->append(u":"_j)
        ->append(seq)
        ->append(u"):"_j)
        ->append(npc(npc(npc(n)->getEnvironment())->getTimeSource())->currentTimeMillis())->toString());
    auto msg = new ::int8_tArray(msgSize_);
    auto head = ::rice::p2p::util::MathUtils::intToByteArray_(seq);
    ::java::lang::System::arraycopy(head, 0, msg, 0, 4);
    auto idArray_ = npc(id)->toByteArray_();
    ::java::lang::System::arraycopy(idArray_, 0, msg, 4, 20);
    ::rice::pastry::Id::build(idArray_);
    publishAll(msg);
}

void rice::p2p::splitstream::testing::MySplitStreamClient::publishAll(::int8_tArray* b)
{
    for (auto i = int32_t(0); i < npc(stripes)->length; i++) {
        publish(b, (*stripes)[i]);
    }
}

void rice::p2p::splitstream::testing::MySplitStreamClient::publish(::int8_tArray* b, ::rice::p2p::splitstream::Stripe* s)
{
    npc(s)->publish(b);
}

void rice::p2p::splitstream::testing::MySplitStreamClient::joinFailed(::rice::p2p::splitstream::Stripe* s)
{
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"MSSC.joinFailed("_j)->append(static_cast< ::java::lang::Object* >(s))
        ->append(u"):"_j)
        ->append(npc(npc(npc(n)->getEnvironment())->getTimeSource())->currentTimeMillis())->toString());
}

void rice::p2p::splitstream::testing::MySplitStreamClient::deliver(::rice::p2p::splitstream::Stripe* s, ::int8_tArray* data)
{
    auto theInt = new ::int8_tArray(int32_t(4));
    ::java::lang::System::arraycopy(data, 0, theInt, 0, 4);
    auto seq = ::rice::p2p::util::MathUtils::byteArrayToInt(theInt);
    auto material = new ::int8_tArray(int32_t(20));
    ::java::lang::System::arraycopy(data, 4, material, 0, 20);
    ::rice::p2p::commonapi::Id* publisher = ::rice::pastry::Id::build(material);
    ::rice::p2p::commonapi::Id* stripeId = java_cast< ::rice::pastry::Id* >((npc(npc(s)->getStripeId())->getId()));
    auto stripeStr = npc(npc(stripeId)->toString())->substring(3, 4);
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"deliver("_j)->append(stripeStr)
        ->append(u","_j)
        ->append(static_cast< ::java::lang::Object* >(publisher))
        ->append(u","_j)
        ->append(seq)
        ->append(u"):"_j)
        ->append(npc(npc(npc(n)->getEnvironment())->getTimeSource())->currentTimeMillis())
        ->append(u" from "_j)
        ->append(static_cast< ::java::lang::Object* >(npc(s)->getParent()))->toString());
}

void rice::p2p::splitstream::testing::MySplitStreamClient::startPublishTask()
{
    publishTask = new MySplitStreamClient_startPublishTask_1(this);
    npc(npc(npc(npc(n)->getEnvironment())->getSelectorManager())->getTimer())->schedule(publishTask, SEND_PERIOD_, SEND_PERIOD_);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::splitstream::testing::MySplitStreamClient::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.splitstream.testing.MySplitStreamClient", 48);
    return c;
}

void rice::p2p::splitstream::testing::MySplitStreamClient::clinit()
{
    super::clinit();
    static bool in_cl_init = false;
struct clinit_ {
    clinit_() {
        in_cl_init = true;
        SEND_PERIOD_ = int32_t(15000);
        msgSize_ = int32_t(24);
    }
};

    if(!in_cl_init) {
        static clinit_ clinit_instance;
    }
}

java::lang::Class* rice::p2p::splitstream::testing::MySplitStreamClient::getClass0()
{
    return class_();
}

