// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/limitsockets/LimitSocketsTransportLayer.java
#include <org/mpisws/p2p/transport/limitsockets/LimitSocketsTransportLayer_LSSocket_forceClose_1.hpp>

#include <java/lang/Exception.hpp>
#include <org/mpisws/p2p/transport/limitsockets/LimitSocketsTransportLayer_LSSocket.hpp>

org::mpisws::p2p::transport::limitsockets::LimitSocketsTransportLayer_LSSocket_forceClose_1::LimitSocketsTransportLayer_LSSocket_forceClose_1(LimitSocketsTransportLayer_LSSocket *LimitSocketsTransportLayer_LSSocket_this)
    : super(*static_cast< ::default_init_tag* >(0))
    , LimitSocketsTransportLayer_LSSocket_this(LimitSocketsTransportLayer_LSSocket_this)
{
    clinit();
    ctor();
}

void org::mpisws::p2p::transport::limitsockets::LimitSocketsTransportLayer_LSSocket_forceClose_1::run()
{
    try {
        LimitSocketsTransportLayer_LSSocket_this->close();
    } catch (::java::lang::Exception* ioe) {
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::limitsockets::LimitSocketsTransportLayer_LSSocket_forceClose_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::limitsockets::LimitSocketsTransportLayer_LSSocket_forceClose_1::getClass0()
{
    return class_();
}

