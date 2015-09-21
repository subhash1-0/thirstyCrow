// Generated from /pastry-2.1/src/rice/pastry/socket/nat/rendezvous/RendezvousPNSApplication.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/routing/fwd-pastry-2.1.hpp>
#include <rice/pastry/socket/nat/rendezvous/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/Continuation.hpp>

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

class rice::pastry::socket::nat::rendezvous::RendezvousPNSApplication_getRouteRow_2
    : public virtual ::java::lang::Object
    , public virtual ::rice::Continuation
{

public:
    typedef ::java::lang::Object super;
    virtual void receiveResult(::rice::pastry::routing::RouteSetArray* result);
    void receiveException(::java::lang::Exception* exception) override;

    // Generated
    RendezvousPNSApplication_getRouteRow_2(RendezvousPNSApplication *RendezvousPNSApplication_this, ::rice::pastry::NodeHandle* input, int16_t row, ::rice::Continuation* c);
    static ::java::lang::Class *class_();
    virtual void receiveResult(::java::lang::Object* result) override;
    RendezvousPNSApplication *RendezvousPNSApplication_this;
    ::rice::pastry::NodeHandle* input;
    int16_t row;
    ::rice::Continuation* c;

private:
    virtual ::java::lang::Class* getClass0();
    friend class RendezvousPNSApplication;
    friend class RendezvousPNSApplication_getLeafSet_1;
};
