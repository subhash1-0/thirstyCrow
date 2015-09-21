// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/nio/fwd-pastry-2.1.hpp>
#include <javax/net/ssl/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

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

    namespace nio
    {
typedef ::SubArray< ::java::nio::Buffer, ::java::lang::ObjectArray > BufferArray;
typedef ::SubArray< ::java::nio::ByteBuffer, BufferArray, ::java::lang::ComparableArray > ByteBufferArray;
    } // nio
} // java

struct default_init_tag;

class javax::net::ssl::SSLEngine
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;

private:
    ::java::lang::String* peerHost {  };
    int32_t peerPort {  };

protected:
    void ctor();
    void ctor(::java::lang::String* arg0, int32_t arg1);

public:
    virtual void beginHandshake() = 0;
    virtual void closeInbound() = 0;
    virtual void closeOutbound() = 0;
    virtual ::java::lang::Runnable* getDelegatedTask() = 0;
    virtual bool getEnableSessionCreation() = 0;
    virtual ::java::lang::StringArray* getEnabledCipherSuites() = 0;
    virtual ::java::lang::StringArray* getEnabledProtocols() = 0;
    virtual SSLSession* getHandshakeSession();
    virtual SSLEngineResult_HandshakeStatus* getHandshakeStatus() = 0;
    virtual bool getNeedClientAuth() = 0;
    virtual ::java::lang::String* getPeerHost();
    virtual int32_t getPeerPort();
    virtual SSLParameters* getSSLParameters();
    virtual SSLSession* getSession() = 0;
    virtual ::java::lang::StringArray* getSupportedCipherSuites() = 0;
    virtual ::java::lang::StringArray* getSupportedProtocols() = 0;
    virtual bool getUseClientMode() = 0;
    virtual bool getWantClientAuth() = 0;
    virtual bool isInboundDone() = 0;
    virtual bool isOutboundDone() = 0;
    virtual void setEnableSessionCreation(bool arg0) = 0;
    virtual void setEnabledCipherSuites(::java::lang::StringArray* arg0) = 0;
    virtual void setEnabledProtocols(::java::lang::StringArray* arg0) = 0;
    virtual void setNeedClientAuth(bool arg0) = 0;
    virtual void setSSLParameters(SSLParameters* arg0);
    virtual void setUseClientMode(bool arg0) = 0;
    virtual void setWantClientAuth(bool arg0) = 0;
    virtual SSLEngineResult* unwrap(::java::nio::ByteBuffer* arg0, ::java::nio::ByteBuffer* arg1);
    virtual SSLEngineResult* unwrap(::java::nio::ByteBuffer* arg0, ::java::nio::ByteBufferArray* arg1);
    virtual SSLEngineResult* unwrap(::java::nio::ByteBuffer* arg0, ::java::nio::ByteBufferArray* arg1, int32_t arg2, int32_t arg3) = 0;
    virtual SSLEngineResult* wrap(::java::nio::ByteBuffer* arg0, ::java::nio::ByteBuffer* arg1);
    virtual SSLEngineResult* wrap(::java::nio::ByteBufferArray* arg0, ::java::nio::ByteBuffer* arg1);
    virtual SSLEngineResult* wrap(::java::nio::ByteBufferArray* arg0, int32_t arg1, int32_t arg2, ::java::nio::ByteBuffer* arg3) = 0;

    // Generated

public: /* protected */
    SSLEngine();
    SSLEngine(::java::lang::String* arg0, int32_t arg1);
protected:
    SSLEngine(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
