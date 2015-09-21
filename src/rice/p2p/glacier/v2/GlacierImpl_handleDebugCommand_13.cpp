// Generated from /pastry-2.1/src/rice/p2p/glacier/v2/GlacierImpl.java
#include <rice/p2p/glacier/v2/GlacierImpl_handleDebugCommand_13.hpp>

#include <java/lang/NullPointerException.hpp>
#include <rice/Continuation.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/time/TimeSource.hpp>
#include <rice/p2p/glacier/v2/DebugContent.hpp>
#include <rice/p2p/glacier/v2/GlacierImpl_handleDebugCommand_13_receiveResult_13_1.hpp>
#include <rice/p2p/glacier/v2/GlacierImpl.hpp>
#include <rice/p2p/past/PastContent.hpp>
#include <Array.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::glacier::v2::GlacierImpl_handleDebugCommand_13::GlacierImpl_handleDebugCommand_13(GlacierImpl *GlacierImpl_this, ::rice::p2p::commonapi::Id* randomID, int32_t lifetime)
    : super(*static_cast< ::default_init_tag* >(0))
    , GlacierImpl_this(GlacierImpl_this)
    , randomID(randomID)
    , lifetime(lifetime)
{
    clinit();
    ctor();
}

void rice::p2p::glacier::v2::GlacierImpl_handleDebugCommand_13::receiveResult(::java::lang::Object* o)
{
    GlacierImpl_this->insert(static_cast< ::rice::p2p::past::PastContent* >(new DebugContent(randomID, false, int32_t(0), new ::int8_tArray({}))), npc(npc(GlacierImpl_this->environment)->getTimeSource())->currentTimeMillis() + lifetime, static_cast< ::rice::Continuation* >(new GlacierImpl_handleDebugCommand_13_receiveResult_13_1(this)));
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::glacier::v2::GlacierImpl_handleDebugCommand_13::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::glacier::v2::GlacierImpl_handleDebugCommand_13::getClass0()
{
    return class_();
}

