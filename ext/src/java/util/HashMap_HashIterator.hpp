// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct default_init_tag;

class java::util::HashMap_HashIterator
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    HashMap_Node* current {  };
    int32_t expectedModCount {  };
    int32_t index {  };
    HashMap_Node* next {  };
    HashMap* this$0 {  };

protected:
    void ctor();

public:
    bool hasNext();

public: /* package */
    HashMap_Node* nextNode();

public:
    void remove();

    // Generated

public: /* package */
    HashMap_HashIterator(HashMap *HashMap_this);
protected:
    HashMap_HashIterator(HashMap *HashMap_this, const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    HashMap *HashMap_this;

private:
    virtual ::java::lang::Class* getClass0();
};
