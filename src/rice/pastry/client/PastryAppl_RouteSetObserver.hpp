// Generated from /pastry-2.1/src/rice/pastry/client/PastryAppl.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/client/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/pastry/NodeSetListener.hpp>

struct default_init_tag;

class rice::pastry::client::PastryAppl_RouteSetObserver
    : public virtual ::java::lang::Object
    , public virtual ::rice::pastry::NodeSetListener
{

public:
    typedef ::java::lang::Object super;
    void nodeSetUpdate(::rice::pastry::NodeSetEventSource* nodeSetEventSource, ::rice::pastry::NodeHandle* handle, bool added) override;

    // Generated
    PastryAppl_RouteSetObserver(PastryAppl *PastryAppl_this);
protected:
    PastryAppl_RouteSetObserver(PastryAppl *PastryAppl_this, const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    PastryAppl *PastryAppl_this;

private:
    virtual ::java::lang::Class* getClass0();
    friend class PastryAppl;
    friend class PastryAppl_LeafSetObserver;
    friend class PastryAppl_routeMsg_1;
    friend class PastryAppl_routeMsg_2;
};
