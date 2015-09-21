// Generated from /pastry-2.1/src/rice/p2p/util/XMLObjectInputStream.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <rice/p2p/util/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct default_init_tag;

class rice::p2p::util::XMLObjectInputStream_ValidationList_Callback
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    ::java::io::ObjectInputValidation* obj {  };
    int32_t priority {  };
    XMLObjectInputStream_ValidationList_Callback* next {  };
protected:
    void ctor(::java::io::ObjectInputValidation* obj, int32_t priority, XMLObjectInputStream_ValidationList_Callback* next);

    // Generated

public: /* package */
    XMLObjectInputStream_ValidationList_Callback(::java::io::ObjectInputValidation* obj, int32_t priority, XMLObjectInputStream_ValidationList_Callback* next);
protected:
    XMLObjectInputStream_ValidationList_Callback(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
    friend class XMLObjectInputStream;
    friend class XMLObjectInputStream_GetField;
    friend class XMLObjectInputStream_ValidationList;
};
