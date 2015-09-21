// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/challenge/PacketInfo.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/challenge/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/infostore/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::peerreview::challenge::PacketInfo
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    ::java::lang::Object* source {  };
    ::org::mpisws::p2p::transport::peerreview::infostore::Evidence* message {  };
    bool isAccusation {  };
    ::java::lang::Object* subject {  };
    ::java::lang::Object* originator {  };
    int64_t evidenceSeq {  };
    ::java::util::Map* options {  };
protected:
    void ctor(::java::lang::Object* source, ::org::mpisws::p2p::transport::peerreview::infostore::Evidence* message, bool isAccusation, ::java::lang::Object* subject, ::java::lang::Object* originator, int64_t evidenceSeq, ::java::util::Map* options);

    // Generated

public:
    PacketInfo(::java::lang::Object* source, ::org::mpisws::p2p::transport::peerreview::infostore::Evidence* message, bool isAccusation, ::java::lang::Object* subject, ::java::lang::Object* originator, int64_t evidenceSeq, ::java::util::Map* options);
protected:
    PacketInfo(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
