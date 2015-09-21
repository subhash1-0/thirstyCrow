// Generated from /pastry-2.1/src/rice/pastry/testing/rendezvous/RendezvousScribeTest.java
#include <rice/pastry/testing/rendezvous/RendezvousScribeTest.hpp>

#include <java/io/PrintStream.hpp>
#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/CharSequence.hpp>
#include <java/lang/Comparable.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/System.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/params/Parameters.hpp>
#include <rice/p2p/scribe/testing/RawScribeRegrTest.hpp>
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

rice::pastry::testing::rendezvous::RendezvousScribeTest::RendezvousScribeTest(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::testing::rendezvous::RendezvousScribeTest::RendezvousScribeTest()
    : RendezvousScribeTest(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

void rice::pastry::testing::rendezvous::RendezvousScribeTest::main(::java::lang::StringArray* args) /* throws(IOException) */
{
    clinit();
    for (auto i = int32_t(0); i < npc(args)->length; i++) {
        if(npc((*args)[i])->equals(static_cast< ::java::lang::Object* >(u"-tofile"_j))) {
            ::java::lang::System::setOut(new ::java::io::PrintStream(u"delme.txt"_j));
            ::java::lang::System::setErr(::java::lang::System::out());
            break;
        }
    }
    auto env = ::rice::p2p::scribe::testing::RawScribeRegrTest::parseArgs(args);
    auto p = npc(env)->getParameters();
    npc(p)->setBoolean(u"rendezvous_test_firewall"_j, true);
    npc(p)->setBoolean(u"rendezvous_test_makes_bootstrap"_j, true);
    npc(p)->setFloat(u"rendezvous_test_num_firewalled"_j, 0.5f);
    auto scribeTest = new ::rice::p2p::scribe::testing::RawScribeRegrTest(env);
    npc(scribeTest)->start();
    npc(env)->destroy();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::testing::rendezvous::RendezvousScribeTest::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.testing.rendezvous.RendezvousScribeTest", 51);
    return c;
}

java::lang::Class* rice::pastry::testing::rendezvous::RendezvousScribeTest::getClass0()
{
    return class_();
}

