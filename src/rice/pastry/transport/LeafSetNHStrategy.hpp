// Generated from /pastry-2.1/src/rice/pastry/transport/LeafSetNHStrategy.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/multiaddress/fwd-pastry-2.1.hpp>
#include <rice/pastry/leafset/fwd-pastry-2.1.hpp>
#include <rice/pastry/transport/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/sourceroute/manager/simple/NextHopStrategy.hpp>

struct default_init_tag;

class rice::pastry::transport::LeafSetNHStrategy
    : public virtual ::java::lang::Object
    , public virtual ::org::mpisws::p2p::transport::sourceroute::manager::simple::NextHopStrategy
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    ::rice::pastry::leafset::LeafSet* ls {  };
protected:
    void ctor(::rice::pastry::leafset::LeafSet* leafSet);

public:
    virtual ::java::util::Collection* getNextHops(::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* destination);

private:
    ::java::util::Collection* walkLeafSet(::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* destination, int32_t numRequested);

    // Generated

public:
    LeafSetNHStrategy(::rice::pastry::leafset::LeafSet* leafSet);
protected:
    LeafSetNHStrategy(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    virtual ::java::util::Collection* getNextHops(::java::lang::Object* destination) override;

private:
    virtual ::java::lang::Class* getClass0();
};
