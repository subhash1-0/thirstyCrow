// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct default_init_tag;

class java::io::ObjectOutputStream_DebugTraceInfoStack
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;

private:
    ::java::util::List* stack {  };

protected:
    void ctor();

public: /* package */
    virtual void clear();
    virtual void pop();
    virtual void push(::java::lang::String* arg0);

public:
    ::java::lang::String* toString() override;

    // Generated

public: /* package */
    ObjectOutputStream_DebugTraceInfoStack();
protected:
    ObjectOutputStream_DebugTraceInfoStack(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
