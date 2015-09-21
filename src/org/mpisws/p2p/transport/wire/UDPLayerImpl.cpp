// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/wire/UDPLayerImpl.java
#include <org/mpisws/p2p/transport/wire/UDPLayerImpl.hpp>

#include <java/io/IOException.hpp>
#include <java/lang/Class.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/Integer.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/Runnable.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/net/BindException.hpp>
#include <java/net/DatagramSocket.hpp>
#include <java/net/InetSocketAddress.hpp>
#include <java/net/SocketAddress.hpp>
#include <java/nio/ByteBuffer.hpp>
#include <java/nio/channels/DatagramChannel.hpp>
#include <java/nio/channels/SelectionKey.hpp>
#include <java/util/Collections.hpp>
#include <java/util/HashMap.hpp>
#include <java/util/Iterator.hpp>
#include <java/util/LinkedList.hpp>
#include <java/util/List.hpp>
#include <java/util/Map.hpp>
#include <org/mpisws/p2p/transport/ErrorHandler.hpp>
#include <org/mpisws/p2p/transport/MessageCallback.hpp>
#include <org/mpisws/p2p/transport/wire/UDPLayer.hpp>
#include <org/mpisws/p2p/transport/wire/UDPLayerImpl_destroy_1.hpp>
#include <org/mpisws/p2p/transport/wire/UDPLayerImpl_acceptMessages_2.hpp>
#include <org/mpisws/p2p/transport/wire/UDPLayerImpl_Envelope.hpp>
#include <org/mpisws/p2p/transport/wire/WireTransportLayer.hpp>
#include <org/mpisws/p2p/transport/wire/WireTransportLayerImpl.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/LogManager.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/environment/params/Parameters.hpp>
#include <rice/selector/SelectorManager.hpp>
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

namespace
{
    template<typename F>
    struct finally_
    {
        finally_(F f) : f(f), moved(false) { }
        finally_(finally_ &&x) : f(x.f), moved(false) { x.moved = true; }
        ~finally_() { if(!moved) f(); }
    private:
        finally_(const finally_&); finally_& operator=(const finally_&);
        F f;
        bool moved;
    };

    template<typename F> finally_<F> finally(F f) { return finally_<F>(f); }
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
org::mpisws::p2p::transport::wire::UDPLayerImpl::UDPLayerImpl(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::transport::wire::UDPLayerImpl::UDPLayerImpl(WireTransportLayerImpl* wire)  /* throws(IOException) */
    : UDPLayerImpl(*static_cast< ::default_init_tag* >(0))
{
    ctor(wire);
}

void org::mpisws::p2p::transport::wire::UDPLayerImpl::init()
{
    lastTimePrinted = int32_t(0);
}

java::util::Map*& org::mpisws::p2p::transport::wire::UDPLayerImpl::OPTIONS()
{
    clinit();
    return OPTIONS_;
}
java::util::Map* org::mpisws::p2p::transport::wire::UDPLayerImpl::OPTIONS_;

void org::mpisws::p2p::transport::wire::UDPLayerImpl::ctor(WireTransportLayerImpl* wire) /* throws(IOException) */
{
    super::ctor();
    init();
    this->wire = wire;
    this->logger = npc(npc(npc(wire)->environment)->getLogManager())->getLogger(UDPLayer::class_(), nullptr);
    this->pendingMsgs = new ::java::util::LinkedList();
    openServerSocket();
}

org::mpisws::p2p::transport::MessageRequestHandle* org::mpisws::p2p::transport::wire::UDPLayerImpl::sendMessage(::java::net::InetSocketAddress* destination, ::java::nio::ByteBuffer* msg, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options)
{
    UDPLayerImpl_Envelope* envelope;
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER - int32_t(3))
        npc(logger)->log(::java::lang::StringBuilder().append(u"sendMessage("_j)->append(static_cast< ::java::lang::Object* >(destination))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(msg))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(deliverAckToMe))
            ->append(u")"_j)->toString());

    envelope = new UDPLayerImpl_Envelope(this, destination, msg, deliverAckToMe, options);
    {
        synchronized synchronized_0(pendingMsgs);
        {
            npc(pendingMsgs)->add(static_cast< ::java::lang::Object* >(envelope));
        }
    }
    npc(npc(npc(wire)->environment)->getSelectorManager())->modifyKey(key);
    return envelope;
}

void org::mpisws::p2p::transport::wire::UDPLayerImpl::openServerSocket() /* throws(IOException) */
{
    auto p = npc(npc(wire)->environment)->getParameters();
    DATAGRAM_RECEIVE_BUFFER_SIZE = npc(p)->getInt(u"transport_wire_datagram_receive_buffer_size"_j);
    DATAGRAM_SEND_BUFFER_SIZE = npc(p)->getInt(u"transport_wire_datagram_send_buffer_size"_j);
    this->readBuffer = ::java::nio::ByteBuffer::allocateDirect(DATAGRAM_SEND_BUFFER_SIZE);
    try {
        channel = ::java::nio::channels::DatagramChannel::open();
        npc(channel)->configureBlocking(false);
        npc(npc(channel)->socket())->setReuseAddress(false);
        npc(npc(channel)->socket())->bind(npc(wire)->bindAddress);
        npc(npc(channel)->socket())->setSendBufferSize(DATAGRAM_SEND_BUFFER_SIZE);
        npc(npc(channel)->socket())->setReceiveBufferSize(DATAGRAM_RECEIVE_BUFFER_SIZE);
        key = npc(npc(npc(wire)->environment)->getSelectorManager())->register_(channel, this, 0);
        npc(key)->interestOps(::java::nio::channels::SelectionKey::OP_READ);
        if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
            npc(logger)->log(::java::lang::StringBuilder().append(u"UDPLayer bound to "_j)->append(static_cast< ::java::lang::Object* >(npc(wire)->bindAddress))->toString());

    } catch (::java::net::BindException* be) {
        throw new ::java::net::BindException(::java::lang::StringBuilder().append(u"Address already in use:"_j)->append(static_cast< ::java::lang::Object* >(npc(wire)->bindAddress))->toString());
    } catch (::java::io::IOException* e) {
        throw e;
    }
}

void org::mpisws::p2p::transport::wire::UDPLayerImpl::read(::java::nio::channels::SelectionKey* key)
{
    {
        auto finally0 = finally([&] {
            npc(readBuffer)->clear();
        });
        try {
            ::java::net::InetSocketAddress* address = nullptr;
            while ((address = java_cast< ::java::net::InetSocketAddress* >(npc(channel)->receive(readBuffer))) != nullptr) {
                npc(readBuffer)->flip();
                if(npc(readBuffer)->remaining() > 0) {
                    readHeader(address);
                    npc(readBuffer)->clear();
                } else {
                    if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
                        npc(logger)->log(u"(PM) Read from datagram channel, but no bytes were there - no bad, but wierd."_j);

                    break;
                }
            }
        } catch (::java::io::IOException* e) {
            npc(npc(wire)->errorHandler)->receivedException(nullptr, e);
        }
    }
}

void org::mpisws::p2p::transport::wire::UDPLayerImpl::readHeader(::java::net::InetSocketAddress* address) /* throws(IOException) */
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(::java::lang::StringBuilder().append(u"readHeader("_j)->append(static_cast< ::java::lang::Object* >(address))
            ->append(u","_j)
            ->append(npc(readBuffer)->remaining())
            ->append(u")"_j)->toString());

    auto remaining = new ::int8_tArray(npc(readBuffer)->remaining());
    npc(readBuffer)->get(remaining);
    npc(wire)->messageReceived(address, ::java::nio::ByteBuffer::wrap(remaining), OPTIONS_);
}

void org::mpisws::p2p::transport::wire::UDPLayerImpl::write(::java::nio::channels::SelectionKey* key)
{
    UDPLayerImpl_Envelope* write = nullptr;
    {
        auto finally1 = finally([&] {
            if(npc(pendingMsgs)->isEmpty())
                npc(key)->interestOps(npc(key)->interestOps() & ~::java::nio::channels::SelectionKey::OP_WRITE);

        });
        try {
            {
                synchronized synchronized_1(pendingMsgs);
                {
                    auto i = npc(pendingMsgs)->iterator();
                    while (npc(i)->hasNext()) {
                        write = java_cast< UDPLayerImpl_Envelope* >(npc(i)->next());
                        try {
                            auto len = npc(npc(write)->msg)->remaining();
                            if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE) {
                                npc(logger)->log(::java::lang::StringBuilder().append(u"writing "_j)->append(len)
                                    ->append(u" to "_j)
                                    ->append(static_cast< ::java::lang::Object* >(npc(write)->destination))->toString());
                            }
                            if(npc(channel)->send(npc(write)->msg, npc(write)->destination) == len) {
                                if(npc(write)->continuation != nullptr)
                                    npc(npc(write)->continuation)->ack(write);

                                npc(i)->remove();
                            } else {
                                break;
                            }
                        } catch (::java::io::IOException* e) {
                            if(npc(write)->continuation == nullptr) {
                                npc(npc(wire)->errorHandler)->receivedException(npc(write)->destination, e);
                            } else {
                                npc(npc(write)->continuation)->sendFailed(write, e);
                            }
                            npc(i)->remove();
                            return;
                        }
                    }
                }
            }
        } catch (::java::lang::Exception* e) {
            if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING) {
                npc(logger)->logException(::java::lang::StringBuilder().append(u"ERROR (datagrammanager:write) to "_j)->append(static_cast< ::java::lang::Object* >(npc(write)->destination))->toString(), e);
            }
        }
    }
}

void org::mpisws::p2p::transport::wire::UDPLayerImpl::modifyKey(::java::nio::channels::SelectionKey* key)
{
    {
        synchronized synchronized_2(pendingMsgs);
        {
            if(!npc(pendingMsgs)->isEmpty())
                npc(key)->interestOps(npc(key)->interestOps() | ::java::nio::channels::SelectionKey::OP_WRITE);

        }
    }
}

void org::mpisws::p2p::transport::wire::UDPLayerImpl::destroy()
{
    ::java::lang::Runnable* r = new UDPLayerImpl_destroy_1(this);
    if(npc(npc(npc(wire)->environment)->getSelectorManager())->isSelectorThread()) {
        npc(r)->run();
    } else {
        npc(npc(npc(wire)->environment)->getSelectorManager())->invoke(r);
    }
}

void org::mpisws::p2p::transport::wire::UDPLayerImpl::acceptMessages(bool b)
{
    ::java::lang::Runnable* r = new UDPLayerImpl_acceptMessages_2(this, b);
    if(npc(npc(npc(wire)->environment)->getSelectorManager())->isSelectorThread()) {
        npc(r)->run();
    } else {
        npc(npc(npc(wire)->environment)->getSelectorManager())->invoke(r);
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::wire::UDPLayerImpl::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.wire.UDPLayerImpl", 42);
    return c;
}

void org::mpisws::p2p::transport::wire::UDPLayerImpl::clinit()
{
    super::clinit();
    static bool in_cl_init = false;
struct clinit_ {
    clinit_() {
        in_cl_init = true;
        {
            ::java::util::Map* map = new ::java::util::HashMap();
            npc(map)->put(WireTransportLayer::OPTION_TRANSPORT_TYPE(), ::java::lang::Integer::valueOf(WireTransportLayer::TRANSPORT_TYPE_DATAGRAM));
            OPTIONS_ = ::java::util::Collections::unmodifiableMap(map);
        }
    }
};

    if(!in_cl_init) {
        static clinit_ clinit_instance;
    }
}

java::lang::Class* org::mpisws::p2p::transport::wire::UDPLayerImpl::getClass0()
{
    return class_();
}

