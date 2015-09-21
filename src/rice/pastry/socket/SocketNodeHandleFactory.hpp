// Generated from /pastry-2.1/src/rice/pastry/socket/SocketNodeHandleFactory.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/multiaddress/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/socket/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/pastry/NodeHandleFactory.hpp>
#include <org/mpisws/p2p/transport/util/Serializer.hpp>
#include <rice/pastry/socket/SocketNodeHandle.hpp>

struct default_init_tag;

class rice::pastry::socket::SocketNodeHandleFactory
    : public virtual ::java::lang::Object
    , public virtual ::rice::pastry::NodeHandleFactory
    , public virtual ::org::mpisws::p2p::transport::util::Serializer
{

public:
    typedef ::java::lang::Object super;

public: /* protected */
    ::rice::pastry::PastryNode* pn {  };
    ::java::util::Map* handleSet {  };
    ::java::util::Collection* listeners {  };

public: /* package */
    ::rice::environment::logging::Logger* logger {  };
protected:
    void ctor(::rice::pastry::PastryNode* pn);

public:
    virtual SocketNodeHandle* getNodeHandle(::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* i, int64_t epoch, ::rice::pastry::Id* id);
    SocketNodeHandle* readNodeHandle(::rice::p2p::commonapi::rawserialization::InputBuffer* buf) /* throws(IOException) */ override;
    virtual SocketNodeHandle* coalesce(SocketNodeHandle* h);

public: /* protected */
    virtual void notifyListeners(SocketNodeHandle* nh);

public:
    void addNodeHandleFactoryListener(::rice::pastry::NodeHandleFactoryListener* listener) override;
    void removeNodeHandleFactoryListener(::rice::pastry::NodeHandleFactoryListener* listener) override;
    SocketNodeHandle* deserialize(::rice::p2p::commonapi::rawserialization::InputBuffer* buf) /* throws(IOException) */ override;
    virtual void serialize(SocketNodeHandle* i, ::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */;

    // Generated
    SocketNodeHandleFactory(::rice::pastry::PastryNode* pn);
protected:
    SocketNodeHandleFactory(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    void init();

public:
    virtual ::rice::pastry::NodeHandle* coalesce(::rice::pastry::NodeHandle* handle) override;
    virtual void serialize(::java::lang::Object* i, ::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) override;

private:
    virtual ::java::lang::Class* getClass0();
};
