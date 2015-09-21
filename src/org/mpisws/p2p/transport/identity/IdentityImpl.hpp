// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/identity/IdentityImpl.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/identity/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/liveness/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/proximity/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/liveness/LivenessTypes.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::identity::IdentityImpl
    : public virtual ::java::lang::Object
    , public virtual ::org::mpisws::p2p::transport::liveness::LivenessTypes
{

public:
    typedef ::java::lang::Object super;

public: /* protected */
    ::int8_tArray* localIdentifier {  };
    IdentityImpl_LowerIdentityImpl* lower {  };
    IdentityImpl_UpperIdentityImpl* upper {  };
    ::java::util::Map* pendingMessages {  };
    ::java::util::Set* deadForever {  };
    ::rice::environment::Environment* environment {  };
    ::rice::environment::logging::Logger* logger {  };
    IdentitySerializer* serializer {  };
    NodeChangeStrategy* nodeChangeStrategy {  };
    SanityChecker* sanityChecker {  };
    ::java::util::Map* bindings {  };

public: /* package */
    int32_t intendedDestCtr {  };

public:
    static constexpr int8_t SUCCESS { int8_t(1) };
    static constexpr int8_t FAILURE { int8_t(0) };
    static constexpr int8_t NO_ID { int8_t(2) };
    static constexpr int8_t NORMAL { int8_t(1) };
    static constexpr int8_t INCORRECT_IDENTITY { int8_t(0) };

private:
    static ::java::lang::String* NODE_HANDLE_FROM_INDEX_;
    static ::java::lang::String* DONT_VERIFY_;

public:
    BindStrategy* bindStrategy {  };
protected:
    void ctor(::int8_tArray* localIdentifier, IdentitySerializer* serializer, NodeChangeStrategy* nodeChangeStrategy, SanityChecker* sanityChecker, BindStrategy* bindStrategy, ::rice::environment::Environment* environment);

public:
    virtual void addPendingMessage(::java::lang::Object* i, IdentityImpl_IdentityMessageHandle* ret);
    virtual void removePendingMessage(::java::lang::Object* i, IdentityImpl_IdentityMessageHandle* ret);
    virtual void printMemStats(int32_t logLevel);

public: /* package */
    ::org::mpisws::p2p::transport::liveness::OverrideLiveness* overrideLiveness {  };

public:
    virtual void setOverrideLiveness(::org::mpisws::p2p::transport::liveness::OverrideLiveness* ol);
    virtual void setDeadForever(::java::lang::Object* l, ::java::lang::Object* i, ::java::util::Map* options);

public: /* protected */
    virtual ::java::lang::Object* getIntendedDest(::java::util::Map* options);
    virtual bool addBinding(::java::lang::Object* u, ::java::lang::Object* l, ::java::util::Map* options);

public:
    virtual bool destinationChanged(::java::lang::Object* oldDest, ::java::lang::Object* newDest, ::java::lang::Object* i, ::java::util::Map* options);
    virtual void initLowerLayer(::org::mpisws::p2p::transport::TransportLayer* tl, ::org::mpisws::p2p::transport::ErrorHandler* handler);
    virtual LowerIdentity* getLowerIdentity();
    virtual UpperIdentity* getUpperIdentity();
    virtual void initUpperLayer(::java::lang::Object* localIdentifier, ::org::mpisws::p2p::transport::TransportLayer* tl, ::org::mpisws::p2p::transport::liveness::LivenessProvider* live, ::org::mpisws::p2p::transport::proximity::ProximityProvider* prox, ::org::mpisws::p2p::transport::liveness::OverrideLiveness* overrideLiveness);

    // Generated
    IdentityImpl(::int8_tArray* localIdentifier, IdentitySerializer* serializer, NodeChangeStrategy* nodeChangeStrategy, SanityChecker* sanityChecker, BindStrategy* bindStrategy, ::rice::environment::Environment* environment);
protected:
    IdentityImpl(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    static void clinit();

private:
    void init();

public:
    static ::java::lang::String*& NODE_HANDLE_FROM_INDEX();
    static ::java::lang::String*& DONT_VERIFY();

private:
    virtual ::java::lang::Class* getClass0();
    friend class IdentityImpl_IdentityImpl_1;
    friend class IdentityImpl_IdentityImpl_1_nodeHandleFound_1_1;
    friend class IdentityImpl_LowerIdentityImpl;
    friend class IdentityImpl_LowerIdentityImpl_openSocket_1;
    friend class IdentityImpl_LowerIdentityImpl_openSocket_1_receiveResult_1_1;
    friend class IdentityImpl_LowerIdentityImpl_openSocket_1_receiveResult_1_2;
    friend class IdentityImpl_LowerIdentityImpl_openSocket_1_receiveResult_1_2_receiveSelectResult_1_2_1;
    friend class IdentityImpl_LowerIdentityImpl_openSocket_1_receiveResult_1_2_receiveSelectResult_1_2_1_receiveSelectResult_1_2_1_1;
    friend class IdentityImpl_LowerIdentityImpl_incomingSocket_2;
    friend class IdentityImpl_LowerIdentityImpl_incomingSocket_2_receiveSelectResult_2_1;
    friend class IdentityImpl_LowerIdentityImpl_incomingSocket_2_receiveSelectResult_2_1_receiveSelectResult_2_1_1;
    friend class IdentityImpl_LowerIdentityImpl_incomingSocket_2_receiveSelectResult_2_1_receiveSelectResult_2_1_2;
    friend class IdentityImpl_LowerIdentityImpl_incomingSocket_2_receiveSelectResult_2_1_receiveSelectResult_2_1_2_receiveSelectResult_2_1_2_1;
    friend class IdentityImpl_LowerIdentityImpl_sendMessage_3;
    friend class IdentityImpl_UpperIdentityImpl;
    friend class IdentityImpl_UpperIdentityImpl_openSocket_1;
    friend class IdentityImpl_IdentityMessageHandle;
};
