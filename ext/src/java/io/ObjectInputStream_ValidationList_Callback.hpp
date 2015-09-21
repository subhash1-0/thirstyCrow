// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/security/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct default_init_tag;

class java::io::ObjectInputStream_ValidationList_Callback
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    ::java::security::AccessControlContext* acc {  };
    ObjectInputStream_ValidationList_Callback* next {  };
    ObjectInputValidation* obj {  };
    int32_t priority {  };

protected:
    void ctor(ObjectInputValidation* arg0, int32_t arg1, ObjectInputStream_ValidationList_Callback* arg2, ::java::security::AccessControlContext* arg3);

    // Generated

public: /* package */
    ObjectInputStream_ValidationList_Callback(ObjectInputValidation* arg0, int32_t arg1, ObjectInputStream_ValidationList_Callback* arg2, ::java::security::AccessControlContext* arg3);
protected:
    ObjectInputStream_ValidationList_Callback(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
