// Generated from /pastry-2.1/src/rice/pastry/peerreview/FetchLeafsetApp.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/messaging/fwd-pastry-2.1.hpp>
#include <rice/pastry/peerreview/fwd-pastry-2.1.hpp>
#include <rice/pastry/client/PastryAppl.hpp>

struct default_init_tag;

class rice::pastry::peerreview::FetchLeafsetApp
    : public ::rice::pastry::client::PastryAppl
{

public:
    typedef ::rice::pastry::client::PastryAppl super;
    static constexpr int32_t APP_ID { int32_t(-133359640) };

public: /* protected */
    ::java::util::Map* pendingLookups {  };
    int32_t numNeighbors {  };
    int8_t routeMsgVersion {  };
protected:
    void ctor(::rice::pastry::PastryNode* pn, int32_t numNeighbors);

public:
    void messageForAppl(::rice::pastry::messaging::Message* msg) override;

public: /* protected */
    virtual void handleResponse(FetchLeafsetResponse* response);

public:
    virtual void getNeighbors(::rice::pastry::Id* subject, ::rice::Continuation* continuation);

    // Generated
    FetchLeafsetApp(::rice::pastry::PastryNode* pn, int32_t numNeighbors);
protected:
    FetchLeafsetApp(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    void init();
    virtual ::java::lang::Class* getClass0();
    friend class FetchLeafsetApp_FetchLeafsetApp_1;
    friend class FetchLeafsetApp_getNeighbors_2;
};
