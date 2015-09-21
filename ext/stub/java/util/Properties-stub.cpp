// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/util/Properties.hpp>

extern void unimplemented_(const char16_t* name);
java::util::Properties::Properties(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::util::Properties::Properties()
    : Properties(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

java::util::Properties::Properties(Properties* arg0)
    : Properties(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0);
}

char16_tArray*& java::util::Properties::hexDigit()
{
    clinit();
    return hexDigit_;
}
char16_tArray* java::util::Properties::hexDigit_;
constexpr int64_t java::util::Properties::serialVersionUID;

void ::java::util::Properties::ctor()
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::util::Properties::ctor()");
}

void ::java::util::Properties::ctor(Properties* arg0)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::util::Properties::ctor(Properties* arg0)");
}

/* private: void java::util::Properties::enumerate(Hashtable* arg0) */
/* private: void java::util::Properties::enumerateStringProperties(Hashtable* arg0) */
java::lang::String* java::util::Properties::getProperty(::java::lang::String* arg0)
{ /* stub */
    unimplemented_(u"java::lang::String* java::util::Properties::getProperty(::java::lang::String* arg0)");
    return 0;
}

java::lang::String* java::util::Properties::getProperty(::java::lang::String* arg0, ::java::lang::String* arg1)
{ /* stub */
    unimplemented_(u"java::lang::String* java::util::Properties::getProperty(::java::lang::String* arg0, ::java::lang::String* arg1)");
    return 0;
}

void java::util::Properties::list(::java::io::PrintStream* arg0)
{ /* stub */
    unimplemented_(u"void java::util::Properties::list(::java::io::PrintStream* arg0)");
}

void java::util::Properties::list(::java::io::PrintWriter* arg0)
{ /* stub */
    unimplemented_(u"void java::util::Properties::list(::java::io::PrintWriter* arg0)");
}

void java::util::Properties::load(::java::io::Reader* arg0)
{ /* stub */
    unimplemented_(u"void java::util::Properties::load(::java::io::Reader* arg0)");
}

void java::util::Properties::load(::java::io::InputStream* arg0)
{ /* stub */
    unimplemented_(u"void java::util::Properties::load(::java::io::InputStream* arg0)");
}

/* private: void java::util::Properties::load0(Properties_LineReader* arg0) */
/* private: java::lang::String* java::util::Properties::loadConvert(::char16_tArray* arg0, int32_t arg1, int32_t arg2, ::char16_tArray* arg3) */
void java::util::Properties::loadFromXML(::java::io::InputStream* arg0)
{ /* stub */
    unimplemented_(u"void java::util::Properties::loadFromXML(::java::io::InputStream* arg0)");
}

java::util::Enumeration* java::util::Properties::propertyNames()
{ /* stub */
    unimplemented_(u"java::util::Enumeration* java::util::Properties::propertyNames()");
    return 0;
}

void java::util::Properties::save(::java::io::OutputStream* arg0, ::java::lang::String* arg1)
{ /* stub */
    unimplemented_(u"void java::util::Properties::save(::java::io::OutputStream* arg0, ::java::lang::String* arg1)");
}

/* private: java::lang::String* java::util::Properties::saveConvert(::java::lang::String* arg0, bool arg1, bool arg2) */
java::lang::Object* java::util::Properties::setProperty(::java::lang::String* arg0, ::java::lang::String* arg1)
{ /* stub */
    unimplemented_(u"java::lang::Object* java::util::Properties::setProperty(::java::lang::String* arg0, ::java::lang::String* arg1)");
    return 0;
}

void java::util::Properties::store(::java::io::Writer* arg0, ::java::lang::String* arg1)
{ /* stub */
    unimplemented_(u"void java::util::Properties::store(::java::io::Writer* arg0, ::java::lang::String* arg1)");
}

void java::util::Properties::store(::java::io::OutputStream* arg0, ::java::lang::String* arg1)
{ /* stub */
    unimplemented_(u"void java::util::Properties::store(::java::io::OutputStream* arg0, ::java::lang::String* arg1)");
}

/* private: void java::util::Properties::store0(::java::io::BufferedWriter* arg0, ::java::lang::String* arg1, bool arg2) */
void java::util::Properties::storeToXML(::java::io::OutputStream* arg0, ::java::lang::String* arg1)
{ /* stub */
    unimplemented_(u"void java::util::Properties::storeToXML(::java::io::OutputStream* arg0, ::java::lang::String* arg1)");
}

void java::util::Properties::storeToXML(::java::io::OutputStream* arg0, ::java::lang::String* arg1, ::java::lang::String* arg2)
{ /* stub */
    unimplemented_(u"void java::util::Properties::storeToXML(::java::io::OutputStream* arg0, ::java::lang::String* arg1, ::java::lang::String* arg2)");
}

java::util::Set* java::util::Properties::stringPropertyNames()
{ /* stub */
    unimplemented_(u"java::util::Set* java::util::Properties::stringPropertyNames()");
    return 0;
}

/* private: char16_t java::util::Properties::toHex(int32_t arg0) */
/* private: void java::util::Properties::writeComments(::java::io::BufferedWriter* arg0, ::java::lang::String* arg1) */
extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::util::Properties::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.util.Properties", 20);
    return c;
}

java::lang::Class* java::util::Properties::getClass0()
{
    return class_();
}

