// Generated from /pastry-2.1/src/rice/p2p/util/MRHAdapter.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/util/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/MessageRequestHandle.hpp>
#include <rice/p2p/commonapi/Message.hpp>
#include <rice/p2p/commonapi/NodeHandle.hpp>

struct default_init_tag;

class rice::p2p::util::MRHAdapter
    : public virtual ::java::lang::Object
    , public virtual ::org::mpisws::p2p::transport::MessageRequestHandle
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    ::org::mpisws::p2p::transport::MessageRequestHandle* internal {  };

public:
    virtual void setInternal(::org::mpisws::p2p::transport::MessageRequestHandle* name);
    ::rice::p2p::commonapi::NodeHandle* getIdentifier() override;
    ::rice::p2p::commonapi::Message* getMessage() override;
    ::java::util::Map* getOptions() override;
    bool cancel() override;

    // Generated
    MRHAdapter();
protected:
    MRHAdapter(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
