// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <java/util/AbstractSet.hpp>

struct default_init_tag;

class java::util::TreeMap_NavigableSubMap_EntrySetView
    : public AbstractSet
{

public:
    typedef AbstractSet super;

private:
    int32_t size_ {  };
    int32_t sizeModCount {  };

public: /* package */
    TreeMap_NavigableSubMap* this$0 {  };

protected:
    void ctor();

public:
    bool contains(::java::lang::Object* arg0) override;
    bool isEmpty() override;
    bool remove(::java::lang::Object* arg0) override;
    int32_t size() override;

    // Generated

public: /* package */
    TreeMap_NavigableSubMap_EntrySetView(TreeMap_NavigableSubMap *TreeMap_NavigableSubMap_this);
protected:
    TreeMap_NavigableSubMap_EntrySetView(TreeMap_NavigableSubMap *TreeMap_NavigableSubMap_this, const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    TreeMap_NavigableSubMap *TreeMap_NavigableSubMap_this;

private:
    virtual ::java::lang::Class* getClass0();
};
