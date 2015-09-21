// Generated from /pastry-2.1/src/rice/p2p/scribe/testing/RawScribeRegrTest.java
#include <rice/p2p/scribe/testing/RawScribeRegrTest.hpp>

#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/util/Observer.hpp>
#include <rice/Destructable.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/p2p/commonapi/Application.hpp>
#include <rice/p2p/scribe/BaseScribe.hpp>
#include <rice/p2p/scribe/Scribe.hpp>
#include <rice/p2p/scribe/ScribeImpl.hpp>
#include <rice/p2p/scribe/javaserialized/JavaScribe.hpp>
#include <rice/p2p/scribe/maintenance/MaintainableScribe.hpp>
#include <rice/p2p/scribe/rawserialization/RawScribe.hpp>
#include <rice/p2p/scribe/rawserialization/ScribeContentDeserializer.hpp>
#include <rice/p2p/scribe/testing/RawScribeRegrTest_processNode_1.hpp>
#include <rice/p2p/scribe/testing/RawScribeRegrTest_RawTestScribeContent.hpp>
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
        } // scribe
    } // p2p
} // rice

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::scribe::testing::RawScribeRegrTest::RawScribeRegrTest(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::scribe::testing::RawScribeRegrTest::RawScribeRegrTest(::rice::environment::Environment* env)  /* throws(IOException) */
    : RawScribeRegrTest(*static_cast< ::default_init_tag* >(0))
{
    ctor(env);
}

void rice::p2p::scribe::testing::RawScribeRegrTest::ctor(::rice::environment::Environment* env) /* throws(IOException) */
{
    super::ctor(env);
}

rice::p2p::scribe::testing::ScribeRegrTest_TestScribeContent* rice::p2p::scribe::testing::RawScribeRegrTest::buildTestScribeContent(::rice::p2p::scribe::Topic* topic, int32_t num)
{
    return new RawScribeRegrTest_RawTestScribeContent(topic, num);
}

void rice::p2p::scribe::testing::RawScribeRegrTest::processNode(int32_t num, ::rice::p2p::commonapi::Node* node)
{
    super::processNode(num, node);
    npc((*scribes)[num])->setContentDeserializer(static_cast< ::rice::p2p::scribe::rawserialization::ScribeContentDeserializer* >(new RawScribeRegrTest_processNode_1(this)));
}

void rice::p2p::scribe::testing::RawScribeRegrTest::main(::java::lang::StringArray* args) /* throws(IOException) */
{
    clinit();
    auto env = parseArgs(args);
    ScribeRegrTest* scribeTest = new RawScribeRegrTest(env);
    npc(scribeTest)->start();
    npc(env)->destroy();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::scribe::testing::RawScribeRegrTest::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.scribe.testing.RawScribeRegrTest", 41);
    return c;
}

java::lang::Class* rice::p2p::scribe::testing::RawScribeRegrTest::getClass0()
{
    return class_();
}

