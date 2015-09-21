// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct default_init_tag;

class java::io::ObjectOutputStream_ReplaceTable
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;

private:
    ObjectOutputStream_HandleTable* htab {  };
    ::java::lang::ObjectArray* reps {  };

protected:
    void ctor(int32_t arg0, float arg1);

public: /* package */
    virtual void assign(::java::lang::Object* arg0, ::java::lang::Object* arg1);
    virtual void clear();
    /*void grow(); (private) */
    virtual ::java::lang::Object* lookup(::java::lang::Object* arg0);
    virtual int32_t size();

    // Generated
    ObjectOutputStream_ReplaceTable(int32_t arg0, float arg1);
protected:
    ObjectOutputStream_ReplaceTable(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
