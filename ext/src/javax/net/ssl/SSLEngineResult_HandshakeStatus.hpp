// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <javax/net/ssl/fwd-pastry-2.1.hpp>
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

struct default_init_tag;

class javax::net::ssl::SSLEngineResult_HandshakeStatus final
    : public ::java::lang::Enum
{

public:
    typedef ::java::lang::Enum super;

private:
    static SSLEngineResult_HandshakeStatusArray* $VALUES_;

public:
    static SSLEngineResult_HandshakeStatus* FINISHED;
    static SSLEngineResult_HandshakeStatus* NEED_TASK;
    static SSLEngineResult_HandshakeStatus* NEED_UNWRAP;
    static SSLEngineResult_HandshakeStatus* NEED_WRAP;
    static SSLEngineResult_HandshakeStatus* NOT_HANDSHAKING;

    /*void ctor(::java::lang::String* name, int ordinal); (private) */
    static SSLEngineResult_HandshakeStatus* valueOf(::java::lang::String* arg0);
    static SSLEngineResult_HandshakeStatusArray* values();

    // Generated
    SSLEngineResult_HandshakeStatus(::java::lang::String* name, int ordinal);
protected:
    SSLEngineResult_HandshakeStatus(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    static ::java::lang::Enum* valueOf(::java::lang::Class* arg0, ::java::lang::String* arg1);

private:
    static SSLEngineResult_HandshakeStatusArray*& $VALUES();
    virtual ::java::lang::Class* getClass0();
};
