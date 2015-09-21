// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <java/util/function/fwd-pastry-2.1.hpp>
#include <java/util/AbstractMap.hpp>
#include <java/io/Serializable.hpp>

struct default_init_tag;

class java::util::Collections_SingletonMap
    : public AbstractMap
    , public virtual ::java::io::Serializable
{

public:
    typedef AbstractMap super;

private:
    Set* entrySet_ {  };
    ::java::lang::Object* k {  };
    Set* keySet_ {  };
    static constexpr int64_t serialVersionUID { int64_t(-6979724477215052911LL) };
    ::java::lang::Object* v {  };
    Collection* values_ {  };

protected:
    void ctor(::java::lang::Object* arg0, ::java::lang::Object* arg1);

public:
    ::java::lang::Object* compute(::java::lang::Object* arg0, ::java::util::function::BiFunction* arg1) override;
    ::java::lang::Object* computeIfAbsent(::java::lang::Object* arg0, ::java::util::function::Function* arg1) override;
    ::java::lang::Object* computeIfPresent(::java::lang::Object* arg0, ::java::util::function::BiFunction* arg1) override;
    bool containsKey(::java::lang::Object* arg0) override;
    bool containsValue(::java::lang::Object* arg0) override;
    Set* entrySet() override;
    void forEach(::java::util::function::BiConsumer* arg0) override;
    ::java::lang::Object* get(::java::lang::Object* arg0) override;
    ::java::lang::Object* getOrDefault(::java::lang::Object* arg0, ::java::lang::Object* arg1) override;
    bool isEmpty() override;
    Set* keySet() override;
    ::java::lang::Object* merge(::java::lang::Object* arg0, ::java::lang::Object* arg1, ::java::util::function::BiFunction* arg2) override;
    ::java::lang::Object* putIfAbsent(::java::lang::Object* arg0, ::java::lang::Object* arg1) override;
    bool remove(::java::lang::Object* arg0, ::java::lang::Object* arg1) override;
    ::java::lang::Object* replace(::java::lang::Object* arg0, ::java::lang::Object* arg1) override;
    bool replace(::java::lang::Object* arg0, ::java::lang::Object* arg1, ::java::lang::Object* arg2) override;
    void replaceAll(::java::util::function::BiFunction* arg0) override;
    int32_t size() override;
    Collection* values() override;

    // Generated

public: /* package */
    Collections_SingletonMap(::java::lang::Object* arg0, ::java::lang::Object* arg1);
protected:
    Collections_SingletonMap(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    ::java::lang::Object* remove(::java::lang::Object* key);

private:
    virtual ::java::lang::Class* getClass0();
};
