// Generated from /pastry-2.1/src/rice/p2p/past/gc/messaging/GCRefreshMessage.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/p2p/past/gc/fwd-pastry-2.1.hpp>
#include <rice/p2p/past/gc/messaging/fwd-pastry-2.1.hpp>
#include <rice/p2p/past/messaging/ContinuationMessage.hpp>

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

        namespace past
        {
            namespace gc
            {
typedef ::SubArray< ::rice::p2p::past::gc::GCId, ::java::lang::ObjectArray, ::rice::p2p::commonapi::IdArray > GCIdArray;
            } // gc
        } // past
    } // p2p
} // rice

struct default_init_tag;

class rice::p2p::past::gc::messaging::GCRefreshMessage
    : public ::rice::p2p::past::messaging::ContinuationMessage
{

public:
    typedef ::rice::p2p::past::messaging::ContinuationMessage super;
    static constexpr int16_t TYPE { int16_t(11) };

public: /* protected */
    ::rice::p2p::past::gc::GCIdArray* keys {  };
protected:
    void ctor(int32_t uid, ::rice::p2p::past::gc::GCIdSet* keys, ::rice::p2p::commonapi::NodeHandle* source, ::rice::p2p::commonapi::Id* dest);

public:
    virtual ::rice::p2p::past::gc::GCIdArray* getKeys();
    ::java::lang::String* toString() override;
    int16_t getType() override;
    void serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */ override;
    static GCRefreshMessage* build(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint) /* throws(IOException) */;
protected:
    void ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint) /* throws(IOException) */;

    // Generated

public:
    GCRefreshMessage(int32_t uid, ::rice::p2p::past::gc::GCIdSet* keys, ::rice::p2p::commonapi::NodeHandle* source, ::rice::p2p::commonapi::Id* dest);

private:
    GCRefreshMessage(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint);
protected:
    GCRefreshMessage(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    virtual void serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf, bool javaSerialize);

private:
    virtual ::java::lang::Class* getClass0();
};
