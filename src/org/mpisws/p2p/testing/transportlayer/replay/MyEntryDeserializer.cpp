// Generated from /pastry-2.1/src/org/mpisws/p2p/testing/transportlayer/replay/MyEntryDeserializer.java
#include <org/mpisws/p2p/testing/transportlayer/replay/MyEntryDeserializer.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/net/InetAddress.hpp>
#include <java/net/InetSocketAddress.hpp>
#include <org/mpisws/p2p/transport/peerreview/history/IndexEntry.hpp>
#include <org/mpisws/p2p/transport/peerreview/history/SecureHistory.hpp>
#include <org/mpisws/p2p/transport/util/Serializer.hpp>
#include <rice/p2p/util/rawserialization/SimpleInputBuffer.hpp>
#include <Array.hpp>

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

org::mpisws::p2p::testing::transportlayer::replay::MyEntryDeserializer::MyEntryDeserializer(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::testing::transportlayer::replay::MyEntryDeserializer::MyEntryDeserializer(::org::mpisws::p2p::transport::util::Serializer* serializer) 
    : MyEntryDeserializer(*static_cast< ::default_init_tag* >(0))
{
    ctor(serializer);
}

void org::mpisws::p2p::testing::transportlayer::replay::MyEntryDeserializer::ctor(::org::mpisws::p2p::transport::util::Serializer* serializer)
{
    super::ctor();
    this->serializer = serializer;
}

java::lang::String* org::mpisws::p2p::testing::transportlayer::replay::MyEntryDeserializer::entryId(int16_t id)
{
    auto ret = super::entryId(id);
    if(ret != nullptr)
        return ret;

    switch (id) {
    case EVT_BOOT:
        return u"Boot"_j;
    case EVT_SUBSCRIBE:
        return u"Subscribe"_j;
    case EVT_PUBLISH:
        return u"Publish"_j;
    default:
        return nullptr;
    }

}

java::lang::String* org::mpisws::p2p::testing::transportlayer::replay::MyEntryDeserializer::read(::org::mpisws::p2p::transport::peerreview::history::IndexEntry* ie, ::org::mpisws::p2p::transport::peerreview::history::SecureHistory* history) /* throws(IOException) */
{
    ::rice::p2p::util::rawserialization::SimpleInputBuffer* nextEvent = nullptr;
    if(npc(ie)->getSizeInFile() > 0)
        nextEvent = new ::rice::p2p::util::rawserialization::SimpleInputBuffer(npc(history)->getEntry(ie, npc(ie)->getSizeInFile()));

    switch (npc(ie)->getType()) {
    case EVT_SOCKET_OPEN_OUTGOING: {
            auto socketId = npc(nextEvent)->readInt();
            auto addrBytes = new ::int8_tArray(int32_t(4));
            npc(nextEvent)->read(addrBytes);
            auto addr = new ::java::net::InetSocketAddress(::java::net::InetAddress::getByAddress(addrBytes), static_cast< int32_t >(npc(nextEvent)->readShort()));
            return ::java::lang::StringBuilder().append(entryId(npc(ie)->getType()))->append(u" socketId:"_j)
                ->append(socketId)
                ->append(u" addr:"_j)
                ->append(static_cast< ::java::lang::Object* >(addr))->toString();
        }
    case EVT_SOCKET_OPENED_OUTGOING: {
            auto socketId = npc(nextEvent)->readInt();
            return ::java::lang::StringBuilder().append(entryId(npc(ie)->getType()))->append(u" socketId:"_j)
                ->append(socketId)->toString();
        }
    case EVT_SEND: {
            ::rice::p2p::commonapi::rawserialization::InputBuffer* buf = new ::rice::p2p::util::rawserialization::SimpleInputBuffer(npc(history)->getEntry(ie, npc(ie)->getSizeInFile()));
            return ::java::lang::StringBuilder().append(entryId(npc(ie)->getType()))->append(u" n:"_j)
                ->append(npc(ie)->getSeq())
                ->append(u" s:"_j)
                ->append(npc(ie)->getSizeInFile())
                ->append(u" i:"_j)
                ->append(npc(ie)->getFileIndex())
                ->append(u" ->"_j)
                ->append(static_cast< ::java::lang::Object* >(java_cast< ::java::lang::Object* >(npc(serializer)->deserialize(buf))))->toString();
        }
    default:
        return super::read(ie, history);
    }

}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::testing::transportlayer::replay::MyEntryDeserializer::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.testing.transportlayer.replay.MyEntryDeserializer", 64);
    return c;
}

java::lang::Class* org::mpisws::p2p::testing::transportlayer::replay::MyEntryDeserializer::getClass0()
{
    return class_();
}

