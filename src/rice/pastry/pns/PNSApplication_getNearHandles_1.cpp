// Generated from /pastry-2.1/src/rice/pastry/pns/PNSApplication.java
#include <rice/pastry/pns/PNSApplication_getNearHandles_1.hpp>

#include <java/io/IOException.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Integer.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/util/Collection.hpp>
#include <java/util/Map.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/p2p/commonapi/Cancellable.hpp>
#include <rice/p2p/util/AttachableCancellable.hpp>
#include <rice/p2p/util/tuples/MutableTuple.hpp>
#include <rice/pastry/NodeHandle.hpp>
#include <rice/pastry/pns/PNSApplication_getNearHandles_1_receiveResult_1_1.hpp>
#include <rice/pastry/pns/PNSApplication.hpp>

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

rice::pastry::pns::PNSApplication_getNearHandles_1::PNSApplication_getNearHandles_1(PNSApplication *PNSApplication_this, ::rice::pastry::NodeHandle* handle, ::rice::p2p::util::tuples::MutableTuple* best, ::rice::p2p::util::AttachableCancellable* ret, ::java::util::Collection* bootHandles, ::rice::Continuation* deliverResultToMe, ::java::util::Collection* remaining)
    : super(*static_cast< ::default_init_tag* >(0))
    , PNSApplication_this(PNSApplication_this)
    , handle(handle)
    , best(best)
    , ret(ret)
    , bootHandles(bootHandles)
    , deliverResultToMe(deliverResultToMe)
    , remaining(remaining)
{
    clinit();
    ctor();
}

void rice::pastry::pns::PNSApplication_getNearHandles_1::receiveResult(::java::lang::Integer* result)
{
    if(npc(PNSApplication_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(PNSApplication_this->logger)->log(::java::lang::StringBuilder().append(u"got proximity for "_j)->append(static_cast< ::java::lang::Object* >(handle))
            ->append(u" in getNearHandles()"_j)->toString());

    if((java_cast< ::rice::pastry::NodeHandle* >(npc(best)->a()) != nullptr) && (npc(java_cast< ::java::lang::Integer* >(npc(PNSApplication_this->pingCache)->get(java_cast< ::rice::pastry::NodeHandle* >(npc(best)->a()))))->intValue() < npc(result)->intValue())) {
        return;
    }
    if(java_cast< ::rice::p2p::commonapi::Cancellable* >(npc(best)->b()) != nullptr)
        npc(java_cast< ::rice::p2p::commonapi::Cancellable* >(npc(best)->b()))->cancel();

    auto cancellable = PNSApplication_this->getNearest(handle, new PNSApplication_getNearHandles_1_receiveResult_1_1(this, ret, bootHandles, deliverResultToMe));
    npc(ret)->attach(cancellable);
    npc(best)->set(handle, cancellable);
}

void rice::pastry::pns::PNSApplication_getNearHandles_1::receiveResult(::java::lang::Object* result)
{ 
    receiveResult(dynamic_cast< ::java::lang::Integer* >(result));
}

void rice::pastry::pns::PNSApplication_getNearHandles_1::receiveException(::java::io::IOException* exception)
{
    npc(remaining)->remove(handle);
}

void rice::pastry::pns::PNSApplication_getNearHandles_1::receiveException(::java::lang::Exception* exception)
{ 
    receiveException(dynamic_cast< ::java::io::IOException* >(exception));
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::pns::PNSApplication_getNearHandles_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::pastry::pns::PNSApplication_getNearHandles_1::getClass0()
{
    return class_();
}

