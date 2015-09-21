// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/util/BufferWriter.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/nio/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/util/fwd-pastry-2.1.hpp>
#include <rice/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/P2PSocketReceiver.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::util::BufferWriter
    : public virtual ::java::lang::Object
    , public virtual ::org::mpisws::p2p::transport::P2PSocketReceiver
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    ::java::nio::ByteBuffer* sizeBuf {  };
    ::java::nio::ByteBuffer* writeMe {  };
    ::rice::Continuation* continuation {  };
protected:
    void ctor(::java::nio::ByteBuffer* writeMe, ::org::mpisws::p2p::transport::P2PSocket* socket, ::rice::Continuation* continuation, bool includeSizeHeader);
    void ctor(::java::nio::ByteBuffer* writeMe, ::org::mpisws::p2p::transport::P2PSocket* socket, ::rice::Continuation* continuation);

public:
    void receiveException(::org::mpisws::p2p::transport::P2PSocket* socket, ::java::lang::Exception* ioe) override;
    void receiveSelectResult(::org::mpisws::p2p::transport::P2PSocket* socket, bool canRead, bool canWrite) /* throws(IOException) */ override;

    // Generated
    BufferWriter(::java::nio::ByteBuffer* writeMe, ::org::mpisws::p2p::transport::P2PSocket* socket, ::rice::Continuation* continuation, bool includeSizeHeader);
    BufferWriter(::java::nio::ByteBuffer* writeMe, ::org::mpisws::p2p::transport::P2PSocket* socket, ::rice::Continuation* continuation);
protected:
    BufferWriter(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    void init();
    virtual ::java::lang::Class* getClass0();
};
