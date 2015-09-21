// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <java/util/function/fwd-pastry-2.1.hpp>
#include <java/util/AbstractSet.hpp>
#include <java/io/Serializable.hpp>

struct default_init_tag;

class java::util::Collections_SingletonSet
    : public AbstractSet
    , public virtual ::java::io::Serializable
{

public:
    typedef AbstractSet super;

private:
    ::java::lang::Object* element {  };
    static constexpr int64_t serialVersionUID { int64_t(3193687207550431679LL) };

protected:
    void ctor(::java::lang::Object* arg0);

public:
    bool contains(::java::lang::Object* arg0) override;
    void forEach(::java::util::function::Consumer* arg0) override;
    Iterator* iterator() override;
    bool removeIf(::java::util::function::Predicate* arg0) override;
    int32_t size() override;
    Spliterator* spliterator() override;

    // Generated

public: /* package */
    Collections_SingletonSet(::java::lang::Object* arg0);
protected:
    Collections_SingletonSet(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
