// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/nio/channels/DatagramChannel.hpp>

template<typename ComponentType, typename... Bases> struct SubArray;
namespace java
{
    namespace lang
    {
typedef ::SubArray< ::java::lang::Comparable, ObjectArray > ComparableArray;
    } // lang

    namespace nio
    {
typedef ::SubArray< ::java::nio::Buffer, ::java::lang::ObjectArray > BufferArray;
typedef ::SubArray< ::java::nio::ByteBuffer, BufferArray, ::java::lang::ComparableArray > ByteBufferArray;
    } // nio
} // java

extern void unimplemented_(const char16_t* name);
java::nio::channels::DatagramChannel::DatagramChannel(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::nio::channels::DatagramChannel::DatagramChannel(::java::nio::channels::spi::SelectorProvider* arg0)
    : DatagramChannel(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0);
}


void ::java::nio::channels::DatagramChannel::ctor(::java::nio::channels::spi::SelectorProvider* arg0)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::nio::channels::DatagramChannel::ctor(::java::nio::channels::spi::SelectorProvider* arg0)");
}

java::nio::channels::DatagramChannel* java::nio::channels::DatagramChannel::open()
{ /* stub */
    clinit();
    unimplemented_(u"java::nio::channels::DatagramChannel* java::nio::channels::DatagramChannel::open()");
    return 0;
}

java::nio::channels::DatagramChannel* java::nio::channels::DatagramChannel::open(::java::net::ProtocolFamily* arg0)
{ /* stub */
    clinit();
    unimplemented_(u"java::nio::channels::DatagramChannel* java::nio::channels::DatagramChannel::open(::java::net::ProtocolFamily* arg0)");
    return 0;
}

int64_t java::nio::channels::DatagramChannel::read(::java::nio::ByteBufferArray* arg0)
{ /* stub */
    unimplemented_(u"int64_t java::nio::channels::DatagramChannel::read(::java::nio::ByteBufferArray* arg0)");
    return 0;
}

int32_t java::nio::channels::DatagramChannel::validOps()
{ /* stub */
    unimplemented_(u"int32_t java::nio::channels::DatagramChannel::validOps()");
    return 0;
}

int64_t java::nio::channels::DatagramChannel::write(::java::nio::ByteBufferArray* arg0)
{ /* stub */
    unimplemented_(u"int64_t java::nio::channels::DatagramChannel::write(::java::nio::ByteBufferArray* arg0)");
    return 0;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::nio::channels::DatagramChannel::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.nio.channels.DatagramChannel", 33);
    return c;
}

bool java::nio::channels::DatagramChannel::isOpen()
{
    return AbstractInterruptibleChannel::isOpen();
}

void java::nio::channels::DatagramChannel::close()
{
    AbstractInterruptibleChannel::close();
}

java::lang::Class* java::nio::channels::DatagramChannel::getClass0()
{
    return class_();
}

