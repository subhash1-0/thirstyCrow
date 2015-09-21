// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct default_init_tag;

class java::lang::Class_EnclosingMethodInfo final
    : public Object
{

public:
    typedef Object super;

private:
    static bool $assertionsDisabled_;
    String* descriptor {  };
    Class* enclosingClass {  };
    String* name {  };

    /*void ctor(ObjectArray* arg0); (private) */

public: /* package */
    String* getDescriptor();
    Class* getEnclosingClass();
    String* getName();
    bool isConstructor();
    bool isMethod();
    bool isPartial();

    // Generated

public:
    Class_EnclosingMethodInfo();
protected:
    Class_EnclosingMethodInfo(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

public: /* package */
    static bool& $assertionsDisabled();

private:
    virtual ::java::lang::Class* getClass0();
};
