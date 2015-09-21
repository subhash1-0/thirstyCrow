// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/io/FilterOutputStream.hpp>

extern void unimplemented_(const char16_t* name);
java::io::FilterOutputStream::FilterOutputStream(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::io::FilterOutputStream::FilterOutputStream(OutputStream* arg0)
    : FilterOutputStream(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0);
}


void ::java::io::FilterOutputStream::ctor(OutputStream* arg0)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::io::FilterOutputStream::ctor(OutputStream* arg0)");
}

void java::io::FilterOutputStream::close()
{ /* stub */
    unimplemented_(u"void java::io::FilterOutputStream::close()");
}

void java::io::FilterOutputStream::flush()
{ /* stub */
    unimplemented_(u"void java::io::FilterOutputStream::flush()");
}

void java::io::FilterOutputStream::write(int32_t arg0)
{ /* stub */
    unimplemented_(u"void java::io::FilterOutputStream::write(int32_t arg0)");
}

void java::io::FilterOutputStream::write(::int8_tArray* arg0)
{ /* stub */
    unimplemented_(u"void java::io::FilterOutputStream::write(::int8_tArray* arg0)");
}

void java::io::FilterOutputStream::write(::int8_tArray* arg0, int32_t arg1, int32_t arg2)
{ /* stub */
    unimplemented_(u"void java::io::FilterOutputStream::write(::int8_tArray* arg0, int32_t arg1, int32_t arg2)");
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::io::FilterOutputStream::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.io.FilterOutputStream", 26);
    return c;
}

java::lang::Class* java::io::FilterOutputStream::getClass0()
{
    return class_();
}

