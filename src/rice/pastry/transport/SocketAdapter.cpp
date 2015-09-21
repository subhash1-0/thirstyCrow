// Generated from /pastry-2.1/src/rice/pastry/transport/SocketAdapter.java
#include <rice/pastry/transport/SocketAdapter.hpp>

#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/Class.hpp>
#include <java/lang/Comparable.hpp>
#include <java/lang/IllegalStateException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/nio/Buffer.hpp>
#include <java/nio/ByteBuffer.hpp>
#include <org/mpisws/p2p/transport/P2PSocket.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/LogManager.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/p2p/commonapi/appsocket/AppSocketReceiver.hpp>
#include <SubArray.hpp>
#include <ObjectArray.hpp>

template<typename ComponentType, typename... Bases> struct SubArray;
namespace java
{
    namespace lang
    {
typedef ::SubArray< ::java::lang::Comparable, ObjectArray > ComparableArray;
    } // lang

    namespace nio
    {
typedef ::SubArray< ::java::nio::Buffer, ::java::lang::ObjectArray > BufferArray;
typedef ::SubArray< ::java::nio::ByteBuffer, BufferArray, ::java::lang::ComparableArray > ByteBufferArray;
    } // nio
} // java

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::pastry::transport::SocketAdapter::SocketAdapter(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::transport::SocketAdapter::SocketAdapter(::org::mpisws::p2p::transport::P2PSocket* socket, ::rice::environment::Environment* env) 
    : SocketAdapter(*static_cast< ::default_init_tag* >(0))
{
    ctor(socket,env);
}

void rice::pastry::transport::SocketAdapter::init()
{
    reader = nullptr;
    writer = nullptr;
}

void rice::pastry::transport::SocketAdapter::ctor(::org::mpisws::p2p::transport::P2PSocket* socket, ::rice::environment::Environment* env)
{
    super::ctor();
    init();
    this->internal = socket;
    this->logger = npc(npc(env)->getLogManager())->getLogger(SocketAdapter::class_(), nullptr);
    this->environment = env;
}

void rice::pastry::transport::SocketAdapter::close()
{
    npc(internal)->close();
}

int64_t rice::pastry::transport::SocketAdapter::read(::java::nio::ByteBufferArray* dsts, int32_t offset, int32_t length) /* throws(IOException) */
{
    int64_t ret = int32_t(0);
    for (auto i = offset; i < offset + length; i++) {
        ret += npc(internal)->read((*dsts)[i]);
    }
    return ret;
}

void rice::pastry::transport::SocketAdapter::register_(bool wantToRead, bool wantToWrite, int32_t timeout, ::rice::p2p::commonapi::appsocket::AppSocketReceiver* receiver)
{
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
    npc(internal)->register_(wantToRead, wantToWrite, this);
}

void rice::pastry::transport::SocketAdapter::receiveException(::org::mpisws::p2p::transport::P2PSocket* s, ::java::lang::Exception* e)
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
}

void rice::pastry::transport::SocketAdapter::receiveSelectResult(::org::mpisws::p2p::transport::P2PSocket* s, bool canRead, bool canWrite) /* throws(IOException) */
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINEST)
        npc(logger)->log(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(this))->append(u"rsr("_j)
            ->append(static_cast< ::java::lang::Object* >(internal))
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
                    ->append(static_cast< ::java::lang::Object* >(internal))
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
                    ->append(static_cast< ::java::lang::Object* >(internal))
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

void rice::pastry::transport::SocketAdapter::shutdownOutput()
{
    npc(internal)->shutdownOutput();
}

int64_t rice::pastry::transport::SocketAdapter::write(::java::nio::ByteBufferArray* srcs, int32_t offset, int32_t length) /* throws(IOException) */
{
    int64_t ret = int32_t(0);
    for (auto i = offset; i < offset + length; i++) {
        ret += npc(internal)->write((*srcs)[i]);
    }
    return ret;
}

int64_t rice::pastry::transport::SocketAdapter::read(::java::nio::ByteBuffer* dst) /* throws(IOException) */
{
    return npc(internal)->read(dst);
}

int64_t rice::pastry::transport::SocketAdapter::write(::java::nio::ByteBuffer* src) /* throws(IOException) */
{
    return npc(internal)->write(src);
}

java::lang::String* rice::pastry::transport::SocketAdapter::toString()
{
    return ::java::lang::StringBuilder().append(u"SA["_j)->append(static_cast< ::java::lang::Object* >(internal))
        ->append(u"]"_j)->toString();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::transport::SocketAdapter::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.transport.SocketAdapter", 35);
    return c;
}

java::lang::Class* rice::pastry::transport::SocketAdapter::getClass0()
{
    return class_();
}

