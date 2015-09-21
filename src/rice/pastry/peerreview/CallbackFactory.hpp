// Generated from /pastry-2.1/src/rice/pastry/peerreview/CallbackFactory.java

#pragma once

#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/peerreview/fwd-pastry-2.1.hpp>
#include <rice/pastry/transport/fwd-pastry-2.1.hpp>
#include <rice/pastry/socket/SocketPastryNodeFactory.hpp>

struct default_init_tag;

class rice::pastry::peerreview::CallbackFactory
    : public ::rice::pastry::socket::SocketPastryNodeFactory
{

public:
    typedef ::rice::pastry::socket::SocketPastryNodeFactory super;
    ::java::util::Map* localHandleTable {  };
protected:
    void ctor(::rice::environment::Environment* env) /* throws(IOException) */;

public:
    ::rice::pastry::transport::NodeHandleAdapter* getNodeHandleAdapter(::rice::pastry::PastryNode* pn, ::rice::pastry::NodeHandleFactory* handleFactory2, ::rice::pastry::transport::TLDeserializer* deserializer) /* throws(IOException) */ override;
    ::rice::pastry::NodeHandle* getLocalHandle(::rice::pastry::PastryNode* pn, ::rice::pastry::NodeHandleFactory* nhf) override;

    // Generated
    CallbackFactory(::rice::environment::Environment* env);
protected:
    CallbackFactory(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
