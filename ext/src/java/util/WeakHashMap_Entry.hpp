// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/lang/ref/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <java/lang/ref/WeakReference.hpp>
#include <java/util/Map_Entry.hpp>

struct default_init_tag;

class java::util::WeakHashMap_Entry
    : public ::java::lang::ref::WeakReference
    , public virtual Map_Entry
{

public:
    typedef ::java::lang::ref::WeakReference super;

public: /* package */
    int32_t hash {  };
    WeakHashMap_Entry* next {  };
    ::java::lang::Object* value {  };

protected:
    void ctor(::java::lang::Object* arg0, ::java::lang::Object* arg1, ::java::lang::ref::ReferenceQueue* arg2, int32_t arg3, WeakHashMap_Entry* arg4);

public:
    bool equals(::java::lang::Object* arg0) override;
    ::java::lang::Object* getKey() override;
    ::java::lang::Object* getValue() override;
    int32_t hashCode() override;
    ::java::lang::Object* setValue(::java::lang::Object* arg0) override;
    ::java::lang::String* toString() override;

    // Generated

public: /* package */
    WeakHashMap_Entry(::java::lang::Object* arg0, ::java::lang::Object* arg1, ::java::lang::ref::ReferenceQueue* arg2, int32_t arg3, WeakHashMap_Entry* arg4);
protected:
    WeakHashMap_Entry(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
