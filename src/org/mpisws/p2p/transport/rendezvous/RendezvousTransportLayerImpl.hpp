// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/rendezvous/RendezvousTransportLayerImpl.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/nio/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/rendezvous/fwd-pastry-2.1.hpp>
#include <rice/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <rice/environment/random/fwd-pastry-2.1.hpp>
#include <rice/environment/time/fwd-pastry-2.1.hpp>
#include <rice/p2p/util/tuples/fwd-pastry-2.1.hpp>
#include <rice/selector/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/TransportLayer.hpp>
#include <org/mpisws/p2p/transport/TransportLayerCallback.hpp>
#include <org/mpisws/p2p/transport/rendezvous/PilotManager.hpp>
#include <org/mpisws/p2p/transport/rendezvous/RendezvousTransportLayer.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl
    : public virtual ::java::lang::Object
    , public virtual ::org::mpisws::p2p::transport::TransportLayer
    , public virtual ::org::mpisws::p2p::transport::TransportLayerCallback
    , public virtual PilotManager
    , public virtual RendezvousTransportLayer
{

public:
    typedef ::java::lang::Object super;
    static constexpr int8_t NORMAL_SOCKET { int8_t(0) };
    static constexpr int8_t CONNECTOR_SOCKET { int8_t(1) };
    static constexpr int8_t ACCEPTOR_SOCKET { int8_t(2) };
    static constexpr int8_t PILOT_SOCKET { int8_t(3) };
    static constexpr int8_t CONNECTION_RESPONSE_FAILURE { int8_t(0) };
    static constexpr int8_t CONNECTION_RESPONSE_SUCCESS { int8_t(1) };
    static constexpr int64_t NO_TAG { int64_t(-0x7fffffffffffffffLL-1) };

private:
    static ::java::lang::String* TAG_KEY_;
    static ::java::lang::String* FROM_OVERLAY_;
    static ::java::lang::String* OPTION_USE_PILOT_;

public:
    ::java::lang::String* RENDEZVOUS_CONTACT_STRING {  };

public: /* protected */
    ::org::mpisws::p2p::transport::TransportLayer* tl {  };
    ::org::mpisws::p2p::transport::TransportLayerCallback* callback {  };
    RendezvousGenerationStrategy* rendezvousGenerator {  };
    PilotFinder* pilotFinder {  };
    RendezvousStrategy* rendezvousStrategy {  };
    ResponseStrategy* responseStrategy {  };
    RendezvousContact* localNodeHandle {  };
    ::rice::environment::logging::Logger* logger {  };
    ContactDeserializer* serializer {  };
    ::rice::selector::SelectorManager* selectorManager {  };
    ::rice::environment::random::RandomSource* random {  };
    ::rice::environment::time::TimeSource* time {  };
    EphemeralDB* ephemeralDB {  };
    ContactDirectStrategy* contactDirectStrategy {  };
    ::org::mpisws::p2p::transport::ErrorHandler* errorHandler {  };
protected:
    void ctor(::org::mpisws::p2p::transport::TransportLayer* tl, ::java::lang::String* RENDEZVOUS_CONTACT_STRING, RendezvousContact* myRendezvousContact, ContactDeserializer* deserializer, RendezvousGenerationStrategy* rendezvousGenerator, PilotFinder* pilotFinder, RendezvousStrategy* rendezvousStrategy, ResponseStrategy* responseStrategy, ContactDirectStrategy* contactDirectStrategy, ::rice::environment::Environment* env);

public:
    ::org::mpisws::p2p::transport::SocketRequestHandle* openSocket(::java::lang::Object* i, ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe, ::java::util::Map* options) override;

private:
    void openSocketUsingRouting(RendezvousContact* contact, ::org::mpisws::p2p::transport::SocketRequestHandle* handle, ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe, ::java::util::Map* options);
    bool openSocketUsingPilotFinder(RendezvousContact* contact, ::org::mpisws::p2p::transport::SocketRequestHandle* handle, ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe, ::java::util::Map* options);

public: /* protected */
    virtual bool openSocketUsingPilotToMe(RendezvousContact* contact, ::org::mpisws::p2p::transport::SocketRequestHandle* handle, ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe, ::java::util::Map* options);
    virtual void openSocketViaPilot(RendezvousContact* dest, RendezvousContact* middleMan, ::org::mpisws::p2p::transport::SocketRequestHandle* handle, ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe, ::java::util::Map* options);
    virtual void routeForSocket();

public:
    void incomingSocket(::org::mpisws::p2p::transport::P2PSocket* s) /* throws(IOException) */ override;

public: /* protected */
    virtual void readConnectHeader(::org::mpisws::p2p::transport::P2PSocket* socket) /* throws(IOException) */;
    virtual void readAcceptHeader(::org::mpisws::p2p::transport::P2PSocket* acceptorSocket) /* throws(IOException) */;

public: /* package */
    ::java::util::Map* expectedIncomingSockets {  };

public: /* protected */
    virtual void putExpectedIncomingSocket(RendezvousContact* contact, int32_t uid, ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe, ::org::mpisws::p2p::transport::SocketRequestHandle* requestHandle);
    virtual ::rice::p2p::util::tuples::Tuple* removeExpectedIncomingSocket(RendezvousContact* target, int32_t uid);
    virtual void createForwarder(::org::mpisws::p2p::transport::P2PSocket* a, ::org::mpisws::p2p::transport::P2PSocket* b, RendezvousContact* connector, RendezvousContact* acceptor, int32_t uid);

public: /* package */
    ::java::util::Map* connectSockets {  };

public:
    virtual void putConnectSocket(RendezvousContact* requestor, RendezvousContact* target, int32_t uid, ::org::mpisws::p2p::transport::P2PSocket* socket);
    virtual ::org::mpisws::p2p::transport::P2PSocket* removeConnectSocket(RendezvousContact* requestor, RendezvousContact* target, int32_t uid);
    virtual void openChannel(RendezvousContact* requestor, RendezvousContact* middleMan, int32_t uid);

public: /* protected */
    virtual void openAcceptSocket(RendezvousContact* requestor, RendezvousContact* middleMan, int32_t uid);

public:
    virtual void messageReceivedFromOverlay(RendezvousContact* i, ::java::nio::ByteBuffer* m, ::java::util::Map* options) /* throws(IOException) */;
    virtual void messageReceived(::java::lang::Object* i, ::java::nio::ByteBuffer* m, ::java::util::Map* options) /* throws(IOException) */;

public: /* protected */
    virtual RendezvousContact* getHighIdentifier(::java::util::Map* options);
    virtual int64_t getTag(::java::util::Map* options);

public:
    virtual ::org::mpisws::p2p::transport::MessageRequestHandle* sendMessage(::java::lang::Object* i, ::java::nio::ByteBuffer* m, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options);
    ::java::lang::String* toString() override;
    void acceptMessages(bool b) override;
    void acceptSockets(bool b) override;
    ::java::lang::Object* getLocalIdentifier() override;
    void setCallback(::org::mpisws::p2p::transport::TransportLayerCallback* callback) override;
    void setErrorHandler(::org::mpisws::p2p::transport::ErrorHandler* handler) override;
    void destroy() override;

public: /* package */
    ::java::util::Map* outgoingPilots {  };
    ::java::util::ArrayList* opListeners {  };

public: /* protected */
    virtual void notifyOutgoingPilotAdded(RendezvousContact* i);
    virtual void notifyOutgoingPilotRemoved(RendezvousContact* i);

public:
    void addOutgoingPilotListener(OutgoingPilotListener* listener) override;
    void removeOutgoingPilotListener(OutgoingPilotListener* listener) override;
    virtual ::org::mpisws::p2p::transport::SocketRequestHandle* openPilot(RendezvousContact* i, ::rice::Continuation* deliverAckToMe);
    virtual void closePilot(RendezvousContact* i);
    static constexpr int8_t PILOT_PING { int8_t(1) };
    static constexpr int8_t PILOT_PONG { int8_t(2) };
    static constexpr int8_t PILOT_REQUEST { int8_t(3) };

private:
    static ::int8_tArray* PILOT_PING_BYTES_;
    static ::int8_tArray* PILOT_PONG_BYTES_;
    static ::int8_tArray* PILOT_SOCKET_BYTES_;

public:
    static constexpr int32_t PILOT_PING_PERIOD { int32_t(5000) };

public: /* package */
    ::java::util::Map* incomingPilots {  };
    ::java::util::ArrayList* ipListeners {  };

public: /* protected */
    virtual void notifyIncomingPilotAdded(RendezvousContact* i);
    virtual void notifyIncomingPilotRemoved(RendezvousContact* i);

public:
    void addIncomingPilotListener(IncomingPilotListener* listener) override;
    void removeIncomingPilotListener(IncomingPilotListener* listener) override;

private:
    static ::int8_tArray* makeByteArray_(int8_t writeMe);

    // Generated

public:
    RendezvousTransportLayerImpl(::org::mpisws::p2p::transport::TransportLayer* tl, ::java::lang::String* RENDEZVOUS_CONTACT_STRING, RendezvousContact* myRendezvousContact, ContactDeserializer* deserializer, RendezvousGenerationStrategy* rendezvousGenerator, PilotFinder* pilotFinder, RendezvousStrategy* rendezvousStrategy, ResponseStrategy* responseStrategy, ContactDirectStrategy* contactDirectStrategy, ::rice::environment::Environment* env);
protected:
    RendezvousTransportLayerImpl(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    static void clinit();

private:
    void init();

public:
    virtual void closePilot(::java::lang::Object* i) override;
    virtual void messageReceived(::java::lang::Object* i, ::java::lang::Object* m, ::java::util::Map* options) override;
    virtual void messageReceivedFromOverlay(::java::lang::Object* i, ::java::nio::ByteBuffer* m, ::java::util::Map* options) override;
    virtual void openChannel(::java::lang::Object* requestor, ::java::lang::Object* middleMan, int32_t uid) override;
    virtual ::org::mpisws::p2p::transport::SocketRequestHandle* openPilot(::java::lang::Object* i, ::rice::Continuation* deliverAckToMe) override;
    virtual ::org::mpisws::p2p::transport::MessageRequestHandle* sendMessage(::java::lang::Object* i, ::java::lang::Object* m, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options) override;
    static ::java::lang::String*& TAG_KEY();
    static ::java::lang::String*& FROM_OVERLAY();
    static ::java::lang::String*& OPTION_USE_PILOT();
    static ::int8_tArray*& PILOT_PING_BYTES();
    static ::int8_tArray*& PILOT_PONG_BYTES();
    static ::int8_tArray*& PILOT_SOCKET_BYTES();

private:
    virtual ::java::lang::Class* getClass0();
    friend class RendezvousTransportLayerImpl_openSocket_1;
    friend class RendezvousTransportLayerImpl_openSocket_1_receiveResult_1_1;
    friend class RendezvousTransportLayerImpl_openSocketUsingRouting_2;
    friend class RendezvousTransportLayerImpl_openSocketViaPilot_3;
    friend class RendezvousTransportLayerImpl_openSocketViaPilot_3_receiveResult_3_1;
    friend class RendezvousTransportLayerImpl_incomingSocket_4;
    friend class RendezvousTransportLayerImpl_readConnectHeader_5;
    friend class RendezvousTransportLayerImpl_readAcceptHeader_6;
    friend class RendezvousTransportLayerImpl_readAcceptHeader_6_receiveSelectResult_6_1;
    friend class RendezvousTransportLayerImpl_readAcceptHeader_6_receiveSelectResult_6_2;
    friend class RendezvousTransportLayerImpl_readAcceptHeader_6_receiveSelectResult_6_3;
    friend class RendezvousTransportLayerImpl_readAcceptHeader_6_receiveSelectResult_6_4;
    friend class RendezvousTransportLayerImpl_readAcceptHeader_6_receiveSelectResult_6_5;
    friend class RendezvousTransportLayerImpl_openAcceptSocket_7;
    friend class RendezvousTransportLayerImpl_openAcceptSocket_7_receiveResult_7_1;
    friend class RendezvousTransportLayerImpl_sendMessage_8;
    friend class RendezvousTransportLayerImpl_openPilot_9;
    friend class RendezvousTransportLayerImpl_AbstractPilot;
    friend class RendezvousTransportLayerImpl_OutgoingPilot;
    friend class RendezvousTransportLayerImpl_IncomingPilot;
    friend class RendezvousTransportLayerImpl_ByteWriter;
};
