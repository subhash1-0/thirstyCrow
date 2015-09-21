// Generated from /pastry-2.1/src/rice/pastry/testing/DirectPastryPingTest.java
#include <rice/pastry/testing/DirectPastryPingTest.hpp>

#include <java/io/BufferedReader.hpp>
#include <java/io/InputStreamReader.hpp>
#include <java/io/PrintStream.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>
#include <java/util/StringTokenizer.hpp>
#include <java/util/Vector.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/params/Parameters.hpp>
#include <rice/pastry/testing/PingTestRecord.hpp>
#include <rice/pastry/testing/SinglePingTest.hpp>

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

rice::pastry::testing::DirectPastryPingTest::DirectPastryPingTest(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::testing::DirectPastryPingTest::DirectPastryPingTest() 
    : DirectPastryPingTest(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

void rice::pastry::testing::DirectPastryPingTest::ctor()
{
    super::ctor();
}

bool rice::pastry::testing::DirectPastryPingTest::parseInput(::java::lang::String* in, ::rice::environment::Environment* environment)
{
    clinit();
    auto tokened = new ::java::util::StringTokenizer(in);
    if(!npc(tokened)->hasMoreTokens()) {
        return false;
    }
    auto token = npc(tokened)->nextToken();
    auto n = -int32_t(1);
    auto k = -int32_t(1);
    SinglePingTest* spt;
    int32_t i;
    if(npc(token)->startsWith(u"q"_j)) {
        return true;
    } else if(npc(token)->startsWith(u"s"_j)) {
        auto trlist = new ::java::util::Vector();
        for (i = 0; i < 8; i++) {
            n = k = (i + int32_t(1)) * int32_t(1000);
            auto tr = new PingTestRecord(n, k, npc(npc(environment)->getParameters())->getInt(u"pastry_rtBaseBitLength"_j));
            spt = new SinglePingTest(tr, environment);
            npc(spt)->test();
            npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(npc(tr)->getNodeNumber())->append(u"\t"_j)
                ->append(npc(tr)->getAveHops())
                ->append(u"\t"_j)
                ->append(npc(tr)->getAveDistance())->toString());
        }
    }
    return false;
}

void rice::pastry::testing::DirectPastryPingTest::main(::java::lang::StringArray* args) /* throws(IOException) */
{
    clinit();
    auto quit = false;
    auto env = ::rice::environment::Environment::directEnvironment();
    auto input = new ::java::io::BufferedReader(new ::java::io::InputStreamReader(::java::lang::System::in()));
    ::java::lang::String* command = nullptr;
    npc(::java::lang::System::out())->println(u"Usage: s - run standalone test"_j);
    npc(::java::lang::System::out())->println(u"       q - quit"_j);
    while (!quit) {
        try {
            command = npc(input)->readLine();
        } catch (::java::lang::Exception* e) {
            npc(::java::lang::System::out())->println(static_cast< ::java::lang::Object* >(e));
        }
        quit = parseInput(command, env);
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::testing::DirectPastryPingTest::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.testing.DirectPastryPingTest", 40);
    return c;
}

java::lang::Class* rice::pastry::testing::DirectPastryPingTest::getClass0()
{
    return class_();
}

