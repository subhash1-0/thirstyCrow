// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/io/InputStreamReader.hpp>

extern void unimplemented_(const char16_t* name);
java::io::InputStreamReader::InputStreamReader(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::io::InputStreamReader::InputStreamReader(InputStream* arg0)
    : InputStreamReader(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0);
}

java::io::InputStreamReader::InputStreamReader(InputStream* arg0, ::java::lang::String* arg1)
    : InputStreamReader(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0, arg1);
}

java::io::InputStreamReader::InputStreamReader(InputStream* arg0, ::java::nio::charset::Charset* arg1)
    : InputStreamReader(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0, arg1);
}

java::io::InputStreamReader::InputStreamReader(InputStream* arg0, ::java::nio::charset::CharsetDecoder* arg1)
    : InputStreamReader(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0, arg1);
}


void ::java::io::InputStreamReader::ctor(InputStream* arg0)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::io::InputStreamReader::ctor(InputStream* arg0)");
}

void ::java::io::InputStreamReader::ctor(InputStream* arg0, ::java::lang::String* arg1)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::io::InputStreamReader::ctor(InputStream* arg0, ::java::lang::String* arg1)");
}

void ::java::io::InputStreamReader::ctor(InputStream* arg0, ::java::nio::charset::Charset* arg1)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::io::InputStreamReader::ctor(InputStream* arg0, ::java::nio::charset::Charset* arg1)");
}

void ::java::io::InputStreamReader::ctor(InputStream* arg0, ::java::nio::charset::CharsetDecoder* arg1)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::io::InputStreamReader::ctor(InputStream* arg0, ::java::nio::charset::CharsetDecoder* arg1)");
}

void java::io::InputStreamReader::close()
{ /* stub */
    unimplemented_(u"void java::io::InputStreamReader::close()");
}

java::lang::String* java::io::InputStreamReader::getEncoding()
{ /* stub */
    unimplemented_(u"java::lang::String* java::io::InputStreamReader::getEncoding()");
    return 0;
}

int32_t java::io::InputStreamReader::read()
{ /* stub */
    unimplemented_(u"int32_t java::io::InputStreamReader::read()");
    return 0;
}

int32_t java::io::InputStreamReader::read(::char16_tArray* arg0, int32_t arg1, int32_t arg2)
{ /* stub */
    unimplemented_(u"int32_t java::io::InputStreamReader::read(::char16_tArray* arg0, int32_t arg1, int32_t arg2)");
    return 0;
}

bool java::io::InputStreamReader::ready()
{ /* stub */
    unimplemented_(u"bool java::io::InputStreamReader::ready()");
    return 0;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::io::InputStreamReader::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.io.InputStreamReader", 25);
    return c;
}

int32_t java::io::InputStreamReader::read(::java::nio::CharBuffer* arg0)
{
    return super::read(arg0);
}

int32_t java::io::InputStreamReader::read(::char16_tArray* arg0)
{
    return super::read(arg0);
}

java::lang::Class* java::io::InputStreamReader::getClass0()
{
    return class_();
}

