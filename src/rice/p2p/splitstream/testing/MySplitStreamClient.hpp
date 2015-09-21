// Generated from /pastry-2.1/src/rice/p2p/splitstream/testing/MySplitStreamClient.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/scribe/fwd-pastry-2.1.hpp>
#include <rice/p2p/splitstream/fwd-pastry-2.1.hpp>
#include <rice/p2p/splitstream/testing/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/selector/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/p2p/splitstream/SplitStreamClient.hpp>

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

class rice::p2p::splitstream::testing::MySplitStreamClient
    : public virtual ::java::lang::Object
    , public virtual ::rice::p2p::splitstream::SplitStreamClient
{

public:
    typedef ::java::lang::Object super;

private:
    static int32_t SEND_PERIOD_;
    static int32_t msgSize_;
    ::rice::pastry::PastryNode* n {  };
    ::rice::p2p::splitstream::StripeArray* stripes {  };
    ::rice::p2p::splitstream::Channel* channel {  };
    ::rice::p2p::splitstream::SplitStream* ss {  };
    int32_t numMesgsReceived {  };
    ::rice::p2p::splitstream::SplitStreamScribePolicy* policy {  };
    ::java::lang::String* instance {  };

public: /* package */
    ::rice::selector::TimerTask* publishTask {  };
    int32_t curSeq {  };
protected:
    void ctor(::rice::pastry::PastryNode* n, ::java::lang::String* instance);

public:
    virtual void attachChannel(::rice::p2p::splitstream::ChannelId* cid);
    virtual void subscribeToAllChannels();
    virtual ::rice::p2p::splitstream::StripeArray* getStripes();
    virtual bool shouldPublish();
    virtual void publishNext();
    virtual void publish(::rice::p2p::commonapi::Id* id, int32_t seq);
    virtual void publishAll(::int8_tArray* b);
    virtual void publish(::int8_tArray* b, ::rice::p2p::splitstream::Stripe* s);
    void joinFailed(::rice::p2p::splitstream::Stripe* s) override;
    void deliver(::rice::p2p::splitstream::Stripe* s, ::int8_tArray* data) override;
    virtual void startPublishTask();

    // Generated
    MySplitStreamClient(::rice::pastry::PastryNode* n, ::java::lang::String* instance);
protected:
    MySplitStreamClient(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    static void clinit();

private:
    void init();

public:
    static int32_t& SEND_PERIOD();
    static int32_t& msgSize();

private:
    virtual ::java::lang::Class* getClass0();
    friend class MySplitStreamClient_startPublishTask_1;
};
