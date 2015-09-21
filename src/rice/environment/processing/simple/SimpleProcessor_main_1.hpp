// Generated from /pastry-2.1/src/rice/environment/processing/simple/SimpleProcessor.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/environment/processing/simple/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/Executable.hpp>

struct default_init_tag;

class rice::environment::processing::simple::SimpleProcessor_main_1
    : public virtual ::java::lang::Object
    , public virtual ::rice::Executable
{

public:
    typedef ::java::lang::Object super;
    ::java::lang::Object* execute() override;

    // Generated
    SimpleProcessor_main_1();
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
    friend class SimpleProcessor;
    friend class SimpleProcessor_main_2;
    friend class SimpleProcessor_main_3;
    friend class SimpleProcessor_main_4;
};
