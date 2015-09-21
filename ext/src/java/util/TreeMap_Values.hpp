// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <java/util/AbstractCollection.hpp>

struct default_init_tag;

class java::util::TreeMap_Values
    : public AbstractCollection
{

public:
    typedef AbstractCollection super;

public: /* package */
    TreeMap* this$0 {  };

protected:
    void ctor();

public:
    void clear() override;
    bool contains(::java::lang::Object* arg0) override;
    Iterator* iterator() override;
    bool remove(::java::lang::Object* arg0) override;
    int32_t size() override;
    Spliterator* spliterator() override;

    // Generated

public: /* package */
    TreeMap_Values(TreeMap *TreeMap_this);
protected:
    TreeMap_Values(TreeMap *TreeMap_this, const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    TreeMap *TreeMap_this;

private:
    virtual ::java::lang::Class* getClass0();
};
