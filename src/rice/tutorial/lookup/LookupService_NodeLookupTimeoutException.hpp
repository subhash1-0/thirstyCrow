// Generated from /pastry-2.1/src/rice/tutorial/lookup/LookupService.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <rice/tutorial/lookup/fwd-pastry-2.1.hpp>
#include <java/lang/Exception.hpp>

struct default_init_tag;

class rice::tutorial::lookup::LookupService_NodeLookupTimeoutException
    : public ::java::lang::Exception
{

public:
    typedef ::java::lang::Exception super;

private:
    static constexpr int64_t serialVersionUID { int64_t(-9138111846775601203LL) };

    // Generated

public:
    LookupService_NodeLookupTimeoutException();
protected:
    LookupService_NodeLookupTimeoutException(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
    friend class LookupService;
    friend class LookupService_requestNodeHandles_1;
    friend class LookupService_sendMessageWithRetries_2;
    friend class LookupService_requestNodeHandle_3;
    friend class LookupService_requestNodeHandle_3_run_3_1;
    friend class LookupService_NodeLookupTimeout;
    friend class LookupService_NodeLookupQuery;
    friend class LookupService_NodeLookupResponse;
};
