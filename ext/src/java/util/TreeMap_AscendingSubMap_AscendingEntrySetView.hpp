// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <java/util/fwd-pastry-2.1.hpp>
#include <java/util/TreeMap_NavigableSubMap_EntrySetView.hpp>

struct default_init_tag;

class java::util::TreeMap_AscendingSubMap_AscendingEntrySetView final
    : public TreeMap_NavigableSubMap_EntrySetView
{

public:
    typedef TreeMap_NavigableSubMap_EntrySetView super;

public: /* package */
    TreeMap_AscendingSubMap* this$0 {  };

protected:
    void ctor();

public:
    Iterator* iterator() override;

    // Generated

public: /* package */
    TreeMap_AscendingSubMap_AscendingEntrySetView(TreeMap_AscendingSubMap *TreeMap_AscendingSubMap_this);
protected:
    TreeMap_AscendingSubMap_AscendingEntrySetView(TreeMap_AscendingSubMap *TreeMap_AscendingSubMap_this, const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    TreeMap_AscendingSubMap *TreeMap_AscendingSubMap_this;

private:
    virtual ::java::lang::Class* getClass0();
};
