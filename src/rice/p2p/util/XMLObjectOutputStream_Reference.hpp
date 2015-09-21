// Generated from /pastry-2.1/src/rice/p2p/util/XMLObjectOutputStream.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/p2p/util/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct default_init_tag;

class rice::p2p::util::XMLObjectOutputStream_Reference
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;

private:
    ::java::lang::Object* object {  };
protected:
    void ctor(::java::lang::Object* object);

public:
    int32_t hashCode() override;
    bool equals(::java::lang::Object* o) override;

    // Generated
    XMLObjectOutputStream_Reference(XMLObjectOutputStream *XMLObjectOutputStream_this, ::java::lang::Object* object);
protected:
    XMLObjectOutputStream_Reference(XMLObjectOutputStream *XMLObjectOutputStream_this, const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    XMLObjectOutputStream *XMLObjectOutputStream_this;

private:
    virtual ::java::lang::Class* getClass0();
    friend class XMLObjectOutputStream;
    friend class XMLObjectOutputStream_PutField;
};
