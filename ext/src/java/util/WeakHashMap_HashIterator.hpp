// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <java/util/Iterator.hpp>

struct default_init_tag;

class java::util::WeakHashMap_HashIterator
    : public virtual ::java::lang::Object
    , public virtual Iterator
{

public:
    typedef ::java::lang::Object super;

private:
    ::java::lang::Object* currentKey {  };
    WeakHashMap_Entry* entry {  };
    int32_t expectedModCount {  };
    int32_t index {  };
    WeakHashMap_Entry* lastReturned {  };
    ::java::lang::Object* nextKey {  };

public: /* package */
    WeakHashMap* this$0 {  };

protected:
    void ctor();

public:
    bool hasNext() override;

public: /* protected */
    virtual WeakHashMap_Entry* nextEntry();

public:
    void remove() override;

    // Generated

public: /* package */
    WeakHashMap_HashIterator(WeakHashMap *WeakHashMap_this);
protected:
    WeakHashMap_HashIterator(WeakHashMap *WeakHashMap_this, const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    WeakHashMap *WeakHashMap_this;

private:
    virtual ::java::lang::Class* getClass0();
};
