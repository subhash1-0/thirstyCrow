// Generated from /pastry-2.1/src/rice/p2p/glacier/v2/GlacierImpl.java
#include <rice/p2p/glacier/v2/GlacierImpl_startup_4_receiveResult_4_2.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/p2p/commonapi/NodeHandle.hpp>
#include <rice/p2p/glacier/FragmentKey.hpp>
#include <rice/p2p/glacier/v2/FragmentAndManifest.hpp>
#include <rice/p2p/glacier/v2/GlacierImpl_startup_4.hpp>
#include <rice/p2p/glacier/v2/GlacierImpl.hpp>
#include <rice/p2p/glacier/v2/messaging/GlacierDataMessage.hpp>
#include <rice/p2p/glacier/v2/messaging/GlacierResponseMessage.hpp>

template<typename T, typename U>
static T java_cast(U* u)
{
    if(!u) return static_cast<T>(nullptr);
    auto t = dynamic_cast<T>(u);
    if(!t) throw new ::java::lang::ClassCastException();
    return t;
}

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::glacier::v2::GlacierImpl_startup_4_receiveResult_4_2::GlacierImpl_startup_4_receiveResult_4_2(GlacierImpl_startup_4 *GlacierImpl_startup_4_this, ::rice::p2p::glacier::FragmentKey* thisKey, ::rice::p2p::glacier::v2::messaging::GlacierResponseMessage* grm)
    : super(*static_cast< ::default_init_tag* >(0))
    , GlacierImpl_startup_4_this(GlacierImpl_startup_4_this)
    , thisKey(thisKey)
    , grm(grm)
{
    clinit();
    ctor();
}

void rice::p2p::glacier::v2::GlacierImpl_startup_4_receiveResult_4_2::receiveResult(::java::lang::Object* o)
{
    if(o != nullptr) {
        if(npc(GlacierImpl_startup_4_this->GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::INFO)
            npc(GlacierImpl_startup_4_this->GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Fragment "_j)->append(static_cast< ::java::lang::Object* >(thisKey))
                ->append(u" found ("_j)
                ->append(static_cast< ::java::lang::Object* >(o))
                ->append(u"), handing off..."_j)->toString());

        auto fam = java_cast< FragmentAndManifest* >(o);
        GlacierImpl_startup_4_this->GlacierImpl_this->sendMessage(nullptr, new ::rice::p2p::glacier::v2::messaging::GlacierDataMessage(npc(grm)->getUID(), thisKey, npc(fam)->fragment, npc(fam)->manifest, GlacierImpl_startup_4_this->GlacierImpl_this->getLocalNodeHandle(), npc(npc(grm)->getSource())->getId(), true, GlacierImpl_startup_4_this->GlacierImpl_this->tagHandoff), npc(grm)->getSource());
    } else {
        if(npc(GlacierImpl_startup_4_this->GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(GlacierImpl_startup_4_this->GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Handoff failed; fragment "_j)->append(static_cast< ::java::lang::Object* >(thisKey))
                ->append(u" not found in fragment store"_j)->toString());

    }
}

void rice::p2p::glacier::v2::GlacierImpl_startup_4_receiveResult_4_2::receiveException(::java::lang::Exception* e)
{
    if(npc(GlacierImpl_startup_4_this->GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
        npc(GlacierImpl_startup_4_this->GlacierImpl_this->logger)->logException(::java::lang::StringBuilder().append(u"Handoff failed; exception while fetching "_j)->append(static_cast< ::java::lang::Object* >(thisKey))
            ->append(u", e="_j)->toString(), e);

}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::glacier::v2::GlacierImpl_startup_4_receiveResult_4_2::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::glacier::v2::GlacierImpl_startup_4_receiveResult_4_2::getClass0()
{
    return class_();
}

