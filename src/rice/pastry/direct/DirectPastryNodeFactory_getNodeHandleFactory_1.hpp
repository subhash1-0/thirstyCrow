// Generated from /pastry-2.1/src/rice/pastry/direct/DirectPastryNodeFactory.java

#pragma once

#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/direct/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/pastry/NodeHandleFactory.hpp>

struct default_init_tag;

class rice::pastry::direct::DirectPastryNodeFactory_getNodeHandleFactory_1
    : public virtual ::java::lang::Object
    , public virtual ::rice::pastry::NodeHandleFactory
{

public:
    typedef ::java::lang::Object super;
    ::rice::pastry::NodeHandle* readNodeHandle(::rice::p2p::commonapi::rawserialization::InputBuffer* buf) /* throws(IOException) */ override;
    ::rice::pastry::NodeHandle* coalesce(::rice::pastry::NodeHandle* handle) override;

public: /* protected */
    virtual void notifyListeners(::rice::pastry::NodeHandle* nh);

public:
    void addNodeHandleFactoryListener(::rice::pastry::NodeHandleFactoryListener* listener) override;
    void removeNodeHandleFactoryListener(::rice::pastry::NodeHandleFactoryListener* listener) override;

    // Generated
    DirectPastryNodeFactory_getNodeHandleFactory_1(DirectPastryNodeFactory *DirectPastryNodeFactory_this);
    static ::java::lang::Class *class_();
    DirectPastryNodeFactory *DirectPastryNodeFactory_this;

private:
    virtual ::java::lang::Class* getClass0();
    friend class DirectPastryNodeFactory;
    friend class DirectPastryNodeFactory_NullCancellableTask;
    friend class DirectPastryNodeFactory_getNodeHandleAdapter_2;
    friend class DirectPastryNodeFactory_getBootstrapper_3;
    friend class DirectPastryNodeFactory_getBootstrapper_3_boot_3_1;
};
