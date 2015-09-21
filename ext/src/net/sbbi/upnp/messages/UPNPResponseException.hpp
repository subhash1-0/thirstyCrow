// Generated from /pastry-2.1/lib/sbbi-upnplib-1.0.4.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <net/sbbi/upnp/messages/fwd-pastry-2.1.hpp>
#include <java/lang/Exception.hpp>

struct default_init_tag;

class net::sbbi::upnp::messages::UPNPResponseException
    : public ::java::lang::Exception
{

public:
    typedef ::java::lang::Exception super;

public: /* protected */
    int32_t detailErrorCode {  };
    ::java::lang::String* detailErrorDescription {  };
    ::java::lang::String* faultCode {  };
    ::java::lang::String* faultString {  };

private:
    static constexpr int64_t serialVersionUID { int64_t(8313107558129180594LL) };

protected:
    void ctor();
    void ctor(int32_t detailErrorCode, ::java::lang::String* detailErrorDescription);

public:
    virtual int32_t getDetailErrorCode();
    virtual ::java::lang::String* getDetailErrorDescription();
    virtual ::java::lang::String* getFaultCode();
    virtual ::java::lang::String* getFaultString();
    ::java::lang::String* getLocalizedMessage() override;
    ::java::lang::String* getMessage() override;

    // Generated
    UPNPResponseException();
    UPNPResponseException(int32_t detailErrorCode, ::java::lang::String* detailErrorDescription);
protected:
    UPNPResponseException(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
