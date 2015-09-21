// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/sourceroute/manager/SourceRouteManagerImpl.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/nio/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/sourceroute/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/sourceroute/manager/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::sourceroute::manager::SourceRouteManagerImpl_AddressManager
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;

public: /* protected */
    ::java::lang::Object* address {  };
    ::org::mpisws::p2p::transport::sourceroute::SourceRoute* best {  };
    ::java::util::LinkedList* pendingMessages {  };
    ::java::util::LinkedList* pendingSockets {  };
    int32_t liveness {  };
    int64_t updated {  };

public:
    static constexpr int32_t LIVENESS_UNKNOWN { int32_t(-1) };

public: /* package */
    ::java::util::HashSet* routes {  };
protected:
    void ctor(::java::lang::Object* address);

public:
    virtual void clearLivenessState();
    virtual int32_t proximity(::java::util::Map* options);
    virtual int32_t getLiveness(::java::util::Map* options);
    virtual ::org::mpisws::p2p::transport::MessageRequestHandle* sendMessage(::java::nio::ByteBuffer* message, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options);
    virtual ::org::mpisws::p2p::transport::SocketRequestHandle* openSocket(::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe, ::java::util::Map* options);
    virtual bool checkLiveness(::java::util::Map* options);
    ::java::lang::String* toString() override;
    virtual void livenessChanged(::org::mpisws::p2p::transport::sourceroute::SourceRoute* i, int32_t val, ::java::util::Map* options);

public: /* protected */
    virtual void markAlive(::org::mpisws::p2p::transport::sourceroute::SourceRoute* route, ::java::util::Map* options);
    virtual void markSuspected(::org::mpisws::p2p::transport::sourceroute::SourceRoute* route, ::java::util::Map* options);
    virtual void markDead(::org::mpisws::p2p::transport::sourceroute::SourceRoute* deadRoute, ::java::util::Map* options);
    virtual void markDeadForever(::java::util::Map* options);
    virtual void markProximity(::org::mpisws::p2p::transport::sourceroute::SourceRoute* route, int32_t proximity, ::java::util::Map* options);
    virtual void setAlive(::java::util::Map* options);
    virtual void setSuspected(::java::util::Map* options);
    virtual void setDead(::java::util::Map* options);
    virtual void setDeadForever(::java::util::Map* options);
    virtual void purgeQueue();

    // Generated

public:
    SourceRouteManagerImpl_AddressManager(SourceRouteManagerImpl *SourceRouteManagerImpl_this, ::java::lang::Object* address);
protected:
    SourceRouteManagerImpl_AddressManager(SourceRouteManagerImpl *SourceRouteManagerImpl_this, const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    void init();
    SourceRouteManagerImpl *SourceRouteManagerImpl_this;
    virtual ::java::lang::Class* getClass0();
    friend class SourceRouteManagerImpl;
    friend class SourceRouteManagerImpl_AddressManager_PendingSocket;
    friend class SourceRouteManagerImpl_AddressManager_PendingMessage;
    friend class SourceRouteManagerImpl_AddressManager_sendMessage_1;
    friend class SourceRouteManagerImpl_AddressManager_openSocket_2;
};
