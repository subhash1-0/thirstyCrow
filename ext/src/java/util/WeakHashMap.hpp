// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/lang/ref/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <java/util/function/fwd-pastry-2.1.hpp>
#include <java/util/AbstractMap.hpp>
#include <java/util/Map.hpp>

template<typename ComponentType, typename... Bases> struct SubArray;
namespace java
{
    namespace lang
    {
        namespace ref
        {
typedef ::SubArray< ::java::lang::ref::Reference, ::java::lang::ObjectArray > ReferenceArray;
typedef ::SubArray< ::java::lang::ref::WeakReference, ReferenceArray > WeakReferenceArray;
        } // ref
    } // lang

    namespace util
    {
typedef ::SubArray< ::java::util::Map_Entry, ::java::lang::ObjectArray > Map_EntryArray;
typedef ::SubArray< ::java::util::WeakHashMap_Entry, ::java::lang::ref::WeakReferenceArray, Map_EntryArray > WeakHashMap_EntryArray;
    } // util
} // java

struct default_init_tag;

class java::util::WeakHashMap
    : public AbstractMap
    , public virtual Map
{

public:
    typedef AbstractMap super;

private:
    static constexpr int32_t DEFAULT_INITIAL_CAPACITY { int32_t(16) };
    static constexpr float DEFAULT_LOAD_FACTOR { 0.75f };
    static constexpr int32_t MAXIMUM_CAPACITY { int32_t(1073741824) };
    static ::java::lang::Object* NULL_KEY_;
    Set* entrySet_ {  };
    float loadFactor {  };

public: /* package */
    int32_t modCount {  };

private:
    ::java::lang::ref::ReferenceQueue* queue {  };
    int32_t size_ {  };

public: /* package */
    WeakHashMap_EntryArray* table {  };

private:
    int32_t threshold {  };

protected:
    void ctor();
    void ctor(int32_t arg0);
    void ctor(Map* arg0);
    void ctor(int32_t arg0, float arg1);

public:
    void clear() override;
    bool containsKey(::java::lang::Object* arg0) override;
    /*bool containsNullValue(); (private) */
    bool containsValue(::java::lang::Object* arg0) override;
    Set* entrySet() override;
    /*static bool eq(::java::lang::Object* arg0, ::java::lang::Object* arg1); (private) */
    /*void expungeStaleEntries(); (private) */
    void forEach(::java::util::function::BiConsumer* arg0) override;
    ::java::lang::Object* get(::java::lang::Object* arg0) override;

public: /* package */
    virtual WeakHashMap_Entry* getEntry(::java::lang::Object* arg0);
    /*WeakHashMap_EntryArray* getTable(); (private) */
    int32_t hash(::java::lang::Object* arg0);
    /*static int32_t indexFor(int32_t arg0, int32_t arg1); (private) */

public:
    bool isEmpty() override;
    Set* keySet() override;
    /*static ::java::lang::Object* maskNull(::java::lang::Object* arg0); (private) */
    /*WeakHashMap_EntryArray* newTable(int32_t arg0); (private) */
    ::java::lang::Object* put(::java::lang::Object* arg0, ::java::lang::Object* arg1) override;
    void putAll(Map* arg0) override;
    ::java::lang::Object* remove(::java::lang::Object* arg0) override;

public: /* package */
    virtual bool removeMapping(::java::lang::Object* arg0);

public:
    void replaceAll(::java::util::function::BiFunction* arg0) override;

public: /* package */
    virtual void resize(int32_t arg0);

public:
    int32_t size() override;
    /*void transfer(WeakHashMap_EntryArray* arg0, WeakHashMap_EntryArray* arg1); (private) */

public: /* package */
    static ::java::lang::Object* unmaskNull(::java::lang::Object* arg0);

public:
    Collection* values() override;

    // Generated
    WeakHashMap();
    WeakHashMap(int32_t arg0);
    WeakHashMap(Map* arg0);
    WeakHashMap(int32_t arg0, float arg1);
protected:
    WeakHashMap(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    virtual bool equals(::java::lang::Object* arg0);
    virtual int32_t hashCode();
    virtual bool remove(::java::lang::Object* arg0, ::java::lang::Object* arg1);

private:
    static ::java::lang::Object*& NULL_KEY();
    virtual ::java::lang::Class* getClass0();
};
