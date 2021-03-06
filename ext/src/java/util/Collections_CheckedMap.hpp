// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <java/util/function/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <java/util/Map.hpp>
#include <java/io/Serializable.hpp>

struct default_init_tag;

class java::util::Collections_CheckedMap
    : public virtual ::java::lang::Object
    , public virtual Map
    , public virtual ::java::io::Serializable
{

public:
    typedef ::java::lang::Object super;

private:
    Set* entrySet_ {  };

public: /* package */
    ::java::lang::Class* keyType {  };

private:
    Map* m {  };
    static constexpr int64_t serialVersionUID { int64_t(5742860141034234728LL) };

public: /* package */
    ::java::lang::Class* valueType {  };

protected:
    void ctor(Map* arg0, ::java::lang::Class* arg1, ::java::lang::Class* arg2);
    /*::java::lang::String* badKeyMsg(::java::lang::Object* arg0); (private) */
    /*::java::lang::String* badValueMsg(::java::lang::Object* arg0); (private) */

public:
    void clear() override;
    ::java::lang::Object* compute(::java::lang::Object* arg0, ::java::util::function::BiFunction* arg1) override;
    ::java::lang::Object* computeIfAbsent(::java::lang::Object* arg0, ::java::util::function::Function* arg1) override;
    ::java::lang::Object* computeIfPresent(::java::lang::Object* arg0, ::java::util::function::BiFunction* arg1) override;
    bool containsKey(::java::lang::Object* arg0) override;
    bool containsValue(::java::lang::Object* arg0) override;
    Set* entrySet() override;
    bool equals(::java::lang::Object* arg0) override;
    void forEach(::java::util::function::BiConsumer* arg0) override;
    ::java::lang::Object* get(::java::lang::Object* arg0) override;
    int32_t hashCode() override;
    bool isEmpty() override;
    Set* keySet() override;
    ::java::lang::Object* merge(::java::lang::Object* arg0, ::java::lang::Object* arg1, ::java::util::function::BiFunction* arg2) override;
    ::java::lang::Object* put(::java::lang::Object* arg0, ::java::lang::Object* arg1) override;
    void putAll(Map* arg0) override;
    ::java::lang::Object* putIfAbsent(::java::lang::Object* arg0, ::java::lang::Object* arg1) override;
    ::java::lang::Object* remove(::java::lang::Object* arg0) override;
    bool remove(::java::lang::Object* arg0, ::java::lang::Object* arg1) override;
    ::java::lang::Object* replace(::java::lang::Object* arg0, ::java::lang::Object* arg1) override;
    bool replace(::java::lang::Object* arg0, ::java::lang::Object* arg1, ::java::lang::Object* arg2) override;
    void replaceAll(::java::util::function::BiFunction* arg0) override;
    int32_t size() override;
    ::java::lang::String* toString() override;
    /*::java::util::function::BiFunction* typeCheck(::java::util::function::BiFunction* arg0); (private) */
    /*void typeCheck(::java::lang::Object* arg0, ::java::lang::Object* arg1); (private) */
    Collection* values() override;

    // Generated

public: /* package */
    Collections_CheckedMap(Map* arg0, ::java::lang::Class* arg1, ::java::lang::Class* arg2);
protected:
    Collections_CheckedMap(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
