// Generated from /pastry-2.1/src/rice/p2p/glacier/v2/GlacierImpl.java
#include <rice/p2p/glacier/v2/GlacierImpl_neighborSeen_25_receiveResult_25_1.hpp>

#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/glacier/v2/GlacierImpl_neighborSeen_25.hpp>
#include <rice/p2p/glacier/v2/GlacierImpl.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::glacier::v2::GlacierImpl_neighborSeen_25_receiveResult_25_1::GlacierImpl_neighborSeen_25_receiveResult_25_1(GlacierImpl_neighborSeen_25 *GlacierImpl_neighborSeen_25_this, ::rice::p2p::commonapi::Id* fNodeId, int64_t fWhen, int64_t previousWhen)
    : super(*static_cast< ::default_init_tag* >(0))
    , GlacierImpl_neighborSeen_25_this(GlacierImpl_neighborSeen_25_this)
    , fNodeId(fNodeId)
    , fWhen(fWhen)
    , previousWhen(previousWhen)
{
    clinit();
    ctor();
}

void rice::p2p::glacier::v2::GlacierImpl_neighborSeen_25_receiveResult_25_1::receiveResult(::java::lang::Object* o)
{
    if(npc(GlacierImpl_neighborSeen_25_this->GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(GlacierImpl_neighborSeen_25_this->GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Continue: neighborSeen ("_j)->append(static_cast< ::java::lang::Object* >(fNodeId))
            ->append(u", "_j)
            ->append(fWhen)
            ->append(u") after store"_j)->toString());

    if(npc(GlacierImpl_neighborSeen_25_this->GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(GlacierImpl_neighborSeen_25_this->GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Neighbor: Updated "_j)->append(static_cast< ::java::lang::Object* >(fNodeId))
            ->append(u" from "_j)
            ->append(previousWhen)
            ->append(u" to "_j)
            ->append(fWhen)->toString());

    GlacierImpl_neighborSeen_25_this->GlacierImpl_this->determineResponsibleRange();
}

void rice::p2p::glacier::v2::GlacierImpl_neighborSeen_25_receiveResult_25_1::receiveException(::java::lang::Exception* e)
{
    if(npc(GlacierImpl_neighborSeen_25_this->GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
        npc(GlacierImpl_neighborSeen_25_this->GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"receiveException("_j)->append(static_cast< ::java::lang::Object* >(e))
            ->append(u") while storing a neighbor ("_j)
            ->append(static_cast< ::java::lang::Object* >(fNodeId))
            ->append(u")"_j)->toString());

}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::glacier::v2::GlacierImpl_neighborSeen_25_receiveResult_25_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::glacier::v2::GlacierImpl_neighborSeen_25_receiveResult_25_1::getClass0()
{
    return class_();
}

