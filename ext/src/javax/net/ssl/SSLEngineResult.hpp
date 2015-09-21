// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <javax/net/ssl/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct default_init_tag;

class javax::net::ssl::SSLEngineResult
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;

private:
    int32_t bytesConsumed_ {  };
    int32_t bytesProduced_ {  };
    SSLEngineResult_HandshakeStatus* handshakeStatus {  };
    SSLEngineResult_Status* status {  };

protected:
    void ctor(SSLEngineResult_Status* arg0, SSLEngineResult_HandshakeStatus* arg1, int32_t arg2, int32_t arg3);

public:
    int32_t bytesConsumed();
    int32_t bytesProduced();
    SSLEngineResult_HandshakeStatus* getHandshakeStatus();
    SSLEngineResult_Status* getStatus();
    ::java::lang::String* toString() override;

    // Generated
    SSLEngineResult(SSLEngineResult_Status* arg0, SSLEngineResult_HandshakeStatus* arg1, int32_t arg2, int32_t arg3);
protected:
    SSLEngineResult(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
