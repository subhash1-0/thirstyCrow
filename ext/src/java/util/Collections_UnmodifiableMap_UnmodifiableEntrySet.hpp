// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <java/util/function/fwd-pastry-2.1.hpp>
#include <java/util/stream/fwd-pastry-2.1.hpp>
#include <java/util/Collections_UnmodifiableSet.hpp>

struct default_init_tag;

class java::util::Collections_UnmodifiableMap_UnmodifiableEntrySet
    : public Collections_UnmodifiableSet
{

public:
    typedef Collections_UnmodifiableSet super;

private:
    static constexpr int64_t serialVersionUID { int64_t(7854390611657943733LL) };

protected:
    void ctor(Set* arg0);

public:
    bool contains(::java::lang::Object* arg0) override;
    bool containsAll(Collection* arg0) override;

public: /* package */
    static ::java::util::function::Consumer* entryConsumer(::java::util::function::Consumer* arg0);

public:
    bool equals(::java::lang::Object* arg0) override;
    void forEach(::java::util::function::Consumer* arg0) override;
    Iterator* iterator() override;
    ::java::util::stream::Stream* parallelStream() override;
    Spliterator* spliterator() override;
    ::java::util::stream::Stream* stream() override;
    ::java::lang::ObjectArray* toArray_() override;
    ::java::lang::ObjectArray* toArray_(::java::lang::ObjectArray* arg0) override;

    // Generated

public: /* package */
    Collections_UnmodifiableMap_UnmodifiableEntrySet(Set* arg0);
protected:
    Collections_UnmodifiableMap_UnmodifiableEntrySet(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
