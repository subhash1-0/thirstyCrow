// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <java/util/function/fwd-pastry-2.1.hpp>
#include <java/util/stream/fwd-pastry-2.1.hpp>
#include <java/util/Collections_SynchronizedCollection.hpp>
#include <java/util/Set.hpp>

struct default_init_tag;

class java::util::Collections_SynchronizedSet
    : public Collections_SynchronizedCollection
    , public virtual Set
{

public:
    typedef Collections_SynchronizedCollection super;

private:
    static constexpr int64_t serialVersionUID { int64_t(487447009682186044LL) };

protected:
    void ctor(Set* arg0);
    void ctor(Set* arg0, ::java::lang::Object* arg1);

public:
    bool equals(::java::lang::Object* arg0) override;
    int32_t hashCode() override;

    // Generated

public: /* package */
    Collections_SynchronizedSet(Set* arg0);
    Collections_SynchronizedSet(Set* arg0, ::java::lang::Object* arg1);
protected:
    Collections_SynchronizedSet(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    virtual void forEach(::java::util::function::Consumer* action);
    virtual ::java::util::stream::Stream* parallelStream();
    virtual bool removeIf(::java::util::function::Predicate* filter);
    virtual ::java::util::stream::Stream* stream();
    bool add(::java::lang::Object* arg0);
    bool addAll(Collection* arg0);
    void clear();
    bool contains(::java::lang::Object* arg0);
    bool containsAll(Collection* arg0);
    bool isEmpty();
    Iterator* iterator();
    bool remove(::java::lang::Object* arg0);
    bool removeAll(Collection* arg0);
    bool retainAll(Collection* arg0);
    int32_t size();
    Spliterator* spliterator();
    ::java::lang::ObjectArray* toArray_();
    ::java::lang::ObjectArray* toArray_(::java::lang::ObjectArray* arg0);

private:
    virtual ::java::lang::Class* getClass0();
};
