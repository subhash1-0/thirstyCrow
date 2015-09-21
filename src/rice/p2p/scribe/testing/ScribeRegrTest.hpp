// Generated from /pastry-2.1/src/rice/p2p/scribe/testing/ScribeRegrTest.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/scribe/fwd-pastry-2.1.hpp>
#include <rice/p2p/scribe/javaserialized/fwd-pastry-2.1.hpp>
#include <rice/p2p/scribe/maintenance/fwd-pastry-2.1.hpp>
#include <rice/p2p/scribe/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/p2p/scribe/testing/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/testing/CommonAPITest.hpp>

template<typename ComponentType, typename... Bases> struct SubArray;
namespace java
{
    namespace io
    {
typedef ::SubArray< ::java::io::Serializable, ::java::lang::ObjectArray > SerializableArray;
    } // io

    namespace lang
    {
typedef ::SubArray< ::java::lang::CharSequence, ObjectArray > CharSequenceArray;
typedef ::SubArray< ::java::lang::Comparable, ObjectArray > ComparableArray;
typedef ::SubArray< ::java::lang::String, ObjectArray, ::java::io::SerializableArray, ComparableArray, CharSequenceArray > StringArray;
    } // lang

    namespace util
    {
typedef ::SubArray< ::java::util::Observer, ::java::lang::ObjectArray > ObserverArray;
    } // util
} // java

namespace rice
{
typedef ::SubArray< ::rice::Destructable, ::java::lang::ObjectArray > DestructableArray;

    namespace p2p
    {
        namespace commonapi
        {
typedef ::SubArray< ::rice::p2p::commonapi::Application, ::java::lang::ObjectArray > ApplicationArray;
        } // commonapi

        namespace scribe
        {
typedef ::SubArray< ::rice::p2p::scribe::BaseScribe, ::java::lang::ObjectArray, ::rice::DestructableArray > BaseScribeArray;

            namespace rawserialization
            {
typedef ::SubArray< ::rice::p2p::scribe::rawserialization::RawScribe, ::java::lang::ObjectArray, ::rice::p2p::scribe::BaseScribeArray > RawScribeArray;
            } // rawserialization

            namespace javaserialized
            {
typedef ::SubArray< ::rice::p2p::scribe::javaserialized::JavaScribe, ::java::lang::ObjectArray, ::rice::p2p::scribe::BaseScribeArray > JavaScribeArray;
            } // javaserialized
typedef ::SubArray< ::rice::p2p::scribe::Scribe, ::java::lang::ObjectArray, ::rice::p2p::scribe::rawserialization::RawScribeArray, ::rice::p2p::scribe::javaserialized::JavaScribeArray > ScribeArray;

            namespace maintenance
            {
typedef ::SubArray< ::rice::p2p::scribe::maintenance::MaintainableScribe, ::java::lang::ObjectArray, ::rice::p2p::scribe::BaseScribeArray > MaintainableScribeArray;
            } // maintenance
typedef ::SubArray< ::rice::p2p::scribe::ScribeImpl, ::java::lang::ObjectArray, ScribeArray, ::rice::p2p::scribe::maintenance::MaintainableScribeArray, ::rice::p2p::commonapi::ApplicationArray, ::java::util::ObserverArray > ScribeImplArray;
typedef ::SubArray< ::rice::p2p::scribe::ScribePolicy, ::java::lang::ObjectArray > ScribePolicyArray;
typedef ::SubArray< ::rice::p2p::scribe::ScribePolicy_DefaultScribePolicy, ::java::lang::ObjectArray, ScribePolicyArray > ScribePolicy_DefaultScribePolicyArray;

            namespace testing
            {
typedef ::SubArray< ::rice::p2p::scribe::testing::ScribeRegrTest_TestScribePolicy, ::rice::p2p::scribe::ScribePolicy_DefaultScribePolicyArray > ScribeRegrTest_TestScribePolicyArray;
            } // testing
        } // scribe
    } // p2p
} // rice

struct default_init_tag;

class rice::p2p::scribe::testing::ScribeRegrTest
    : public ::rice::p2p::commonapi::testing::CommonAPITest
{

public:
    typedef ::rice::p2p::commonapi::testing::CommonAPITest super;

private:
    static ::java::lang::String* INSTANCE_;

public: /* protected */
    ::rice::p2p::scribe::ScribeImplArray* scribes {  };
    ScribeRegrTest_TestScribePolicyArray* policies {  };
protected:
    void ctor(::rice::environment::Environment* env) /* throws(IOException) */;

public:
    virtual ScribeRegrTest_TestScribeContent* buildTestScribeContent(::rice::p2p::scribe::Topic* topic, int32_t numMessages);
    void setupParams(::rice::environment::Environment* env) override;
    static void main(::java::lang::StringArray* args) /* throws(IOException) */;

public: /* protected */
    void processNode(int32_t num, ::rice::p2p::commonapi::Node* node) override;
    void runTest() override;
    virtual void testAddNode();
    virtual void testBasic(int32_t skip, ::java::lang::String* name);
    virtual void testMultiSubscribe(int32_t skip, ::java::lang::String* name);
    virtual void testAPI();
    virtual void testFailureNotification();
    virtual void testSingleRoot(::java::lang::String* name);
    virtual void testMaintenance();

private:
    ::rice::p2p::commonapi::Id* generateId();

public:
    static ::java::util::List* buildListOf1(::rice::p2p::scribe::Topic* topic);

    // Generated
    ScribeRegrTest(::rice::environment::Environment* env);
protected:
    ScribeRegrTest(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    static void clinit();
    static ::java::lang::String*& INSTANCE();

private:
    virtual ::java::lang::Class* getClass0();
    friend class ScribeRegrTest_TestScribeContent;
    friend class ScribeRegrTest_TestRouteMessage;
    friend class ScribeRegrTest_TestScribeClient;
    friend class ScribeRegrTest_TestScribePolicy;
};
