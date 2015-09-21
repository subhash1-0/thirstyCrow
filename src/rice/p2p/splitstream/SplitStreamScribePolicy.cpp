// Generated from /pastry-2.1/src/rice/p2p/splitstream/SplitStreamScribePolicy.java
#include <rice/p2p/splitstream/SplitStreamScribePolicy.hpp>

#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Integer.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/util/Arrays.hpp>
#include <java/util/Collection.hpp>
#include <java/util/Hashtable.hpp>
#include <java/util/Iterator.hpp>
#include <java/util/List.hpp>
#include <java/util/Observable.hpp>
#include <java/util/Vector.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/params/Parameters.hpp>
#include <rice/environment/random/RandomSource.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/commonapi/NodeHandle.hpp>
#include <rice/p2p/scribe/Scribe.hpp>
#include <rice/p2p/scribe/ScribeClient.hpp>
#include <rice/p2p/scribe/ScribeContent.hpp>
#include <rice/p2p/scribe/Topic.hpp>
#include <rice/p2p/scribe/messaging/AnycastMessage.hpp>
#include <rice/p2p/scribe/messaging/SubscribeMessage.hpp>
#include <rice/p2p/scribe/rawserialization/RawScribeContent.hpp>
#include <rice/p2p/splitstream/Channel.hpp>
#include <rice/p2p/splitstream/ChannelId.hpp>
#include <rice/p2p/splitstream/SplitStream.hpp>
#include <rice/p2p/splitstream/SplitStreamSubscribeContent.hpp>
#include <rice/p2p/splitstream/Stripe.hpp>
#include <rice/p2p/splitstream/StripeId.hpp>
#include <rice/pastry/Id.hpp>
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

        namespace scribe
        {
typedef ::SubArray< ::rice::p2p::scribe::ScribeClient, ::java::lang::ObjectArray > ScribeClientArray;
        } // scribe

        namespace splitstream
        {
typedef ::SubArray< ::rice::p2p::splitstream::Channel, ::java::lang::ObjectArray > ChannelArray;
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

rice::p2p::splitstream::SplitStreamScribePolicy::SplitStreamScribePolicy(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::splitstream::SplitStreamScribePolicy::SplitStreamScribePolicy(::rice::p2p::scribe::Scribe* scribe, SplitStream* splitStream) 
    : SplitStreamScribePolicy(*static_cast< ::default_init_tag* >(0))
{
    ctor(scribe,splitStream);
}

void rice::p2p::splitstream::SplitStreamScribePolicy::ctor(::rice::p2p::scribe::Scribe* scribe, SplitStream* splitStream)
{
    super::ctor(npc(splitStream)->getEnvironment());
    DEFAULT_MAXIMUM_CHILDREN = npc(npc(npc(scribe)->getEnvironment())->getParameters())->getInt(u"p2p_splitStream_policy_default_maximum_children"_j);
    this->scribe = scribe;
    this->splitStream = splitStream;
    this->policy = new ::java::util::Hashtable();
}

int32_t rice::p2p::splitstream::SplitStreamScribePolicy::getMaxChildren(ChannelId* id)
{
    auto max = java_cast< ::java::lang::Integer* >(java_cast< ::java::lang::Integer* >(npc(policy)->get(static_cast< ::java::lang::Object* >(id))));
    if(max == nullptr) {
        return DEFAULT_MAXIMUM_CHILDREN;
    } else {
        return npc(max)->intValue();
    }
}

void rice::p2p::splitstream::SplitStreamScribePolicy::setMaxChildren(ChannelId* id, int32_t children)
{
    npc(policy)->put(static_cast< ::java::lang::Object* >(id), static_cast< ::java::lang::Object* >(new ::java::lang::Integer(children)));
}

bool rice::p2p::splitstream::SplitStreamScribePolicy::allowSubscribe(::rice::p2p::scribe::messaging::SubscribeMessage* message, ::rice::p2p::scribe::ScribeClientArray* clients, ::rice::p2p::commonapi::NodeHandleArray* children)
{
    auto channel = getChannel(npc(message)->getTopic());
    auto newChild = java_cast< ::rice::p2p::commonapi::NodeHandle* >(npc(message)->getSubscriber());
    if(channel == nullptr) {
        return npc(scribe)->isRoot(npc(message)->getTopic());
    }
    if(npc(npc(npc(message)->getSubscriber())->getId())->equals(npc(channel)->getLocalId()))
        return false;

    auto content = npc(message)->getContent();
    if(content != nullptr && (dynamic_cast< SplitStreamSubscribeContent* >(content) != nullptr)) {
        auto stage = npc((java_cast< SplitStreamSubscribeContent* >(content)))->getStage();
        if(stage == SplitStreamSubscribeContent::STAGE_FINAL()) {
            auto list = ::java::util::Arrays::asList(children);
            if(!npc(list)->contains(static_cast< ::java::lang::Object* >(npc(message)->getSource()))) {
                return false;
            } else {
                npc(this->scribe)->removeChild(npc(message)->getTopic(), npc(message)->getSource());
                return true;
            }
        }
    }
    if(getTotalChildren(channel) < getMaxChildren(npc(channel)->getChannelId())) {
        return true;
    } else {
        if((!npc(npc(npc(message)->getTopic())->getId())->equals(npc(npc(npc(channel)->getPrimaryStripe())->getStripeId())->getId())) && (!npc(scribe)->isRoot(npc(message)->getTopic()))) {
            return false;
        } else {
            if(npc(children)->length > 0) {
                auto victimChild = freeBandwidth(channel, newChild, npc(npc(message)->getTopic())->getId());
                if(npc(npc(victimChild)->getId())->equals(npc(newChild)->getId())) {
                    return false;
                } else {
                    npc(scribe)->removeChild(new ::rice::p2p::scribe::Topic(npc(npc(message)->getTopic())->getId()), victimChild);
                    return true;
                }
            } else {
                auto res = freeBandwidthUltimate(npc(npc(message)->getTopic())->getId());
                if(res != nullptr) {
                    npc(scribe)->removeChild(new ::rice::p2p::scribe::Topic(java_cast< ::rice::p2p::commonapi::Id* >(java_cast< ::java::lang::Object* >(npc(res)->elementAt(1)))), java_cast< ::rice::p2p::commonapi::NodeHandle* >(java_cast< ::java::lang::Object* >(npc(res)->elementAt(0))));
                    return true;
                } else {
                    return false;
                }
            }
        }
    }
}

void rice::p2p::splitstream::SplitStreamScribePolicy::directAnycast(::rice::p2p::scribe::messaging::AnycastMessage* message, ::rice::p2p::commonapi::NodeHandle* parent, ::java::util::Collection* children)
{
    if(parent != nullptr) {
        if(SplitStreamScribePolicy::getPrefixMatch(npc(npc(message)->getTopic())->getId(), npc(parent)->getId(), npc(splitStream)->getStripeBaseBitLength()) > 0)
            npc(message)->addFirst(parent);
        else
            npc(message)->addLast(parent);
    }
    if(dynamic_cast< ::rice::p2p::scribe::messaging::SubscribeMessage* >(message) != nullptr) {
        auto good = new ::java::util::Vector();
        auto bad = new ::java::util::Vector();
        for (auto _i = npc(children)->iterator(); _i->hasNext(); ) {
            ::rice::p2p::commonapi::NodeHandle* child = java_cast< ::rice::p2p::commonapi::NodeHandle* >(_i->next());
            {
                if(SplitStreamScribePolicy::getPrefixMatch(npc(npc(message)->getTopic())->getId(), npc(child)->getId(), npc(splitStream)->getStripeBaseBitLength()) > 0)
                    npc(good)->add(static_cast< ::java::lang::Object* >(child));
                else
                    npc(bad)->add(static_cast< ::java::lang::Object* >(child));
            }
        }
        int32_t index;
        while (npc(good)->size() > 0) {
            index = npc(npc(npc(scribe)->getEnvironment())->getRandomSource())->nextInt(npc(good)->size());
            npc(message)->addFirst(java_cast< ::rice::p2p::commonapi::NodeHandle* >((java_cast< ::java::lang::Object* >(npc(good)->elementAt(index)))));
            npc(good)->remove(static_cast< ::java::lang::Object* >(java_cast< ::rice::p2p::commonapi::NodeHandle* >((java_cast< ::java::lang::Object* >(npc(good)->elementAt(index))))));
        }
        while (npc(bad)->size() > 0) {
            index = npc(npc(npc(scribe)->getEnvironment())->getRandomSource())->nextInt(npc(bad)->size());
            npc(message)->addLast(java_cast< ::rice::p2p::commonapi::NodeHandle* >((java_cast< ::java::lang::Object* >(npc(bad)->elementAt(index)))));
            npc(bad)->remove(static_cast< ::java::lang::Object* >(java_cast< ::rice::p2p::commonapi::NodeHandle* >((java_cast< ::java::lang::Object* >(npc(bad)->elementAt(index))))));
        }
        auto nextHop = npc(message)->getNext();
        while ((nextHop != nullptr) && (!npc(nextHop)->isAlive())) {
            nextHop = npc(message)->getNext();
        }
        if(nextHop == nullptr) {
            if(npc(this->scribe)->isRoot(npc(message)->getTopic())) {
                auto res = freeBandwidthUltimate(npc(npc(message)->getTopic())->getId());
                if(res != nullptr) {
                    npc(scribe)->removeChild(new ::rice::p2p::scribe::Topic(java_cast< ::rice::p2p::commonapi::Id* >(java_cast< ::java::lang::Object* >(npc(res)->elementAt(1)))), java_cast< ::rice::p2p::commonapi::NodeHandle* >(java_cast< ::java::lang::Object* >(npc(res)->elementAt(0))));
                    npc(scribe)->addChild(npc(message)->getTopic(), npc((java_cast< ::rice::p2p::scribe::messaging::SubscribeMessage* >(message)))->getSubscriber());
                    return;
                }
            } else {
                auto ssc = new SplitStreamSubscribeContent(SplitStreamSubscribeContent::STAGE_FINAL());
                npc(message)->remove(parent);
                npc(message)->addFirst(parent);
                npc(message)->setContent(static_cast< ::rice::p2p::scribe::rawserialization::RawScribeContent* >(ssc));
            }
        } else {
            npc(message)->addFirst(nextHop);
        }
    }
}

rice::p2p::splitstream::Channel* rice::p2p::splitstream::SplitStreamScribePolicy::getChannel(::rice::p2p::scribe::Topic* topic)
{
    auto channels = npc(splitStream)->getChannels();
    for (auto i = int32_t(0); i < npc(channels)->length; i++) {
        auto channel = (*channels)[i];
        auto stripes = npc(channel)->getStripes();
        for (auto j = int32_t(0); j < npc(stripes)->length; j++) {
            auto stripe = (*stripes)[j];
            if(npc(npc(npc(stripe)->getStripeId())->getId())->equals(npc(topic)->getId())) {
                return channel;
            }
        }
    }
    return nullptr;
}

int32_t rice::p2p::splitstream::SplitStreamScribePolicy::getTotalChildren(Channel* channel)
{
    auto total = int32_t(0);
    auto stripes = npc(channel)->getStripes();
    for (auto j = int32_t(0); j < npc(stripes)->length; j++) {
        total += npc(npc(scribe)->getChildren(new ::rice::p2p::scribe::Topic(npc(npc((*stripes)[j])->getStripeId())->getId())))->length;
    }
    return total;
}

java::util::Vector* rice::p2p::splitstream::SplitStreamScribePolicy::freeBandwidthUltimate(::rice::p2p::commonapi::Id* stripeId)
{
    auto channel = getChannel(new ::rice::p2p::scribe::Topic(stripeId));
    auto stripes = npc(channel)->getStripes();
    auto candidateStripes = new ::java::util::Vector();
    ::rice::p2p::commonapi::Id* victimStripeId = nullptr;
    ::rice::p2p::scribe::Topic* tp;
    for (auto i = int32_t(0); i < npc(stripes)->length; i++) {
        tp = new ::rice::p2p::scribe::Topic(npc(npc((*stripes)[i])->getStripeId())->getId());
        if(!npc(npc(npc(npc(channel)->getPrimaryStripe())->getStripeId())->getId())->equals(npc(npc((*stripes)[i])->getStripeId())->getId()) && !npc(this->scribe)->isRoot(tp) && (npc(npc(scribe)->getChildren(tp))->length > 0)) {
            npc(candidateStripes)->add(static_cast< ::java::lang::Object* >(npc(npc((*stripes)[i])->getStripeId())->getId()));
        }
    }
    if(npc(candidateStripes)->size() == 0) {
        for (auto i = int32_t(0); i < npc(stripes)->length; i++) {
            tp = new ::rice::p2p::scribe::Topic(npc(npc((*stripes)[i])->getStripeId())->getId());
            if((!npc(npc(npc(npc(channel)->getPrimaryStripe())->getStripeId())->getId())->equals(npc(npc((*stripes)[i])->getStripeId())->getId())) && (npc(npc(scribe)->getChildren(tp))->length > 0) && (!npc(npc(npc((*stripes)[i])->getStripeId())->getId())->equals(stripeId))) {
                npc(candidateStripes)->add(static_cast< ::java::lang::Object* >(npc(npc((*stripes)[i])->getStripeId())->getId()));
            }
        }
    }
    if(npc(candidateStripes)->size() > 0) {
        victimStripeId = java_cast< ::rice::p2p::commonapi::Id* >(java_cast< ::java::lang::Object* >(npc(candidateStripes)->elementAt(npc(npc(npc(scribe)->getEnvironment())->getRandomSource())->nextInt(npc(candidateStripes)->size()))));
        ::rice::p2p::commonapi::NodeHandleArray* children;
        children = npc(this->scribe)->getChildren(new ::rice::p2p::scribe::Topic(victimStripeId));
        auto child = (*children)[npc(npc(npc(scribe)->getEnvironment())->getRandomSource())->nextInt(npc(children)->length)];
        auto result = new ::java::util::Vector();
        npc(result)->addElement(child);
        npc(result)->addElement(victimStripeId);
        return result;
    }
    return nullptr;
}

rice::p2p::commonapi::NodeHandle* rice::p2p::splitstream::SplitStreamScribePolicy::freeBandwidth(Channel* channel, ::rice::p2p::commonapi::NodeHandle* newChild, ::rice::p2p::commonapi::Id* stripeId)
{
    auto primaryStripe = npc(channel)->getPrimaryStripe();
    auto localId = npc(channel)->getLocalId();
    auto children = npc(scribe)->getChildren(new ::rice::p2p::scribe::Topic(npc(npc(primaryStripe)->getStripeId())->getId()));
    auto minPrefixMatch = getPrefixMatch(stripeId, npc(newChild)->getId(), npc(channel)->getStripeBase());
    auto victims = new ::java::util::Vector();
    for (auto j = int32_t(0); j < npc(children)->length; j++) {
        auto c = java_cast< ::rice::p2p::commonapi::NodeHandle* >((*children)[j]);
        auto match = getPrefixMatch(stripeId, npc(c)->getId(), npc(channel)->getStripeBase());
        if(match < minPrefixMatch) {
            npc(victims)->addElement(c);
        }
    }
    if(npc(victims)->size() == 0)
        return newChild;
    else
        return java_cast< ::rice::p2p::commonapi::NodeHandle* >(java_cast< ::java::lang::Object* >(npc(victims)->elementAt(npc(npc(npc(scribe)->getEnvironment())->getRandomSource())->nextInt(npc(victims)->size()))));
}

int32_t rice::p2p::splitstream::SplitStreamScribePolicy::getPrefixMatch(::rice::p2p::commonapi::Id* target, ::rice::p2p::commonapi::Id* sample, int32_t digitLength)
{
    clinit();
    auto numDigits = ::rice::pastry::Id::IdBitLength / digitLength - int32_t(1);
    return (numDigits - npc((java_cast< ::rice::pastry::Id* >(target)))->indexOfMSDD(java_cast< ::rice::pastry::Id* >(sample), digitLength));
}

void rice::p2p::splitstream::SplitStreamScribePolicy::childAdded(::rice::p2p::scribe::Topic* topic, ::rice::p2p::commonapi::NodeHandle* child)
{
}

void rice::p2p::splitstream::SplitStreamScribePolicy::childRemoved(::rice::p2p::scribe::Topic* topic, ::rice::p2p::commonapi::NodeHandle* child)
{
}

void rice::p2p::splitstream::SplitStreamScribePolicy::intermediateNode(::rice::p2p::scribe::messaging::ScribeMessage* message)
{
}

void rice::p2p::splitstream::SplitStreamScribePolicy::recvAnycastFail(::rice::p2p::scribe::Topic* topic, ::rice::p2p::commonapi::NodeHandle* failedAtNode, ::rice::p2p::scribe::ScribeContent* content)
{
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::splitstream::SplitStreamScribePolicy::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.splitstream.SplitStreamScribePolicy", 44);
    return c;
}

java::util::List* rice::p2p::splitstream::SplitStreamScribePolicy::allowSubscribe(::rice::p2p::scribe::Scribe* scribe, ::rice::p2p::commonapi::NodeHandle* source, ::java::util::List* topics, ::rice::p2p::scribe::ScribeContent* content)
{
    return super::allowSubscribe(scribe, source, topics, content);
}

java::lang::Class* rice::p2p::splitstream::SplitStreamScribePolicy::getClass0()
{
    return class_();
}

