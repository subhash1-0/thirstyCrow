// Generated from /pastry-2.1/src/rice/p2p/splitstream/testing/SplitStreamRegrTest.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/splitstream/fwd-pastry-2.1.hpp>
#include <rice/p2p/splitstream/testing/fwd-pastry-2.1.hpp>
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
} // java

namespace rice
{
typedef ::SubArray< ::rice::Destructable, ::java::lang::ObjectArray > DestructableArray;

    namespace p2p
    {
        namespace splitstream
        {
typedef ::SubArray< ::rice::p2p::splitstream::SplitStream, ::java::lang::ObjectArray, ::rice::DestructableArray > SplitStreamArray;
typedef ::SubArray< ::rice::p2p::splitstream::SplitStreamClient, ::java::lang::ObjectArray > SplitStreamClientArray;
typedef ::SubArray< ::rice::p2p::splitstream::SplitStreamImpl, ::java::lang::ObjectArray, SplitStreamArray > SplitStreamImplArray;

            namespace testing
            {
typedef ::SubArray< ::rice::p2p::splitstream::testing::SplitStreamRegrTest_SplitStreamTestClient, ::java::lang::ObjectArray, ::rice::p2p::splitstream::SplitStreamClientArray > SplitStreamRegrTest_SplitStreamTestClientArray;
            } // testing
        } // splitstream
    } // p2p
} // rice

struct default_init_tag;

class rice::p2p::splitstream::testing::SplitStreamRegrTest
    : public ::rice::p2p::commonapi::testing::CommonAPITest
{

public:
    typedef ::rice::p2p::commonapi::testing::CommonAPITest super;

private:
    static ::java::lang::String* INSTANCE_;

public: /* protected */
    ::rice::p2p::splitstream::SplitStreamImplArray* splitstreams {  };
    SplitStreamRegrTest_SplitStreamTestClientArray* ssclients {  };
protected:
    void ctor(::rice::environment::Environment* env) /* throws(IOException) */;

public:
    static void main(::java::lang::StringArray* args) /* throws(IOException) */;

public: /* protected */
    void processNode(int32_t num, ::rice::p2p::commonapi::Node* node) override;
    void runTest() override;
    virtual void testBandwidthUsage();
    virtual void testIndependence();
    virtual void testMaintenance(int32_t num);
    virtual void testBasic();
    virtual bool checkTree(int32_t startindex, int32_t num);
    virtual void testFailure(int32_t numnodes);

private:
    ::rice::p2p::commonapi::Id* generateId();

    // Generated

public:
    SplitStreamRegrTest(::rice::environment::Environment* env);
protected:
    SplitStreamRegrTest(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    static void clinit();
    static ::java::lang::String*& INSTANCE();

private:
    virtual ::java::lang::Class* getClass0();
    friend class SplitStreamRegrTest_SplitStreamTestClient;
};
