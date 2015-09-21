// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <java/util/function/fwd-pastry-2.1.hpp>
#include <java/util/stream/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <java/util/Collection.hpp>
#include <java/io/Serializable.hpp>

struct default_init_tag;

class java::util::Collections_CheckedCollection
    : public virtual ::java::lang::Object
    , public virtual Collection
    , public virtual ::java::io::Serializable
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    Collection* c {  };

private:
    static constexpr int64_t serialVersionUID { int64_t(1578914078182001775LL) };

public: /* package */
    ::java::lang::Class* type {  };

private:
    ::java::lang::ObjectArray* zeroLengthElementArray__ {  };

protected:
    void ctor(Collection* arg0, ::java::lang::Class* arg1);

public:
    bool add(::java::lang::Object* arg0) override;
    bool addAll(Collection* arg0) override;
    /*::java::lang::String* badElementMsg(::java::lang::Object* arg0); (private) */

public: /* package */
    virtual Collection* checkedCopyOf(Collection* arg0);

public:
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

public: /* package */
    virtual ::java::lang::Object* typeCheck(::java::lang::Object* arg0);
    /*::java::lang::ObjectArray* zeroLengthElementArray_(); (private) */

    // Generated
    Collections_CheckedCollection(Collection* arg0, ::java::lang::Class* arg1);
protected:
    Collections_CheckedCollection(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    virtual bool equals(::java::lang::Object* arg0);
    virtual int32_t hashCode();

private:
    virtual ::java::lang::Class* getClass0();
};
