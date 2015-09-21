// Generated from /pastry-2.1/src/rice/p2p/glacier/v2/GlacierImpl.java
#include <rice/p2p/glacier/v2/GlacierImpl_startup_5_timeoutExpired_5_1.hpp>

#include <java/lang/NullPointerException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/glacier/v2/FragmentMetadata.hpp>
#include <rice/p2p/glacier/v2/GlacierImpl_startup_5.hpp>
#include <rice/p2p/glacier/v2/GlacierImpl.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::glacier::v2::GlacierImpl_startup_5_timeoutExpired_5_1::GlacierImpl_startup_5_timeoutExpired_5_1(GlacierImpl_startup_5 *GlacierImpl_startup_5_this, ::rice::p2p::commonapi::Id* thisKey, int64_t now, FragmentMetadata* metadata)
    : super(*static_cast< ::default_init_tag* >(0))
    , GlacierImpl_startup_5_this(GlacierImpl_startup_5_this)
    , thisKey(thisKey)
    , now(now)
    , metadata(metadata)
{
    clinit();
    ctor();
}

void rice::p2p::glacier::v2::GlacierImpl_startup_5_timeoutExpired_5_1::receiveResult(::java::lang::Object* o)
{
    if(npc(GlacierImpl_startup_5_this->GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::INFO)
        npc(GlacierImpl_startup_5_this->GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"GC collected "_j)->append(npc(thisKey)->toStringFull())
            ->append(u", expired "_j)
            ->append((now - npc(metadata)->getCurrentExpiration()))
            ->append(u" msec ago"_j)->toString());

}

void rice::p2p::glacier::v2::GlacierImpl_startup_5_timeoutExpired_5_1::receiveException(::java::lang::Exception* e)
{
    if(npc(GlacierImpl_startup_5_this->GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(GlacierImpl_startup_5_this->GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"GC cannot collect "_j)->append(npc(thisKey)->toStringFull())->toString());

}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::glacier::v2::GlacierImpl_startup_5_timeoutExpired_5_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::glacier::v2::GlacierImpl_startup_5_timeoutExpired_5_1::getClass0()
{
    return class_();
}

