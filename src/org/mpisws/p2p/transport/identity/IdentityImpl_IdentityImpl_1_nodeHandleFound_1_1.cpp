// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/identity/IdentityImpl.java
#include <org/mpisws/p2p/transport/identity/IdentityImpl_IdentityImpl_1_nodeHandleFound_1_1.hpp>

#include <org/mpisws/p2p/transport/identity/IdentityImpl_IdentityImpl_1.hpp>
#include <org/mpisws/p2p/transport/identity/IdentityImpl.hpp>

org::mpisws::p2p::transport::identity::IdentityImpl_IdentityImpl_1_nodeHandleFound_1_1::IdentityImpl_IdentityImpl_1_nodeHandleFound_1_1(IdentityImpl_IdentityImpl_1 *IdentityImpl_IdentityImpl_1_this, ::java::lang::Object* handle)
    : super(*static_cast< ::default_init_tag* >(0))
    , IdentityImpl_IdentityImpl_1_this(IdentityImpl_IdentityImpl_1_this)
    , handle(handle)
{
    clinit();
    ctor();
}

void org::mpisws::p2p::transport::identity::IdentityImpl_IdentityImpl_1_nodeHandleFound_1_1::run()
{
    IdentityImpl_IdentityImpl_1_this->IdentityImpl_this->addBinding(handle, nullptr, nullptr);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::identity::IdentityImpl_IdentityImpl_1_nodeHandleFound_1_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::identity::IdentityImpl_IdentityImpl_1_nodeHandleFound_1_1::getClass0()
{
    return class_();
}

