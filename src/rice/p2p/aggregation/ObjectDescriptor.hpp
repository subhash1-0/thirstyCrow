// Generated from /pastry-2.1/src/rice/p2p/aggregation/ObjectDescriptor.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/p2p/aggregation/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <java/io/Serializable.hpp>
#include <java/lang/Comparable.hpp>

struct default_init_tag;

class rice::p2p::aggregation::ObjectDescriptor
    : public virtual ::java::lang::Object
    , public virtual ::java::io::Serializable
    , public virtual ::java::lang::Comparable
{

public:
    typedef ::java::lang::Object super;

private:
    static constexpr int64_t serialVersionUID { int64_t(-3035115249019556223LL) };

public:
    ::rice::p2p::commonapi::Id* key {  };
    int64_t version {  };
    int64_t currentLifetime {  };
    int64_t refreshedLifetime {  };
    int32_t size {  };
protected:
    void ctor(::rice::p2p::commonapi::Id* key, int64_t version, int64_t currentLifetime, int64_t refreshedLifetime, int32_t size);

public:
    ::java::lang::String* toString() override;
    virtual bool isAliveAt(int64_t pointInTime);
    virtual int32_t compareTo(ObjectDescriptor* other);

    // Generated
    ObjectDescriptor(::rice::p2p::commonapi::Id* key, int64_t version, int64_t currentLifetime, int64_t refreshedLifetime, int32_t size);
protected:
    ObjectDescriptor(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    virtual int32_t compareTo(::java::lang::Object* o) override;

private:
    virtual ::java::lang::Class* getClass0();
};
