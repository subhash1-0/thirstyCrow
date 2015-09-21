// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/multiaddress/MultiInetSocketAddress.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/net/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/multiaddress/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/simpleidentity/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <java/io/Serializable.hpp>

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

class org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress
    : public virtual ::java::lang::Object
    , public virtual ::java::io::Serializable
{

public:
    typedef ::java::lang::Object super;

private:
    static ::org::mpisws::p2p::transport::simpleidentity::InetSocketAddressSerializer* serializer_;

public: /* protected */
    ::java::net::InetSocketAddressArray* address {  };
protected:
    void ctor(::java::net::InetSocketAddress* address);
    void ctor(::java::net::InetSocketAddressArray* addressList);
    void ctor(::java::net::InetSocketAddress* outer, ::java::net::InetSocketAddress* inner);

public:
    int32_t hashCode() override;
    bool equals(::java::lang::Object* o) override;
    virtual bool addressEquals(MultiInetSocketAddress* that);
    ::java::lang::String* toString() override;
    virtual void toStringShort(::java::lang::StringBuffer* result);
    virtual ::java::net::InetSocketAddress* getInnermostAddress();
    virtual ::java::net::InetSocketAddress* getOutermostAddress();
    virtual int32_t getNumAddresses();
    virtual ::java::net::InetSocketAddress* getAddress(int32_t index);
    static MultiInetSocketAddress* build(::rice::p2p::commonapi::rawserialization::InputBuffer* buf) /* throws(IOException) */;
    virtual void serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */;
    virtual int16_t getSerializedLength();

    // Generated
    MultiInetSocketAddress(::java::net::InetSocketAddress* address);
    MultiInetSocketAddress(::java::net::InetSocketAddressArray* addressList);
    MultiInetSocketAddress(::java::net::InetSocketAddress* outer, ::java::net::InetSocketAddress* inner);
protected:
    MultiInetSocketAddress(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    static void clinit();

public: /* package */
    static ::org::mpisws::p2p::transport::simpleidentity::InetSocketAddressSerializer*& serializer();

private:
    virtual ::java::lang::Class* getClass0();
};
