// Generated from /pastry-2.1/src/rice/tutorial/transportlayer/BandwidthLimitingTransportLayer.java
#include <rice/tutorial/transportlayer/BandwidthLimitingTransportLayer_BandwidthLimitingSocket.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/nio/ByteBuffer.hpp>
#include <java/util/Collection.hpp>
#include <org/mpisws/p2p/transport/ErrorHandler.hpp>
#include <org/mpisws/p2p/transport/P2PSocket.hpp>
#include <org/mpisws/p2p/transport/P2PSocketReceiver.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/tutorial/transportlayer/BandwidthLimitingTransportLayer.hpp>

template<typename T, typename U>
static T java_cast(U* u)
{
    if(!u) return static_cast<T>(nullptr);
    auto t = dynamic_cast<T>(u);
    if(!t) throw new ::java::lang::ClassCastException();
    return t;
}

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

extern void lock(::java::lang::Object *);
extern void unlock(::java::lang::Object *);

namespace
{
    struct synchronized
    {
        synchronized(::java::lang::Object *o) : o(o) { ::lock(o); }
        ~synchronized() { ::unlock(o); }
    private:
        synchronized(const synchronized&); synchronized& operator=(const synchronized&);
        ::java::lang::Object *o;
    };
}
rice::tutorial::transportlayer::BandwidthLimitingTransportLayer_BandwidthLimitingSocket::BandwidthLimitingTransportLayer_BandwidthLimitingSocket(BandwidthLimitingTransportLayer *BandwidthLimitingTransportLayer_this, const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
    , BandwidthLimitingTransportLayer_this(BandwidthLimitingTransportLayer_this)
{
    clinit();
}

rice::tutorial::transportlayer::BandwidthLimitingTransportLayer_BandwidthLimitingSocket::BandwidthLimitingTransportLayer_BandwidthLimitingSocket(BandwidthLimitingTransportLayer *BandwidthLimitingTransportLayer_this, ::org::mpisws::p2p::transport::P2PSocket* socket) 
    : BandwidthLimitingTransportLayer_BandwidthLimitingSocket(BandwidthLimitingTransportLayer_this, *static_cast< ::default_init_tag* >(0))
{
    ctor(socket);
}

void rice::tutorial::transportlayer::BandwidthLimitingTransportLayer_BandwidthLimitingSocket::ctor(::org::mpisws::p2p::transport::P2PSocket* socket)
{
    super::ctor(java_cast< ::java::lang::Object* >(npc(socket)->getIdentifier()), socket, BandwidthLimitingTransportLayer_this->logger, java_cast< ::org::mpisws::p2p::transport::ErrorHandler* >(BandwidthLimitingTransportLayer_this->errorHandler), npc(socket)->getOptions());
    {
        synchronized synchronized_0(BandwidthLimitingTransportLayer_this);
        {
            npc(BandwidthLimitingTransportLayer_this->sockets)->add(this);
        }
    }
}

int64_t rice::tutorial::transportlayer::BandwidthLimitingTransportLayer_BandwidthLimitingSocket::write(::java::nio::ByteBuffer* srcs) /* throws(IOException) */
{
    if(npc(srcs)->remaining() <= BandwidthLimitingTransportLayer_this->bucket) {
        auto ret = super::write(srcs);
        if(ret >= 0) {
            {
                synchronized synchronized_1(this);
                {
                    BandwidthLimitingTransportLayer_this->bucket -= ret;
                }
            }
        }
        return ret;
    }
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(::java::lang::StringBuilder().append(u"Limiting "_j)->append(static_cast< ::java::lang::Object* >(socket))
            ->append(u" to "_j)
            ->append(BandwidthLimitingTransportLayer_this->bucket)
            ->append(u" bytes."_j)->toString());

    auto originalPosition = npc(srcs)->position();
    auto temp = ::java::nio::ByteBuffer::wrap(npc(srcs)->array(), originalPosition, BandwidthLimitingTransportLayer_this->bucket);
    auto ret = super::write(temp);
    if(ret < 0) {
        return ret;
    }
    {
        synchronized synchronized_2(this);
        {
            BandwidthLimitingTransportLayer_this->bucket -= ret;
        }
    }
    npc(srcs)->position(originalPosition + static_cast< int32_t >(ret));
    return ret;
}

void rice::tutorial::transportlayer::BandwidthLimitingTransportLayer_BandwidthLimitingSocket::register_(bool wantToRead, bool wantToWrite, ::org::mpisws::p2p::transport::P2PSocketReceiver* receiver)
{
    auto canWrite = wantToWrite;
    if(wantToWrite == true && BandwidthLimitingTransportLayer_this->bucket == 0) {
        canWrite = false;
        storedWriter = receiver;
    }
    if(wantToRead || canWrite)
        super::register_(wantToRead, canWrite, static_cast< ::org::mpisws::p2p::transport::P2PSocketReceiver* >(receiver));

}

void rice::tutorial::transportlayer::BandwidthLimitingTransportLayer_BandwidthLimitingSocket::notifyBandwidthRefilled()
{
    if(storedWriter != nullptr) {
        auto temp = storedWriter;
        storedWriter = nullptr;
        super::register_(false, true, static_cast< ::org::mpisws::p2p::transport::P2PSocketReceiver* >(temp));
    }
}

void rice::tutorial::transportlayer::BandwidthLimitingTransportLayer_BandwidthLimitingSocket::close()
{
    super::close();
    {
        synchronized synchronized_3(BandwidthLimitingTransportLayer_this);
        {
            npc(BandwidthLimitingTransportLayer_this->sockets)->remove(this);
        }
    }
}

void rice::tutorial::transportlayer::BandwidthLimitingTransportLayer_BandwidthLimitingSocket::shutdownOutput()
{
    super::shutdownOutput();
    {
        synchronized synchronized_4(BandwidthLimitingTransportLayer_this);
        {
            npc(BandwidthLimitingTransportLayer_this->sockets)->remove(this);
        }
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::tutorial::transportlayer::BandwidthLimitingTransportLayer_BandwidthLimitingSocket::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.tutorial.transportlayer.BandwidthLimitingTransportLayer.BandwidthLimitingSocket", 84);
    return c;
}

java::lang::Class* rice::tutorial::transportlayer::BandwidthLimitingTransportLayer_BandwidthLimitingSocket::getClass0()
{
    return class_();
}

