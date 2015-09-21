// Generated from /pastry-2.1/src/rice/pastry/routing/RoutingTable.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/routing/fwd-pastry-2.1.hpp>
#include <java/util/Observable.hpp>
#include <rice/pastry/NodeSetEventSource.hpp>

template<typename ComponentType, typename... Bases> struct SubArray;
namespace java
{
    namespace io
    {
typedef ::SubArray< ::java::io::Serializable, ::java::lang::ObjectArray > SerializableArray;
    } // io

    namespace lang
    {
typedef ::SubArray< ::java::lang::Cloneable, ObjectArray > CloneableArray;
typedef ::SubArray< ::java::lang::Iterable, ObjectArray > IterableArray;
    } // lang

    namespace util
    {
typedef ::SubArray< ::java::util::Observer, ::java::lang::ObjectArray > ObserverArray;
    } // util
} // java

namespace rice
{
    namespace p2p
    {
        namespace commonapi
        {
typedef ::SubArray< ::rice::p2p::commonapi::NodeHandleSet, ::java::lang::ObjectArray, ::java::io::SerializableArray > NodeHandleSetArray;
        } // commonapi
    } // p2p

    namespace pastry
    {
typedef ::SubArray< ::rice::pastry::NodeSetI, ::java::lang::ObjectArray, ::rice::p2p::commonapi::NodeHandleSetArray > NodeSetIArray;

        namespace routing
        {
typedef ::SubArray< ::rice::pastry::routing::RouteSet, ::java::lang::ObjectArray, ::rice::pastry::NodeSetIArray, ::java::io::SerializableArray, ::java::util::ObserverArray, ::java::lang::IterableArray > RouteSetArray;
typedef ::SubArray< ::rice::pastry::routing::RouteSetArray, ::java::lang::CloneableArray, ::java::io::SerializableArray > RouteSetArrayArray;
        } // routing
    } // pastry
} // rice

struct default_init_tag;

class rice::pastry::routing::RoutingTable
    : public ::java::util::Observable
    , public virtual ::rice::pastry::NodeSetEventSource
{

public:
    typedef ::java::util::Observable super;
    int8_t idBaseBitLength {  };

private:
    ::rice::pastry::Id* myNodeId {  };

public:
    ::rice::pastry::NodeHandle* myNodeHandle {  };

public: /* protected */
    ::rice::pastry::PastryNode* pn {  };

private:
    RouteSetArrayArray* routingTable {  };
    int32_t maxEntries {  };

public: /* package */
    ::rice::environment::logging::Logger* logger {  };
    int32_t cols {  }, rows {  };
protected:
    void ctor(::rice::pastry::NodeHandle* me, int32_t max, int8_t base, ::rice::pastry::PastryNode* pn);

public:
    virtual int32_t numColumns();
    virtual int16_t numRows();
    virtual int8_t baseBitLength();
    virtual ::rice::pastry::NodeHandle* bestAlternateRoute(::rice::pastry::Id* key);
    virtual ::rice::pastry::NodeHandle* bestAlternateRoute(int32_t minLiveness, ::rice::pastry::Id* key);
    virtual ::rice::pastry::NodeSet* alternateRoutes(::rice::pastry::Id* key, int32_t max);
    virtual ::java::util::Iterator* alternateRoutesIterator(::rice::pastry::Id* key);
    virtual RouteSet* getRouteSet(int32_t index, int32_t digit);
    virtual RouteSet* getBestEntry(::rice::pastry::Id* key);

private:
    RouteSet* makeBestEntry(::rice::pastry::Id* key);

public:
    virtual bool put(::rice::pastry::NodeHandle* handle);
    static constexpr int32_t TEST_FAIL_NO_PREFIX_MATCH { int32_t(-1) };
    static constexpr int32_t TEST_FAIL_EXISTING_ARE_BETTER { int32_t(0) };
    static constexpr int32_t TEST_SUCCESS_BETTER_PROXIMITY { int32_t(1) };
    static constexpr int32_t TEST_SUCCESS_ENTRY_WAS_DEAD { int32_t(2) };
    static constexpr int32_t TEST_SUCCESS_AVAILABLE_SPACE { int32_t(3) };
    static constexpr int32_t TEST_SUCCESS_NO_ENTRIES { int32_t(4) };
    virtual int32_t test(::rice::pastry::NodeHandle* handle);
    virtual ::rice::pastry::NodeHandle* get(::rice::pastry::Id* nid);
    virtual RouteSetArray* getRow(int32_t i);
    virtual ::rice::pastry::NodeHandle* remove(::rice::pastry::NodeHandle* nh);
    virtual void nodeSetUpdate(::java::lang::Object* o, ::rice::pastry::NodeHandle* handle, bool added);
    ::java::lang::String* toString() override;
    virtual ::java::lang::String* printSelf();
    virtual int32_t numEntries();
    virtual int32_t numUniqueEntries();

public: /* package */
    ::java::util::ArrayList* listeners {  };

public:
    void addObserver(::java::util::Observer* o) override;
    void deleteObserver(::java::util::Observer* o) override;
    void addNodeSetListener(::rice::pastry::NodeSetListener* listener) override;
    void removeNodeSetListener(::rice::pastry::NodeSetListener* listener) override;
    virtual ::java::util::List* asList();
    virtual void destroy();

    // Generated
    RoutingTable(::rice::pastry::NodeHandle* me, int32_t max, int8_t base, ::rice::pastry::PastryNode* pn);
protected:
    RoutingTable(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    void init();
    virtual ::java::lang::Class* getClass0();
    friend class RoutingTable_alternateRoutesIterator_1;
};
