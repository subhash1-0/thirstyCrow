// Generated from /pastry-2.1/src/rice/pastry/socket/internet/InternetPastryNodeFactory.java
#include <rice/pastry/socket/internet/InternetPastryNodeFactory_findExternalNodes_1.hpp>

#include <java/io/IOException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/util/Collection.hpp>
#include <rice/pastry/socket/internet/InternetPastryNodeFactory.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::pastry::socket::internet::InternetPastryNodeFactory_findExternalNodes_1::InternetPastryNodeFactory_findExternalNodes_1(InternetPastryNodeFactory *InternetPastryNodeFactory_this, ::rice::pastry::Id* nodeId, ::java::net::InetSocketAddress* bindAddress, ::rice::Continuation* deliverResultToMe, ::java::util::Collection* nonInternetRoutable)
    : super(*static_cast< ::default_init_tag* >(0))
    , InternetPastryNodeFactory_this(InternetPastryNodeFactory_this)
    , nodeId(nodeId)
    , bindAddress(bindAddress)
    , deliverResultToMe(deliverResultToMe)
    , nonInternetRoutable(nonInternetRoutable)
{
    clinit();
    ctor();
}

void rice::pastry::socket::internet::InternetPastryNodeFactory_findExternalNodes_1::receiveResult(::java::util::Collection* result)
{
    InternetPastryNodeFactory_this->findExternalAddressHelper(nodeId, bindAddress, deliverResultToMe, result);
}

void rice::pastry::socket::internet::InternetPastryNodeFactory_findExternalNodes_1::receiveResult(::java::lang::Object* result)
{ 
    receiveResult(dynamic_cast< ::java::util::Collection* >(result));
}

void rice::pastry::socket::internet::InternetPastryNodeFactory_findExternalNodes_1::receiveException(::java::io::IOException* exception)
{
    if(nonInternetRoutable == nullptr || npc(nonInternetRoutable)->isEmpty())
        InternetPastryNodeFactory_this->findExternalAddressHelper(nodeId, bindAddress, deliverResultToMe, nullptr);

}

void rice::pastry::socket::internet::InternetPastryNodeFactory_findExternalNodes_1::receiveException(::java::lang::Exception* exception)
{ 
    receiveException(dynamic_cast< ::java::io::IOException* >(exception));
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::socket::internet::InternetPastryNodeFactory_findExternalNodes_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::pastry::socket::internet::InternetPastryNodeFactory_findExternalNodes_1::getClass0()
{
    return class_();
}

