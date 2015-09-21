// Generated from /pastry-2.1/src/rice/p2p/util/XMLParser.java
#include <rice/p2p/util/XMLParser.hpp>

#include <java/io/EOFException.hpp>
#include <java/io/Reader.hpp>
#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/CharSequence.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Cloneable.hpp>
#include <java/lang/Comparable.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/RuntimeException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/UnsupportedOperationException.hpp>
#include <java/util/Stack.hpp>
#include <org/xmlpull/v1/XmlPullParserException.hpp>
#include <rice/p2p/util/StringCache.hpp>
#include <rice/p2p/util/XMLParser_CharArrayBuffer.hpp>
#include <Array.hpp>
#include <SubArray.hpp>
#include <ObjectArray.hpp>

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

template<typename T, typename U>
static T java_cast(U* u)
{
    if(!u) return static_cast<T>(nullptr);
    auto t = dynamic_cast<T>(u);
    if(!t) throw new ::java::lang::ClassCastException();
    return t;
}

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

namespace
{
    template<typename F>
    struct finally_
    {
        finally_(F f) : f(f), moved(false) { }
        finally_(finally_ &&x) : f(x.f), moved(false) { x.moved = true; }
        ~finally_() { if(!moved) f(); }
    private:
        finally_(const finally_&); finally_& operator=(const finally_&);
        F f;
        bool moved;
    };

    template<typename F> finally_<F> finally(F f) { return finally_<F>(f); }
}
rice::p2p::util::XMLParser::XMLParser(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::util::XMLParser::XMLParser() 
    : XMLParser(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

void rice::p2p::util::XMLParser::init()
{
    attributeKeys = new ::java::lang::StringArray(MAX_ATTRIBUTES);
    attributeValues = new ::java::lang::StringArray(MAX_ATTRIBUTES);
}

constexpr int32_t rice::p2p::util::XMLParser::BUFFER_SIZE;

constexpr int32_t rice::p2p::util::XMLParser::MAX_ATTRIBUTES;

char16_tArray*& rice::p2p::util::XMLParser::QUOTE()
{
    clinit();
    return QUOTE_;
}
char16_tArray* rice::p2p::util::XMLParser::QUOTE_;

char16_tArray*& rice::p2p::util::XMLParser::TAG_END()
{
    clinit();
    return TAG_END_;
}
char16_tArray* rice::p2p::util::XMLParser::TAG_END_;

char16_tArray*& rice::p2p::util::XMLParser::WHITESPACE()
{
    clinit();
    return WHITESPACE_;
}
char16_tArray* rice::p2p::util::XMLParser::WHITESPACE_;

char16_tArray*& rice::p2p::util::XMLParser::WHITESPACE_OR_TAG_END()
{
    clinit();
    return WHITESPACE_OR_TAG_END_;
}
char16_tArray* rice::p2p::util::XMLParser::WHITESPACE_OR_TAG_END_;

char16_tArray*& rice::p2p::util::XMLParser::WHITESPACE_OR_EQUALS()
{
    clinit();
    return WHITESPACE_OR_EQUALS_;
}
char16_tArray* rice::p2p::util::XMLParser::WHITESPACE_OR_EQUALS_;

char16_tArray*& rice::p2p::util::XMLParser::SINGLE()
{
    clinit();
    return SINGLE_;
}
char16_tArray* rice::p2p::util::XMLParser::SINGLE_;

java::lang::StringArrayArray*& rice::p2p::util::XMLParser::ENTITIES()
{
    clinit();
    return ENTITIES_;
}
java::lang::StringArrayArray* rice::p2p::util::XMLParser::ENTITIES_;

void rice::p2p::util::XMLParser::ctor()
{
    super::ctor();
    init();
    this->buffer = new ::char16_tArray(BUFFER_SIZE);
    this->bufferPosition = 0;
    this->bufferLimit = 0;
    this->mark_ = -int32_t(1);
    this->tags = new ::java::util::Stack();
    this->cache = new StringCache();
    this->inTag = false;
    this->numAttributes = 0;
}

void rice::p2p::util::XMLParser::setInput(::java::io::Reader* in) /* throws(XmlPullParserException) */
{
    this->reader = in;
}

java::lang::String* rice::p2p::util::XMLParser::getText()
{
    return this->text;
}

java::lang::String* rice::p2p::util::XMLParser::getName()
{
    return this->name;
}

java::lang::String* rice::p2p::util::XMLParser::getAttributeValue(::java::lang::String* namespace_, ::java::lang::String* name)
{
    for (auto i = int32_t(0); i < numAttributes; i++) 
                if(npc((*attributeKeys)[i])->equals(static_cast< ::java::lang::Object* >(name)))
            return (*attributeValues)[i];


    return nullptr;
}

int32_t rice::p2p::util::XMLParser::getEventType() /* throws(XmlPullParserException) */
{
    return 0;
}

int32_t rice::p2p::util::XMLParser::next() /* throws(XmlPullParserException, IOException) */
{
    char16_t next = int32_t(0);
    try {
        next = current();
    } catch (::java::io::EOFException* e) {
        return END_DOCUMENT;
    }
    {
        int32_t result;
        switch (next) {
        case u'<':
            result = parseTag();
            if(result == START_DOCUMENT)
                return this->next();
            else
                return result;
        case u'/':
            if(this->inTag)
                return parseEndTag(java_cast< ::java::lang::String* >(java_cast< ::java::lang::Object* >(npc(tags)->pop())));
            else
                return parseText();
        default:
            return parseText();
        }
    }

}

bool rice::p2p::util::XMLParser::isWhitespace() /* throws(XmlPullParserException) */
{
    return isWhitespace(text);
}

void rice::p2p::util::XMLParser::fillBuffer() /* throws(IOException) */
{
    if(marked != nullptr)
        npc(this->marked)->append(buffer, 0, bufferPosition);
    else if(mark_ != -int32_t(1))
        this->marked = new XMLParser_CharArrayBuffer(this, buffer, mark_, bufferPosition - mark_);

    auto read = npc(reader)->read(buffer);
    if(read > 0) {
        bufferLimit = read;
        bufferPosition = 0;
    }
}

char16_t rice::p2p::util::XMLParser::current() /* throws(IOException) */
{
    if(bufferPosition == bufferLimit)
        fillBuffer();

    if(bufferPosition == bufferLimit)
        throw new ::java::io::EOFException();

    return (*buffer)[bufferPosition];
}

void rice::p2p::util::XMLParser::step()
{
    bufferPosition++;
}

void rice::p2p::util::XMLParser::mark()
{
    this->mark_ = bufferPosition;
}

java::lang::String* rice::p2p::util::XMLParser::unmark()
{
    {
        auto finally0 = finally([&] {
            this->mark_ = -int32_t(1);
            this->marked = nullptr;
        });
        {
            if(this->marked != nullptr) {
                npc(this->marked)->append(buffer, 0, bufferPosition);
                return npc(cache)->get(npc(marked)->getBuffer(), 0, npc(marked)->getLength());
            } else {
                return npc(cache)->get(buffer, mark_, bufferPosition - mark_);
            }
        }
    }

}

void rice::p2p::util::XMLParser::clearAttributes()
{
    this->numAttributes = 0;
}

void rice::p2p::util::XMLParser::addAttribute(::java::lang::String* key, ::java::lang::String* value)
{
    if(numAttributes == npc(attributeKeys)->length)
        throw new ::java::lang::RuntimeException(::java::lang::StringBuilder().append(u"More than "_j)->append(npc(attributeKeys)->length)
            ->append(u" attributes encountered - unsupported!"_j)->toString());

    attributeKeys->set(numAttributes, key);
    attributeValues->set(numAttributes, value);
    numAttributes++;
}

void rice::p2p::util::XMLParser::expect(char16_t c) /* throws(XmlPullParserException, IOException) */
{
    if(current() != c)
        throw new ::org::xmlpull::v1::XmlPullParserException(::java::lang::StringBuilder().append(u"Expected character '"_j)->append(c)
            ->append(u"' got '"_j)
            ->append(current())
            ->append(u"'"_j)->toString());
    else
        step();
}

bool rice::p2p::util::XMLParser::isWhitespace(::java::lang::String* text)
{
    for (auto i = int32_t(0); i < npc(text)->length(); i++) 
                if(!contains(WHITESPACE_, npc(text)->charAt(i)))
            return false;


    return true;
}

bool rice::p2p::util::XMLParser::contains(::char16_tArray* chars, char16_t c)
{
    for (auto i = int32_t(0); i < npc(chars)->length; i++) 
                if((*chars)[i] == c)
            return true;


    return false;
}

java::lang::String* rice::p2p::util::XMLParser::parseUntil(::char16_tArray* chars) /* throws(IOException) */
{
    mark();
    while (true) {
        if(contains(chars, current()))
            break;
        else
            step();
    }
    return unmark();
}

java::lang::String* rice::p2p::util::XMLParser::parseUntil(char16_t c) /* throws(IOException) */
{
    mark();
    while (true) {
        if(current() == c)
            break;
        else
            step();
    }
    return unmark();
}

void rice::p2p::util::XMLParser::parseUntilNot(::char16_tArray* chars) /* throws(IOException) */
{
    while (true) {
        if(!contains(chars, current()))
            break;
        else
            step();
    }
}

int32_t rice::p2p::util::XMLParser::parseEndTag(::java::lang::String* tag) /* throws(XmlPullParserException, IOException) */
{
    expect(u'/');
    expect(u'>');
    this->name = tag;
    this->inTag = false;
    return END_TAG;
}

int32_t rice::p2p::util::XMLParser::parseTag() /* throws(XmlPullParserException, IOException) */
{
    expect(u'<');
    switch (current()) {
    case u'/':
        return parseEndTag();
    case u'?':
        return parseDocumentTag();
    default:
        return parseStartTag();
    }

}

int32_t rice::p2p::util::XMLParser::parseEndTag() /* throws(XmlPullParserException, IOException) */
{
    expect(u'/');
    parseUntilNot(WHITESPACE_);
    clearAttributes();
    this->name = parseUntil(WHITESPACE_OR_TAG_END_);
    npc(tags)->pop();
    this->inTag = false;
    parseUntilNot(WHITESPACE_);
    expect(u'>');
    return END_TAG;
}

int32_t rice::p2p::util::XMLParser::parseStartTag() /* throws(XmlPullParserException, IOException) */
{
    parseUntilNot(WHITESPACE_);
    this->name = parseUntil(WHITESPACE_OR_TAG_END_);
    npc(tags)->push(this->name);
    parseUntilNot(WHITESPACE_);
    parseAttributes();
    parseUntilNot(WHITESPACE_);
    if(current() != u'/') {
        expect(u'>');
        this->inTag = false;
    } else {
        this->inTag = true;
    }
    return START_TAG;
}

int32_t rice::p2p::util::XMLParser::parseDocumentTag() /* throws(XmlPullParserException, IOException) */
{
    expect(u'?');
    parseUntilNot(WHITESPACE_);
    auto type = parseUntil(WHITESPACE_OR_TAG_END_);
    if(!(npc(npc(type)->toLowerCase())->equals(static_cast< ::java::lang::Object* >(u"xml"_j))))
        throw new ::org::xmlpull::v1::XmlPullParserException(::java::lang::StringBuilder().append(u"This does not appear to be an XML document - found '"_j)->append(type)
            ->append(u"'!"_j)->toString());

    parseUntilNot(WHITESPACE_);
    parseAttributes();
    clearAttributes();
    parseUntilNot(WHITESPACE_);
    this->inTag = false;
    expect(u'?');
    expect(u'>');
    return START_DOCUMENT;
}

void rice::p2p::util::XMLParser::parseAttributes() /* throws(XmlPullParserException, IOException) */
{
    clearAttributes();
    while (true) {
        parseUntilNot(WHITESPACE_);
        if(contains(TAG_END_, current())) {
            return;
        } else {
            auto key = parseUntil(WHITESPACE_OR_EQUALS_);
            parseUntilNot(WHITESPACE_);
            expect(u'=');
            parseUntilNot(WHITESPACE_);
            ::java::lang::String* value = nullptr;
            auto quote = current();
            if(contains(QUOTE_, quote)) {
                expect(quote);
                value = convert(parseUntil(quote));
                expect(quote);
            } else {
                value = convert(parseUntil(WHITESPACE_OR_TAG_END_));
            }
            addAttribute(key, value);
        }
    }
}

int32_t rice::p2p::util::XMLParser::parseText() /* throws(XmlPullParserException, IOException) */
{
    clearAttributes();
    this->text = convert(parseUntil(u'<'));
    this->inTag = false;
    return TEXT;
}

java::lang::String* rice::p2p::util::XMLParser::convert(::java::lang::String* string)
{
    if(npc(string)->indexOf(static_cast< int32_t >(u'&')) < 0)
        return string;

    for (auto i = int32_t(0); i < npc(ENTITIES_)->length; i++) 
                string = npc(string)->replaceAll((*(*ENTITIES_)[i])[int32_t(0)], (*(*ENTITIES_)[i])[int32_t(1)]);

    return string;
}

void rice::p2p::util::XMLParser::setFeature(::java::lang::String* name, bool state) /* throws(XmlPullParserException) */
{
    throw new ::java::lang::UnsupportedOperationException();
}

bool rice::p2p::util::XMLParser::getFeature(::java::lang::String* name)
{
    throw new ::java::lang::UnsupportedOperationException();
}

void rice::p2p::util::XMLParser::setProperty(::java::lang::String* name, ::java::lang::Object* value) /* throws(XmlPullParserException) */
{
    throw new ::java::lang::UnsupportedOperationException();
}

java::lang::Object* rice::p2p::util::XMLParser::getProperty(::java::lang::String* name)
{
    throw new ::java::lang::UnsupportedOperationException();
}

void rice::p2p::util::XMLParser::setInput(::java::io::InputStream* inputStream, ::java::lang::String* inputEncoding) /* throws(XmlPullParserException) */
{
    throw new ::java::lang::UnsupportedOperationException();
}

java::lang::String* rice::p2p::util::XMLParser::getInputEncoding()
{
    throw new ::java::lang::UnsupportedOperationException();
}

void rice::p2p::util::XMLParser::defineEntityReplacementText(::java::lang::String* entityName, ::java::lang::String* replacementText) /* throws(XmlPullParserException) */
{
    throw new ::java::lang::UnsupportedOperationException();
}

int32_t rice::p2p::util::XMLParser::getNamespaceCount(int32_t depth) /* throws(XmlPullParserException) */
{
    throw new ::java::lang::UnsupportedOperationException();
}

java::lang::String* rice::p2p::util::XMLParser::getNamespacePrefix(int32_t pos) /* throws(XmlPullParserException) */
{
    throw new ::java::lang::UnsupportedOperationException();
}

java::lang::String* rice::p2p::util::XMLParser::getNamespaceUri(int32_t pos) /* throws(XmlPullParserException) */
{
    throw new ::java::lang::UnsupportedOperationException();
}

java::lang::String* rice::p2p::util::XMLParser::getNamespace(::java::lang::String* prefix)
{
    throw new ::java::lang::UnsupportedOperationException();
}

int32_t rice::p2p::util::XMLParser::getDepth()
{
    throw new ::java::lang::UnsupportedOperationException();
}

java::lang::String* rice::p2p::util::XMLParser::getPositionDescription()
{
    throw new ::java::lang::UnsupportedOperationException();
}

int32_t rice::p2p::util::XMLParser::getLineNumber()
{
    throw new ::java::lang::UnsupportedOperationException();
}

int32_t rice::p2p::util::XMLParser::getColumnNumber()
{
    throw new ::java::lang::UnsupportedOperationException();
}

char16_tArray* rice::p2p::util::XMLParser::getTextCharacters(::int32_tArray* holderForStartAndLength)
{
    throw new ::java::lang::UnsupportedOperationException();
}

java::lang::String* rice::p2p::util::XMLParser::getNamespace()
{
    throw new ::java::lang::UnsupportedOperationException();
}

java::lang::String* rice::p2p::util::XMLParser::getPrefix()
{
    throw new ::java::lang::UnsupportedOperationException();
}

bool rice::p2p::util::XMLParser::isEmptyElementTag() /* throws(XmlPullParserException) */
{
    throw new ::java::lang::UnsupportedOperationException();
}

java::lang::String* rice::p2p::util::XMLParser::getAttributeNamespace(int32_t index)
{
    throw new ::java::lang::UnsupportedOperationException();
}

java::lang::String* rice::p2p::util::XMLParser::getAttributePrefix(int32_t index)
{
    throw new ::java::lang::UnsupportedOperationException();
}

java::lang::String* rice::p2p::util::XMLParser::getAttributeType(int32_t index)
{
    throw new ::java::lang::UnsupportedOperationException();
}

bool rice::p2p::util::XMLParser::isAttributeDefault(int32_t index)
{
    throw new ::java::lang::UnsupportedOperationException();
}

int32_t rice::p2p::util::XMLParser::nextToken() /* throws(XmlPullParserException, IOException) */
{
    throw new ::java::lang::UnsupportedOperationException();
}

void rice::p2p::util::XMLParser::require(int32_t type, ::java::lang::String* namespace_, ::java::lang::String* name) /* throws(XmlPullParserException, IOException) */
{
    throw new ::java::lang::UnsupportedOperationException();
}

java::lang::String* rice::p2p::util::XMLParser::nextText() /* throws(XmlPullParserException, IOException) */
{
    throw new ::java::lang::UnsupportedOperationException();
}

int32_t rice::p2p::util::XMLParser::nextTag() /* throws(XmlPullParserException, IOException) */
{
    throw new ::java::lang::UnsupportedOperationException();
}

int32_t rice::p2p::util::XMLParser::getAttributeCount()
{
    throw new ::java::lang::UnsupportedOperationException();
}

java::lang::String* rice::p2p::util::XMLParser::getAttributeName(int32_t index)
{
    throw new ::java::lang::UnsupportedOperationException();
}

java::lang::String* rice::p2p::util::XMLParser::getAttributeValue(int32_t index)
{
    throw new ::java::lang::UnsupportedOperationException();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::util::XMLParser::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.util.XMLParser", 23);
    return c;
}

void rice::p2p::util::XMLParser::clinit()
{
    super::clinit();
    static bool in_cl_init = false;
struct clinit_ {
    clinit_() {
        in_cl_init = true;
        QUOTE_ = new ::char16_tArray({
            u'\''
            , u'"'
        });
        TAG_END_ = new ::char16_tArray({
            u'>'
            , u'/'
            , u'?'
        });
        WHITESPACE_ = new ::char16_tArray({
            u' '
            , u'\u0009'
            , u'\u000a'
            , u'\u000d'
        });
        WHITESPACE_OR_TAG_END_ = new ::char16_tArray({
            u' '
            , u'\u0009'
            , u'\u000a'
            , u'\u000d'
            , u'>'
            , u'/'
            , u'?'
        });
        WHITESPACE_OR_EQUALS_ = new ::char16_tArray({
            u' '
            , u'\u0009'
            , u'\u000a'
            , u'\u000d'
            , u'='
        });
        SINGLE_ = new ::char16_tArray(int32_t(1));
        ENTITIES_ = new ::java::lang::StringArrayArray({
            (new ::java::lang::StringArray({
            u"&apos;"_j
            , u"'"_j
        }))
            , (new ::java::lang::StringArray({
            u"&quot;"_j
            , u"\""_j
        }))
            , (new ::java::lang::StringArray({
            u"&lt;"_j
            , u"<"_j
        }))
            , (new ::java::lang::StringArray({
            u"&gt;"_j
            , u">"_j
        }))
            , (new ::java::lang::StringArray({
            u"&#13;"_j
            , ::java::lang::String::valueOf(static_cast< char16_t >(int32_t(13)))
        }))
            , (new ::java::lang::StringArray({
            u"&#10;"_j
            , ::java::lang::String::valueOf(static_cast< char16_t >(int32_t(10)))
        }))
            , (new ::java::lang::StringArray({
            u"&#9;"_j
            , ::java::lang::String::valueOf(static_cast< char16_t >(int32_t(9)))
        }))
            , (new ::java::lang::StringArray({
            u"&amp;"_j
            , u"&"_j
        }))
        });
    }
};

    if(!in_cl_init) {
        static clinit_ clinit_instance;
    }
}

java::lang::Class* rice::p2p::util::XMLParser::getClass0()
{
    return class_();
}

