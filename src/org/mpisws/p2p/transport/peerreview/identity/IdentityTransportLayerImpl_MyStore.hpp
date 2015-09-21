// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/identity/IdentityTransportLayerImpl.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/security/cert/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/identity/fwd-pastry-2.1.hpp>
#include <java/util/HashMap.hpp>
#include <org/mpisws/p2p/transport/table/TableStore.hpp>
#include <java/security/cert/X509Certificate.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::peerreview::identity::IdentityTransportLayerImpl_MyStore
    : public ::java::util::HashMap
    , public virtual ::org::mpisws::p2p::transport::table::TableStore
{

public:
    typedef ::java::util::HashMap super;

public: /* package */
    IdentityTransportCallback* callback {  };

public:
    virtual ::java::security::cert::X509Certificate* put(::java::lang::Object* key, ::java::security::cert::X509Certificate* value);

    // Generated
    IdentityTransportLayerImpl_MyStore();
protected:
    IdentityTransportLayerImpl_MyStore(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    virtual bool containsKey(::java::lang::Object* key);
    virtual ::java::security::cert::X509Certificate* get(::java::lang::Object* k);
    ::java::lang::Object* put(::java::lang::Object* arg0, ::java::lang::Object* arg1) override;

private:
    virtual ::java::lang::Class* getClass0();
    friend class IdentityTransportLayerImpl;
};
