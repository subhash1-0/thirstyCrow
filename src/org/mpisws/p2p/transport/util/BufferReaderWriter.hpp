// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/util/BufferReaderWriter.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/nio/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/util/fwd-pastry-2.1.hpp>
#include <rice/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::util::BufferReaderWriter
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    bool doneReading {  };
    bool doneWriting {  };
    bool failed {  };
    bool sentException {  };
    ::java::nio::ByteBuffer* read {  };

private:
    ::rice::Continuation* c {  };
    ::org::mpisws::p2p::transport::P2PSocket* socket {  };
protected:
    void ctor(::org::mpisws::p2p::transport::P2PSocket* sock, ::java::nio::ByteBuffer* writeMe, bool writeSize, ::rice::Continuation* c);
    void ctor(::org::mpisws::p2p::transport::P2PSocket* sock, ::java::nio::ByteBuffer* writeMe, bool writeSize, ::rice::Continuation* c, int32_t readSize);

public:
    virtual void done(::java::lang::Exception* e);

    // Generated
    BufferReaderWriter(::org::mpisws::p2p::transport::P2PSocket* sock, ::java::nio::ByteBuffer* writeMe, bool writeSize, ::rice::Continuation* c);
    BufferReaderWriter(::org::mpisws::p2p::transport::P2PSocket* sock, ::java::nio::ByteBuffer* writeMe, bool writeSize, ::rice::Continuation* c, int32_t readSize);
protected:
    BufferReaderWriter(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    void init();
    virtual ::java::lang::Class* getClass0();
    friend class BufferReaderWriter_BufferReaderWriter_1;
    friend class BufferReaderWriter_BufferReaderWriter_2;
};
