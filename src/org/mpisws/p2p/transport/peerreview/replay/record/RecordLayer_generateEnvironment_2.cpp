// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/replay/record/RecordLayer.java
#include <org/mpisws/p2p/transport/peerreview/replay/record/RecordLayer_generateEnvironment_2.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/RuntimeException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <org/mpisws/p2p/transport/peerreview/replay/record/RecordSM.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/CloneableLogManager.hpp>
#include <rice/environment/logging/LogManager.hpp>
#include <rice/environment/processing/Processor.hpp>
#include <rice/environment/random/RandomSource.hpp>
#include <rice/environment/time/TimeSource.hpp>
#include <rice/environment/time/simple/SimpleTimeSource.hpp>
#include <rice/environment/time/simulated/DirectTimeSource.hpp>
#include <rice/selector/SelectorManager.hpp>

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

org::mpisws::p2p::transport::peerreview::replay::record::RecordLayer_generateEnvironment_2::RecordLayer_generateEnvironment_2(::rice::selector::SelectorManager* sm, ::rice::environment::processing::Processor* proc, ::rice::environment::random::RandomSource* rs, ::rice::environment::time::TimeSource* time, ::rice::environment::logging::LogManager* lm, ::rice::environment::params::Parameters* params, ::rice::environment::exception::ExceptionStrategy* strategy)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
    ctor(sm, proc, rs, time, lm, params, strategy);
}

org::mpisws::p2p::transport::peerreview::replay::record::RecordLayer_generateEnvironment_2::RecordLayer_generateEnvironment_2(::java::lang::StringArray* orderedDefaultFiles, ::java::lang::String* paramFileName)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
    ctor(orderedDefaultFiles, paramFileName);
}

org::mpisws::p2p::transport::peerreview::replay::record::RecordLayer_generateEnvironment_2::RecordLayer_generateEnvironment_2(::java::lang::String* paramFileName)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
    ctor(paramFileName);
}

org::mpisws::p2p::transport::peerreview::replay::record::RecordLayer_generateEnvironment_2::RecordLayer_generateEnvironment_2()
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
    ctor();
}

rice::environment::Environment* org::mpisws::p2p::transport::peerreview::replay::record::RecordLayer_generateEnvironment_2::cloneEnvironment(::java::lang::String* prefix, bool cloneSelector, bool cloneProcessor)
{
    auto dts = new ::rice::environment::time::simulated::DirectTimeSource(npc(getTimeSource())->currentTimeMillis());
    auto lman = getLogManager();
    if(dynamic_cast< ::rice::environment::logging::CloneableLogManager* >(lman) != nullptr) {
        lman = npc((java_cast< ::rice::environment::logging::CloneableLogManager* >(getLogManager())))->clone(prefix, dts);
    }
    npc(dts)->setLogManager(lman);
    auto rand = cloneRandomSource(lman);
    auto sman = cloneSelectorManager(prefix, static_cast< ::rice::environment::time::TimeSource* >(dts), rand, lman, cloneSelector);
    auto proc = static_cast< ::rice::environment::Environment* >(this)->cloneProcessor(prefix, lman, cloneProcessor);
    auto ret = new ::rice::environment::Environment(sman, proc, rand, dts, lman, getParameters(), getExceptionStrategy());
    addDestructable(ret);
    return ret;
}

rice::environment::Environment* org::mpisws::p2p::transport::peerreview::replay::record::RecordLayer_generateEnvironment_2::cloneEnvironment(::java::lang::String* prefix)
{
    return cloneEnvironment(prefix, true, true);
}

rice::selector::SelectorManager* org::mpisws::p2p::transport::peerreview::replay::record::RecordLayer_generateEnvironment_2::cloneSelectorManager(::java::lang::String* prefix, ::rice::environment::time::TimeSource* ts, ::rice::environment::random::RandomSource* rs, ::rice::environment::logging::LogManager* lman, bool cloneSelector)
{
    auto sman = getSelectorManager();
    if(cloneSelector) {
        sman = new RecordSM(::java::lang::StringBuilder().append(prefix)->append(u" Selector"_j)->toString(), new ::rice::environment::time::simple::SimpleTimeSource(), java_cast< ::rice::environment::time::simulated::DirectTimeSource* >(ts), lman, rs);
    }
    return sman;
}

rice::environment::time::TimeSource* org::mpisws::p2p::transport::peerreview::replay::record::RecordLayer_generateEnvironment_2::cloneTimeSource(::rice::environment::logging::LogManager* manager)
{
    throw new ::java::lang::RuntimeException(u"Operation not allowed.  Use the overridden clone method."_j);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::peerreview::replay::record::RecordLayer_generateEnvironment_2::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::peerreview::replay::record::RecordLayer_generateEnvironment_2::getClass0()
{
    return class_();
}

