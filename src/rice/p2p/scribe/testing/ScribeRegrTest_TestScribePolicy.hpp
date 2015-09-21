// Generated from /pastry-2.1/src/rice/p2p/scribe/testing/ScribeRegrTest.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/scribe/fwd-pastry-2.1.hpp>
#include <rice/p2p/scribe/messaging/fwd-pastry-2.1.hpp>
#include <rice/p2p/scribe/testing/fwd-pastry-2.1.hpp>
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

class rice::p2p::scribe::testing::ScribeRegrTest_TestScribePolicy
    : public ::rice::p2p::scribe::ScribePolicy_DefaultScribePolicy
{

public:
    typedef ::rice::p2p::scribe::ScribePolicy_DefaultScribePolicy super;

public: /* protected */
    ::rice::p2p::scribe::Scribe* scribe {  };
    bool allowSubscribe_ {  };
    bool neverAllowSubscribe_ {  };
protected:
    void ctor(::rice::p2p::scribe::Scribe* scribe);

public:
    virtual void allowSubscribe(bool allowSubscribe);
    virtual void neverAllowSubscribe(bool neverAllowSubscribe);
    bool allowSubscribe(::rice::p2p::scribe::messaging::SubscribeMessage* message, ::rice::p2p::scribe::ScribeClientArray* clients, ::rice::p2p::commonapi::NodeHandleArray* children) override;

    // Generated
    ScribeRegrTest_TestScribePolicy(ScribeRegrTest *ScribeRegrTest_this, ::rice::p2p::scribe::Scribe* scribe);
protected:
    ScribeRegrTest_TestScribePolicy(ScribeRegrTest *ScribeRegrTest_this, const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    ::java::util::List* allowSubscribe(::rice::p2p::scribe::Scribe* scribe, ::rice::p2p::commonapi::NodeHandle* source, ::java::util::List* topics, ::rice::p2p::scribe::ScribeContent* content);
    ScribeRegrTest *ScribeRegrTest_this;

private:
    virtual ::java::lang::Class* getClass0();
    friend class ScribeRegrTest;
    friend class ScribeRegrTest_TestScribeContent;
    friend class ScribeRegrTest_TestRouteMessage;
    friend class ScribeRegrTest_TestScribeClient;
};
