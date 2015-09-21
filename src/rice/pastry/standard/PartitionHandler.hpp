// Generated from /pastry-2.1/src/rice/pastry/standard/PartitionHandler.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/net/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/socket/fwd-pastry-2.1.hpp>
#include <rice/pastry/standard/fwd-pastry-2.1.hpp>
#include <rice/selector/fwd-pastry-2.1.hpp>
#include <rice/selector/TimerTask.hpp>
#include <rice/pastry/NodeSetListener.hpp>

template<typename ComponentType, typename... Bases> struct SubArray;
namespace java
{
    namespace io
    {
typedef ::SubArray< ::java::io::Serializable, ::java::lang::ObjectArray > SerializableArray;
    } // io

    namespace net
    {
typedef ::SubArray< ::java::net::SocketAddress, ::java::lang::ObjectArray, ::java::io::SerializableArray > SocketAddressArray;
typedef ::SubArray< ::java::net::InetSocketAddress, SocketAddressArray > InetSocketAddressArray;
    } // net
} // java

struct default_init_tag;

class rice::pastry::standard::PartitionHandler
    : public ::rice::selector::TimerTask
    , public virtual ::rice::pastry::NodeSetListener
{

public:
    typedef ::rice::selector::TimerTask super;

public: /* protected */
    ::rice::pastry::PastryNode* pastryNode {  };
    ::java::net::InetSocketAddressArray* bootstraps {  };
    ::rice::pastry::socket::SocketPastryNodeFactory* factory {  };
    ::rice::environment::logging::Logger* logger {  };
    double bootstrapRate {  };
    int32_t maxGoneSize {  };
    int32_t maxGoneAge {  };
    ::java::util::Map* gone {  };
    ::rice::environment::Environment* env {  };
protected:
    void ctor(::rice::pastry::PastryNode* pn, ::rice::pastry::socket::SocketPastryNodeFactory* factory, ::java::net::InetSocketAddressArray* bootstraps);

private:
    void doGoneMaintainence();
    ::java::util::List* getRoutingTableAsList();

public:
    virtual ::rice::pastry::NodeHandle* getCandidateNode();

private:
    void getNodeHandleToProbe(::rice::Continuation* c);

public:
    void run() override;
    void nodeSetUpdate(::rice::pastry::NodeSetEventSource* nodeSetEventSource, ::rice::pastry::NodeHandle* handle, bool added) override;
    virtual void start(::rice::selector::Timer* timer);
    virtual void rejoin(::rice::pastry::NodeHandle* target);

    // Generated
    PartitionHandler(::rice::pastry::PastryNode* pn, ::rice::pastry::socket::SocketPastryNodeFactory* factory, ::java::net::InetSocketAddressArray* bootstraps);
protected:
    PartitionHandler(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
    friend class PartitionHandler_run_1;
    friend class PartitionHandler_GoneSetEntry;
};
