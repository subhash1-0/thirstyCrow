// Generated from /pastry-2.1/src/rice/pastry/socket/nat/connectivityverifiier/ConnectivityVerifierImpl.java
#include <rice/pastry/socket/nat/connectivityverifiier/ConnectivityVerifierImpl_findExternalAddressHelper_5_receiveException_5_2.hpp>

#include <java/io/IOException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <rice/Continuation.hpp>
#include <rice/pastry/socket/nat/connectivityverifiier/ConnectivityVerifierImpl_findExternalAddressHelper_5.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::pastry::socket::nat::connectivityverifiier::ConnectivityVerifierImpl_findExternalAddressHelper_5_receiveException_5_2::ConnectivityVerifierImpl_findExternalAddressHelper_5_receiveException_5_2(ConnectivityVerifierImpl_findExternalAddressHelper_5 *ConnectivityVerifierImpl_findExternalAddressHelper_5_this, ::rice::Continuation* deliverResultToMe, ::java::io::IOException* exception)
    : super(*static_cast< ::default_init_tag* >(0))
    , ConnectivityVerifierImpl_findExternalAddressHelper_5_this(ConnectivityVerifierImpl_findExternalAddressHelper_5_this)
    , deliverResultToMe(deliverResultToMe)
    , exception(exception)
{
    clinit();
    ctor();
}

void rice::pastry::socket::nat::connectivityverifiier::ConnectivityVerifierImpl_findExternalAddressHelper_5_receiveException_5_2::run()
{
    npc(deliverResultToMe)->receiveException(exception);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::socket::nat::connectivityverifiier::ConnectivityVerifierImpl_findExternalAddressHelper_5_receiveException_5_2::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::pastry::socket::nat::connectivityverifiier::ConnectivityVerifierImpl_findExternalAddressHelper_5_receiveException_5_2::getClass0()
{
    return class_();
}

