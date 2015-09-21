// Generated from /pastry-2.1/src/rice/pastry/peerreview/FetchLeafsetApp.java

#pragma once

#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/peerreview/fwd-pastry-2.1.hpp>
#include <rice/selector/TimerTask.hpp>

struct default_init_tag;

class rice::pastry::peerreview::FetchLeafsetApp_getNeighbors_2
    : public ::rice::selector::TimerTask
{

public:
    typedef ::rice::selector::TimerTask super;
    void run() override;

    // Generated
    FetchLeafsetApp_getNeighbors_2(FetchLeafsetApp *FetchLeafsetApp_this, ::rice::pastry::Id* subject);
    static ::java::lang::Class *class_();
    FetchLeafsetApp *FetchLeafsetApp_this;
    ::rice::pastry::Id* subject;

private:
    virtual ::java::lang::Class* getClass0();
    friend class FetchLeafsetApp;
    friend class FetchLeafsetApp_FetchLeafsetApp_1;
};
