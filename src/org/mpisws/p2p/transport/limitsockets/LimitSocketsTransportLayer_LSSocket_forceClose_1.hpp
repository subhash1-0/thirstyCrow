// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/limitsockets/LimitSocketsTransportLayer.java

#pragma once

#include <org/mpisws/p2p/transport/limitsockets/fwd-pastry-2.1.hpp>
#include <rice/selector/TimerTask.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::limitsockets::LimitSocketsTransportLayer_LSSocket_forceClose_1
    : public ::rice::selector::TimerTask
{

public:
    typedef ::rice::selector::TimerTask super;
    void run() override;

    // Generated
    LimitSocketsTransportLayer_LSSocket_forceClose_1(LimitSocketsTransportLayer_LSSocket *LimitSocketsTransportLayer_LSSocket_this);
    static ::java::lang::Class *class_();
    LimitSocketsTransportLayer_LSSocket *LimitSocketsTransportLayer_LSSocket_this;

private:
    virtual ::java::lang::Class* getClass0();
    friend class LimitSocketsTransportLayer;
    friend class LimitSocketsTransportLayer_openSocket_1;
    friend class LimitSocketsTransportLayer_openSocket_2;
    friend class LimitSocketsTransportLayer_LSSocket;
};
