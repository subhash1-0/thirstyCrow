// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/io/Reader.hpp>

extern void unimplemented_(const char16_t* name);
java::io::Reader::Reader(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::io::Reader::Reader()
    : Reader(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

java::io::Reader::Reader(::java::lang::Object* arg0)
    : Reader(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0);
}

constexpr int32_t java::io::Reader::maxSkipBufferSize;

void ::java::io::Reader::ctor()
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::io::Reader::ctor()");
}

void ::java::io::Reader::ctor(::java::lang::Object* arg0)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::io::Reader::ctor(::java::lang::Object* arg0)");
}

void java::io::Reader::mark(int32_t arg0)
{ /* stub */
    unimplemented_(u"void java::io::Reader::mark(int32_t arg0)");
}

bool java::io::Reader::markSupported()
{ /* stub */
    unimplemented_(u"bool java::io::Reader::markSupported()");
    return 0;
}

int32_t java::io::Reader::read()
{ /* stub */
    unimplemented_(u"int32_t java::io::Reader::read()");
    return 0;
}

int32_t java::io::Reader::read(::java::nio::CharBuffer* arg0)
{ /* stub */
    unimplemented_(u"int32_t java::io::Reader::read(::java::nio::CharBuffer* arg0)");
    return 0;
}

int32_t java::io::Reader::read(::char16_tArray* arg0)
{ /* stub */
    unimplemented_(u"int32_t java::io::Reader::read(::char16_tArray* arg0)");
    return 0;
}

bool java::io::Reader::ready()
{ /* stub */
    unimplemented_(u"bool java::io::Reader::ready()");
    return 0;
}

void java::io::Reader::reset()
{ /* stub */
    unimplemented_(u"void java::io::Reader::reset()");
}

int64_t java::io::Reader::skip(int64_t arg0)
{ /* stub */
    unimplemented_(u"int64_t java::io::Reader::skip(int64_t arg0)");
    return 0;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::io::Reader::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.io.Reader", 14);
    return c;
}

java::lang::Class* java::io::Reader::getClass0()
{
    return class_();
}

