// Generated from /pastry-2.1/src/rice/pastry/socket/SPNFIdentitySerializer.java
#include <rice/pastry/socket/SPNFIdentitySerializer_addSerializerListener_1.hpp>

#include <java/lang/NullPointerException.hpp>
#include <org/mpisws/p2p/transport/identity/SerializerListener.hpp>
#include <rice/pastry/socket/SPNFIdentitySerializer.hpp>
#include <rice/pastry/socket/SocketNodeHandle.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::pastry::socket::SPNFIdentitySerializer_addSerializerListener_1::SPNFIdentitySerializer_addSerializerListener_1(SPNFIdentitySerializer *SPNFIdentitySerializer_this, ::org::mpisws::p2p::transport::identity::SerializerListener* listener)
    : super(*static_cast< ::default_init_tag* >(0))
    , SPNFIdentitySerializer_this(SPNFIdentitySerializer_this)
    , listener(listener)
{
    clinit();
    ctor();
}

void rice::pastry::socket::SPNFIdentitySerializer_addSerializerListener_1::nodeHandleFound(SocketNodeHandle* nodeHandle)
{
    npc(listener)->nodeHandleFound(nodeHandle);
}

void rice::pastry::socket::SPNFIdentitySerializer_addSerializerListener_1::nodeHandleFound(::rice::pastry::NodeHandle* nodeHandle)
{ 
    nodeHandleFound(dynamic_cast< SocketNodeHandle* >(nodeHandle));
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::socket::SPNFIdentitySerializer_addSerializerListener_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::pastry::socket::SPNFIdentitySerializer_addSerializerListener_1::getClass0()
{
    return class_();
}

