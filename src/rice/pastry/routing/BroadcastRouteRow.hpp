// Generated from /pastry-2.1/src/rice/pastry/routing/BroadcastRouteRow.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/routing/fwd-pastry-2.1.hpp>
#include <rice/pastry/messaging/PRawMessage.hpp>
#include <java/io/Serializable.hpp>

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

class rice::pastry::routing::BroadcastRouteRow
    : public ::rice::pastry::messaging::PRawMessage
    , public virtual ::java::io::Serializable
{

public:
    typedef ::rice::pastry::messaging::PRawMessage super;

private:
    ::rice::pastry::NodeHandle* fromNode {  };
    RouteSetArray* row {  };

public:
    static constexpr int16_t TYPE { int16_t(2) };
protected:
    void ctor(::java::util::Date* stamp, ::rice::pastry::NodeHandle* from, RouteSetArray* r);
    void ctor(::rice::pastry::NodeHandle* from, RouteSetArray* r);

public:
    virtual ::rice::pastry::NodeHandle* from();
    virtual RouteSetArray* getRow();
    ::java::lang::String* toString() override;
    virtual ::java::lang::String* toStringFull();
    int16_t getType() override;
    void serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */ override;
protected:
    void ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::pastry::NodeHandleFactory* nhf, ::rice::pastry::PastryNode* localNode) /* throws(IOException) */;

    // Generated

public:
    BroadcastRouteRow(::java::util::Date* stamp, ::rice::pastry::NodeHandle* from, RouteSetArray* r);
    BroadcastRouteRow(::rice::pastry::NodeHandle* from, RouteSetArray* r);
    BroadcastRouteRow(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::pastry::NodeHandleFactory* nhf, ::rice::pastry::PastryNode* localNode);
protected:
    BroadcastRouteRow(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
