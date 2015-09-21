// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/nio/channels/spi/AbstractSelectableChannel.hpp>

#include <java/nio/channels/SelectionKey.hpp>

extern void unimplemented_(const char16_t* name);
java::nio::channels::spi::AbstractSelectableChannel::AbstractSelectableChannel(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::nio::channels::spi::AbstractSelectableChannel::AbstractSelectableChannel(SelectorProvider* arg0)
    : AbstractSelectableChannel(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0);
}

bool& java::nio::channels::spi::AbstractSelectableChannel::$assertionsDisabled()
{
    clinit();
    return $assertionsDisabled_;
}
bool java::nio::channels::spi::AbstractSelectableChannel::$assertionsDisabled_;

void ::java::nio::channels::spi::AbstractSelectableChannel::ctor(SelectorProvider* arg0)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::nio::channels::spi::AbstractSelectableChannel::ctor(SelectorProvider* arg0)");
}

/* private: void java::nio::channels::spi::AbstractSelectableChannel::addKey(::java::nio::channels::SelectionKey* arg0) */
java::lang::Object* java::nio::channels::spi::AbstractSelectableChannel::blockingLock()
{ /* stub */
    unimplemented_(u"java::lang::Object* java::nio::channels::spi::AbstractSelectableChannel::blockingLock()");
    return 0;
}

java::nio::channels::SelectableChannel* java::nio::channels::spi::AbstractSelectableChannel::configureBlocking(bool arg0)
{ /* stub */
    unimplemented_(u"java::nio::channels::SelectableChannel* java::nio::channels::spi::AbstractSelectableChannel::configureBlocking(bool arg0)");
    return 0;
}

/* private: java::nio::channels::SelectionKey* java::nio::channels::spi::AbstractSelectableChannel::findKey(::java::nio::channels::Selector* arg0) */
/* private: bool java::nio::channels::spi::AbstractSelectableChannel::haveValidKeys() */
void java::nio::channels::spi::AbstractSelectableChannel::implCloseChannel()
{ /* stub */
    unimplemented_(u"void java::nio::channels::spi::AbstractSelectableChannel::implCloseChannel()");
}

bool java::nio::channels::spi::AbstractSelectableChannel::isBlocking()
{ /* stub */
    unimplemented_(u"bool java::nio::channels::spi::AbstractSelectableChannel::isBlocking()");
    return 0;
}

bool java::nio::channels::spi::AbstractSelectableChannel::isRegistered()
{ /* stub */
    unimplemented_(u"bool java::nio::channels::spi::AbstractSelectableChannel::isRegistered()");
    return 0;
}

java::nio::channels::SelectionKey* java::nio::channels::spi::AbstractSelectableChannel::keyFor(::java::nio::channels::Selector* arg0)
{ /* stub */
    unimplemented_(u"java::nio::channels::SelectionKey* java::nio::channels::spi::AbstractSelectableChannel::keyFor(::java::nio::channels::Selector* arg0)");
    return 0;
}

java::nio::channels::spi::SelectorProvider* java::nio::channels::spi::AbstractSelectableChannel::provider()
{ /* stub */
    unimplemented_(u"java::nio::channels::spi::SelectorProvider* java::nio::channels::spi::AbstractSelectableChannel::provider()");
    return 0;
}

java::nio::channels::SelectionKey* java::nio::channels::spi::AbstractSelectableChannel::register_(::java::nio::channels::Selector* arg0, int32_t arg1, ::java::lang::Object* arg2)
{ /* stub */
    unimplemented_(u"java::nio::channels::SelectionKey* java::nio::channels::spi::AbstractSelectableChannel::register_(::java::nio::channels::Selector* arg0, int32_t arg1, ::java::lang::Object* arg2)");
    return 0;
}

void java::nio::channels::spi::AbstractSelectableChannel::removeKey(::java::nio::channels::SelectionKey* arg0)
{ /* stub */
    unimplemented_(u"void java::nio::channels::spi::AbstractSelectableChannel::removeKey(::java::nio::channels::SelectionKey* arg0)");
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::nio::channels::spi::AbstractSelectableChannel::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.nio.channels.spi.AbstractSelectableChannel", 47);
    return c;
}

java::nio::channels::SelectionKey* java::nio::channels::spi::AbstractSelectableChannel::register_(::java::nio::channels::Selector* arg0, int32_t arg1)
{
    return super::register_(arg0, arg1);
}

java::lang::Class* java::nio::channels::spi::AbstractSelectableChannel::getClass0()
{
    return class_();
}

