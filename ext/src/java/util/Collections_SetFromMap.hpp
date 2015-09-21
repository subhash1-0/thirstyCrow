// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <java/util/function/fwd-pastry-2.1.hpp>
#include <java/util/stream/fwd-pastry-2.1.hpp>
#include <java/util/AbstractSet.hpp>
#include <java/util/Set.hpp>
#include <java/io/Serializable.hpp>

struct default_init_tag;

class java::util::Collections_SetFromMap
    : public AbstractSet
    , public virtual Set
    , public virtual ::java::io::Serializable
{

public:
    typedef AbstractSet super;

private:
    Map* m {  };
    Set* s {  };
    static constexpr int64_t serialVersionUID { int64_t(2454657854757543876LL) };

protected:
    void ctor(Map* arg0);

public:
    bool add(::java::lang::Object* arg0) override;
    void clear() override;
    bool contains(::java::lang::Object* arg0) override;
    bool containsAll(Collection* arg0) override;
    bool equals(::java::lang::Object* arg0) override;
    void forEach(::java::util::function::Consumer* arg0) override;
    int32_t hashCode() override;
    bool isEmpty() override;
    Iterator* iterator() override;
    ::java::util::stream::Stream* parallelStream() override;
    /*void readObject(::java::io::ObjectInputStream* arg0); (private) */
    bool remove(::java::lang::Object* arg0) override;
    bool removeAll(Collection* arg0) override;
    bool removeIf(::java::util::function::Predicate* arg0) override;
    bool retainAll(Collection* arg0) override;
    int32_t size() override;
    Spliterator* spliterator() override;
    ::java::util::stream::Stream* stream() override;
    ::java::lang::ObjectArray* toArray_() override;
    ::java::lang::ObjectArray* toArray_(::java::lang::ObjectArray* arg0) override;
    ::java::lang::String* toString() override;

    // Generated

public: /* package */
    Collections_SetFromMap(Map* arg0);
protected:
    Collections_SetFromMap(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    bool addAll(Collection* arg0);

private:
    virtual ::java::lang::Class* getClass0();
};
