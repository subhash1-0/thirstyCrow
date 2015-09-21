// Generated from /pastry-2.1/src/org/mpisws/p2p/testing/transportlayer/replay/MyScribeClient.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/testing/transportlayer/replay/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/scribe/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/p2p/scribe/ScribeClient.hpp>
#include <rice/p2p/commonapi/Application.hpp>

template<typename ComponentType, typename... Bases> struct SubArray;
namespace java
{
    namespace io
    {
typedef ::SubArray< ::java::io::Serializable, ::java::lang::ObjectArray > SerializableArray;
    } // io

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
    } // p2p
} // rice

struct default_init_tag;

class org::mpisws::p2p::testing::transportlayer::replay::MyScribeClient
    : public virtual ::java::lang::Object
    , public virtual ::rice::p2p::scribe::ScribeClient
    , public virtual ::rice::p2p::commonapi::Application
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    int32_t seqNum {  };
    ::rice::p2p::commonapi::CancellableTask* publishTask {  };
    ::rice::p2p::scribe::Scribe* myScribe {  };
    ::rice::p2p::scribe::Topic* myTopic {  };
    ::rice::p2p::commonapi::Node* node {  };

public: /* protected */
    ::rice::p2p::commonapi::Endpoint* endpoint {  };
    ::rice::environment::logging::Logger* logger {  };
protected:
    void ctor(::rice::p2p::commonapi::Node* node);

public:
    virtual void subscribe();
    virtual void startPublishTask();
    void deliver(::rice::p2p::commonapi::Id* id, ::rice::p2p::commonapi::Message* message) override;
    virtual void sendMulticast();
    void deliver(::rice::p2p::scribe::Topic* topic, ::rice::p2p::scribe::ScribeContent* content) override;
    virtual void sendAnycast();
    bool anycast(::rice::p2p::scribe::Topic* topic, ::rice::p2p::scribe::ScribeContent* content) override;
    void childAdded(::rice::p2p::scribe::Topic* topic, ::rice::p2p::commonapi::NodeHandle* child) override;
    void childRemoved(::rice::p2p::scribe::Topic* topic, ::rice::p2p::commonapi::NodeHandle* child) override;
    void subscribeFailed(::rice::p2p::scribe::Topic* topic) override;
    bool forward(::rice::p2p::commonapi::RouteMessage* message) override;
    void update(::rice::p2p::commonapi::NodeHandle* handle, bool joined) override;
    virtual bool isRoot();
    virtual ::rice::p2p::commonapi::NodeHandle* getParent();
    virtual ::rice::p2p::commonapi::NodeHandleArray* getChildren();

    // Generated
    MyScribeClient(::rice::p2p::commonapi::Node* node);
protected:
    MyScribeClient(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    void init();
    virtual ::java::lang::Class* getClass0();
    friend class MyScribeClient_PublishContent;
};
