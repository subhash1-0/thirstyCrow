// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/io/OutputStreamWriter.hpp>

extern void unimplemented_(const char16_t* name);
java::io::OutputStreamWriter::OutputStreamWriter(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::io::OutputStreamWriter::OutputStreamWriter(OutputStream* arg0)
    : OutputStreamWriter(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0);
}

java::io::OutputStreamWriter::OutputStreamWriter(OutputStream* arg0, ::java::lang::String* arg1)
    : OutputStreamWriter(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0, arg1);
}

java::io::OutputStreamWriter::OutputStreamWriter(OutputStream* arg0, ::java::nio::charset::Charset* arg1)
    : OutputStreamWriter(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0, arg1);
}

java::io::OutputStreamWriter::OutputStreamWriter(OutputStream* arg0, ::java::nio::charset::CharsetEncoder* arg1)
    : OutputStreamWriter(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0, arg1);
}


void ::java::io::OutputStreamWriter::ctor(OutputStream* arg0)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::io::OutputStreamWriter::ctor(OutputStream* arg0)");
}

void ::java::io::OutputStreamWriter::ctor(OutputStream* arg0, ::java::lang::String* arg1)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::io::OutputStreamWriter::ctor(OutputStream* arg0, ::java::lang::String* arg1)");
}

void ::java::io::OutputStreamWriter::ctor(OutputStream* arg0, ::java::nio::charset::Charset* arg1)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::io::OutputStreamWriter::ctor(OutputStream* arg0, ::java::nio::charset::Charset* arg1)");
}

void ::java::io::OutputStreamWriter::ctor(OutputStream* arg0, ::java::nio::charset::CharsetEncoder* arg1)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::io::OutputStreamWriter::ctor(OutputStream* arg0, ::java::nio::charset::CharsetEncoder* arg1)");
}

void java::io::OutputStreamWriter::close()
{ /* stub */
    unimplemented_(u"void java::io::OutputStreamWriter::close()");
}

void java::io::OutputStreamWriter::flush()
{ /* stub */
    unimplemented_(u"void java::io::OutputStreamWriter::flush()");
}

void java::io::OutputStreamWriter::flushBuffer()
{ /* stub */
    unimplemented_(u"void java::io::OutputStreamWriter::flushBuffer()");
}

java::lang::String* java::io::OutputStreamWriter::getEncoding()
{ /* stub */
    unimplemented_(u"java::lang::String* java::io::OutputStreamWriter::getEncoding()");
    return 0;
}

void java::io::OutputStreamWriter::write(int32_t arg0)
{ /* stub */
    unimplemented_(u"void java::io::OutputStreamWriter::write(int32_t arg0)");
}

void java::io::OutputStreamWriter::write(::char16_tArray* arg0, int32_t arg1, int32_t arg2)
{ /* stub */
    unimplemented_(u"void java::io::OutputStreamWriter::write(::char16_tArray* arg0, int32_t arg1, int32_t arg2)");
}

void java::io::OutputStreamWriter::write(::java::lang::String* arg0, int32_t arg1, int32_t arg2)
{ /* stub */
    unimplemented_(u"void java::io::OutputStreamWriter::write(::java::lang::String* arg0, int32_t arg1, int32_t arg2)");
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::io::OutputStreamWriter::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.io.OutputStreamWriter", 26);
    return c;
}

void java::io::OutputStreamWriter::write(::char16_tArray* cbuf)
{
    super::write(cbuf);
}

void java::io::OutputStreamWriter::write(::java::lang::String* str)
{
    super::write(str);
}

java::lang::Class* java::io::OutputStreamWriter::getClass0()
{
    return class_();
}

