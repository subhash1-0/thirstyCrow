// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/direct/DirectAppSocket.java
#include <org/mpisws/p2p/transport/direct/DirectAppSocket_DirectAppSocketEndpoint.hpp>

#include <java/io/IOException.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Math.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/nio/ByteBuffer.hpp>
#include <java/util/Iterator.hpp>
#include <java/util/LinkedList.hpp>
#include <java/util/Map.hpp>
#include <org/mpisws/p2p/transport/P2PSocketReceiver.hpp>
#include <org/mpisws/p2p/transport/direct/DirectAppSocket_DirectAppSocketEndpoint_register_3.hpp>
#include <org/mpisws/p2p/transport/direct/DirectAppSocket_DirectAppSocketEndpoint_register_4.hpp>
#include <org/mpisws/p2p/transport/direct/DirectAppSocket_DirectAppSocketEndpoint_shutdownOutput_5.hpp>
#include <org/mpisws/p2p/transport/direct/DirectAppSocket_DirectAppSocketEndpoint_read_1.hpp>
#include <org/mpisws/p2p/transport/direct/DirectAppSocket_DirectAppSocketEndpoint_write_2.hpp>
#include <org/mpisws/p2p/transport/direct/DirectAppSocket.hpp>
#include <org/mpisws/p2p/transport/direct/GenericNetworkSimulator.hpp>
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
org::mpisws::p2p::transport::direct::DirectAppSocket_DirectAppSocketEndpoint::DirectAppSocket_DirectAppSocketEndpoint(DirectAppSocket *DirectAppSocket_this, const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
    , DirectAppSocket_this(DirectAppSocket_this)
{
    clinit();
}

org::mpisws::p2p::transport::direct::DirectAppSocket_DirectAppSocketEndpoint::DirectAppSocket_DirectAppSocketEndpoint(DirectAppSocket *DirectAppSocket_this, ::java::lang::Object* localNodeHandle, ::rice::environment::logging::Logger* logger) 
    : DirectAppSocket_DirectAppSocketEndpoint(DirectAppSocket_this, *static_cast< ::default_init_tag* >(0))
{
    ctor(localNodeHandle,logger);
}

void org::mpisws::p2p::transport::direct::DirectAppSocket_DirectAppSocketEndpoint::init()
{
    seq = int32_t(0);
    bytesInFlight = int32_t(0);
    byteDeliveries = new ::java::util::LinkedList();
    firstOffset = int32_t(0);
}

void org::mpisws::p2p::transport::direct::DirectAppSocket_DirectAppSocketEndpoint::ctor(::java::lang::Object* localNodeHandle, ::rice::environment::logging::Logger* logger)
{
    super::ctor();
    init();
    this->localNodeHandle = localNodeHandle;
    this->logger = logger;
}

void org::mpisws::p2p::transport::direct::DirectAppSocket_DirectAppSocketEndpoint::setCounterpart(DirectAppSocket_DirectAppSocketEndpoint* counterpart)
{
    this->counterpart = counterpart;
}

java::lang::Object* org::mpisws::p2p::transport::direct::DirectAppSocket_DirectAppSocketEndpoint::getRemoteNodeHandle()
{
    return java_cast< ::java::lang::Object* >(npc(counterpart)->localNodeHandle);
}

int64_t org::mpisws::p2p::transport::direct::DirectAppSocket_DirectAppSocketEndpoint::read(::java::nio::ByteBuffer* dsts) /* throws(IOException) */
{
    auto lengthRead = int32_t(0);
    {
        synchronized synchronized_0(this);
        {
            if(npc(byteDeliveries)->isEmpty()) {
                return 0;
            }
            if(java_cast< ::int8_tArray* >(npc(byteDeliveries)->getFirst()) == DirectAppSocket::EOF_()) {
                return -int32_t(1);
            }
            auto i = npc(byteDeliveries)->iterator();
            while (npc(i)->hasNext()) {
                auto msg = java_cast< ::int8_tArray* >(java_cast< ::int8_tArray* >(npc(i)->next()));
                auto curBuffer = dsts;
                auto lengthToPut = npc(curBuffer)->remaining();
                if(lengthToPut > (npc(msg)->length - firstOffset)) {
                    lengthToPut = npc(msg)->length - firstOffset;
                }
                npc(curBuffer)->put(msg, firstOffset, lengthToPut);
                firstOffset += lengthToPut;
                lengthRead += lengthToPut;
                if(firstOffset == npc(msg)->length) {
                    npc(i)->remove();
                    firstOffset = 0;
                } else {
                    break;
                }
            }
        }
    }
    bytesInFlight -= lengthRead;
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
        npc(logger)->log(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(this))->append(u".write("_j)
            ->append(static_cast< ::java::lang::Object* >(dsts))
            ->append(u") len:"_j)
            ->append(lengthRead)
            ->append(u" inFlight:"_j)
            ->append(bytesInFlight)->toString());

    npc(DirectAppSocket_this->simulator)->enqueueDelivery(new DirectAppSocket_DirectAppSocketEndpoint_read_1(this), 0);
    return lengthRead;
}

int64_t org::mpisws::p2p::transport::direct::DirectAppSocket_DirectAppSocketEndpoint::write(::java::nio::ByteBuffer* srcs) /* throws(IOException) */
{
    if(outputClosed)
        return -int32_t(1);

    if(!npc(DirectAppSocket_this->simulator)->isAlive(java_cast< ::java::lang::Object* >(npc(counterpart)->localNodeHandle))) {
        return -int32_t(1);
    }
    auto availableToWrite = npc(srcs)->remaining();
    int32_t lengthToWrite;
    {
        synchronized synchronized_1(counterpart);
        {
            lengthToWrite = DirectAppSocket::MAX_BYTES_IN_FLIGHT - npc(counterpart)->bytesInFlight;
            if(lengthToWrite > availableToWrite)
                lengthToWrite = availableToWrite;

            npc(counterpart)->bytesInFlight += lengthToWrite;
        }
    }
    auto const msg = new ::int8_tArray(lengthToWrite);
    auto remaining = lengthToWrite;
    while (remaining > 0) {
        auto lengthToReadFromBuffer = npc(srcs)->remaining();
        if(remaining < lengthToReadFromBuffer)
            lengthToReadFromBuffer = remaining;

        npc(srcs)->get(msg, lengthToWrite - remaining, lengthToReadFromBuffer);
        remaining -= lengthToReadFromBuffer;
    }
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
        npc(logger)->log(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(this))->append(u".write("_j)
            ->append(static_cast< ::java::lang::Object* >(srcs))
            ->append(u") len:"_j)
            ->append(lengthToWrite)
            ->append(u" inFlight:"_j)
            ->append(npc(counterpart)->bytesInFlight)->toString());

    npc(DirectAppSocket_this->simulator)->enqueueDelivery(new DirectAppSocket_DirectAppSocketEndpoint_write_2(this, msg), static_cast< int32_t >(::java::lang::Math::round(npc(DirectAppSocket_this->simulator)->networkDelay(java_cast< ::java::lang::Object* >(localNodeHandle), java_cast< ::java::lang::Object* >(npc(counterpart)->localNodeHandle)))));
    return lengthToWrite;
}

void org::mpisws::p2p::transport::direct::DirectAppSocket_DirectAppSocketEndpoint::addToReadQueue(::int8_tArray* msg)
{
    {
        synchronized synchronized_2(this);
        {
            if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE) {
                if(msg == DirectAppSocket::EOF_()) {
                    npc(logger)->log(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(this))->append(u": addToReadQueue(EOF)"_j)->toString());
                } else {
                    npc(logger)->log(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(this))->append(u": addToReadQueue("_j)
                        ->append(npc(msg)->length)
                        ->append(u")"_j)->toString());
                }
            }
            npc(byteDeliveries)->addLast(static_cast< ::java::lang::Object* >(msg));
        }
    }
    notifyCanRead();
}

void org::mpisws::p2p::transport::direct::DirectAppSocket_DirectAppSocketEndpoint::notifyCanWrite()
{
    if(writer == nullptr)
        return;

    if(npc(counterpart)->bytesInFlight < DirectAppSocket::MAX_BYTES_IN_FLIGHT) {
        auto temp = writer;
        writer = nullptr;
        try {
            if(npc(logger)->level <= ::rice::environment::logging::Logger::FINEST)
                npc(logger)->log(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(this))->append(u".notifyCanWrite()"_j)->toString());

            npc(temp)->receiveSelectResult(this, false, true);
        } catch (::java::io::IOException* ioe) {
            npc(logger)->logException(::java::lang::StringBuilder().append(u"Error in "_j)->append(static_cast< ::java::lang::Object* >(temp))->toString(), ioe);
        }
    }
}

void org::mpisws::p2p::transport::direct::DirectAppSocket_DirectAppSocketEndpoint::notifyCanRead()
{
    if(npc(byteDeliveries)->isEmpty())
        return;

    if(reader != nullptr) {
        auto temp = reader;
        reader = nullptr;
        try {
            if(npc(logger)->level <= ::rice::environment::logging::Logger::FINEST)
                npc(logger)->log(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(this))->append(u".notifyCanRead()"_j)->toString());

            npc(temp)->receiveSelectResult(this, true, false);
        } catch (::java::io::IOException* ioe) {
            npc(logger)->logException(::java::lang::StringBuilder().append(u"Error in "_j)->append(static_cast< ::java::lang::Object* >(temp))->toString(), ioe);
        }
    }
}

void org::mpisws::p2p::transport::direct::DirectAppSocket_DirectAppSocketEndpoint::register_(bool wantToRead, bool wantToWrite, ::org::mpisws::p2p::transport::P2PSocketReceiver* receiver)
{
    if(wantToWrite) {
        writer = receiver;
        npc(DirectAppSocket_this->simulator)->enqueueDelivery(new DirectAppSocket_DirectAppSocketEndpoint_register_3(this), 0);
    }
    if(wantToRead) {
        reader = receiver;
        npc(DirectAppSocket_this->simulator)->enqueueDelivery(new DirectAppSocket_DirectAppSocketEndpoint_register_4(this), 0);
    }
}

void org::mpisws::p2p::transport::direct::DirectAppSocket_DirectAppSocketEndpoint::shutdownOutput()
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
        npc(logger)->log(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(this))->append(u".shutdownOutput()"_j)->toString());

    outputClosed = true;
    if(!npc(DirectAppSocket_this->simulator)->isAlive(java_cast< ::java::lang::Object* >(npc(counterpart)->localNodeHandle)))
        return;

    npc(DirectAppSocket_this->simulator)->enqueueDelivery(new DirectAppSocket_DirectAppSocketEndpoint_shutdownOutput_5(this), static_cast< int32_t >(::java::lang::Math::round(npc(DirectAppSocket_this->simulator)->networkDelay(java_cast< ::java::lang::Object* >(localNodeHandle), java_cast< ::java::lang::Object* >(npc(counterpart)->localNodeHandle)))));
}

void org::mpisws::p2p::transport::direct::DirectAppSocket_DirectAppSocketEndpoint::shutdownInput()
{
}

void org::mpisws::p2p::transport::direct::DirectAppSocket_DirectAppSocketEndpoint::close()
{
    shutdownOutput();
    shutdownInput();
}

java::lang::String* org::mpisws::p2p::transport::direct::DirectAppSocket_DirectAppSocketEndpoint::toString()
{
    return ::java::lang::StringBuilder().append(u"DAS{"_j)->append(static_cast< ::java::lang::Object* >(java_cast< ::java::lang::Object* >(localNodeHandle)))
        ->append(u":"_j)
        ->append(npc(DirectAppSocket_this->simulator)->isAlive(java_cast< ::java::lang::Object* >(localNodeHandle)))
        ->append(u"->"_j)
        ->append(static_cast< ::java::lang::Object* >(java_cast< ::java::lang::Object* >(npc(counterpart)->localNodeHandle)))
        ->append(u":"_j)
        ->append(npc(DirectAppSocket_this->simulator)->isAlive(java_cast< ::java::lang::Object* >(npc(counterpart)->localNodeHandle)))
        ->append(u" w:"_j)
        ->append(static_cast< ::java::lang::Object* >(writer))
        ->append(u" r:"_j)
        ->append(static_cast< ::java::lang::Object* >(reader))
        ->append(u"}"_j)->toString();
}

java::lang::Object* org::mpisws::p2p::transport::direct::DirectAppSocket_DirectAppSocketEndpoint::getIdentifier()
{
    return java_cast< ::java::lang::Object* >(getRemoteNodeHandle());
}

java::util::Map* org::mpisws::p2p::transport::direct::DirectAppSocket_DirectAppSocketEndpoint::getOptions()
{
    return DirectAppSocket_this->options;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::direct::DirectAppSocket_DirectAppSocketEndpoint::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.direct.DirectAppSocket.DirectAppSocketEndpoint", 71);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::direct::DirectAppSocket_DirectAppSocketEndpoint::getClass0()
{
    return class_();
}

