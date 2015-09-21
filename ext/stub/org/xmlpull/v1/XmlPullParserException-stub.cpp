// Generated from /pastry-2.1/lib/xmlpull_1_1_3_4a.jar
#include <org/xmlpull/v1/XmlPullParserException.hpp>

extern void unimplemented_(const char16_t* name);
org::xmlpull::v1::XmlPullParserException::XmlPullParserException(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::xmlpull::v1::XmlPullParserException::XmlPullParserException(::java::lang::String* s)
    : XmlPullParserException(*static_cast< ::default_init_tag* >(0))
{
    ctor(s);
}

org::xmlpull::v1::XmlPullParserException::XmlPullParserException(::java::lang::String* msg, XmlPullParser* parser, ::java::lang::Throwable* chain)
    : XmlPullParserException(*static_cast< ::default_init_tag* >(0))
{
    ctor(msg, parser, chain);
}


void ::org::xmlpull::v1::XmlPullParserException::ctor(::java::lang::String* s)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::org::xmlpull::v1::XmlPullParserException::ctor(::java::lang::String* s)");
}

void ::org::xmlpull::v1::XmlPullParserException::ctor(::java::lang::String* msg, XmlPullParser* parser, ::java::lang::Throwable* chain)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::org::xmlpull::v1::XmlPullParserException::ctor(::java::lang::String* msg, XmlPullParser* parser, ::java::lang::Throwable* chain)");
}

int32_t org::xmlpull::v1::XmlPullParserException::getColumnNumber()
{ /* stub */
    unimplemented_(u"int32_t org::xmlpull::v1::XmlPullParserException::getColumnNumber()");
    return 0;
}

java::lang::Throwable* org::xmlpull::v1::XmlPullParserException::getDetail()
{ /* stub */
return detail ; /* getter */
}

int32_t org::xmlpull::v1::XmlPullParserException::getLineNumber()
{ /* stub */
    unimplemented_(u"int32_t org::xmlpull::v1::XmlPullParserException::getLineNumber()");
    return 0;
}

void org::xmlpull::v1::XmlPullParserException::printStackTrace()
{ /* stub */
    unimplemented_(u"void org::xmlpull::v1::XmlPullParserException::printStackTrace()");
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::xmlpull::v1::XmlPullParserException::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.xmlpull.v1.XmlPullParserException", 37);
    return c;
}

void org::xmlpull::v1::XmlPullParserException::printStackTrace(::java::io::PrintStream* arg0)
{
    super::printStackTrace(arg0);
}

void org::xmlpull::v1::XmlPullParserException::printStackTrace(::java::io::PrintWriter* arg0)
{
    super::printStackTrace(arg0);
}

java::lang::Class* org::xmlpull::v1::XmlPullParserException::getClass0()
{
    return class_();
}

