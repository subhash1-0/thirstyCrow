// Generated from /pastry-2.1/src/rice/p2p/glacier/v2/GlacierImpl.java
#include <rice/p2p/glacier/v2/GlacierImpl_retrieveFragment_30.hpp>

#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/Continuation.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/p2p/glacier/FragmentKey.hpp>
#include <rice/p2p/glacier/v2/GlacierImpl.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::glacier::v2::GlacierImpl_retrieveFragment_30::GlacierImpl_retrieveFragment_30(GlacierImpl *GlacierImpl_this, ::rice::p2p::glacier::FragmentKey* key, ::rice::Continuation* c2)
    : super(*static_cast< ::default_init_tag* >(0))
    , GlacierImpl_this(GlacierImpl_this)
    , key(key)
    , c2(c2)
{
    clinit();
    ctor();
}

void rice::p2p::glacier::v2::GlacierImpl_retrieveFragment_30::receiveResult(::java::lang::Object* o)
{
    if(o != nullptr)
        if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
            npc(GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"retrieveFragment: Key "_j)->append(npc(key)->toStringFull())
                ->append(u" found in trash, retrieving..."_j)->toString());
        else if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
            npc(GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"retrieveFragment: Key "_j)->append(npc(key)->toStringFull())
                ->append(u" not found in trash"_j)->toString());


    npc(c2)->receiveResult(o);
}

void rice::p2p::glacier::v2::GlacierImpl_retrieveFragment_30::receiveException(::java::lang::Exception* e)
{
    if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
        npc(GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Exception while getting object "_j)->append(static_cast< ::java::lang::Object* >(key))
            ->append(u" from trash "_j)
            ->append(static_cast< ::java::lang::Object* >(e))->toString());

    npc(c2)->receiveResult(nullptr);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::glacier::v2::GlacierImpl_retrieveFragment_30::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::glacier::v2::GlacierImpl_retrieveFragment_30::getClass0()
{
    return class_();
}

