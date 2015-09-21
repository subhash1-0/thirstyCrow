// Generated from /pastry-2.1/src/rice/p2p/commonapi/testing/CommonAPITest.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/net/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <rice/environment/params/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/testing/fwd-pastry-2.1.hpp>
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
typedef ::SubArray< ::rice::p2p::commonapi::Node, ::java::lang::ObjectArray > NodeArray;
        } // commonapi
    } // p2p
} // rice

struct default_init_tag;

class rice::p2p::commonapi::testing::CommonAPITest
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;

public: /* protected */
    ::rice::p2p::commonapi::NodeArray* nodes {  };
    ::rice::pastry::PastryNodeFactory* factory {  };
    ::rice::pastry::NodeIdFactory* idFactory {  };
    ::rice::pastry::direct::NetworkSimulator* simulator {  };
    ::rice::environment::Environment* environment {  };
    ::rice::environment::params::Parameters* params {  };

public:
    int32_t NUM_NODES {  };
    ::rice::p2p::commonapi::IdFactory* FACTORY {  };

private:
    static ::java::lang::String* SUCCESS_;
    static ::java::lang::String* FAILURE_;

public: /* protected */
    static constexpr int32_t PAD_SIZE { int32_t(60) };

private:
    static ::java::lang::String* PROTOCOL_DIRECT_;
    static ::java::lang::String* PROTOCOL_SOCKET_;
    static ::java::lang::String* PROTOCOL_RENDEZVOUS_;
    static ::java::lang::String* SIMULATOR_SPHERE_;
    static ::java::lang::String* SIMULATOR_EUCLIDEAN_;
    static ::java::lang::String* SIMULATOR_GT_ITM_;

public:
    int32_t PORT {  };
    ::java::net::InetSocketAddress* BOOTSTRAP {  };

private:
    static int32_t BOOTSTRAP_PORT_;

public:
    ::java::lang::String* PROTOCOL {  };
    ::java::lang::String* SIMULATOR {  };

private:
    static ::java::lang::String* INSTANCE_NAME_;

public: /* protected */
    ::rice::environment::logging::Logger* logger {  };
protected:
    void ctor(::rice::environment::Environment* env) /* throws(IOException) */;

public:
    static constexpr int32_t LEASE_PERIOD { int32_t(10000) };
    static constexpr int32_t TIME_TO_FIND_FAULTY { int32_t(15000) };
    virtual void waitToRecoverFromKilling(int32_t additionalTime);
    virtual void waitOnClock(int32_t time);
    virtual void setupParams(::rice::environment::Environment* env);
    virtual void createNodes();
    virtual void start();

public: /* protected */
    virtual void simulate();
    virtual void simulate(int32_t numOps);
    virtual ::rice::p2p::commonapi::Node* createNode(int32_t num);
    virtual ::rice::pastry::NodeHandle* getBootstrap();
    virtual void pause(int32_t ms);
    virtual void kill(int32_t n);
    virtual void processNode(int32_t num, ::rice::p2p::commonapi::Node* node) = 0;
    virtual void runTest() = 0;
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

public:
    static ::rice::environment::Environment* parseArgs(::java::lang::StringArray* args) /* throws(IOException) */;

    // Generated
    CommonAPITest(::rice::environment::Environment* env);
protected:
    CommonAPITest(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    static void clinit();
    static ::java::lang::String*& SUCCESS();
    static ::java::lang::String*& FAILURE();
    static ::java::lang::String*& PROTOCOL_DIRECT();
    static ::java::lang::String*& PROTOCOL_SOCKET();
    static ::java::lang::String*& PROTOCOL_RENDEZVOUS();
    static ::java::lang::String*& SIMULATOR_SPHERE();
    static ::java::lang::String*& SIMULATOR_EUCLIDEAN();
    static ::java::lang::String*& SIMULATOR_GT_ITM();
    static int32_t& BOOTSTRAP_PORT();
    static ::java::lang::String*& INSTANCE_NAME();

private:
    virtual ::java::lang::Class* getClass0();
};
