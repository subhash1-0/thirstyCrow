// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/wire/SocketManager.java

#pragma once

#include <org/mpisws/p2p/transport/wire/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/Runnable.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::wire::SocketManager_shutdownOutput_3
    : public virtual ::java::lang::Object
    , public virtual ::java::lang::Runnable
{

public:
    typedef ::java::lang::Object super;
    void run() override;

    // Generated
    SocketManager_shutdownOutput_3(SocketManager *SocketManager_this);
    static ::java::lang::Class *class_();
    SocketManager *SocketManager_this;

private:
    virtual ::java::lang::Class* getClass0();
    friend class SocketManager;
    friend class SocketManager_SocketManager_1;
    friend class SocketManager_close_2;
};
