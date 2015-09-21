// Generated from /pastry-2.1/lib/xmlpull_1_1_3_4a.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <org/xmlpull/v1/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

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

struct org::xmlpull::v1::XmlPullParser
    : public virtual ::java::lang::Object
{
    static constexpr int32_t CDSECT { int32_t(5) };
    static constexpr int32_t COMMENT { int32_t(9) };
    static constexpr int32_t DOCDECL { int32_t(10) };
    static constexpr int32_t END_DOCUMENT { int32_t(1) };
    static constexpr int32_t END_TAG { int32_t(3) };
    static constexpr int32_t ENTITY_REF { int32_t(6) };

private:
    static ::java::lang::String* FEATURE_PROCESS_DOCDECL_;
    static ::java::lang::String* FEATURE_PROCESS_NAMESPACES_;
    static ::java::lang::String* FEATURE_REPORT_NAMESPACE_ATTRIBUTES_;
    static ::java::lang::String* FEATURE_VALIDATION_;

public:
    static constexpr int32_t IGNORABLE_WHITESPACE { int32_t(7) };

private:
    static ::java::lang::String* NO_NAMESPACE_;

public:
    static constexpr int32_t PROCESSING_INSTRUCTION { int32_t(8) };
    static constexpr int32_t START_DOCUMENT { int32_t(0) };
    static constexpr int32_t START_TAG { int32_t(2) };
    static constexpr int32_t TEXT { int32_t(4) };

private:
    static ::java::lang::StringArray* TYPES_;


public:
    virtual void defineEntityReplacementText(::java::lang::String* arg0, ::java::lang::String* arg1) = 0;
    virtual int32_t getAttributeCount() = 0;
    virtual ::java::lang::String* getAttributeName(int32_t arg0) = 0;
    virtual ::java::lang::String* getAttributeNamespace(int32_t arg0) = 0;
    virtual ::java::lang::String* getAttributePrefix(int32_t arg0) = 0;
    virtual ::java::lang::String* getAttributeType(int32_t arg0) = 0;
    virtual ::java::lang::String* getAttributeValue(int32_t arg0) = 0;
    virtual ::java::lang::String* getAttributeValue(::java::lang::String* arg0, ::java::lang::String* arg1) = 0;
    virtual int32_t getColumnNumber() = 0;
    virtual int32_t getDepth() = 0;
    virtual int32_t getEventType() = 0;
    virtual bool getFeature(::java::lang::String* arg0) = 0;
    virtual ::java::lang::String* getInputEncoding() = 0;
    virtual int32_t getLineNumber() = 0;
    virtual ::java::lang::String* getName() = 0;
    virtual ::java::lang::String* getNamespace() = 0;
    virtual ::java::lang::String* getNamespace(::java::lang::String* arg0) = 0;
    virtual int32_t getNamespaceCount(int32_t arg0) = 0;
    virtual ::java::lang::String* getNamespacePrefix(int32_t arg0) = 0;
    virtual ::java::lang::String* getNamespaceUri(int32_t arg0) = 0;
    virtual ::java::lang::String* getPositionDescription() = 0;
    virtual ::java::lang::String* getPrefix() = 0;
    virtual ::java::lang::Object* getProperty(::java::lang::String* arg0) = 0;
    virtual ::java::lang::String* getText() = 0;
    virtual ::char16_tArray* getTextCharacters(::int32_tArray* arg0) = 0;
    virtual bool isAttributeDefault(int32_t arg0) = 0;
    virtual bool isEmptyElementTag() = 0;
    virtual bool isWhitespace() = 0;
    virtual int32_t next() = 0;
    virtual int32_t nextTag() = 0;
    virtual ::java::lang::String* nextText() = 0;
    virtual int32_t nextToken() = 0;
    virtual void require(int32_t arg0, ::java::lang::String* arg1, ::java::lang::String* arg2) = 0;
    virtual void setFeature(::java::lang::String* arg0, bool arg1) = 0;
    virtual void setInput(::java::io::Reader* arg0) = 0;
    virtual void setInput(::java::io::InputStream* arg0, ::java::lang::String* arg1) = 0;
    virtual void setProperty(::java::lang::String* arg0, ::java::lang::Object* arg1) = 0;

    // Generated
    static ::java::lang::Class *class_();
    static ::java::lang::String*& FEATURE_PROCESS_DOCDECL();
    static ::java::lang::String*& FEATURE_PROCESS_NAMESPACES();
    static ::java::lang::String*& FEATURE_REPORT_NAMESPACE_ATTRIBUTES();
    static ::java::lang::String*& FEATURE_VALIDATION();
    static ::java::lang::String*& NO_NAMESPACE();
    static ::java::lang::StringArray*& TYPES();
};
