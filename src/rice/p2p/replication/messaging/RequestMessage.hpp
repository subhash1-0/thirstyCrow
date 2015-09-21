// Generated from /pastry-2.1/src/rice/p2p/replication/messaging/RequestMessage.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/p2p/replication/messaging/fwd-pastry-2.1.hpp>
#include <rice/p2p/util/fwd-pastry-2.1.hpp>
#include <rice/p2p/replication/messaging/ReplicationMessage.hpp>

template<typename ComponentType, typename... Bases> struct SubArray;
namespace java
{
    namespace io
    {
typedef ::SubArray< ::java::io::Serializable, ::java::lang::ObjectArray > SerializableArray;
    } // io
} // java

namespace rice
{
    namespace p2p
    {
        namespace commonapi
        {
typedef ::SubArray< ::rice::p2p::commonapi::IdRange, ::java::lang::ObjectArray, ::java::io::SerializableArray > IdRangeArray;
        } // commonapi

        namespace util
        {
typedef ::SubArray< ::rice::p2p::util::IdBloomFilter, ::java::lang::ObjectArray, ::java::io::SerializableArray > IdBloomFilterArray;
        } // util
    } // p2p
} // rice

struct default_init_tag;

class rice::p2p::replication::messaging::RequestMessage
    : public ReplicationMessage
{

public:
    typedef ReplicationMessage super;
    static constexpr int16_t TYPE { int16_t(2) };

public: /* protected */
    ::rice::p2p::commonapi::IdRangeArray* ranges {  };
    ::rice::p2p::util::IdBloomFilterArray* filters {  };
protected:
    void ctor(::rice::p2p::commonapi::NodeHandle* source, ::rice::p2p::commonapi::IdRangeArray* ranges, ::rice::p2p::util::IdBloomFilterArray* filters);

public:
    virtual ::rice::p2p::commonapi::IdRangeArray* getRanges();
    virtual ::rice::p2p::util::IdBloomFilterArray* getFilters();
    ::java::lang::String* toString() override;
    int16_t getType() override;
    void serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */ override;
    static RequestMessage* build(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint) /* throws(IOException) */;
protected:
    void ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint) /* throws(IOException) */;

    // Generated

public:
    RequestMessage(::rice::p2p::commonapi::NodeHandle* source, ::rice::p2p::commonapi::IdRangeArray* ranges, ::rice::p2p::util::IdBloomFilterArray* filters);

private:
    RequestMessage(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint);
protected:
    RequestMessage(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
