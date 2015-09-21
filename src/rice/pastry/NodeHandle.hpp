// Generated from /pastry-2.1/src/rice/pastry/NodeHandle.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/messaging/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/NodeHandle.hpp>
#include <rice/p2p/commonapi/rawserialization/RawSerializable.hpp>

struct default_init_tag;

class rice::pastry::NodeHandle
    : public ::rice::p2p::commonapi::NodeHandle
    , public virtual ::rice::p2p::commonapi::rawserialization::RawSerializable
{

public:
    typedef ::rice::p2p::commonapi::NodeHandle super;
    static constexpr int32_t LIVENESS_ALIVE { int32_t(1) };
    static constexpr int32_t LIVENESS_SUSPECTED { int32_t(2) };
    static constexpr int32_t LIVENESS_DEAD { int32_t(3) };

public: /* protected */
    PastryNode* localnode {  };
    ::rice::environment::logging::Logger* logger {  };

public: /* package */
    static constexpr int64_t serialVersionUID { int64_t(987479397660721015LL) };

public:
    virtual Id* getNodeId() = 0;
    ::rice::p2p::commonapi::Id* getId() override;
    bool isAlive() override;
    virtual int32_t getLiveness() = 0;
    bool checkLiveness() override;
    int32_t proximity() = 0;
    virtual bool ping() = 0;
    PastryNode* getLocalNode();
    virtual void assertLocalNode();
    /*bool equals(::java::lang::Object* obj); (already declared) */
    virtual void bootstrap(::rice::pastry::messaging::Message* msg) /* throws(IOException) */;
    /*int32_t hashCode(); (already declared) */
    virtual void receiveMessage(::rice::pastry::messaging::Message* msg) = 0;
    /*void serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf); (already declared) */

public: /* package */
    ::java::util::List* obs {  };

private:
    void readObject(::java::io::ObjectInputStream* in) /* throws(IOException, ClassNotFoundException) */;

public:
    void addObserver(::java::util::Observer* o) override;
    virtual void addObserver(::java::util::Observer* o, int32_t priority);
    void deleteObserver(::java::util::Observer* o) override;
    void notifyObservers(::java::lang::Object* arg) override;
    int32_t countObservers() override;
    void deleteObservers() override;
    virtual void update(::java::lang::Object* update);

    // Generated
    NodeHandle();
protected:
    void ctor();
    NodeHandle(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    void init();

public:
    virtual void notifyObservers();

private:
    virtual ::java::lang::Class* getClass0();
    friend class NodeHandle_ObsPri;
};
