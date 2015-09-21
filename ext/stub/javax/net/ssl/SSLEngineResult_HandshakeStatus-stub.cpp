// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <javax/net/ssl/SSLEngineResult_HandshakeStatus.hpp>

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
typedef ::SubArray< ::javax::net::ssl::SSLEngineResult_HandshakeStatus, ::java::lang::EnumArray > SSLEngineResult_HandshakeStatusArray;
        } // ssl
    } // net
} // javax

extern void unimplemented_(const char16_t* name);
javax::net::ssl::SSLEngineResult_HandshakeStatus::SSLEngineResult_HandshakeStatus(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

javax::net::ssl::SSLEngineResult_HandshakeStatusArray*& javax::net::ssl::SSLEngineResult_HandshakeStatus::$VALUES()
{
    clinit();
    return $VALUES_;
}
javax::net::ssl::SSLEngineResult_HandshakeStatusArray* javax::net::ssl::SSLEngineResult_HandshakeStatus::$VALUES_;
javax::net::ssl::SSLEngineResult_HandshakeStatus* javax::net::ssl::SSLEngineResult_HandshakeStatus::FINISHED;
javax::net::ssl::SSLEngineResult_HandshakeStatus* javax::net::ssl::SSLEngineResult_HandshakeStatus::NEED_TASK;
javax::net::ssl::SSLEngineResult_HandshakeStatus* javax::net::ssl::SSLEngineResult_HandshakeStatus::NEED_UNWRAP;
javax::net::ssl::SSLEngineResult_HandshakeStatus* javax::net::ssl::SSLEngineResult_HandshakeStatus::NEED_WRAP;
javax::net::ssl::SSLEngineResult_HandshakeStatus* javax::net::ssl::SSLEngineResult_HandshakeStatus::NOT_HANDSHAKING;

/* private: void ::javax::net::ssl::SSLEngineResult_HandshakeStatus::ctor(::java::lang::String* name, int ordinal) */
javax::net::ssl::SSLEngineResult_HandshakeStatus* javax::net::ssl::SSLEngineResult_HandshakeStatus::valueOf(::java::lang::String* arg0)
{ /* stub */
    clinit();
    unimplemented_(u"javax::net::ssl::SSLEngineResult_HandshakeStatus* javax::net::ssl::SSLEngineResult_HandshakeStatus::valueOf(::java::lang::String* arg0)");
    return 0;
}

javax::net::ssl::SSLEngineResult_HandshakeStatusArray* javax::net::ssl::SSLEngineResult_HandshakeStatus::values()
{ /* stub */
    clinit();
    unimplemented_(u"javax::net::ssl::SSLEngineResult_HandshakeStatusArray* javax::net::ssl::SSLEngineResult_HandshakeStatus::values()");
    return 0;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* javax::net::ssl::SSLEngineResult_HandshakeStatus::class_()
{
    static ::java::lang::Class* c = ::class_(u"javax.net.ssl.SSLEngineResult.HandshakeStatus", 45);
    return c;
}

java::lang::Enum* javax::net::ssl::SSLEngineResult_HandshakeStatus::valueOf(::java::lang::Class* arg0, ::java::lang::String* arg1)
{
    return super::valueOf(arg0, arg1);
}

java::lang::Class* javax::net::ssl::SSLEngineResult_HandshakeStatus::getClass0()
{
    return class_();
}

