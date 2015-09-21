// Generated from /pastry-2.1/src/rice/p2p/glacier/v2/GlacierImpl.java
#include <rice/p2p/glacier/v2/GlacierImpl_startup_4_receiveResult_4_3.hpp>

#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/p2p/commonapi/IdRange.hpp>
#include <rice/p2p/commonapi/NodeHandle.hpp>
#include <rice/p2p/glacier/FragmentKey.hpp>
#include <rice/p2p/glacier/v2/GlacierImpl_startup_4.hpp>
#include <rice/p2p/glacier/v2/GlacierImpl.hpp>
#include <rice/p2p/glacier/v2/Manifest.hpp>
#include <rice/p2p/glacier/v2/messaging/GlacierDataMessage.hpp>
#include <rice/p2p/glacier/v2/messaging/GlacierResponseMessage.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::glacier::v2::GlacierImpl_startup_4_receiveResult_4_3::GlacierImpl_startup_4_receiveResult_4_3(GlacierImpl_startup_4 *GlacierImpl_startup_4_this, ::rice::p2p::glacier::FragmentKey* thisKey, ::rice::p2p::glacier::v2::messaging::GlacierDataMessage* gdm, Manifest* thisManifest)
    : super(*static_cast< ::default_init_tag* >(0))
    , GlacierImpl_startup_4_this(GlacierImpl_startup_4_this)
    , thisKey(thisKey)
    , gdm(gdm)
    , thisManifest(thisManifest)
{
    clinit();
    ctor();
}

void rice::p2p::glacier::v2::GlacierImpl_startup_4_receiveResult_4_3::receiveResult(::java::lang::Object* o)
{
    if(npc(GlacierImpl_startup_4_this->GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::INFO)
        npc(GlacierImpl_startup_4_this->GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Handoff: Stored OK, sending receipt: "_j)->append(static_cast< ::java::lang::Object* >(thisKey))->toString());

    GlacierImpl_startup_4_this->GlacierImpl_this->sendMessage(nullptr, new ::rice::p2p::glacier::v2::messaging::GlacierResponseMessage(npc(gdm)->getUID(), thisKey, true, npc(thisManifest)->getExpiration(), npc(GlacierImpl_startup_4_this->GlacierImpl_this->responsibleRange)->containsId(GlacierImpl_startup_4_this->GlacierImpl_this->getFragmentLocation(thisKey)), GlacierImpl_startup_4_this->GlacierImpl_this->getLocalNodeHandle(), npc(npc(gdm)->getSource())->getId(), true, GlacierImpl_startup_4_this->GlacierImpl_this->tagHandoff), npc(gdm)->getSource());
}

void rice::p2p::glacier::v2::GlacierImpl_startup_4_receiveResult_4_3::receiveException(::java::lang::Exception* e)
{
    if(npc(GlacierImpl_startup_4_this->GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
        npc(GlacierImpl_startup_4_this->GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Handoff: receiveException("_j)->append(static_cast< ::java::lang::Object* >(e))
            ->append(u") while storing a fragment -- unexpected, ignored (key="_j)
            ->append(static_cast< ::java::lang::Object* >(thisKey))
            ->append(u")"_j)->toString());

}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::glacier::v2::GlacierImpl_startup_4_receiveResult_4_3::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::glacier::v2::GlacierImpl_startup_4_receiveResult_4_3::getClass0()
{
    return class_();
}

