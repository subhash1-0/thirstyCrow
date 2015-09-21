// Generated from /pastry-2.1/src/rice/p2p/splitstream/Stripe.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/scribe/fwd-pastry-2.1.hpp>
#include <rice/p2p/splitstream/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/p2p/scribe/ScribeClient.hpp>

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
    } // p2p
} // rice

struct default_init_tag;

class rice::p2p::splitstream::Stripe
    : public virtual ::java::lang::Object
    , public virtual ::rice::p2p::scribe::ScribeClient
{

public:
    typedef ::java::lang::Object super;
    int32_t MAX_FAILED_SUBSCRIPTION {  };

public: /* protected */
    StripeId* stripeId {  };
    ::rice::p2p::scribe::Topic* topic {  };
    ::rice::p2p::scribe::Scribe* scribe {  };
    bool isPrimary_ {  };
    ::java::util::Vector* clients {  };
    Channel* channel {  };
    ::java::util::Hashtable* failed {  };
    ::java::lang::String* instance {  };

public: /* package */
    ::rice::environment::logging::Logger* logger {  };
protected:
    void ctor(StripeId* stripeId, ::rice::p2p::scribe::Scribe* scribe, ::java::lang::String* instance, Channel* channel, int32_t maxFailedSubscriptions);

public:
    virtual StripeId* getStripeId();
    virtual bool isPrimary();
    virtual bool isSubscribed();
    virtual void subscribe(SplitStreamClient* client);
    virtual void unsubscribe(SplitStreamClient* client);
    virtual void publish(::int8_tArray* data);
    bool anycast(::rice::p2p::scribe::Topic* topic, ::rice::p2p::scribe::ScribeContent* content) override;
    void deliver(::rice::p2p::scribe::Topic* topic, ::rice::p2p::scribe::ScribeContent* content) override;
    void childAdded(::rice::p2p::scribe::Topic* topic, ::rice::p2p::commonapi::NodeHandle* child) override;
    void childRemoved(::rice::p2p::scribe::Topic* topic, ::rice::p2p::commonapi::NodeHandle* child) override;
    void subscribeFailed(::rice::p2p::scribe::Topic* topic) override;
    ::java::lang::String* toString() override;
    virtual ::rice::p2p::commonapi::NodeHandleArray* getChildren();
    virtual ::rice::p2p::commonapi::NodeHandle* getParent();
    virtual bool isRoot();

    // Generated
    Stripe(StripeId* stripeId, ::rice::p2p::scribe::Scribe* scribe, ::java::lang::String* instance, Channel* channel, int32_t maxFailedSubscriptions);
protected:
    Stripe(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
    friend class Stripe_subscribeFailed_1;
};
