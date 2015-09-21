// Generated from /pastry-2.1/src/rice/pastry/transport/BogusNodeHandle.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/net/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/messaging/fwd-pastry-2.1.hpp>
#include <rice/pastry/transport/fwd-pastry-2.1.hpp>
#include <rice/pastry/socket/TransportLayerNodeHandle.hpp>
#include <java/util/Collection.hpp>

template<typename ComponentType, typename... Bases> struct SubArray;
namespace java
{
    namespace io
    {
typedef ::SubArray< ::java::io::Serializable, ::java::lang::ObjectArray > SerializableArray;
    } // io

    namespace net
    {
typedef ::SubArray< ::java::net::SocketAddress, ::java::lang::ObjectArray, ::java::io::SerializableArray > SocketAddressArray;
typedef ::SubArray< ::java::net::InetSocketAddress, SocketAddressArray > InetSocketAddressArray;
    } // net
} // java

struct default_init_tag;

class rice::pastry::transport::BogusNodeHandle
    : public ::rice::pastry::socket::TransportLayerNodeHandle
{

public:
    typedef ::rice::pastry::socket::TransportLayerNodeHandle super;
    ::java::util::Collection* addresses {  };
protected:
    void ctor(::java::net::InetSocketAddress* address);
    void ctor(::java::net::InetSocketAddressArray* bootstraps);

public:
    bool equals(::java::lang::Object* obj) override;
    int32_t getLiveness() override;
    ::rice::pastry::Id* getNodeId() override;
    ::java::lang::String* toString() override;
    int32_t hashCode() override;
    bool ping() override;
    int32_t proximity() override;
    void receiveMessage(::rice::pastry::messaging::Message* msg) override;
    void serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */ override;
    ::java::util::Collection* getAddress() override;
    int64_t getEpoch() override;

    // Generated
    BogusNodeHandle(::java::net::InetSocketAddress* address);
    BogusNodeHandle(::java::net::InetSocketAddressArray* bootstraps);
protected:
    BogusNodeHandle(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
