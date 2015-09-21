// Generated from /pastry-2.1/src/rice/p2p/util/testing/TestSortedLinkedList.java
#include <rice/p2p/util/testing/TestSortedLinkedList.hpp>

#include <java/io/PrintStream.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Integer.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/RuntimeException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>
#include <java/util/Iterator.hpp>
#include <java/util/Random.hpp>
#include <rice/p2p/util/SortedLinkedList.hpp>

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

rice::p2p::util::testing::TestSortedLinkedList::TestSortedLinkedList(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::util::testing::TestSortedLinkedList::TestSortedLinkedList()
    : TestSortedLinkedList(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

void rice::p2p::util::testing::TestSortedLinkedList::main(::java::lang::StringArray* args)
{
    clinit();
    auto foo = new ::rice::p2p::util::SortedLinkedList();
    auto r = new ::java::util::Random();
    for (auto ctr = int32_t(0); ctr < 10; ctr++) {
        auto i = npc(r)->nextInt(100);
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"Adding "_j)->append(i)->toString());
        npc(foo)->add(::java::lang::Integer::valueOf(i));
    }
    npc(::java::lang::System::out())->println(static_cast< ::java::lang::Object* >(foo));
    int32_t last = (npc(java_cast< ::java::lang::Integer* >(npc(foo)->getFirst())))->intValue();
    for (auto _i = npc(foo)->iterator(); _i->hasNext(); ) {
        int32_t i = npc(java_cast< ::java::lang::Integer* >(_i->next()))->intValue();
        {
            if(i < last)
                throw new ::java::lang::RuntimeException(::java::lang::StringBuilder().append(i)->append(u"<"_j)
                    ->append(last)->toString());

        }
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::util::testing::TestSortedLinkedList::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.util.testing.TestSortedLinkedList", 42);
    return c;
}

java::lang::Class* rice::p2p::util::testing::TestSortedLinkedList::getClass0()
{
    return class_();
}

