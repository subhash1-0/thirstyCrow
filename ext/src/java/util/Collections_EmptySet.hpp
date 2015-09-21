// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <java/util/function/fwd-pastry-2.1.hpp>
#include <java/util/AbstractSet.hpp>
#include <java/io/Serializable.hpp>

struct default_init_tag;

class java::util::Collections_EmptySet
    : public AbstractSet
    , public virtual ::java::io::Serializable
{

public:
    typedef AbstractSet super;

private:
    static constexpr int64_t serialVersionUID { int64_t(1582296315990362920LL) };

    /*void ctor(); (private) */

public:
    bool contains(::java::lang::Object* arg0) override;
    bool containsAll(Collection* arg0) override;
    void forEach(::java::util::function::Consumer* arg0) override;
    bool isEmpty() override;
    Iterator* iterator() override;
    /*::java::lang::Object* readResolve(); (private) */
    bool removeIf(::java::util::function::Predicate* arg0) override;
    int32_t size() override;
    Spliterator* spliterator() override;
    ::java::lang::ObjectArray* toArray_() override;
    ::java::lang::ObjectArray* toArray_(::java::lang::ObjectArray* arg0) override;

    // Generated
    Collections_EmptySet();
protected:
    Collections_EmptySet(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
