// Generated from /pastry-2.1/lib/xmlpull_1_1_3_4a.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <org/xmlpull/v1/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct org::xmlpull::v1::XmlSerializer
    : public virtual ::java::lang::Object
{

    virtual XmlSerializer* attribute(::java::lang::String* arg0, ::java::lang::String* arg1, ::java::lang::String* arg2) = 0;
    virtual void cdsect(::java::lang::String* arg0) = 0;
    virtual void comment(::java::lang::String* arg0) = 0;
    virtual void docdecl(::java::lang::String* arg0) = 0;
    virtual void endDocument() = 0;
    virtual XmlSerializer* endTag(::java::lang::String* arg0, ::java::lang::String* arg1) = 0;
    virtual void entityRef(::java::lang::String* arg0) = 0;
    virtual void flush() = 0;
    virtual int32_t getDepth() = 0;
    virtual bool getFeature(::java::lang::String* arg0) = 0;
    virtual ::java::lang::String* getName() = 0;
    virtual ::java::lang::String* getNamespace() = 0;
    virtual ::java::lang::String* getPrefix(::java::lang::String* arg0, bool arg1) = 0;
    virtual ::java::lang::Object* getProperty(::java::lang::String* arg0) = 0;
    virtual void ignorableWhitespace(::java::lang::String* arg0) = 0;
    virtual void processingInstruction(::java::lang::String* arg0) = 0;
    virtual void setFeature(::java::lang::String* arg0, bool arg1) = 0;
    virtual void setOutput(::java::io::Writer* arg0) = 0;
    virtual void setOutput(::java::io::OutputStream* arg0, ::java::lang::String* arg1) = 0;
    virtual void setPrefix(::java::lang::String* arg0, ::java::lang::String* arg1) = 0;
    virtual void setProperty(::java::lang::String* arg0, ::java::lang::Object* arg1) = 0;
    virtual void startDocument(::java::lang::String* arg0, ::java::lang::Boolean* arg1) = 0;
    virtual XmlSerializer* startTag(::java::lang::String* arg0, ::java::lang::String* arg1) = 0;
    virtual XmlSerializer* text(::java::lang::String* arg0) = 0;
    virtual XmlSerializer* text(::char16_tArray* arg0, int32_t arg1, int32_t arg2) = 0;

    // Generated
    static ::java::lang::Class *class_();
};
