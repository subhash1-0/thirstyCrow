// Generated from /pastry-2.1/src/rice/pastry/testing/RoutingTableTest.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/scribe/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/leafset/fwd-pastry-2.1.hpp>
#include <rice/pastry/routing/fwd-pastry-2.1.hpp>
#include <rice/pastry/testing/fwd-pastry-2.1.hpp>
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

struct default_init_tag;

class rice::pastry::testing::RoutingTableTest
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    bool printLiveness {  };
    bool printLeafSets {  };
    ::java::util::Vector* nodes {  };
    ::java::util::HashMap* apps {  };
    int32_t timeToFindFaulty {  };
    ::rice::environment::Environment* env {  };
    int32_t numNodes {  };
    int32_t meanSessionTime {  };
    bool useScribe {  };
    int32_t msgSendRate {  };
    int32_t rtMaintTime {  };
    int32_t tryNum {  };
    ::rice::pastry::PastryNodeFactory* factory {  };
    ::rice::p2p::commonapi::IdFactory* idFactory {  };
    ::rice::pastry::NodeIdFactory* nidFactory {  };
    ::rice::p2p::scribe::Topic* topic {  };
    int32_t reportRate {  };
    int32_t testTime {  };

public:
    static constexpr bool logHeavy { false };
protected:
    void ctor(int32_t numNodes, int32_t meanSessionTime, bool useScribe, int32_t msgSendRate, int32_t rtMaintTime, int32_t tryNum, ::rice::environment::Environment* env) /* throws(Exception) */;

public:
    virtual void startLoggerTask();
    virtual void createNodes() /* throws(InterruptedException) */;
    virtual void sendSomeMessages();
    virtual void sendSomeScribeMessages();
    virtual ::rice::pastry::PastryNode* createNode() /* throws(InterruptedException, IOException) */;
    virtual void finishNode(::rice::pastry::PastryNode* node);

private:
    void testLeafSets();
    void testRoutingTables(int32_t round);
    double testRoutingTables1();
    double testRoutingTables1a();
    int32_t testRoutingTables2();
    int32_t testRoutingTables2a();
    int32_t calcLatency(::rice::pastry::PastryNode* node, ::rice::pastry::NodeHandle* thatHandle);

public: /* package */
    int32_t thePenalty {  };

private:
    ::rice::pastry::NodeHandle* getNextHop(::rice::pastry::routing::RoutingTable* rt, ::rice::pastry::leafset::LeafSet* ls, ::rice::pastry::NodeHandle* thatHandle, ::rice::pastry::PastryNode* localNode);

public:
    static void main(::java::lang::StringArray* args) /* throws(Exception) */;

    // Generated
    RoutingTableTest(int32_t numNodes, int32_t meanSessionTime, bool useScribe, int32_t msgSendRate, int32_t rtMaintTime, int32_t tryNum, ::rice::environment::Environment* env);
protected:
    RoutingTableTest(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    void init();
    virtual ::java::lang::Class* getClass0();
    friend class RoutingTableTest_startLoggerTask_1;
    friend class RoutingTableTest_startLoggerTask_2;
    friend class RoutingTableTest_CreatorTimerTask;
    friend class RoutingTableTest_TestScribeContent;
    friend class RoutingTableTest_createNode_3;
    friend class RoutingTableTest_createNode_4;
    friend class RoutingTableTest_createNode_5;
    friend class RoutingTableTest_finishNode_6;
    friend class RoutingTableTest_finishNode_6_6_1;
    friend class RoutingTableTest_finishNode_7;
    friend class RoutingTableTest_testLeafSets_8;
    friend class RoutingTableTest_MyApp;
    friend class RoutingTableTest_TestScribeClient;
    friend class RoutingTableTest_main_9;
};
