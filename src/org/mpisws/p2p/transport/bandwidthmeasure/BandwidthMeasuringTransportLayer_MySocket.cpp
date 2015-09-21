// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/bandwidthmeasure/BandwidthMeasuringTransportLayer.java
#include <org/mpisws/p2p/transport/bandwidthmeasure/BandwidthMeasuringTransportLayer_MySocket.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/nio/ByteBuffer.hpp>
#include <java/util/Collection.hpp>
#include <java/util/Map.hpp>
#include <org/mpisws/p2p/transport/ErrorHandler.hpp>
#include <org/mpisws/p2p/transport/P2PSocket.hpp>
#include <org/mpisws/p2p/transport/P2PSocketReceiver.hpp>
#include <org/mpisws/p2p/transport/bandwidthmeasure/BandwidthMeasuringTransportLayer.hpp>
#include <rice/p2p/util/tuples/Tuple.hpp>
#include <Array.hpp>

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
org::mpisws::p2p::transport::bandwidthmeasure::BandwidthMeasuringTransportLayer_MySocket::BandwidthMeasuringTransportLayer_MySocket(BandwidthMeasuringTransportLayer *BandwidthMeasuringTransportLayer_this, const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
    , BandwidthMeasuringTransportLayer_this(BandwidthMeasuringTransportLayer_this)
{
    clinit();
}

org::mpisws::p2p::transport::bandwidthmeasure::BandwidthMeasuringTransportLayer_MySocket::BandwidthMeasuringTransportLayer_MySocket(BandwidthMeasuringTransportLayer *BandwidthMeasuringTransportLayer_this, ::java::lang::Object* identifier, ::org::mpisws::p2p::transport::P2PSocket* socket, ::rice::environment::logging::Logger* logger, ::org::mpisws::p2p::transport::ErrorHandler* errorHandler, ::java::util::Map* options) 
    : BandwidthMeasuringTransportLayer_MySocket(BandwidthMeasuringTransportLayer_this, *static_cast< ::default_init_tag* >(0))
{
    ctor(identifier,socket,logger,errorHandler,options);
}

void org::mpisws::p2p::transport::bandwidthmeasure::BandwidthMeasuringTransportLayer_MySocket::close()
{
    {
        synchronized synchronized_0(BandwidthMeasuringTransportLayer_this->measured);
        {
            npc(java_cast< ::java::util::Collection* >(npc(BandwidthMeasuringTransportLayer_this->getVals(java_cast< ::java::lang::Object* >(identifier)))->b()))->remove(this);
        }
    }
    super::close();
}

void org::mpisws::p2p::transport::bandwidthmeasure::BandwidthMeasuringTransportLayer_MySocket::receiveException(::org::mpisws::p2p::transport::P2PSocket* socket, ::java::lang::Exception* e)
{
    {
        synchronized synchronized_1(BandwidthMeasuringTransportLayer_this->measured);
        {
            npc(java_cast< ::java::util::Collection* >(npc(BandwidthMeasuringTransportLayer_this->getVals(java_cast< ::java::lang::Object* >(identifier)))->b()))->remove(this);
        }
    }
    super::receiveException(static_cast< ::org::mpisws::p2p::transport::P2PSocket* >(socket), e);
}

bool org::mpisws::p2p::transport::bandwidthmeasure::BandwidthMeasuringTransportLayer_MySocket::wantsToWrite()
{
    return (writer != nullptr);
}

void org::mpisws::p2p::transport::bandwidthmeasure::BandwidthMeasuringTransportLayer_MySocket::register_(bool wantToRead, bool wantToWrite, ::org::mpisws::p2p::transport::P2PSocketReceiver* receiver)
{
    super::register_(wantToRead, wantToWrite, static_cast< ::org::mpisws::p2p::transport::P2PSocketReceiver* >(receiver));
}

void org::mpisws::p2p::transport::bandwidthmeasure::BandwidthMeasuringTransportLayer_MySocket::ctor(::java::lang::Object* identifier, ::org::mpisws::p2p::transport::P2PSocket* socket, ::rice::environment::logging::Logger* logger, ::org::mpisws::p2p::transport::ErrorHandler* errorHandler, ::java::util::Map* options)
{
    super::ctor(identifier, socket, logger, errorHandler, options);
    {
        synchronized synchronized_2(BandwidthMeasuringTransportLayer_this->measured);
        {
            npc(java_cast< ::java::util::Collection* >(npc(BandwidthMeasuringTransportLayer_this->getVals(identifier))->b()))->add(this);
        }
    }
}

int64_t org::mpisws::p2p::transport::bandwidthmeasure::BandwidthMeasuringTransportLayer_MySocket::write(::java::nio::ByteBuffer* srcs) /* throws(IOException) */
{
    auto ret = super::write(srcs);
    {
        synchronized synchronized_3(BandwidthMeasuringTransportLayer_this->measured);
        {
            auto vals = java_cast< ::int32_tArray* >(npc(BandwidthMeasuringTransportLayer_this->getVals(java_cast< ::java::lang::Object* >(getIdentifier())))->a());
            if(npc(srcs)->hasRemaining()) {
                (*vals)[BandwidthMeasuringTransportLayer::CUR_SATURATED] = BandwidthMeasuringTransportLayer::SATURATED;
            }
            (*vals)[BandwidthMeasuringTransportLayer::CUR_UP] += ret;
        }
    }
    return ret;
}

int64_t org::mpisws::p2p::transport::bandwidthmeasure::BandwidthMeasuringTransportLayer_MySocket::read(::java::nio::ByteBuffer* srcs) /* throws(IOException) */
{
    auto ret = super::read(srcs);
    {
        synchronized synchronized_4(BandwidthMeasuringTransportLayer_this->measured);
        {
            auto vals = java_cast< ::int32_tArray* >(npc(BandwidthMeasuringTransportLayer_this->getVals(java_cast< ::java::lang::Object* >(getIdentifier())))->a());
            (*vals)[BandwidthMeasuringTransportLayer::CUR_DOWN] += ret;
        }
    }
    return ret;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::bandwidthmeasure::BandwidthMeasuringTransportLayer_MySocket::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.bandwidthmeasure.BandwidthMeasuringTransportLayer.MySocket", 83);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::bandwidthmeasure::BandwidthMeasuringTransportLayer_MySocket::getClass0()
{
    return class_();
}

