// Generated from /pastry-2.1/src/rice/tutorial/ssl/DistTutorial.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/sourceroute/fwd-pastry-2.1.hpp>
#include <rice/pastry/socket/fwd-pastry-2.1.hpp>
#include <rice/tutorial/ssl/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/identity/BindStrategy.hpp>

struct default_init_tag;

class rice::tutorial::ssl::DistTutorial_DistTutorial_1_getBindStrategy_1_1
    : public virtual ::java::lang::Object
    , public virtual ::org::mpisws::p2p::transport::identity::BindStrategy
{

public:
    typedef ::java::lang::Object super;
    virtual bool accept(::rice::pastry::socket::TransportLayerNodeHandle* u, ::org::mpisws::p2p::transport::sourceroute::SourceRoute* l, ::java::util::Map* options);

    // Generated
    DistTutorial_DistTutorial_1_getBindStrategy_1_1(DistTutorial_DistTutorial_1 *DistTutorial_DistTutorial_1_this);
    static ::java::lang::Class *class_();
    virtual bool accept(::java::lang::Object* u, ::java::lang::Object* l, ::java::util::Map* options) override;
    DistTutorial_DistTutorial_1 *DistTutorial_DistTutorial_1_this;

private:
    virtual ::java::lang::Class* getClass0();
    friend class DistTutorial;
    friend class DistTutorial_DistTutorial_1;
};
