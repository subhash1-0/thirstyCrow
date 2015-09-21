// Generated from /pastry-2.1/src/rice/pastry/socket/SocketPastryNodeFactory.java
#include <rice/pastry/socket/SocketPastryNodeFactory_TLBootstrapper_boot_1_receiveResult_1_1.hpp>

#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/util/Collection.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/pastry/JoinFailedException.hpp>
#include <rice/pastry/PastryNode.hpp>
#include <rice/pastry/socket/SocketPastryNodeFactory_TLBootstrapper_boot_1.hpp>
#include <rice/pastry/socket/SocketPastryNodeFactory_TLBootstrapper.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::pastry::socket::SocketPastryNodeFactory_TLBootstrapper_boot_1_receiveResult_1_1::SocketPastryNodeFactory_TLBootstrapper_boot_1_receiveResult_1_1(SocketPastryNodeFactory_TLBootstrapper_boot_1 *SocketPastryNodeFactory_TLBootstrapper_boot_1_this, bool seed, ::java::util::Collection* bootaddresses)
    : super(*static_cast< ::default_init_tag* >(0))
    , SocketPastryNodeFactory_TLBootstrapper_boot_1_this(SocketPastryNodeFactory_TLBootstrapper_boot_1_this)
    , seed(seed)
    , bootaddresses(bootaddresses)
{
    clinit();
    ctor();
}

void rice::pastry::socket::SocketPastryNodeFactory_TLBootstrapper_boot_1_receiveResult_1_1::receiveResult(::java::util::Collection* result)
{
    if(!seed && npc(result)->isEmpty()) {
        npc(SocketPastryNodeFactory_TLBootstrapper_boot_1_this->SocketPastryNodeFactory_TLBootstrapper_this->pn)->joinFailed(new ::rice::pastry::JoinFailedException(::java::lang::StringBuilder().append(u"Cannot join ring.  All bootstraps are faulty."_j)->append(static_cast< ::java::lang::Object* >(bootaddresses))->toString()));
        return;
    }
    if(npc(SocketPastryNodeFactory_TLBootstrapper_boot_1_this->SocketPastryNodeFactory_TLBootstrapper_this->logger)->level <= ::rice::environment::logging::Logger::INFO)
        npc(SocketPastryNodeFactory_TLBootstrapper_boot_1_this->SocketPastryNodeFactory_TLBootstrapper_this->logger)->log(::java::lang::StringBuilder().append(u"boot() calling pn.doneNode("_j)->append(static_cast< ::java::lang::Object* >(result))
            ->append(u")"_j)->toString());

    npc(SocketPastryNodeFactory_TLBootstrapper_boot_1_this->SocketPastryNodeFactory_TLBootstrapper_this->pn)->doneNode(result);
}

void rice::pastry::socket::SocketPastryNodeFactory_TLBootstrapper_boot_1_receiveResult_1_1::receiveResult(::java::lang::Object* result)
{ 
    receiveResult(dynamic_cast< ::java::util::Collection* >(result));
}

void rice::pastry::socket::SocketPastryNodeFactory_TLBootstrapper_boot_1_receiveResult_1_1::receiveException(::java::lang::Exception* exception)
{
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::socket::SocketPastryNodeFactory_TLBootstrapper_boot_1_receiveResult_1_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::pastry::socket::SocketPastryNodeFactory_TLBootstrapper_boot_1_receiveResult_1_1::getClass0()
{
    return class_();
}

