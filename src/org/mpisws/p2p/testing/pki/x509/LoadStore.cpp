// Generated from /pastry-2.1/src/org/mpisws/p2p/testing/pki/x509/LoadStore.java
#include <org/mpisws/p2p/testing/pki/x509/LoadStore.hpp>

#include <java/io/FileInputStream.hpp>
#include <java/io/PrintStream.hpp>
#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/CharSequence.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Comparable.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/System.hpp>
#include <java/security/Key.hpp>
#include <java/security/KeyStore.hpp>
#include <java/security/Security.hpp>
#include <java/security/cert/Certificate.hpp>
#include <java/util/Enumeration.hpp>
#include <org/bouncycastle/jce/provider/BouncyCastleProvider.hpp>
#include <Array.hpp>
#include <SubArray.hpp>
#include <ObjectArray.hpp>

template<typename ComponentType, typename... Bases> struct SubArray;
namespace java
{
    namespace io
    {
typedef ::SubArray< ::java::io::Serializable, ::java::lang::ObjectArray > SerializableArray;
    } // io

    namespace lang
    {
typedef ::SubArray< ::java::lang::CharSequence, ObjectArray > CharSequenceArray;
typedef ::SubArray< ::java::lang::Comparable, ObjectArray > ComparableArray;
typedef ::SubArray< ::java::lang::String, ObjectArray, ::java::io::SerializableArray, ComparableArray, CharSequenceArray > StringArray;
    } // lang

    namespace security
    {
        namespace cert
        {
typedef ::SubArray< ::java::security::cert::Certificate, ::java::lang::ObjectArray, ::java::io::SerializableArray > CertificateArray;
        } // cert
    } // security
} // java

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

org::mpisws::p2p::testing::pki::x509::LoadStore::LoadStore(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::testing::pki::x509::LoadStore::LoadStore()
    : LoadStore(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

void org::mpisws::p2p::testing::pki::x509::LoadStore::main(::java::lang::StringArray* args) /* throws(Exception) */
{
    clinit();
    auto pw = new ::char16_tArray(int32_t(0));
    if(npc(args)->length > 0) {
        pw = npc((*args)[int32_t(0)])->toCharArray_();
    }
    ::java::security::Security::addProvider(new ::org::bouncycastle::jce::provider::BouncyCastleProvider());
    auto store = ::java::security::KeyStore::getInstance(u"UBER"_j, u"BC"_j);
    npc(store)->load(new ::java::io::FileInputStream(u"ca-store"_j), pw);
    auto e = npc(store)->aliases();
    while (npc(e)->hasMoreElements()) {
        npc(::java::lang::System::out())->println(java_cast< ::java::lang::String* >(npc(e)->nextElement()));
    }
    auto privateKey = npc(store)->getKey(u"private"_j, pw);
    auto chain = npc(store)->getCertificateChain(u"private"_j);
    npc(::java::lang::System::out())->println(static_cast< ::java::lang::Object* >(privateKey));
    npc(::java::lang::System::out())->println(static_cast< ::java::lang::Object* >((*chain)[int32_t(0)]));
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::testing::pki::x509::LoadStore::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.testing.pki.x509.LoadStore", 41);
    return c;
}

java::lang::Class* org::mpisws::p2p::testing::pki::x509::LoadStore::getClass0()
{
    return class_();
}

