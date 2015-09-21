// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <java/io/fwd-pastry-2.1.hpp>
#include <java/io/Serializable.hpp>

struct java::io::Externalizable
    : public virtual Serializable
{

    virtual void readExternal(ObjectInput* arg0) = 0;
    virtual void writeExternal(ObjectOutput* arg0) = 0;

    // Generated
    static ::java::lang::Class *class_();
};
