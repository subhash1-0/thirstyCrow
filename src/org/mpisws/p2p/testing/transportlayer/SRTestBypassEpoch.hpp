// Generated from /pastry-2.1/src/org/mpisws/p2p/testing/transportlayer/SRTestBypassEpoch.java

#pragma once

#include <org/mpisws/p2p/testing/transportlayer/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/testing/transportlayer/SRTest.hpp>

struct default_init_tag;

class org::mpisws::p2p::testing::transportlayer::SRTestBypassEpoch
    : public SRTest
{

public:
    typedef SRTest super;

    // Generated
    SRTestBypassEpoch();
protected:
    SRTestBypassEpoch(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
