// Generated from /pastry-2.1/src/rice/pastry/socket/SocketPastryNodeFactory.java
#include <rice/pastry/socket/SocketPastryNodeFactory_getIpServiceTransportLayer_2_getNodeHandle_2_1.hpp>

#include <java/io/IOException.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <rice/Continuation.hpp>
#include <rice/p2p/util/rawserialization/SimpleInputBuffer.hpp>
#include <rice/pastry/NodeHandle.hpp>
#include <rice/pastry/NodeHandleFactory.hpp>
#include <rice/pastry/socket/SocketPastryNodeFactory_getIpServiceTransportLayer_2.hpp>
#include <rice/pastry/socket/SocketPastryNodeFactory.hpp>
#include <Array.hpp>

template<typename T, typename U>
static T java_cast(U* u)
{
    if(!u) return static_cast<T>(nullptr);
    auto t = dynamic_cast<T>(u);
    if(!t) throw new ::java::lang::ClassCastException();
    return t;
}

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::pastry::socket::SocketPastryNodeFactory_getIpServiceTransportLayer_2_getNodeHandle_2_1::SocketPastryNodeFactory_getIpServiceTransportLayer_2_getNodeHandle_2_1(SocketPastryNodeFactory_getIpServiceTransportLayer_2 *SocketPastryNodeFactory_getIpServiceTransportLayer_2_this, ::rice::pastry::PastryNode* pn, ::rice::Continuation* c)
    : super(*static_cast< ::default_init_tag* >(0))
    , SocketPastryNodeFactory_getIpServiceTransportLayer_2_this(SocketPastryNodeFactory_getIpServiceTransportLayer_2_this)
    , pn(pn)
    , c(c)
{
    clinit();
    ctor();
}

void rice::pastry::socket::SocketPastryNodeFactory_getIpServiceTransportLayer_2_getNodeHandle_2_1::receiveResult(::int8_tArray* result)
{
    try {
        auto nh = java_cast< ::rice::pastry::NodeHandle* >(npc(SocketPastryNodeFactory_getIpServiceTransportLayer_2_this->SocketPastryNodeFactory_this->getNodeHandleFactory(pn))->readNodeHandle(new ::rice::p2p::util::rawserialization::SimpleInputBuffer(result)));
        npc(c)->receiveResult(nh);
    } catch (::java::io::IOException* ioe) {
        npc(c)->receiveException(ioe);
    }
}

void rice::pastry::socket::SocketPastryNodeFactory_getIpServiceTransportLayer_2_getNodeHandle_2_1::receiveResult(::java::lang::Object* result)
{ 
    receiveResult(dynamic_cast< ::int8_tArray* >(result));
}

void rice::pastry::socket::SocketPastryNodeFactory_getIpServiceTransportLayer_2_getNodeHandle_2_1::receiveException(::java::io::IOException* exception)
{
    npc(c)->receiveException(exception);
}

void rice::pastry::socket::SocketPastryNodeFactory_getIpServiceTransportLayer_2_getNodeHandle_2_1::receiveException(::java::lang::Exception* exception)
{ 
    receiveException(dynamic_cast< ::java::io::IOException* >(exception));
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::socket::SocketPastryNodeFactory_getIpServiceTransportLayer_2_getNodeHandle_2_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::pastry::socket::SocketPastryNodeFactory_getIpServiceTransportLayer_2_getNodeHandle_2_1::getClass0()
{
    return class_();
}

