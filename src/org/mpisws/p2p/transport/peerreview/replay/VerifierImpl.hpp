// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/replay/VerifierImpl.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/nio/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/history/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/identity/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/replay/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <rice/environment/random/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/peerreview/replay/Verifier.hpp>
#include <rice/p2p/commonapi/rawserialization/RawSerializable.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::peerreview::replay::VerifierImpl
    : public virtual ::java::lang::Object
    , public virtual Verifier
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    ::java::util::Map* eventCallback {  };
    ::java::util::Map* callbacks {  };

public: /* protected */
    ::rice::p2p::commonapi::rawserialization::RawSerializable* localHandle {  };
    ::org::mpisws::p2p::transport::peerreview::history::SecureHistory* history {  };

public: /* package */
    ::org::mpisws::p2p::transport::peerreview::PeerReviewCallback* app {  };
    bool foundFault {  };
    int64_t nextEventIndex {  };
    ::org::mpisws::p2p::transport::peerreview::history::IndexEntry* next {  };
    ::rice::p2p::commonapi::rawserialization::InputBuffer* nextEvent {  };
    bool initialized {  };
    ::int32_tArray* eventToCallback {  };

public: /* protected */
    ::rice::environment::logging::Logger* logger {  };
    ::org::mpisws::p2p::transport::peerreview::identity::IdentityTransport* transport {  };

public: /* package */
    ::rice::environment::random::RandomSource* prng {  };
    ::org::mpisws::p2p::transport::peerreview::PeerReview* peerreview {  };
    ::rice::environment::Environment* environment {  };
    ::java::lang::Object* extInfo {  };
protected:
    void ctor(::org::mpisws::p2p::transport::peerreview::PeerReview* peerreview, ::rice::environment::Environment* env, ::org::mpisws::p2p::transport::peerreview::history::SecureHistory* history, ::rice::p2p::commonapi::rawserialization::RawSerializable* localHandle, int64_t firstEntryToReplay, ::java::lang::Object* extInfo) /* throws(IOException) */;

public:
    virtual ::java::lang::Object* getExtInfo();

public: /* protected */
    virtual void fetchNextEvent();

public:
    bool verifiedOK() override;
    virtual ::org::mpisws::p2p::transport::peerreview::history::IndexEntry* getNextEvent();
    void setApplication(::org::mpisws::p2p::transport::peerreview::PeerReviewCallback* app) override;
    virtual void registerEvent(EventCallback* callback, ::int16_tArray*/*...*/ eventType);
    virtual void registerEvent(EventCallback* callback, int16_t eventType);
    bool makeProgress() override;
    virtual ::org::mpisws::p2p::transport::MessageRequestHandle* sendMessage(::rice::p2p::commonapi::rawserialization::RawSerializable* target, ::java::nio::ByteBuffer* message, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options);
    int64_t getNextEventTime() override;
    bool isSuccess() override;

public: /* protected */
    virtual ::java::io::IOException* deserializeException(::rice::p2p::commonapi::rawserialization::InputBuffer* nextEvent) /* throws(IOException) */;

public: /* package */
    ::java::util::Map* sockets {  };

public:
    virtual ::org::mpisws::p2p::transport::SocketRequestHandle* openSocket(::rice::p2p::commonapi::rawserialization::RawSerializable* i, ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe, ::java::util::Map* options);

public: /* protected */
    virtual void socketIO(int32_t socketId, bool canRead, bool canWrite) /* throws(IOException) */;
    virtual void incomingSocket(::rice::p2p::commonapi::rawserialization::RawSerializable* from, int32_t socketId) /* throws(IOException) */;
    virtual void socketOpened(int32_t socketId) /* throws(IOException) */;
    virtual void socketException(int32_t socketId, ::java::io::IOException* ioe) /* throws(IOException) */;

public:
    virtual int32_t openSocket(::rice::p2p::commonapi::rawserialization::RawSerializable* target) /* throws(IOException) */;
    virtual int32_t readSocket(int32_t socketId, ::java::nio::ByteBuffer* dst) /* throws(IOException) */;
    virtual void generatedSocketException(int32_t socketId, ::java::io::IOException* ioe);
    virtual int32_t writeSocket(int32_t socketId, ::java::nio::ByteBuffer* src) /* throws(IOException) */;
    virtual void close(int32_t socketId);
    virtual void shutdownOutput(int32_t socketId);
    ::rice::environment::Environment* getEnvironment() override;
    void acceptMessages(bool b) override;
    void acceptSockets(bool b) override;
    ::rice::p2p::commonapi::rawserialization::RawSerializable* getLocalIdentifier() override;
    void setCallback(::org::mpisws::p2p::transport::TransportLayerCallback* callback) override;
    void setErrorHandler(::org::mpisws::p2p::transport::ErrorHandler* handler) override;
    void destroy() override;

    // Generated
    VerifierImpl(::org::mpisws::p2p::transport::peerreview::PeerReview* peerreview, ::rice::environment::Environment* env, ::org::mpisws::p2p::transport::peerreview::history::SecureHistory* history, ::rice::p2p::commonapi::rawserialization::RawSerializable* localHandle, int64_t firstEntryToReplay, ::java::lang::Object* extInfo);
protected:
    VerifierImpl(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    void init();

public:
    virtual ::org::mpisws::p2p::transport::SocketRequestHandle* openSocket(::java::lang::Object* i, ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe, ::java::util::Map* options) override;
    virtual ::org::mpisws::p2p::transport::MessageRequestHandle* sendMessage(::java::lang::Object* i, ::java::lang::Object* m, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options) override;

private:
    virtual ::java::lang::Class* getClass0();
    friend class VerifierImpl_openSocket_1;
};
