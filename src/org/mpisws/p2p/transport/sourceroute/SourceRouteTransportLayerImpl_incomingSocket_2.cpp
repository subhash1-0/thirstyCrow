// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/sourceroute/SourceRouteTransportLayerImpl.java
#include <org/mpisws/p2p/transport/sourceroute/SourceRouteTransportLayerImpl_incomingSocket_2.hpp>

#include <java/io/IOException.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/nio/ByteBuffer.hpp>
#include <org/mpisws/p2p/transport/ErrorHandler.hpp>
#include <org/mpisws/p2p/transport/P2PSocket.hpp>
#include <org/mpisws/p2p/transport/TransportLayer.hpp>
#include <org/mpisws/p2p/transport/sourceroute/SourceRoute.hpp>
#include <org/mpisws/p2p/transport/sourceroute/SourceRouteFactory.hpp>
#include <org/mpisws/p2p/transport/sourceroute/SourceRouteForwardStrategy.hpp>
#include <org/mpisws/p2p/transport/sourceroute/SourceRouteTransportLayerImpl_incomingSocket_2_receiveSelectResult_2_1.hpp>
#include <org/mpisws/p2p/transport/sourceroute/SourceRouteTransportLayerImpl.hpp>
#include <org/mpisws/p2p/transport/util/InsufficientBytesException.hpp>
#include <org/mpisws/p2p/transport/util/SocketInputBuffer.hpp>
#include <rice/environment/logging/Logger.hpp>
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

org::mpisws::p2p::transport::sourceroute::SourceRouteTransportLayerImpl_incomingSocket_2::SourceRouteTransportLayerImpl_incomingSocket_2(SourceRouteTransportLayerImpl *SourceRouteTransportLayerImpl_this, ::org::mpisws::p2p::transport::util::SocketInputBuffer* sib, ::org::mpisws::p2p::transport::P2PSocket* socka)
    : super(*static_cast< ::default_init_tag* >(0))
    , SourceRouteTransportLayerImpl_this(SourceRouteTransportLayerImpl_this)
    , sib(sib)
    , socka(socka)
{
    clinit();
    ctor();
}

void org::mpisws::p2p::transport::sourceroute::SourceRouteTransportLayerImpl_incomingSocket_2::receiveSelectResult(::org::mpisws::p2p::transport::P2PSocket* socket, bool canRead, bool canWrite) /* throws(IOException) */
{
    if(npc(SourceRouteTransportLayerImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINER)
        npc(SourceRouteTransportLayerImpl_this->logger)->log(::java::lang::StringBuilder().append(u"incomingSocket("_j)->append(static_cast< ::java::lang::Object* >(socket))
            ->append(u"):receiveSelectResult()"_j)->toString());

    if(canWrite || !canRead)
        throw new ::java::io::IOException(::java::lang::StringBuilder().append(u"Expected to read! "_j)->append(canRead)
            ->append(u","_j)
            ->append(canWrite)->toString());

    try {
        auto const sr = npc(SourceRouteTransportLayerImpl_this->srFactory)->build(sib, java_cast< ::java::lang::Object* >(npc(SourceRouteTransportLayerImpl_this->etl)->getLocalIdentifier()), java_cast< ::java::lang::Object* >(npc(socka)->getIdentifier()));
        if(npc(SourceRouteTransportLayerImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINEST)
            npc(SourceRouteTransportLayerImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Read socket "_j)->append(static_cast< ::java::lang::Object* >(sr))->toString());

        if(npc(java_cast< ::java::lang::Object* >(npc(sr)->getLastHop()))->equals(java_cast< ::java::lang::Object* >(npc(SourceRouteTransportLayerImpl_this->etl)->getLocalIdentifier()))) {
            SourceRouteTransportLayerImpl_this->incomingSocketHelper(socket, npc(SourceRouteTransportLayerImpl_this->srFactory)->reverse(sr));
        } else {
            auto hopNum = npc(sr)->getHop(static_cast< ::java::lang::Object* >(java_cast< ::java::lang::Object* >(npc(SourceRouteTransportLayerImpl_this->etl)->getLocalIdentifier())));
            if(hopNum < 1) {
                npc(sib)->reset();
                auto dump = new ::int8_tArray(npc(sib)->size());
                npc(sib)->read(dump);
                npc(SourceRouteTransportLayerImpl_this->errorHandler)->receivedUnexpectedData(sr, dump, 0, nullptr);
                npc(socka)->close();
                return;
            }
            npc(sib)->reset();
            auto srbytes = new ::int8_tArray(npc(sib)->size());
            npc(sib)->read(srbytes);
            auto const b = ::java::nio::ByteBuffer::wrap(srbytes);
            if(npc(SourceRouteTransportLayerImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINER)
                npc(SourceRouteTransportLayerImpl_this->logger)->log(::java::lang::StringBuilder().append(u"I'm hop "_j)->append(hopNum)
                    ->append(u" in "_j)
                    ->append(static_cast< ::java::lang::Object* >(sr))->toString());

            auto nextHop = java_cast< ::java::lang::Object* >(npc(sr)->getHop(hopNum + int32_t(1)));
            if(npc(SourceRouteTransportLayerImpl_this->forwardSourceRouteStrategy)->forward(nextHop, sr, true, npc(socka)->getOptions())) {
                if(npc(SourceRouteTransportLayerImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINEST)
                    npc(SourceRouteTransportLayerImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Attempting to open next hop "_j)->append(static_cast< ::java::lang::Object* >(nextHop))
                        ->append(u" <"_j)
                        ->append(hopNum)
                        ->append(u"> in "_j)
                        ->append(static_cast< ::java::lang::Object* >(sr))->toString());

                npc(SourceRouteTransportLayerImpl_this->etl)->openSocket(nextHop, new SourceRouteTransportLayerImpl_incomingSocket_2_receiveSelectResult_2_1(this, b, sr, socka), nullptr);
            } else {
                if(npc(SourceRouteTransportLayerImpl_this->logger)->level <= ::rice::environment::logging::Logger::INFO)
                    npc(SourceRouteTransportLayerImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Rejecting opening next hop "_j)->append(static_cast< ::java::lang::Object* >(nextHop))
                        ->append(u" <"_j)
                        ->append(hopNum)
                        ->append(u"> in "_j)
                        ->append(static_cast< ::java::lang::Object* >(sr))->toString());

                npc(socka)->close();
            }
        }
    } catch (::org::mpisws::p2p::transport::util::InsufficientBytesException* ibe) {
        npc(socket)->register_(true, false, this);
    } catch (::java::io::IOException* e) {
        if(npc(SourceRouteTransportLayerImpl_this->logger)->level <= ::rice::environment::logging::Logger::INFO)
            npc(SourceRouteTransportLayerImpl_this->errorHandler)->receivedException(npc(SourceRouteTransportLayerImpl_this->srFactory)->getSourceRoute(java_cast< ::java::lang::Object* >(npc(SourceRouteTransportLayerImpl_this->etl)->getLocalIdentifier()), java_cast< ::java::lang::Object* >(npc(socket)->getIdentifier())), e);

        npc(socka)->close();
    }
}

void org::mpisws::p2p::transport::sourceroute::SourceRouteTransportLayerImpl_incomingSocket_2::receiveException(::org::mpisws::p2p::transport::P2PSocket* socket, ::java::lang::Exception* e)
{
    npc(SourceRouteTransportLayerImpl_this->errorHandler)->receivedException(npc(SourceRouteTransportLayerImpl_this->srFactory)->getSourceRoute(java_cast< ::java::lang::Object* >(npc(SourceRouteTransportLayerImpl_this->etl)->getLocalIdentifier()), java_cast< ::java::lang::Object* >(npc(socket)->getIdentifier())), e);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::sourceroute::SourceRouteTransportLayerImpl_incomingSocket_2::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::sourceroute::SourceRouteTransportLayerImpl_incomingSocket_2::getClass0()
{
    return class_();
}

