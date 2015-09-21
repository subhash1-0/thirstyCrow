// Generated from /pastry-2.1/src/rice/p2p/past/gc/GCPast.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/past/fwd-pastry-2.1.hpp>
#include <rice/p2p/past/gc/fwd-pastry-2.1.hpp>
#include <rice/p2p/past/Past.hpp>

template<typename ComponentType, typename... Bases> struct SubArray;
namespace java
{
    namespace io
    {
typedef ::SubArray< ::java::io::Serializable, ::java::lang::ObjectArray > SerializableArray;
    } // io

    namespace lang
    {
typedef ::SubArray< ::java::lang::Comparable, ObjectArray > ComparableArray;
    } // lang
} // java

namespace rice
{
    namespace p2p
    {
        namespace commonapi
        {
typedef ::SubArray< ::rice::p2p::commonapi::Id, ::java::lang::ObjectArray, ::java::lang::ComparableArray, ::java::io::SerializableArray > IdArray;
        } // commonapi
    } // p2p
} // rice

struct rice::p2p::past::gc::GCPast
    : public virtual ::rice::p2p::past::Past
{
    static constexpr int64_t INFINITY_EXPIRATION { int64_t(9223372036854775807LL) };
    /*void insert(::rice::p2p::past::PastContent* obj, ::rice::Continuation* command); (already declared) */
    virtual void insert(::rice::p2p::past::PastContent* obj, int64_t expiration, ::rice::Continuation* command) = 0;
    virtual void refresh(::rice::p2p::commonapi::IdArray* ids, ::int64_tArray* expiration, ::rice::Continuation* command) = 0;
    virtual void refresh(::rice::p2p::commonapi::IdArray* ids, int64_t expiration, ::rice::Continuation* command) = 0;

    // Generated
    static ::java::lang::Class *class_();
    virtual void insert(::rice::p2p::past::PastContent* obj, ::rice::Continuation* command) = 0;
};
