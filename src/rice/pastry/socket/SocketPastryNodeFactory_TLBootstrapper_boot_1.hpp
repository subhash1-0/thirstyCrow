// Generated from /pastry-2.1/src/rice/pastry/socket/SocketPastryNodeFactory.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/pastry/socket/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/Continuation.hpp>

struct default_init_tag;

class rice::pastry::socket::SocketPastryNodeFactory_TLBootstrapper_boot_1
    : public virtual ::java::lang::Object
    , public virtual ::rice::Continuation
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    bool done {  };

public:
    virtual void receiveResult(::java::util::Collection* initialSet);
    void receiveException(::java::lang::Exception* exception) override;

    // Generated
    SocketPastryNodeFactory_TLBootstrapper_boot_1(SocketPastryNodeFactory_TLBootstrapper *SocketPastryNodeFactory_TLBootstrapper_this, bool seed, ::java::util::Collection* bootaddresses);
    static ::java::lang::Class *class_();

private:
    void init();

public:
    virtual void receiveResult(::java::lang::Object* result) override;
    SocketPastryNodeFactory_TLBootstrapper *SocketPastryNodeFactory_TLBootstrapper_this;
    bool seed;
    ::java::util::Collection* bootaddresses;

private:
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
    friend class SocketPastryNodeFactory_TLBootstrapper;
    friend class SocketPastryNodeFactory_TLBootstrapper_boot_1_receiveResult_1_1;
    friend class SocketPastryNodeFactory_TLBootstrapper_boot_2;
    friend class SocketPastryNodeFactory_TLBootstrapper_boot_3;
    friend class SocketPastryNodeFactory_TLBootstrapper_boot_4;
    friend class SocketPastryNodeFactory_newNode_11;
    friend class SocketPastryNodeFactory_newNode_11_run_11_1;
};
