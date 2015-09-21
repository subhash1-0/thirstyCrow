// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/table/UnknownValueException.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/table/fwd-pastry-2.1.hpp>
#include <java/lang/Exception.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::table::UnknownValueException
    : public ::java::lang::Exception
{

public:
    typedef ::java::lang::Exception super;

public: /* package */
    ::java::lang::Object* source {  };
    ::java::lang::Object* key {  };
protected:
    void ctor(::java::lang::Object* source, ::java::lang::Object* key);

public:
    virtual ::java::lang::Object* getSource();
    virtual ::java::lang::Object* getKey();

    // Generated
    UnknownValueException(::java::lang::Object* source, ::java::lang::Object* key);
protected:
    UnknownValueException(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
