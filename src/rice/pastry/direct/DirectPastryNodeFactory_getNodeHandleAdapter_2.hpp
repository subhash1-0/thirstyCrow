// Generated from /pastry-2.1/src/rice/pastry/direct/DirectPastryNodeFactory.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/proximity/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/direct/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/proximity/ProximityProvider.hpp>

struct default_init_tag;

class rice::pastry::direct::DirectPastryNodeFactory_getNodeHandleAdapter_2
    : public virtual ::java::lang::Object
    , public virtual ::org::mpisws::p2p::transport::proximity::ProximityProvider
{

public:
    typedef ::java::lang::Object super;
    virtual int32_t proximity(::rice::pastry::NodeHandle* i, ::java::util::Map* options);

public: /* package */
    ::java::util::List* proxListeners {  };

public:
    void addProximityListener(::org::mpisws::p2p::transport::proximity::ProximityListener* name) override;
    bool removeProximityListener(::org::mpisws::p2p::transport::proximity::ProximityListener* name) override;
    virtual void clearState(::rice::pastry::NodeHandle* i);

    // Generated
    DirectPastryNodeFactory_getNodeHandleAdapter_2(DirectPastryNodeFactory *DirectPastryNodeFactory_this, ::rice::pastry::PastryNode* pn);
    static ::java::lang::Class *class_();

private:
    void init();

public:
    virtual void clearState(::java::lang::Object* i) override;
    virtual int32_t proximity(::java::lang::Object* i, ::java::util::Map* options) override;
    DirectPastryNodeFactory *DirectPastryNodeFactory_this;
    ::rice::pastry::PastryNode* pn;

private:
    virtual ::java::lang::Class* getClass0();
    friend class DirectPastryNodeFactory;
    friend class DirectPastryNodeFactory_NullCancellableTask;
    friend class DirectPastryNodeFactory_getNodeHandleFactory_1;
    friend class DirectPastryNodeFactory_getBootstrapper_3;
    friend class DirectPastryNodeFactory_getBootstrapper_3_boot_3_1;
};
