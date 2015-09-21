// Generated from /pastry-2.1/src/rice/p2p/scribe/ScribeImpl.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/scribe/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct default_init_tag;

class rice::p2p::scribe::ScribeImpl_TopicManager
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;

public: /* protected */
    Topic* topic {  };
    ::java::util::List* pathToRoot {  };
    ::java::util::ArrayList* clients {  };
    ::java::util::ArrayList* children {  };
    ::rice::p2p::commonapi::NodeHandle* parent {  };
protected:
    void ctor(Topic* topic);

public:
    virtual Topic* getTopic();
    virtual ::rice::p2p::commonapi::NodeHandle* getParent();
    virtual ::java::util::Collection* getClients();
    virtual bool containsClient(ScribeMultiClient* client);
    virtual ::java::util::Collection* getChildren();
    virtual int32_t numChildren();
    virtual ::java::util::List* getPathToRoot();
    virtual void setPathToRoot(::java::util::List* pathToRoot);
    virtual void setParent(::rice::p2p::commonapi::NodeHandle* handle, ::java::util::List* pathToRoot);
    ::java::lang::String* toString() override;
    virtual void addClient(ScribeMultiClient* client);
    virtual bool removeClient(ScribeMultiClient* client);
    virtual bool containsChild(::rice::p2p::commonapi::NodeHandle* child);
    virtual void addChild(::rice::p2p::commonapi::NodeHandle* child);
    virtual bool removeChild(::rice::p2p::commonapi::NodeHandle* child);

    // Generated

private:
    ScribeImpl_TopicManager(ScribeImpl *ScribeImpl_this, Topic* topic);
protected:
    ScribeImpl_TopicManager(ScribeImpl *ScribeImpl_this, const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    ScribeImpl *ScribeImpl_this;

private:
    virtual ::java::lang::Class* getClass0();
    friend class ScribeImpl;
    friend class ScribeImpl_ScribeImpl_1;
    friend class ScribeImpl_ScribeClientConverter;
    friend class ScribeImpl_destroy_2;
};
