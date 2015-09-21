// Generated from /pastry-2.1/src/rice/pastry/transport/BogusNodeHandle.java
#include <rice/pastry/transport/BogusNodeHandle.hpp>

#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/IllegalStateException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/net/InetSocketAddress.hpp>
#include <java/net/SocketAddress.hpp>
#include <java/util/Arrays.hpp>
#include <java/util/Collection.hpp>
#include <java/util/Collections.hpp>
#include <java/util/List.hpp>
#include <SubArray.hpp>
#include <ObjectArray.hpp>

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

rice::pastry::transport::BogusNodeHandle::BogusNodeHandle(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::transport::BogusNodeHandle::BogusNodeHandle(::java::net::InetSocketAddress* address) 
    : BogusNodeHandle(*static_cast< ::default_init_tag* >(0))
{
    ctor(address);
}

rice::pastry::transport::BogusNodeHandle::BogusNodeHandle(::java::net::InetSocketAddressArray* bootstraps) 
    : BogusNodeHandle(*static_cast< ::default_init_tag* >(0))
{
    ctor(bootstraps);
}

void rice::pastry::transport::BogusNodeHandle::ctor(::java::net::InetSocketAddress* address)
{
    super::ctor();
    addresses = ::java::util::Collections::singletonList(address);
}

void rice::pastry::transport::BogusNodeHandle::ctor(::java::net::InetSocketAddressArray* bootstraps)
{
    super::ctor();
    addresses = ::java::util::Arrays::asList(bootstraps);
}

bool rice::pastry::transport::BogusNodeHandle::equals(::java::lang::Object* obj)
{
    throw new ::java::lang::IllegalStateException(u"This NodeHandle is Bogus, don't use it."_j);
}

int32_t rice::pastry::transport::BogusNodeHandle::getLiveness()
{
    throw new ::java::lang::IllegalStateException(u"This NodeHandle is Bogus, don't use it."_j);
}

rice::pastry::Id* rice::pastry::transport::BogusNodeHandle::getNodeId()
{
    throw new ::java::lang::IllegalStateException(u"This NodeHandle is Bogus, don't use it."_j);
}

java::lang::String* rice::pastry::transport::BogusNodeHandle::toString()
{
    return ::java::lang::StringBuilder().append(u"BogusNodeHandle "_j)->append(static_cast< ::java::lang::Object* >(addresses))->toString();
}

int32_t rice::pastry::transport::BogusNodeHandle::hashCode()
{
    throw new ::java::lang::IllegalStateException(u"This NodeHandle is Bogus, don't use it."_j);
}

bool rice::pastry::transport::BogusNodeHandle::ping()
{
    throw new ::java::lang::IllegalStateException(u"This NodeHandle is Bogus, don't use it."_j);
}

int32_t rice::pastry::transport::BogusNodeHandle::proximity()
{
    throw new ::java::lang::IllegalStateException(u"This NodeHandle is Bogus, don't use it."_j);
}

void rice::pastry::transport::BogusNodeHandle::receiveMessage(::rice::pastry::messaging::Message* msg)
{
    throw new ::java::lang::IllegalStateException(u"This NodeHandle is Bogus, don't use it."_j);
}

void rice::pastry::transport::BogusNodeHandle::serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */
{
    throw new ::java::lang::IllegalStateException(u"This NodeHandle is Bogus, don't use it."_j);
}

java::util::Collection* rice::pastry::transport::BogusNodeHandle::getAddress()
{
    return addresses;
}

int64_t rice::pastry::transport::BogusNodeHandle::getEpoch()
{
    return 0;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::transport::BogusNodeHandle::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.transport.BogusNodeHandle", 37);
    return c;
}

java::lang::Class* rice::pastry::transport::BogusNodeHandle::getClass0()
{
    return class_();
}

