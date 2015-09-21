// Generated from /pastry-2.1/src/rice/p2p/scribe/ScribeImpl.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/ref/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/scribe/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/p2p/scribe/ScribeMultiClient.hpp>

struct default_init_tag;

class rice::p2p::scribe::ScribeImpl_ScribeClientConverter
    : public virtual ::java::lang::Object
    , public virtual ScribeMultiClient
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    ::java::lang::ref::WeakReference* client {  };
protected:
    void ctor(ScribeClient* client);

public:
    void subscribeFailed(::java::util::Collection* topics) override;
    void subscribeSuccess(::java::util::Collection* topics) override;
    bool anycast(Topic* topic, ScribeContent* content) override;
    void childAdded(Topic* topic, ::rice::p2p::commonapi::NodeHandle* child) override;
    void childRemoved(Topic* topic, ::rice::p2p::commonapi::NodeHandle* child) override;
    void deliver(Topic* topic, ScribeContent* content) override;
    void subscribeFailed(Topic* topic) override;

    // Generated
    ScribeImpl_ScribeClientConverter(ScribeClient* client);
protected:
    ScribeImpl_ScribeClientConverter(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
    friend class ScribeImpl;
    friend class ScribeImpl_ScribeImpl_1;
    friend class ScribeImpl_TopicManager;
    friend class ScribeImpl_destroy_2;
};
