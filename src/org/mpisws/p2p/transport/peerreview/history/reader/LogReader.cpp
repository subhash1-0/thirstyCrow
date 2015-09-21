// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/history/reader/LogReader.java
#include <org/mpisws/p2p/transport/peerreview/history/reader/LogReader.hpp>

#include <java/lang/NullPointerException.hpp>
#include <java/lang/String.hpp>
#include <org/mpisws/p2p/transport/peerreview/history/IndexEntry.hpp>
#include <org/mpisws/p2p/transport/peerreview/history/SecureHistory.hpp>
#include <org/mpisws/p2p/transport/peerreview/history/SecureHistoryFactory.hpp>
#include <org/mpisws/p2p/transport/peerreview/history/reader/EntryDeserializer.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::transport::peerreview::history::reader::LogReader::LogReader(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::transport::peerreview::history::reader::LogReader::LogReader(::java::lang::String* name, ::org::mpisws::p2p::transport::peerreview::history::SecureHistoryFactory* factory, EntryDeserializer* deserializer)  /* throws(IOException) */
    : LogReader(*static_cast< ::default_init_tag* >(0))
{
    ctor(name,factory,deserializer);
}

void org::mpisws::p2p::transport::peerreview::history::reader::LogReader::ctor(::java::lang::String* name, ::org::mpisws::p2p::transport::peerreview::history::SecureHistoryFactory* factory, EntryDeserializer* deserializer) /* throws(IOException) */
{
    super::ctor();
    this->deserializer = deserializer;
    history = npc(factory)->open(name, u"r"_j);
    entryIndex = 0;
}

java::lang::String* org::mpisws::p2p::transport::peerreview::history::reader::LogReader::readEntry() /* throws(IOException) */
{
    if(entryIndex >= npc(history)->getNumEntries())
        return nullptr;

    auto ie = npc(history)->statEntry(entryIndex);
    auto ret = npc(deserializer)->read(ie, history);
    entryIndex++;
    return ret;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::peerreview::history::reader::LogReader::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.peerreview.history.reader.LogReader", 60);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::peerreview::history::reader::LogReader::getClass0()
{
    return class_();
}

