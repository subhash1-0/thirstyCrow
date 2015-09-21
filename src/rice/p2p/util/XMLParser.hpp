// Generated from /pastry-2.1/src/rice/p2p/util/XMLParser.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/p2p/util/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/xmlpull/v1/XmlPullParser.hpp>

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
typedef ::SubArray< ::java::lang::Cloneable, ObjectArray > CloneableArray;
typedef ::SubArray< ::java::lang::Comparable, ObjectArray > ComparableArray;
typedef ::SubArray< ::java::lang::String, ObjectArray, ::java::io::SerializableArray, ComparableArray, CharSequenceArray > StringArray;
typedef ::SubArray< ::java::lang::StringArray, CloneableArray, ::java::io::SerializableArray > StringArrayArray;
    } // lang
} // java

struct default_init_tag;

class rice::p2p::util::XMLParser
    : public virtual ::java::lang::Object
    , public virtual ::org::xmlpull::v1::XmlPullParser
{

public:
    typedef ::java::lang::Object super;
    static constexpr int32_t BUFFER_SIZE { int32_t(32000) };
    static constexpr int32_t MAX_ATTRIBUTES { int32_t(100) };

private:
    static ::char16_tArray* QUOTE_;
    static ::char16_tArray* TAG_END_;
    static ::char16_tArray* WHITESPACE_;
    static ::char16_tArray* WHITESPACE_OR_TAG_END_;
    static ::char16_tArray* WHITESPACE_OR_EQUALS_;
    static ::char16_tArray* SINGLE_;
    static ::java::lang::StringArrayArray* ENTITIES_;

public: /* protected */
    ::java::io::Reader* reader {  };
    ::char16_tArray* buffer {  };
    int32_t bufferPosition {  };
    int32_t bufferLimit {  };
    StringCache* cache {  };
    ::java::util::Stack* tags {  };
    ::java::lang::String* name {  };
    ::java::lang::String* text {  };
    ::java::lang::StringArray* attributeKeys {  };
    ::java::lang::StringArray* attributeValues {  };
    int32_t numAttributes {  };
    bool inTag {  };
    int32_t mark_ {  };
    XMLParser_CharArrayBuffer* marked {  };
protected:
    void ctor();

public:
    void setInput(::java::io::Reader* in) /* throws(XmlPullParserException) */ override;
    ::java::lang::String* getText() override;
    ::java::lang::String* getName() override;
    ::java::lang::String* getAttributeValue(::java::lang::String* namespace_, ::java::lang::String* name) override;
    int32_t getEventType() /* throws(XmlPullParserException) */ override;
    int32_t next() /* throws(XmlPullParserException, IOException) */ override;
    bool isWhitespace() /* throws(XmlPullParserException) */ override;

public: /* protected */
    virtual void fillBuffer() /* throws(IOException) */;
    virtual char16_t current() /* throws(IOException) */;
    virtual void step();
    virtual void mark();
    virtual ::java::lang::String* unmark();
    virtual void clearAttributes();
    virtual void addAttribute(::java::lang::String* key, ::java::lang::String* value);
    virtual void expect(char16_t c) /* throws(XmlPullParserException, IOException) */;

public:
    virtual bool isWhitespace(::java::lang::String* text);

public: /* protected */
    virtual bool contains(::char16_tArray* chars, char16_t c);
    virtual ::java::lang::String* parseUntil(::char16_tArray* chars) /* throws(IOException) */;
    virtual ::java::lang::String* parseUntil(char16_t c) /* throws(IOException) */;
    virtual void parseUntilNot(::char16_tArray* chars) /* throws(IOException) */;
    virtual int32_t parseEndTag(::java::lang::String* tag) /* throws(XmlPullParserException, IOException) */;
    virtual int32_t parseTag() /* throws(XmlPullParserException, IOException) */;
    virtual int32_t parseEndTag() /* throws(XmlPullParserException, IOException) */;
    virtual int32_t parseStartTag() /* throws(XmlPullParserException, IOException) */;
    virtual int32_t parseDocumentTag() /* throws(XmlPullParserException, IOException) */;
    virtual void parseAttributes() /* throws(XmlPullParserException, IOException) */;
    virtual int32_t parseText() /* throws(XmlPullParserException, IOException) */;
    virtual ::java::lang::String* convert(::java::lang::String* string);

public:
    void setFeature(::java::lang::String* name, bool state) /* throws(XmlPullParserException) */ override;
    bool getFeature(::java::lang::String* name) override;
    void setProperty(::java::lang::String* name, ::java::lang::Object* value) /* throws(XmlPullParserException) */ override;
    ::java::lang::Object* getProperty(::java::lang::String* name) override;
    void setInput(::java::io::InputStream* inputStream, ::java::lang::String* inputEncoding) /* throws(XmlPullParserException) */ override;
    ::java::lang::String* getInputEncoding() override;
    void defineEntityReplacementText(::java::lang::String* entityName, ::java::lang::String* replacementText) /* throws(XmlPullParserException) */ override;
    int32_t getNamespaceCount(int32_t depth) /* throws(XmlPullParserException) */ override;
    ::java::lang::String* getNamespacePrefix(int32_t pos) /* throws(XmlPullParserException) */ override;
    ::java::lang::String* getNamespaceUri(int32_t pos) /* throws(XmlPullParserException) */ override;
    ::java::lang::String* getNamespace(::java::lang::String* prefix) override;
    int32_t getDepth() override;
    ::java::lang::String* getPositionDescription() override;
    int32_t getLineNumber() override;
    int32_t getColumnNumber() override;
    ::char16_tArray* getTextCharacters(::int32_tArray* holderForStartAndLength) override;
    ::java::lang::String* getNamespace() override;
    ::java::lang::String* getPrefix() override;
    bool isEmptyElementTag() /* throws(XmlPullParserException) */ override;
    ::java::lang::String* getAttributeNamespace(int32_t index) override;
    ::java::lang::String* getAttributePrefix(int32_t index) override;
    ::java::lang::String* getAttributeType(int32_t index) override;
    bool isAttributeDefault(int32_t index) override;
    int32_t nextToken() /* throws(XmlPullParserException, IOException) */ override;
    void require(int32_t type, ::java::lang::String* namespace_, ::java::lang::String* name) /* throws(XmlPullParserException, IOException) */ override;
    ::java::lang::String* nextText() /* throws(XmlPullParserException, IOException) */ override;
    int32_t nextTag() /* throws(XmlPullParserException, IOException) */ override;
    int32_t getAttributeCount() override;
    ::java::lang::String* getAttributeName(int32_t index) override;
    ::java::lang::String* getAttributeValue(int32_t index) override;

    // Generated
    XMLParser();
protected:
    XMLParser(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    static void clinit();

private:
    void init();

public:
    static ::char16_tArray*& QUOTE();
    static ::char16_tArray*& TAG_END();
    static ::char16_tArray*& WHITESPACE();
    static ::char16_tArray*& WHITESPACE_OR_TAG_END();
    static ::char16_tArray*& WHITESPACE_OR_EQUALS();
    static ::char16_tArray*& SINGLE();
    static ::java::lang::StringArrayArray*& ENTITIES();

private:
    virtual ::java::lang::Class* getClass0();
    friend class XMLParser_CharArrayBuffer;
};
