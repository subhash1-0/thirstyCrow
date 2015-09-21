// Generated from /pastry-2.1/src/rice/pastry/socket/EpochInetSocketAddress.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/net/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/pastry/socket/fwd-pastry-2.1.hpp>
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
typedef ::SubArray< ::java::net::InetAddress, ::java::lang::ObjectArray, ::java::io::SerializableArray > InetAddressArray;
typedef ::SubArray< ::java::net::SocketAddress, ::java::lang::ObjectArray, ::java::io::SerializableArray > SocketAddressArray;
typedef ::SubArray< ::java::net::InetSocketAddress, SocketAddressArray > InetSocketAddressArray;
    } // net
} // java

struct default_init_tag;

class rice::pastry::socket::EpochInetSocketAddress
    : public virtual ::java::lang::Object
    , public virtual ::java::io::Serializable
{

public:
    typedef ::java::lang::Object super;

private:
    static constexpr int64_t serialVersionUID { int64_t(2081191512212313338LL) };

public:
    static constexpr int64_t EPOCH_UNKNOWN { int64_t(-1LL) };

public: /* protected */
    ::java::net::InetSocketAddressArray* address {  };
    int64_t epoch {  };
protected:
    void ctor(::java::net::InetSocketAddress* address);
    void ctor(::java::net::InetSocketAddress* address, int64_t epoch);
    void ctor(::java::net::InetSocketAddressArray* addressList, int64_t epoch);

public:
    int32_t hashCode() override;
    bool equals(::java::lang::Object* o) override;
    virtual bool addressEquals(EpochInetSocketAddress* that);
    ::java::lang::String* toString() override;
    virtual ::java::net::InetSocketAddress* getAddress(EpochInetSocketAddress* local);
    virtual ::java::net::InetSocketAddress* getAddress(::java::net::InetAddressArray* local);
    virtual ::java::net::InetSocketAddress* getInnermostAddress();
    virtual int64_t getEpoch();
    static EpochInetSocketAddress* build(::rice::p2p::commonapi::rawserialization::InputBuffer* buf) /* throws(IOException) */;
    virtual void serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */;
    virtual int16_t getSerializedLength();

    // Generated
    EpochInetSocketAddress(::java::net::InetSocketAddress* address);
    EpochInetSocketAddress(::java::net::InetSocketAddress* address, int64_t epoch);
    EpochInetSocketAddress(::java::net::InetSocketAddressArray* addressList, int64_t epoch);
protected:
    EpochInetSocketAddress(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
