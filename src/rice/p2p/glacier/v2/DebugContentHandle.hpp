// Generated from /pastry-2.1/src/rice/p2p/glacier/v2/DebugContentHandle.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/glacier/v2/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/p2p/past/gc/GCPastContentHandle.hpp>

struct default_init_tag;

class rice::p2p::glacier::v2::DebugContentHandle
    : public virtual ::java::lang::Object
    , public virtual ::rice::p2p::past::gc::GCPastContentHandle
{

public:
    typedef ::java::lang::Object super;

public: /* protected */
    ::rice::p2p::commonapi::Id* myId {  };
    ::rice::p2p::commonapi::NodeHandle* myNodeHandle {  };
    int64_t myExpiration {  };
    int64_t myVersion {  };
protected:
    void ctor(::rice::p2p::commonapi::Id* id, int64_t version, int64_t expiration, ::rice::p2p::commonapi::NodeHandle* nodeHandle);

public:
    ::rice::p2p::commonapi::Id* getId() override;
    ::rice::p2p::commonapi::NodeHandle* getNodeHandle() override;
    int64_t getVersion() override;
    int64_t getExpiration() override;

    // Generated

public: /* package */
    DebugContentHandle(::rice::p2p::commonapi::Id* id, int64_t version, int64_t expiration, ::rice::p2p::commonapi::NodeHandle* nodeHandle);
protected:
    DebugContentHandle(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
