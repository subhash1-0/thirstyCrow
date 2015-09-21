// Generated from /pastry-2.1/src/rice/pastry/socket/nat/connectivityverifiier/ConnectivityVerifierImpl.java
#include <rice/pastry/socket/nat/connectivityverifiier/ConnectivityVerifierImpl_findExternalNodesHelper_3_receiveResult_3_1.hpp>

#include <java/lang/NullPointerException.hpp>
#include <java/util/Collection.hpp>
#include <rice/Continuation.hpp>
#include <rice/pastry/socket/nat/connectivityverifiier/ConnectivityVerifierImpl_findExternalNodesHelper_3.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::pastry::socket::nat::connectivityverifiier::ConnectivityVerifierImpl_findExternalNodesHelper_3_receiveResult_3_1::ConnectivityVerifierImpl_findExternalNodesHelper_3_receiveResult_3_1(ConnectivityVerifierImpl_findExternalNodesHelper_3 *ConnectivityVerifierImpl_findExternalNodesHelper_3_this, ::rice::Continuation* deliverResultToMe, ::java::util::Collection* result)
    : super(*static_cast< ::default_init_tag* >(0))
    , ConnectivityVerifierImpl_findExternalNodesHelper_3_this(ConnectivityVerifierImpl_findExternalNodesHelper_3_this)
    , deliverResultToMe(deliverResultToMe)
    , result(result)
{
    clinit();
    ctor();
}

void rice::pastry::socket::nat::connectivityverifiier::ConnectivityVerifierImpl_findExternalNodesHelper_3_receiveResult_3_1::run()
{
    npc(deliverResultToMe)->receiveResult(result);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::socket::nat::connectivityverifiier::ConnectivityVerifierImpl_findExternalNodesHelper_3_receiveResult_3_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::pastry::socket::nat::connectivityverifiier::ConnectivityVerifierImpl_findExternalNodesHelper_3_receiveResult_3_1::getClass0()
{
    return class_();
}

