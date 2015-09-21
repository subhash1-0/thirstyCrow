// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/priority/MessageInfoImpl.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/nio/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/priority/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/priority/MessageInfo.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::priority::MessageInfoImpl
    : public virtual ::java::lang::Object
    , public virtual MessageInfo
{

public:
    typedef ::java::lang::Object super;

private:
    ::java::nio::ByteBuffer* message {  };
    ::java::util::Map* options {  };
    int32_t priority {  };
protected:
    void ctor(::java::nio::ByteBuffer* message, ::java::util::Map* options, int32_t priority);

public:
    ::java::nio::ByteBuffer* getMessage() override;
    ::java::util::Map* getOptions() override;
    int32_t getPriroity() override;
    int32_t getSize() override;

    // Generated
    MessageInfoImpl(::java::nio::ByteBuffer* message, ::java::util::Map* options, int32_t priority);
protected:
    MessageInfoImpl(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
