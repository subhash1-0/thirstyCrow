// Generated from /pastry-2.1/src/rice/pastry/socket/nat/rendezvous/RendezvousPNSApplication.java
#include <rice/pastry/socket/nat/rendezvous/RendezvousPNSApplication_getLeafSet_1.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/util/Iterator.hpp>
#include <rice/Continuation.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/pastry/NodeHandle.hpp>
#include <rice/pastry/leafset/LeafSet.hpp>
#include <rice/pastry/socket/nat/rendezvous/RendezvousPNSApplication.hpp>

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

rice::pastry::socket::nat::rendezvous::RendezvousPNSApplication_getLeafSet_1::RendezvousPNSApplication_getLeafSet_1(RendezvousPNSApplication *RendezvousPNSApplication_this, ::rice::pastry::NodeHandle* input, ::rice::Continuation* c)
    : super(*static_cast< ::default_init_tag* >(0))
    , RendezvousPNSApplication_this(RendezvousPNSApplication_this)
    , input(input)
    , c(c)
{
    clinit();
    ctor();
}

void rice::pastry::socket::nat::rendezvous::RendezvousPNSApplication_getLeafSet_1::receiveResult(::rice::pastry::leafset::LeafSet* result)
{
    for (auto _i = npc(result)->iterator(); _i->hasNext(); ) {
        ::rice::pastry::NodeHandle* handle = java_cast< ::rice::pastry::NodeHandle* >(_i->next());
        {
            if(!RendezvousPNSApplication_this->useHandle(handle)) {
                if(npc(RendezvousPNSApplication_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
                    npc(RendezvousPNSApplication_this->logger)->log(::java::lang::StringBuilder().append(u"getLeafSet("_j)->append(static_cast< ::java::lang::Object* >(input))
                        ->append(u") Dropping "_j)
                        ->append(static_cast< ::java::lang::Object* >(handle))->toString());

                npc(result)->remove(handle);
            }
        }
    }
    npc(c)->receiveResult(result);
}

void rice::pastry::socket::nat::rendezvous::RendezvousPNSApplication_getLeafSet_1::receiveResult(::java::lang::Object* result)
{ 
    receiveResult(dynamic_cast< ::rice::pastry::leafset::LeafSet* >(result));
}

void rice::pastry::socket::nat::rendezvous::RendezvousPNSApplication_getLeafSet_1::receiveException(::java::lang::Exception* exception)
{
    npc(c)->receiveException(exception);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::socket::nat::rendezvous::RendezvousPNSApplication_getLeafSet_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::pastry::socket::nat::rendezvous::RendezvousPNSApplication_getLeafSet_1::getClass0()
{
    return class_();
}

