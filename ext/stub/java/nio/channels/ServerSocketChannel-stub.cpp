// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/nio/channels/ServerSocketChannel.hpp>

extern void unimplemented_(const char16_t* name);
java::nio::channels::ServerSocketChannel::ServerSocketChannel(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::nio::channels::ServerSocketChannel::ServerSocketChannel(::java::nio::channels::spi::SelectorProvider* arg0)
    : ServerSocketChannel(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0);
}


void ::java::nio::channels::ServerSocketChannel::ctor(::java::nio::channels::spi::SelectorProvider* arg0)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::nio::channels::ServerSocketChannel::ctor(::java::nio::channels::spi::SelectorProvider* arg0)");
}

java::nio::channels::ServerSocketChannel* java::nio::channels::ServerSocketChannel::bind(::java::net::SocketAddress* arg0)
{ /* stub */
    unimplemented_(u"java::nio::channels::ServerSocketChannel* java::nio::channels::ServerSocketChannel::bind(::java::net::SocketAddress* arg0)");
    return 0;
}

java::nio::channels::ServerSocketChannel* java::nio::channels::ServerSocketChannel::open()
{ /* stub */
    clinit();
    unimplemented_(u"java::nio::channels::ServerSocketChannel* java::nio::channels::ServerSocketChannel::open()");
    return 0;
}

int32_t java::nio::channels::ServerSocketChannel::validOps()
{ /* stub */
    unimplemented_(u"int32_t java::nio::channels::ServerSocketChannel::validOps()");
    return 0;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::nio::channels::ServerSocketChannel::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.nio.channels.ServerSocketChannel", 37);
    return c;
}

void java::nio::channels::ServerSocketChannel::close()
{
    AbstractInterruptibleChannel::close();
}

bool java::nio::channels::ServerSocketChannel::isOpen()
{
    return AbstractInterruptibleChannel::isOpen();
}

java::lang::Class* java::nio::channels::ServerSocketChannel::getClass0()
{
    return class_();
}

