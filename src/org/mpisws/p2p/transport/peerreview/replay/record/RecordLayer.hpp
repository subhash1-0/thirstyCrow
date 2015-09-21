// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/replay/record/RecordLayer.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/nio/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/history/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/replay/record/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/util/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <rice/environment/random/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/peerreview/PeerReviewConstants.hpp>
#include <org/mpisws/p2p/transport/TransportLayer.hpp>
#include <org/mpisws/p2p/transport/TransportLayerCallback.hpp>

template<typename ComponentType, typename... Bases> struct SubArray;
namespace java
{
    namespace lang
    {
typedef ::SubArray< ::java::lang::Comparable, ObjectArray > ComparableArray;
    } // lang

    namespace nio
    {
typedef ::SubArray< ::java::nio::Buffer, ::java::lang::ObjectArray > BufferArray;
typedef ::SubArray< ::java::nio::ByteBuffer, BufferArray, ::java::lang::ComparableArray > ByteBufferArray;
    } // nio
} // java

struct default_init_tag;

class org::mpisws::p2p::transport::peerreview::replay::record::RecordLayer
    : public virtual ::java::lang::Object
    , public virtual ::org::mpisws::p2p::transport::peerreview::PeerReviewConstants
    , public virtual ::org::mpisws::p2p::transport::TransportLayer
    , public virtual ::org::mpisws::p2p::transport::TransportLayerCallback
{

public:
    typedef ::java::lang::Object super;

private:
    static ::java::lang::String* PR_RELEVANT_LEN_;
    static ::java::lang::String* PR_RELEVANT_MSG_;

public: /* package */
    ::rice::environment::Environment* environment {  };
    ::org::mpisws::p2p::transport::TransportLayer* tl {  };
    ::org::mpisws::p2p::transport::TransportLayerCallback* callback {  };
    ::org::mpisws::p2p::transport::util::Serializer* identifierSerializer {  };
    ::org::mpisws::p2p::transport::ErrorHandler* handler {  };
    ::org::mpisws::p2p::transport::peerreview::history::SecureHistory* history {  };
    ::rice::environment::logging::Logger* logger {  };
    int64_t lastLogEntry {  };
    bool initialized {  };
    int32_t socketCtr {  };

private:
    static ::java::nio::ByteBuffer* ONE_;
    static ::java::nio::ByteBuffer* ZERO_;
protected:
    void ctor(::org::mpisws::p2p::transport::TransportLayer* tl, ::java::lang::String* name, ::org::mpisws::p2p::transport::util::Serializer* serializer, ::rice::environment::Environment* env) /* throws(IOException) */;

public:
    virtual void updateLogTime();
    virtual void logEvent(int16_t type, ::java::nio::ByteBufferArray*/*...*/ entry) /* throws(IOException) */;
    ::org::mpisws::p2p::transport::SocketRequestHandle* openSocket(::java::lang::Object* i, ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe, ::java::util::Map* options) override;
    void incomingSocket(::org::mpisws::p2p::transport::P2PSocket* s) /* throws(IOException) */ override;
    virtual ::org::mpisws::p2p::transport::MessageRequestHandle* sendMessage(::java::lang::Object* i, ::java::nio::ByteBuffer* m, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options);
    virtual void messageReceived(::java::lang::Object* i, ::java::nio::ByteBuffer* m, ::java::util::Map* options) /* throws(IOException) */;
    void acceptMessages(bool b) override;
    void acceptSockets(bool b) override;
    ::java::lang::Object* getLocalIdentifier() override;
    void setCallback(::org::mpisws::p2p::transport::TransportLayerCallback* callback) override;
    void setErrorHandler(::org::mpisws::p2p::transport::ErrorHandler* handler) override;
    void destroy() override;
    static ::rice::environment::Environment* generateEnvironment();
    static ::rice::environment::Environment* generateEnvironment(int32_t randomSeed);
    static ::rice::environment::Environment* generateEnvironment(::rice::environment::random::RandomSource* rs);
    virtual void logSocketException(::java::nio::ByteBuffer* socketId, ::java::lang::Exception* ioe) /* throws(IOException) */;

    // Generated
    RecordLayer(::org::mpisws::p2p::transport::TransportLayer* tl, ::java::lang::String* name, ::org::mpisws::p2p::transport::util::Serializer* serializer, ::rice::environment::Environment* env);
protected:
    RecordLayer(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    static void clinit();

private:
    void init();

public:
    virtual void messageReceived(::java::lang::Object* i, ::java::lang::Object* m, ::java::util::Map* options) override;
    virtual ::org::mpisws::p2p::transport::MessageRequestHandle* sendMessage(::java::lang::Object* i, ::java::lang::Object* m, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options) override;
    static ::java::lang::String*& PR_RELEVANT_LEN();
    static ::java::lang::String*& PR_RELEVANT_MSG();
    static ::java::nio::ByteBuffer*& ONE();
    static ::java::nio::ByteBuffer*& ZERO();

private:
    virtual ::java::lang::Class* getClass0();
    friend class RecordLayer_openSocket_1;
    friend class RecordLayer_generateEnvironment_2;
};
