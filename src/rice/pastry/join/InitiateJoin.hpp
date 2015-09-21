// Generated from /pastry-2.1/src/rice/pastry/join/InitiateJoin.java

#pragma once

#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/join/fwd-pastry-2.1.hpp>
#include <rice/pastry/messaging/Message.hpp>
#include <java/io/Serializable.hpp>

template<typename ComponentType, typename... Bases> struct SubArray;
namespace java
{
    namespace io
    {
typedef ::SubArray< ::java::io::Serializable, ::java::lang::ObjectArray > SerializableArray;
    } // io

    namespace util
    {
typedef ::SubArray< ::java::util::Observable, ::java::lang::ObjectArray > ObservableArray;
    } // util
} // java

namespace rice
{
    namespace p2p
    {
        namespace commonapi
        {
typedef ::SubArray< ::rice::p2p::commonapi::NodeHandle, ::java::util::ObservableArray, ::java::io::SerializableArray > NodeHandleArray;

            namespace rawserialization
            {
typedef ::SubArray< ::rice::p2p::commonapi::rawserialization::RawSerializable, ::java::lang::ObjectArray > RawSerializableArray;
            } // rawserialization
        } // commonapi
    } // p2p

    namespace pastry
    {
typedef ::SubArray< ::rice::pastry::NodeHandle, ::rice::p2p::commonapi::NodeHandleArray, ::rice::p2p::commonapi::rawserialization::RawSerializableArray > NodeHandleArray;
    } // pastry
} // rice

struct default_init_tag;

class rice::pastry::join::InitiateJoin
    : public ::rice::pastry::messaging::Message
    , public virtual ::java::io::Serializable
{

public:
    typedef ::rice::pastry::messaging::Message super;

private:
    ::rice::pastry::NodeHandleArray* handle {  };
protected:
    void ctor(::java::util::Collection* nh);
    void ctor(::java::util::Date* stamp, ::java::util::Collection* nh);

public:
    virtual ::rice::pastry::NodeHandle* getHandle();
    ::java::lang::String* toString() override;

    // Generated
    InitiateJoin(::java::util::Collection* nh);
    InitiateJoin(::java::util::Date* stamp, ::java::util::Collection* nh);
protected:
    InitiateJoin(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
