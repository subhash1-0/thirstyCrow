// Generated from /pastry-2.1/src/rice/p2p/past/PastImpl.java
#include <rice/p2p/past/PastImpl_PastImpl_1.hpp>

#include <java/io/IOException.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Comparable.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/nio/Buffer.hpp>
#include <java/nio/ByteBuffer.hpp>
#include <java/util/WeakHashMap.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/p2p/commonapi/Endpoint.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/commonapi/Message.hpp>
#include <rice/p2p/commonapi/appsocket/AppSocket.hpp>
#include <rice/p2p/commonapi/rawserialization/MessageDeserializer.hpp>
#include <rice/p2p/past/PastImpl.hpp>
#include <rice/p2p/past/messaging/PastMessage.hpp>
#include <rice/p2p/util/MathUtils.hpp>
#include <rice/p2p/util/rawserialization/SimpleInputBuffer.hpp>
#include <Array.hpp>
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

rice::p2p::past::PastImpl_PastImpl_1::PastImpl_PastImpl_1(PastImpl *PastImpl_this)
    : super(*static_cast< ::default_init_tag* >(0))
    , PastImpl_this(PastImpl_this)
{
    clinit();
    ctor();
}

void rice::p2p::past::PastImpl_PastImpl_1::receiveSocket(::rice::p2p::commonapi::appsocket::AppSocket* socket)
{
    if(npc(PastImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(PastImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Received Socket from "_j)->append(static_cast< ::java::lang::Object* >(socket))->toString());

    npc(socket)->register_(true, false, 10000, this);
    npc(PastImpl_this->endpoint)->accept(this);
}

void rice::p2p::past::PastImpl_PastImpl_1::receiveSelectResult(::rice::p2p::commonapi::appsocket::AppSocket* socket, bool canRead, bool canWrite)
{
    if(npc(PastImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINER)
        npc(PastImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Reading from "_j)->append(static_cast< ::java::lang::Object* >(socket))->toString());

    try {
        auto bb = java_cast< ::java::nio::ByteBufferArray* >(java_cast< ::java::lang::Object* >(npc(PastImpl_this->pendingSocketTransactions)->get(static_cast< ::java::lang::Object* >(socket))));
        if(bb == nullptr) {
            bb = new ::java::nio::ByteBufferArray(int32_t(1));
            bb->set(int32_t(0), ::java::nio::ByteBuffer::allocate(4));
            if(npc(socket)->read(bb, 0, 1) == -int32_t(1)) {
                close(socket);
                return;
            }
            auto sizeArr = npc((*bb)[int32_t(0)])->array();
            auto size = ::rice::p2p::util::MathUtils::byteArrayToInt(sizeArr);
            if(npc(PastImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINER)
                npc(PastImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Found object of size "_j)->append(size)
                    ->append(u" from "_j)
                    ->append(static_cast< ::java::lang::Object* >(socket))->toString());

            bb->set(int32_t(0), ::java::nio::ByteBuffer::allocate(size));
            npc(PastImpl_this->pendingSocketTransactions)->put(static_cast< ::java::lang::Object* >(socket), static_cast< ::java::lang::Object* >(bb));
        }
        if(npc(socket)->read(bb, 0, 1) == -int32_t(1)) {
            close(socket);
        }
        if(npc((*bb)[int32_t(0)])->remaining() == 0) {
            npc(PastImpl_this->pendingSocketTransactions)->remove(static_cast< ::java::lang::Object* >(socket));
            if(npc(PastImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINEST)
                npc(PastImpl_this->logger)->log(::java::lang::StringBuilder().append(u"bb[0].limit() "_j)->append(npc((*bb)[int32_t(0)])->limit())
                    ->append(u" bb[0].remaining() "_j)
                    ->append(npc((*bb)[int32_t(0)])->remaining())
                    ->append(u" from "_j)
                    ->append(static_cast< ::java::lang::Object* >(socket))->toString());

            auto sib = new ::rice::p2p::util::rawserialization::SimpleInputBuffer(npc((*bb)[int32_t(0)])->array());
            auto type = npc(sib)->readShort();
            auto result = java_cast< ::rice::p2p::past::messaging::PastMessage* >(npc(npc(PastImpl_this->endpoint)->getDeserializer())->deserialize(sib, type, static_cast< int8_t >(int32_t(0)), nullptr));
            PastImpl_this->deliver(static_cast< ::rice::p2p::commonapi::Id* >(nullptr), static_cast< ::rice::p2p::commonapi::Message* >(result));
        }
        npc(socket)->register_(true, false, 10000, this);
    } catch (::java::io::IOException* ioe) {
        receiveException(socket, static_cast< ::java::lang::Exception* >(ioe));
    }
}

void rice::p2p::past::PastImpl_PastImpl_1::receiveException(::rice::p2p::commonapi::appsocket::AppSocket* socket, ::java::lang::Exception* e)
{
    if(npc(PastImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
        npc(PastImpl_this->logger)->logException(u"Error receiving message"_j, e);

    close(socket);
}

void rice::p2p::past::PastImpl_PastImpl_1::close(::rice::p2p::commonapi::appsocket::AppSocket* socket)
{
    if(socket == nullptr)
        return;

    npc(PastImpl_this->pendingSocketTransactions)->remove(static_cast< ::java::lang::Object* >(socket));
    npc(socket)->close();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::past::PastImpl_PastImpl_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::past::PastImpl_PastImpl_1::getClass0()
{
    return class_();
}

