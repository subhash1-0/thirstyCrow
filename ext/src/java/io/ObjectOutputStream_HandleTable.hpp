// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct default_init_tag;

class java::io::ObjectOutputStream_HandleTable
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;

private:
    float loadFactor {  };
    ::int32_tArray* next {  };
    ::java::lang::ObjectArray* objs {  };
    int32_t size_ {  };
    ::int32_tArray* spine {  };
    int32_t threshold {  };

protected:
    void ctor(int32_t arg0, float arg1);

public: /* package */
    virtual int32_t assign(::java::lang::Object* arg0);
    virtual void clear();
    /*void growEntries(); (private) */
    /*void growSpine(); (private) */
    /*int32_t hash(::java::lang::Object* arg0); (private) */
    /*void insert(::java::lang::Object* arg0, int32_t arg1); (private) */
    virtual int32_t lookup(::java::lang::Object* arg0);
    virtual int32_t size();

    // Generated
    ObjectOutputStream_HandleTable(int32_t arg0, float arg1);
protected:
    ObjectOutputStream_HandleTable(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
