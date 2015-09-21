// Generated from /pastry-2.1/src/rice/p2p/multiring/testing/MultiringRegrTest.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/multiring/fwd-pastry-2.1.hpp>
#include <rice/p2p/multiring/testing/fwd-pastry-2.1.hpp>
#include <rice/p2p/scribe/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/direct/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

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
typedef ::SubArray< ::java::lang::Cloneable, ObjectArray > CloneableArray;
typedef ::SubArray< ::java::lang::Comparable, ObjectArray > ComparableArray;
typedef ::SubArray< ::java::lang::String, ObjectArray, ::java::io::SerializableArray, ComparableArray, CharSequenceArray > StringArray;
    } // lang
} // java

namespace rice
{
    namespace p2p
    {
        namespace commonapi
        {
typedef ::SubArray< ::rice::p2p::commonapi::Application, ::java::lang::ObjectArray > ApplicationArray;
typedef ::SubArray< ::rice::p2p::commonapi::Id, ::java::lang::ObjectArray, ::java::lang::ComparableArray, ::java::io::SerializableArray > IdArray;
typedef ::SubArray< ::rice::p2p::commonapi::Node, ::java::lang::ObjectArray > NodeArray;
        } // commonapi

        namespace scribe
        {
typedef ::SubArray< ::rice::p2p::scribe::ScribeClient, ::java::lang::ObjectArray > ScribeClientArray;
        } // scribe

        namespace multiring
        {
typedef ::SubArray< ::rice::p2p::multiring::MultiringNode, ::java::lang::ObjectArray, ::rice::p2p::commonapi::NodeArray, ::rice::p2p::scribe::ScribeClientArray > MultiringNodeArray;

            namespace testing
            {
typedef ::SubArray< ::rice::p2p::multiring::testing::MultiringRegrTest_MultiringTestApp, ::java::lang::ObjectArray, ::rice::p2p::commonapi::ApplicationArray > MultiringRegrTest_MultiringTestAppArray;
            } // testing
typedef ::SubArray< ::rice::p2p::multiring::MultiringNodeArray, ::java::lang::CloneableArray, ::java::io::SerializableArray > MultiringNodeArrayArray;

            namespace testing
            {
typedef ::SubArray< ::rice::p2p::multiring::testing::MultiringRegrTest_MultiringTestAppArray, ::java::lang::CloneableArray, ::java::io::SerializableArray > MultiringRegrTest_MultiringTestAppArrayArray;
            } // testing
        } // multiring
    } // p2p
} // rice

struct default_init_tag;

class rice::p2p::multiring::testing::MultiringRegrTest
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;

public: /* protected */
    ::rice::p2p::multiring::MultiringNodeArray* globalNodes {  };
    ::rice::p2p::multiring::MultiringNodeArrayArray* organizationalNodes {  };
    MultiringRegrTest_MultiringTestAppArray* globalApps {  };
    MultiringRegrTest_MultiringTestAppArrayArray* organizationalApps {  };
    ::rice::p2p::commonapi::Id* globalRingId {  };
    ::rice::p2p::commonapi::IdArray* ringIds {  };
    ::rice::pastry::PastryNodeFactory* factory {  };
    ::rice::p2p::commonapi::IdFactory* idFactory {  };
    ::rice::pastry::direct::NetworkSimulator* simulator {  };

private:
    static int32_t NUM_GLOBAL_NODES_;
    static int32_t NUM_ORGANIZATIONS_;
    static int32_t NUM_INTERNAL_NODES_;
    static int32_t NUM_GATEWAY_NODES_;
    static int32_t NUM_ORGANIZATIONAL_NODES_;
    static ::java::lang::String* SUCCESS_;
    static ::java::lang::String* FAILURE_;

public: /* protected */
    static constexpr int32_t PAD_SIZE { int32_t(60) };

public:
    static constexpr int32_t PROTOCOL_DIRECT { int32_t(-138) };
    static constexpr int32_t SIMULATOR_SPHERE { int32_t(-1) };
    static constexpr int32_t SIMULATOR_EUCLIDEAN { int32_t(-2) };

private:
    static int32_t PORT_;
    static ::java::lang::String* BOOTSTRAP_HOST_;
    static int32_t BOOTSTRAP_PORT_;
    static int32_t PROTOCOL_;
    static int32_t SIMULATOR_;
    static ::java::lang::String* INSTANCE_NAME_;

public:
    ::rice::environment::Environment* environment {  };
protected:
    void ctor(::rice::environment::Environment* env) /* throws(IOException) */;

public:
    virtual void createNodes();
    virtual void start();

public: /* protected */
    virtual void simulate();
    virtual ::rice::p2p::multiring::MultiringNode* createNode(::rice::p2p::commonapi::Id* ringId, ::rice::p2p::multiring::MultiringNode* bootstrap);
    virtual ::rice::p2p::multiring::MultiringNode* createNode(::rice::p2p::multiring::MultiringNode* existing, ::rice::p2p::commonapi::Id* ringId, ::rice::p2p::multiring::MultiringNode* bootstrap);
    virtual ::rice::pastry::NodeHandle* getBootstrap(::rice::p2p::commonapi::Node* bootstrap);
    virtual void pause(int32_t ms);
    virtual void kill(int32_t n);

private:
    ::rice::p2p::commonapi::Id* generateId();
    ::rice::p2p::commonapi::Id* generateId(int32_t i);

public: /* protected */
    virtual void runTest();
    void sectionStart(::java::lang::String* name);
    void sectionDone();
    void stepStart(::java::lang::String* name);
    void stepDone();
    void stepDone(::java::lang::String* status);
    void stepDone(::java::lang::String* status, ::java::lang::String* message);
    void stepException(::java::lang::Exception* e);

private:
    ::java::lang::String* pad(::java::lang::String* start);

public: /* protected */
    void assertTrue(::java::lang::String* intention, bool test);
    void assertEquals(::java::lang::String* description, ::java::lang::Object* expected, ::java::lang::Object* actual);
    static void parseArgs(::java::lang::StringArray* args);

public:
    static void main(::java::lang::StringArray* args) /* throws(IOException) */;

    // Generated
    MultiringRegrTest(::rice::environment::Environment* env);
protected:
    MultiringRegrTest(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    static void clinit();
    static int32_t& NUM_GLOBAL_NODES();
    static int32_t& NUM_ORGANIZATIONS();
    static int32_t& NUM_INTERNAL_NODES();
    static int32_t& NUM_GATEWAY_NODES();
    static int32_t& NUM_ORGANIZATIONAL_NODES();
    static ::java::lang::String*& SUCCESS();
    static ::java::lang::String*& FAILURE();
    static int32_t& PORT();
    static ::java::lang::String*& BOOTSTRAP_HOST();
    static int32_t& BOOTSTRAP_PORT();
    static int32_t& PROTOCOL();
    static int32_t& SIMULATOR();
    static ::java::lang::String*& INSTANCE_NAME();

private:
    virtual ::java::lang::Class* getClass0();
    friend class MultiringRegrTest_MultiringTestApp;
    friend class MultiringRegrTest_MultiringTestMessage;
};
