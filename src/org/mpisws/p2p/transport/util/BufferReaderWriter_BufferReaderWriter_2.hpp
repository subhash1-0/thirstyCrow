// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/util/BufferReaderWriter.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/util/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/Continuation.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::util::BufferReaderWriter_BufferReaderWriter_2
    : public virtual ::java::lang::Object
    , public virtual ::rice::Continuation
{

public:
    typedef ::java::lang::Object super;
    void receiveException(::java::lang::Exception* exception) override;
    virtual void receiveResult(::org::mpisws::p2p::transport::P2PSocket* result);

    // Generated
    BufferReaderWriter_BufferReaderWriter_2(BufferReaderWriter *BufferReaderWriter_this);
    static ::java::lang::Class *class_();
    virtual void receiveResult(::java::lang::Object* result) override;
    BufferReaderWriter *BufferReaderWriter_this;

private:
    virtual ::java::lang::Class* getClass0();
    friend class BufferReaderWriter;
    friend class BufferReaderWriter_BufferReaderWriter_1;
};
