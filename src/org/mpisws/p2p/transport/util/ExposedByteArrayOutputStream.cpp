// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/util/ExposedByteArrayOutputStream.java
#include <org/mpisws/p2p/transport/util/ExposedByteArrayOutputStream.hpp>

#include <Array.hpp>

org::mpisws::p2p::transport::util::ExposedByteArrayOutputStream::ExposedByteArrayOutputStream(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::transport::util::ExposedByteArrayOutputStream::ExposedByteArrayOutputStream(int32_t size) 
    : ExposedByteArrayOutputStream(*static_cast< ::default_init_tag* >(0))
{
    ctor(size);
}

org::mpisws::p2p::transport::util::ExposedByteArrayOutputStream::ExposedByteArrayOutputStream() 
    : ExposedByteArrayOutputStream(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

void org::mpisws::p2p::transport::util::ExposedByteArrayOutputStream::ctor(int32_t size)
{
    super::ctor(size);
}

void org::mpisws::p2p::transport::util::ExposedByteArrayOutputStream::ctor()
{
    super::ctor();
}

int8_tArray* org::mpisws::p2p::transport::util::ExposedByteArrayOutputStream::buf()
{
    return ::java::io::ByteArrayOutputStream::buf;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::util::ExposedByteArrayOutputStream::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.util.ExposedByteArrayOutputStream", 58);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::util::ExposedByteArrayOutputStream::getClass0()
{
    return class_();
}

