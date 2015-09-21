// Generated from /pastry-2.1/src/rice/pastry/direct/DirectPastryNodeFactory.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/direct/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/Continuation.hpp>

struct default_init_tag;

class rice::pastry::direct::DirectPastryNodeFactory_getBootstrapper_3_boot_3_1
    : public virtual ::java::lang::Object
    , public virtual ::rice::Continuation
{

public:
    typedef ::java::lang::Object super;
    virtual void receiveResult(::java::util::Collection* result);
    void receiveException(::java::lang::Exception* exception) override;

    // Generated
    DirectPastryNodeFactory_getBootstrapper_3_boot_3_1(DirectPastryNodeFactory_getBootstrapper_3 *DirectPastryNodeFactory_getBootstrapper_3_this, ::rice::pastry::PastryNode* pn);
    static ::java::lang::Class *class_();
    virtual void receiveResult(::java::lang::Object* result) override;
    DirectPastryNodeFactory_getBootstrapper_3 *DirectPastryNodeFactory_getBootstrapper_3_this;
    ::rice::pastry::PastryNode* pn;

private:
    virtual ::java::lang::Class* getClass0();
    friend class DirectPastryNodeFactory;
    friend class DirectPastryNodeFactory_NullCancellableTask;
    friend class DirectPastryNodeFactory_getNodeHandleFactory_1;
    friend class DirectPastryNodeFactory_getNodeHandleAdapter_2;
    friend class DirectPastryNodeFactory_getBootstrapper_3;
};
