// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <java/util/LinkedHashMap_LinkedHashIterator.hpp>
#include <java/util/Iterator.hpp>

struct default_init_tag;

class java::util::LinkedHashMap_LinkedKeyIterator final
    : public LinkedHashMap_LinkedHashIterator
    , public Iterator
{

public:
    typedef LinkedHashMap_LinkedHashIterator super;

public: /* package */
    LinkedHashMap* this$0 {  };

protected:
    void ctor();

public:
    ::java::lang::Object* next() override;

    // Generated

public: /* package */
    LinkedHashMap_LinkedKeyIterator(LinkedHashMap *LinkedHashMap_this);
protected:
    LinkedHashMap_LinkedKeyIterator(LinkedHashMap *LinkedHashMap_this, const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    virtual bool hasNext();
    virtual void remove();

private:
    virtual ::java::lang::Class* getClass0();
};
