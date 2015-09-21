// Generated from /pastry-2.1/src/rice/p2p/glacier/v2/GlacierImpl.java
#include <rice/p2p/glacier/v2/GlacierImpl_neighborSeen_25.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/Long.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/glacier/v2/GlacierImpl_neighborSeen_25_receiveResult_25_1.hpp>
#include <rice/p2p/glacier/v2/GlacierImpl.hpp>
#include <rice/persistence/StorageManager.hpp>

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

rice::p2p::glacier::v2::GlacierImpl_neighborSeen_25::GlacierImpl_neighborSeen_25(GlacierImpl *GlacierImpl_this, ::rice::p2p::commonapi::Id* fNodeId, int64_t fWhen)
    : super(*static_cast< ::default_init_tag* >(0))
    , GlacierImpl_this(GlacierImpl_this)
    , fNodeId(fNodeId)
    , fWhen(fWhen)
{
    clinit();
    ctor();
}

void rice::p2p::glacier::v2::GlacierImpl_neighborSeen_25::receiveResult(::java::lang::Object* o)
{
    if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Continue: neighborSeen ("_j)->append(static_cast< ::java::lang::Object* >(fNodeId))
            ->append(u", "_j)
            ->append(fWhen)
            ->append(u") after getObject"_j)->toString());

    auto const previousWhen = (o != nullptr) ? npc((java_cast< ::java::lang::Long* >(o)))->longValue() : static_cast< int64_t >(int32_t(0));
    if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Neighbor: "_j)->append(static_cast< ::java::lang::Object* >(fNodeId))
            ->append(u" previously seen at "_j)
            ->append(previousWhen)->toString());

    if(previousWhen >= fWhen) {
        if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
            npc(GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Neighbor: No update needed (new TS="_j)->append(fWhen)
                ->append(u")"_j)->toString());

        return;
    }
    npc(GlacierImpl_this->neighborStorage)->store(fNodeId, nullptr, new ::java::lang::Long(fWhen), new GlacierImpl_neighborSeen_25_receiveResult_25_1(this, fNodeId, fWhen, previousWhen));
}

void rice::p2p::glacier::v2::GlacierImpl_neighborSeen_25::receiveException(::java::lang::Exception* e)
{
    if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
        npc(GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"receiveException("_j)->append(static_cast< ::java::lang::Object* >(e))
            ->append(u") while retrieving a neighbor ("_j)
            ->append(static_cast< ::java::lang::Object* >(fNodeId))
            ->append(u")"_j)->toString());

}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::glacier::v2::GlacierImpl_neighborSeen_25::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::glacier::v2::GlacierImpl_neighborSeen_25::getClass0()
{
    return class_();
}

