// Generated from /pastry-2.1/src/rice/p2p/glacier/v2/GlacierContinuation.java
#include <rice/p2p/glacier/v2/GlacierContinuation.hpp>

#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>

rice::p2p::glacier::v2::GlacierContinuation::GlacierContinuation(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::glacier::v2::GlacierContinuation::GlacierContinuation()
    : GlacierContinuation(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

void rice::p2p::glacier::v2::GlacierContinuation::init_()
{
}

void rice::p2p::glacier::v2::GlacierContinuation::syncReceiveResult(::java::lang::Object* result)
{
    if(!terminated)
        receiveResult(result);

}

void rice::p2p::glacier::v2::GlacierContinuation::syncReceiveException(::java::lang::Exception* exception)
{
    if(!terminated)
        receiveException(exception);

}

void rice::p2p::glacier::v2::GlacierContinuation::syncTimeoutExpired()
{
    if(!terminated)
        timeoutExpired();

}

void rice::p2p::glacier::v2::GlacierContinuation::setup(int32_t uid)
{
    myUID = uid;
    terminated = false;
}

int32_t rice::p2p::glacier::v2::GlacierContinuation::getMyUID()
{
    return myUID;
}

bool rice::p2p::glacier::v2::GlacierContinuation::hasTerminated()
{
    return terminated;
}

void rice::p2p::glacier::v2::GlacierContinuation::terminate()
{
    terminated = true;
}

java::lang::String* rice::p2p::glacier::v2::GlacierContinuation::toString()
{
    return ::java::lang::StringBuilder().append(u"Unknown continuation #"_j)->append(getMyUID())->toString();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::glacier::v2::GlacierContinuation::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.glacier.v2.GlacierContinuation", 39);
    return c;
}

java::lang::Class* rice::p2p::glacier::v2::GlacierContinuation::getClass0()
{
    return class_();
}

