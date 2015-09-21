// Generated from /pastry-2.1/src/rice/pastry/standard/CertifiedNodeIdFactory.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/net/fwd-pastry-2.1.hpp>
#include <java/security/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/standard/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/pastry/NodeIdFactory.hpp>

template<typename ComponentType, typename... Bases> struct SubArray;
namespace java
{
    namespace io
    {
typedef ::SubArray< ::java::io::Serializable, ::java::lang::ObjectArray > SerializableArray;
    } // io

    namespace lang
    {
typedef ::SubArray< ::java::lang::CharSequence, ObjectArray > CharSequenceArray;
typedef ::SubArray< ::java::lang::Comparable, ObjectArray > ComparableArray;
typedef ::SubArray< ::java::lang::String, ObjectArray, ::java::io::SerializableArray, ComparableArray, CharSequenceArray > StringArray;
    } // lang
} // java

struct default_init_tag;

class rice::pastry::standard::CertifiedNodeIdFactory
    : public virtual ::java::lang::Object
    , public virtual ::rice::pastry::NodeIdFactory
{

public:
    typedef ::java::lang::Object super;

private:
    static ::java::lang::String* NODE_ID_FILENAME_;

public: /* protected */
    int32_t port {  };
    IPNodeIdFactory* realFactory {  };
    ::rice::environment::Environment* environment {  };
    ::rice::environment::logging::Logger* logger {  };
protected:
    void ctor(::java::net::InetAddress* localIP, int32_t port, ::rice::environment::Environment* env);

public:
    ::rice::pastry::Id* generateNodeId() override;
    static void generateCertificate(::rice::pastry::Id* id, ::java::io::OutputStream* os, ::java::security::PrivateKey* key);
    static void main(::java::lang::StringArray* args) /* throws(Exception) */;
    static ::java::lang::String* getArg(::java::lang::StringArray* args, ::java::lang::String* argType);

    // Generated
    CertifiedNodeIdFactory(::java::net::InetAddress* localIP, int32_t port, ::rice::environment::Environment* env);
protected:
    CertifiedNodeIdFactory(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    static void clinit();
    static ::java::lang::String*& NODE_ID_FILENAME();

private:
    virtual ::java::lang::Class* getClass0();
};
