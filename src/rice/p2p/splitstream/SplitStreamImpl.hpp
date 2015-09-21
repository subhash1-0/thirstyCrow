// Generated from /pastry-2.1/src/rice/p2p/splitstream/SplitStreamImpl.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/scribe/fwd-pastry-2.1.hpp>
#include <rice/p2p/splitstream/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/p2p/splitstream/SplitStream.hpp>

template<typename ComponentType, typename... Bases> struct SubArray;
namespace rice
{
    namespace p2p
    {
        namespace splitstream
        {
typedef ::SubArray< ::rice::p2p::splitstream::Channel, ::java::lang::ObjectArray > ChannelArray;
        } // splitstream
    } // p2p
} // rice

struct default_init_tag;

class rice::p2p::splitstream::SplitStreamImpl
    : public virtual ::java::lang::Object
    , public virtual SplitStream
{

public:
    typedef ::java::lang::Object super;

public: /* protected */
    ::rice::p2p::scribe::Scribe* scribe {  };
    ::rice::p2p::commonapi::Node* node {  };
    ::java::util::Hashtable* channels {  };
    int32_t stripeBaseBitLength {  };
    int32_t maxFailedSubscriptions {  };
    int32_t defaultMaxChildren {  };
    ::java::lang::String* instance {  };
protected:
    void ctor(::rice::p2p::commonapi::Node* node, ::java::lang::String* instance);
    void ctor(::rice::p2p::commonapi::Node* node, ::java::lang::String* instance, SplitStreamScribePolicyFactory* factory);

public:
    Channel* createChannel(ChannelId* id) override;
    Channel* attachChannel(ChannelId* id) override;
    ChannelArray* getChannels() override;
    virtual SplitStreamScribePolicy* getPolicy();
    int32_t getStripeBaseBitLength() override;
    ::rice::environment::Environment* getEnvironment() override;
    void destroy() override;

    // Generated
    SplitStreamImpl(::rice::p2p::commonapi::Node* node, ::java::lang::String* instance);
    SplitStreamImpl(::rice::p2p::commonapi::Node* node, ::java::lang::String* instance, SplitStreamScribePolicyFactory* factory);
protected:
    SplitStreamImpl(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
    friend class SplitStreamImpl_SplitStreamImpl_1;
    friend class SplitStreamImpl_SplitStreamImpl_2;
};
