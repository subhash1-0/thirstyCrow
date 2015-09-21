// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/rendezvous/EphemeralDBImpl.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/rendezvous/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <rice/environment/time/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/rendezvous/EphemeralDB.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::rendezvous::EphemeralDBImpl
    : public virtual ::java::lang::Object
    , public virtual EphemeralDB
{

public:
    typedef ::java::lang::Object super;

public: /* protected */
    int64_t STALE_PORT_TIME {  };

public: /* package */
    ::rice::environment::time::TimeSource* time {  };
    ::rice::environment::logging::Logger* logger {  };

public: /* protected */
    int64_t nextTag {  };
    ::java::util::Map* highToTag {  };
    ::java::util::Map* ephemeralToTag {  };
    ::java::util::Map* tagToEphemeral {  };
protected:
    void ctor(::rice::environment::Environment* env, int64_t stalePortTime);

public:
    void mapHighToTag(::java::lang::Object* high, int64_t tag) override;
    ::java::lang::Object* getEphemeral(::java::lang::Object* high) override;
    ::java::lang::Object* getEphemeral(int64_t tag, ::java::lang::Object* i) override;
    int64_t getTagForEphemeral(::java::lang::Object* addr) override;

public: /* protected */
    virtual void clear(int64_t tag);

    // Generated

public:
    EphemeralDBImpl(::rice::environment::Environment* env, int64_t stalePortTime);
protected:
    EphemeralDBImpl(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    void init();
    virtual ::java::lang::Class* getClass0();
};
