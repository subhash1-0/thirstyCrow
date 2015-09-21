// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/nio/channels/SelectionKey.hpp>

extern void unimplemented_(const char16_t* name);
java::nio::channels::SelectionKey::SelectionKey(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::nio::channels::SelectionKey::SelectionKey()
    : SelectionKey(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

constexpr int32_t java::nio::channels::SelectionKey::OP_ACCEPT;
constexpr int32_t java::nio::channels::SelectionKey::OP_CONNECT;
constexpr int32_t java::nio::channels::SelectionKey::OP_READ;
constexpr int32_t java::nio::channels::SelectionKey::OP_WRITE;
java::util::concurrent::atomic::AtomicReferenceFieldUpdater*& java::nio::channels::SelectionKey::attachmentUpdater()
{
    clinit();
    return attachmentUpdater_;
}
java::util::concurrent::atomic::AtomicReferenceFieldUpdater* java::nio::channels::SelectionKey::attachmentUpdater_;

void ::java::nio::channels::SelectionKey::ctor()
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::nio::channels::SelectionKey::ctor()");
}

java::lang::Object* java::nio::channels::SelectionKey::attach(::java::lang::Object* arg0)
{ /* stub */
    unimplemented_(u"java::lang::Object* java::nio::channels::SelectionKey::attach(::java::lang::Object* arg0)");
    return 0;
}

java::lang::Object* java::nio::channels::SelectionKey::attachment()
{ /* stub */
    unimplemented_(u"java::lang::Object* java::nio::channels::SelectionKey::attachment()");
    return 0;
}

bool java::nio::channels::SelectionKey::isAcceptable()
{ /* stub */
    unimplemented_(u"bool java::nio::channels::SelectionKey::isAcceptable()");
    return 0;
}

bool java::nio::channels::SelectionKey::isConnectable()
{ /* stub */
    unimplemented_(u"bool java::nio::channels::SelectionKey::isConnectable()");
    return 0;
}

bool java::nio::channels::SelectionKey::isReadable()
{ /* stub */
    unimplemented_(u"bool java::nio::channels::SelectionKey::isReadable()");
    return 0;
}

bool java::nio::channels::SelectionKey::isWritable()
{ /* stub */
    unimplemented_(u"bool java::nio::channels::SelectionKey::isWritable()");
    return 0;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::nio::channels::SelectionKey::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.nio.channels.SelectionKey", 30);
    return c;
}

java::lang::Class* java::nio::channels::SelectionKey::getClass0()
{
    return class_();
}

