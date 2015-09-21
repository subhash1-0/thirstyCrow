// Generated from /pastry-2.1/src/rice/pastry/direct/DirectPastryNodeFactory.java
#include <rice/pastry/direct/DirectPastryNodeFactory_getBootstrapper_3_boot_3_1.hpp>

#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/util/Collection.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/pastry/PastryNode.hpp>
#include <rice/pastry/direct/DirectPastryNodeFactory_getBootstrapper_3.hpp>
#include <rice/pastry/direct/DirectPastryNodeFactory.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::pastry::direct::DirectPastryNodeFactory_getBootstrapper_3_boot_3_1::DirectPastryNodeFactory_getBootstrapper_3_boot_3_1(DirectPastryNodeFactory_getBootstrapper_3 *DirectPastryNodeFactory_getBootstrapper_3_this, ::rice::pastry::PastryNode* pn)
    : super(*static_cast< ::default_init_tag* >(0))
    , DirectPastryNodeFactory_getBootstrapper_3_this(DirectPastryNodeFactory_getBootstrapper_3_this)
    , pn(pn)
{
    clinit();
    ctor();
}

void rice::pastry::direct::DirectPastryNodeFactory_getBootstrapper_3_boot_3_1::receiveResult(::java::util::Collection* result)
{
    if(npc(DirectPastryNodeFactory_getBootstrapper_3_this->DirectPastryNodeFactory_this->logger)->level <= ::rice::environment::logging::Logger::INFO)
        npc(DirectPastryNodeFactory_getBootstrapper_3_this->DirectPastryNodeFactory_this->logger)->log(::java::lang::StringBuilder().append(u"boot() calling pn.doneNode("_j)->append(static_cast< ::java::lang::Object* >(result))
            ->append(u")"_j)->toString());

    npc(pn)->doneNode(result);
}

void rice::pastry::direct::DirectPastryNodeFactory_getBootstrapper_3_boot_3_1::receiveResult(::java::lang::Object* result)
{ 
    receiveResult(dynamic_cast< ::java::util::Collection* >(result));
}

void rice::pastry::direct::DirectPastryNodeFactory_getBootstrapper_3_boot_3_1::receiveException(::java::lang::Exception* exception)
{
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::direct::DirectPastryNodeFactory_getBootstrapper_3_boot_3_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::pastry::direct::DirectPastryNodeFactory_getBootstrapper_3_boot_3_1::getClass0()
{
    return class_();
}

