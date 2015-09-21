// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <sun/util/spi/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct default_init_tag;

class java::util::Properties_XmlSupport
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;

private:
    static ::sun::util::spi::XmlPropertiesProvider* PROVIDER_;

    /*void ctor(); (private) */

public: /* package */
    static void load(Properties* arg0, ::java::io::InputStream* arg1);
    /*static ::sun::util::spi::XmlPropertiesProvider* loadProvider(); (private) */
    /*static ::sun::util::spi::XmlPropertiesProvider* loadProviderAsService(::java::lang::ClassLoader* arg0); (private) */
    /*static ::sun::util::spi::XmlPropertiesProvider* loadProviderFromProperty(::java::lang::ClassLoader* arg0); (private) */
    static void save(Properties* arg0, ::java::io::OutputStream* arg1, ::java::lang::String* arg2, ::java::lang::String* arg3);

    // Generated

public:
    Properties_XmlSupport();
protected:
    Properties_XmlSupport(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    static ::sun::util::spi::XmlPropertiesProvider*& PROVIDER();
    virtual ::java::lang::Class* getClass0();
};
