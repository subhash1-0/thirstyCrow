// Generated from /pastry-2.1/src/rice/p2p/util/testing/IdBloomFilterReplicationTest.java
#include <rice/p2p/util/testing/IdBloomFilterReplicationTest.hpp>

#include <java/io/PrintStream.hpp>
#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Comparable.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>
#include <java/util/Iterator.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/random/RandomSource.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/commonapi/IdFactory.hpp>
#include <rice/p2p/commonapi/IdSet.hpp>
#include <rice/p2p/multiring/MultiringIdFactory.hpp>
#include <rice/p2p/past/gc/GCIdFactory.hpp>
#include <rice/p2p/util/IdBloomFilter.hpp>
#include <rice/pastry/commonapi/PastryIdFactory.hpp>
#include <SubArray.hpp>
#include <ObjectArray.hpp>

template<typename ComponentType, typename... Bases> struct SubArray;
namespace java
{
    namespace io
    {
typedef ::SubArray< ::java::io::Serializable, ::java::lang::ObjectArray > SerializableArray;
    } // io

    namespace lang
    {
typedef ::SubArray< ::java::lang::CharSequence, ObjectArray > CharSequenceArray;
typedef ::SubArray< ::java::lang::Comparable, ObjectArray > ComparableArray;
typedef ::SubArray< ::java::lang::String, ObjectArray, ::java::io::SerializableArray, ComparableArray, CharSequenceArray > StringArray;
    } // lang
} // java

namespace rice
{
    namespace p2p
    {
        namespace commonapi
        {
typedef ::SubArray< ::rice::p2p::commonapi::Id, ::java::lang::ObjectArray, ::java::lang::ComparableArray, ::java::io::SerializableArray > IdArray;
        } // commonapi
    } // p2p
} // rice

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

rice::p2p::util::testing::IdBloomFilterReplicationTest::IdBloomFilterReplicationTest(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::util::testing::IdBloomFilterReplicationTest::IdBloomFilterReplicationTest()
    : IdBloomFilterReplicationTest(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

int32_t& rice::p2p::util::testing::IdBloomFilterReplicationTest::NUM()
{
    clinit();
    return NUM_;
}
int32_t rice::p2p::util::testing::IdBloomFilterReplicationTest::NUM_;

int32_t& rice::p2p::util::testing::IdBloomFilterReplicationTest::NUM_RUNS()
{
    clinit();
    return NUM_RUNS_;
}
int32_t rice::p2p::util::testing::IdBloomFilterReplicationTest::NUM_RUNS_;

rice::environment::random::RandomSource*& rice::p2p::util::testing::IdBloomFilterReplicationTest::random()
{
    clinit();
    return random_;
}
rice::environment::random::RandomSource* rice::p2p::util::testing::IdBloomFilterReplicationTest::random_;

rice::p2p::commonapi::IdFactory*& rice::p2p::util::testing::IdBloomFilterReplicationTest::pFactory()
{
    clinit();
    return pFactory_;
}
rice::p2p::commonapi::IdFactory* rice::p2p::util::testing::IdBloomFilterReplicationTest::pFactory_;

rice::p2p::commonapi::IdFactory*& rice::p2p::util::testing::IdBloomFilterReplicationTest::factory()
{
    clinit();
    return factory_;
}
rice::p2p::commonapi::IdFactory* rice::p2p::util::testing::IdBloomFilterReplicationTest::factory_;

rice::p2p::past::gc::GCIdFactory*& rice::p2p::util::testing::IdBloomFilterReplicationTest::gFactory()
{
    clinit();
    return gFactory_;
}
rice::p2p::past::gc::GCIdFactory* rice::p2p::util::testing::IdBloomFilterReplicationTest::gFactory_;

rice::p2p::commonapi::IdArray*& rice::p2p::util::testing::IdBloomFilterReplicationTest::SHARED()
{
    clinit();
    return SHARED_;
}
rice::p2p::commonapi::IdArray* rice::p2p::util::testing::IdBloomFilterReplicationTest::SHARED_;

rice::p2p::commonapi::IdArray*& rice::p2p::util::testing::IdBloomFilterReplicationTest::EXTRA()
{
    clinit();
    return EXTRA_;
}
rice::p2p::commonapi::IdArray* rice::p2p::util::testing::IdBloomFilterReplicationTest::EXTRA_;

rice::p2p::commonapi::IdSet*& rice::p2p::util::testing::IdBloomFilterReplicationTest::remote()
{
    clinit();
    return remote_;
}
rice::p2p::commonapi::IdSet* rice::p2p::util::testing::IdBloomFilterReplicationTest::remote_;

void rice::p2p::util::testing::IdBloomFilterReplicationTest::main(::java::lang::StringArray* args) /* throws(IOException) */
{
    clinit();
    auto env = new ::rice::environment::Environment();
    random_ = npc(env)->getRandomSource();
    pFactory_ = new ::rice::pastry::commonapi::PastryIdFactory(env);
    factory_ = new ::rice::p2p::multiring::MultiringIdFactory(npc(pFactory_)->buildRandomId(random_), pFactory_);
    gFactory_ = new ::rice::p2p::past::gc::GCIdFactory(factory_);
    doConfig();
}

void rice::p2p::util::testing::IdBloomFilterReplicationTest::buildShared()
{
    clinit();
    remote_ = npc(factory_)->buildIdSet();
    for (auto i = int32_t(0); i < npc(SHARED_)->length; i++) {
        SHARED_->set(i, npc(factory_)->buildRandomId(random_));
        npc(remote_)->addId((*SHARED_)[i]);
    }
    for (auto i = int32_t(0); i < npc(EXTRA_)->length; i++) 
                EXTRA_->set(i, npc(factory_)->buildRandomId(random_));

}

void rice::p2p::util::testing::IdBloomFilterReplicationTest::doConfig()
{
    clinit();
    npc(::java::lang::System::out())->println();
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"BPK: "_j)->append(::rice::p2p::util::IdBloomFilter::NUM_BITS_PER_KEY())
        ->append(u"\tHASH: "_j)
        ->append(::rice::p2p::util::IdBloomFilter::NUM_HASH_FUNCTIONS())->toString());
    npc(::java::lang::System::out())->print(u"\t\t"_j);
    for (auto i = int32_t(0); i < int32_t(2) * NUM_; i += NUM_ / int32_t(10)) 
                npc(::java::lang::System::out())->print(::java::lang::StringBuilder().append(i)->append(u"\t"_j)->toString());

    npc(::java::lang::System::out())->println(u"\n"_j);
    for (auto i = int32_t(0); i < NUM_; i += NUM_ / int32_t(10)) {
        npc(::java::lang::System::out())->print(::java::lang::StringBuilder().append(i)->append(u"\t\t"_j)->toString());
        npc(::java::lang::System::out())->print(::java::lang::StringBuilder().append(doRun(i, 10000))->append(u"\t"_j)->toString());
        npc(::java::lang::System::out())->println();
    }
}

double rice::p2p::util::testing::IdBloomFilterReplicationTest::doRun(int32_t has, int32_t extra)
{
    clinit();
    auto total = int32_t(0);
    for (auto i = int32_t(0); i < NUM_RUNS_; i++) 
                total += run(has, extra);

    return (static_cast< double >(total)) / (static_cast< double >(NUM_RUNS_));
}

int32_t rice::p2p::util::testing::IdBloomFilterReplicationTest::run(int32_t has, int32_t extra)
{
    clinit();
    buildShared();
    auto local = npc(factory_)->buildIdSet();
    for (auto i = int32_t(0); i < has; i++) 
                npc(local)->addId((*SHARED_)[i]);

    for (auto i = int32_t(0); i < extra; i++) 
                npc(local)->addId((*EXTRA_)[i]);

    auto count = int32_t(0);
    auto missing = NUM_ - has;
    while (missing > 0) {
        count++;
        auto filter = new ::rice::p2p::util::IdBloomFilter(local);
        auto i = npc(remote_)->getIterator();
        while (npc(i)->hasNext()) {
            auto next = java_cast< ::rice::p2p::commonapi::Id* >(java_cast< ::rice::p2p::commonapi::Id* >(npc(i)->next()));
            if(!npc(filter)->check(next)) {
                npc(local)->addId(next);
                missing--;
            }
        }
    }
    return count;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::util::testing::IdBloomFilterReplicationTest::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.util.testing.IdBloomFilterReplicationTest", 50);
    return c;
}

void rice::p2p::util::testing::IdBloomFilterReplicationTest::clinit()
{
    super::clinit();
    static bool in_cl_init = false;
struct clinit_ {
    clinit_() {
        in_cl_init = true;
        NUM_ = int32_t(10000);
        NUM_RUNS_ = int32_t(100);
        random_ = nullptr;
        pFactory_ = nullptr;
        factory_ = nullptr;
        gFactory_ = nullptr;
        SHARED_ = new ::rice::p2p::commonapi::IdArray(NUM_);
        EXTRA_ = new ::rice::p2p::commonapi::IdArray(int32_t(2) * NUM_);
    }
};

    if(!in_cl_init) {
        static clinit_ clinit_instance;
    }
}

java::lang::Class* rice::p2p::util::testing::IdBloomFilterReplicationTest::getClass0()
{
    return class_();
}

