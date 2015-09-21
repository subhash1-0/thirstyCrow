// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/nio/channels/Selector.hpp>

extern void unimplemented_(const char16_t* name);
java::nio::channels::Selector::Selector(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::nio::channels::Selector::Selector()
    : Selector(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}


void ::java::nio::channels::Selector::ctor()
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::nio::channels::Selector::ctor()");
}

java::nio::channels::Selector* java::nio::channels::Selector::open()
{ /* stub */
    clinit();
    unimplemented_(u"java::nio::channels::Selector* java::nio::channels::Selector::open()");
    return 0;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::nio::channels::Selector::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.nio.channels.Selector", 26);
    return c;
}

java::lang::Class* java::nio::channels::Selector::getClass0()
{
    return class_();
}

