// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/nio/channels/SocketChannel.hpp>

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
java::nio::channels::SocketChannel::SocketChannel(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::nio::channels::SocketChannel::SocketChannel(::java::nio::channels::spi::SelectorProvider* arg0)
    : SocketChannel(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0);
}

bool& java::nio::channels::SocketChannel::$assertionsDisabled()
{
    clinit();
    return $assertionsDisabled_;
}
bool java::nio::channels::SocketChannel::$assertionsDisabled_;

void ::java::nio::channels::SocketChannel::ctor(::java::nio::channels::spi::SelectorProvider* arg0)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::nio::channels::SocketChannel::ctor(::java::nio::channels::spi::SelectorProvider* arg0)");
}

java::nio::channels::SocketChannel* java::nio::channels::SocketChannel::open()
{ /* stub */
    clinit();
    unimplemented_(u"java::nio::channels::SocketChannel* java::nio::channels::SocketChannel::open()");
    return 0;
}

java::nio::channels::SocketChannel* java::nio::channels::SocketChannel::open(::java::net::SocketAddress* arg0)
{ /* stub */
    clinit();
    unimplemented_(u"java::nio::channels::SocketChannel* java::nio::channels::SocketChannel::open(::java::net::SocketAddress* arg0)");
    return 0;
}

int64_t java::nio::channels::SocketChannel::read(::java::nio::ByteBufferArray* arg0)
{ /* stub */
    unimplemented_(u"int64_t java::nio::channels::SocketChannel::read(::java::nio::ByteBufferArray* arg0)");
    return 0;
}

int32_t java::nio::channels::SocketChannel::validOps()
{ /* stub */
    unimplemented_(u"int32_t java::nio::channels::SocketChannel::validOps()");
    return 0;
}

int64_t java::nio::channels::SocketChannel::write(::java::nio::ByteBufferArray* arg0)
{ /* stub */
    unimplemented_(u"int64_t java::nio::channels::SocketChannel::write(::java::nio::ByteBufferArray* arg0)");
    return 0;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::nio::channels::SocketChannel::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.nio.channels.SocketChannel", 31);
    return c;
}

void java::nio::channels::SocketChannel::close()
{
    AbstractInterruptibleChannel::close();
}

bool java::nio::channels::SocketChannel::isOpen()
{
    return AbstractInterruptibleChannel::isOpen();
}

java::lang::Class* java::nio::channels::SocketChannel::getClass0()
{
    return class_();
}

