// Generated from /pastry-2.1/src/rice/p2p/util/XMLReader.java
#include <rice/p2p/util/XMLReader.hpp>

#include <java/io/BufferedReader.hpp>
#include <java/io/IOException.hpp>
#include <java/io/Reader.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <org/xmlpull/v1/XmlPullParser.hpp>
#include <org/xmlpull/v1/XmlPullParserException.hpp>
#include <rice/p2p/util/Base64.hpp>
#include <rice/p2p/util/XMLParser.hpp>
#include <Array.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::util::XMLReader::XMLReader(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::util::XMLReader::XMLReader(::java::io::Reader* in)  /* throws(IOException) */
    : XMLReader(*static_cast< ::default_init_tag* >(0))
{
    ctor(in);
}

void rice::p2p::util::XMLReader::ctor(::java::io::Reader* in) /* throws(IOException) */
{
    super::ctor();
    this->in = new ::java::io::BufferedReader(in);
    try {
        xpp = new XMLParser();
        npc(xpp)->setInput(this->in);
    } catch (::org::xmlpull::v1::XmlPullParserException* e) {
        throw new ::java::io::IOException(::java::lang::StringBuilder().append(u"XML Exception thrown: "_j)->append(static_cast< ::java::lang::Object* >(e))->toString());
    }
}

void rice::p2p::util::XMLReader::close() /* throws(IOException) */
{
    npc(in)->close();
}

int8_tArray* rice::p2p::util::XMLReader::readBase64() /* throws(IOException) */
{
    auto bytes = new ::int8_tArray(int32_t(0));
    assertStartTag(u"base64"_j);
    step();
    if(isText()) {
        bytes = npc(npc(xpp)->getText())->getBytes();
        bytes = Base64::decode(bytes, 0, npc(bytes)->length);
        step();
    }
    assertEndTag(u"base64"_j);
    return bytes;
}

void rice::p2p::util::XMLReader::readHeader() /* throws(IOException) */
{
    assertEvent(npc(xpp)->START_DOCUMENT);
    readStartTag(u"jsx"_j);
}

void rice::p2p::util::XMLReader::assertEvent(int32_t type) /* throws(IOException) */
{
    if(eventType != type)
        throw new ::java::io::IOException(::java::lang::StringBuilder().append(u"Expected event "_j)->append(type)
            ->append(u", got a "_j)
            ->append(eventType)->toString());

}

void rice::p2p::util::XMLReader::assertStartTag() /* throws(IOException) */
{
    assertEvent(npc(xpp)->START_TAG);
}

void rice::p2p::util::XMLReader::assertEndTag() /* throws(IOException) */
{
    assertEvent(npc(xpp)->END_TAG);
}

void rice::p2p::util::XMLReader::assertStartTag(::java::lang::String* name) /* throws(IOException) */
{
    assertStartTag();
    if(!npc(npc(xpp)->getName())->equals(static_cast< ::java::lang::Object* >(name)))
        throw new ::java::io::IOException(::java::lang::StringBuilder().append(u"Expected start tag '"_j)->append(name)
            ->append(u"', got a '"_j)
            ->append(npc(xpp)->getName())
            ->append(u"'"_j)->toString());

}

void rice::p2p::util::XMLReader::assertEndTag(::java::lang::String* name) /* throws(IOException) */
{
    assertEvent(npc(xpp)->END_TAG);
    if(!npc(npc(xpp)->getName())->equals(static_cast< ::java::lang::Object* >(name)))
        throw new ::java::io::IOException(::java::lang::StringBuilder().append(u"Expected end tag '"_j)->append(name)
            ->append(u"', got a '"_j)
            ->append(npc(xpp)->getName())
            ->append(u"'"_j)->toString());

}

void rice::p2p::util::XMLReader::readStartTag() /* throws(IOException) */
{
    step();
    assertStartTag();
}

void rice::p2p::util::XMLReader::readEndTag() /* throws(IOException) */
{
    step();
    assertEndTag();
}

void rice::p2p::util::XMLReader::readStartTag(::java::lang::String* name) /* throws(IOException) */
{
    readStartTag();
    assertStartTag(name);
}

void rice::p2p::util::XMLReader::readEndTag(::java::lang::String* name) /* throws(IOException) */
{
    readEndTag();
    assertEndTag(name);
}

void rice::p2p::util::XMLReader::assertAttribute(::java::lang::String* name, ::java::lang::String* value) /* throws(IOException) */
{
    if(getAttribute(name) == nullptr)
        throw new ::java::io::IOException(::java::lang::StringBuilder().append(u"Expected attribute "_j)->append(name)
            ->append(u", found none"_j)->toString());

    if(!npc(getAttribute(name))->equals(static_cast< ::java::lang::Object* >(value)))
        throw new ::java::io::IOException(::java::lang::StringBuilder().append(u"Expected attribute "_j)->append(name)
            ->append(u" to be '"_j)
            ->append(value)
            ->append(u"', got '"_j)
            ->append(getAttribute(name))
            ->append(u"'"_j)->toString());

}

void rice::p2p::util::XMLReader::step() /* throws(IOException) */
{
    try {
        eventType = npc(xpp)->next();
        if((eventType == npc(xpp)->TEXT) && (npc(xpp)->isWhitespace()))
            step();

    } catch (::org::xmlpull::v1::XmlPullParserException* e) {
        throw new ::java::io::IOException(::java::lang::StringBuilder().append(u"XML Exception thrown: "_j)->append(static_cast< ::java::lang::Object* >(e))->toString());
    }
}

bool rice::p2p::util::XMLReader::isStartDocument()
{
    return (eventType == npc(xpp)->START_DOCUMENT);
}

bool rice::p2p::util::XMLReader::isEndDocument()
{
    return (eventType == npc(xpp)->END_DOCUMENT);
}

bool rice::p2p::util::XMLReader::isStartTag()
{
    return (eventType == npc(xpp)->START_TAG);
}

bool rice::p2p::util::XMLReader::isEndTag()
{
    return (eventType == npc(xpp)->END_TAG);
}

bool rice::p2p::util::XMLReader::isText()
{
    return (eventType == npc(xpp)->TEXT);
}

java::lang::String* rice::p2p::util::XMLReader::getAttribute(::java::lang::String* name) /* throws(IOException) */
{
    assertEvent(npc(xpp)->START_TAG);
    auto result = npc(xpp)->getAttributeValue(nullptr, name);
    return result;
}

java::lang::String* rice::p2p::util::XMLReader::getStartTag() /* throws(IOException) */
{
    try {
        assertEvent(npc(xpp)->START_TAG);
        return npc(xpp)->getName();
    } catch (::java::io::IOException* e) {
        throw new ::java::io::IOException(::java::lang::StringBuilder().append(u"getStartTag called, caused "_j)->append(static_cast< ::java::lang::Object* >(e))->toString());
    }
}

java::lang::String* rice::p2p::util::XMLReader::getEndTag() /* throws(IOException) */
{
    try {
        assertEvent(npc(xpp)->END_TAG);
        return npc(xpp)->getName();
    } catch (::java::io::IOException* e) {
        throw new ::java::io::IOException(::java::lang::StringBuilder().append(u"getEndTag called, caused "_j)->append(static_cast< ::java::lang::Object* >(e))->toString());
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::util::XMLReader::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.util.XMLReader", 23);
    return c;
}

java::lang::Class* rice::p2p::util::XMLReader::getClass0()
{
    return class_();
}

