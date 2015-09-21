// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/replay/playback/ReplayLayer.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/nio/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/history/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/replay/playback/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/util/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/replay/playback/ReplayVerifier.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::peerreview::replay::playback::ReplayLayer
    : public ReplayVerifier
{

public:
    typedef ReplayVerifier super;

public: /* package */
    ::org::mpisws::p2p::transport::TransportLayerCallback* callback {  };
    ::java::util::Map* sockets {  };
protected:
    void ctor(::org::mpisws::p2p::transport::util::Serializer* serializer, ::org::mpisws::p2p::transport::peerreview::history::HashProvider* hashProv, ::org::mpisws::p2p::transport::peerreview::history::SecureHistory* history, ::java::lang::Object* localHandle, ::rice::environment::Environment* environment) /* throws(IOException) */;

public:
    ::org::mpisws::p2p::transport::SocketRequestHandle* openSocket(::java::lang::Object* i, ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe, ::java::util::Map* options) override;
    virtual ::org::mpisws::p2p::transport::MessageRequestHandle* sendMessage(::java::lang::Object* i, ::java::nio::ByteBuffer* m, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options);
    ::java::lang::Object* getLocalIdentifier() override;
    void setCallback(::org::mpisws::p2p::transport::TransportLayerCallback* callback) override;
    void setErrorHandler(::org::mpisws::p2p::transport::ErrorHandler* handler) override;
    void destroy() override;
    void acceptMessages(bool b) override;
    void acceptSockets(bool b) override;

public: /* package */
    ::rice::environment::Environment* environment {  };

public: /* protected */
    void receive(::java::lang::Object* from, ::java::nio::ByteBuffer* msg) /* throws(IOException) */ override;
    void socketIO(int32_t socketId, bool canRead, bool canWrite) /* throws(IOException) */ override;
    void incomingSocket(::java::lang::Object* from, int32_t socketId) /* throws(IOException) */ override;

public:
    static ::rice::environment::Environment* generateEnvironment(::java::lang::String* name, int64_t startTime, int64_t randSeed, ::rice::environment::logging::LogManager* lm2);

public: /* protected */
    void socketOpened(int32_t socketId) /* throws(IOException) */ override;
    void socketException(int32_t socketId, ::java::io::IOException* ioe) /* throws(IOException) */ override;

public:
    ::rice::environment::Environment* getEnvironment() override;

    // Generated
    ReplayLayer(::org::mpisws::p2p::transport::util::Serializer* serializer, ::org::mpisws::p2p::transport::peerreview::history::HashProvider* hashProv, ::org::mpisws::p2p::transport::peerreview::history::SecureHistory* history, ::java::lang::Object* localHandle, ::rice::environment::Environment* environment);
protected:
    ReplayLayer(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    void init();

public:
    virtual ::org::mpisws::p2p::transport::MessageRequestHandle* sendMessage(::java::lang::Object* i, ::java::lang::Object* m, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options) override;
    virtual int32_t openSocket(::java::lang::Object* target);

private:
    virtual ::java::lang::Class* getClass0();
    friend class ReplayLayer_openSocket_1;
};
