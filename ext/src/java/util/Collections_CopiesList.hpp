// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <java/util/stream/fwd-pastry-2.1.hpp>
#include <java/util/AbstractList.hpp>
#include <java/util/RandomAccess.hpp>
#include <java/io/Serializable.hpp>

struct default_init_tag;

class java::util::Collections_CopiesList
    : public AbstractList
    , public virtual RandomAccess
    , public virtual ::java::io::Serializable
{

public:
    typedef AbstractList super;

private:
    static bool $assertionsDisabled_;

public: /* package */
    ::java::lang::Object* element {  };
    int32_t n {  };

private:
    static constexpr int64_t serialVersionUID { int64_t(2739099268398711800LL) };

protected:
    void ctor(int32_t arg0, ::java::lang::Object* arg1);

public:
    bool contains(::java::lang::Object* arg0) override;
    ::java::lang::Object* get(int32_t arg0) override;
    int32_t indexOf(::java::lang::Object* arg0) override;
    int32_t lastIndexOf(::java::lang::Object* arg0) override;
    ::java::util::stream::Stream* parallelStream() override;
    int32_t size() override;
    Spliterator* spliterator() override;
    ::java::util::stream::Stream* stream() override;
    List* subList(int32_t arg0, int32_t arg1) override;
    ::java::lang::ObjectArray* toArray_() override;
    ::java::lang::ObjectArray* toArray_(::java::lang::ObjectArray* arg0) override;

    // Generated

public: /* package */
    Collections_CopiesList(int32_t arg0, ::java::lang::Object* arg1);
protected:
    Collections_CopiesList(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

public: /* package */
    static bool& $assertionsDisabled();

private:
    virtual ::java::lang::Class* getClass0();
};
