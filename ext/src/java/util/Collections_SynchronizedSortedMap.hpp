// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <java/util/function/fwd-pastry-2.1.hpp>
#include <java/util/Collections_SynchronizedMap.hpp>
#include <java/util/SortedMap.hpp>

struct default_init_tag;

class java::util::Collections_SynchronizedSortedMap
    : public Collections_SynchronizedMap
    , public virtual SortedMap
{

public:
    typedef Collections_SynchronizedMap super;

private:
    static constexpr int64_t serialVersionUID { int64_t(-8798146769416483793LL) };
    SortedMap* sm {  };

protected:
    void ctor(SortedMap* arg0);
    void ctor(SortedMap* arg0, ::java::lang::Object* arg1);

public:
    Comparator* comparator() override;
    ::java::lang::Object* firstKey() override;
    SortedMap* headMap(::java::lang::Object* arg0) override;
    ::java::lang::Object* lastKey() override;
    SortedMap* subMap(::java::lang::Object* arg0, ::java::lang::Object* arg1) override;
    SortedMap* tailMap(::java::lang::Object* arg0) override;

    // Generated

public: /* package */
    Collections_SynchronizedSortedMap(SortedMap* arg0);
    Collections_SynchronizedSortedMap(SortedMap* arg0, ::java::lang::Object* arg1);
protected:
    Collections_SynchronizedSortedMap(const ::default_init_tag&);


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
    Set* entrySet();
    Set* keySet();
    Collection* values();

private:
    virtual ::java::lang::Class* getClass0();
};
