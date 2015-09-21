// Generated from /pastry-2.1/src/rice/pastry/direct/MessageDelivery.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <rice/pastry/direct/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/direct/Delivery.hpp>

struct default_init_tag;

class rice::pastry::direct::MessageDelivery
    : public virtual ::java::lang::Object
    , public virtual ::org::mpisws::p2p::transport::direct::Delivery
{

public:
    typedef ::java::lang::Object super;

public: /* protected */
    ::java::lang::Object* msg {  };
    ::java::lang::Object* node {  };
    ::rice::environment::logging::Logger* logger {  };
    int32_t seq {  };

public: /* package */
    BasicNetworkSimulator* networkSimulator {  };
    ::java::lang::Object* from {  };

public: /* protected */
    ::java::util::Map* options {  };
protected:
    void ctor(::java::lang::Object* m, ::java::lang::Object* to, ::java::lang::Object* from, ::java::util::Map* options, BasicNetworkSimulator* sim);

public:
    void deliver() override;
    int32_t getSeq() override;
    ::java::lang::String* toString() override;

    // Generated
    MessageDelivery(::java::lang::Object* m, ::java::lang::Object* to, ::java::lang::Object* from, ::java::util::Map* options, BasicNetworkSimulator* sim);
protected:
    MessageDelivery(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
