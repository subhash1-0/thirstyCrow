// Generated from /pastry-2.1/src/rice/pastry/messaging/PastryObjectInputStream.java

#pragma once

#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/messaging/fwd-pastry-2.1.hpp>
#include <java/io/ObjectInputStream.hpp>

struct default_init_tag;

class rice::pastry::messaging::PastryObjectInputStream
    : public ::java::io::ObjectInputStream
{

public:
    typedef ::java::io::ObjectInputStream super;

public: /* protected */
    ::rice::pastry::PastryNode* node {  };
protected:
    void ctor(::java::io::InputStream* stream, ::rice::pastry::PastryNode* node) /* throws(IOException) */;

public: /* protected */
    ::java::lang::Object* resolveObject(::java::lang::Object* input) /* throws(IOException) */ override;

    // Generated

public:
    PastryObjectInputStream(::java::io::InputStream* stream, ::rice::pastry::PastryNode* node);
protected:
    PastryObjectInputStream(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
