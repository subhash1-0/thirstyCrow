// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/util/DefaultErrorHandler.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/util/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/ErrorHandler.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::util::DefaultErrorHandler
    : public virtual ::java::lang::Object
    , public virtual ::org::mpisws::p2p::transport::ErrorHandler
{

public:
    typedef ::java::lang::Object super;
    int32_t NUM_BYTES_TO_PRINT {  };

public: /* protected */
    int32_t printlevel {  };

private:
    ::rice::environment::logging::Logger* logger {  };
protected:
    void ctor(::rice::environment::logging::Logger* logger);
    void ctor(::rice::environment::logging::Logger* logger, int32_t printlevel);

public:
    void receivedUnexpectedData(::java::lang::Object* id, ::int8_tArray* bytes, int32_t pos, ::java::util::Map* options) override;
    void receivedException(::java::lang::Object* i, ::java::lang::Throwable* error) override;

    // Generated
    DefaultErrorHandler(::rice::environment::logging::Logger* logger);
    DefaultErrorHandler(::rice::environment::logging::Logger* logger, int32_t printlevel);
protected:
    DefaultErrorHandler(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    void init();
    virtual ::java::lang::Class* getClass0();
};
