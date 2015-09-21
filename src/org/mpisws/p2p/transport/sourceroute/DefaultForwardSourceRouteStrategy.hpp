// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/sourceroute/DefaultForwardSourceRouteStrategy.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/sourceroute/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/sourceroute/SourceRouteForwardStrategy.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::sourceroute::DefaultForwardSourceRouteStrategy
    : public virtual ::java::lang::Object
    , public virtual SourceRouteForwardStrategy
{

public:
    typedef ::java::lang::Object super;
    bool forward(::java::lang::Object* nextHop, SourceRoute* sr, bool socket, ::java::util::Map* options) override;

    // Generated
    DefaultForwardSourceRouteStrategy();
protected:
    DefaultForwardSourceRouteStrategy(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
