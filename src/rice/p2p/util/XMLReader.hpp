// Generated from /pastry-2.1/src/rice/p2p/util/XMLReader.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <org/xmlpull/v1/fwd-pastry-2.1.hpp>
#include <rice/p2p/util/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct default_init_tag;

class rice::p2p::util::XMLReader
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;

public: /* protected */
    ::java::io::Reader* in {  };
    ::org::xmlpull::v1::XmlPullParser* xpp {  };
    int32_t eventType {  };
protected:
    void ctor(::java::io::Reader* in) /* throws(IOException) */;

public:
    virtual void close() /* throws(IOException) */;
    virtual ::int8_tArray* readBase64() /* throws(IOException) */;
    virtual void readHeader() /* throws(IOException) */;

public: /* protected */
    virtual void assertEvent(int32_t type) /* throws(IOException) */;

public:
    virtual void assertStartTag() /* throws(IOException) */;
    virtual void assertEndTag() /* throws(IOException) */;
    virtual void assertStartTag(::java::lang::String* name) /* throws(IOException) */;
    virtual void assertEndTag(::java::lang::String* name) /* throws(IOException) */;
    virtual void readStartTag() /* throws(IOException) */;
    virtual void readEndTag() /* throws(IOException) */;
    virtual void readStartTag(::java::lang::String* name) /* throws(IOException) */;
    virtual void readEndTag(::java::lang::String* name) /* throws(IOException) */;
    virtual void assertAttribute(::java::lang::String* name, ::java::lang::String* value) /* throws(IOException) */;
    virtual void step() /* throws(IOException) */;
    virtual bool isStartDocument();
    virtual bool isEndDocument();
    virtual bool isStartTag();
    virtual bool isEndTag();
    virtual bool isText();
    virtual ::java::lang::String* getAttribute(::java::lang::String* name) /* throws(IOException) */;
    virtual ::java::lang::String* getStartTag() /* throws(IOException) */;
    virtual ::java::lang::String* getEndTag() /* throws(IOException) */;

    // Generated
    XMLReader(::java::io::Reader* in);
protected:
    XMLReader(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
