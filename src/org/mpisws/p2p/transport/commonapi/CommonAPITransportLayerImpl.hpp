// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/commonapi/CommonAPITransportLayerImpl.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/nio/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/commonapi/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/commonapi/CommonAPITransportLayer.hpp>
#include <org/mpisws/p2p/transport/TransportLayerCallback.hpp>
#include <rice/p2p/commonapi/NodeHandle.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::commonapi::CommonAPITransportLayerImpl
    : public virtual ::java::lang::Object
    , public virtual CommonAPITransportLayer
    , public virtual ::org::mpisws::p2p::transport::TransportLayerCallback
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    ::org::mpisws::p2p::transport::TransportLayer* tl {  };
    ::org::mpisws::p2p::transport::TransportLayerCallback* callback {  };
    ::org::mpisws::p2p::transport::ErrorHandler* errorHandler {  };
    RawMessageDeserializer* deserializer {  };
    IdFactory* idFactory {  };
    ::rice::environment::logging::Logger* logger {  };

private:
    static ::java::lang::String* MSG_CLASS_;
    static ::java::lang::String* MSG_STRING_;
    static ::java::lang::String* MSG_TYPE_;
    static ::java::lang::String* MSG_ADDR_;

public: /* protected */
    OptionsAdder* optionsAdder {  };
protected:
    void ctor(::org::mpisws::p2p::transport::TransportLayer* tl, IdFactory* idFactory, RawMessageDeserializer* deserializer, OptionsAdder* optionsAdder, ::org::mpisws::p2p::transport::ErrorHandler* errorHandler, ::rice::environment::Environment* env);

public:
    void acceptMessages(bool b) override;
    void acceptSockets(bool b) override;
    ::rice::p2p::commonapi::NodeHandle* getLocalIdentifier() override;
    virtual ::org::mpisws::p2p::transport::MessageRequestHandle* sendMessage(::rice::p2p::commonapi::NodeHandle* i, ::rice::p2p::commonapi::rawserialization::RawMessage* m, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options);
    virtual void messageReceived(::rice::p2p::commonapi::NodeHandle* i, ::java::nio::ByteBuffer* m, ::java::util::Map* options) /* throws(IOException) */;
    void setCallback(::org::mpisws::p2p::transport::TransportLayerCallback* callback) override;
    void setErrorHandler(::org::mpisws::p2p::transport::ErrorHandler* handler) override;

public: /* protected */
    bool destroyed {  };

public:
    void destroy() override;
    virtual ::org::mpisws::p2p::transport::SocketRequestHandle* openSocket(::rice::p2p::commonapi::NodeHandle* i, ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe, ::java::util::Map* options);
    void incomingSocket(::org::mpisws::p2p::transport::P2PSocket* s) /* throws(IOException) */ override;

    // Generated
    CommonAPITransportLayerImpl(::org::mpisws::p2p::transport::TransportLayer* tl, IdFactory* idFactory, RawMessageDeserializer* deserializer, OptionsAdder* optionsAdder, ::org::mpisws::p2p::transport::ErrorHandler* errorHandler, ::rice::environment::Environment* env);
protected:
    CommonAPITransportLayerImpl(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    static void clinit();

private:
    void init();

public:
    virtual void messageReceived(::java::lang::Object* i, ::java::lang::Object* m, ::java::util::Map* options) override;
    virtual ::org::mpisws::p2p::transport::SocketRequestHandle* openSocket(::java::lang::Object* i, ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe, ::java::util::Map* options) override;
    virtual ::org::mpisws::p2p::transport::MessageRequestHandle* sendMessage(::java::lang::Object* i, ::java::lang::Object* m, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options) override;
    static ::java::lang::String*& MSG_CLASS();
    static ::java::lang::String*& MSG_STRING();
    static ::java::lang::String*& MSG_TYPE();
    static ::java::lang::String*& MSG_ADDR();

private:
    virtual ::java::lang::Class* getClass0();
    friend class CommonAPITransportLayerImpl_CommonAPITransportLayerImpl_1;
    friend class CommonAPITransportLayerImpl_sendMessage_2;
};
