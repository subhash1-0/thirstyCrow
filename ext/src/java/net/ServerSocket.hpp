// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/net/fwd-pastry-2.1.hpp>
#include <java/nio/channels/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <java/io/Closeable.hpp>

struct default_init_tag;

class java::net::ServerSocket
    : public virtual ::java::lang::Object
    , public virtual ::java::io::Closeable
{

public:
    typedef ::java::lang::Object super;

private:
    bool bound {  };
    ::java::lang::Object* closeLock {  };
    bool closed {  };
    bool created {  };
    static SocketImplFactory* factory_;
    SocketImpl* impl {  };
    bool oldImpl {  };

protected:
    void ctor();
    void ctor(SocketImpl* arg0);
    void ctor(int32_t arg0);
    void ctor(int32_t arg0, int32_t arg1);
    void ctor(int32_t arg0, int32_t arg1, InetAddress* arg2);

public:
    virtual Socket* accept();
    virtual void bind(SocketAddress* arg0);
    virtual void bind(SocketAddress* arg0, int32_t arg1);
    /*void checkOldImpl(); (private) */
    void close() override;

public: /* package */
    virtual void createImpl();

public:
    virtual ::java::nio::channels::ServerSocketChannel* getChannel();

public: /* package */
    virtual SocketImpl* getImpl();

public:
    virtual InetAddress* getInetAddress();
    virtual int32_t getLocalPort();
    virtual SocketAddress* getLocalSocketAddress();
    virtual int32_t getReceiveBufferSize();
    virtual bool getReuseAddress();
    virtual int32_t getSoTimeout();

public: /* protected */
    void implAccept(Socket* arg0);

public:
    virtual bool isBound();
    virtual bool isClosed();

public: /* package */
    virtual void setBound();
    virtual void setCreated();
    /*void setImpl(); (private) */

public:
    virtual void setPerformancePreferences(int32_t arg0, int32_t arg1, int32_t arg2);
    virtual void setReceiveBufferSize(int32_t arg0);
    virtual void setReuseAddress(bool arg0);
    virtual void setSoTimeout(int32_t arg0);
    static void setSocketFactory(SocketImplFactory* arg0);
    ::java::lang::String* toString() override;

    // Generated
    ServerSocket();

public: /* package */
    ServerSocket(SocketImpl* arg0);

public:
    ServerSocket(int32_t arg0);
    ServerSocket(int32_t arg0, int32_t arg1);
    ServerSocket(int32_t arg0, int32_t arg1, InetAddress* arg2);
protected:
    ServerSocket(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    static SocketImplFactory*& factory();
    virtual ::java::lang::Class* getClass0();
};
