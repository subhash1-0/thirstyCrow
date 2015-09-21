// Generated from /pastry-2.1/lib/sbbi-upnplib-1.0.4.jar

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <net/sbbi/upnp/messages/fwd-pastry-2.1.hpp>
#include <net/sbbi/upnp/services/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct default_init_tag;

class net::sbbi::upnp::messages::ActionResponse
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;

private:
    ::java::util::Map* outArguments {  };
    ::java::util::Map* outArgumentsVals {  };

protected:
    void ctor();

public: /* protected */
    virtual void addResult(::net::sbbi::upnp::services::ServiceActionArgument* arg, ::java::lang::String* value);

public:
    virtual ::net::sbbi::upnp::services::ServiceActionArgument* getOutActionArgument(::java::lang::String* actionArgumentName);
    virtual ::java::util::Set* getOutActionArgumentNames();
    virtual ::java::lang::String* getOutActionArgumentValue(::java::lang::String* actionArgumentName);
    ::java::lang::String* toString() override;

    // Generated

public: /* protected */
    ActionResponse();
protected:
    ActionResponse(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
