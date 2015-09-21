// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/identity/IdentityTransportLayerImpl.java
#include <org/mpisws/p2p/transport/peerreview/identity/IdentityTransportLayerImpl_MyStore.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/security/cert/X509Certificate.hpp>
#include <org/mpisws/p2p/transport/peerreview/identity/IdentityTransportCallback.hpp>

template<typename T, typename U>
static T java_cast(U* u)
{
    if(!u) return static_cast<T>(nullptr);
    auto t = dynamic_cast<T>(u);
    if(!t) throw new ::java::lang::ClassCastException();
    return t;
}

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::transport::peerreview::identity::IdentityTransportLayerImpl_MyStore::IdentityTransportLayerImpl_MyStore(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::transport::peerreview::identity::IdentityTransportLayerImpl_MyStore::IdentityTransportLayerImpl_MyStore()
    : IdentityTransportLayerImpl_MyStore(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

java::security::cert::X509Certificate* org::mpisws::p2p::transport::peerreview::identity::IdentityTransportLayerImpl_MyStore::put(::java::lang::Object* key, ::java::security::cert::X509Certificate* value)
{
    auto ret = java_cast< ::java::security::cert::X509Certificate* >(super::put(static_cast< ::java::lang::Object* >(key), static_cast< ::java::lang::Object* >(value)));
    if(ret == nullptr && callback != nullptr) {
        npc(callback)->notifyCertificateAvailable(key);
    }
    return ret;
}

java::lang::Object* org::mpisws::p2p::transport::peerreview::identity::IdentityTransportLayerImpl_MyStore::put(::java::lang::Object* arg0, ::java::lang::Object* arg1)
{ 
    return put(dynamic_cast< ::java::lang::Object* >(arg0), dynamic_cast< ::java::security::cert::X509Certificate* >(arg1));
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::peerreview::identity::IdentityTransportLayerImpl_MyStore::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.peerreview.identity.IdentityTransportLayerImpl.MyStore", 79);
    return c;
}

bool org::mpisws::p2p::transport::peerreview::identity::IdentityTransportLayerImpl_MyStore::containsKey(::java::lang::Object* key)
{
    return HashMap::containsKey(key);
}

java::security::cert::X509Certificate* org::mpisws::p2p::transport::peerreview::identity::IdentityTransportLayerImpl_MyStore::get(::java::lang::Object* k)
{
    return java_cast< ::java::security::cert::X509Certificate* >(HashMap::get(k));
}

java::lang::Class* org::mpisws::p2p::transport::peerreview::identity::IdentityTransportLayerImpl_MyStore::getClass0()
{
    return class_();
}

