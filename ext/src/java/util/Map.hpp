// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <java/util/function/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct java::util::Map
    : public virtual ::java::lang::Object
{

    virtual void clear() = 0;
    virtual ::java::lang::Object* compute(::java::lang::Object* key, ::java::util::function::BiFunction* remappingFunction);
    virtual ::java::lang::Object* computeIfAbsent(::java::lang::Object* key, ::java::util::function::Function* mappingFunction);
    virtual ::java::lang::Object* computeIfPresent(::java::lang::Object* key, ::java::util::function::BiFunction* remappingFunction);
    virtual bool containsKey(::java::lang::Object* key) = 0;
    virtual bool containsValue(::java::lang::Object* value) = 0;
    virtual Set* entrySet() = 0;
    /*virtual bool equals(::java::lang::Object* o); (already declared) */
    virtual void forEach(::java::util::function::BiConsumer* action);
    virtual ::java::lang::Object* get(::java::lang::Object* key) = 0;
    virtual ::java::lang::Object* getOrDefault(::java::lang::Object* key, ::java::lang::Object* defaultValue);
    /*virtual int32_t hashCode(); (already declared) */
    virtual bool isEmpty() = 0;
    virtual Set* keySet() = 0;
    virtual ::java::lang::Object* merge(::java::lang::Object* key, ::java::lang::Object* value, ::java::util::function::BiFunction* remappingFunction);
    virtual ::java::lang::Object* put(::java::lang::Object* key, ::java::lang::Object* value) = 0;
    virtual void putAll(Map* m) = 0;
    virtual ::java::lang::Object* putIfAbsent(::java::lang::Object* key, ::java::lang::Object* value);
    virtual ::java::lang::Object* remove(::java::lang::Object* key) = 0;
    virtual bool remove(::java::lang::Object* key, ::java::lang::Object* value);
    virtual ::java::lang::Object* replace(::java::lang::Object* key, ::java::lang::Object* value);
    virtual bool replace(::java::lang::Object* key, ::java::lang::Object* oldValue, ::java::lang::Object* newValue);
    virtual void replaceAll(::java::util::function::BiFunction* function);
    virtual int32_t size() = 0;
    virtual Collection* values() = 0;

    // Generated
    static ::java::lang::Class *class_();
};
