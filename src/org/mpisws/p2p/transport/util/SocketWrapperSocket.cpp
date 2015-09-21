// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/util/SocketWrapperSocket.java
#include <org/mpisws/p2p/transport/util/SocketWrapperSocket.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/IllegalStateException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/util/Map.hpp>
#include <org/mpisws/p2p/transport/ErrorHandler.hpp>
#include <org/mpisws/p2p/transport/P2PSocket.hpp>
#include <org/mpisws/p2p/transport/P2PSocketReceiver.hpp>
#include <rice/environment/logging/Logger.hpp>

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

org::mpisws::p2p::transport::util::SocketWrapperSocket::SocketWrapperSocket(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::transport::util::SocketWrapperSocket::SocketWrapperSocket(::java::lang::Object* identifier, ::org::mpisws::p2p::transport::P2PSocket* socket, ::rice::environment::logging::Logger* logger, ::org::mpisws::p2p::transport::ErrorHandler* errorHandler, ::java::util::Map* options) 
    : SocketWrapperSocket(*static_cast< ::default_init_tag* >(0))
{
    ctor(identifier,socket,logger,errorHandler,options);
}

void org::mpisws::p2p::transport::util::SocketWrapperSocket::ctor(::java::lang::Object* identifier, ::org::mpisws::p2p::transport::P2PSocket* socket, ::rice::environment::logging::Logger* logger, ::org::mpisws::p2p::transport::ErrorHandler* errorHandler, ::java::util::Map* options)
{
    super::ctor();
    this->identifier = identifier;
    this->socket = socket;
    this->logger = logger;
    this->options = options;
    this->errorHandler = errorHandler;
}

java::lang::Object* org::mpisws::p2p::transport::util::SocketWrapperSocket::getIdentifier()
{
    return java_cast< ::java::lang::Object* >(identifier);
}

void org::mpisws::p2p::transport::util::SocketWrapperSocket::close()
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER) {
        npc(logger)->logException(::java::lang::StringBuilder().append(u"Closing "_j)->append(static_cast< ::java::lang::Object* >(this))->toString(), new ::java::lang::Exception(u"Stack Trace"_j));
    } else if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(::java::lang::StringBuilder().append(u"Closing "_j)->append(static_cast< ::java::lang::Object* >(this))->toString());

    npc(socket)->close();
}

int64_t org::mpisws::p2p::transport::util::SocketWrapperSocket::read(::java::nio::ByteBuffer* dsts) /* throws(IOException) */
{
    auto ret = npc(socket)->read(dsts);
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINEST)
        npc(logger)->log(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(this))->append(u"read():"_j)
            ->append(ret)->toString());

    return ret;
}

void org::mpisws::p2p::transport::util::SocketWrapperSocket::register_(bool wantToRead, bool wantToWrite, ::org::mpisws::p2p::transport::P2PSocketReceiver* receiver)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINEST)
        npc(logger)->log(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(this))->append(u"register("_j)
            ->append(wantToRead)
            ->append(u","_j)
            ->append(wantToWrite)
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(receiver))
            ->append(u")"_j)->toString());

    if(wantToRead) {
        if(reader != nullptr && reader != receiver)
            throw new ::java::lang::IllegalStateException(::java::lang::StringBuilder().append(u"Already registered "_j)->append(static_cast< ::java::lang::Object* >(reader))
                ->append(u" for reading. Can't register "_j)
                ->append(static_cast< ::java::lang::Object* >(receiver))->toString());

        reader = receiver;
    }
    if(wantToWrite) {
        if(writer != nullptr && writer != receiver)
            throw new ::java::lang::IllegalStateException(::java::lang::StringBuilder().append(u"Already registered "_j)->append(static_cast< ::java::lang::Object* >(reader))
                ->append(u" for writing. Can't register "_j)
                ->append(static_cast< ::java::lang::Object* >(receiver))->toString());

        writer = receiver;
    }
    npc(socket)->register_(wantToRead, wantToWrite, this);
}

void org::mpisws::p2p::transport::util::SocketWrapperSocket::receiveSelectResult(::org::mpisws::p2p::transport::P2PSocket* socket, bool canRead, bool canWrite) /* throws(IOException) */
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINEST)
        npc(logger)->log(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(this))->append(u"rsr("_j)
            ->append(static_cast< ::java::lang::Object* >(socket))
            ->append(u","_j)
            ->append(canRead)
            ->append(u","_j)
            ->append(canWrite)
            ->append(u")"_j)->toString());

    if(canRead && canWrite && (reader == writer)) {
        auto temp = reader;
        reader = nullptr;
        writer = nullptr;
        npc(temp)->receiveSelectResult(this, canRead, canWrite);
        return;
    }
    if(canRead) {
        auto temp = reader;
        if(temp == nullptr) {
            if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                npc(logger)->log(::java::lang::StringBuilder().append(u"no reader in "_j)->append(static_cast< ::java::lang::Object* >(this))
                    ->append(u".rsr("_j)
                    ->append(static_cast< ::java::lang::Object* >(socket))
                    ->append(u","_j)
                    ->append(canRead)
                    ->append(u","_j)
                    ->append(canWrite)
                    ->append(u")"_j)->toString());

        } else {
            reader = nullptr;
            npc(temp)->receiveSelectResult(this, true, false);
        }
    }
    if(canWrite) {
        auto temp = writer;
        if(temp == nullptr) {
            if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                npc(logger)->log(::java::lang::StringBuilder().append(u"no writer in "_j)->append(static_cast< ::java::lang::Object* >(this))
                    ->append(u".rsr("_j)
                    ->append(static_cast< ::java::lang::Object* >(socket))
                    ->append(u","_j)
                    ->append(canRead)
                    ->append(u","_j)
                    ->append(canWrite)
                    ->append(u")"_j)->toString());

        } else {
            writer = nullptr;
            npc(temp)->receiveSelectResult(this, false, true);
        }
    }
}

void org::mpisws::p2p::transport::util::SocketWrapperSocket::receiveException(::org::mpisws::p2p::transport::P2PSocket* socket, ::java::lang::Exception* e)
{
    if(writer != nullptr) {
        if(writer == reader) {
            auto temp = writer;
            writer = nullptr;
            reader = nullptr;
            npc(temp)->receiveException(this, e);
        } else {
            auto temp = writer;
            writer = nullptr;
            npc(temp)->receiveException(this, e);
        }
    }
    if(reader != nullptr) {
        auto temp = reader;
        reader = nullptr;
        npc(temp)->receiveException(this, e);
    }
    if(reader == nullptr && writer == nullptr && errorHandler != nullptr)
        npc(errorHandler)->receivedException(java_cast< ::java::lang::Object* >(getIdentifier()), e);

}

void org::mpisws::p2p::transport::util::SocketWrapperSocket::shutdownOutput()
{
    npc(socket)->shutdownOutput();
}

int64_t org::mpisws::p2p::transport::util::SocketWrapperSocket::write(::java::nio::ByteBuffer* srcs) /* throws(IOException) */
{
    auto ret = npc(socket)->write(srcs);
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINEST)
        npc(logger)->log(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(this))->append(u"write():"_j)
            ->append(ret)->toString());

    return ret;
}

java::lang::String* org::mpisws::p2p::transport::util::SocketWrapperSocket::toString()
{
    if(static_cast< ::java::lang::Object* >(java_cast< ::java::lang::Object* >(getIdentifier())) == static_cast< ::java::lang::Object* >(java_cast< ::java::lang::Object* >(npc(socket)->getIdentifier())))
        return npc(socket)->toString();

    return ::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(java_cast< ::java::lang::Object* >(identifier)))->append(u"-"_j)
        ->append(static_cast< ::java::lang::Object* >(socket))->toString();
}

java::util::Map* org::mpisws::p2p::transport::util::SocketWrapperSocket::getOptions()
{
    return options;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::util::SocketWrapperSocket::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.util.SocketWrapperSocket", 49);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::util::SocketWrapperSocket::getClass0()
{
    return class_();
}

