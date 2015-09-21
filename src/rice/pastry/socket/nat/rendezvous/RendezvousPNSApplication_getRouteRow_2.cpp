// Generated from /pastry-2.1/src/rice/pastry/socket/nat/rendezvous/RendezvousPNSApplication.java
#include <rice/pastry/socket/nat/rendezvous/RendezvousPNSApplication_getRouteRow_2.hpp>

#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/Iterable.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/util/Iterator.hpp>
#include <java/util/Observer.hpp>
#include <rice/Continuation.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/p2p/commonapi/NodeHandleSet.hpp>
#include <rice/pastry/NodeHandle.hpp>
#include <rice/pastry/NodeSetI.hpp>
#include <rice/pastry/routing/RouteSet.hpp>
#include <rice/pastry/socket/nat/rendezvous/RendezvousPNSApplication.hpp>
#include <SubArray.hpp>
#include <ObjectArray.hpp>

template<typename ComponentType, typename... Bases> struct SubArray;
namespace java
{
    namespace io
    {
typedef ::SubArray< ::java::io::Serializable, ::java::lang::ObjectArray > SerializableArray;
    } // io

    namespace lang
    {
typedef ::SubArray< ::java::lang::Iterable, ObjectArray > IterableArray;
    } // lang

    namespace util
    {
typedef ::SubArray< ::java::util::Observer, ::java::lang::ObjectArray > ObserverArray;
    } // util
} // java

namespace rice
{
    namespace p2p
    {
        namespace commonapi
        {
typedef ::SubArray< ::rice::p2p::commonapi::NodeHandleSet, ::java::lang::ObjectArray, ::java::io::SerializableArray > NodeHandleSetArray;
        } // commonapi
    } // p2p

    namespace pastry
    {
typedef ::SubArray< ::rice::pastry::NodeSetI, ::java::lang::ObjectArray, ::rice::p2p::commonapi::NodeHandleSetArray > NodeSetIArray;

        namespace routing
        {
typedef ::SubArray< ::rice::pastry::routing::RouteSet, ::java::lang::ObjectArray, ::rice::pastry::NodeSetIArray, ::java::io::SerializableArray, ::java::util::ObserverArray, ::java::lang::IterableArray > RouteSetArray;
        } // routing
    } // pastry
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

rice::pastry::socket::nat::rendezvous::RendezvousPNSApplication_getRouteRow_2::RendezvousPNSApplication_getRouteRow_2(RendezvousPNSApplication *RendezvousPNSApplication_this, ::rice::pastry::NodeHandle* input, int16_t row, ::rice::Continuation* c)
    : super(*static_cast< ::default_init_tag* >(0))
    , RendezvousPNSApplication_this(RendezvousPNSApplication_this)
    , input(input)
    , row(row)
    , c(c)
{
    clinit();
    ctor();
}

void rice::pastry::socket::nat::rendezvous::RendezvousPNSApplication_getRouteRow_2::receiveResult(::rice::pastry::routing::RouteSetArray* result)
{
    for (auto ctr = int32_t(0); ctr < npc(result)->length; ctr++) {
        auto rs = (*result)[ctr];
        if(rs != nullptr) {
            for (auto _i = npc(rs)->iterator(); _i->hasNext(); ) {
                ::rice::pastry::NodeHandle* handle = java_cast< ::rice::pastry::NodeHandle* >(_i->next());
                {
                    if(handle != nullptr && !RendezvousPNSApplication_this->useHandle(handle)) {
                        if(npc(RendezvousPNSApplication_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
                            npc(RendezvousPNSApplication_this->logger)->log(::java::lang::StringBuilder().append(u"getRouteRow("_j)->append(static_cast< ::java::lang::Object* >(input))
                                ->append(u","_j)
                                ->append(row)
                                ->append(u") Dropping "_j)
                                ->append(static_cast< ::java::lang::Object* >(handle))
                                ->append(u" because it is FireWalled"_j)->toString());

                        npc(rs)->remove(handle);
                    }
                }
            }
            if(npc(rs)->isEmpty())
                result->set(ctr, nullptr);

        }
    }
    npc(c)->receiveResult(result);
}

void rice::pastry::socket::nat::rendezvous::RendezvousPNSApplication_getRouteRow_2::receiveResult(::java::lang::Object* result)
{ 
    receiveResult(dynamic_cast< ::rice::pastry::routing::RouteSetArray* >(result));
}

void rice::pastry::socket::nat::rendezvous::RendezvousPNSApplication_getRouteRow_2::receiveException(::java::lang::Exception* exception)
{
    npc(c)->receiveException(exception);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::socket::nat::rendezvous::RendezvousPNSApplication_getRouteRow_2::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::pastry::socket::nat::rendezvous::RendezvousPNSApplication_getRouteRow_2::getClass0()
{
    return class_();
}

