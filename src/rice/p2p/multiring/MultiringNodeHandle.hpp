// Generated from /pastry-2.1/src/rice/p2p/multiring/MultiringNodeHandle.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/p2p/multiring/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/NodeHandle.hpp>
#include <java/util/Observer.hpp>

struct default_init_tag;

class rice::p2p::multiring::MultiringNodeHandle
    : public ::rice::p2p::commonapi::NodeHandle
    , public virtual ::java::util::Observer
{

public:
    typedef ::rice::p2p::commonapi::NodeHandle super;

public: /* package */
    static constexpr int64_t serialVersionUID { int64_t(-2972303779251779984LL) };

public: /* protected */
    ::rice::p2p::commonapi::NodeHandle* handle {  };
    ::rice::p2p::commonapi::Id* ringId {  };
protected:
    void ctor(::rice::p2p::commonapi::Id* ringId, ::rice::p2p::commonapi::NodeHandle* handle);

public: /* protected */
    virtual ::rice::p2p::commonapi::NodeHandle* getHandle();

public:
    virtual ::rice::p2p::commonapi::Id* getRingId();
    ::rice::p2p::commonapi::Id* getId() override;
    bool isAlive() override;
    int32_t proximity() override;
    void update(::java::util::Observable* o, ::java::lang::Object* obj) override;
    ::java::lang::String* toString() override;
    bool equals(::java::lang::Object* o) override;
    int32_t hashCode() override;

private:
    void readObject(::java::io::ObjectInputStream* ois) /* throws(IOException, ClassNotFoundException) */;

public:
    bool checkLiveness() override;
protected:
    void ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint) /* throws(IOException) */;

public:
    void serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */ override;

    // Generated
    MultiringNodeHandle(::rice::p2p::commonapi::Id* ringId, ::rice::p2p::commonapi::NodeHandle* handle);
    MultiringNodeHandle(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint);
protected:
    MultiringNodeHandle(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
