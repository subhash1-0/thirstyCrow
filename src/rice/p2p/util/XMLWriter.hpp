// Generated from /pastry-2.1/src/rice/p2p/util/XMLWriter.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <org/xmlpull/v1/fwd-pastry-2.1.hpp>
#include <rice/p2p/util/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct default_init_tag;

class rice::p2p::util::XMLWriter
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;

public: /* protected */
    ::org::xmlpull::v1::XmlSerializer* serializer {  };
    ::java::io::Writer* writer {  };
protected:
    void ctor(::java::io::OutputStream* out) /* throws(IOException) */;

public:
    virtual void flush() /* throws(IOException) */;
    virtual void close() /* throws(IOException) */;
    virtual void writeBase64(::int8_tArray* bytes, int32_t off, int32_t len) /* throws(IOException) */;
    virtual void writeHeader() /* throws(IOException) */;
    virtual void attribute(::java::lang::String* name, int32_t value) /* throws(IOException) */;
    virtual void attribute(::java::lang::String* name, double value) /* throws(IOException) */;
    virtual void attribute(::java::lang::String* name, float value) /* throws(IOException) */;
    virtual void attribute(::java::lang::String* name, int64_t value) /* throws(IOException) */;
    virtual void attribute(::java::lang::String* name, char16_t value) /* throws(IOException) */;
    virtual void attribute(::java::lang::String* name, bool value) /* throws(IOException) */;
    virtual void attribute(::java::lang::String* name, ::java::lang::Object* value) /* throws(IOException) */;

public: /* protected */
    virtual void attribute(::java::lang::String* name, ::java::lang::String* value) /* throws(IOException) */;

public:
    virtual void start(::java::lang::String* name) /* throws(IOException) */;
    virtual void end(::java::lang::String* name) /* throws(IOException) */;

    // Generated
    XMLWriter(::java::io::OutputStream* out);
protected:
    XMLWriter(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
