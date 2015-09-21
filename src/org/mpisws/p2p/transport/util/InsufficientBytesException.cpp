// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/util/InsufficientBytesException.java
#include <org/mpisws/p2p/transport/util/InsufficientBytesException.hpp>

#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>

org::mpisws::p2p::transport::util::InsufficientBytesException::InsufficientBytesException(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::transport::util::InsufficientBytesException::InsufficientBytesException(int32_t needed, int32_t available) 
    : InsufficientBytesException(*static_cast< ::default_init_tag* >(0))
{
    ctor(needed,available);
}

void org::mpisws::p2p::transport::util::InsufficientBytesException::ctor(int32_t needed, int32_t available)
{
    super::ctor(::java::lang::StringBuilder().append(u"Not enough bytes available.  Need "_j)->append(needed)
        ->append(u" have "_j)
        ->append(available)->toString());
    this->needed = needed;
    this->available = available;
}

int32_t org::mpisws::p2p::transport::util::InsufficientBytesException::getBytesAvailable()
{
    return available;
}

int32_t org::mpisws::p2p::transport::util::InsufficientBytesException::getBytesNeeded()
{
    return needed;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::util::InsufficientBytesException::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.util.InsufficientBytesException", 56);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::util::InsufficientBytesException::getClass0()
{
    return class_();
}

