// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/wire/exception/StalledSocketException.java
#include <org/mpisws/p2p/transport/wire/exception/StalledSocketException.hpp>

#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/net/InetSocketAddress.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::transport::wire::exception::StalledSocketException::StalledSocketException(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::transport::wire::exception::StalledSocketException::StalledSocketException(::java::lang::Object* addr, ::java::lang::String* s) 
    : StalledSocketException(*static_cast< ::default_init_tag* >(0))
{
    ctor(addr,s);
}

org::mpisws::p2p::transport::wire::exception::StalledSocketException::StalledSocketException(::java::net::InetSocketAddress* addr) 
    : StalledSocketException(*static_cast< ::default_init_tag* >(0))
{
    ctor(addr);
}

void org::mpisws::p2p::transport::wire::exception::StalledSocketException::ctor(::java::lang::Object* addr, ::java::lang::String* s)
{
    super::ctor(s);
    this->addr = addr;
}

void org::mpisws::p2p::transport::wire::exception::StalledSocketException::ctor(::java::net::InetSocketAddress* addr)
{
    super::ctor(npc(addr)->toString());
    this->addr = addr;
}

java::lang::Object* org::mpisws::p2p::transport::wire::exception::StalledSocketException::getIdentifier()
{
    return addr;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::wire::exception::StalledSocketException::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.wire.exception.StalledSocketException", 62);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::wire::exception::StalledSocketException::getClass0()
{
    return class_();
}

