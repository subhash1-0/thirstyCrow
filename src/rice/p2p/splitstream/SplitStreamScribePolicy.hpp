// Generated from /pastry-2.1/src/rice/p2p/splitstream/SplitStreamScribePolicy.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/scribe/fwd-pastry-2.1.hpp>
#include <rice/p2p/scribe/messaging/fwd-pastry-2.1.hpp>
#include <rice/p2p/splitstream/fwd-pastry-2.1.hpp>
#include <rice/p2p/scribe/ScribePolicy_DefaultScribePolicy.hpp>

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
    } // p2p
} // rice

struct default_init_tag;

class rice::p2p::splitstream::SplitStreamScribePolicy
    : public ::rice::p2p::scribe::ScribePolicy_DefaultScribePolicy
{

public:
    typedef ::rice::p2p::scribe::ScribePolicy_DefaultScribePolicy super;
    int32_t DEFAULT_MAXIMUM_CHILDREN {  };

public: /* protected */
    SplitStream* splitStream {  };
    ::rice::p2p::scribe::Scribe* scribe {  };
    ::java::util::Hashtable* policy {  };
protected:
    void ctor(::rice::p2p::scribe::Scribe* scribe, SplitStream* splitStream);

public:
    virtual int32_t getMaxChildren(ChannelId* id);
    virtual void setMaxChildren(ChannelId* id, int32_t children);
    bool allowSubscribe(::rice::p2p::scribe::messaging::SubscribeMessage* message, ::rice::p2p::scribe::ScribeClientArray* clients, ::rice::p2p::commonapi::NodeHandleArray* children) override;
    void directAnycast(::rice::p2p::scribe::messaging::AnycastMessage* message, ::rice::p2p::commonapi::NodeHandle* parent, ::java::util::Collection* children) override;

private:
    Channel* getChannel(::rice::p2p::scribe::Topic* topic);

public:
    virtual int32_t getTotalChildren(Channel* channel);
    virtual ::java::util::Vector* freeBandwidthUltimate(::rice::p2p::commonapi::Id* stripeId);
    virtual ::rice::p2p::commonapi::NodeHandle* freeBandwidth(Channel* channel, ::rice::p2p::commonapi::NodeHandle* newChild, ::rice::p2p::commonapi::Id* stripeId);
    static int32_t getPrefixMatch(::rice::p2p::commonapi::Id* target, ::rice::p2p::commonapi::Id* sample, int32_t digitLength);
    void childAdded(::rice::p2p::scribe::Topic* topic, ::rice::p2p::commonapi::NodeHandle* child) override;
    void childRemoved(::rice::p2p::scribe::Topic* topic, ::rice::p2p::commonapi::NodeHandle* child) override;
    void intermediateNode(::rice::p2p::scribe::messaging::ScribeMessage* message) override;
    void recvAnycastFail(::rice::p2p::scribe::Topic* topic, ::rice::p2p::commonapi::NodeHandle* failedAtNode, ::rice::p2p::scribe::ScribeContent* content) override;

    // Generated
    SplitStreamScribePolicy(::rice::p2p::scribe::Scribe* scribe, SplitStream* splitStream);
protected:
    SplitStreamScribePolicy(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    ::java::util::List* allowSubscribe(::rice::p2p::scribe::Scribe* scribe, ::rice::p2p::commonapi::NodeHandle* source, ::java::util::List* topics, ::rice::p2p::scribe::ScribeContent* content);

private:
    virtual ::java::lang::Class* getClass0();
};
