// Generated from /pastry-2.1/src/rice/p2p/glacier/v2/GlacierImpl.java
#include <rice/p2p/glacier/v2/GlacierImpl_startup_2_timeoutExpired_2_1.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/Long.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/glacier/v2/GlacierImpl_startup_2.hpp>
#include <rice/p2p/glacier/v2/GlacierImpl_startup_2_timeoutExpired_2_1_receiveResult_2_1_1.hpp>
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

rice::p2p::glacier::v2::GlacierImpl_startup_2_timeoutExpired_2_1::GlacierImpl_startup_2_timeoutExpired_2_1(GlacierImpl_startup_2 *GlacierImpl_startup_2_this, ::rice::p2p::commonapi::Id* thisNeighbor, int64_t earliestAcceptableDate)
    : super(*static_cast< ::default_init_tag* >(0))
    , GlacierImpl_startup_2_this(GlacierImpl_startup_2_this)
    , thisNeighbor(thisNeighbor)
    , earliestAcceptableDate(earliestAcceptableDate)
{
    clinit();
    ctor();
}

void rice::p2p::glacier::v2::GlacierImpl_startup_2_timeoutExpired_2_1::receiveResult(::java::lang::Object* o)
{
    if(o == nullptr) {
        if(npc(GlacierImpl_startup_2_this->GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(GlacierImpl_startup_2_this->GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"CNE: Cannot retrieve neighbor "_j)->append(static_cast< ::java::lang::Object* >(thisNeighbor))->toString());

        return;
    }
    auto lastSeen = npc((java_cast< ::java::lang::Long* >(o)))->longValue();
    if(lastSeen < earliestAcceptableDate) {
        if(npc(GlacierImpl_startup_2_this->GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::INFO)
            npc(GlacierImpl_startup_2_this->GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"CNE: Removing expired neighbor "_j)->append(static_cast< ::java::lang::Object* >(thisNeighbor))
                ->append(u" ("_j)
                ->append(lastSeen)
                ->append(u"<"_j)
                ->append(earliestAcceptableDate)
                ->append(u")"_j)->toString());

        npc(GlacierImpl_startup_2_this->GlacierImpl_this->neighborStorage)->unstore(thisNeighbor, new GlacierImpl_startup_2_timeoutExpired_2_1_receiveResult_2_1_1(this, thisNeighbor));
    } else {
        if(npc(GlacierImpl_startup_2_this->GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::INFO)
            npc(GlacierImpl_startup_2_this->GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"CNE: Neighbor "_j)->append(static_cast< ::java::lang::Object* >(thisNeighbor))
                ->append(u" still active, last seen "_j)
                ->append(lastSeen)->toString());

    }
}

void rice::p2p::glacier::v2::GlacierImpl_startup_2_timeoutExpired_2_1::receiveException(::java::lang::Exception* e)
{
    if(npc(GlacierImpl_startup_2_this->GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
        npc(GlacierImpl_startup_2_this->GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"CNE: Exception while retrieving neighbor "_j)->append(static_cast< ::java::lang::Object* >(thisNeighbor))
            ->append(u", e="_j)
            ->append(static_cast< ::java::lang::Object* >(e))->toString());

}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::glacier::v2::GlacierImpl_startup_2_timeoutExpired_2_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::glacier::v2::GlacierImpl_startup_2_timeoutExpired_2_1::getClass0()
{
    return class_();
}

