// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <java/util/function/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <java/util/Iterator.hpp>

struct default_init_tag;

class java::util::Vector_Itr
    : public virtual ::java::lang::Object
    , public virtual Iterator
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    int32_t cursor {  };
    int32_t expectedModCount {  };
    int32_t lastRet {  };
    Vector* this$0 {  };

    /*void ctor(); (private) */
    void checkForComodification();

public:
    void forEachRemaining(::java::util::function::Consumer* arg0) override;
    bool hasNext() override;
    ::java::lang::Object* next() override;
    void remove() override;

    // Generated
    Vector_Itr(Vector *Vector_this);
protected:
    Vector_Itr(Vector *Vector_this, const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    Vector *Vector_this;

private:
    virtual ::java::lang::Class* getClass0();
};
