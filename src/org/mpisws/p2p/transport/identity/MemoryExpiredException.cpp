// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/identity/MemoryExpiredException.java
#include <org/mpisws/p2p/transport/identity/MemoryExpiredException.hpp>

org::mpisws::p2p::transport::identity::MemoryExpiredException::MemoryExpiredException(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::transport::identity::MemoryExpiredException::MemoryExpiredException(::java::lang::String* string) 
    : MemoryExpiredException(*static_cast< ::default_init_tag* >(0))
{
    ctor(string);
}

void org::mpisws::p2p::transport::identity::MemoryExpiredException::ctor(::java::lang::String* string)
{
    super::ctor(string);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::identity::MemoryExpiredException::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.identity.MemoryExpiredException", 56);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::identity::MemoryExpiredException::getClass0()
{
    return class_();
}

