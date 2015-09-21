// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/Basics.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/peerreview/PeerReviewConstants.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::peerreview::Basics
    : public virtual ::java::lang::Object
    , public virtual PeerReviewConstants
{

public:
    typedef ::java::lang::Object super;
    static ::java::lang::String* renderStatus(int32_t status);

    // Generated
    Basics();
protected:
    Basics(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
