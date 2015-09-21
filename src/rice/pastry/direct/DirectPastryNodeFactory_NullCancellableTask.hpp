// Generated from /pastry-2.1/src/rice/pastry/direct/DirectPastryNodeFactory.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <rice/pastry/direct/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/p2p/commonapi/CancellableTask.hpp>

struct default_init_tag;

class rice::pastry::direct::DirectPastryNodeFactory_NullCancellableTask
    : public virtual ::java::lang::Object
    , public virtual ::rice::p2p::commonapi::CancellableTask
{

public:
    typedef ::java::lang::Object super;
    void run() override;
    bool cancel() override;
    int64_t scheduledExecutionTime() override;

    // Generated
    DirectPastryNodeFactory_NullCancellableTask();
protected:
    DirectPastryNodeFactory_NullCancellableTask(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
    friend class DirectPastryNodeFactory;
    friend class DirectPastryNodeFactory_getNodeHandleFactory_1;
    friend class DirectPastryNodeFactory_getNodeHandleAdapter_2;
    friend class DirectPastryNodeFactory_getBootstrapper_3;
    friend class DirectPastryNodeFactory_getBootstrapper_3_boot_3_1;
};
