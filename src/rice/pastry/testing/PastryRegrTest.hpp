// Generated from /pastry-2.1/src/rice/pastry/testing/PastryRegrTest.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/messaging/fwd-pastry-2.1.hpp>
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

class rice::pastry::testing::PastryRegrTest
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;

public: /* protected */
    ::rice::pastry::PastryNodeFactory* factory {  };

public:
    ::java::util::Vector* pastryNodes {  };
    ::java::util::SortedMap* pastryNodesSorted {  };
    ::java::util::SortedMap* pastryNodesSortedReady {  };
    ::java::util::Vector* pastryNodesLastAdded {  };
    bool inConcJoin {  };

private:
    ::java::util::Vector* rtApps {  };

public:
    ::rice::pastry::messaging::Message* lastMsg {  };
    ::rice::pastry::Id_Distance* lastDist {  };
    ::rice::pastry::Id* lastNode {  };

public: /* protected */
    virtual ::rice::pastry::NodeHandle* getBootstrap(bool firstNode) = 0;
    virtual void registerapp(::rice::pastry::PastryNode* pn, RegrTestApp* app) = 0;
    virtual bool simulate() = 0;
    virtual bool isReallyAlive(::rice::pastry::NodeHandle* nh) = 0;
    virtual void killNode(::rice::pastry::PastryNode* pn) = 0;
    ::rice::environment::Environment* environment {  };
protected:
    void ctor(::rice::environment::Environment* env);

private:
    void makePastryNode();

public: /* protected */
    virtual ::rice::pastry::PastryNode* generateNode(::rice::pastry::NodeHandle* bootstrap);

private:
    void makePastryNode(int32_t num);

public:
    virtual void pause(int32_t ms) = 0;
    virtual void sendPings(int32_t k);

private:
    void checkLeafSet(RegrTestApp* rta);

public: /* protected */
    virtual void checkRoutingTable(RegrTestApp* rta);

private:
    void initiateLeafSetMaintenance();
    void initiateRouteSetMaintenance();
    void killNodes(int32_t num);

public: /* protected */
    static void mainfunc(PastryRegrTest* pt, ::java::lang::StringArray* args, int32_t n, int32_t d, int32_t k, int32_t m, int32_t numConcJoins);

    // Generated
    PastryRegrTest(::rice::environment::Environment* env);
protected:
    PastryRegrTest(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
    friend class PastryRegrTest_checkLeafSet_DistComp_1;
};
