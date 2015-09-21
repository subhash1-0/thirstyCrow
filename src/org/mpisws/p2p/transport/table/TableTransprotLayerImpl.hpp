// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/table/TableTransprotLayerImpl.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/nio/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/table/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/util/fwd-pastry-2.1.hpp>
#include <rice/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/table/TableTransportLayer.hpp>
#include <org/mpisws/p2p/transport/TransportLayerCallback.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::table::TableTransprotLayerImpl
    : public virtual ::java::lang::Object
    , public virtual TableTransportLayer
    , public virtual ::org::mpisws::p2p::transport::TransportLayerCallback
{

public:
    typedef ::java::lang::Object super;
    static constexpr int8_t PASSTHROUGH { int8_t(0) };
    static constexpr int8_t REQUEST { int8_t(1) };
    static constexpr int8_t RESPONSE_SUCCESS { int8_t(2) };
    static constexpr int8_t RESPONSE_FAILED { int8_t(3) };

public: /* protected */
    TableStore* knownValues {  };
    ::org::mpisws::p2p::transport::TransportLayerCallback* callback {  };
    ::org::mpisws::p2p::transport::TransportLayer* tl {  };
    ::org::mpisws::p2p::transport::util::Serializer* keySerializer {  };
    ::org::mpisws::p2p::transport::util::Serializer* valueSerializer {  };
    ::org::mpisws::p2p::transport::ErrorHandler* errorHandler {  };
    ::rice::environment::logging::Logger* logger {  };
protected:
    void ctor(::org::mpisws::p2p::transport::util::Serializer* iSerializer, ::org::mpisws::p2p::transport::util::Serializer* cSerializer, TableStore* tableStore, ::org::mpisws::p2p::transport::TransportLayer* tl, ::rice::environment::Environment* env);

public:
    ::rice::p2p::commonapi::Cancellable* requestValue(::java::lang::Object* source, ::java::lang::Object* principal, ::rice::Continuation* c, ::java::util::Map* options) override;
    ::org::mpisws::p2p::transport::SocketRequestHandle* openSocket(::java::lang::Object* i, ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe, ::java::util::Map* options) override;
    void incomingSocket(::org::mpisws::p2p::transport::P2PSocket* sock) /* throws(IOException) */ override;
    virtual void handleValueRequest(::org::mpisws::p2p::transport::P2PSocket* sock);
    bool hasKey(::java::lang::Object* i) override;
    void acceptMessages(bool b) override;
    void acceptSockets(bool b) override;
    ::java::lang::Object* getLocalIdentifier() override;
    virtual ::org::mpisws::p2p::transport::MessageRequestHandle* sendMessage(::java::lang::Object* i, ::java::nio::ByteBuffer* m, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options);
    void setCallback(::org::mpisws::p2p::transport::TransportLayerCallback* callback) override;
    void setErrorHandler(::org::mpisws::p2p::transport::ErrorHandler* handler) override;
    void destroy() override;
    virtual void messageReceived(::java::lang::Object* i, ::java::nio::ByteBuffer* m, ::java::util::Map* options) /* throws(IOException) */;

    // Generated
    TableTransprotLayerImpl(::org::mpisws::p2p::transport::util::Serializer* iSerializer, ::org::mpisws::p2p::transport::util::Serializer* cSerializer, TableStore* tableStore, ::org::mpisws::p2p::transport::TransportLayer* tl, ::rice::environment::Environment* env);
protected:
    TableTransprotLayerImpl(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    virtual void messageReceived(::java::lang::Object* i, ::java::lang::Object* m, ::java::util::Map* options) override;
    virtual ::org::mpisws::p2p::transport::MessageRequestHandle* sendMessage(::java::lang::Object* i, ::java::lang::Object* m, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options) override;

private:
    virtual ::java::lang::Class* getClass0();
    friend class TableTransprotLayerImpl_requestValue_1;
    friend class TableTransprotLayerImpl_requestValue_1_receiveResult_1_1;
    friend class TableTransprotLayerImpl_requestValue_1_receiveResult_1_1_receiveResult_1_1_1;
    friend class TableTransprotLayerImpl_openSocket_2;
    friend class TableTransprotLayerImpl_openSocket_2_receiveResult_2_1;
    friend class TableTransprotLayerImpl_incomingSocket_3;
    friend class TableTransprotLayerImpl_handleValueRequest_4;
};
