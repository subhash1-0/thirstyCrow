// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/net/fwd-pastry-2.1.hpp>
#include <java/nio/channels/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <java/io/Closeable.hpp>

struct default_init_tag;

class java::net::DatagramSocket
    : public virtual ::java::lang::Object
    , public virtual ::java::io::Closeable
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    static constexpr int32_t ST_CONNECTED { int32_t(1) };
    static constexpr int32_t ST_CONNECTED_NO_IMPL { int32_t(2) };
    static constexpr int32_t ST_NOT_CONNECTED { int32_t(0) };

private:
    bool bound {  };
    int32_t bytesLeftToFilter {  };
    ::java::lang::Object* closeLock {  };
    bool closed {  };

public: /* package */
    int32_t connectState {  };
    InetAddress* connectedAddress {  };
    int32_t connectedPort {  };

private:
    bool created {  };
    bool explicitFilter {  };
    static DatagramSocketImplFactory* factory_;

public: /* package */
    DatagramSocketImpl* impl {  };

private:
    static ::java::lang::Class* implClass_;

public: /* package */
    bool oldImpl {  };

protected:
    void ctor();
    void ctor(DatagramSocketImpl* arg0);
    void ctor(SocketAddress* arg0);
    void ctor(int32_t arg0);
    void ctor(int32_t arg0, InetAddress* arg1);

public:
    virtual void bind(SocketAddress* arg0);

public: /* package */
    virtual void checkAddress(InetAddress* arg0, ::java::lang::String* arg1);
    /*bool checkFiltering(DatagramPacket* arg0); (private) */
    /*void checkOldImpl(); (private) */

public:
    void close() override;
    virtual void connect(SocketAddress* arg0);
    virtual void connect(InetAddress* arg0, int32_t arg1);
    /*void connectInternal(InetAddress* arg0, int32_t arg1); (private) */

public: /* package */
    virtual void createImpl();

public:
    virtual void disconnect();
    virtual bool getBroadcast();
    virtual ::java::nio::channels::DatagramChannel* getChannel();

public: /* package */
    virtual DatagramSocketImpl* getImpl();

public:
    virtual InetAddress* getInetAddress();
    virtual InetAddress* getLocalAddress();
    virtual int32_t getLocalPort();
    virtual SocketAddress* getLocalSocketAddress();
    virtual int32_t getPort();
    virtual int32_t getReceiveBufferSize();
    virtual SocketAddress* getRemoteSocketAddress();
    virtual bool getReuseAddress();
    virtual int32_t getSendBufferSize();
    virtual int32_t getSoTimeout();
    virtual int32_t getTrafficClass();
    virtual bool isBound();
    virtual bool isClosed();
    virtual bool isConnected();
    virtual void receive(DatagramPacket* arg0);
    virtual void send(DatagramPacket* arg0);
    virtual void setBroadcast(bool arg0);
    static void setDatagramSocketImplFactory(DatagramSocketImplFactory* arg0);
    virtual void setReceiveBufferSize(int32_t arg0);
    virtual void setReuseAddress(bool arg0);
    virtual void setSendBufferSize(int32_t arg0);
    virtual void setSoTimeout(int32_t arg0);
    virtual void setTrafficClass(int32_t arg0);

    // Generated
    DatagramSocket();

public: /* protected */
    DatagramSocket(DatagramSocketImpl* arg0);

public:
    DatagramSocket(SocketAddress* arg0);
    DatagramSocket(int32_t arg0);
    DatagramSocket(int32_t arg0, InetAddress* arg1);
protected:
    DatagramSocket(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

public: /* package */
    static DatagramSocketImplFactory*& factory();
    static ::java::lang::Class*& implClass();

private:
    virtual ::java::lang::Class* getClass0();
};
