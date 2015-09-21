// Generated from /pastry-2.1/src/rice/tutorial/splitstream/MySplitStreamClient.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/environment/random/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/scribe/fwd-pastry-2.1.hpp>
#include <rice/p2p/splitstream/fwd-pastry-2.1.hpp>
#include <rice/tutorial/splitstream/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/p2p/splitstream/SplitStreamClient.hpp>
#include <rice/p2p/commonapi/Application.hpp>

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

struct default_init_tag;

class rice::tutorial::splitstream::MySplitStreamClient
    : public virtual ::java::lang::Object
    , public virtual ::rice::p2p::splitstream::SplitStreamClient
    , public virtual ::rice::p2p::commonapi::Application
{

public:
    typedef ::java::lang::Object super;
    static constexpr int32_t DATA_LENGTH { int32_t(10) };
    static constexpr int32_t NUM_PUBLISHES { int32_t(10) };

public: /* package */
    int8_t seqNum {  };
    ::rice::p2p::splitstream::SplitStream* mySplitStream {  };
    ::rice::p2p::splitstream::ChannelId* myChannelId {  };
    ::rice::p2p::splitstream::Channel* myChannel {  };
    ::rice::p2p::splitstream::StripeArray* myStripes {  };

public: /* protected */
    ::rice::environment::random::RandomSource* random {  };

public: /* package */
    ::rice::p2p::commonapi::CancellableTask* publishTask {  };

public: /* protected */
    ::rice::p2p::commonapi::Endpoint* endpoint {  };
protected:
    void ctor(::rice::p2p::commonapi::Node* node);

public:
    virtual void subscribe();
    virtual void startPublishTask();
    void deliver(::rice::p2p::commonapi::Id* id, ::rice::p2p::commonapi::Message* message) override;
    virtual void publish();

private:
    ::java::lang::String* printData(::int8_tArray* data);

public:
    void deliver(::rice::p2p::splitstream::Stripe* s, ::int8_tArray* data) override;
    void joinFailed(::rice::p2p::splitstream::Stripe* s) override;
    bool forward(::rice::p2p::commonapi::RouteMessage* message) override;
    void update(::rice::p2p::commonapi::NodeHandle* handle, bool joined) override;

    // Generated
    MySplitStreamClient(::rice::p2p::commonapi::Node* node);
protected:
    MySplitStreamClient(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    void init();
    virtual ::java::lang::Class* getClass0();
    friend class MySplitStreamClient_PublishContent;
};
