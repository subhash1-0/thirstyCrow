// Generated from /pastry-2.1/src/org/mpisws/p2p/testing/transportlayer/peerreview/LogSnippitTest.java
#include <org/mpisws/p2p/testing/transportlayer/peerreview/LogSnippitTest.hpp>

#include <java/io/PrintStream.hpp>
#include <java/lang/Integer.hpp>
#include <java/lang/Math.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/Short.hpp>
#include <java/lang/String.hpp>
#include <java/lang/System.hpp>
#include <java/util/ArrayList.hpp>
#include <java/util/List.hpp>
#include <java/util/Random.hpp>
#include <org/mpisws/p2p/transport/peerreview/audit/LogSnippet.hpp>
#include <org/mpisws/p2p/transport/peerreview/audit/SnippetEntry.hpp>
#include <rice/p2p/commonapi/rawserialization/InputBuffer.hpp>
#include <rice/p2p/util/rawserialization/SimpleInputBuffer.hpp>
#include <rice/p2p/util/rawserialization/SimpleOutputBuffer.hpp>
#include <Array.hpp>

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

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::testing::transportlayer::peerreview::LogSnippitTest::LogSnippitTest(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::testing::transportlayer::peerreview::LogSnippitTest::LogSnippitTest()
    : LogSnippitTest(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

void org::mpisws::p2p::testing::transportlayer::peerreview::LogSnippitTest::main(::java::lang::StringArray* args) /* throws(Exception) */
{
    clinit();
    auto r = new ::java::util::Random();
    auto hashSize = npc(r)->nextInt(100) + int32_t(1);
    auto list = new ::java::util::ArrayList(int32_t(100));
    auto seq = ::java::lang::Math::abs(npc(r)->nextLong());
    for (auto i = int32_t(0); i < 400; i++) {
        auto isHash = npc(r)->nextInt(10) == 1;
        ::int8_tArray* content;
        if(isHash) {
            content = new ::int8_tArray(hashSize);
        } else {
            switch (npc(r)->nextInt(15)) {
            case int32_t(9):
                content = new ::int8_tArray(npc(r)->nextInt(65535));
                break;
            case int32_t(8):
                content = new ::int8_tArray(npc(r)->nextInt(::java::lang::Short::MAX_VALUE * int32_t(10)));
                break;
            case int32_t(10):
                content = new ::int8_tArray(int32_t(255));
                break;
            case int32_t(11):
                content = new ::int8_tArray(int32_t(254));
                break;
            case int32_t(12):
                content = new ::int8_tArray(int32_t(253));
                break;
            case int32_t(13):
                content = new ::int8_tArray(int32_t(65535));
                break;
            case int32_t(14):
                content = new ::int8_tArray(int32_t(65534));
                break;
            default:
                content = new ::int8_tArray(npc(r)->nextInt(254) + int32_t(1));
            }

        }
        npc(r)->nextBytes(content);
        auto seqChoice = npc(r)->nextInt(10);
        if(seqChoice < 5) {
            seq++;
        } else if(seqChoice < 8) {
            seq -= (seq % ::org::mpisws::p2p::transport::peerreview::audit::SnippetEntry::NUM_INDEXES);
            seq += ::org::mpisws::p2p::transport::peerreview::audit::SnippetEntry::NUM_INDEXES;
        } else {
            seq += npc(r)->nextInt(::java::lang::Integer::MAX_VALUE);
        }
        npc(list)->add(static_cast< ::java::lang::Object* >(new ::org::mpisws::p2p::transport::peerreview::audit::SnippetEntry(static_cast< int8_t >(npc(r)->nextInt(256)), seq, isHash, content)));
    }
    auto baseHash = new ::int8_tArray(hashSize);
    npc(r)->nextBytes(baseHash);
    auto ls = new ::org::mpisws::p2p::transport::peerreview::audit::LogSnippet(baseHash, static_cast< ::java::util::List* >(list));
    auto sob = new ::rice::p2p::util::rawserialization::SimpleOutputBuffer();
    npc(ls)->serialize(sob);
    auto sib = new ::rice::p2p::util::rawserialization::SimpleInputBuffer(npc(sob)->getBytes());
    auto ls2 = new ::org::mpisws::p2p::transport::peerreview::audit::LogSnippet(static_cast< ::rice::p2p::commonapi::rawserialization::InputBuffer* >(sib), hashSize);
    if(npc(ls2)->equals(static_cast< ::java::lang::Object* >(ls))) {
        npc(::java::lang::System::out())->println(u"success"_j);
    } else {
        npc(::java::lang::System::out())->println(u"failure"_j);
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::testing::transportlayer::peerreview::LogSnippitTest::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.testing.transportlayer.peerreview.LogSnippitTest", 63);
    return c;
}

java::lang::Class* org::mpisws::p2p::testing::transportlayer::peerreview::LogSnippitTest::getClass0()
{
    return class_();
}

