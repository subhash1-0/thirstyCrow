// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct default_init_tag;

class java::util::WeakHashMap_WeakHashMapSpliterator
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    WeakHashMap_Entry* current {  };
    int32_t est {  };
    int32_t expectedModCount {  };
    int32_t fence {  };
    int32_t index {  };
    WeakHashMap* map {  };

protected:
    void ctor(WeakHashMap* arg0, int32_t arg1, int32_t arg2, int32_t arg3, int32_t arg4);

public:
    int64_t estimateSize();

public: /* package */
    int32_t getFence();

    // Generated
    WeakHashMap_WeakHashMapSpliterator(WeakHashMap* arg0, int32_t arg1, int32_t arg2, int32_t arg3, int32_t arg4);
protected:
    WeakHashMap_WeakHashMapSpliterator(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
