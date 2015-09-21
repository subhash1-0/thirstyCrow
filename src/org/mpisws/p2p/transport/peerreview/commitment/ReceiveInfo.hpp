// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/commitment/ReceiveInfo.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/commitment/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::peerreview::commitment::ReceiveInfo
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    ::java::lang::Object* sender {  };
    int64_t senderSeq {  };
    int64_t indexInLocalHistory {  };
protected:
    void ctor(::java::lang::Object* sender, int64_t senderSeq, int64_t indexInLocalHistory);

    // Generated

public:
    ReceiveInfo(::java::lang::Object* sender, int64_t senderSeq, int64_t indexInLocalHistory);
protected:
    ReceiveInfo(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
