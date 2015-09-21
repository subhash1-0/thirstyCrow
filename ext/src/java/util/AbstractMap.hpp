// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <atomic>
#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <java/util/Map.hpp>

struct default_init_tag;

class java::util::AbstractMap
    : public virtual ::java::lang::Object
    , public virtual Map
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    std::atomic< Set* > keySet_ {  };
    std::atomic< Collection* > values_ {  };

protected:
    void ctor();

public:
    void clear() override;

public: /* protected */
    ::java::lang::Object* clone() override;

public:
    bool containsKey(::java::lang::Object* arg0) override;
    bool containsValue(::java::lang::Object* arg0) override;
    /*Set* entrySet(); (already declared) */
    /*static bool eq(::java::lang::Object* arg0, ::java::lang::Object* arg1); (private) */
    bool equals(::java::lang::Object* arg0) override;
    ::java::lang::Object* get(::java::lang::Object* arg0) override;
    int32_t hashCode() override;
    bool isEmpty() override;
    Set* keySet() override;
    ::java::lang::Object* put(::java::lang::Object* arg0, ::java::lang::Object* arg1) override;
    void putAll(Map* arg0) override;
    ::java::lang::Object* remove(::java::lang::Object* arg0) override;
    int32_t size() override;
    ::java::lang::String* toString() override;
    Collection* values() override;

    // Generated

public: /* protected */
    AbstractMap();
protected:
    AbstractMap(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    virtual bool remove(::java::lang::Object* arg0, ::java::lang::Object* arg1);

private:
    virtual ::java::lang::Class* getClass0();
};
