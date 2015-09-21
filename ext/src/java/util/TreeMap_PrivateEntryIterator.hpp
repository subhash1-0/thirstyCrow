// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <java/util/Iterator.hpp>

struct default_init_tag;

class java::util::TreeMap_PrivateEntryIterator
    : public virtual ::java::lang::Object
    , public virtual Iterator
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    int32_t expectedModCount {  };
    TreeMap_Entry* lastReturned {  };
    TreeMap_Entry* next {  };
    TreeMap* this$0 {  };

protected:
    void ctor(TreeMap_Entry* arg0);

public:
    bool hasNext() override;

public: /* package */
    TreeMap_Entry* nextEntry();
    TreeMap_Entry* prevEntry();

public:
    void remove() override;

    // Generated

public: /* package */
    TreeMap_PrivateEntryIterator(TreeMap *TreeMap_this, TreeMap_Entry* arg0);
protected:
    TreeMap_PrivateEntryIterator(TreeMap *TreeMap_this, const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    TreeMap *TreeMap_this;

private:
    virtual ::java::lang::Class* getClass0();
};
