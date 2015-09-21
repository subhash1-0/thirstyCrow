// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <java/util/WeakHashMap_HashIterator.hpp>

struct default_init_tag;

class java::util::WeakHashMap_ValueIterator
    : public WeakHashMap_HashIterator
{

public:
    typedef WeakHashMap_HashIterator super;

public: /* package */
    WeakHashMap* this$0 {  };

    /*void ctor(); (private) */

public:
    ::java::lang::Object* next() override;

    // Generated
    WeakHashMap_ValueIterator(WeakHashMap *WeakHashMap_this);
protected:
    WeakHashMap_ValueIterator(WeakHashMap *WeakHashMap_this, const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
