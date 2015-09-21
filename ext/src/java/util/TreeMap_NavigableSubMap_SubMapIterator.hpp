// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <java/util/Iterator.hpp>

struct default_init_tag;

class java::util::TreeMap_NavigableSubMap_SubMapIterator
    : public virtual ::java::lang::Object
    , public virtual Iterator
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    int32_t expectedModCount {  };
    ::java::lang::Object* fenceKey {  };
    TreeMap_Entry* lastReturned {  };
    TreeMap_Entry* next {  };
    TreeMap_NavigableSubMap* this$0 {  };

protected:
    void ctor(TreeMap_Entry* a0, TreeMap_Entry* a1);

public:
    bool hasNext() override;

public: /* package */
    TreeMap_Entry* nextEntry();
    TreeMap_Entry* prevEntry();
    void removeAscending();
    void removeDescending();

    // Generated
    TreeMap_NavigableSubMap_SubMapIterator(TreeMap_NavigableSubMap *TreeMap_NavigableSubMap_this, TreeMap_Entry* a0, TreeMap_Entry* a1);
protected:
    TreeMap_NavigableSubMap_SubMapIterator(TreeMap_NavigableSubMap *TreeMap_NavigableSubMap_this, const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    TreeMap_NavigableSubMap *TreeMap_NavigableSubMap_this;

private:
    virtual ::java::lang::Class* getClass0();
};
