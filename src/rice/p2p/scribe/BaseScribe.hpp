// Generated from /pastry-2.1/src/rice/p2p/scribe/BaseScribe.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/scribe/fwd-pastry-2.1.hpp>
#include <rice/Destructable.hpp>

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

    namespace util
    {
typedef ::SubArray< ::java::util::Observable, ::java::lang::ObjectArray > ObservableArray;
    } // util
} // java

namespace rice
{
    namespace p2p
    {
        namespace commonapi
        {
typedef ::SubArray< ::rice::p2p::commonapi::NodeHandle, ::java::util::ObservableArray, ::java::io::SerializableArray > NodeHandleArray;
        } // commonapi

        namespace scribe
        {
typedef ::SubArray< ::rice::p2p::scribe::Topic, ::java::lang::ObjectArray, ::java::io::SerializableArray, ::java::lang::ComparableArray > TopicArray;
        } // scribe
    } // p2p
} // rice

struct rice::p2p::scribe::BaseScribe
    : public virtual ::rice::Destructable
{
    virtual void subscribe(Topic* topic, ScribeClient* client) = 0;
    virtual void unsubscribe(Topic* topic, ScribeClient* client) = 0;
    virtual void unsubscribe(Topic* topic, ScribeMultiClient* client) = 0;
    virtual void unsubscribe(::java::util::Collection* topicsToUnsubscribe, ScribeMultiClient* client) = 0;
    virtual void addChild(Topic* topic, ::rice::p2p::commonapi::NodeHandle* child) = 0;
    virtual void removeChild(Topic* topic, ::rice::p2p::commonapi::NodeHandle* child) = 0;
    virtual bool isRoot(Topic* topic) = 0;
    virtual ::rice::p2p::commonapi::NodeHandle* getRoot(Topic* topic) = 0;
    virtual ::rice::p2p::commonapi::NodeHandleArray* getChildren(Topic* topic) = 0;
    virtual ::java::util::Collection* getChildrenOfTopic(Topic* topic) = 0;
    virtual ::rice::p2p::commonapi::NodeHandle* getParent(Topic* topic) = 0;
    virtual TopicArray* getTopics(ScribeClient* client) = 0;
    virtual ::java::util::Collection* getTopicsByClient(ScribeClient* client) = 0;
    virtual ::java::util::Collection* getTopicsByClient(ScribeMultiClient* client) = 0;
    virtual int32_t numChildren(Topic* topic) = 0;
    virtual ::java::util::Collection* getClients(Topic* topic) = 0;
    virtual ::java::util::Collection* getClientsByTopic(Topic* topic) = 0;
    virtual bool containsTopic(Topic* topic) = 0;
    virtual bool containsChild(Topic* topic, ::rice::p2p::commonapi::NodeHandle* child) = 0;
    virtual ScribePolicy* getPolicy() = 0;
    virtual void setPolicy(ScribePolicy* policy) = 0;
    virtual ::rice::environment::Environment* getEnvironment() = 0;

    // Generated
    static ::java::lang::Class *class_();
};
