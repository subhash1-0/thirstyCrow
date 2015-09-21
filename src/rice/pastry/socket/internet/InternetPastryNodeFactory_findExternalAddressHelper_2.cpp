// Generated from /pastry-2.1/src/rice/pastry/socket/internet/InternetPastryNodeFactory.java
#include <rice/pastry/socket/internet/InternetPastryNodeFactory_findExternalAddressHelper_2.hpp>

#include <java/io/IOException.hpp>
#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/net/InetAddress.hpp>
#include <rice/Continuation.hpp>
#include <rice/pastry/socket/internet/InternetPastryNodeFactory.hpp>
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
typedef ::SubArray< ::java::net::InetAddress, ::java::lang::ObjectArray, ::java::io::SerializableArray > InetAddressArray;
    } // net
} // java

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::pastry::socket::internet::InternetPastryNodeFactory_findExternalAddressHelper_2::InternetPastryNodeFactory_findExternalAddressHelper_2(InternetPastryNodeFactory *InternetPastryNodeFactory_this, ::rice::Continuation* deliverResultToMe, ::rice::pastry::Id* nodeId, ::java::net::InetSocketAddress* bindAddress)
    : super(*static_cast< ::default_init_tag* >(0))
    , InternetPastryNodeFactory_this(InternetPastryNodeFactory_this)
    , deliverResultToMe(deliverResultToMe)
    , nodeId(nodeId)
    , bindAddress(bindAddress)
{
    clinit();
    ctor();
}

void rice::pastry::socket::internet::InternetPastryNodeFactory_findExternalAddressHelper_2::receiveResult(::java::net::InetAddress* result)
{
    if(InternetPastryNodeFactory_this->externalAddresses != nullptr) {
        if(!npc((*InternetPastryNodeFactory_this->externalAddresses)[int32_t(0)])->equals(static_cast< ::java::lang::Object* >(result))) {
            npc(deliverResultToMe)->receiveException(new ::java::io::IOException(::java::lang::StringBuilder().append(u"Probe address ("_j)->append(static_cast< ::java::lang::Object* >(result))
                ->append(u") does not match specified externalAddress ("_j)
                ->append(static_cast< ::java::lang::Object* >((*InternetPastryNodeFactory_this->externalAddresses)[int32_t(0)]))
                ->append(u")."_j)->toString()));
            return;
        }
    }
    InternetPastryNodeFactory_this->openFirewallPort(nodeId, bindAddress, deliverResultToMe, result, -int32_t(1));
}

void rice::pastry::socket::internet::InternetPastryNodeFactory_findExternalAddressHelper_2::receiveResult(::java::lang::Object* result)
{ 
    receiveResult(dynamic_cast< ::java::net::InetAddress* >(result));
}

void rice::pastry::socket::internet::InternetPastryNodeFactory_findExternalAddressHelper_2::receiveException(::java::io::IOException* exception)
{
    npc(deliverResultToMe)->receiveException(exception);
}

void rice::pastry::socket::internet::InternetPastryNodeFactory_findExternalAddressHelper_2::receiveException(::java::lang::Exception* exception)
{ 
    receiveException(dynamic_cast< ::java::io::IOException* >(exception));
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::socket::internet::InternetPastryNodeFactory_findExternalAddressHelper_2::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::pastry::socket::internet::InternetPastryNodeFactory_findExternalAddressHelper_2::getClass0()
{
    return class_();
}

