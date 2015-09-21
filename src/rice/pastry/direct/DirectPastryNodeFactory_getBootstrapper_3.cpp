// Generated from /pastry-2.1/src/rice/pastry/direct/DirectPastryNodeFactory.java
#include <rice/pastry/direct/DirectPastryNodeFactory_getBootstrapper_3.hpp>

#include <java/lang/NullPointerException.hpp>
#include <rice/pastry/direct/DirectPastryNodeFactory_getBootstrapper_3_boot_3_1.hpp>
#include <rice/pastry/direct/DirectPastryNodeFactory.hpp>
#include <rice/pastry/standard/ProximityNeighborSelector.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::pastry::direct::DirectPastryNodeFactory_getBootstrapper_3::DirectPastryNodeFactory_getBootstrapper_3(DirectPastryNodeFactory *DirectPastryNodeFactory_this, ::rice::pastry::standard::ProximityNeighborSelector* pns, ::rice::pastry::PastryNode* pn)
    : super(*static_cast< ::default_init_tag* >(0))
    , DirectPastryNodeFactory_this(DirectPastryNodeFactory_this)
    , pns(pns)
    , pn(pn)
{
    clinit();
    ctor();
}

void rice::pastry::direct::DirectPastryNodeFactory_getBootstrapper_3::boot(::java::util::Collection* bootaddresses)
{
    npc(pns)->getNearHandles(bootaddresses, new DirectPastryNodeFactory_getBootstrapper_3_boot_3_1(this, pn));
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::direct::DirectPastryNodeFactory_getBootstrapper_3::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::pastry::direct::DirectPastryNodeFactory_getBootstrapper_3::getClass0()
{
    return class_();
}

