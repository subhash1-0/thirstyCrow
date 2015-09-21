// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/io/ObjectStreamException.hpp>

struct default_init_tag;

class java::io::NotSerializableException
    : public ObjectStreamException
{

public:
    typedef ObjectStreamException super;

private:
    static constexpr int64_t serialVersionUID { int64_t(2906642554793891381LL) };

protected:
    void ctor();
    void ctor(::java::lang::String* arg0);

    // Generated

public:
    NotSerializableException();
    NotSerializableException(::java::lang::String* arg0);
protected:
    NotSerializableException(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
