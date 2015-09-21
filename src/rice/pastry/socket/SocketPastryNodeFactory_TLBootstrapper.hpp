// Generated from /pastry-2.1/src/rice/pastry/socket/SocketPastryNodeFactory.java

#pragma once

#include <java/net/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/socket/fwd-pastry-2.1.hpp>
#include <rice/pastry/standard/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/pastry/boot/Bootstrapper.hpp>

struct default_init_tag;

class rice::pastry::socket::SocketPastryNodeFactory_TLBootstrapper
    : public virtual ::java::lang::Object
    , public virtual ::rice::pastry::boot::Bootstrapper
{

public:
    typedef ::java::lang::Object super;

public: /* protected */
    ::rice::pastry::PastryNode* pn {  };
    ::org::mpisws::p2p::transport::TransportLayer* tl {  };
    SocketNodeHandleFactory* handleFactory {  };
    ::rice::pastry::standard::ProximityNeighborSelector* pns {  };
    ::rice::environment::logging::Logger* logger {  };

public: /* package */
    ::java::util::List* listener {  };
protected:
    void ctor(::rice::pastry::PastryNode* pn, ::org::mpisws::p2p::transport::TransportLayer* tl, SocketNodeHandleFactory* handleFactory, ::rice::pastry::standard::ProximityNeighborSelector* pns);

public: /* protected */
    virtual void bootAsBootstrap();

public:
    void boot(::java::util::Collection* bootaddresses_temp) override;

public: /* protected */
    virtual SocketNodeHandle* getTempNodeHandle(::java::net::InetSocketAddress* addr);
    virtual void checkLiveness(SocketNodeHandle* h, ::java::util::Map* options);

    // Generated

public:
    SocketPastryNodeFactory_TLBootstrapper(SocketPastryNodeFactory *SocketPastryNodeFactory_this, ::rice::pastry::PastryNode* pn, ::org::mpisws::p2p::transport::TransportLayer* tl, SocketNodeHandleFactory* handleFactory, ::rice::pastry::standard::ProximityNeighborSelector* pns);
protected:
    SocketPastryNodeFactory_TLBootstrapper(SocketPastryNodeFactory *SocketPastryNodeFactory_this, const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    void init();
    SocketPastryNodeFactory *SocketPastryNodeFactory_this;
    virtual ::java::lang::Class* getClass0();
    friend class SocketPastryNodeFactory;
    friend class SocketPastryNodeFactory_TransLiveness;
    friend class SocketPastryNodeFactory_TransLivenessProximity;
    friend class SocketPastryNodeFactory_getSocketCountListener_1;
    friend class SocketPastryNodeFactory_getIpServiceTransportLayer_2;
    friend class SocketPastryNodeFactory_getIpServiceTransportLayer_2_getNodeHandle_2_1;
    friend class SocketPastryNodeFactory_getIdentityImpl_3;
    friend class SocketPastryNodeFactory_getIdentityImpl_4;
    friend class SocketPastryNodeFactory_getLivenessTransportLayer_5;
    friend class SocketPastryNodeFactory_getSourceRouteManagerLayer_6;
    friend class SocketPastryNodeFactory_getUpperIdentityLayer_7;
    friend class SocketPastryNodeFactory_getCommonAPITransportLayer_8;
    friend class SocketPastryNodeFactory_getCommonAPITransportLayer_9;
    friend class SocketPastryNodeFactory_getOptionsAdder_10;
    friend class SocketPastryNodeFactory_TLBootstrapper_boot_1;
    friend class SocketPastryNodeFactory_TLBootstrapper_boot_1_receiveResult_1_1;
    friend class SocketPastryNodeFactory_TLBootstrapper_boot_2;
    friend class SocketPastryNodeFactory_TLBootstrapper_boot_3;
    friend class SocketPastryNodeFactory_TLBootstrapper_boot_4;
    friend class SocketPastryNodeFactory_newNode_11;
    friend class SocketPastryNodeFactory_newNode_11_run_11_1;
};
