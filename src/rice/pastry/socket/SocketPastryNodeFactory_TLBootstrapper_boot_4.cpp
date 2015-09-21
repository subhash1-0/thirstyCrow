// Generated from /pastry-2.1/src/rice/pastry/socket/SocketPastryNodeFactory.java
#include <rice/pastry/socket/SocketPastryNodeFactory_TLBootstrapper_boot_4.hpp>

#include <java/lang/NullPointerException.hpp>
#include <java/util/Collection.hpp>
#include <rice/Continuation.hpp>
#include <rice/pastry/socket/SocketPastryNodeFactory_TLBootstrapper.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::pastry::socket::SocketPastryNodeFactory_TLBootstrapper_boot_4::SocketPastryNodeFactory_TLBootstrapper_boot_4(SocketPastryNodeFactory_TLBootstrapper *SocketPastryNodeFactory_TLBootstrapper_this, ::rice::Continuation* beginPns, ::java::util::Collection* bootHandles)
    : super(*static_cast< ::default_init_tag* >(0))
    , SocketPastryNodeFactory_TLBootstrapper_this(SocketPastryNodeFactory_TLBootstrapper_this)
    , beginPns(beginPns)
    , bootHandles(bootHandles)
{
    clinit();
    ctor();
}

void rice::pastry::socket::SocketPastryNodeFactory_TLBootstrapper_boot_4::run()
{
    npc(beginPns)->receiveResult(bootHandles);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::socket::SocketPastryNodeFactory_TLBootstrapper_boot_4::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::pastry::socket::SocketPastryNodeFactory_TLBootstrapper_boot_4::getClass0()
{
    return class_();
}

