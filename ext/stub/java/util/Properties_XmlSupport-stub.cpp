// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/util/Properties_XmlSupport.hpp>

extern void unimplemented_(const char16_t* name);
java::util::Properties_XmlSupport::Properties_XmlSupport(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

sun::util::spi::XmlPropertiesProvider*& java::util::Properties_XmlSupport::PROVIDER()
{
    clinit();
    return PROVIDER_;
}
sun::util::spi::XmlPropertiesProvider* java::util::Properties_XmlSupport::PROVIDER_;

/* private: void ::java::util::Properties_XmlSupport::ctor() */
void java::util::Properties_XmlSupport::load(Properties* arg0, ::java::io::InputStream* arg1)
{ /* stub */
    clinit();
    unimplemented_(u"void java::util::Properties_XmlSupport::load(Properties* arg0, ::java::io::InputStream* arg1)");
}

/* private: sun::util::spi::XmlPropertiesProvider* java::util::Properties_XmlSupport::loadProvider() */
/* private: sun::util::spi::XmlPropertiesProvider* java::util::Properties_XmlSupport::loadProviderAsService(::java::lang::ClassLoader* arg0) */
/* private: sun::util::spi::XmlPropertiesProvider* java::util::Properties_XmlSupport::loadProviderFromProperty(::java::lang::ClassLoader* arg0) */
void java::util::Properties_XmlSupport::save(Properties* arg0, ::java::io::OutputStream* arg1, ::java::lang::String* arg2, ::java::lang::String* arg3)
{ /* stub */
    clinit();
    unimplemented_(u"void java::util::Properties_XmlSupport::save(Properties* arg0, ::java::io::OutputStream* arg1, ::java::lang::String* arg2, ::java::lang::String* arg3)");
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::util::Properties_XmlSupport::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.util.Properties.XmlSupport", 31);
    return c;
}

java::lang::Class* java::util::Properties_XmlSupport::getClass0()
{
    return class_();
}

