// Generated from /pastry-2.1/src/rice/pastry/standard/ConsistentJoinProtocol.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/standard/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/Comparable.hpp>

struct default_init_tag;

class rice::pastry::standard::ConsistentJoinProtocol_FailedTime
    : public virtual ::java::lang::Object
    , public virtual ::java::lang::Comparable
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    int64_t time {  };
    ::rice::pastry::NodeHandle* handle {  };
protected:
    void ctor(::rice::pastry::NodeHandle* handle, int64_t time);

public:
    virtual int32_t compareTo(ConsistentJoinProtocol_FailedTime* arg0);
    ::java::lang::String* toString() override;

    // Generated
    ConsistentJoinProtocol_FailedTime(::rice::pastry::NodeHandle* handle, int64_t time);
protected:
    ConsistentJoinProtocol_FailedTime(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    virtual int32_t compareTo(::java::lang::Object* o) override;

private:
    virtual ::java::lang::Class* getClass0();
    friend class ConsistentJoinProtocol;
    friend class ConsistentJoinProtocol_CJPDeserializer;
    friend class ConsistentJoinProtocol_ConsistentJoinProtocol_1;
    friend class ConsistentJoinProtocol_RequestFromEveryoneMsg;
};
