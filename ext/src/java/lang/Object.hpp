// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>

struct default_init_tag;

class java::lang::Object
{

protected:
    void ctor();

public: /* protected */
    virtual Object* clone();

public:
    virtual bool equals(Object* arg0);

public: /* protected */
    virtual void finalize();

public:
    Class* getClass();
    virtual int32_t hashCode();
    void notify();
    void notifyAll();
    /*static void registerNatives(); (private) */
    virtual String* toString();
    void wait();
    void wait(int64_t arg0);
    void wait(int64_t arg0, int32_t arg1);

    // Generated
    Object();
protected:
    Object(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    static void clinit();
    virtual ~Object();

private:
    virtual ::java::lang::Class* getClass0();
};
