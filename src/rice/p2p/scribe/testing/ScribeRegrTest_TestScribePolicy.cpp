// Generated from /pastry-2.1/src/rice/p2p/scribe/testing/ScribeRegrTest.java
#include <rice/p2p/scribe/testing/ScribeRegrTest_TestScribePolicy.hpp>

#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/util/List.hpp>
#include <rice/p2p/scribe/Scribe.hpp>
#include <rice/p2p/scribe/ScribeClient.hpp>
#include <rice/p2p/scribe/messaging/SubscribeMessage.hpp>
#include <rice/p2p/scribe/testing/ScribeRegrTest.hpp>
#include <ObjectArray.hpp>
#include <SubArray.hpp>

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

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::scribe::testing::ScribeRegrTest_TestScribePolicy::ScribeRegrTest_TestScribePolicy(ScribeRegrTest *ScribeRegrTest_this, const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
    , ScribeRegrTest_this(ScribeRegrTest_this)
{
    clinit();
}

rice::p2p::scribe::testing::ScribeRegrTest_TestScribePolicy::ScribeRegrTest_TestScribePolicy(ScribeRegrTest *ScribeRegrTest_this, ::rice::p2p::scribe::Scribe* scribe) 
    : ScribeRegrTest_TestScribePolicy(ScribeRegrTest_this, *static_cast< ::default_init_tag* >(0))
{
    ctor(scribe);
}

void rice::p2p::scribe::testing::ScribeRegrTest_TestScribePolicy::ctor(::rice::p2p::scribe::Scribe* scribe)
{
    super::ctor(npc(scribe)->getEnvironment());
    this->scribe = scribe;
    allowSubscribe_ = true;
    neverAllowSubscribe_ = false;
}

void rice::p2p::scribe::testing::ScribeRegrTest_TestScribePolicy::allowSubscribe(bool allowSubscribe)
{
    this->allowSubscribe_ = allowSubscribe;
}

void rice::p2p::scribe::testing::ScribeRegrTest_TestScribePolicy::neverAllowSubscribe(bool neverAllowSubscribe)
{
    this->neverAllowSubscribe_ = neverAllowSubscribe;
}

bool rice::p2p::scribe::testing::ScribeRegrTest_TestScribePolicy::allowSubscribe(::rice::p2p::scribe::messaging::SubscribeMessage* message, ::rice::p2p::scribe::ScribeClientArray* clients, ::rice::p2p::commonapi::NodeHandleArray* children)
{
    return (!neverAllowSubscribe_) && (allowSubscribe_ || (npc(clients)->length > 0) || npc(this->scribe)->isRoot(npc(message)->getTopic()));
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::scribe::testing::ScribeRegrTest_TestScribePolicy::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.scribe.testing.ScribeRegrTest.TestScribePolicy", 55);
    return c;
}

java::util::List* rice::p2p::scribe::testing::ScribeRegrTest_TestScribePolicy::allowSubscribe(::rice::p2p::scribe::Scribe* scribe, ::rice::p2p::commonapi::NodeHandle* source, ::java::util::List* topics, ::rice::p2p::scribe::ScribeContent* content)
{
    return super::allowSubscribe(scribe, source, topics, content);
}

java::lang::Class* rice::p2p::scribe::testing::ScribeRegrTest_TestScribePolicy::getClass0()
{
    return class_();
}

