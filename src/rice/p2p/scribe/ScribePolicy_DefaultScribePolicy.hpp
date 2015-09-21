// Generated from /pastry-2.1/src/rice/p2p/scribe/ScribePolicy.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/scribe/fwd-pastry-2.1.hpp>
#include <rice/p2p/scribe/messaging/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/p2p/scribe/ScribePolicy.hpp>

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

        namespace scribe
        {
typedef ::SubArray< ::rice::p2p::scribe::ScribeClient, ::java::lang::ObjectArray > ScribeClientArray;
        } // scribe
    } // p2p
} // rice

struct default_init_tag;

class rice::p2p::scribe::ScribePolicy_DefaultScribePolicy
    : public virtual ::java::lang::Object
    , public virtual ScribePolicy
{

public:
    typedef ::java::lang::Object super;

public: /* protected */
    ::rice::environment::Environment* environment {  };
protected:
    void ctor(::rice::environment::Environment* env);

public:
    ::java::util::List* allowSubscribe(Scribe* scribe, ::rice::p2p::commonapi::NodeHandle* source, ::java::util::List* topics, ScribeContent* content) override;
    virtual bool allowSubscribe(::rice::p2p::scribe::messaging::SubscribeMessage* message, ScribeClientArray* clients, ::rice::p2p::commonapi::NodeHandleArray* children);
    void directAnycast(::rice::p2p::scribe::messaging::AnycastMessage* message, ::rice::p2p::commonapi::NodeHandle* parent, ::java::util::Collection* theChildren) override;
    void childAdded(Topic* topic, ::rice::p2p::commonapi::NodeHandle* child) override;
    void childRemoved(Topic* topic, ::rice::p2p::commonapi::NodeHandle* child) override;
    void intermediateNode(::rice::p2p::scribe::messaging::ScribeMessage* message) override;
    void recvAnycastFail(Topic* topic, ::rice::p2p::commonapi::NodeHandle* failedAtNode, ScribeContent* content) override;
    ScribeContent* divideContent(::java::util::List* theTopics, ScribeContent* content) override;

    // Generated
    ScribePolicy_DefaultScribePolicy(::rice::environment::Environment* env);
protected:
    ScribePolicy_DefaultScribePolicy(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
    friend class ScribePolicy;
    friend class ScribePolicy_DefaultScribePolicy_BogusSubscribeMessage;
    friend class ScribePolicy_LimitedScribePolicy;
};
