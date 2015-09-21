// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/sourceroute/Forwarder.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/nio/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/sourceroute/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/P2PSocketReceiver.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::sourceroute::Forwarder_HalfPipe
    : public virtual ::java::lang::Object
    , public virtual ::org::mpisws::p2p::transport::P2PSocketReceiver
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    ::org::mpisws::p2p::transport::P2PSocket* from {  };
    ::org::mpisws::p2p::transport::P2PSocket* to {  };
    ::java::nio::ByteBuffer* buf {  };
    bool shutdownTo {  };
protected:
    void ctor(::org::mpisws::p2p::transport::P2PSocket* from, ::org::mpisws::p2p::transport::P2PSocket* to);

public:
    ::java::lang::String* toString() override;
    void receiveException(::org::mpisws::p2p::transport::P2PSocket* socket, ::java::lang::Exception* e) override;
    void receiveSelectResult(::org::mpisws::p2p::transport::P2PSocket* socket, bool canRead, bool canWrite) /* throws(IOException) */ override;

    // Generated
    Forwarder_HalfPipe(Forwarder *Forwarder_this, ::org::mpisws::p2p::transport::P2PSocket* from, ::org::mpisws::p2p::transport::P2PSocket* to);
protected:
    Forwarder_HalfPipe(Forwarder *Forwarder_this, const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    void init();
    Forwarder *Forwarder_this;
    virtual ::java::lang::Class* getClass0();
    friend class Forwarder;
};
