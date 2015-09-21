// Generated from /pastry-2.1/src/rice/p2p/commonapi/NodeHandle.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <java/util/Observable.hpp>
#include <java/io/Serializable.hpp>

struct default_init_tag;

class rice::p2p::commonapi::NodeHandle
    : public ::java::util::Observable
    , public virtual ::java::io::Serializable
{

public:
    typedef ::java::util::Observable super;

private:
    static ::java::lang::Integer* PROXIMITY_CHANGED_;
    static ::java::lang::Integer* DECLARED_DEAD_;
    static ::java::lang::Integer* DECLARED_LIVE_;
    static constexpr int64_t serialVersionUID { int64_t(4761193998848368227LL) };

public:
    virtual Id* getId() = 0;
    virtual bool isAlive() = 0;
    virtual int32_t proximity() = 0;
    virtual bool checkLiveness() = 0;
    virtual void serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */ = 0;

    // Generated
    NodeHandle();
protected:
    NodeHandle(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    static void clinit();
    static ::java::lang::Integer*& PROXIMITY_CHANGED();
    static ::java::lang::Integer*& DECLARED_DEAD();
    static ::java::lang::Integer*& DECLARED_LIVE();

private:
    virtual ::java::lang::Class* getClass0();
};
