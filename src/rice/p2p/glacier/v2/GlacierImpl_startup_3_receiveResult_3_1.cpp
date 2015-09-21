// Generated from /pastry-2.1/src/rice/p2p/glacier/v2/GlacierImpl.java
#include <rice/p2p/glacier/v2/GlacierImpl_startup_3_receiveResult_3_1.hpp>

#include <java/io/Serializable.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/util/Iterator.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/commonapi/IdRange.hpp>
#include <rice/p2p/commonapi/IdSet.hpp>
#include <rice/p2p/glacier/FragmentKey.hpp>
#include <rice/p2p/glacier/VersionKey.hpp>
#include <rice/p2p/glacier/v2/BloomFilter.hpp>
#include <rice/p2p/glacier/v2/FragmentMetadata.hpp>
#include <rice/p2p/glacier/v2/GlacierImpl_startup_3.hpp>
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

rice::p2p::glacier::v2::GlacierImpl_startup_3_receiveResult_3_1::GlacierImpl_startup_3_receiveResult_3_1(GlacierImpl_startup_3 *GlacierImpl_startup_3_this, ::rice::p2p::commonapi::IdSet* keySet, ::rice::p2p::commonapi::IdRange* originalRange)
    : super(*static_cast< ::default_init_tag* >(0))
    , GlacierImpl_startup_3_this(GlacierImpl_startup_3_this)
    , keySet(keySet)
    , originalRange(originalRange)
{
    clinit();
    ctor();
}

java::lang::Object* rice::p2p::glacier::v2::GlacierImpl_startup_3_receiveResult_3_1::execute()
{
    auto bv = new BloomFilter((int32_t(2) * npc(keySet)->numElements() + int32_t(5)) * GlacierImpl_startup_3_this->GlacierImpl_this->syncBloomFilterBitsPerKey, GlacierImpl_startup_3_this->GlacierImpl_this->syncBloomFilterNumHashes, npc(GlacierImpl_startup_3_this->GlacierImpl_this->environment)->getRandomSource());
    auto iter = npc(keySet)->getIterator();
    while (npc(iter)->hasNext()) {
        auto fkey = java_cast< ::rice::p2p::glacier::FragmentKey* >(java_cast< ::java::lang::Object* >(npc(iter)->next()));
        auto thisPos = GlacierImpl_startup_3_this->GlacierImpl_this->getFragmentLocation(fkey);
        if(npc(originalRange)->containsId(thisPos)) {
            auto metadata = java_cast< FragmentMetadata* >(npc(GlacierImpl_startup_3_this->GlacierImpl_this->fragmentStorage)->getMetadata(fkey));
            if(metadata != nullptr) {
                auto currentExp = npc(metadata)->getCurrentExpiration();
                auto prevExp = npc(metadata)->getPreviousExpiration();
                if(npc(GlacierImpl_startup_3_this->GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINER)
                    npc(GlacierImpl_startup_3_this->GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u" - Adding "_j)->append(static_cast< ::java::lang::Object* >(fkey))
                        ->append(u" as "_j)
                        ->append(static_cast< ::java::lang::Object* >(npc(npc(fkey)->getVersionKey())->getId()))
                        ->append(u", ecur="_j)
                        ->append(currentExp)
                        ->append(u", eprev="_j)
                        ->append(prevExp)->toString());

                npc(bv)->add(GlacierImpl_startup_3_this->GlacierImpl_this->getHashInput(npc(fkey)->getVersionKey(), currentExp));
                npc(bv)->add(GlacierImpl_startup_3_this->GlacierImpl_this->getHashInput(npc(fkey)->getVersionKey(), prevExp));
            } else {
                if(npc(GlacierImpl_startup_3_this->GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
                    npc(GlacierImpl_startup_3_this->GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"SYNC Cannot read metadata of object "_j)->append(npc(fkey)->toStringFull())
                        ->append(u", storage returned null"_j)->toString());

            }
        }
    }
    return bv;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::glacier::v2::GlacierImpl_startup_3_receiveResult_3_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::glacier::v2::GlacierImpl_startup_3_receiveResult_3_1::getClass0()
{
    return class_();
}

