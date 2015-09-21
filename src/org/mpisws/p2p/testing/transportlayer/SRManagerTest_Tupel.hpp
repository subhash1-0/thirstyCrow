// Generated from /pastry-2.1/src/org/mpisws/p2p/testing/transportlayer/SRManagerTest.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/testing/transportlayer/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/multiaddress/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct default_init_tag;

class org::mpisws::p2p::testing::transportlayer::SRManagerTest_Tupel
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    ::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* sr {  };
    int32_t val {  };

protected:
    void ctor(::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* i, int32_t val);

    // Generated

public:
    SRManagerTest_Tupel(SRManagerTest *SRManagerTest_this, ::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* i, int32_t val);
protected:
    SRManagerTest_Tupel(SRManagerTest *SRManagerTest_this, const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    SRManagerTest *SRManagerTest_this;

private:
    virtual ::java::lang::Class* getClass0();
};
