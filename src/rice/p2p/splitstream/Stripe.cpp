// Generated from /pastry-2.1/src/rice/p2p/splitstream/Stripe.java
#include <rice/p2p/splitstream/Stripe.hpp>

#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/Class.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Integer.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/util/Hashtable.hpp>
#include <java/util/Observable.hpp>
#include <java/util/Vector.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/LogManager.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/environment/params/Parameters.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/commonapi/NodeHandle.hpp>
#include <rice/p2p/scribe/Scribe.hpp>
#include <rice/p2p/scribe/ScribeClient.hpp>
#include <rice/p2p/scribe/ScribeContent.hpp>
#include <rice/p2p/scribe/ScribeImpl.hpp>
#include <rice/p2p/scribe/Topic.hpp>
#include <rice/p2p/splitstream/Channel.hpp>
#include <rice/p2p/splitstream/SplitStreamClient.hpp>
#include <rice/p2p/splitstream/SplitStreamContent.hpp>
#include <rice/p2p/splitstream/SplitStreamScribePolicy.hpp>
#include <rice/p2p/splitstream/Stripe_subscribeFailed_1.hpp>
#include <rice/p2p/splitstream/StripeId.hpp>
#include <rice/selector/SelectorManager.hpp>
#include <rice/selector/Timer.hpp>
#include <Array.hpp>
#include <SubArray.hpp>
#include <ObjectArray.hpp>

template<typename ComponentType, typename... Bases> struct SubArray;
namespace java
{
    namespace io
    {
typedef ::SubArray< ::java::io::Serializable, ::java::lang::ObjectArray > SerializableArray;
    } // io

    namespace util
    {
typedef ::SubArray< ::java::util::Observable, ::java::lang::ObjectArray > ObservableArray;
    } // util
} // java

namespace rice
{
    namespace p2p
    {
        namespace commonapi
        {
typedef ::SubArray< ::rice::p2p::commonapi::NodeHandle, ::java::util::ObservableArray, ::java::io::SerializableArray > NodeHandleArray;
        } // commonapi

        namespace splitstream
        {
typedef ::SubArray< ::rice::p2p::splitstream::SplitStreamClient, ::java::lang::ObjectArray > SplitStreamClientArray;
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

rice::p2p::splitstream::Stripe::Stripe(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::splitstream::Stripe::Stripe(StripeId* stripeId, ::rice::p2p::scribe::Scribe* scribe, ::java::lang::String* instance, Channel* channel, int32_t maxFailedSubscriptions) 
    : Stripe(*static_cast< ::default_init_tag* >(0))
{
    ctor(stripeId,scribe,instance,channel,maxFailedSubscriptions);
}

void rice::p2p::splitstream::Stripe::ctor(StripeId* stripeId, ::rice::p2p::scribe::Scribe* scribe, ::java::lang::String* instance, Channel* channel, int32_t maxFailedSubscriptions)
{
    super::ctor();
    this->instance = instance;
    this->MAX_FAILED_SUBSCRIPTION = maxFailedSubscriptions;
    this->stripeId = stripeId;
    this->scribe = scribe;
    logger = npc(npc(npc(scribe)->getEnvironment())->getLogManager())->getLogger(Stripe::class_(), instance);
    this->channel = channel;
    this->isPrimary_ = false;
    this->failed = new ::java::util::Hashtable();
    if(SplitStreamScribePolicy::getPrefixMatch(npc(this->channel)->getLocalId(), npc(stripeId)->getId(), npc(channel)->getStripeBase()) > 0)
        this->isPrimary_ = true;

    this->clients = new ::java::util::Vector();
    this->topic = new ::rice::p2p::scribe::Topic(npc(stripeId)->getId());
}

rice::p2p::splitstream::StripeId* rice::p2p::splitstream::Stripe::getStripeId()
{
    return stripeId;
}

bool rice::p2p::splitstream::Stripe::isPrimary()
{
    return isPrimary_;
}

bool rice::p2p::splitstream::Stripe::isSubscribed()
{
    return (npc(clients)->size() != 0);
}

void rice::p2p::splitstream::Stripe::subscribe(SplitStreamClient* client)
{
    if(!npc(clients)->contains(static_cast< ::java::lang::Object* >(client))) {
        if(npc(clients)->size() == 0) {
            npc(scribe)->subscribe(topic, this);
        }
        npc(clients)->add(static_cast< ::java::lang::Object* >(client));
    }
}

void rice::p2p::splitstream::Stripe::unsubscribe(SplitStreamClient* client)
{
    if(npc(clients)->contains(static_cast< ::java::lang::Object* >(client))) {
        npc(clients)->remove(static_cast< ::java::lang::Object* >(client));
        if(npc(clients)->size() == 0) {
            npc(scribe)->unsubscribe(topic, static_cast< ::rice::p2p::scribe::ScribeClient* >(this));
        }
    }
}

void rice::p2p::splitstream::Stripe::publish(::int8_tArray* data)
{
    npc(scribe)->publish(topic, new SplitStreamContent(data));
}

bool rice::p2p::splitstream::Stripe::anycast(::rice::p2p::scribe::Topic* topic, ::rice::p2p::scribe::ScribeContent* content)
{
    return false;
}

void rice::p2p::splitstream::Stripe::deliver(::rice::p2p::scribe::Topic* topic, ::rice::p2p::scribe::ScribeContent* content)
{
    if(npc(this->topic)->equals(static_cast< ::java::lang::Object* >(topic))) {
        if(dynamic_cast< SplitStreamContent* >(content) != nullptr) {
            auto data = npc((java_cast< SplitStreamContent* >(content)))->getData();
            auto clients = java_cast< SplitStreamClientArray* >(java_cast< SplitStreamClientArray* >(npc(java_cast< ::java::util::Vector* >(this->clients))->toArray_(static_cast< ::java::lang::ObjectArray* >(new SplitStreamClientArray(int32_t(0))))));
            for (auto i = int32_t(0); i < npc(clients)->length; i++) {
                npc((*clients)[i])->deliver(this, data);
            }
        } else {
            if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                npc(logger)->log(::java::lang::StringBuilder().append(u"Received unexpected content "_j)->append(static_cast< ::java::lang::Object* >(content))->toString());

        }
    } else {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(logger)->log(::java::lang::StringBuilder().append(u"Received update for unexcpected topic "_j)->append(static_cast< ::java::lang::Object* >(topic))
                ->append(u" content "_j)
                ->append(static_cast< ::java::lang::Object* >(content))->toString());

    }
}

void rice::p2p::splitstream::Stripe::childAdded(::rice::p2p::scribe::Topic* topic, ::rice::p2p::commonapi::NodeHandle* child)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(::java::lang::StringBuilder().append(u"childAdded("_j)->append(static_cast< ::java::lang::Object* >(topic))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(child))
            ->append(u")"_j)->toString());

}

void rice::p2p::splitstream::Stripe::childRemoved(::rice::p2p::scribe::Topic* topic, ::rice::p2p::commonapi::NodeHandle* child)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(::java::lang::StringBuilder().append(u"childRemoved("_j)->append(static_cast< ::java::lang::Object* >(topic))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(child))
            ->append(u")"_j)->toString());

}

void rice::p2p::splitstream::Stripe::subscribeFailed(::rice::p2p::scribe::Topic* topic)
{
    auto count = java_cast< ::java::lang::Integer* >(java_cast< ::java::lang::Integer* >(npc(failed)->get(static_cast< ::java::lang::Object* >(topic))));
    if(count == nullptr) {
        count = new ::java::lang::Integer(int32_t(0));
    }
    if(npc(count)->intValue() < MAX_FAILED_SUBSCRIPTION) {
        count = new ::java::lang::Integer(npc(count)->intValue() + int32_t(1));
        if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(logger)->log(::java::lang::StringBuilder().append(u"DEBUG :: Subscription failed at "_j)->append(static_cast< ::java::lang::Object* >(npc(channel)->getLocalId()))
                ->append(u" for topic "_j)
                ->append(static_cast< ::java::lang::Object* >(topic))
                ->append(u" - retrying."_j)->toString());

        npc(scribe)->subscribe(topic, this);
        npc(failed)->put(static_cast< ::java::lang::Object* >(topic), static_cast< ::java::lang::Object* >(count));
    } else {
        ::rice::selector::TimerTask* resubscribeTask = new Stripe_subscribeFailed_1(this, topic);
        npc(npc(npc(npc(scribe)->getEnvironment())->getSelectorManager())->getTimer())->schedule(resubscribeTask, npc(npc(npc(scribe)->getEnvironment())->getParameters())->getInt(u"p2p_splitStream_stripe_max_failed_subscription_retry_delay"_j));
    }
}

java::lang::String* rice::p2p::splitstream::Stripe::toString()
{
    return ::java::lang::StringBuilder().append(u"Stripe "_j)->append(static_cast< ::java::lang::Object* >(stripeId))->toString();
}

rice::p2p::commonapi::NodeHandleArray* rice::p2p::splitstream::Stripe::getChildren()
{
    return npc(this->scribe)->getChildren(new ::rice::p2p::scribe::Topic(npc(this->getStripeId())->getId()));
}

rice::p2p::commonapi::NodeHandle* rice::p2p::splitstream::Stripe::getParent()
{
    return npc((java_cast< ::rice::p2p::scribe::ScribeImpl* >(this->scribe)))->getParent(new ::rice::p2p::scribe::Topic(npc(this->getStripeId())->getId()));
}

bool rice::p2p::splitstream::Stripe::isRoot()
{
    return npc((java_cast< ::rice::p2p::scribe::ScribeImpl* >(this->scribe)))->isRoot(topic);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::splitstream::Stripe::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.splitstream.Stripe", 27);
    return c;
}

java::lang::Class* rice::p2p::splitstream::Stripe::getClass0()
{
    return class_();
}

