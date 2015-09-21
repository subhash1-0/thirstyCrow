// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/sourceroute/SourceRouteFactory.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/sourceroute/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct org::mpisws::p2p::transport::sourceroute::SourceRouteFactory
    : public virtual ::java::lang::Object
{
    virtual SourceRoute* getSourceRoute(::java::util::List* route) = 0;
    virtual SourceRoute* reverse(SourceRoute* route) = 0;
    virtual SourceRoute* build(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::java::lang::Object* local, ::java::lang::Object* lastHop) /* throws(IOException) */ = 0;
    virtual SourceRoute* getSourceRoute(::java::lang::Object* local, ::java::lang::Object* dest) = 0;
    virtual SourceRoute* getSourceRoute(::java::lang::Object* local) = 0;

    // Generated
    static ::java::lang::Class *class_();
};
