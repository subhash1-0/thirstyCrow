// Generated from /pastry-2.1/src/rice/p2p/glacier/v2/GlacierImpl.java
#include <rice/p2p/glacier/v2/GlacierImpl_startup_3_receiveResult_3_2.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/p2p/commonapi/IdSet.hpp>
#include <rice/p2p/commonapi/NodeHandle.hpp>
#include <rice/p2p/glacier/v2/BloomFilter.hpp>
#include <rice/p2p/glacier/v2/GlacierImpl_startup_3.hpp>
#include <rice/p2p/glacier/v2/GlacierImpl.hpp>
#include <rice/p2p/glacier/v2/messaging/GlacierRangeResponseMessage.hpp>
#include <rice/p2p/glacier/v2/messaging/GlacierSyncMessage.hpp>

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

rice::p2p::glacier::v2::GlacierImpl_startup_3_receiveResult_3_2::GlacierImpl_startup_3_receiveResult_3_2(GlacierImpl_startup_3 *GlacierImpl_startup_3_this, ::rice::p2p::commonapi::IdSet* keySet, ::rice::p2p::glacier::v2::messaging::GlacierRangeResponseMessage* grrm)
    : super(*static_cast< ::default_init_tag* >(0))
    , GlacierImpl_startup_3_this(GlacierImpl_startup_3_this)
    , keySet(keySet)
    , grrm(grrm)
{
    clinit();
    ctor();
}

void rice::p2p::glacier::v2::GlacierImpl_startup_3_receiveResult_3_2::receiveResult(::java::lang::Object* o)
{
    if(dynamic_cast< BloomFilter* >(o) != nullptr) {
        auto bv = java_cast< BloomFilter* >(o);
        if(npc(GlacierImpl_startup_3_this->GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
            npc(GlacierImpl_startup_3_this->GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Got "_j)->append(static_cast< ::java::lang::Object* >(bv))->toString());

        if(npc(GlacierImpl_startup_3_this->GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::INFO)
            npc(GlacierImpl_startup_3_this->GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(npc(keySet)->numElements())->append(u" keys added, sending sync request..."_j)->toString());

        GlacierImpl_startup_3_this->GlacierImpl_this->sendMessage(nullptr, new ::rice::p2p::glacier::v2::messaging::GlacierSyncMessage(GlacierImpl_startup_3_this->GlacierImpl_this->getUID(), npc(grrm)->getCommonRange(), GlacierImpl_startup_3_this->offset, bv, GlacierImpl_startup_3_this->GlacierImpl_this->getLocalNodeHandle(), npc(npc(grrm)->getSource())->getId(), GlacierImpl_startup_3_this->GlacierImpl_this->tagSync), npc(grrm)->getSource());
    } else {
        if(npc(GlacierImpl_startup_3_this->GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(GlacierImpl_startup_3_this->GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"While processing range response: Result is of unknown type: "_j)->append(static_cast< ::java::lang::Object* >(o))
                ->append(u" -- discarding request"_j)->toString());

    }
}

void rice::p2p::glacier::v2::GlacierImpl_startup_3_receiveResult_3_2::receiveException(::java::lang::Exception* e)
{
    if(npc(GlacierImpl_startup_3_this->GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
        npc(GlacierImpl_startup_3_this->GlacierImpl_this->logger)->logException(::java::lang::StringBuilder().append(u"Exception while processing range response: "_j)->append(static_cast< ::java::lang::Object* >(e))
            ->append(u" -- discarding request"_j)->toString(), e);

}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::glacier::v2::GlacierImpl_startup_3_receiveResult_3_2::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::glacier::v2::GlacierImpl_startup_3_receiveResult_3_2::getClass0()
{
    return class_();
}

