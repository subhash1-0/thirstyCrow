// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <java/util/function/fwd-pastry-2.1.hpp>
#include <java/util/stream/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <java/util/Collection.hpp>
#include <java/io/Serializable.hpp>

struct default_init_tag;

class java::util::Collections_SynchronizedCollection
    : public virtual ::java::lang::Object
    , public virtual Collection
    , public virtual ::java::io::Serializable
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    Collection* c {  };
    ::java::lang::Object* mutex {  };

private:
    static constexpr int64_t serialVersionUID { int64_t(3053995032091335093LL) };

protected:
    void ctor(Collection* arg0);
    void ctor(Collection* arg0, ::java::lang::Object* arg1);

public:
    bool add(::java::lang::Object* arg0) override;
    bool addAll(Collection* arg0) override;
    void clear() override;
    bool contains(::java::lang::Object* arg0) override;
    bool containsAll(Collection* arg0) override;
    void forEach(::java::util::function::Consumer* arg0) override;
    bool isEmpty() override;
    Iterator* iterator() override;
    ::java::util::stream::Stream* parallelStream() override;
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
    /*void writeObject(::java::io::ObjectOutputStream* arg0); (private) */

    // Generated

public: /* package */
    Collections_SynchronizedCollection(Collection* arg0);
    Collections_SynchronizedCollection(Collection* arg0, ::java::lang::Object* arg1);
protected:
    Collections_SynchronizedCollection(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    virtual bool equals(::java::lang::Object* o);
    virtual int32_t hashCode();

private:
    virtual ::java::lang::Class* getClass0();
};
