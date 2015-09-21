// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/replay/record/RecordLayer.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/replay/record/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/environment/exception/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <rice/environment/params/fwd-pastry-2.1.hpp>
#include <rice/environment/processing/fwd-pastry-2.1.hpp>
#include <rice/environment/random/fwd-pastry-2.1.hpp>
#include <rice/environment/time/fwd-pastry-2.1.hpp>
#include <rice/selector/fwd-pastry-2.1.hpp>
#include <rice/environment/Environment.hpp>

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

struct default_init_tag;

class org::mpisws::p2p::transport::peerreview::replay::record::RecordLayer_generateEnvironment_2
    : public ::rice::environment::Environment
{

public:
    typedef ::rice::environment::Environment super;
    ::rice::environment::Environment* cloneEnvironment(::java::lang::String* prefix, bool cloneSelector, bool cloneProcessor) override;
    ::rice::environment::Environment* cloneEnvironment(::java::lang::String* prefix) override;

public: /* protected */
    ::rice::selector::SelectorManager* cloneSelectorManager(::java::lang::String* prefix, ::rice::environment::time::TimeSource* ts, ::rice::environment::random::RandomSource* rs, ::rice::environment::logging::LogManager* lman, bool cloneSelector) override;
    ::rice::environment::time::TimeSource* cloneTimeSource(::rice::environment::logging::LogManager* manager) override;

    // Generated

public:
    RecordLayer_generateEnvironment_2(::rice::selector::SelectorManager* sm, ::rice::environment::processing::Processor* proc, ::rice::environment::random::RandomSource* rs, ::rice::environment::time::TimeSource* time, ::rice::environment::logging::LogManager* lm, ::rice::environment::params::Parameters* params, ::rice::environment::exception::ExceptionStrategy* strategy);
    RecordLayer_generateEnvironment_2(::java::lang::StringArray* orderedDefaultFiles, ::java::lang::String* paramFileName);
    RecordLayer_generateEnvironment_2(::java::lang::String* paramFileName);
    RecordLayer_generateEnvironment_2();
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
    friend class RecordLayer;
    friend class RecordLayer_openSocket_1;
};
