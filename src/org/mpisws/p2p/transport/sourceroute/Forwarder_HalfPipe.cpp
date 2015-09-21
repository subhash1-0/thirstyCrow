// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/sourceroute/Forwarder.java
#include <org/mpisws/p2p/transport/sourceroute/Forwarder_HalfPipe.hpp>

#include <java/io/IOException.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/nio/ByteBuffer.hpp>
#include <org/mpisws/p2p/transport/P2PSocket.hpp>
#include <org/mpisws/p2p/transport/sourceroute/Forwarder.hpp>
#include <rice/environment/logging/Logger.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::transport::sourceroute::Forwarder_HalfPipe::Forwarder_HalfPipe(Forwarder *Forwarder_this, const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
    , Forwarder_this(Forwarder_this)
{
    clinit();
}

org::mpisws::p2p::transport::sourceroute::Forwarder_HalfPipe::Forwarder_HalfPipe(Forwarder *Forwarder_this, ::org::mpisws::p2p::transport::P2PSocket* from, ::org::mpisws::p2p::transport::P2PSocket* to) 
    : Forwarder_HalfPipe(Forwarder_this, *static_cast< ::default_init_tag* >(0))
{
    ctor(from,to);
}

void org::mpisws::p2p::transport::sourceroute::Forwarder_HalfPipe::init()
{
    shutdownTo = false;
}

void org::mpisws::p2p::transport::sourceroute::Forwarder_HalfPipe::ctor(::org::mpisws::p2p::transport::P2PSocket* from, ::org::mpisws::p2p::transport::P2PSocket* to)
{
    super::ctor();
    init();
    this->from = from;
    this->to = to;
    buf = ::java::nio::ByteBuffer::allocate(1024);
    npc(from)->register_(true, false, this);
}

java::lang::String* org::mpisws::p2p::transport::sourceroute::Forwarder_HalfPipe::toString()
{
    return ::java::lang::StringBuilder().append(u"HalfPipe "_j)->append(static_cast< ::java::lang::Object* >(from))
        ->append(u"=>"_j)
        ->append(static_cast< ::java::lang::Object* >(to))->toString();
}

void org::mpisws::p2p::transport::sourceroute::Forwarder_HalfPipe::receiveException(::org::mpisws::p2p::transport::P2PSocket* socket, ::java::lang::Exception* e)
{
    if(npc(Forwarder_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(Forwarder_this->logger)->logException(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(this))->append(u" "_j)
            ->append(static_cast< ::java::lang::Object* >(socket))->toString(), e);

    npc(from)->close();
    npc(to)->close();
}

void org::mpisws::p2p::transport::sourceroute::Forwarder_HalfPipe::receiveSelectResult(::org::mpisws::p2p::transport::P2PSocket* socket, bool canRead, bool canWrite) /* throws(IOException) */
{
    if(canRead) {
        if(socket != from)
            throw new ::java::io::IOException(::java::lang::StringBuilder().append(u"Expected to read from "_j)->append(static_cast< ::java::lang::Object* >(from))
                ->append(u" got "_j)
                ->append(static_cast< ::java::lang::Object* >(socket))->toString());

        auto result = npc(from)->read(buf);
        if(result == -int32_t(1)) {
            if(npc(Forwarder_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
                npc(Forwarder_this->logger)->log(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(from))->append(u" has shut down input, shutting down output on "_j)
                    ->append(static_cast< ::java::lang::Object* >(to))->toString());

            shutdownTo = true;
            return;
        }
        if(npc(Forwarder_this->logger)->level <= ::rice::environment::logging::Logger::FINER)
            npc(Forwarder_this->logger)->log(::java::lang::StringBuilder().append(u"Read "_j)->append(result)
                ->append(u" bytes from "_j)
                ->append(static_cast< ::java::lang::Object* >(from))->toString());

        npc(buf)->flip();
        npc(to)->register_(false, true, this);
    } else {
        if(canWrite) {
            if(socket != to)
                throw new ::java::io::IOException(::java::lang::StringBuilder().append(u"Expected to write to "_j)->append(static_cast< ::java::lang::Object* >(to))
                    ->append(u" got "_j)
                    ->append(static_cast< ::java::lang::Object* >(socket))->toString());

            auto result = npc(to)->write(buf);
            if(result == -int32_t(1)) {
                if(npc(Forwarder_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
                    npc(Forwarder_this->logger)->log(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(to))->append(u" has closed, closing "_j)
                        ->append(static_cast< ::java::lang::Object* >(from))->toString());

                npc(from)->close();
            }
            if(npc(Forwarder_this->logger)->level <= ::rice::environment::logging::Logger::FINER)
                npc(Forwarder_this->logger)->log(::java::lang::StringBuilder().append(u"Wrote "_j)->append(result)
                    ->append(u" bytes to "_j)
                    ->append(static_cast< ::java::lang::Object* >(to))->toString());

            if(npc(buf)->hasRemaining()) {
                npc(to)->register_(false, true, this);
            } else {
                if(shutdownTo) {
                    npc(to)->shutdownOutput();
                    return;
                }
                npc(buf)->clear();
                npc(from)->register_(true, false, this);
            }
        } else {
            throw new ::java::io::IOException(::java::lang::StringBuilder().append(u"Didn't select for either "_j)->append(static_cast< ::java::lang::Object* >(socket))
                ->append(u","_j)
                ->append(canRead)
                ->append(u","_j)
                ->append(canWrite)->toString());
        }
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::sourceroute::Forwarder_HalfPipe::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.sourceroute.Forwarder.HalfPipe", 55);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::sourceroute::Forwarder_HalfPipe::getClass0()
{
    return class_();
}

