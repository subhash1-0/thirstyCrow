// Generated from /pastry-2.1/src/rice/p2p/util/StringCache.java

#pragma once

#include <atomic>
#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/p2p/util/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

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

struct default_init_tag;

class rice::p2p::util::StringCache
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    static constexpr int32_t DEFAULT_INITIAL_CAPACITY { int32_t(16) };
    static constexpr int32_t MAXIMUM_CAPACITY { int32_t(1073741824) };
    static constexpr float DEFAULT_LOAD_FACTOR { 0.75f };
    StringCache_EntryArray* table {  };
    int32_t size_ {  };
    int32_t threshold {  };
    float loadFactor {  };
    std::atomic< int32_t > modCount {  };
protected:
    void ctor();

public: /* package */
    static int32_t hash(::char16_tArray* chars, int32_t off, int32_t len);
    static bool eq(::char16_tArray* chars, int32_t off, int32_t len, ::java::lang::String* s);
    static int32_t indexFor(int32_t h, int32_t length);

public:
    virtual int32_t size();
    virtual bool isEmpty();
    virtual ::java::lang::String* get(::char16_tArray* chars);
    virtual ::java::lang::String* get(::char16_tArray* chars, int32_t offset, int32_t length);

public: /* package */
    virtual void resize(int32_t newCapacity);
    virtual void transfer(StringCache_EntryArray* newTable);

public:
    virtual void clear();

public: /* package */
    virtual void addEntry(int32_t hash, ::java::lang::String* value, int32_t bucketIndex);

private:
    static constexpr int64_t serialVersionUID { int64_t(362498820763181265LL) };

    // Generated

public:
    StringCache();
protected:
    StringCache(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
    friend class StringCache_Entry;
};
