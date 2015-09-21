// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <java/util/Iterator.hpp>

struct default_init_tag;

class java::util::PriorityQueue_Itr final
    : public virtual ::java::lang::Object
    , public Iterator
{

public:
    typedef ::java::lang::Object super;

private:
    int32_t cursor {  };
    int32_t expectedModCount {  };
    ArrayDeque* forgetMeNot {  };
    int32_t lastRet {  };
    ::java::lang::Object* lastRetElt {  };

public: /* package */
    PriorityQueue* this$0 {  };

    /*void ctor(); (private) */

public:
    bool hasNext() override;
    ::java::lang::Object* next() override;
    void remove() override;

    // Generated
    PriorityQueue_Itr(PriorityQueue *PriorityQueue_this);
protected:
    PriorityQueue_Itr(PriorityQueue *PriorityQueue_this, const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    PriorityQueue *PriorityQueue_this;

private:
    virtual ::java::lang::Class* getClass0();
};
