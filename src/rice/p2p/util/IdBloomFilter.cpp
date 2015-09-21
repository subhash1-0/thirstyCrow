// Generated from /pastry-2.1/src/rice/p2p/util/IdBloomFilter.java
#include <rice/p2p/util/IdBloomFilter.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/util/Iterator.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/commonapi/IdSet.hpp>
#include <rice/p2p/util/BloomFilter.hpp>
#include <Array.hpp>

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

rice::p2p::util::IdBloomFilter::IdBloomFilter(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::util::IdBloomFilter::IdBloomFilter(::rice::p2p::commonapi::IdSet* set) 
    : IdBloomFilter(*static_cast< ::default_init_tag* >(0))
{
    ctor(set);
}

rice::p2p::util::IdBloomFilter::IdBloomFilter(::rice::p2p::commonapi::rawserialization::InputBuffer* buf)  /* throws(IOException) */
    : IdBloomFilter(*static_cast< ::default_init_tag* >(0))
{
    ctor(buf);
}

constexpr int64_t rice::p2p::util::IdBloomFilter::serialVersionUID;

int32_t& rice::p2p::util::IdBloomFilter::NUM_BITS_PER_KEY()
{
    clinit();
    return NUM_BITS_PER_KEY_;
}
int32_t rice::p2p::util::IdBloomFilter::NUM_BITS_PER_KEY_;

int32_t& rice::p2p::util::IdBloomFilter::NUM_HASH_FUNCTIONS()
{
    clinit();
    return NUM_HASH_FUNCTIONS_;
}
int32_t rice::p2p::util::IdBloomFilter::NUM_HASH_FUNCTIONS_;

void rice::p2p::util::IdBloomFilter::ctor(::rice::p2p::commonapi::IdSet* set)
{
    super::ctor();
    auto size = (npc(set)->numElements() < 64 ? int32_t(64) : npc(set)->numElements());
    this->filter = new BloomFilter(NUM_HASH_FUNCTIONS_, NUM_BITS_PER_KEY_ * size);
    auto i = npc(set)->getIterator();
    while (npc(i)->hasNext()) 
                addId(java_cast< ::rice::p2p::commonapi::Id* >(java_cast< ::rice::p2p::commonapi::Id* >(npc(i)->next())));

}

void rice::p2p::util::IdBloomFilter::checkArray_(::rice::p2p::commonapi::Id* id)
{
    if(array == nullptr)
        array = npc(id)->toByteArray_();
    else
        npc(id)->toByteArray_(array, 0);
}

void rice::p2p::util::IdBloomFilter::addId(::rice::p2p::commonapi::Id* id)
{
    checkArray_(id);
    npc(filter)->add(array);
}

bool rice::p2p::util::IdBloomFilter::check(::rice::p2p::commonapi::Id* id)
{
    checkArray_(id);
    return npc(filter)->check(array);
}

void rice::p2p::util::IdBloomFilter::check(::rice::p2p::commonapi::IdSet* set, ::rice::p2p::commonapi::IdSet* result, int32_t max)
{
    auto it = npc(set)->getIterator();
    auto count = int32_t(0);
    while (npc(it)->hasNext() && (count < max)) {
        auto next = java_cast< ::rice::p2p::commonapi::Id* >(java_cast< ::rice::p2p::commonapi::Id* >(npc(it)->next()));
        if(!check(next)) {
            npc(result)->addId(next);
            count++;
        }
    }
}

void rice::p2p::util::IdBloomFilter::ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf) /* throws(IOException) */
{
    super::ctor();
    filter = new BloomFilter(buf);
}

void rice::p2p::util::IdBloomFilter::serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */
{
    npc(filter)->serialize(buf);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::util::IdBloomFilter::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.util.IdBloomFilter", 27);
    return c;
}

void rice::p2p::util::IdBloomFilter::clinit()
{
    super::clinit();
    static bool in_cl_init = false;
struct clinit_ {
    clinit_() {
        in_cl_init = true;
        NUM_BITS_PER_KEY_ = int32_t(4);
        NUM_HASH_FUNCTIONS_ = int32_t(2);
    }
};

    if(!in_cl_init) {
        static clinit_ clinit_instance;
    }
}

java::lang::Class* rice::p2p::util::IdBloomFilter::getClass0()
{
    return class_();
}

