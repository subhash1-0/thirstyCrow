// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <java/util/function/fwd-pastry-2.1.hpp>
#include <java/util/Collections_SynchronizedSortedMap.hpp>
#include <java/util/NavigableMap.hpp>
#include <java/util/NavigableSet.hpp>

struct default_init_tag;

class java::util::Collections_SynchronizedNavigableMap
    : public Collections_SynchronizedSortedMap
    , public virtual NavigableMap
{

public:
    typedef Collections_SynchronizedSortedMap super;

private:
    NavigableMap* nm {  };
    static constexpr int64_t serialVersionUID { int64_t(699392247599746807LL) };

protected:
    void ctor(NavigableMap* arg0);
    void ctor(NavigableMap* arg0, ::java::lang::Object* arg1);

public:
    Map_Entry* ceilingEntry(::java::lang::Object* arg0) override;
    ::java::lang::Object* ceilingKey(::java::lang::Object* arg0) override;
    NavigableSet* descendingKeySet() override;
    NavigableMap* descendingMap() override;
    Map_Entry* firstEntry() override;
    Map_Entry* floorEntry(::java::lang::Object* arg0) override;
    ::java::lang::Object* floorKey(::java::lang::Object* arg0) override;
    SortedMap* headMap(::java::lang::Object* arg0) override;
    NavigableMap* headMap(::java::lang::Object* arg0, bool arg1) override;
    Map_Entry* higherEntry(::java::lang::Object* arg0) override;
    ::java::lang::Object* higherKey(::java::lang::Object* arg0) override;
    NavigableSet* keySet() override;
    Map_Entry* lastEntry() override;
    Map_Entry* lowerEntry(::java::lang::Object* arg0) override;
    ::java::lang::Object* lowerKey(::java::lang::Object* arg0) override;
    NavigableSet* navigableKeySet() override;
    Map_Entry* pollFirstEntry() override;
    Map_Entry* pollLastEntry() override;
    SortedMap* subMap(::java::lang::Object* arg0, ::java::lang::Object* arg1) override;
    NavigableMap* subMap(::java::lang::Object* arg0, bool arg1, ::java::lang::Object* arg2, bool arg3) override;
    SortedMap* tailMap(::java::lang::Object* arg0) override;
    NavigableMap* tailMap(::java::lang::Object* arg0, bool arg1) override;

    // Generated

public: /* package */
    Collections_SynchronizedNavigableMap(NavigableMap* arg0);
    Collections_SynchronizedNavigableMap(NavigableMap* arg0, ::java::lang::Object* arg1);
protected:
    Collections_SynchronizedNavigableMap(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    virtual void clear();
    virtual ::java::lang::Object* compute(::java::lang::Object* arg0, ::java::util::function::BiFunction* arg1);
    virtual ::java::lang::Object* computeIfAbsent(::java::lang::Object* arg0, ::java::util::function::Function* arg1);
    virtual ::java::lang::Object* computeIfPresent(::java::lang::Object* arg0, ::java::util::function::BiFunction* arg1);
    virtual bool containsKey(::java::lang::Object* arg0);
    virtual bool containsValue(::java::lang::Object* arg0);
    virtual bool equals(::java::lang::Object* arg0);
    virtual void forEach(::java::util::function::BiConsumer* arg0);
    virtual ::java::lang::Object* get(::java::lang::Object* arg0);
    virtual ::java::lang::Object* getOrDefault(::java::lang::Object* arg0, ::java::lang::Object* arg1);
    virtual int32_t hashCode();
    virtual bool isEmpty();
    virtual ::java::lang::Object* merge(::java::lang::Object* arg0, ::java::lang::Object* arg1, ::java::util::function::BiFunction* arg2);
    virtual ::java::lang::Object* put(::java::lang::Object* arg0, ::java::lang::Object* arg1);
    virtual void putAll(Map* arg0);
    virtual ::java::lang::Object* putIfAbsent(::java::lang::Object* arg0, ::java::lang::Object* arg1);
    virtual ::java::lang::Object* remove(::java::lang::Object* arg0);
    virtual bool remove(::java::lang::Object* arg0, ::java::lang::Object* arg1);
    virtual ::java::lang::Object* replace(::java::lang::Object* arg0, ::java::lang::Object* arg1);
    virtual bool replace(::java::lang::Object* arg0, ::java::lang::Object* arg1, ::java::lang::Object* arg2);
    virtual void replaceAll(::java::util::function::BiFunction* arg0);
    virtual int32_t size();
    virtual Comparator* comparator();
    Set* entrySet();
    virtual ::java::lang::Object* firstKey();
    virtual ::java::lang::Object* lastKey();
    Collection* values();

private:
    virtual ::java::lang::Class* getClass0();
};
