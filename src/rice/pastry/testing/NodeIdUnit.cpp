// Generated from /pastry-2.1/src/rice/pastry/testing/NodeIdUnit.java
#include <rice/pastry/testing/NodeIdUnit.hpp>

#include <java/io/PrintStream.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/random/RandomSource.hpp>
#include <rice/p2p/commonapi/Id_Distance.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/pastry/Id_Distance.hpp>
#include <rice/pastry/Id.hpp>
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

rice::pastry::testing::NodeIdUnit::NodeIdUnit(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::testing::NodeIdUnit::NodeIdUnit() 
    : NodeIdUnit(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

rice::pastry::Id* rice::pastry::testing::NodeIdUnit::createNodeId()
{
    auto raw = new ::int8_tArray(::rice::pastry::Id::IdBitLength >> int32_t(3));
    npc(rng)->nextBytes(raw);
    auto nodeId = ::rice::pastry::Id::build(raw);
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"created node "_j)->append(static_cast< ::java::lang::Object* >(nodeId))->toString());
    auto copy = new ::int8_tArray(npc(raw)->length);
    npc(nodeId)->blit(copy);
    for (auto i = int32_t(0); i < npc(raw)->length; i++) 
                if((*copy)[i] != (*raw)[i])
            npc(::java::lang::System::out())->println(u"blit test failed!"_j);


    copy = npc(nodeId)->copy();
    for (auto i = int32_t(0); i < npc(raw)->length; i++) 
                if((*copy)[i] != (*raw)[i])
            npc(::java::lang::System::out())->println(u"copy test failed!"_j);


    return nodeId;
}

void rice::pastry::testing::NodeIdUnit::equalityTest()
{
    npc(::java::lang::System::out())->println(u"--------------------------"_j);
    npc(::java::lang::System::out())->println(u"Creating oth"_j);
    auto oth = createNodeId();
    if(npc(nid)->equals(oth) == false)
        npc(::java::lang::System::out())->println(u"not equal - as expected."_j);
    else
        npc(::java::lang::System::out())->println(u"ALERT: equal - warning this happens with very low probability"_j);
    if(npc(nid)->equals(nid) == true)
        npc(::java::lang::System::out())->println(u"equality seems reflexive."_j);
    else
        npc(::java::lang::System::out())->println(u"ALERT: equality is not reflexive."_j);
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"hash code of nid: "_j)->append(npc(nid)->hashCode())->toString());
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"hash code of oth: "_j)->append(npc(oth)->hashCode())->toString());
    npc(::java::lang::System::out())->println(u"--------------------------"_j);
}

void rice::pastry::testing::NodeIdUnit::distanceTest()
{
    npc(::java::lang::System::out())->println(u"--------------------------"_j);
    npc(::java::lang::System::out())->println(u"creating a and b respectively"_j);
    auto a = createNodeId();
    auto b = createNodeId();
    for (auto i = int32_t(0); i < 100; i++) {
        auto adist = npc(nid)->distance(a);
        auto adist2 = npc(a)->distance(nid);
        auto bdist = npc(nid)->distance(b);
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"adist ="_j)->append(static_cast< ::java::lang::Object* >(adist))
            ->append(u"\n bdist="_j)
            ->append(static_cast< ::java::lang::Object* >(bdist))->toString());
        if(npc(adist)->equals(static_cast< ::java::lang::Object* >(adist2)) == true)
            npc(::java::lang::System::out())->println(u"distance seems reflexive"_j);
        else
            npc(::java::lang::System::out())->println(u"ALERT: distance is non-reflexive."_j);
        if(npc(adist)->equals(static_cast< ::java::lang::Object* >(bdist)) == true)
            npc(::java::lang::System::out())->println(u"ALERT: nodes seem at equal distance - very unlikely"_j);
        else
            npc(::java::lang::System::out())->println(u"nodes have different distance as expected."_j);
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"result of comparison with a and b "_j)->append(npc(adist)->compareTo(static_cast< ::rice::p2p::commonapi::Id_Distance* >(bdist)))->toString());
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"result of comparison with a to itself "_j)->append(npc(adist)->compareTo(static_cast< ::rice::p2p::commonapi::Id_Distance* >(adist2)))->toString());
        if(npc(a)->clockwise(b))
            npc(::java::lang::System::out())->println(u"b is clockwise from a"_j);
        else
            npc(::java::lang::System::out())->println(u"b is counter-clockwise from a"_j);
        auto abs = npc(a)->distance(b);
        auto abl = npc(a)->longDistance(b);
        if(npc(abs)->compareTo(static_cast< ::rice::p2p::commonapi::Id_Distance* >(abl)) != -int32_t(1))
            npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"ERROR: abs.compareTo(abl)="_j)->append(npc(abs)->compareTo(static_cast< ::rice::p2p::commonapi::Id_Distance* >(abl)))->toString());

        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"abs="_j)->append(static_cast< ::java::lang::Object* >(abs))->toString());
        npc(abs)->shift(-int32_t(1), 1);
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"abs.shift(-1)="_j)->append(static_cast< ::java::lang::Object* >(abs))->toString());
        npc(abs)->shift(1, 0);
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"abs.shift(1)="_j)->append(static_cast< ::java::lang::Object* >(abs))->toString());
        if(!npc(abs)->equals(static_cast< ::java::lang::Object* >(npc(a)->distance(b))))
            npc(::java::lang::System::out())->println(u"SHIFT ERROR!"_j);

        a = createNodeId();
        b = createNodeId();
    }
    auto raw0 = (new ::int8_tArray({
        static_cast< int8_t >(int32_t(0))
        , static_cast< int8_t >(int32_t(0))
        , static_cast< int8_t >(int32_t(0))
        , static_cast< int8_t >(int32_t(0))
        , static_cast< int8_t >(int32_t(0))
        , static_cast< int8_t >(int32_t(0))
        , static_cast< int8_t >(int32_t(0))
        , static_cast< int8_t >(int32_t(0))
        , static_cast< int8_t >(int32_t(0))
        , static_cast< int8_t >(int32_t(0))
        , static_cast< int8_t >(int32_t(0))
        , static_cast< int8_t >(int32_t(0))
        , static_cast< int8_t >(int32_t(0))
        , static_cast< int8_t >(int32_t(0))
        , static_cast< int8_t >(int32_t(0))
        , static_cast< int8_t >(int32_t(0))
    }));
    auto raw80 = (new ::int8_tArray({
        static_cast< int8_t >(int32_t(0))
        , static_cast< int8_t >(int32_t(0))
        , static_cast< int8_t >(int32_t(0))
        , static_cast< int8_t >(int32_t(0))
        , static_cast< int8_t >(int32_t(0))
        , static_cast< int8_t >(int32_t(0))
        , static_cast< int8_t >(int32_t(0))
        , static_cast< int8_t >(int32_t(0))
        , static_cast< int8_t >(int32_t(0))
        , static_cast< int8_t >(int32_t(0))
        , static_cast< int8_t >(int32_t(0))
        , static_cast< int8_t >(int32_t(0))
        , static_cast< int8_t >(int32_t(0))
        , static_cast< int8_t >(int32_t(0))
        , static_cast< int8_t >(int32_t(0))
        , static_cast< int8_t >(-int32_t(128))
    }));
    auto raw7f = (new ::int8_tArray({
        static_cast< int8_t >(-int32_t(1))
        , static_cast< int8_t >(-int32_t(1))
        , static_cast< int8_t >(-int32_t(1))
        , static_cast< int8_t >(-int32_t(1))
        , static_cast< int8_t >(-int32_t(1))
        , static_cast< int8_t >(-int32_t(1))
        , static_cast< int8_t >(-int32_t(1))
        , static_cast< int8_t >(-int32_t(1))
        , static_cast< int8_t >(-int32_t(1))
        , static_cast< int8_t >(-int32_t(1))
        , static_cast< int8_t >(-int32_t(1))
        , static_cast< int8_t >(-int32_t(1))
        , static_cast< int8_t >(-int32_t(1))
        , static_cast< int8_t >(-int32_t(1))
        , static_cast< int8_t >(-int32_t(1))
        , static_cast< int8_t >(int32_t(127))
    }));
    auto t1 = (new ::int8_tArray({
        static_cast< int8_t >(int32_t(98))
        , static_cast< int8_t >(int32_t(172))
        , static_cast< int8_t >(int32_t(10))
        , static_cast< int8_t >(int32_t(109))
        , static_cast< int8_t >(int32_t(38))
        , static_cast< int8_t >(int32_t(58))
        , static_cast< int8_t >(int32_t(235))
        , static_cast< int8_t >(int32_t(177))
        , static_cast< int8_t >(int32_t(228))
        , static_cast< int8_t >(int32_t(142))
        , static_cast< int8_t >(int32_t(37))
        , static_cast< int8_t >(int32_t(242))
        , static_cast< int8_t >(int32_t(229))
        , static_cast< int8_t >(int32_t(14))
        , static_cast< int8_t >(int32_t(162))
        , static_cast< int8_t >(int32_t(19))
    }));
    auto t2 = (new ::int8_tArray({
        static_cast< int8_t >(int32_t(58))
        , static_cast< int8_t >(int32_t(63))
        , static_cast< int8_t >(int32_t(250))
        , static_cast< int8_t >(int32_t(130))
        , static_cast< int8_t >(int32_t(0))
        , static_cast< int8_t >(int32_t(145))
        , static_cast< int8_t >(int32_t(251))
        , static_cast< int8_t >(int32_t(130))
        , static_cast< int8_t >(int32_t(157))
        , static_cast< int8_t >(int32_t(210))
        , static_cast< int8_t >(int32_t(216))
        , static_cast< int8_t >(int32_t(66))
        , static_cast< int8_t >(int32_t(134))
        , static_cast< int8_t >(int32_t(64))
        , static_cast< int8_t >(int32_t(93))
        , static_cast< int8_t >(int32_t(215))
    }));
    a = ::rice::pastry::Id::build(t1);
    b = ::rice::pastry::Id::build(t2);
    auto n0 = ::rice::pastry::Id::build(raw0);
    auto n7f = ::rice::pastry::Id::build(raw7f);
    auto n80 = ::rice::pastry::Id::build(raw80);
    auto c = n0;
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"a="_j)->append(static_cast< ::java::lang::Object* >(a))
        ->append(u"b="_j)
        ->append(static_cast< ::java::lang::Object* >(b))
        ->append(u"c="_j)
        ->append(static_cast< ::java::lang::Object* >(c))->toString());
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"a.clockwise(b)="_j)->append(npc(a)->clockwise(b))->toString());
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"a.clockwise(a)="_j)->append(npc(a)->clockwise(a))->toString());
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"b.clockwise(b)="_j)->append(npc(b)->clockwise(b))->toString());
    if(npc(a)->clockwise(c))
        npc(::java::lang::System::out())->println(u"c is clockwise from a"_j);
    else
        npc(::java::lang::System::out())->println(u"c is counter-clockwise from a"_j);
    if(npc(b)->clockwise(c))
        npc(::java::lang::System::out())->println(u"c is clockwise from b"_j);
    else
        npc(::java::lang::System::out())->println(u"c is counter-clockwise from b"_j);
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"a.distance(b)"_j)->append(static_cast< ::java::lang::Object* >(npc(a)->distance(b)))
        ->append(u"b.distance(a)="_j)
        ->append(static_cast< ::java::lang::Object* >(npc(b)->distance(a)))->toString());
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"a.longDistance(b)"_j)->append(static_cast< ::java::lang::Object* >(npc(a)->longDistance(b)))
        ->append(u"b.longDistance(a)="_j)
        ->append(static_cast< ::java::lang::Object* >(npc(b)->longDistance(a)))->toString());
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"a.distance(a)"_j)->append(static_cast< ::java::lang::Object* >(npc(a)->distance(a)))
        ->append(u"a.longDistance(a)="_j)
        ->append(static_cast< ::java::lang::Object* >(npc(a)->longDistance(a)))->toString());
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"a.isBetween(a,n7f)="_j)->append(npc(a)->isBetween(a, n7f))->toString());
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"a.isBetween(n0,a)="_j)->append(npc(a)->isBetween(n0, a))->toString());
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"a.isBetween(n0,n7f)="_j)->append(npc(a)->isBetween(n0, n7f))->toString());
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"b.isBetween(n0,n80)="_j)->append(npc(b)->isBetween(n0, n80))->toString());
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"a.isBetween(a,n80)="_j)->append(npc(a)->isBetween(a, n80))->toString());
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"b.isBetween(n0,b)="_j)->append(npc(b)->isBetween(n0, b))->toString());
    npc(::java::lang::System::out())->println(u"--------------------------"_j);
}

void rice::pastry::testing::NodeIdUnit::baseFiddlingTest()
{
    npc(::java::lang::System::out())->println(u"--------------------------"_j);
    auto bitRep = u""_j;
    for (auto i = int32_t(0); i < ::rice::pastry::Id::IdBitLength; i++) {
        if(npc(nid)->checkBit(i) == true)
            bitRep = ::java::lang::StringBuilder().append(bitRep)->append(u"1"_j)->toString();
        else
            bitRep = ::java::lang::StringBuilder().append(bitRep)->append(u"0"_j)->toString();
    }
    npc(::java::lang::System::out())->println(bitRep);
    auto digRep = u""_j;
    for (auto i = int32_t(0); i < ::rice::pastry::Id::IdBitLength; i++) {
        digRep = ::java::lang::StringBuilder().append(digRep)->append(npc(nid)->getDigit(i, 1))->toString();
    }
    npc(::java::lang::System::out())->println(digRep);
    if(npc(bitRep)->equals(static_cast< ::java::lang::Object* >(digRep)) == true)
        npc(::java::lang::System::out())->println(u"strings the same - as expected"_j);
    else
        npc(::java::lang::System::out())->println(u"ALERT: strings differ - this is wrong."_j);
    npc(::java::lang::System::out())->println(u"--------------------------"_j);
}

void rice::pastry::testing::NodeIdUnit::msdTest()
{
    npc(::java::lang::System::out())->println(u"--------------------------"_j);
    npc(::java::lang::System::out())->println(u"creating a and b respectively"_j);
    auto a = createNodeId();
    auto b = createNodeId();
    auto adist = npc(nid)->distance(a);
    auto bdist = npc(nid)->distance(b);
    auto aldist = npc(nid)->longDistance(a);
    auto bldist = npc(nid)->longDistance(b);
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"nid.dist(a)="_j)->append(static_cast< ::java::lang::Object* >(adist))->toString());
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"nid.longDist(a)="_j)->append(static_cast< ::java::lang::Object* >(aldist))->toString());
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"nid.dist(b)="_j)->append(static_cast< ::java::lang::Object* >(bdist))->toString());
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"nid.longDist(b)="_j)->append(static_cast< ::java::lang::Object* >(bldist))->toString());
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"adist.compareTo(bdist) "_j)->append(npc(adist)->compareTo(static_cast< ::rice::p2p::commonapi::Id_Distance* >(bdist)))->toString());
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"aldist.compareTo(bldist) "_j)->append(npc(aldist)->compareTo(static_cast< ::rice::p2p::commonapi::Id_Distance* >(bldist)))->toString());
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"msdb a and nid "_j)->append(npc(nid)->indexOfMSDB(a))->toString());
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"msdb b and nid "_j)->append(npc(nid)->indexOfMSDB(b))->toString());
    if(npc(nid)->indexOfMSDB(a) == npc(a)->indexOfMSDB(nid))
        npc(::java::lang::System::out())->println(u"msdb is symmetric"_j);
    else
        npc(::java::lang::System::out())->println(u"ALERT: msdb is not symmetric"_j);
    for (auto i = int32_t(2); i <= 6; i++) {
        int32_t msdd;
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"msdd a and nid (base "_j)->append((int32_t(1) << i))
            ->append(u") "_j)
            ->append((msdd = npc(nid)->indexOfMSDD(a, i)))
            ->append(u" val="_j)
            ->append(npc(a)->getDigit(msdd, i))
            ->append(u","_j)
            ->append(npc(nid)->getDigit(msdd, i))->toString());
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"msdd b and nid (base "_j)->append((int32_t(1) << i))
            ->append(u") "_j)
            ->append((msdd = npc(nid)->indexOfMSDD(b, i)))
            ->append(u" val="_j)
            ->append(npc(b)->getDigit(msdd, i))
            ->append(u","_j)
            ->append(npc(nid)->getDigit(msdd, i))->toString());
    }
    npc(::java::lang::System::out())->println(u"--------------------------"_j);
}

void rice::pastry::testing::NodeIdUnit::alternateTest()
{
    npc(::java::lang::System::out())->println(u"--------------------------"_j);
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"nid="_j)->append(static_cast< ::java::lang::Object* >(nid))->toString());
    for (auto b = int32_t(2); b < 7; b++) 
                for (auto num = int32_t(2); num <= (int32_t(1) << b); num *= 2) 
                        for (auto i = int32_t(1); i < num; i++) 
                                npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"alternate (b="_j)->append(b)
                    ->append(u") "_j)
                    ->append(i)
                    ->append(u":"_j)
                    ->append(static_cast< ::java::lang::Object* >(npc(nid)->getAlternateId(num, b, i)))->toString());



    npc(::java::lang::System::out())->println(u"--------------------------"_j);
}

void rice::pastry::testing::NodeIdUnit::domainPrefixTest()
{
    npc(::java::lang::System::out())->println(u"--------------------------"_j);
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"nid="_j)->append(static_cast< ::java::lang::Object* >(nid))->toString());
    for (auto b = int32_t(2); b < 7; b++) 
                for (auto row = npc(nid)->IdBitLength / b - int32_t(1); row >= 0; row--) 
                        for (auto col = int32_t(0); col < (int32_t(1) << b); col++) {
                auto domainFirst = npc(nid)->getDomainPrefix(row, col, 0, b);
                auto domainLast = npc(nid)->getDomainPrefix(row, col, -int32_t(1), b);
                npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"prefixes "_j)->append(static_cast< ::java::lang::Object* >(nid))
                    ->append(static_cast< ::java::lang::Object* >(domainFirst))
                    ->append(static_cast< ::java::lang::Object* >(domainLast))->toString());
                auto cmp = npc(domainFirst)->compareTo(static_cast< ::rice::p2p::commonapi::Id* >(domainLast));
                auto equal = npc(domainFirst)->equals(domainLast);
                if((cmp == 0) != equal)
                    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"ERROR, compareTo="_j)->append(cmp)
                        ->append(u" equal="_j)
                        ->append(equal)->toString());

                if(cmp == 1)
                    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"ERROR, compareTo="_j)->append(cmp)->toString());

            }


    npc(::java::lang::System::out())->println(u"--------------------------"_j);
}

void rice::pastry::testing::NodeIdUnit::ctor()
{
    super::ctor();
    auto env = new ::rice::environment::Environment();
    rng = npc(env)->getRandomSource();
    npc(::java::lang::System::out())->println(u"Creating nid"_j);
    nid = createNodeId();
    equalityTest();
    distanceTest();
    baseFiddlingTest();
    msdTest();
    alternateTest();
    domainPrefixTest();
}

void rice::pastry::testing::NodeIdUnit::main(::java::lang::StringArray* args)
{
    clinit();
    auto niu = new NodeIdUnit();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::testing::NodeIdUnit::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.testing.NodeIdUnit", 30);
    return c;
}

java::lang::Class* rice::pastry::testing::NodeIdUnit::getClass0()
{
    return class_();
}

