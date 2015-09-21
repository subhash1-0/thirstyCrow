// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/nio/channels/ClosedChannelException.hpp>

extern void unimplemented_(const char16_t* name);
java::nio::channels::ClosedChannelException::ClosedChannelException(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::nio::channels::ClosedChannelException::ClosedChannelException()
    : ClosedChannelException(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

constexpr int64_t java::nio::channels::ClosedChannelException::serialVersionUID;

void ::java::nio::channels::ClosedChannelException::ctor()
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::nio::channels::ClosedChannelException::ctor()");
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::nio::channels::ClosedChannelException::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.nio.channels.ClosedChannelException", 40);
    return c;
}

java::lang::Class* java::nio::channels::ClosedChannelException::getClass0()
{
    return class_();
}

