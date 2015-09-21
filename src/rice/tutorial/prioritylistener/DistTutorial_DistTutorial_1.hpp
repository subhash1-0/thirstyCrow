// Generated from /pastry-2.1/src/rice/tutorial/prioritylistener/DistTutorial.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/multiaddress/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/tutorial/prioritylistener/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/priority/PriorityTransportLayerListener.hpp>

struct default_init_tag;

class rice::tutorial::prioritylistener::DistTutorial_DistTutorial_1
    : public virtual ::java::lang::Object
    , public virtual ::org::mpisws::p2p::transport::priority::PriorityTransportLayerListener
{

public:
    typedef ::java::lang::Object super;
    virtual void wrote(int32_t bytes, ::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* i, ::java::util::Map* options, bool passthrough, bool socket);
    virtual void read(int32_t bytes, ::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* i, ::java::util::Map* options, bool passthrough, bool socket);
    virtual void enqueued(int32_t bytes, ::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* i, ::java::util::Map* options, bool passthrough, bool socket);
    virtual void dropped(int32_t bytes, ::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* i, ::java::util::Map* options, bool passthrough, bool socket);

    // Generated
    DistTutorial_DistTutorial_1(DistTutorial *DistTutorial_this, ::rice::pastry::PastryNode* node);
    static ::java::lang::Class *class_();
    virtual void dropped(int32_t bytes, ::java::lang::Object* i, ::java::util::Map* options, bool passthrough, bool socket) override;
    virtual void enqueued(int32_t bytes, ::java::lang::Object* i, ::java::util::Map* options, bool passthrough, bool socket) override;
    virtual void read(int32_t bytes, ::java::lang::Object* i, ::java::util::Map* options, bool passthrough, bool socket) override;
    virtual void wrote(int32_t bytes, ::java::lang::Object* i, ::java::util::Map* options, bool passthrough, bool socket) override;
    DistTutorial *DistTutorial_this;
    ::rice::pastry::PastryNode* node;

private:
    virtual ::java::lang::Class* getClass0();
    friend class DistTutorial;
};
