// Generated from /pastry-2.1/src/rice/pastry/messaging/PJavaSerializedMessage.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/pastry/messaging/fwd-pastry-2.1.hpp>
#include <rice/pastry/messaging/PRawMessage.hpp>

struct default_init_tag;

class rice::pastry::messaging::PJavaSerializedMessage
    : public PRawMessage
{

public:
    typedef PRawMessage super;

public: /* package */
    Message* msg {  };
protected:
    void ctor(Message* msg);

public:
    int16_t getType() override;
    void serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */ override;
    virtual Message* getMessage();

    // Generated
    PJavaSerializedMessage(Message* msg);
protected:
    PJavaSerializedMessage(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
