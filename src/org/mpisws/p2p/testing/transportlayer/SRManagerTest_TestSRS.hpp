// Generated from /pastry-2.1/src/org/mpisws/p2p/testing/transportlayer/SRManagerTest.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/testing/transportlayer/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/multiaddress/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/sourceroute/manager/SourceRouteStrategy.hpp>

struct default_init_tag;

class org::mpisws::p2p::testing::transportlayer::SRManagerTest_TestSRS
    : public virtual ::java::lang::Object
    , public virtual ::org::mpisws::p2p::transport::sourceroute::manager::SourceRouteStrategy
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    ::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* local {  };

protected:
    void ctor(::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* local);

public:
    virtual ::java::util::Collection* getSourceRoutes(::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* destination);

    // Generated
    SRManagerTest_TestSRS(::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* local);
protected:
    SRManagerTest_TestSRS(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    virtual ::java::util::Collection* getSourceRoutes(::java::lang::Object* destination) override;

private:
    virtual ::java::lang::Class* getClass0();
};
