// Generated from /pastry-2.1/src/rice/p2p/util/StringCache.java
#include <rice/p2p/util/StringCache.hpp>

#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/Integer.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/String.hpp>
#include <rice/p2p/util/StringCache_Entry.hpp>
#include <Array.hpp>
#include <ObjectArray.hpp>
#include <SubArray.hpp>

template<typename ComponentType, typename... Bases> struct SubArray;
namespace rice
{
    namespace p2p
    {
        namespace util
        {
typedef ::SubArray< ::rice::p2p::util::StringCache_Entry, ::java::lang::ObjectArray > StringCache_EntryArray;
        } // util
    } // p2p
} // rice

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::util::StringCache::StringCache(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::util::StringCache::StringCache() 
    : StringCache(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

constexpr int32_t rice::p2p::util::StringCache::DEFAULT_INITIAL_CAPACITY;

constexpr int32_t rice::p2p::util::StringCache::MAXIMUM_CAPACITY;

constexpr float rice::p2p::util::StringCache::DEFAULT_LOAD_FACTOR;

void rice::p2p::util::StringCache::ctor()
{
    super::ctor();
    this->loadFactor = DEFAULT_LOAD_FACTOR;
    threshold = static_cast< int32_t >((DEFAULT_INITIAL_CAPACITY * DEFAULT_LOAD_FACTOR));
    table = new StringCache_EntryArray(DEFAULT_INITIAL_CAPACITY);
}

int32_t rice::p2p::util::StringCache::hash(::char16_tArray* chars, int32_t off, int32_t len)
{
    clinit();
    auto h = int32_t(0);
    for (auto i = int32_t(0); i < len; i++) 
                h = int32_t(31) * h + (*chars)[off++];

    return h;
}

bool rice::p2p::util::StringCache::eq(::char16_tArray* chars, int32_t off, int32_t len, ::java::lang::String* s)
{
    clinit();
    if(len != npc(s)->length())
        return false;

    for (auto i = int32_t(0); i < len; i++) 
                if((*chars)[i + off] != npc(s)->charAt(i))
            return false;


    return true;
}

int32_t rice::p2p::util::StringCache::indexFor(int32_t h, int32_t length)
{
    clinit();
    return h & (length - int32_t(1));
}

int32_t rice::p2p::util::StringCache::size()
{
    return size_;
}

bool rice::p2p::util::StringCache::isEmpty()
{
    return size_ == 0;
}

java::lang::String* rice::p2p::util::StringCache::get(::char16_tArray* chars)
{
    return get(chars, 0, npc(chars)->length);
}

java::lang::String* rice::p2p::util::StringCache::get(::char16_tArray* chars, int32_t offset, int32_t length)
{
    auto hash = StringCache::hash(chars, offset, length);
    auto i = indexFor(hash, npc(table)->length);
    auto e = (*table)[i];
    while (true) {
        if(e == nullptr) {
            auto s = new ::java::lang::String(chars, offset, length);
            addEntry(hash, s, i);
            return s;
        }
        if(npc(e)->hash == hash && eq(chars, offset, length, npc(e)->value))
            return npc(e)->value;

        e = npc(e)->next;
    }
}

void rice::p2p::util::StringCache::resize(int32_t newCapacity)
{
    auto oldTable = table;
    auto oldCapacity = npc(oldTable)->length;
    if(oldCapacity == MAXIMUM_CAPACITY) {
        threshold = ::java::lang::Integer::MAX_VALUE;
        return;
    }
    auto newTable = new StringCache_EntryArray(newCapacity);
    transfer(newTable);
    table = newTable;
    threshold = static_cast< int32_t >((newCapacity * loadFactor));
}

void rice::p2p::util::StringCache::transfer(StringCache_EntryArray* newTable)
{
    auto src = table;
    auto newCapacity = npc(newTable)->length;
    for (auto j = int32_t(0); j < npc(src)->length; j++) {
        auto e = (*src)[j];
        if(e != nullptr) {
            src->set(j, nullptr);
            do {
                auto next = npc(e)->next;
                auto i = indexFor(npc(e)->hash, newCapacity);
                npc(e)->next = (*newTable)[i];
                newTable->set(i, e);
                e = next;
            } while (e != nullptr);
        }
    }
}

void rice::p2p::util::StringCache::clear()
{
    modCount++;
    auto tab = table;
    for (auto i = int32_t(0); i < npc(tab)->length; i++) 
                tab->set(i, nullptr);

    size_ = 0;
}

void rice::p2p::util::StringCache::addEntry(int32_t hash, ::java::lang::String* value, int32_t bucketIndex)
{
    table->set(bucketIndex, new StringCache_Entry(hash, value, (*table)[bucketIndex]));
    if(size_++ >= threshold)
        resize(int32_t(2) * npc(table)->length);

}

constexpr int64_t rice::p2p::util::StringCache::serialVersionUID;

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::util::StringCache::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.util.StringCache", 25);
    return c;
}

java::lang::Class* rice::p2p::util::StringCache::getClass0()
{
    return class_();
}

