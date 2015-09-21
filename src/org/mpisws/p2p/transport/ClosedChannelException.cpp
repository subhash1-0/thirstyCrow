// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/ClosedChannelException.java
#include <org/mpisws/p2p/transport/ClosedChannelException.hpp>

#include <java/lang/String.hpp>

org::mpisws::p2p::transport::ClosedChannelException::ClosedChannelException(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::transport::ClosedChannelException::ClosedChannelException(::java::lang::String* reason) 
    : ClosedChannelException(*static_cast< ::default_init_tag* >(0))
{
    ctor(reason);
}

void org::mpisws::p2p::transport::ClosedChannelException::ctor(::java::lang::String* reason)
{
    super::ctor();
    this->reason = reason;
}

java::lang::String* org::mpisws::p2p::transport::ClosedChannelException::getMessage()
{
    return reason;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::ClosedChannelException::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.ClosedChannelException", 47);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::ClosedChannelException::getClass0()
{
    return class_();
}

