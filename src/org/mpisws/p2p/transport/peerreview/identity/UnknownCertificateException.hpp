// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/identity/UnknownCertificateException.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/identity/fwd-pastry-2.1.hpp>
#include <java/lang/Exception.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::peerreview::identity::UnknownCertificateException
    : public ::java::lang::Exception
{

public:
    typedef ::java::lang::Exception super;

public: /* package */
    ::java::lang::Object* source {  };
    ::java::lang::Object* principal {  };
protected:
    void ctor(::java::lang::Object* source, ::java::lang::Object* principal);

public:
    virtual ::java::lang::Object* getSource();
    virtual ::java::lang::Object* getPrincipal();

    // Generated
    UnknownCertificateException(::java::lang::Object* source, ::java::lang::Object* principal);
protected:
    UnknownCertificateException(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
