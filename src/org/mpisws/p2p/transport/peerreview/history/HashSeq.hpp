// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/history/HashSeq.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/history/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::peerreview::history::HashSeq
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;

private:
    ::int8_tArray* hash {  };
    int64_t seq {  };
protected:
    void ctor(::int8_tArray* h, int64_t s);

public:
    virtual ::int8_tArray* getHash();
    virtual int64_t getSeq();

    // Generated
    HashSeq(::int8_tArray* h, int64_t s);
protected:
    HashSeq(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
