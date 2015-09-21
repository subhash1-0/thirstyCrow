// Generated from /pastry-2.1/src/rice/p2p/past/PastImpl.java
#include <rice/p2p/past/PastImpl_sendViaSocket_4.hpp>

#include <java/io/IOException.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/Comparable.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/nio/Buffer.hpp>
#include <java/nio/ByteBuffer.hpp>
#include <rice/Continuation.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/p2p/commonapi/NodeHandle.hpp>
#include <rice/p2p/commonapi/appsocket/AppSocket.hpp>
#include <rice/p2p/past/PastImpl.hpp>
#include <rice/p2p/past/messaging/PastMessage.hpp>
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

rice::p2p::past::PastImpl_sendViaSocket_4::PastImpl_sendViaSocket_4(PastImpl *PastImpl_this, ::rice::p2p::commonapi::NodeHandle* handle, ::rice::p2p::past::messaging::PastMessage* m, ::java::nio::ByteBufferArray* bb, ::rice::Continuation* c)
    : super(*static_cast< ::default_init_tag* >(0))
    , PastImpl_this(PastImpl_this)
    , handle(handle)
    , m(m)
    , bb(bb)
    , c(c)
{
    clinit();
    ctor();
}

void rice::p2p::past::PastImpl_sendViaSocket_4::receiveSocket(::rice::p2p::commonapi::appsocket::AppSocket* socket)
{
    if(npc(PastImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINER)
        npc(PastImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Opened socket to "_j)->append(static_cast< ::java::lang::Object* >(handle))
            ->append(u":"_j)
            ->append(static_cast< ::java::lang::Object* >(socket))
            ->append(u" to send "_j)
            ->append(static_cast< ::java::lang::Object* >(m))->toString());

    npc(socket)->register_(false, true, 10000, this);
}

void rice::p2p::past::PastImpl_sendViaSocket_4::receiveSelectResult(::rice::p2p::commonapi::appsocket::AppSocket* socket, bool canRead, bool canWrite)
{
    if(npc(PastImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINEST)
        npc(PastImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Writing to "_j)->append(static_cast< ::java::lang::Object* >(handle))
            ->append(u":"_j)
            ->append(static_cast< ::java::lang::Object* >(socket))
            ->append(u" to send "_j)
            ->append(static_cast< ::java::lang::Object* >(m))->toString());

    try {
        npc(socket)->write(bb, 0, 1);
    } catch (::java::io::IOException* ioe) {
        if(c != nullptr)
            npc(c)->receiveException(ioe);
        else if(npc(PastImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(PastImpl_this->logger)->logException(::java::lang::StringBuilder().append(u"Error sending "_j)->append(static_cast< ::java::lang::Object* >(m))->toString(), ioe);

        return;
    }
    if(npc((*bb)[int32_t(0)])->remaining() > 0) {
        npc(socket)->register_(false, true, 10000, this);
    } else {
        npc(socket)->close();
    }
}

void rice::p2p::past::PastImpl_sendViaSocket_4::receiveException(::rice::p2p::commonapi::appsocket::AppSocket* socket, ::java::lang::Exception* e)
{
    if(c != nullptr)
        npc(c)->receiveException(e);

}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::past::PastImpl_sendViaSocket_4::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::past::PastImpl_sendViaSocket_4::getClass0()
{
    return class_();
}

