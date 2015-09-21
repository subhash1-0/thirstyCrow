// Generated from /pastry-2.1/src/rice/p2p/glacier/v2/GlacierImpl.java
#include <rice/p2p/glacier/v2/GlacierImpl_startup_5.hpp>

#include <java/io/Serializable.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/util/Iterator.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/environment/time/TimeSource.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/commonapi/IdSet.hpp>
#include <rice/p2p/glacier/v2/FragmentMetadata.hpp>
#include <rice/p2p/glacier/v2/GlacierImpl_startup_5_timeoutExpired_5_1.hpp>
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

rice::p2p::glacier::v2::GlacierImpl_startup_5::GlacierImpl_startup_5(GlacierImpl *GlacierImpl_this)
    : super(*static_cast< ::default_init_tag* >(0))
    , GlacierImpl_this(GlacierImpl_this)
{
    clinit();
    ctor();
}

java::lang::String* rice::p2p::glacier::v2::GlacierImpl_startup_5::toString()
{
    return u"Garbage collector"_j;
}

void rice::p2p::glacier::v2::GlacierImpl_startup_5::init_()
{
    nextTimeout = npc(npc(GlacierImpl_this->environment)->getTimeSource())->currentTimeMillis() + GlacierImpl_this->garbageCollectionInterval;
}

void rice::p2p::glacier::v2::GlacierImpl_startup_5::receiveResult(::java::lang::Object* o)
{
    if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
        npc(GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"GC received object: "_j)->append(static_cast< ::java::lang::Object* >(o))->toString());

}

void rice::p2p::glacier::v2::GlacierImpl_startup_5::receiveException(::java::lang::Exception* e)
{
    if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
        npc(GlacierImpl_this->logger)->logException(u"GC received exception: "_j, e);

}

int64_t rice::p2p::glacier::v2::GlacierImpl_startup_5::getTimeout()
{
    return nextTimeout;
}

void rice::p2p::glacier::v2::GlacierImpl_startup_5::timeoutExpired()
{
    nextTimeout = npc(npc(GlacierImpl_this->environment)->getTimeSource())->currentTimeMillis() + GlacierImpl_this->garbageCollectionInterval;
    auto const now = npc(npc(GlacierImpl_this->environment)->getTimeSource())->currentTimeMillis();
    auto fragments = npc(GlacierImpl_this->fragmentStorage)->scan();
    int32_t doneSoFar = int32_t(0), candidates = int32_t(0);
    if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::INFO)
        npc(GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Garbage collection started at "_j)->append(now)
            ->append(u", scanning "_j)
            ->append(npc(fragments)->numElements())
            ->append(u" fragment(s)..."_j)->toString());

    auto iter = npc(fragments)->getIterator();
    while (npc(iter)->hasNext()) {
        auto const thisKey = java_cast< ::rice::p2p::commonapi::Id* >(java_cast< ::java::lang::Object* >(npc(iter)->next()));
        auto const metadata = java_cast< FragmentMetadata* >(npc(GlacierImpl_this->fragmentStorage)->getMetadata(thisKey));
        if(metadata != nullptr) {
            if(npc(metadata)->getCurrentExpiration() < now) {
                candidates++;
                if(doneSoFar < GlacierImpl_this->garbageCollectionMaxFragmentsPerRun) {
                    doneSoFar++;
                    GlacierImpl_this->deleteFragment(thisKey, new GlacierImpl_startup_5_timeoutExpired_5_1(this, thisKey, now, metadata));
                }
            }
        } else {
            if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
                npc(GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"GC cannot read metadata in object "_j)->append(npc(thisKey)->toStringFull())
                    ->append(u", storage returned null"_j)->toString());

        }
    }
    if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::INFO)
        npc(GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Garbage collection completed at "_j)->append(npc(npc(GlacierImpl_this->environment)->getTimeSource())->currentTimeMillis())->toString());

    if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::INFO)
        npc(GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Found "_j)->append(candidates)
            ->append(u" candidate(s), collected "_j)
            ->append(doneSoFar)->toString());

}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::glacier::v2::GlacierImpl_startup_5::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::glacier::v2::GlacierImpl_startup_5::getClass0()
{
    return class_();
}

