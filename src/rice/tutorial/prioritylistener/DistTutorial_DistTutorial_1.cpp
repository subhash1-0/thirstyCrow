// Generated from /pastry-2.1/src/rice/tutorial/prioritylistener/DistTutorial.java
#include <rice/tutorial/prioritylistener/DistTutorial_DistTutorial_1.hpp>

#include <java/io/PrintStream.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Integer.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/Short.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>
#include <java/util/Map.hpp>
#include <org/mpisws/p2p/transport/commonapi/CommonAPITransportLayerImpl.hpp>
#include <org/mpisws/p2p/transport/multiaddress/MultiInetSocketAddress.hpp>
#include <rice/pastry/PastryNode.hpp>
#include <rice/tutorial/prioritylistener/DistTutorial.hpp>

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

rice::tutorial::prioritylistener::DistTutorial_DistTutorial_1::DistTutorial_DistTutorial_1(DistTutorial *DistTutorial_this, ::rice::pastry::PastryNode* node)
    : super(*static_cast< ::default_init_tag* >(0))
    , DistTutorial_this(DistTutorial_this)
    , node(node)
{
    clinit();
    ctor();
}

void rice::tutorial::prioritylistener::DistTutorial_DistTutorial_1::wrote(int32_t bytes, ::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* i, ::java::util::Map* options, bool passthrough, bool socket)
{
    auto address = int32_t(0);
    auto addressI = java_cast< ::java::lang::Integer* >(java_cast< ::java::lang::Object* >(npc(options)->get(::org::mpisws::p2p::transport::commonapi::CommonAPITransportLayerImpl::MSG_ADDR())));
    if(addressI != nullptr) {
        address = npc(addressI)->intValue();
    }
    auto messageClass = java_cast< ::java::lang::String* >(java_cast< ::java::lang::Object* >(npc(options)->get(::org::mpisws::p2p::transport::commonapi::CommonAPITransportLayerImpl::MSG_CLASS())));
    auto toString = java_cast< ::java::lang::String* >(java_cast< ::java::lang::Object* >(npc(options)->get(::org::mpisws::p2p::transport::commonapi::CommonAPITransportLayerImpl::MSG_STRING())));
    int16_t type = int32_t(0);
    auto typeS = java_cast< ::java::lang::Short* >(java_cast< ::java::lang::Object* >(npc(options)->get(::org::mpisws::p2p::transport::commonapi::CommonAPITransportLayerImpl::MSG_TYPE())));
    if(typeS != nullptr) {
        type = npc(typeS)->shortValue();
    }
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(node))->append(u" wrote a "_j)
        ->append(messageClass)
        ->append(u" of size "_j)
        ->append(bytes)
        ->append(u" to "_j)
        ->append(static_cast< ::java::lang::Object* >(i))
        ->append(u" addr:"_j)
        ->append(address)
        ->append(u" type:"_j)
        ->append(type)
        ->append(u" "_j)
        ->append(toString)->toString());
}

void rice::tutorial::prioritylistener::DistTutorial_DistTutorial_1::wrote(int32_t bytes, ::java::lang::Object* i, ::java::util::Map* options, bool passthrough, bool socket)
{ 
    wrote(bytes, dynamic_cast< ::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* >(i), options, passthrough, socket);
}

void rice::tutorial::prioritylistener::DistTutorial_DistTutorial_1::read(int32_t bytes, ::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* i, ::java::util::Map* options, bool passthrough, bool socket)
{
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(node))->append(u" read a message of size "_j)
        ->append(bytes)
        ->append(u" from "_j)
        ->append(static_cast< ::java::lang::Object* >(i))->toString());
}

void rice::tutorial::prioritylistener::DistTutorial_DistTutorial_1::read(int32_t bytes, ::java::lang::Object* i, ::java::util::Map* options, bool passthrough, bool socket)
{ 
    read(bytes, dynamic_cast< ::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* >(i), options, passthrough, socket);
}

void rice::tutorial::prioritylistener::DistTutorial_DistTutorial_1::enqueued(int32_t bytes, ::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* i, ::java::util::Map* options, bool passthrough, bool socket)
{
    auto address = int32_t(0);
    auto addressI = java_cast< ::java::lang::Integer* >(java_cast< ::java::lang::Object* >(npc(options)->get(::org::mpisws::p2p::transport::commonapi::CommonAPITransportLayerImpl::MSG_ADDR())));
    if(addressI != nullptr) {
        address = npc(addressI)->intValue();
    }
    auto messageClass = java_cast< ::java::lang::String* >(java_cast< ::java::lang::Object* >(npc(options)->get(::org::mpisws::p2p::transport::commonapi::CommonAPITransportLayerImpl::MSG_CLASS())));
    auto toString = java_cast< ::java::lang::String* >(java_cast< ::java::lang::Object* >(npc(options)->get(::org::mpisws::p2p::transport::commonapi::CommonAPITransportLayerImpl::MSG_STRING())));
    int16_t type = int32_t(0);
    auto typeS = java_cast< ::java::lang::Short* >(java_cast< ::java::lang::Object* >(npc(options)->get(::org::mpisws::p2p::transport::commonapi::CommonAPITransportLayerImpl::MSG_TYPE())));
    if(typeS != nullptr) {
        type = npc(typeS)->shortValue();
    }
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(node))->append(u" enqueued a "_j)
        ->append(messageClass)
        ->append(u" of size "_j)
        ->append(bytes)
        ->append(u" to "_j)
        ->append(static_cast< ::java::lang::Object* >(i))
        ->append(u" addr:"_j)
        ->append(address)
        ->append(u" type:"_j)
        ->append(type)
        ->append(u" "_j)
        ->append(toString)->toString());
}

void rice::tutorial::prioritylistener::DistTutorial_DistTutorial_1::enqueued(int32_t bytes, ::java::lang::Object* i, ::java::util::Map* options, bool passthrough, bool socket)
{ 
    enqueued(bytes, dynamic_cast< ::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* >(i), options, passthrough, socket);
}

void rice::tutorial::prioritylistener::DistTutorial_DistTutorial_1::dropped(int32_t bytes, ::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* i, ::java::util::Map* options, bool passthrough, bool socket)
{
    auto address = int32_t(0);
    auto addressI = java_cast< ::java::lang::Integer* >(java_cast< ::java::lang::Object* >(npc(options)->get(::org::mpisws::p2p::transport::commonapi::CommonAPITransportLayerImpl::MSG_ADDR())));
    if(addressI != nullptr) {
        address = npc(addressI)->intValue();
    }
    auto messageClass = java_cast< ::java::lang::String* >(java_cast< ::java::lang::Object* >(npc(options)->get(::org::mpisws::p2p::transport::commonapi::CommonAPITransportLayerImpl::MSG_CLASS())));
    auto toString = java_cast< ::java::lang::String* >(java_cast< ::java::lang::Object* >(npc(options)->get(::org::mpisws::p2p::transport::commonapi::CommonAPITransportLayerImpl::MSG_STRING())));
    int16_t type = int32_t(0);
    auto typeS = java_cast< ::java::lang::Short* >(java_cast< ::java::lang::Object* >(npc(options)->get(::org::mpisws::p2p::transport::commonapi::CommonAPITransportLayerImpl::MSG_TYPE())));
    if(typeS != nullptr) {
        type = npc(typeS)->shortValue();
    }
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(node))->append(u" dropped a "_j)
        ->append(messageClass)
        ->append(u" of size "_j)
        ->append(bytes)
        ->append(u" to "_j)
        ->append(static_cast< ::java::lang::Object* >(i))
        ->append(u" addr:"_j)
        ->append(address)
        ->append(u" type:"_j)
        ->append(type)
        ->append(u" "_j)
        ->append(toString)->toString());
}

void rice::tutorial::prioritylistener::DistTutorial_DistTutorial_1::dropped(int32_t bytes, ::java::lang::Object* i, ::java::util::Map* options, bool passthrough, bool socket)
{ 
    dropped(bytes, dynamic_cast< ::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* >(i), options, passthrough, socket);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::tutorial::prioritylistener::DistTutorial_DistTutorial_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::tutorial::prioritylistener::DistTutorial_DistTutorial_1::getClass0()
{
    return class_();
}

