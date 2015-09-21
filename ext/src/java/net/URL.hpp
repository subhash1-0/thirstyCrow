// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/lang/reflect/fwd-pastry-2.1.hpp>
#include <java/net/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <java/io/Serializable.hpp>

template<typename ComponentType, typename... Bases> struct SubArray;
namespace java
{
    namespace io
    {
typedef ::SubArray< ::java::io::Serializable, ::java::lang::ObjectArray > SerializableArray;
    } // io

    namespace lang
    {
        namespace reflect
        {
typedef ::SubArray< ::java::lang::reflect::AnnotatedElement, ::java::lang::ObjectArray > AnnotatedElementArray;
typedef ::SubArray< ::java::lang::reflect::GenericDeclaration, ::java::lang::ObjectArray, AnnotatedElementArray > GenericDeclarationArray;
typedef ::SubArray< ::java::lang::reflect::Type, ::java::lang::ObjectArray > TypeArray;
        } // reflect
typedef ::SubArray< ::java::lang::Class, ObjectArray, ::java::io::SerializableArray, ::java::lang::reflect::GenericDeclarationArray, ::java::lang::reflect::TypeArray, ::java::lang::reflect::AnnotatedElementArray > ClassArray;
    } // lang
} // java

struct default_init_tag;

class java::net::URL final
    : public virtual ::java::lang::Object
    , public ::java::io::Serializable
{

public:
    typedef ::java::lang::Object super;

private:
    ::java::lang::String* authority {  };
    static URLStreamHandlerFactory* factory_;
    ::java::lang::String* file {  };

public: /* package */
    URLStreamHandler* handler {  };

private:
    static ::java::util::Hashtable* handlers_;
    int32_t hashCode_ {  };
    ::java::lang::String* host {  };

public: /* package */
    InetAddress* hostAddress {  };

private:
    ::java::lang::String* path {  };
    int32_t port {  };
    ::java::lang::String* protocol {  };
    static ::java::lang::String* protocolPathProp_;
    ::java::lang::String* query {  };
    ::java::lang::String* ref {  };

public: /* package */
    static constexpr int64_t serialVersionUID { int64_t(-7627629688361524110LL) };

private:
    static ::java::lang::Object* streamHandlerLock_;
    ::java::lang::String* userInfo {  };

protected:
    void ctor(::java::lang::String* arg0);
    void ctor(URL* arg0, ::java::lang::String* arg1);
    void ctor(::java::lang::String* arg0, ::java::lang::String* arg1, ::java::lang::String* arg2);
    void ctor(URL* arg0, ::java::lang::String* arg1, URLStreamHandler* arg2);
    void ctor(::java::lang::String* arg0, ::java::lang::String* arg1, int32_t arg2, ::java::lang::String* arg3);
    void ctor(::java::lang::String* arg0, ::java::lang::String* arg1, int32_t arg2, ::java::lang::String* arg3, URLStreamHandler* arg4);
    /*void checkSpecifyHandler(::java::lang::SecurityManager* arg0); (private) */

public:
    bool equals(::java::lang::Object* arg0) override;
    ::java::lang::String* getAuthority();
    ::java::lang::Object* getContent();
    ::java::lang::Object* getContent(::java::lang::ClassArray* arg0);
    int32_t getDefaultPort();
    ::java::lang::String* getFile();
    ::java::lang::String* getHost();
    ::java::lang::String* getPath();
    int32_t getPort();
    ::java::lang::String* getProtocol();
    ::java::lang::String* getQuery();
    ::java::lang::String* getRef();

public: /* package */
    static URLStreamHandler* getURLStreamHandler(::java::lang::String* arg0);

public:
    ::java::lang::String* getUserInfo();
    int32_t hashCode() override;
    /*bool isValidProtocol(::java::lang::String* arg0); (private) */
    URLConnection* openConnection();
    URLConnection* openConnection(Proxy* arg0);
    ::java::io::InputStream* openStream();
    /*void readObject(::java::io::ObjectInputStream* arg0); (private) */
    bool sameFile(URL* arg0);

public: /* package */
    void set(::java::lang::String* arg0, ::java::lang::String* arg1, int32_t arg2, ::java::lang::String* arg3, ::java::lang::String* arg4);
    void set(::java::lang::String* arg0, ::java::lang::String* arg1, int32_t arg2, ::java::lang::String* arg3, ::java::lang::String* arg4, ::java::lang::String* arg5, ::java::lang::String* arg6, ::java::lang::String* arg7);

public:
    static void setURLStreamHandlerFactory(URLStreamHandlerFactory* arg0);
    ::java::lang::String* toExternalForm();
    ::java::lang::String* toString() override;
    URI* toURI();
    /*void writeObject(::java::io::ObjectOutputStream* arg0); (private) */

    // Generated
    URL(::java::lang::String* arg0);
    URL(URL* arg0, ::java::lang::String* arg1);
    URL(::java::lang::String* arg0, ::java::lang::String* arg1, ::java::lang::String* arg2);
    URL(URL* arg0, ::java::lang::String* arg1, URLStreamHandler* arg2);
    URL(::java::lang::String* arg0, ::java::lang::String* arg1, int32_t arg2, ::java::lang::String* arg3);
    URL(::java::lang::String* arg0, ::java::lang::String* arg1, int32_t arg2, ::java::lang::String* arg3, URLStreamHandler* arg4);
protected:
    URL(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

public: /* package */
    static URLStreamHandlerFactory*& factory();
    static ::java::util::Hashtable*& handlers();

private:
    static ::java::lang::String*& protocolPathProp();
    static ::java::lang::Object*& streamHandlerLock();
    virtual ::java::lang::Class* getClass0();
};
