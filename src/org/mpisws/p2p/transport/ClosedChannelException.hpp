// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/ClosedChannelException.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <java/nio/channels/ClosedChannelException.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::ClosedChannelException
    : public ::java::nio::channels::ClosedChannelException
{

public:
    typedef ::java::nio::channels::ClosedChannelException super;

public: /* package */
    ::java::lang::String* reason {  };
protected:
    void ctor(::java::lang::String* reason);

public:
    ::java::lang::String* getMessage() override;

    // Generated
    ClosedChannelException(::java::lang::String* reason);
protected:
    ClosedChannelException(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
