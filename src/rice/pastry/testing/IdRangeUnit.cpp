// Generated from /pastry-2.1/src/rice/pastry/testing/IdRangeUnit.java
#include <rice/pastry/testing/IdRangeUnit.hpp>

#include <java/io/PrintStream.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>
#include <rice/environment/random/simple/SimpleRandomSource.hpp>
#include <rice/pastry/Id_Distance.hpp>
#include <rice/pastry/Id.hpp>
#include <rice/pastry/IdRange.hpp>
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

rice::pastry::testing::IdRangeUnit::IdRangeUnit(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::testing::IdRangeUnit::IdRangeUnit() 
    : IdRangeUnit(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

rice::pastry::IdRange* rice::pastry::testing::IdRangeUnit::createRandomIdRange()
{
    ::rice::pastry::IdRange* r;
    r = new ::rice::pastry::IdRange(::rice::pastry::Id::makeRandomId(rng), ::rice::pastry::Id::makeRandomId(rng));
    return r;
}

rice::pastry::IdRange* rice::pastry::testing::IdRangeUnit::createFullIdRange()
{
    ::rice::pastry::IdRange* r;
    auto id = ::rice::pastry::Id::makeRandomId(rng);
    r = new ::rice::pastry::IdRange(id, id);
    return r;
}

rice::pastry::IdRange* rice::pastry::testing::IdRangeUnit::createEmptyIdRange()
{
    ::rice::pastry::IdRange* r;
    r = new ::rice::pastry::IdRange();
    return r;
}

rice::pastry::IdRange* rice::pastry::testing::IdRangeUnit::createIdRangeStartingWith(::rice::pastry::Id* ccw)
{
    ::rice::pastry::IdRange* r;
    r = new ::rice::pastry::IdRange(ccw, ::rice::pastry::Id::makeRandomId(rng));
    return r;
}

rice::pastry::IdRange* rice::pastry::testing::IdRangeUnit::createIdRangeEndingIn(::rice::pastry::Id* cw)
{
    ::rice::pastry::IdRange* r;
    r = new ::rice::pastry::IdRange(::rice::pastry::Id::makeRandomId(rng), cw);
    return r;
}

rice::pastry::Id* rice::pastry::testing::IdRangeUnit::createIdWithPrefix(int8_t b)
{
    auto data = new ::int8_tArray(::rice::pastry::Id::IdBitLength / int32_t(8));
    (*data)[npc(data)->length - int32_t(1)] = b;
    return ::rice::pastry::Id::build(data);
}

void rice::pastry::testing::IdRangeUnit::halfTest()
{
    auto r = createFullIdRange();
    auto ccw = npc(r)->ccwHalf();
    auto cw = npc(r)->cwHalf();
    if(!npc(npc(npc(cw)->getCW())->distance(npc(cw)->getCCW()))->equals(static_cast< ::java::lang::Object* >(npc(npc(cw)->getCW())->longDistance(npc(cw)->getCCW())))) {
        npc(::java::lang::System::out())->println(u"ALERT: cw long distance not equal"_j);
    }
    if(!npc(npc(npc(ccw)->getCW())->distance(npc(ccw)->getCCW()))->equals(static_cast< ::java::lang::Object* >(npc(npc(ccw)->getCW())->longDistance(npc(ccw)->getCCW())))) {
        npc(::java::lang::System::out())->println(u"ALERT: ccw long distance not equal"_j);
    }
}

void rice::pastry::testing::IdRangeUnit::equalityTest(::rice::pastry::IdRange* r1, ::rice::pastry::IdRange* r2)
{
    if(npc(r1)->equals(static_cast< ::java::lang::Object* >(r2)) && !npc(r1)->isEmpty() && !npc(r1)->isFull())
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"ALERT: equality failed with high probability"_j)->append(static_cast< ::java::lang::Object* >(r1))
            ->append(static_cast< ::java::lang::Object* >(r2))->toString());

    if(!npc(r1)->equals(static_cast< ::java::lang::Object* >(r1)))
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"ALERT: equality is not reflexive."_j)->append(static_cast< ::java::lang::Object* >(r1))->toString());

    auto r3 = new ::rice::pastry::IdRange(npc(r2)->getCCW(), npc(r2)->getCW());
    auto r31 = new ::rice::pastry::IdRange(r3);
    if((!npc(r3)->equals(static_cast< ::java::lang::Object* >(r2)) && !npc(r2)->isEmpty()) || !npc(r3)->equals(static_cast< ::java::lang::Object* >(r31)))
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"ALERT: equality failed."_j)->append(static_cast< ::java::lang::Object* >(r2))
            ->append(static_cast< ::java::lang::Object* >(r3))
            ->append(static_cast< ::java::lang::Object* >(r31))->toString());

    auto r4 = new ::rice::pastry::IdRange();
    auto r5 = new ::rice::pastry::IdRange(npc(r1)->getCCW(), npc(r1)->getCCW());
    if(npc(r4)->equals(static_cast< ::java::lang::Object* >(r5)))
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"ALERT: equality failed"_j)->append(static_cast< ::java::lang::Object* >(r4))
            ->append(static_cast< ::java::lang::Object* >(r4))->toString());

    if(!npc(r4)->isEmpty() || npc(r5)->isEmpty())
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"ALERT: isEmpty failed"_j)->append(static_cast< ::java::lang::Object* >(r4))
            ->append(static_cast< ::java::lang::Object* >(r5))->toString());

}

void rice::pastry::testing::IdRangeUnit::mergeIntersectTest(::rice::pastry::IdRange* r1, ::rice::pastry::IdRange* r2)
{
    auto m1 = npc(r1)->merge(r2);
    auto m2 = npc(r2)->merge(r1);
    auto i1 = npc(r1)->intersect(r2);
    if(!npc(m1)->equals(static_cast< ::java::lang::Object* >(m2)) && (!npc(i1)->isEmpty() || npc(r1)->isAdjacent(r2)) && !npc(r1)->isEmpty())
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"ALERT: merge is not symmetric 1"_j)->append(static_cast< ::java::lang::Object* >(r1))
            ->append(static_cast< ::java::lang::Object* >(r2))
            ->append(static_cast< ::java::lang::Object* >(m1))
            ->append(static_cast< ::java::lang::Object* >(m2))->toString());

    auto intersect = !npc(i1)->isEmpty();
    auto adjacent = npc(r1)->isAdjacent(r2);
    auto intersectOrAdjacent = intersect || adjacent;
    auto i2 = npc(r2)->intersect(r1);
    if(npc(i1)->isEmpty() != npc(i2)->isEmpty())
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"ALERT: intersect error 1."_j)->append(static_cast< ::java::lang::Object* >(i1))
            ->append(static_cast< ::java::lang::Object* >(i2))->toString());

    if(intersectOrAdjacent) {
        if(npc(m1)->equals(static_cast< ::java::lang::Object* >(r1)) && !npc(i1)->isEmpty() && !npc(i1)->equals(static_cast< ::java::lang::Object* >(r2)))
            npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"ALERT: merge is not symmetric 2"_j)->append(static_cast< ::java::lang::Object* >(r1))
                ->append(static_cast< ::java::lang::Object* >(r2))
                ->append(static_cast< ::java::lang::Object* >(m1))
                ->append(static_cast< ::java::lang::Object* >(i1))->toString());

        if(npc(m1)->equals(static_cast< ::java::lang::Object* >(r2)) && !npc(i1)->isEmpty() && !npc(i1)->equals(static_cast< ::java::lang::Object* >(r1)))
            npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"ALERT: merge is not symmetric 3"_j)->append(static_cast< ::java::lang::Object* >(r1))
                ->append(static_cast< ::java::lang::Object* >(r2))
                ->append(static_cast< ::java::lang::Object* >(m1))
                ->append(static_cast< ::java::lang::Object* >(i1))->toString());

        auto re1 = npc(m1)->intersect(r1);
        auto re2 = npc(m1)->intersect(r2);
        if(!npc(r1)->equals(static_cast< ::java::lang::Object* >(re1)) || !npc(r2)->equals(static_cast< ::java::lang::Object* >(re2)))
            npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"ALERT: intersect error 2."_j)->append(static_cast< ::java::lang::Object* >(r1))
                ->append(static_cast< ::java::lang::Object* >(re1))
                ->append(static_cast< ::java::lang::Object* >(r2))
                ->append(static_cast< ::java::lang::Object* >(re2))
                ->append(static_cast< ::java::lang::Object* >(m1))->toString());

    } else {
        if(!npc(m1)->equals(static_cast< ::java::lang::Object* >(r1)) && !npc(r1)->isEmpty())
            npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"ALERT: merge error 0."_j)->append(static_cast< ::java::lang::Object* >(r1))
                ->append(static_cast< ::java::lang::Object* >(r2))
                ->append(static_cast< ::java::lang::Object* >(m1))->toString());

    }
    if((npc(r1)->isEmpty() || npc(r2)->isEmpty()) && !npc(i1)->isEmpty())
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"ALERT: intersect error 3."_j)->append(static_cast< ::java::lang::Object* >(r1))
            ->append(static_cast< ::java::lang::Object* >(r2))
            ->append(static_cast< ::java::lang::Object* >(i1))->toString());

    if(npc(r1)->isEmpty() && !npc(m1)->equals(static_cast< ::java::lang::Object* >(r2)))
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"ALERT: merge error 1."_j)->append(static_cast< ::java::lang::Object* >(r1))
            ->append(static_cast< ::java::lang::Object* >(r2))
            ->append(static_cast< ::java::lang::Object* >(m1))->toString());

    if(npc(r2)->isEmpty() && !npc(m1)->equals(static_cast< ::java::lang::Object* >(r1)))
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"ALERT: merge error 2."_j)->append(static_cast< ::java::lang::Object* >(r1))
            ->append(static_cast< ::java::lang::Object* >(r2))
            ->append(static_cast< ::java::lang::Object* >(m1))->toString());

    if((npc(r1)->isFull() || npc(r2)->isFull()) && !npc(m1)->isFull())
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"ALERT: merge error 3."_j)->append(static_cast< ::java::lang::Object* >(r1))
            ->append(static_cast< ::java::lang::Object* >(r2))
            ->append(static_cast< ::java::lang::Object* >(m1))->toString());

    if(npc(r1)->isFull() && !npc(i1)->equals(static_cast< ::java::lang::Object* >(r2)))
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"ALERT: intersect error 4."_j)->append(static_cast< ::java::lang::Object* >(r1))
            ->append(static_cast< ::java::lang::Object* >(r2))
            ->append(static_cast< ::java::lang::Object* >(i1))->toString());

    if(npc(r2)->isFull() && !npc(i1)->equals(static_cast< ::java::lang::Object* >(r1)))
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"ALERT: intersect error 5."_j)->append(static_cast< ::java::lang::Object* >(r1))
            ->append(static_cast< ::java::lang::Object* >(r2))
            ->append(static_cast< ::java::lang::Object* >(m1))->toString());

}

void rice::pastry::testing::IdRangeUnit::diffSubtractTest(::rice::pastry::IdRange* r1, ::rice::pastry::IdRange* r2)
{
    auto d1 = npc(r1)->diff(r2);
    auto d2 = npc(r2)->diff(r1);
    auto i1 = npc(r1)->intersect(r2);
    auto i2 = npc(r2)->intersect(r1);
    if(!npc(npc(d1)->intersect(i1))->isEmpty() || !npc(npc(d1)->intersect(i2))->isEmpty() || !npc(npc(d2)->intersect(i1))->isEmpty()|| !npc(npc(d2)->intersect(i2))->isEmpty())
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"ALERT: diff error 1."_j)->append(static_cast< ::java::lang::Object* >(r1))
            ->append(static_cast< ::java::lang::Object* >(r2))
            ->append(static_cast< ::java::lang::Object* >(d1))
            ->append(static_cast< ::java::lang::Object* >(d2))
            ->append(static_cast< ::java::lang::Object* >(i1))
            ->append(static_cast< ::java::lang::Object* >(i2))->toString());

    if(!npc(i1)->equals(static_cast< ::java::lang::Object* >(i2))) {
        if(npc(d1)->equals(static_cast< ::java::lang::Object* >(d2))) {
            npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"ALERT: diff error 15."_j)->append(static_cast< ::java::lang::Object* >(r1))
                ->append(static_cast< ::java::lang::Object* >(r2))
                ->append(static_cast< ::java::lang::Object* >(d1))
                ->append(static_cast< ::java::lang::Object* >(d2))
                ->append(static_cast< ::java::lang::Object* >(i1))
                ->append(static_cast< ::java::lang::Object* >(i2))->toString());
        }
    }
    auto re1 = d1;
    auto re2 = d2;
    for (auto i = int32_t(0); i < 3; i++) {
        re1 = npc(re1)->merge(d1);
        re1 = npc(re1)->merge(i1);
        re1 = npc(re1)->merge(d2);
        re1 = npc(re1)->merge(i2);
        re2 = npc(re2)->merge(d1);
        re2 = npc(re2)->merge(i1);
        re2 = npc(re2)->merge(d2);
        re2 = npc(re2)->merge(i2);
    }
    auto r12 = npc(r1)->merge(r2);
    if((!npc(re1)->equals(static_cast< ::java::lang::Object* >(r1)) && !npc(re1)->equals(static_cast< ::java::lang::Object* >(r2)) && !npc(re1)->equals(static_cast< ::java::lang::Object* >(r12))) || (!npc(re2)->equals(static_cast< ::java::lang::Object* >(r1)) && !npc(re2)->equals(static_cast< ::java::lang::Object* >(r2)) && !npc(re2)->equals(static_cast< ::java::lang::Object* >(r12))))
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"ALERT: diff error 2."_j)->append(static_cast< ::java::lang::Object* >(r1))
            ->append(static_cast< ::java::lang::Object* >(r2))
            ->append(static_cast< ::java::lang::Object* >(d1))
            ->append(static_cast< ::java::lang::Object* >(d2))
            ->append(static_cast< ::java::lang::Object* >(i1))
            ->append(static_cast< ::java::lang::Object* >(i2))
            ->append(static_cast< ::java::lang::Object* >(re1))
            ->append(static_cast< ::java::lang::Object* >(re2))->toString());

    d1 = npc(r1)->subtract(r2, false);
    d2 = npc(r1)->subtract(r2, true);
    if(!npc(npc(d1)->intersect(i1))->isEmpty() || !npc(npc(d1)->intersect(i2))->isEmpty() || !npc(npc(d2)->intersect(i1))->isEmpty()|| !npc(npc(d2)->intersect(i2))->isEmpty())
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"ALERT: subtract error 1."_j)->append(static_cast< ::java::lang::Object* >(r1))
            ->append(static_cast< ::java::lang::Object* >(r2))
            ->append(static_cast< ::java::lang::Object* >(d1))
            ->append(static_cast< ::java::lang::Object* >(d2))
            ->append(static_cast< ::java::lang::Object* >(i1))
            ->append(static_cast< ::java::lang::Object* >(i2))->toString());

    if((!npc(d1)->isEmpty() && npc(npc(d1)->intersect(r1))->isEmpty()) || (!npc(d2)->isEmpty() && npc(npc(d2)->intersect(r1))->isEmpty()))
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"ALERT: subtract error 2."_j)->append(static_cast< ::java::lang::Object* >(r1))
            ->append(static_cast< ::java::lang::Object* >(r2))
            ->append(static_cast< ::java::lang::Object* >(d1))
            ->append(static_cast< ::java::lang::Object* >(d2))->toString());

    re1 = d1;
    re2 = d2;
    for (auto i = int32_t(0); i < 3; i++) {
        re1 = npc(re1)->merge(d1);
        re1 = npc(re1)->merge(i1);
        re1 = npc(re1)->merge(d2);
        re1 = npc(re1)->merge(i2);
        re2 = npc(re2)->merge(d1);
        re2 = npc(re2)->merge(i1);
        re2 = npc(re2)->merge(d2);
        re2 = npc(re2)->merge(i2);
    }
    r12 = npc(r1)->merge(r2);
    if(!npc(re1)->equals(static_cast< ::java::lang::Object* >(r1)) && !npc(re2)->equals(static_cast< ::java::lang::Object* >(r1)))
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"ALERT: subtract error 25."_j)->append(static_cast< ::java::lang::Object* >(r1))
            ->append(static_cast< ::java::lang::Object* >(r2))
            ->append(static_cast< ::java::lang::Object* >(d1))
            ->append(static_cast< ::java::lang::Object* >(d2))
            ->append(static_cast< ::java::lang::Object* >(i1))
            ->append(static_cast< ::java::lang::Object* >(i2))
            ->append(static_cast< ::java::lang::Object* >(re1))
            ->append(static_cast< ::java::lang::Object* >(re2))->toString());

    d1 = npc(r2)->subtract(r1, false);
    d2 = npc(r2)->subtract(r1, true);
    if(!npc(npc(d1)->intersect(i1))->isEmpty() || !npc(npc(d1)->intersect(i2))->isEmpty() || !npc(npc(d2)->intersect(i1))->isEmpty()|| !npc(npc(d2)->intersect(i2))->isEmpty())
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"ALERT: subtract error 3."_j)->append(static_cast< ::java::lang::Object* >(r1))
            ->append(static_cast< ::java::lang::Object* >(r2))
            ->append(static_cast< ::java::lang::Object* >(d1))
            ->append(static_cast< ::java::lang::Object* >(d2))
            ->append(static_cast< ::java::lang::Object* >(i1))
            ->append(static_cast< ::java::lang::Object* >(i2))->toString());

    if((!npc(d1)->isEmpty() && npc(npc(d1)->intersect(r2))->isEmpty()) || (!npc(d2)->isEmpty() && npc(npc(d2)->intersect(r2))->isEmpty()))
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"ALERT: subtract error 4."_j)->append(static_cast< ::java::lang::Object* >(r1))
            ->append(static_cast< ::java::lang::Object* >(r2))
            ->append(static_cast< ::java::lang::Object* >(d1))
            ->append(static_cast< ::java::lang::Object* >(d2))->toString());

    re1 = d1;
    re2 = d2;
    for (auto i = int32_t(0); i < 3; i++) {
        re1 = npc(re1)->merge(d1);
        re1 = npc(re1)->merge(i1);
        re1 = npc(re1)->merge(d2);
        re1 = npc(re1)->merge(i2);
        re2 = npc(re2)->merge(d1);
        re2 = npc(re2)->merge(i1);
        re2 = npc(re2)->merge(d2);
        re2 = npc(re2)->merge(i2);
    }
    r12 = npc(r1)->merge(r2);
    if(!npc(re1)->equals(static_cast< ::java::lang::Object* >(r2)) && !npc(re2)->equals(static_cast< ::java::lang::Object* >(r2)))
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"ALERT: subtract error 5."_j)->append(static_cast< ::java::lang::Object* >(r1))
            ->append(static_cast< ::java::lang::Object* >(r2))
            ->append(static_cast< ::java::lang::Object* >(d1))
            ->append(static_cast< ::java::lang::Object* >(d2))
            ->append(static_cast< ::java::lang::Object* >(i1))
            ->append(static_cast< ::java::lang::Object* >(i2))
            ->append(static_cast< ::java::lang::Object* >(re1))
            ->append(static_cast< ::java::lang::Object* >(re2))->toString());

}

void rice::pastry::testing::IdRangeUnit::mergeTest(::rice::pastry::IdRange* r1, ::rice::pastry::IdRange* r2)
{
    auto ccw = npc(r1)->ccwHalf();
    auto cw = npc(r1)->cwHalf();
    if(!npc(npc(ccw)->intersect(cw))->isEmpty())
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"ALERT: ccw and cw halves intersect."_j)->append(static_cast< ::java::lang::Object* >(r1))
            ->append(static_cast< ::java::lang::Object* >(ccw))
            ->append(static_cast< ::java::lang::Object* >(cw))->toString());

    if(!npc(r1)->equals(static_cast< ::java::lang::Object* >(npc(ccw)->merge(cw))))
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"ALERT: merge cw/ccw failure."_j)->append(static_cast< ::java::lang::Object* >(r1))
            ->append(static_cast< ::java::lang::Object* >(ccw))
            ->append(static_cast< ::java::lang::Object* >(cw))->toString());

    ccw = npc(r2)->ccwHalf();
    cw = npc(r2)->cwHalf();
    if(!npc(npc(ccw)->intersect(cw))->isEmpty())
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"ALERT: ccw and cw halves intersect."_j)->append(static_cast< ::java::lang::Object* >(r2))
            ->append(static_cast< ::java::lang::Object* >(ccw))
            ->append(static_cast< ::java::lang::Object* >(cw))->toString());

    if(!npc(r2)->equals(static_cast< ::java::lang::Object* >(npc(ccw)->merge(cw))))
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"ALERT: merge cw/ccw failure."_j)->append(static_cast< ::java::lang::Object* >(r2))
            ->append(static_cast< ::java::lang::Object* >(ccw))
            ->append(static_cast< ::java::lang::Object* >(cw))->toString());

}

void rice::pastry::testing::IdRangeUnit::ctor()
{
    super::ctor();
    rng = new ::rice::environment::random::simple::SimpleRandomSource(nullptr);
    npc(::java::lang::System::out())->println(u"IdRangeUnit test starting..."_j);
    halfTest();
    for (auto i = int32_t(0); i < 1000; i++) {
        auto r1 = createEmptyIdRange();
        auto r2 = createEmptyIdRange();
        equalityTest(r1, r2);
        mergeIntersectTest(r1, r2);
        diffSubtractTest(r1, r2);
        mergeTest(r1, r2);
        r2 = createFullIdRange();
        equalityTest(r1, r2);
        mergeIntersectTest(r1, r2);
        diffSubtractTest(r1, r2);
        mergeTest(r1, r2);
        r2 = createRandomIdRange();
        equalityTest(r1, r2);
        mergeIntersectTest(r1, r2);
        diffSubtractTest(r1, r2);
        mergeTest(r1, r2);
        r1 = createFullIdRange();
        equalityTest(r1, r2);
        mergeIntersectTest(r1, r2);
        diffSubtractTest(r1, r2);
        mergeTest(r1, r2);
        r2 = createFullIdRange();
        equalityTest(r1, r2);
        mergeIntersectTest(r1, r2);
        diffSubtractTest(r1, r2);
        mergeTest(r1, r2);
        r2 = createEmptyIdRange();
        equalityTest(r1, r2);
        mergeIntersectTest(r1, r2);
        diffSubtractTest(r1, r2);
        mergeTest(r1, r2);
        r1 = createRandomIdRange();
        equalityTest(r1, r2);
        mergeIntersectTest(r1, r2);
        diffSubtractTest(r1, r2);
        mergeTest(r1, r2);
        r2 = createIdRangeStartingWith(npc(r1)->getCW());
        equalityTest(r1, r2);
        mergeIntersectTest(r1, r2);
        diffSubtractTest(r1, r2);
        mergeTest(r1, r2);
        r2 = createIdRangeStartingWith(npc(r1)->getCCW());
        equalityTest(r1, r2);
        mergeIntersectTest(r1, r2);
        diffSubtractTest(r1, r2);
        mergeTest(r1, r2);
        r2 = createIdRangeEndingIn(npc(r1)->getCW());
        equalityTest(r1, r2);
        mergeIntersectTest(r1, r2);
        diffSubtractTest(r1, r2);
        mergeTest(r1, r2);
        r2 = createIdRangeEndingIn(npc(r1)->getCCW());
        equalityTest(r1, r2);
        mergeIntersectTest(r1, r2);
        diffSubtractTest(r1, r2);
        mergeTest(r1, r2);
        r2 = npc(r1)->complement();
        equalityTest(r1, r2);
        mergeIntersectTest(r1, r2);
        diffSubtractTest(r1, r2);
        mergeTest(r1, r2);
        r1 = createFullIdRange();
        equalityTest(r1, r2);
        mergeIntersectTest(r1, r2);
        diffSubtractTest(r1, r2);
        mergeTest(r1, r2);
        r2 = createIdRangeStartingWith(npc(r1)->getCW());
        equalityTest(r1, r2);
        mergeIntersectTest(r1, r2);
        diffSubtractTest(r1, r2);
        mergeTest(r1, r2);
        r2 = createIdRangeStartingWith(npc(r1)->getCCW());
        equalityTest(r1, r2);
        mergeIntersectTest(r1, r2);
        diffSubtractTest(r1, r2);
        mergeTest(r1, r2);
        r2 = createIdRangeEndingIn(npc(r1)->getCW());
        equalityTest(r1, r2);
        mergeIntersectTest(r1, r2);
        diffSubtractTest(r1, r2);
        mergeTest(r1, r2);
        r2 = createIdRangeEndingIn(npc(r1)->getCCW());
        equalityTest(r1, r2);
        mergeIntersectTest(r1, r2);
        diffSubtractTest(r1, r2);
        mergeTest(r1, r2);
        r1 = createEmptyIdRange();
        equalityTest(r1, r2);
        mergeIntersectTest(r1, r2);
        diffSubtractTest(r1, r2);
        mergeTest(r1, r2);
        r2 = createIdRangeStartingWith(npc(r1)->getCW());
        equalityTest(r1, r2);
        mergeIntersectTest(r1, r2);
        diffSubtractTest(r1, r2);
        mergeTest(r1, r2);
        r2 = createIdRangeStartingWith(npc(r1)->getCCW());
        equalityTest(r1, r2);
        mergeIntersectTest(r1, r2);
        diffSubtractTest(r1, r2);
        mergeTest(r1, r2);
        r2 = createIdRangeEndingIn(npc(r1)->getCW());
        equalityTest(r1, r2);
        mergeIntersectTest(r1, r2);
        diffSubtractTest(r1, r2);
        mergeTest(r1, r2);
        r2 = createIdRangeEndingIn(npc(r1)->getCCW());
        equalityTest(r1, r2);
        mergeIntersectTest(r1, r2);
        diffSubtractTest(r1, r2);
        mergeTest(r1, r2);
        r1 = new ::rice::pastry::IdRange(createIdWithPrefix(static_cast< int8_t >(int32_t(192))), createIdWithPrefix(static_cast< int8_t >(int32_t(64))));
        r2 = new ::rice::pastry::IdRange(createIdWithPrefix(static_cast< int8_t >(int32_t(224))), createIdWithPrefix(static_cast< int8_t >(int32_t(32))));
        equalityTest(r1, r2);
        mergeIntersectTest(r1, r2);
        diffSubtractTest(r1, r2);
        mergeTest(r1, r2);
    }
    npc(::java::lang::System::out())->println(u"IdRangeUnit test finished."_j);
}

void rice::pastry::testing::IdRangeUnit::main(::java::lang::StringArray* args)
{
    clinit();
    auto niu = new IdRangeUnit();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::testing::IdRangeUnit::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.testing.IdRangeUnit", 31);
    return c;
}

java::lang::Class* rice::pastry::testing::IdRangeUnit::getClass0()
{
    return class_();
}

