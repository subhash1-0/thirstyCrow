// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <java/util/TreeMap_PrivateEntryIterator.hpp>

struct default_init_tag;

class java::util::TreeMap_DescendingKeyIterator final
    : public TreeMap_PrivateEntryIterator
{

public:
    typedef TreeMap_PrivateEntryIterator super;

public: /* package */
    TreeMap* this$0 {  };

protected:
    void ctor(TreeMap_Entry* arg0);

public:
    ::java::lang::Object* next() override;
    void remove() override;

    // Generated

public: /* package */
    TreeMap_DescendingKeyIterator(TreeMap *TreeMap_this, TreeMap_Entry* arg0);
protected:
    TreeMap_DescendingKeyIterator(TreeMap *TreeMap_this, const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
