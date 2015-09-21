// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <javax/net/ssl/SSLEngineResult_Status.hpp>

#include <java/lang/Enum.hpp>

template<typename ComponentType, typename... Bases> struct SubArray;
namespace java
{
    namespace io
    {
typedef ::SubArray< ::java::io::Serializable, ::java::lang::ObjectArray > SerializableArray;
    } // io

    namespace lang
    {
typedef ::SubArray< ::java::lang::Comparable, ObjectArray > ComparableArray;
typedef ::SubArray< ::java::lang::Enum, ObjectArray, ComparableArray, ::java::io::SerializableArray > EnumArray;
    } // lang
} // java

namespace javax
{
    namespace net
    {
        namespace ssl
        {
typedef ::SubArray< ::javax::net::ssl::SSLEngineResult_Status, ::java::lang::EnumArray > SSLEngineResult_StatusArray;
        } // ssl
    } // net
} // javax

extern void unimplemented_(const char16_t* name);
javax::net::ssl::SSLEngineResult_Status::SSLEngineResult_Status(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

javax::net::ssl::SSLEngineResult_StatusArray*& javax::net::ssl::SSLEngineResult_Status::$VALUES()
{
    clinit();
    return $VALUES_;
}
javax::net::ssl::SSLEngineResult_StatusArray* javax::net::ssl::SSLEngineResult_Status::$VALUES_;
javax::net::ssl::SSLEngineResult_Status* javax::net::ssl::SSLEngineResult_Status::BUFFER_OVERFLOW;
javax::net::ssl::SSLEngineResult_Status* javax::net::ssl::SSLEngineResult_Status::BUFFER_UNDERFLOW;
javax::net::ssl::SSLEngineResult_Status* javax::net::ssl::SSLEngineResult_Status::CLOSED;
javax::net::ssl::SSLEngineResult_Status* javax::net::ssl::SSLEngineResult_Status::OK;

/* private: void ::javax::net::ssl::SSLEngineResult_Status::ctor(::java::lang::String* name, int ordinal) */
javax::net::ssl::SSLEngineResult_Status* javax::net::ssl::SSLEngineResult_Status::valueOf(::java::lang::String* arg0)
{ /* stub */
    clinit();
    unimplemented_(u"javax::net::ssl::SSLEngineResult_Status* javax::net::ssl::SSLEngineResult_Status::valueOf(::java::lang::String* arg0)");
    return 0;
}

javax::net::ssl::SSLEngineResult_StatusArray* javax::net::ssl::SSLEngineResult_Status::values()
{ /* stub */
    clinit();
    unimplemented_(u"javax::net::ssl::SSLEngineResult_StatusArray* javax::net::ssl::SSLEngineResult_Status::values()");
    return 0;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* javax::net::ssl::SSLEngineResult_Status::class_()
{
    static ::java::lang::Class* c = ::class_(u"javax.net.ssl.SSLEngineResult.Status", 36);
    return c;
}

java::lang::Enum* javax::net::ssl::SSLEngineResult_Status::valueOf(::java::lang::Class* arg0, ::java::lang::String* arg1)
{
    return super::valueOf(arg0, arg1);
}

java::lang::Class* javax::net::ssl::SSLEngineResult_Status::getClass0()
{
    return class_();
}

