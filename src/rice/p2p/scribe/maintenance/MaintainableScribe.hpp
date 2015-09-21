// Generated from /pastry-2.1/src/rice/p2p/scribe/maintenance/MaintainableScribe.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/scribe/fwd-pastry-2.1.hpp>
#include <rice/p2p/scribe/maintenance/fwd-pastry-2.1.hpp>
#include <rice/p2p/scribe/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/p2p/scribe/BaseScribe.hpp>

template<typename ComponentType, typename... Bases> struct SubArray;
namespace java
{
    namespace io
    {
typedef ::SubArray< ::java::io::Serializable, ::java::lang::ObjectArray > SerializableArray;
    } // io

    namespace lang
    {
typedef ::SubArray< ::java::lang::Comparable, ObjectArray > ComparableArray;
    } // lang
} // java

namespace rice
{
    namespace p2p
    {
        namespace scribe
        {
typedef ::SubArray< ::rice::p2p::scribe::Topic, ::java::lang::ObjectArray, ::java::io::SerializableArray, ::java::lang::ComparableArray > TopicArray;
        } // scribe
    } // p2p
} // rice

struct rice::p2p::scribe::maintenance::MaintainableScribe
    : public virtual ::rice::p2p::scribe::BaseScribe
{
    static constexpr int32_t MAINTENANCE_ID { int32_t(2147483647) };
    virtual ::java::util::Collection* getTopics() = 0;
    virtual ::rice::p2p::commonapi::Endpoint* getEndpoint() = 0;
    virtual ::java::util::Collection* getTopicsByParent(::rice::p2p::commonapi::NodeHandle* parent) = 0;
    virtual ::java::util::Collection* getTopicsByChild(::rice::p2p::commonapi::NodeHandle* child) = 0;
    virtual void subscribe(::java::util::Collection* nodeWasParent, ::rice::p2p::scribe::ScribeMultiClient* client, ::rice::p2p::scribe::rawserialization::RawScribeContent* content, ::rice::p2p::commonapi::NodeHandle* hint) = 0;
    virtual void setParent(::rice::p2p::scribe::Topic* topic, ::rice::p2p::commonapi::NodeHandle* parent, ::java::util::List* pathToRoot) = 0;
    virtual ::java::util::List* getPathToRoot(::rice::p2p::scribe::Topic* topic) = 0;

    // Generated
    static ::java::lang::Class *class_();
    virtual ::rice::p2p::scribe::TopicArray* getTopics(::rice::p2p::scribe::ScribeClient* client) = 0;
    virtual void subscribe(::rice::p2p::scribe::Topic* topic, ::rice::p2p::scribe::ScribeClient* client) = 0;
};
