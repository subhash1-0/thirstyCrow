// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <java/util/fwd-pastry-2.1.hpp>
#include <java/util/TreeMap_NavigableSubMap_SubMapIterator.hpp>
#include <java/util/Map_Entry.hpp>

struct default_init_tag;

class java::util::TreeMap_NavigableSubMap_DescendingSubMapEntryIterator final
    : public TreeMap_NavigableSubMap_SubMapIterator
{

public:
    typedef TreeMap_NavigableSubMap_SubMapIterator super;

public: /* package */
    TreeMap_NavigableSubMap* this$0 {  };

protected:
    void ctor(TreeMap_Entry* a0, TreeMap_Entry* a1);

public:
    Map_Entry* next() override;
    void remove() override;

    // Generated

public: /* package */
    TreeMap_NavigableSubMap_DescendingSubMapEntryIterator(TreeMap_NavigableSubMap *TreeMap_NavigableSubMap_this, TreeMap_Entry* a0, TreeMap_Entry* a1);
protected:
    TreeMap_NavigableSubMap_DescendingSubMapEntryIterator(TreeMap_NavigableSubMap *TreeMap_NavigableSubMap_this, const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
