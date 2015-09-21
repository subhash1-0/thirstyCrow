// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/liveness/PingMessage.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/liveness/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::liveness::PingMessage
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    int64_t sentTime {  };
protected:
    void ctor(int64_t sentTime);
    void ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf) /* throws(IOException) */;

public:
    ::java::lang::String* toString() override;
    virtual void serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */;

    // Generated
    PingMessage(int64_t sentTime);
    PingMessage(::rice::p2p::commonapi::rawserialization::InputBuffer* buf);
protected:
    PingMessage(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
