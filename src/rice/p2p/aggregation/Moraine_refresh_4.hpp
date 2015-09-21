// Generated from /pastry-2.1/src/rice/p2p/aggregation/Moraine.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/fwd-pastry-2.1.hpp>
#include <rice/p2p/aggregation/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
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

struct default_init_tag;

class rice::p2p::aggregation::Moraine_refresh_4
    : public virtual ::java::lang::Object
    , public virtual ::rice::Continuation
{

public:
    typedef ::java::lang::Object super;
    void receiveResult(::java::lang::Object* result) override;
    void receiveException(::java::lang::Exception* result) override;

    // Generated
    Moraine_refresh_4(Moraine *Moraine_this, ::rice::p2p::commonapi::IdArray* ids, ::int64_tArray* expirations, ::rice::Continuation* command);
    static ::java::lang::Class *class_();
    Moraine *Moraine_this;
    ::rice::p2p::commonapi::IdArray* ids;
    ::int64_tArray* expirations;
    ::rice::Continuation* command;

private:
    virtual ::java::lang::Class* getClass0();
    friend class Moraine;
    friend class Moraine_lookup_1;
    friend class Moraine_lookup_1_receiveResult_1_1;
    friend class Moraine_lookupHandles_2;
    friend class Moraine_fetch_3;
    friend class Moraine_lookup_5;
    friend class Moraine_lookup_5_receiveResult_5_1;
    friend class Moraine_lookupHandles_6;
    friend class Moraine_refresh_7;
};
