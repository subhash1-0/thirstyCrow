// Generated from /pastry-2.1/src/rice/pastry/pns/PNSApplication.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/leafset/fwd-pastry-2.1.hpp>
#include <rice/pastry/messaging/fwd-pastry-2.1.hpp>
#include <rice/pastry/pns/fwd-pastry-2.1.hpp>
#include <rice/pastry/routing/fwd-pastry-2.1.hpp>
#include <rice/selector/fwd-pastry-2.1.hpp>
#include <rice/pastry/client/PastryAppl.hpp>
#include <rice/pastry/standard/ProximityNeighborSelector.hpp>
#include <org/mpisws/p2p/transport/proximity/ProximityListener.hpp>

template<typename ComponentType, typename... Bases> struct SubArray;
namespace java
{
    namespace io
    {
typedef ::SubArray< ::java::io::Serializable, ::java::lang::ObjectArray > SerializableArray;
    } // io

    namespace lang
    {
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
        } // routing
    } // pastry
} // rice

struct default_init_tag;

class rice::pastry::pns::PNSApplication
    : public ::rice::pastry::client::PastryAppl
    , public virtual ::rice::pastry::standard::ProximityNeighborSelector
    , public virtual ::org::mpisws::p2p::transport::proximity::ProximityListener
{

public:
    typedef ::rice::pastry::client::PastryAppl super;
    static constexpr int32_t DEFAULT_PROXIMITY { int32_t(3600000) };

public: /* protected */
    ::java::util::Map* pingCache {  };
    int8_t rtBase {  };
    ::rice::environment::Environment* environment {  };
    ::rice::selector::Timer* timer {  };

public: /* package */
    int16_t depth {  };
protected:
    void ctor(::rice::pastry::PastryNode* pn);
    void ctor(::rice::pastry::PastryNode* pn, ::rice::environment::logging::Logger* logger);

public:
    bool deliverWhenNotReady() override;
    void messageForAppl(::rice::pastry::messaging::Message* msg) override;
    ::rice::p2p::commonapi::Cancellable* getNearHandles(::java::util::Collection* bootHandles, ::rice::Continuation* deliverResultToMe) override;

public: /* protected */
    virtual ::java::util::List* getNearHandlesHelper(::java::util::List* handles);

public:
    virtual ::rice::p2p::commonapi::Cancellable* getLeafSet(::rice::pastry::NodeHandle* handle, ::rice::Continuation* c);

public: /* package */
    ::java::util::Map* waitingForLeafSet {  };

public: /* protected */
    virtual void addToWaitingForLeafSet(::rice::pastry::NodeHandle* handle, ::rice::Continuation* c, ::rice::p2p::commonapi::Cancellable* cancelMeWhenSuccess);
    virtual bool removeFromWaitingForLeafSet(::rice::pastry::NodeHandle* handle, ::rice::Continuation* c);

public:
    virtual ::rice::p2p::commonapi::Cancellable* getRouteRow(::rice::pastry::NodeHandle* handle, int16_t row, ::rice::Continuation* c);

public: /* package */
    ::java::util::Map* waitingForRouteRow {  };

public: /* protected */
    virtual void addToWaitingForRouteRow(::rice::pastry::NodeHandle* handle, int32_t row, ::rice::Continuation* c, ::rice::p2p::commonapi::Cancellable* cancelMeWhenSuccess);
    virtual bool removeFromWaitingForRouteRow(::rice::pastry::NodeHandle* handle, int32_t row, ::rice::Continuation* c);

public:
    virtual ::rice::p2p::commonapi::Cancellable* getProximity(::rice::pastry::NodeHandle* handle, ::rice::Continuation* c, int32_t timeout);

public: /* package */
    ::java::util::Map* waitingForPing {  };

public:
    virtual void proximityChanged(::rice::pastry::NodeHandle* i, int32_t newProximity, ::java::util::Map* options);

private:
    void purgeProximityCache();

public:
    virtual ::java::util::List* sortedProximityCache();
    virtual ::rice::p2p::commonapi::Cancellable* getNearest(::rice::pastry::NodeHandle* seed, ::rice::Continuation* retToMe);

private:
    ::rice::p2p::commonapi::Cancellable* seekThroughRouteRows(int16_t i, int16_t depth, ::rice::pastry::NodeHandle* currentClosest, ::rice::Continuation* returnToMe);
    ::rice::p2p::commonapi::Cancellable* closestToMe(::rice::pastry::NodeHandle* handle, ::rice::pastry::leafset::LeafSet* leafSet, ::rice::Continuation* c);
    ::rice::p2p::commonapi::Cancellable* closestToMe(::rice::pastry::NodeHandle* handle, ::rice::pastry::routing::RouteSetArray* routeSets, ::rice::Continuation* c);
    ::rice::p2p::commonapi::Cancellable* closestToMe(::rice::pastry::NodeHandle* handle, ::java::util::Collection* handles, ::rice::Continuation* c);

    // Generated

public:
    PNSApplication(::rice::pastry::PastryNode* pn);
    PNSApplication(::rice::pastry::PastryNode* pn, ::rice::environment::logging::Logger* logger);
protected:
    PNSApplication(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    void init();

public:
    virtual void proximityChanged(::java::lang::Object* i, int32_t newProximity, ::java::util::Map* options) override;
    virtual ::rice::pastry::leafset::LeafSet* getLeafSet();

private:
    virtual ::java::lang::Class* getClass0();
    friend class PNSApplication_getNearHandles_1;
    friend class PNSApplication_getNearHandles_1_receiveResult_1_1;
    friend class PNSApplication_getLeafSet_2;
    friend class PNSApplication_getLeafSet_3;
    friend class PNSApplication_getLeafSet_4;
    friend class PNSApplication_getRouteRow_5;
    friend class PNSApplication_getRouteRow_6;
    friend class PNSApplication_getRouteRow_7;
    friend class PNSApplication_getProximity_8;
    friend class PNSApplication_getProximity_9;
    friend class PNSApplication_sortedProximityCache_10;
    friend class PNSApplication_getNearest_11;
    friend class PNSApplication_getNearest_12;
    friend class PNSApplication_getNearest_12_receiveResult_12_1;
    friend class PNSApplication_getNearest_12_receiveResult_12_1_receiveResult_12_1_1;
    friend class PNSApplication_seekThroughRouteRows_13;
    friend class PNSApplication_seekThroughRouteRows_13_receiveResult_13_1;
    friend class PNSApplication_closestToMe_14;
    friend class PNSApplication_PNSDeserializer;
};
