// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/commitment/PacketInfo.java

#pragma once

#include <java/nio/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/commitment/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::peerreview::commitment::PacketInfo
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    ::java::nio::ByteBuffer* msg {  };
    ::java::util::Map* options {  };
protected:
    void ctor(::java::nio::ByteBuffer* msg, ::java::util::Map* options);

    // Generated

public:
    PacketInfo(::java::nio::ByteBuffer* msg, ::java::util::Map* options);
protected:
    PacketInfo(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
