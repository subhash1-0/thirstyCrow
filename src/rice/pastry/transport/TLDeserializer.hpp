// Generated from /pastry-2.1/src/rice/pastry/transport/TLDeserializer.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/transport/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/commonapi/RawMessageDeserializer.hpp>
#include <rice/pastry/transport/Deserializer.hpp>

struct default_init_tag;

class rice::pastry::transport::TLDeserializer
    : public virtual ::java::lang::Object
    , public virtual ::org::mpisws::p2p::transport::commonapi::RawMessageDeserializer
    , public virtual Deserializer
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    ::java::util::Map* deserializers {  };
    ::rice::pastry::NodeHandleFactory* nodeHandleFactory {  };

public: /* protected */
    ::rice::environment::Environment* environment {  };
    ::rice::environment::logging::Logger* logger {  };
protected:
    void ctor(::rice::pastry::NodeHandleFactory* nodeHandleFactory, ::rice::environment::Environment* env);

public:
    ::rice::p2p::commonapi::rawserialization::RawMessage* deserialize(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::NodeHandle* sender) /* throws(IOException) */ override;
    void serialize(::rice::p2p::commonapi::rawserialization::RawMessage* m, ::rice::p2p::commonapi::rawserialization::OutputBuffer* o) /* throws(IOException) */ override;
    void clearDeserializer(int32_t address) override;
    ::rice::p2p::commonapi::rawserialization::MessageDeserializer* getDeserializer(int32_t address) override;
    void setDeserializer(int32_t address, ::rice::p2p::commonapi::rawserialization::MessageDeserializer* md) override;

    // Generated
    TLDeserializer(::rice::pastry::NodeHandleFactory* nodeHandleFactory, ::rice::environment::Environment* env);
protected:
    TLDeserializer(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
