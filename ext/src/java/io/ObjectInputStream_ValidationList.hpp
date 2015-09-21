// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct default_init_tag;

class java::io::ObjectInputStream_ValidationList
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;

private:
    ObjectInputStream_ValidationList_Callback* list {  };

protected:
    void ctor();

public:
    virtual void clear();

public: /* package */
    virtual void doCallbacks();
    virtual void register_(ObjectInputValidation* arg0, int32_t arg1);

    // Generated
    ObjectInputStream_ValidationList();
protected:
    ObjectInputStream_ValidationList(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
