// Generated from /pastry-2.1/src/rice/p2p/splitstream/testing/SplitStreamRegrTest.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/scribe/fwd-pastry-2.1.hpp>
#include <rice/p2p/splitstream/fwd-pastry-2.1.hpp>
#include <rice/p2p/splitstream/testing/fwd-pastry-2.1.hpp>
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

class rice::p2p::splitstream::testing::SplitStreamRegrTest_SplitStreamTestClient
    : public virtual ::java::lang::Object
    , public virtual ::rice::p2p::splitstream::SplitStreamClient
{

public:
    typedef ::java::lang::Object super;

private:
    ::rice::p2p::commonapi::Node* n {  };
    ::rice::p2p::splitstream::StripeArray* stripes {  };
    ::rice::p2p::splitstream::Channel* channel {  };
    ::rice::p2p::splitstream::SplitStream* ss {  };
    int32_t numMesgsReceived {  };
    ::rice::p2p::splitstream::SplitStreamScribePolicy* policy {  };
protected:
    void ctor(::rice::p2p::commonapi::Node* n, ::rice::p2p::splitstream::SplitStream* ss);

public:
    virtual void destroy();
    virtual ::rice::p2p::splitstream::Channel* getChannel();
    void joinFailed(::rice::p2p::splitstream::Stripe* s) override;
    void deliver(::rice::p2p::splitstream::Stripe* s, ::int8_tArray* data) override;
    virtual void createChannel(::rice::p2p::splitstream::ChannelId* cid);
    virtual void attachChannel(::rice::p2p::splitstream::ChannelId* cid);
    virtual ::rice::p2p::splitstream::StripeArray* getStripes();
    virtual void subscribeStripes();
    virtual void publishAll(::int8_tArray* b);
    virtual void publish(::int8_tArray* b, ::rice::p2p::splitstream::Stripe* s);
    virtual int32_t getNumMesgs();
    virtual void reset();
    virtual ::rice::p2p::commonapi::Id* getId();

private:
    void log(::java::lang::String* s);

    // Generated

public:
    SplitStreamRegrTest_SplitStreamTestClient(SplitStreamRegrTest *SplitStreamRegrTest_this, ::rice::p2p::commonapi::Node* n, ::rice::p2p::splitstream::SplitStream* ss);
protected:
    SplitStreamRegrTest_SplitStreamTestClient(SplitStreamRegrTest *SplitStreamRegrTest_this, const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    void init();
    SplitStreamRegrTest *SplitStreamRegrTest_this;
    virtual ::java::lang::Class* getClass0();
    friend class SplitStreamRegrTest;
};
