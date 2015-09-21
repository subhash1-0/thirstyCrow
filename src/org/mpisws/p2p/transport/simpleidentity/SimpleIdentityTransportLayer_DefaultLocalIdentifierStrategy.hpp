// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/simpleidentity/SimpleIdentityTransportLayer.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/simpleidentity/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/simpleidentity/LocalIdentifierStrategy.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::simpleidentity::SimpleIdentityTransportLayer_DefaultLocalIdentifierStrategy
    : public virtual ::java::lang::Object
    , public virtual LocalIdentifierStrategy
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    ::int8_tArray* localIdentifierBytes {  };
protected:
    void ctor(::java::lang::Object* i) /* throws(IOException) */;

public:
    ::int8_tArray* getLocalIdentifierBytes() override;

    // Generated
    SimpleIdentityTransportLayer_DefaultLocalIdentifierStrategy(SimpleIdentityTransportLayer *SimpleIdentityTransportLayer_this, ::java::lang::Object* i);
protected:
    SimpleIdentityTransportLayer_DefaultLocalIdentifierStrategy(SimpleIdentityTransportLayer *SimpleIdentityTransportLayer_this, const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    SimpleIdentityTransportLayer *SimpleIdentityTransportLayer_this;

private:
    virtual ::java::lang::Class* getClass0();
    friend class SimpleIdentityTransportLayer;
    friend class SimpleIdentityTransportLayer_openSocket_1;
    friend class SimpleIdentityTransportLayer_openSocket_1_receiveResult_1_1;
    friend class SimpleIdentityTransportLayer_incomingSocket_2;
};
