// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <java/util/AbstractSet.hpp>

struct default_init_tag;

class java::util::WeakHashMap_KeySet
    : public AbstractSet
{

public:
    typedef AbstractSet super;

public: /* package */
    WeakHashMap* this$0 {  };

    /*void ctor(); (private) */

public:
    void clear() override;
    bool contains(::java::lang::Object* arg0) override;
    Iterator* iterator() override;
    bool remove(::java::lang::Object* arg0) override;
    int32_t size() override;
    Spliterator* spliterator() override;

    // Generated
    WeakHashMap_KeySet(WeakHashMap *WeakHashMap_this);
protected:
    WeakHashMap_KeySet(WeakHashMap *WeakHashMap_this, const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    WeakHashMap *WeakHashMap_this;

private:
    virtual ::java::lang::Class* getClass0();
};
