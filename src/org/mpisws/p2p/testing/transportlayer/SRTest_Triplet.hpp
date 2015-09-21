// Generated from /pastry-2.1/src/org/mpisws/p2p/testing/transportlayer/SRTest.java

#pragma once

#include <java/nio/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/testing/transportlayer/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/sourceroute/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct default_init_tag;

class org::mpisws::p2p::testing::transportlayer::SRTest_Triplet
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    ::org::mpisws::p2p::transport::P2PSocket* a {  };
    ::org::mpisws::p2p::transport::P2PSocket* b {  };
    ::java::nio::ByteBuffer* m {  };
    ::org::mpisws::p2p::transport::sourceroute::SourceRoute* path {  };

protected:
    void ctor(::org::mpisws::p2p::transport::sourceroute::SourceRoute* path, ::org::mpisws::p2p::transport::P2PSocket* a, ::org::mpisws::p2p::transport::P2PSocket* b);

    // Generated

public:
    SRTest_Triplet(::org::mpisws::p2p::transport::sourceroute::SourceRoute* path, ::org::mpisws::p2p::transport::P2PSocket* a, ::org::mpisws::p2p::transport::P2PSocket* b);
protected:
    SRTest_Triplet(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
