// Generated from /pastry-2.1/src/rice/p2p/util/XMLObjectInputStream.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/p2p/util/fwd-pastry-2.1.hpp>
#include <java/io/ObjectInputStream_GetField.hpp>

struct default_init_tag;

class rice::p2p::util::XMLObjectInputStream_GetField
    : public ::java::io::ObjectInputStream_GetField
{

public:
    typedef ::java::io::ObjectInputStream_GetField super;

public: /* protected */
    ::java::util::HashMap* primitives {  };
    ::java::util::HashMap* objects {  };

public:
    bool defaulted(::java::lang::String* name) override;
    bool get(::java::lang::String* name, bool value) override;
    int8_t get(::java::lang::String* name, int8_t value) override;
    char16_t get(::java::lang::String* name, char16_t value) override;
    double get(::java::lang::String* name, double value) override;
    float get(::java::lang::String* name, float value) override;
    int32_t get(::java::lang::String* name, int32_t value) override;
    int64_t get(::java::lang::String* name, int64_t value) override;
    int16_t get(::java::lang::String* name, int16_t value) override;
    ::java::lang::Object* get(::java::lang::String* name, ::java::lang::Object* value) override;

public: /* protected */
    virtual void put(::java::lang::String* name, bool value);
    virtual void put(::java::lang::String* name, int8_t value);
    virtual void put(::java::lang::String* name, char16_t value);
    virtual void put(::java::lang::String* name, double value);
    virtual void put(::java::lang::String* name, float value);
    virtual void put(::java::lang::String* name, int32_t value);
    virtual void put(::java::lang::String* name, int64_t value);
    virtual void put(::java::lang::String* name, int16_t value);
    virtual void put(::java::lang::String* name, ::java::lang::Object* value);

public:
    ::java::io::ObjectStreamClass* getObjectStreamClass() override;

    // Generated
    XMLObjectInputStream_GetField(XMLObjectInputStream *XMLObjectInputStream_this);
protected:
    void ctor();
    XMLObjectInputStream_GetField(XMLObjectInputStream *XMLObjectInputStream_this, const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    void init();
    XMLObjectInputStream *XMLObjectInputStream_this;
    virtual ::java::lang::Class* getClass0();
    friend class XMLObjectInputStream;
    friend class XMLObjectInputStream_ValidationList;
    friend class XMLObjectInputStream_ValidationList_Callback;
};
