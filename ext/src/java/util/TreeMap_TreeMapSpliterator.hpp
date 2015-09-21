// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct default_init_tag;

class java::util::TreeMap_TreeMapSpliterator
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    TreeMap_Entry* current {  };
    int32_t est {  };
    int32_t expectedModCount {  };
    TreeMap_Entry* fence {  };
    int32_t side {  };
    TreeMap* tree {  };

protected:
    void ctor(TreeMap* arg0, TreeMap_Entry* arg1, TreeMap_Entry* arg2, int32_t arg3, int32_t arg4, int32_t arg5);

public:
    int64_t estimateSize();

public: /* package */
    int32_t getEstimate();

    // Generated
    TreeMap_TreeMapSpliterator(TreeMap* arg0, TreeMap_Entry* arg1, TreeMap_Entry* arg2, int32_t arg3, int32_t arg4, int32_t arg5);
protected:
    TreeMap_TreeMapSpliterator(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
