// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/proximity/MinRTTProximityProvider.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/proximity/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::proximity::MinRTTProximityProvider_EntityManager
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;

public: /* protected */
    ::java::lang::Object* identifier {  };
    int32_t proximity_ {  };
    int64_t lastPingTime {  };
protected:
    void ctor(::java::lang::Object* route);

public:
    virtual void ping(::java::util::Map* options);
    virtual int32_t proximity();

public: /* protected */
    virtual void markProximity(int32_t proximity, ::java::util::Map* options);

public:
    ::java::lang::String* toString() override;

    // Generated
    MinRTTProximityProvider_EntityManager(MinRTTProximityProvider *MinRTTProximityProvider_this, ::java::lang::Object* route);
protected:
    MinRTTProximityProvider_EntityManager(MinRTTProximityProvider *MinRTTProximityProvider_this, const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    void init();
    MinRTTProximityProvider *MinRTTProximityProvider_this;
    virtual ::java::lang::Class* getClass0();
    friend class MinRTTProximityProvider;
};
