// Generated from /pastry-2.1/src/rice/pastry/standard/PeriodicLeafSetProtocol.java
#include <rice/pastry/standard/PeriodicLeafSetProtocol_removeFromLeafsetIfPossible_1.hpp>

#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/pastry/NodeHandle.hpp>
#include <rice/pastry/standard/PeriodicLeafSetProtocol.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::pastry::standard::PeriodicLeafSetProtocol_removeFromLeafsetIfPossible_1::PeriodicLeafSetProtocol_removeFromLeafsetIfPossible_1(PeriodicLeafSetProtocol *PeriodicLeafSetProtocol_this, ::rice::pastry::NodeHandle* nh)
    : super(*static_cast< ::default_init_tag* >(0))
    , PeriodicLeafSetProtocol_this(PeriodicLeafSetProtocol_this)
    , nh(nh)
{
    clinit();
    ctor();
}

void rice::pastry::standard::PeriodicLeafSetProtocol_removeFromLeafsetIfPossible_1::run()
{
    if(npc(PeriodicLeafSetProtocol_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(PeriodicLeafSetProtocol_this->logger)->log(::java::lang::StringBuilder().append(u"removeFromLeafsetIfPossible("_j)->append(static_cast< ::java::lang::Object* >(nh))
            ->append(u")"_j)->toString());

    PeriodicLeafSetProtocol_this->removeFromLeafsetIfPossible(nh);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::standard::PeriodicLeafSetProtocol_removeFromLeafsetIfPossible_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::pastry::standard::PeriodicLeafSetProtocol_removeFromLeafsetIfPossible_1::getClass0()
{
    return class_();
}

