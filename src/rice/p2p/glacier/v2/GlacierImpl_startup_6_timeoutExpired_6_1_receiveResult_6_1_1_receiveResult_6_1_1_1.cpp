// Generated from /pastry-2.1/src/rice/p2p/glacier/v2/GlacierImpl.java
#include <rice/p2p/glacier/v2/GlacierImpl_startup_6_timeoutExpired_6_1_receiveResult_6_1_1_receiveResult_6_1_1_1.hpp>

#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/p2p/glacier/FragmentKey.hpp>
#include <rice/p2p/glacier/v2/GlacierImpl_startup_6.hpp>
#include <rice/p2p/glacier/v2/GlacierImpl_startup_6_timeoutExpired_6_1.hpp>
#include <rice/p2p/glacier/v2/GlacierImpl_startup_6_timeoutExpired_6_1_receiveResult_6_1_1.hpp>
#include <rice/p2p/glacier/v2/GlacierImpl.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::glacier::v2::GlacierImpl_startup_6_timeoutExpired_6_1_receiveResult_6_1_1_receiveResult_6_1_1_1::GlacierImpl_startup_6_timeoutExpired_6_1_receiveResult_6_1_1_receiveResult_6_1_1_1(GlacierImpl_startup_6_timeoutExpired_6_1_receiveResult_6_1_1 *GlacierImpl_startup_6_timeoutExpired_6_1_receiveResult_6_1_1_this, ::rice::p2p::glacier::FragmentKey* thisKey)
    : super(*static_cast< ::default_init_tag* >(0))
    , GlacierImpl_startup_6_timeoutExpired_6_1_receiveResult_6_1_1_this(GlacierImpl_startup_6_timeoutExpired_6_1_receiveResult_6_1_1_this)
    , thisKey(thisKey)
{
    clinit();
    ctor();
}

void rice::p2p::glacier::v2::GlacierImpl_startup_6_timeoutExpired_6_1_receiveResult_6_1_1_receiveResult_6_1_1_1::receiveResult(::java::lang::Object* o)
{
    if(npc(GlacierImpl_startup_6_timeoutExpired_6_1_receiveResult_6_1_1_this->GlacierImpl_startup_6_timeoutExpired_6_1_this->GlacierImpl_startup_6_this->GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(GlacierImpl_startup_6_timeoutExpired_6_1_receiveResult_6_1_1_this->GlacierImpl_startup_6_timeoutExpired_6_1_this->GlacierImpl_startup_6_this->GlacierImpl_this->logger)->log(u"Local scan: Recovered fragment stored OK"_j);

}

void rice::p2p::glacier::v2::GlacierImpl_startup_6_timeoutExpired_6_1_receiveResult_6_1_1_receiveResult_6_1_1_1::receiveException(::java::lang::Exception* e)
{
    if(npc(GlacierImpl_startup_6_timeoutExpired_6_1_receiveResult_6_1_1_this->GlacierImpl_startup_6_timeoutExpired_6_1_this->GlacierImpl_startup_6_this->GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
        npc(GlacierImpl_startup_6_timeoutExpired_6_1_receiveResult_6_1_1_this->GlacierImpl_startup_6_timeoutExpired_6_1_this->GlacierImpl_startup_6_this->GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Local scan: receiveException("_j)->append(static_cast< ::java::lang::Object* >(e))
            ->append(u") while storing a fragment with existing manifest (key="_j)
            ->append(static_cast< ::java::lang::Object* >(thisKey))
            ->append(u")"_j)->toString());

}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::glacier::v2::GlacierImpl_startup_6_timeoutExpired_6_1_receiveResult_6_1_1_receiveResult_6_1_1_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::glacier::v2::GlacierImpl_startup_6_timeoutExpired_6_1_receiveResult_6_1_1_receiveResult_6_1_1_1::getClass0()
{
    return class_();
}

