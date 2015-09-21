// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/util/SocketWrapperSocket.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/nio/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/util/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/P2PSocket.hpp>
#include <org/mpisws/p2p/transport/P2PSocketReceiver.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::util::SocketWrapperSocket
    : public virtual ::java::lang::Object
    , public virtual ::org::mpisws::p2p::transport::P2PSocket
    , public virtual ::org::mpisws::p2p::transport::P2PSocketReceiver
{

public:
    typedef ::java::lang::Object super;

public: /* protected */
    ::java::lang::Object* identifier {  };
    ::org::mpisws::p2p::transport::P2PSocket* socket {  };
    ::rice::environment::logging::Logger* logger {  };
    ::java::util::Map* options {  };
    ::org::mpisws::p2p::transport::P2PSocketReceiver* reader {  };
    ::org::mpisws::p2p::transport::P2PSocketReceiver* writer {  };
    ::org::mpisws::p2p::transport::ErrorHandler* errorHandler {  };
protected:
    void ctor(::java::lang::Object* identifier, ::org::mpisws::p2p::transport::P2PSocket* socket, ::rice::environment::logging::Logger* logger, ::org::mpisws::p2p::transport::ErrorHandler* errorHandler, ::java::util::Map* options);

public:
    ::java::lang::Object* getIdentifier() override;
    void close() override;
    int64_t read(::java::nio::ByteBuffer* dsts) /* throws(IOException) */ override;
    void register_(bool wantToRead, bool wantToWrite, ::org::mpisws::p2p::transport::P2PSocketReceiver* receiver) override;
    void receiveSelectResult(::org::mpisws::p2p::transport::P2PSocket* socket, bool canRead, bool canWrite) /* throws(IOException) */ override;
    void receiveException(::org::mpisws::p2p::transport::P2PSocket* socket, ::java::lang::Exception* e) override;
    void shutdownOutput() override;
    int64_t write(::java::nio::ByteBuffer* srcs) /* throws(IOException) */ override;
    ::java::lang::String* toString() override;
    ::java::util::Map* getOptions() override;

    // Generated
    SocketWrapperSocket(::java::lang::Object* identifier, ::org::mpisws::p2p::transport::P2PSocket* socket, ::rice::environment::logging::Logger* logger, ::org::mpisws::p2p::transport::ErrorHandler* errorHandler, ::java::util::Map* options);
protected:
    SocketWrapperSocket(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
