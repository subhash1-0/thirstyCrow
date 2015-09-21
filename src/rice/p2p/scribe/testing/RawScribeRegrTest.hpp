// Generated from /pastry-2.1/src/rice/p2p/scribe/testing/RawScribeRegrTest.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/scribe/fwd-pastry-2.1.hpp>
#include <rice/p2p/scribe/testing/fwd-pastry-2.1.hpp>
#include <rice/p2p/scribe/testing/ScribeRegrTest.hpp>

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
} // java

struct default_init_tag;

class rice::p2p::scribe::testing::RawScribeRegrTest
    : public ScribeRegrTest
{

public:
    typedef ScribeRegrTest super;
protected:
    void ctor(::rice::environment::Environment* env) /* throws(IOException) */;

public:
    ScribeRegrTest_TestScribeContent* buildTestScribeContent(::rice::p2p::scribe::Topic* topic, int32_t num) override;

public: /* protected */
    void processNode(int32_t num, ::rice::p2p::commonapi::Node* node) override;

public:
    static void main(::java::lang::StringArray* args) /* throws(IOException) */;

    // Generated
    RawScribeRegrTest(::rice::environment::Environment* env);
protected:
    RawScribeRegrTest(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
    friend class RawScribeRegrTest_processNode_1;
    friend class RawScribeRegrTest_RawTestScribeContent;
};
