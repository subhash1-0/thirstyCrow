// Generated from /pastry-2.1/src/rice/pastry/direct/DirectPastryNodeFactory.java

#pragma once

#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/direct/fwd-pastry-2.1.hpp>
#include <rice/pastry/standard/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/pastry/boot/Bootstrapper.hpp>

struct default_init_tag;

class rice::pastry::direct::DirectPastryNodeFactory_getBootstrapper_3
    : public virtual ::java::lang::Object
    , public virtual ::rice::pastry::boot::Bootstrapper
{

public:
    typedef ::java::lang::Object super;
    void boot(::java::util::Collection* bootaddresses) override;

    // Generated
    DirectPastryNodeFactory_getBootstrapper_3(DirectPastryNodeFactory *DirectPastryNodeFactory_this, ::rice::pastry::standard::ProximityNeighborSelector* pns, ::rice::pastry::PastryNode* pn);
    static ::java::lang::Class *class_();
    DirectPastryNodeFactory *DirectPastryNodeFactory_this;
    ::rice::pastry::standard::ProximityNeighborSelector* pns;
    ::rice::pastry::PastryNode* pn;

private:
    virtual ::java::lang::Class* getClass0();
    friend class DirectPastryNodeFactory;
    friend class DirectPastryNodeFactory_NullCancellableTask;
    friend class DirectPastryNodeFactory_getNodeHandleFactory_1;
    friend class DirectPastryNodeFactory_getNodeHandleAdapter_2;
    friend class DirectPastryNodeFactory_getBootstrapper_3_boot_3_1;
};
