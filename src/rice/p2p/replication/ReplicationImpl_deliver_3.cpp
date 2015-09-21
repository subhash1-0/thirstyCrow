// Generated from /pastry-2.1/src/rice/p2p/replication/ReplicationImpl.java
#include <rice/p2p/replication/ReplicationImpl_deliver_3.hpp>

#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/Class.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>
#include <java/lang/Throwable.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/p2p/commonapi/Endpoint.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/commonapi/IdSet.hpp>
#include <rice/p2p/commonapi/NodeHandle.hpp>
#include <rice/p2p/commonapi/rawserialization/RawMessage.hpp>
#include <rice/p2p/replication/ReplicationImpl.hpp>
#include <rice/p2p/replication/messaging/RequestMessage.hpp>
#include <rice/p2p/replication/messaging/ResponseMessage.hpp>
#include <SubArray.hpp>
#include <ObjectArray.hpp>

template<typename ComponentType, typename... Bases> struct SubArray;
namespace java
{
    namespace io
    {
typedef ::SubArray< ::java::io::Serializable, ::java::lang::ObjectArray > SerializableArray;
    } // io
} // java

namespace rice
{
    namespace p2p
    {
        namespace commonapi
        {
typedef ::SubArray< ::rice::p2p::commonapi::IdSet, ::java::lang::ObjectArray, ::java::io::SerializableArray > IdSetArray;
        } // commonapi
    } // p2p
} // rice

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

rice::p2p::replication::ReplicationImpl_deliver_3::ReplicationImpl_deliver_3(ReplicationImpl *ReplicationImpl_this, ::rice::p2p::replication::messaging::RequestMessage* rm, ::java::lang::String* name, ::rice::environment::Environment* env)
    : super(*static_cast< ::default_init_tag* >(0))
    , ReplicationImpl_this(ReplicationImpl_this)
    , rm(rm)
{
    clinit();
    ctor(name, env);
}

void rice::p2p::replication::ReplicationImpl_deliver_3::receiveResult(::java::lang::Object* o)
{
    auto array = java_cast< ::java::lang::ObjectArray* >(o);
    auto result = new ::rice::p2p::commonapi::IdSetArray(npc(array)->length);
    if((npc(array)->length > 0) && (dynamic_cast< ::java::lang::Throwable* >((*array)[int32_t(0)]) != nullptr)) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::SEVERE)
            npc(logger)->logException(u"Errors in Multicontinuation:"_j, java_cast< ::java::lang::Throwable* >((*array)[int32_t(0)]));

    } else {
        try {
            ::java::lang::System::arraycopy(array, 0, result, 0, npc(array)->length);
        } catch (::java::lang::ArrayStoreException* ase) {
            if(npc(array)->length > 0) {
                if(npc(logger)->level <= ::rice::environment::logging::Logger::SEVERE)
                    npc(logger)->logException(::java::lang::StringBuilder().append(u"Error copying "_j)->append(npc(npc((*array)[int32_t(0)])->getClass())->getName())
                        ->append(u":"_j)
                        ->append(npc(array)->length)->toString(), ase);

                throw ase;
            }
        }
    }
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(::java::lang::StringBuilder().append(u"COUNT: Telling node "_j)->append(static_cast< ::java::lang::Object* >(npc(rm)->getSource()))
            ->append(u" to fetch"_j)->toString());

    npc(ReplicationImpl_this->endpoint)->route(static_cast< ::rice::p2p::commonapi::Id* >(nullptr), static_cast< ::rice::p2p::commonapi::rawserialization::RawMessage* >(new ::rice::p2p::replication::messaging::ResponseMessage(ReplicationImpl_this->handle, npc(rm)->getRanges(), result)), npc(rm)->getSource());
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::replication::ReplicationImpl_deliver_3::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::replication::ReplicationImpl_deliver_3::getClass0()
{
    return class_();
}

