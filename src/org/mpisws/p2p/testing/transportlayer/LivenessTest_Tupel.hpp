// Generated from /pastry-2.1/src/org/mpisws/p2p/testing/transportlayer/LivenessTest.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/testing/transportlayer/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/sourceroute/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct default_init_tag;

class org::mpisws::p2p::testing::transportlayer::LivenessTest_Tupel
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    ::org::mpisws::p2p::transport::sourceroute::SourceRoute* sr {  };
    int32_t val {  };

protected:
    void ctor(::org::mpisws::p2p::transport::sourceroute::SourceRoute* i, int32_t val);

    // Generated

public:
    LivenessTest_Tupel(LivenessTest *LivenessTest_this, ::org::mpisws::p2p::transport::sourceroute::SourceRoute* i, int32_t val);
protected:
    LivenessTest_Tupel(LivenessTest *LivenessTest_this, const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    LivenessTest *LivenessTest_this;

private:
    virtual ::java::lang::Class* getClass0();
};
