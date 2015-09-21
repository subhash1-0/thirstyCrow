// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/io/ObjectInputStream_PeekInputStream.hpp>

extern void unimplemented_(const char16_t* name);
java::io::ObjectInputStream_PeekInputStream::ObjectInputStream_PeekInputStream(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::io::ObjectInputStream_PeekInputStream::ObjectInputStream_PeekInputStream(InputStream* arg0)
    : ObjectInputStream_PeekInputStream(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0);
}


void ::java::io::ObjectInputStream_PeekInputStream::ctor(InputStream* arg0)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::io::ObjectInputStream_PeekInputStream::ctor(InputStream* arg0)");
}

int32_t java::io::ObjectInputStream_PeekInputStream::available()
{ /* stub */
    unimplemented_(u"int32_t java::io::ObjectInputStream_PeekInputStream::available()");
    return 0;
}

void java::io::ObjectInputStream_PeekInputStream::close()
{ /* stub */
    unimplemented_(u"void java::io::ObjectInputStream_PeekInputStream::close()");
}

int32_t java::io::ObjectInputStream_PeekInputStream::peek()
{ /* stub */
    unimplemented_(u"int32_t java::io::ObjectInputStream_PeekInputStream::peek()");
    return 0;
}

int32_t java::io::ObjectInputStream_PeekInputStream::read()
{ /* stub */
    unimplemented_(u"int32_t java::io::ObjectInputStream_PeekInputStream::read()");
    return 0;
}

int32_t java::io::ObjectInputStream_PeekInputStream::read(::int8_tArray* arg0, int32_t arg1, int32_t arg2)
{ /* stub */
    unimplemented_(u"int32_t java::io::ObjectInputStream_PeekInputStream::read(::int8_tArray* arg0, int32_t arg1, int32_t arg2)");
    return 0;
}

void java::io::ObjectInputStream_PeekInputStream::readFully(::int8_tArray* arg0, int32_t arg1, int32_t arg2)
{ /* stub */
    unimplemented_(u"void java::io::ObjectInputStream_PeekInputStream::readFully(::int8_tArray* arg0, int32_t arg1, int32_t arg2)");
}

int64_t java::io::ObjectInputStream_PeekInputStream::skip(int64_t arg0)
{ /* stub */
    unimplemented_(u"int64_t java::io::ObjectInputStream_PeekInputStream::skip(int64_t arg0)");
    return 0;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::io::ObjectInputStream_PeekInputStream::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.io.ObjectInputStream.PeekInputStream", 41);
    return c;
}

int32_t java::io::ObjectInputStream_PeekInputStream::read(::int8_tArray* b)
{
    return super::read(b);
}

java::lang::Class* java::io::ObjectInputStream_PeekInputStream::getClass0()
{
    return class_();
}

