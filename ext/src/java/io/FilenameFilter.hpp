// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct java::io::FilenameFilter
    : public virtual ::java::lang::Object
{

    virtual bool accept(File* arg0, ::java::lang::String* arg1) = 0;

    // Generated
    static ::java::lang::Class *class_();
};
