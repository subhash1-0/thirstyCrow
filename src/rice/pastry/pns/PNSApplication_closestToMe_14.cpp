// Generated from /pastry-2.1/src/rice/pastry/pns/PNSApplication.java
#include <rice/pastry/pns/PNSApplication_closestToMe_14.hpp>

#include <java/io/IOException.hpp>
#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/Integer.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/util/Collection.hpp>
#include <java/util/Observable.hpp>
#include <rice/Continuation.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/p2p/commonapi/NodeHandle.hpp>
#include <rice/p2p/commonapi/rawserialization/RawSerializable.hpp>
#include <rice/p2p/util/AttachableCancellable.hpp>
#include <rice/pastry/NodeHandle.hpp>
#include <rice/pastry/pns/PNSApplication.hpp>
#include <Array.hpp>
#include <SubArray.hpp>
#include <ObjectArray.hpp>

template<typename ComponentType, typename... Bases> struct SubArray;
namespace java
{
    namespace io
    {
typedef ::SubArray< ::java::io::Serializable, ::java::lang::ObjectArray > SerializableArray;
    } // io

    namespace util
    {
typedef ::SubArray< ::java::util::Observable, ::java::lang::ObjectArray > ObservableArray;
    } // util
} // java

namespace rice
{
    namespace p2p
    {
        namespace commonapi
        {
typedef ::SubArray< ::rice::p2p::commonapi::NodeHandle, ::java::util::ObservableArray, ::java::io::SerializableArray > NodeHandleArray;

            namespace rawserialization
            {
typedef ::SubArray< ::rice::p2p::commonapi::rawserialization::RawSerializable, ::java::lang::ObjectArray > RawSerializableArray;
            } // rawserialization
        } // commonapi
    } // p2p

    namespace pastry
    {
typedef ::SubArray< ::rice::pastry::NodeHandle, ::rice::p2p::commonapi::NodeHandleArray, ::rice::p2p::commonapi::rawserialization::RawSerializableArray > NodeHandleArray;
    } // pastry
} // rice

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::pastry::pns::PNSApplication_closestToMe_14::PNSApplication_closestToMe_14(PNSApplication *PNSApplication_this, ::rice::pastry::NodeHandle* tempNode, ::rice::pastry::NodeHandle* handle, ::java::util::Collection* handles, ::java::util::Collection* remaining, ::int32_tArray* nearestdist, ::rice::pastry::NodeHandleArray* closestNode, ::rice::p2p::util::AttachableCancellable* ret, ::rice::Continuation* c)
    : super(*static_cast< ::default_init_tag* >(0))
    , PNSApplication_this(PNSApplication_this)
    , tempNode(tempNode)
    , handle(handle)
    , handles(handles)
    , remaining(remaining)
    , nearestdist(nearestdist)
    , closestNode(closestNode)
    , ret(ret)
    , c(c)
{
    clinit();
    ctor();
}

void rice::pastry::pns::PNSApplication_closestToMe_14::receiveResult(::java::lang::Integer* result)
{
    if(npc(PNSApplication_this->logger)->level <= ::rice::environment::logging::Logger::FINEST)
        npc(PNSApplication_this->logger)->log(::java::lang::StringBuilder().append(u"closestToMe got prox("_j)->append(npc(result)->intValue())
            ->append(u") on "_j)
            ->append(static_cast< ::java::lang::Object* >(tempNode))
            ->append(u"("_j)
            ->append(static_cast< ::java::lang::Object* >(handle))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(handles))
            ->append(u")"_j)->toString());

    npc(remaining)->remove(tempNode);
    auto prox = npc(result)->intValue();
    if((prox >= 0) && (prox < (*nearestdist)[int32_t(0)]) && npc(tempNode)->isAlive()) {
        (*nearestdist)[int32_t(0)] = prox;
        closestNode->set(int32_t(0), tempNode);
    }
    finish();
}

void rice::pastry::pns::PNSApplication_closestToMe_14::receiveResult(::java::lang::Object* result)
{ 
    receiveResult(dynamic_cast< ::java::lang::Integer* >(result));
}

void rice::pastry::pns::PNSApplication_closestToMe_14::receiveException(::java::io::IOException* exception)
{
    npc(remaining)->remove(tempNode);
    finish();
}

void rice::pastry::pns::PNSApplication_closestToMe_14::receiveException(::java::lang::Exception* exception)
{ 
    receiveException(dynamic_cast< ::java::io::IOException* >(exception));
}

void rice::pastry::pns::PNSApplication_closestToMe_14::finish()
{
    if(npc(remaining)->isEmpty()) {
        npc(ret)->cancel();
        npc(c)->receiveResult((*closestNode)[int32_t(0)]);
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::pns::PNSApplication_closestToMe_14::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::pastry::pns::PNSApplication_closestToMe_14::getClass0()
{
    return class_();
}

