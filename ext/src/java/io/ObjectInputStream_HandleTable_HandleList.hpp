// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct default_init_tag;

class java::io::ObjectInputStream_HandleTable_HandleList
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;

private:
    ::int32_tArray* list {  };
    int32_t size_ {  };

protected:
    void ctor();

public:
    virtual void add(int32_t arg0);
    virtual int32_t get(int32_t arg0);
    virtual int32_t size();

    // Generated
    ObjectInputStream_HandleTable_HandleList();
protected:
    ObjectInputStream_HandleTable_HandleList(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
