// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/net/fwd-pastry-2.1.hpp>
#include <java/nio/channels/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <java/io/Closeable.hpp>

struct default_init_tag;

class java::net::Socket
    : public virtual ::java::lang::Object
    , public virtual ::java::io::Closeable
{

public:
    typedef ::java::lang::Object super;

private:
    bool bound {  };
    ::java::lang::Object* closeLock {  };
    bool closed {  };
    bool connected {  };
    bool created {  };
    static SocketImplFactory* factory_;

public: /* package */
    SocketImpl* impl {  };

private:
    bool oldImpl {  };
    bool shutIn {  };
    bool shutOut {  };

protected:
    void ctor();
    void ctor(Proxy* arg0);
    void ctor(SocketImpl* arg0);
    void ctor(::java::lang::String* arg0, int32_t arg1);
    void ctor(InetAddress* arg0, int32_t arg1);
    void ctor(::java::lang::String* arg0, int32_t arg1, bool arg2);
    void ctor(InetAddress* arg0, int32_t arg1, bool arg2);
    /*void ctor(SocketAddress* arg0, SocketAddress* arg1, bool arg2); (private) */
    void ctor(::java::lang::String* arg0, int32_t arg1, InetAddress* arg2, int32_t arg3);
    void ctor(InetAddress* arg0, int32_t arg1, InetAddress* arg2, int32_t arg3);

public:
    virtual void bind(SocketAddress* arg0);
    /*void checkAddress(InetAddress* arg0, ::java::lang::String* arg1); (private) */
    /*void checkOldImpl(); (private) */
    void close() override;
    virtual void connect(SocketAddress* arg0);
    virtual void connect(SocketAddress* arg0, int32_t arg1);

public: /* package */
    virtual void createImpl(bool arg0);

public:
    virtual ::java::nio::channels::SocketChannel* getChannel();

public: /* package */
    virtual SocketImpl* getImpl();

public:
    virtual InetAddress* getInetAddress();
    virtual ::java::io::InputStream* getInputStream();
    virtual bool getKeepAlive();
    virtual InetAddress* getLocalAddress();
    virtual int32_t getLocalPort();
    virtual SocketAddress* getLocalSocketAddress();
    virtual bool getOOBInline();
    virtual ::java::io::OutputStream* getOutputStream();
    virtual int32_t getPort();
    virtual int32_t getReceiveBufferSize();
    virtual SocketAddress* getRemoteSocketAddress();
    virtual bool getReuseAddress();
    virtual int32_t getSendBufferSize();
    virtual int32_t getSoLinger();
    virtual int32_t getSoTimeout();
    virtual bool getTcpNoDelay();
    virtual int32_t getTrafficClass();
    virtual bool isBound();
    virtual bool isClosed();
    virtual bool isConnected();
    virtual bool isInputShutdown();
    virtual bool isOutputShutdown();

public: /* package */
    void postAccept();

public:
    virtual void sendUrgentData(int32_t arg0);

public: /* package */
    virtual void setBound();
    virtual void setConnected();
    virtual void setCreated();
    virtual void setImpl();

public:
    virtual void setKeepAlive(bool arg0);
    virtual void setOOBInline(bool arg0);
    virtual void setPerformancePreferences(int32_t arg0, int32_t arg1, int32_t arg2);
    virtual void setReceiveBufferSize(int32_t arg0);
    virtual void setReuseAddress(bool arg0);
    virtual void setSendBufferSize(int32_t arg0);
    virtual void setSoLinger(bool arg0, int32_t arg1);
    virtual void setSoTimeout(int32_t arg0);
    static void setSocketImplFactory(SocketImplFactory* arg0);
    virtual void setTcpNoDelay(bool arg0);
    virtual void setTrafficClass(int32_t arg0);
    virtual void shutdownInput();
    virtual void shutdownOutput();
    ::java::lang::String* toString() override;

    // Generated
    Socket();
    Socket(Proxy* arg0);

public: /* protected */
    Socket(SocketImpl* arg0);

public:
    Socket(::java::lang::String* arg0, int32_t arg1);
    Socket(InetAddress* arg0, int32_t arg1);
    Socket(::java::lang::String* arg0, int32_t arg1, bool arg2);
    Socket(InetAddress* arg0, int32_t arg1, bool arg2);
    Socket(::java::lang::String* arg0, int32_t arg1, InetAddress* arg2, int32_t arg3);
    Socket(InetAddress* arg0, int32_t arg1, InetAddress* arg2, int32_t arg3);
protected:
    Socket(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    static SocketImplFactory*& factory();
    virtual ::java::lang::Class* getClass0();
};
