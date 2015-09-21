// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/sourceroute/SourceRoute.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/sourceroute/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::sourceroute::SourceRoute
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;

public: /* protected */
    ::java::util::List* path {  };
protected:
    void ctor(::java::util::List* path);
    void ctor(::java::lang::Object* address);
    void ctor(::java::lang::Object* local, ::java::lang::Object* remote);

public:
    int32_t hashCode() override;
    bool equals(::java::lang::Object* o) override;
    ::java::lang::String* toString() override;
    virtual ::java::lang::Object* getFirstHop();
    virtual ::java::lang::Object* getLastHop();
    virtual int32_t getNumHops();
    virtual ::java::lang::Object* getHop(int32_t i);
    virtual bool isDirect();
    virtual bool goesThrough(::java::lang::Object* address);
    virtual int32_t getHop(::java::lang::Object* identifier);
    virtual void serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */ = 0;
    virtual int32_t getSerializedLength() = 0;

    // Generated

public: /* protected */
    SourceRoute(::java::util::List* path);
    SourceRoute(::java::lang::Object* address);
    SourceRoute(::java::lang::Object* local, ::java::lang::Object* remote);
protected:
    SourceRoute(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
