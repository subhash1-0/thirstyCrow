// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/nio/channels/SelectableChannel.hpp>

extern void unimplemented_(const char16_t* name);
java::nio::channels::SelectableChannel::SelectableChannel(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::nio::channels::SelectableChannel::SelectableChannel()
    : SelectableChannel(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}


void ::java::nio::channels::SelectableChannel::ctor()
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::nio::channels::SelectableChannel::ctor()");
}

java::nio::channels::SelectionKey* java::nio::channels::SelectableChannel::register_(Selector* arg0, int32_t arg1)
{ /* stub */
    unimplemented_(u"java::nio::channels::SelectionKey* java::nio::channels::SelectableChannel::register_(Selector* arg0, int32_t arg1)");
    return 0;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::nio::channels::SelectableChannel::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.nio.channels.SelectableChannel", 35);
    return c;
}

void java::nio::channels::SelectableChannel::close()
{
    AbstractInterruptibleChannel::close();
}

bool java::nio::channels::SelectableChannel::isOpen()
{
    return AbstractInterruptibleChannel::isOpen();
}

java::lang::Class* java::nio::channels::SelectableChannel::getClass0()
{
    return class_();
}

