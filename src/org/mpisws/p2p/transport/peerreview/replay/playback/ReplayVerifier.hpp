// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/replay/playback/ReplayVerifier.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/nio/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/history/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/replay/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/replay/playback/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/util/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/peerreview/replay/Verifier.hpp>
#include <org/mpisws/p2p/transport/peerreview/PeerReviewConstants.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::peerreview::replay::playback::ReplayVerifier
    : public virtual ::java::lang::Object
    , public virtual ::org::mpisws::p2p::transport::peerreview::replay::Verifier
    , public virtual ::org::mpisws::p2p::transport::peerreview::PeerReviewConstants
{

public:
    typedef ::java::lang::Object super;

public: /* protected */
    ::java::lang::Object* localHandle {  };
    ::org::mpisws::p2p::transport::peerreview::history::SecureHistory* history {  };

public: /* package */
    ::org::mpisws::p2p::transport::peerreview::PeerReviewCallback* app {  };
    int32_t numEventCallbacks {  };
    bool foundFault {  };
    bool haveNextEvent {  };
    int64_t nextEventIndex {  };
    ::org::mpisws::p2p::transport::peerreview::history::IndexEntry* next {  };
    bool nextEventIsHashed {  };
    ::rice::p2p::commonapi::rawserialization::InputBuffer* nextEvent {  };
    bool initialized {  };
    int16_t signatureSizeBytes {  };
    int16_t hashSizeBytes {  };
    int32_t numTimers {  };
    ::int32_tArray* eventToCallback {  };

public: /* protected */
    ::rice::environment::logging::Logger* logger {  };
    ::org::mpisws::p2p::transport::util::Serializer* serializer {  };
    ::org::mpisws::p2p::transport::peerreview::history::HashProvider* hashProv {  };

public: /* package */
    bool useSendSign {  };
    bool useSenderSeq {  };
    bool useLogHashFlag {  };
protected:
    void ctor(::org::mpisws::p2p::transport::util::Serializer* serializer, ::org::mpisws::p2p::transport::peerreview::history::HashProvider* hashProv, ::org::mpisws::p2p::transport::peerreview::history::SecureHistory* history, ::java::lang::Object* localHandle, int16_t signatureSizeBytes, int16_t hashSizeBytes, int32_t firstEntryToReplay, ::rice::environment::logging::Logger* logger) /* throws(IOException) */;

public:
    bool verifiedOK() override;
    virtual ::org::mpisws::p2p::transport::peerreview::history::IndexEntry* getNextEvent();

public: /* protected */
    virtual void receive(::java::lang::Object* from, ::java::nio::ByteBuffer* msg) /* throws(IOException) */ = 0;
    virtual void incomingSocket(::java::lang::Object* from, int32_t socketId) /* throws(IOException) */ = 0;
    virtual void socketIO(int32_t socketId, bool canRead, bool canWrite) /* throws(IOException) */ = 0;
    virtual void socketOpened(int32_t socketId) /* throws(IOException) */ = 0;
    virtual void socketException(int32_t socketId, ::java::io::IOException* ioe) /* throws(IOException) */ = 0;

public:
    void setApplication(::org::mpisws::p2p::transport::peerreview::PeerReviewCallback* app) override;

public: /* protected */
    virtual void fetchNextEvent();
    virtual void send(::java::lang::Object* target, ::java::nio::ByteBuffer* message, int32_t relevantLen) /* throws(IOException) */;

public:
    virtual int32_t openSocket(::java::lang::Object* target) /* throws(IOException) */;
    virtual int32_t readSocket(int32_t socketId, ::java::nio::ByteBuffer* dst) /* throws(IOException) */;
    virtual void generatedSocketException(int32_t socketId, ::java::io::IOException* ioe);
    virtual int32_t writeSocket(int32_t socketId, ::java::nio::ByteBuffer* src) /* throws(IOException) */;
    virtual void close(int32_t socketId);
    virtual void shutdownOutput(int32_t socketId);

public: /* package */
    ::java::util::Map* eventCallback {  };

public:
    virtual void registerEvent(::org::mpisws::p2p::transport::peerreview::replay::EventCallback* callback, ::int16_tArray*/*...*/ eventType);
    virtual void registerEvent(::org::mpisws::p2p::transport::peerreview::replay::EventCallback* callback, int16_t eventType);
    bool makeProgress() override;
    int64_t getNextEventTime() override;
    bool isSuccess() override;

public: /* protected */
    virtual ::java::io::IOException* deserializeException(::rice::p2p::commonapi::rawserialization::InputBuffer* nextEvent) /* throws(IOException) */;

    // Generated

public:
    ReplayVerifier(::org::mpisws::p2p::transport::util::Serializer* serializer, ::org::mpisws::p2p::transport::peerreview::history::HashProvider* hashProv, ::org::mpisws::p2p::transport::peerreview::history::SecureHistory* history, ::java::lang::Object* localHandle, int16_t signatureSizeBytes, int16_t hashSizeBytes, int32_t firstEntryToReplay, ::rice::environment::logging::Logger* logger);
protected:
    ReplayVerifier(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    void init();

public:
    virtual ::org::mpisws::p2p::transport::SocketRequestHandle* openSocket(::java::lang::Object* i, ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe, ::java::util::Map* options) = 0;

private:
    virtual ::java::lang::Class* getClass0();
};
