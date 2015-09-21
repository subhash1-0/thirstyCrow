// Generated from /pastry-2.1/src/rice/p2p/splitstream/Channel.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/scribe/fwd-pastry-2.1.hpp>
#include <rice/p2p/splitstream/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

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
typedef ::SubArray< ::rice::p2p::splitstream::StripeId, ::java::lang::ObjectArray > StripeIdArray;
        } // splitstream
    } // p2p
} // rice

struct default_init_tag;

class rice::p2p::splitstream::Channel
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;

private:
    int32_t stripeBase {  };

public: /* protected */
    ChannelId* channelId {  };
    StripeArray* stripes {  };
    ::rice::p2p::commonapi::Id* localId {  };
protected:
    void ctor(ChannelId* channelId, ::rice::p2p::scribe::Scribe* scribe, ::java::lang::String* instance, ::rice::p2p::commonapi::IdFactory* factory, ::rice::p2p::commonapi::Id* localId, int32_t stripeBase, int32_t maxFailedSubscriptions);

public:
    virtual ::rice::p2p::commonapi::Id* getLocalId();
    virtual ChannelId* getChannelId();
    virtual StripeArray* getStripes();

public: /* protected */
    virtual Stripe* getPrimaryStripe();

public:
    virtual int32_t getStripeBase();

public: /* protected */
    virtual StripeIdArray* generateStripeIds(ChannelId* id, ::rice::p2p::commonapi::IdFactory* factory);

private:
    static ::int8_tArray* process(::int8_tArray* array, int32_t base, int32_t num);
    static ::int8_tArray* switchEndian(::int8_tArray* array);

    // Generated

public:
    Channel(ChannelId* channelId, ::rice::p2p::scribe::Scribe* scribe, ::java::lang::String* instance, ::rice::p2p::commonapi::IdFactory* factory, ::rice::p2p::commonapi::Id* localId, int32_t stripeBase, int32_t maxFailedSubscriptions);
protected:
    Channel(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
