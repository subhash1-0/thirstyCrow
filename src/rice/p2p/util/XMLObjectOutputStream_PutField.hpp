// Generated from /pastry-2.1/src/rice/p2p/util/XMLObjectOutputStream.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/p2p/util/fwd-pastry-2.1.hpp>
#include <java/io/ObjectOutputStream_PutField.hpp>

template<typename ComponentType, typename... Bases> struct SubArray;
namespace java
{
    namespace io
    {
typedef ::SubArray< ::java::io::Serializable, ::java::lang::ObjectArray > SerializableArray;
    } // io

    namespace lang
    {
typedef ::SubArray< ::java::lang::CharSequence, ObjectArray > CharSequenceArray;
typedef ::SubArray< ::java::lang::Comparable, ObjectArray > ComparableArray;
typedef ::SubArray< ::java::lang::String, ObjectArray, ::java::io::SerializableArray, ComparableArray, CharSequenceArray > StringArray;
    } // lang
} // java

struct default_init_tag;

class rice::p2p::util::XMLObjectOutputStream_PutField
    : public ::java::io::ObjectOutputStream_PutField
{

public:
    typedef ::java::io::ObjectOutputStream_PutField super;

public: /* protected */
    ::java::util::Hashtable* primitives {  };
    ::java::util::Hashtable* objects {  };
    virtual ::java::lang::StringArray* getPrimitives();
    virtual ::java::lang::StringArray* getObjects();

public:
    void put(::java::lang::String* name, bool value) override;
    void put(::java::lang::String* name, int8_t value) override;
    void put(::java::lang::String* name, char16_t value) override;
    void put(::java::lang::String* name, double value) override;
    void put(::java::lang::String* name, float value) override;
    void put(::java::lang::String* name, int32_t value) override;
    void put(::java::lang::String* name, int64_t value) override;
    void put(::java::lang::String* name, int16_t value) override;
    void put(::java::lang::String* name, ::java::lang::Object* value) override;

private:
    ::java::lang::Object* getPrimitive(::java::lang::String* name);

public: /* protected */
    virtual ::java::lang::Object* getObject(::java::lang::String* name);
    virtual bool getBoolean(::java::lang::String* name);
    virtual int8_t getByte(::java::lang::String* name);
    virtual char16_t getChar(::java::lang::String* name);
    virtual double getDouble(::java::lang::String* name);
    virtual float getFloat(::java::lang::String* name);
    virtual int32_t getInt(::java::lang::String* name);
    virtual int64_t getLong(::java::lang::String* name);
    virtual int16_t getShort(::java::lang::String* name);

public:
    void write(::java::io::ObjectOutput* output) /* throws(IOException) */ override;

    // Generated
    XMLObjectOutputStream_PutField(XMLObjectOutputStream *XMLObjectOutputStream_this);
protected:
    void ctor();
    XMLObjectOutputStream_PutField(XMLObjectOutputStream *XMLObjectOutputStream_this, const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    void init();
    XMLObjectOutputStream *XMLObjectOutputStream_this;
    virtual ::java::lang::Class* getClass0();
    friend class XMLObjectOutputStream;
    friend class XMLObjectOutputStream_Reference;
};
