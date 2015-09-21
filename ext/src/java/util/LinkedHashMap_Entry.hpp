// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <java/util/HashMap_Node.hpp>

struct default_init_tag;

class java::util::LinkedHashMap_Entry
    : public HashMap_Node
{

public:
    typedef HashMap_Node super;

public: /* package */
    LinkedHashMap_Entry* after {  };
    LinkedHashMap_Entry* before {  };

protected:
    void ctor(int32_t arg0, ::java::lang::Object* arg1, ::java::lang::Object* arg2, HashMap_Node* arg3);

    // Generated

public: /* package */
    LinkedHashMap_Entry(int32_t arg0, ::java::lang::Object* arg1, ::java::lang::Object* arg2, HashMap_Node* arg3);
protected:
    LinkedHashMap_Entry(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
