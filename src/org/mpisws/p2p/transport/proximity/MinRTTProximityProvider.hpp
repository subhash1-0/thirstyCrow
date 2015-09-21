// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/proximity/MinRTTProximityProvider.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/liveness/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/proximity/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <rice/environment/time/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/proximity/ProximityProvider.hpp>
#include <org/mpisws/p2p/transport/liveness/PingListener.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::proximity::MinRTTProximityProvider
    : public virtual ::java::lang::Object
    , public virtual ProximityProvider
    , public virtual ::org::mpisws::p2p::transport::liveness::PingListener
{

public:
    typedef ::java::lang::Object super;
    int32_t PROX_TIMEOUT {  };

public: /* package */
    ::java::util::Map* managers {  };
    ::org::mpisws::p2p::transport::liveness::Pinger* tl {  };
    ::rice::environment::logging::Logger* logger {  };
    ::rice::environment::time::TimeSource* time {  };
    int32_t pingThrottle {  };
protected:
    void ctor(::org::mpisws::p2p::transport::liveness::Pinger* tl, ::rice::environment::Environment* env);

public:
    int32_t proximity(::java::lang::Object* i, ::java::util::Map* options) override;
    void pingResponse(::java::lang::Object* i, int32_t rtt, ::java::util::Map* options) override;
    void pingReceived(::java::lang::Object* i, ::java::util::Map* options) override;
    void clearState(::java::lang::Object* i) override;
    virtual MinRTTProximityProvider_EntityManager* getManager(::java::lang::Object* i);

public: /* package */
    ::java::util::Collection* listeners {  };

public:
    void addProximityListener(ProximityListener* listener) override;
    bool removeProximityListener(ProximityListener* listener) override;
    virtual void notifyProximityListeners(::java::lang::Object* i, int32_t prox, ::java::util::Map* options);

    // Generated
    MinRTTProximityProvider(::org::mpisws::p2p::transport::liveness::Pinger* tl, ::rice::environment::Environment* env);
protected:
    MinRTTProximityProvider(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    void init();
    virtual ::java::lang::Class* getClass0();
    friend class MinRTTProximityProvider_EntityManager;
};
