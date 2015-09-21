// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct default_init_tag;

class java::util::LinkedList_Node
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    ::java::lang::Object* item {  };
    LinkedList_Node* next {  };
    LinkedList_Node* prev {  };

protected:
    void ctor(LinkedList_Node* arg0, ::java::lang::Object* arg1, LinkedList_Node* arg2);

    // Generated

public: /* package */
    LinkedList_Node(LinkedList_Node* arg0, ::java::lang::Object* arg1, LinkedList_Node* arg2);
protected:
    LinkedList_Node(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
