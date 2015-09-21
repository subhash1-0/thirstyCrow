// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/identity/IdentityImpl.java
#include <org/mpisws/p2p/transport/identity/IdentityImpl_IdentityImpl_1.hpp>

#include <java/lang/NullPointerException.hpp>
#include <java/lang/Runnable.hpp>
#include <org/mpisws/p2p/transport/identity/IdentityImpl_IdentityImpl_1_nodeHandleFound_1_1.hpp>
#include <org/mpisws/p2p/transport/identity/IdentityImpl.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/selector/SelectorManager.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::transport::identity::IdentityImpl_IdentityImpl_1::IdentityImpl_IdentityImpl_1(IdentityImpl *IdentityImpl_this)
    : super(*static_cast< ::default_init_tag* >(0))
    , IdentityImpl_this(IdentityImpl_this)
{
    clinit();
    ctor();
}

void org::mpisws::p2p::transport::identity::IdentityImpl_IdentityImpl_1::nodeHandleFound(::java::lang::Object* handle)
{
    ::java::lang::Runnable* r = new IdentityImpl_IdentityImpl_1_nodeHandleFound_1_1(this, handle);
    if(npc(npc(IdentityImpl_this->environment)->getSelectorManager())->isSelectorThread()) {
        npc(r)->run();
    } else {
        npc(npc(IdentityImpl_this->environment)->getSelectorManager())->invoke(r);
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::identity::IdentityImpl_IdentityImpl_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::identity::IdentityImpl_IdentityImpl_1::getClass0()
{
    return class_();
}

