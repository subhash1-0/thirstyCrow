// Generated from /pastry-2.1/src/rice/p2p/util/XMLWriter.java
#include <rice/p2p/util/XMLWriter.hpp>

#include <java/io/BufferedWriter.hpp>
#include <java/io/IOException.hpp>
#include <java/io/OutputStreamWriter.hpp>
#include <java/io/Writer.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>
#include <org/xmlpull/v1/XmlPullParserException.hpp>
#include <org/xmlpull/v1/XmlPullParserFactory.hpp>
#include <org/xmlpull/v1/XmlSerializer.hpp>
#include <rice/p2p/util/Base64.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::util::XMLWriter::XMLWriter(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::util::XMLWriter::XMLWriter(::java::io::OutputStream* out)  /* throws(IOException) */
    : XMLWriter(*static_cast< ::default_init_tag* >(0))
{
    ctor(out);
}

void rice::p2p::util::XMLWriter::ctor(::java::io::OutputStream* out) /* throws(IOException) */
{
    super::ctor();
    try {
        this->writer = new ::java::io::BufferedWriter(new ::java::io::OutputStreamWriter(out));
        auto factory = ::org::xmlpull::v1::XmlPullParserFactory::newInstance(::java::lang::System::getProperty(::org::xmlpull::v1::XmlPullParserFactory::PROPERTY_NAME()), nullptr);
        serializer = npc(factory)->newSerializer();
        npc(serializer)->setOutput(this->writer);
        npc(serializer)->setProperty(u"http://xmlpull.org/v1/doc/properties.html#serializer-indentation"_j, u" "_j);
        npc(serializer)->setProperty(u"http://xmlpull.org/v1/doc/properties.html#serializer-line-separator"_j, u"\n"_j);
        npc(serializer)->setFeature(u"http://xmlpull.org/v1/doc/features.html#serializer-attvalue-use-apostrophe"_j, true);
    } catch (::org::xmlpull::v1::XmlPullParserException* e) {
        throw new ::java::io::IOException(::java::lang::StringBuilder().append(u"XML Exception thrown: "_j)->append(static_cast< ::java::lang::Object* >(e))->toString());
    }
}

void rice::p2p::util::XMLWriter::flush() /* throws(IOException) */
{
    npc(serializer)->flush();
}

void rice::p2p::util::XMLWriter::close() /* throws(IOException) */
{
    npc(serializer)->text(u"\n"_j);
    npc(serializer)->flush();
    npc(writer)->close();
}

void rice::p2p::util::XMLWriter::writeBase64(::int8_tArray* bytes, int32_t off, int32_t len) /* throws(IOException) */
{
    flush();
    npc(writer)->write(Base64::encodeBytes(bytes, off, len));
}

void rice::p2p::util::XMLWriter::writeHeader() /* throws(IOException) */
{
    npc(serializer)->startDocument(nullptr, nullptr);
    npc(serializer)->text(u"\n\n"_j);
}

void rice::p2p::util::XMLWriter::attribute(::java::lang::String* name, int32_t value) /* throws(IOException) */
{
    attribute(name, ::java::lang::String::valueOf(value));
}

void rice::p2p::util::XMLWriter::attribute(::java::lang::String* name, double value) /* throws(IOException) */
{
    attribute(name, ::java::lang::String::valueOf(value));
}

void rice::p2p::util::XMLWriter::attribute(::java::lang::String* name, float value) /* throws(IOException) */
{
    attribute(name, ::java::lang::String::valueOf(value));
}

void rice::p2p::util::XMLWriter::attribute(::java::lang::String* name, int64_t value) /* throws(IOException) */
{
    attribute(name, ::java::lang::String::valueOf(value));
}

void rice::p2p::util::XMLWriter::attribute(::java::lang::String* name, char16_t value) /* throws(IOException) */
{
    attribute(name, ::java::lang::String::valueOf(value));
}

void rice::p2p::util::XMLWriter::attribute(::java::lang::String* name, bool value) /* throws(IOException) */
{
    attribute(name, ::java::lang::String::valueOf(value));
}

void rice::p2p::util::XMLWriter::attribute(::java::lang::String* name, ::java::lang::Object* value) /* throws(IOException) */
{
    if(value == nullptr)
        return;

    attribute(name, npc(value)->toString());
}

void rice::p2p::util::XMLWriter::attribute(::java::lang::String* name, ::java::lang::String* value) /* throws(IOException) */
{
    npc(serializer)->attribute(nullptr, name, value);
}

void rice::p2p::util::XMLWriter::start(::java::lang::String* name) /* throws(IOException) */
{
    npc(serializer)->startTag(nullptr, name);
}

void rice::p2p::util::XMLWriter::end(::java::lang::String* name) /* throws(IOException) */
{
    npc(serializer)->endTag(nullptr, name);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::util::XMLWriter::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.util.XMLWriter", 23);
    return c;
}

java::lang::Class* rice::p2p::util::XMLWriter::getClass0()
{
    return class_();
}

