// Generated from /pastry-2.1/src/rice/p2p/multiring/RingCertificate.java
#include <rice/p2p/multiring/RingCertificate.hpp>

#include <java/io/BufferedInputStream.hpp>
#include <java/io/BufferedOutputStream.hpp>
#include <java/io/BufferedReader.hpp>
#include <java/io/BufferedWriter.hpp>
#include <java/io/File.hpp>
#include <java/io/FileInputStream.hpp>
#include <java/io/FileOutputStream.hpp>
#include <java/io/IOException.hpp>
#include <java/io/InputStream.hpp>
#include <java/io/InputStreamReader.hpp>
#include <java/io/ObjectInputStream.hpp>
#include <java/io/ObjectOutputStream.hpp>
#include <java/io/OutputStreamWriter.hpp>
#include <java/io/PrintStream.hpp>
#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/CharSequence.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/ClassLoader.hpp>
#include <java/lang/ClassNotFoundException.hpp>
#include <java/lang/Comparable.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/IllegalArgumentException.hpp>
#include <java/lang/Integer.hpp>
#include <java/lang/Long.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/RuntimeException.hpp>
#include <java/lang/SecurityException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>
#include <java/lang/Throwable.hpp>
#include <java/net/InetAddress.hpp>
#include <java/net/InetSocketAddress.hpp>
#include <java/net/SocketAddress.hpp>
#include <java/net/URL.hpp>
#include <java/security/KeyPair.hpp>
#include <java/security/PublicKey.hpp>
#include <java/util/HashMap.hpp>
#include <java/util/zip/GZIPInputStream.hpp>
#include <java/util/zip/GZIPOutputStream.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/params/Parameters.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/util/SecurityUtils.hpp>
#include <rice/p2p/util/XMLObjectInputStream.hpp>
#include <rice/p2p/util/XMLObjectOutputStream.hpp>
#include <rice/pastry/commonapi/PastryIdFactory.hpp>
#include <rice/pastry/dist/DistPastryNodeFactory.hpp>
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

    namespace net
    {
typedef ::SubArray< ::java::net::SocketAddress, ::java::lang::ObjectArray, ::java::io::SerializableArray > SocketAddressArray;
typedef ::SubArray< ::java::net::InetSocketAddress, SocketAddressArray > InetSocketAddressArray;
    } // net
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

namespace
{
    template<typename F>
    struct finally_
    {
        finally_(F f) : f(f), moved(false) { }
        finally_(finally_ &&x) : f(x.f), moved(false) { x.moved = true; }
        ~finally_() { if(!moved) f(); }
    private:
        finally_(const finally_&); finally_& operator=(const finally_&);
        F f;
        bool moved;
    };

    template<typename F> finally_<F> finally(F f) { return finally_<F>(f); }
}
rice::p2p::multiring::RingCertificate::RingCertificate(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::multiring::RingCertificate::RingCertificate(::java::lang::String* name, ::rice::p2p::commonapi::Id* id, int32_t protocol, ::java::net::InetSocketAddressArray* bootstraps, int32_t port, ::java::security::PublicKey* key, ::java::net::InetSocketAddress* logServer) 
    : RingCertificate(*static_cast< ::default_init_tag* >(0))
{
    ctor(name,id,protocol,bootstraps,port,key,logServer);
}

constexpr int64_t rice::p2p::multiring::RingCertificate::serialVersionUID;

java::util::HashMap*& rice::p2p::multiring::RingCertificate::CERTIFICATES()
{
    clinit();
    return CERTIFICATES_;
}
java::util::HashMap* rice::p2p::multiring::RingCertificate::CERTIFICATES_;

rice::p2p::multiring::RingCertificate* rice::p2p::multiring::RingCertificate::getCertificate(::rice::p2p::commonapi::Id* ringId)
{
    clinit();
    return java_cast< RingCertificate* >(java_cast< RingCertificate* >(npc(CERTIFICATES_)->get(static_cast< ::java::lang::Object* >(ringId))));
}

void rice::p2p::multiring::RingCertificate::refresh()
{
    logServer = refreshAddress(logServer);
}

java::net::InetSocketAddress* rice::p2p::multiring::RingCertificate::refreshAddress(::java::net::InetSocketAddress* address)
{
    return new ::java::net::InetSocketAddress(npc(npc(address)->getAddress())->getHostName(), npc(address)->getPort());
}

void rice::p2p::multiring::RingCertificate::ctor(::java::lang::String* name, ::rice::p2p::commonapi::Id* id, int32_t protocol, ::java::net::InetSocketAddressArray* bootstraps, int32_t port, ::java::security::PublicKey* key, ::java::net::InetSocketAddress* logServer)
{
    super::ctor();
    this->name = name;
    this->id = id;
    this->bootstraps = bootstraps;
    this->port = new ::java::lang::Integer(port);
    this->key = key;
    this->logServer = logServer;
    this->version = new ::java::lang::Long(::java::lang::System::currentTimeMillis());
    this->protocol = new ::java::lang::Integer(protocol);
}

java::lang::String* rice::p2p::multiring::RingCertificate::getName()
{
    return name;
}

rice::p2p::commonapi::Id* rice::p2p::multiring::RingCertificate::getId()
{
    return id;
}

int32_t rice::p2p::multiring::RingCertificate::getProtocol()
{
    return npc(protocol)->intValue();
}

int64_t rice::p2p::multiring::RingCertificate::getVersion()
{
    return npc(version)->longValue();
}

java::net::InetSocketAddressArray* rice::p2p::multiring::RingCertificate::getBootstraps()
{
    return bootstraps;
}

int32_t rice::p2p::multiring::RingCertificate::getPort()
{
    return npc(port)->intValue();
}

java::security::PublicKey* rice::p2p::multiring::RingCertificate::getKey()
{
    return key;
}

java::net::InetSocketAddress* rice::p2p::multiring::RingCertificate::getLogServer()
{
    return logServer;
}

void rice::p2p::multiring::RingCertificate::sign(::java::security::PrivateKey* priv)
{
    if(signature != nullptr)
        throw new ::java::lang::IllegalArgumentException(u"Attempt to sign an already-signed RingCertificate!"_j);

    try {
        signature = ::rice::p2p::util::SecurityUtils::sign(::rice::p2p::util::SecurityUtils::serialize(getIdentifier()), priv);
    } catch (::java::io::IOException* e) {
        throw new ::java::lang::RuntimeException(static_cast< ::java::lang::Throwable* >(e));
    }
}

bool rice::p2p::multiring::RingCertificate::verify(::java::security::PublicKey* pub)
{
    if(signature == nullptr)
        throw new ::java::lang::IllegalArgumentException(u"Attempt to verify an unsigned RingCertificate!"_j);

    try {
        return ::rice::p2p::util::SecurityUtils::verify(::rice::p2p::util::SecurityUtils::serialize(getIdentifier()), signature, pub);
    } catch (::java::lang::SecurityException* e) {
        return false;
    } catch (::java::io::IOException* e) {
        throw new ::java::lang::RuntimeException(static_cast< ::java::lang::Throwable* >(e));
    }
}

java::lang::String* rice::p2p::multiring::RingCertificate::toString()
{
    return ::java::lang::StringBuilder().append(u"[Ring Certificate for ring '"_j)->append(name)
        ->append(u"' ("_j)
        ->append(static_cast< ::java::lang::Object* >(id))
        ->append(u")]"_j)->toString();
}

void rice::p2p::multiring::RingCertificate::writeToFile(::java::io::File* file) /* throws(IOException) */
{
    ::java::io::ObjectOutputStream* oos = nullptr;
    {
        auto finally0 = finally([&] {
            if(oos != nullptr)
                npc(oos)->close();

        });
        {
            oos = new ::rice::p2p::util::XMLObjectOutputStream(new ::java::io::BufferedOutputStream(new ::java::util::zip::GZIPOutputStream(new ::java::io::FileOutputStream(file))));
            npc(oos)->writeObject(static_cast< ::java::lang::Object* >(this));
        }
    }

}

rice::p2p::multiring::RingCertificate* rice::p2p::multiring::RingCertificate::readFromStream(::java::io::InputStream* stream) /* throws(IOException) */
{
    clinit();
    ::java::io::ObjectInputStream* ois = nullptr;
    {
        auto finally1 = finally([&] {
            if(ois != nullptr)
                npc(ois)->close();

        });
        try {
            ois = new ::rice::p2p::util::XMLObjectInputStream(new ::java::io::BufferedInputStream(new ::java::util::zip::GZIPInputStream(stream)));
            return java_cast< RingCertificate* >(npc(ois)->readObject());
        } catch (::java::lang::ClassNotFoundException* e) {
            throw new ::java::io::IOException(npc(e)->getMessage());
        }
    }
}

void rice::p2p::multiring::RingCertificate::writeKeyPair(::java::security::KeyPair* pair, ::java::lang::String* pass, ::java::lang::String* ring) /* throws(IOException) */
{
    clinit();
    auto cipher = ::rice::p2p::util::SecurityUtils::encryptSymmetric(::rice::p2p::util::SecurityUtils::serialize(pair), ::rice::p2p::util::SecurityUtils::hash(npc(pass)->getBytes()));
    ::java::io::ObjectOutputStream* oos = new ::rice::p2p::util::XMLObjectOutputStream(new ::java::io::BufferedOutputStream(new ::java::util::zip::GZIPOutputStream(new ::java::io::FileOutputStream(::java::lang::StringBuilder().append(npc(ring)->toLowerCase())->append(u".ringkeypair.enc"_j)->toString()))));
    npc(oos)->writeObject(static_cast< ::java::lang::Object* >(cipher));
    npc(oos)->close();
}

java::security::KeyPair* rice::p2p::multiring::RingCertificate::readKeyPair(::java::lang::String* ring, ::java::lang::String* pass) /* throws(IOException, ClassNotFoundException) */
{
    clinit();
    ::java::io::ObjectInputStream* ois = new ::rice::p2p::util::XMLObjectInputStream(new ::java::io::BufferedInputStream(new ::java::util::zip::GZIPInputStream(new ::java::io::FileInputStream(::java::lang::StringBuilder().append(npc(ring)->toLowerCase())->append(u".ringkeypair.enc"_j)->toString()))));
    auto cipher = java_cast< ::int8_tArray* >(npc(ois)->readObject());
    npc(ois)->close();
    return java_cast< ::java::security::KeyPair* >(::rice::p2p::util::SecurityUtils::deserialize(::rice::p2p::util::SecurityUtils::decryptSymmetric(cipher, ::rice::p2p::util::SecurityUtils::hash(npc(pass)->getBytes()))));
}

java::lang::Object* rice::p2p::multiring::RingCertificate::getIdentifier()
{
    return new ::java::lang::ObjectArray({
        static_cast< ::java::lang::Object* >(name)
        , static_cast< ::java::lang::Object* >(id)
        , static_cast< ::java::lang::Object* >(bootstraps)
        , static_cast< ::java::lang::Object* >(port)
        , static_cast< ::java::lang::Object* >(key)
        , static_cast< ::java::lang::Object* >(logServer)
        , static_cast< ::java::lang::Object* >(version)
        , static_cast< ::java::lang::Object* >(protocol)
    });
}

void rice::p2p::multiring::RingCertificate::main(::java::lang::StringArray* args) /* throws(Exception) */
{
    clinit();
    auto env = new ::rice::environment::Environment();
    auto r = new ::java::io::BufferedReader(new ::java::io::InputStreamReader(::java::lang::System::in()));
    auto w = new ::java::io::BufferedWriter(new ::java::io::OutputStreamWriter(::java::lang::System::out()));
    auto f = new ::java::io::File(u"ca.keypair.enc"_j);
    ::java::io::ObjectInputStream* ois = new ::rice::p2p::util::XMLObjectInputStream(new ::java::io::BufferedInputStream(new ::java::util::zip::GZIPInputStream(new ::java::io::FileInputStream(f))));
    auto caPair = java_cast< ::java::security::KeyPair* >(::rice::p2p::util::SecurityUtils::deserialize(::rice::p2p::util::SecurityUtils::decryptSymmetric(java_cast< ::int8_tArray* >(npc(ois)->readObject()), ::rice::p2p::util::SecurityUtils::hash(npc(npc(prompt(r, w, u"Please enter the CA password: "_j))->trim())->getBytes()))));
    npc(ois)->close();
    auto ring = prompt(r, w, u"Please enter the name of the ring (rice, berkeley): "_j);
    auto bootstrap = npc(npc(prompt(r, w, u"Please enter the bootstraps (host1:port1,host2:port2...): "_j))->trim())->split(u","_j);
    auto port = ::java::lang::Integer::parseInt(prompt(r, w, u"Please enter the default port for nodes: "_j));
    auto logServer = prompt(r, w, u"Please enter the log upload server (host:port): "_j);
    auto pass = prompt(r, w, u"Please enter a password for the ring keypair: "_j);
    auto protocolId = int32_t(0);
    protocolId = ::rice::pastry::dist::DistPastryNodeFactory::PROTOCOL_SOCKET();
    auto id = generateId(ring, env);
    auto log = toInetSocketAddress(logServer);
    auto bootstraps = new ::java::net::InetSocketAddressArray(npc(bootstrap)->length);
    for (auto i = int32_t(0); i < npc(bootstraps)->length; i++) 
                bootstraps->set(i, toInetSocketAddress((*bootstrap)[i]));

    auto pair = ::rice::p2p::util::SecurityUtils::generateKeyAsymmetric();
    auto cert = new RingCertificate(ring, id, protocolId, bootstraps, port, npc(pair)->getPublic(), log);
    npc(cert)->sign(npc(caPair)->getPrivate());
    if(!npc(cert)->verify(npc(caPair)->getPublic()))
        throw new ::java::lang::RuntimeException(u"Could not verify generated certificate!"_j);

    npc(cert)->writeToFile(new ::java::io::File(::java::lang::StringBuilder().append(npc(ring)->toLowerCase())->append(u".ringcert"_j)->toString()));
    writeKeyPair(pair, pass, npc(ring)->toLowerCase());
    ::java::lang::System::exit(0);
}

java::lang::String* rice::p2p::multiring::RingCertificate::prompt(::java::io::BufferedReader* r, ::java::io::BufferedWriter* w, ::java::lang::String* prompt) /* throws(IOException) */
{
    clinit();
    npc(w)->write(prompt);
    npc(w)->flush();
    return npc(r)->readLine();
}

java::net::InetSocketAddress* rice::p2p::multiring::RingCertificate::toInetSocketAddress(::java::lang::String* s) /* throws(IOException) */
{
    clinit();
    auto host = npc(s)->substring(0, npc(s)->indexOf(u":"_j));
    auto port = ::java::lang::Integer::parseInt(npc(s)->substring(npc(s)->indexOf(u":"_j) + int32_t(1)));
    return new ::java::net::InetSocketAddress(host, port);
}

rice::p2p::commonapi::Id* rice::p2p::multiring::RingCertificate::generateId(::java::lang::String* s, ::rice::environment::Environment* env)
{
    clinit();
    auto ring = ::java::lang::StringBuilder().append(npc(npc(s)->substring(0, 1))->toUpperCase())->append(npc(npc(s)->substring(1))->toLowerCase())->toString();
    auto pif = new ::rice::pastry::commonapi::PastryIdFactory(env);
    auto ringId = npc(pif)->buildId(ring);
    auto ringData = npc(ringId)->toByteArray_();
    for (auto i = int32_t(0); i < npc(ringData)->length - npc(npc(env)->getParameters())->getInt(u"p2p_multiring_base"_j); i++) 
                (*ringData)[i] = 0;

    if(npc(npc(s)->toLowerCase())->equals(static_cast< ::java::lang::Object* >(u"global"_j)))
        for (auto i = int32_t(0); i < npc(ringData)->length; i++) 
                        (*ringData)[i] = 0;


    return npc(pif)->buildId(ringData);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::multiring::RingCertificate::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.multiring.RingCertificate", 34);
    return c;
}

void rice::p2p::multiring::RingCertificate::clinit()
{
    super::clinit();
    static bool in_cl_init = false;
struct clinit_ {
    clinit_() {
        in_cl_init = true;
        CERTIFICATES_ = new ::java::util::HashMap();
        {
            try {
                auto a = ::java::lang::ClassLoader::getSystemResource(u"ca.publickey"_j);
                auto b = npc(a)->openStream();
                auto c = new ::java::util::zip::GZIPInputStream(b);
                auto d = new ::java::io::BufferedInputStream(c);
                ::java::io::ObjectInputStream* ois = new ::rice::p2p::util::XMLObjectInputStream(d);
                auto caPublic = java_cast< ::java::security::PublicKey* >(npc(ois)->readObject());
                npc(ois)->close();
                auto a1 = ::java::lang::ClassLoader::getSystemResource(u"ringcert.list"_j);
                auto b1 = npc(a1)->openStream();
                auto c1 = new ::java::io::InputStreamReader(b1);
                auto r = new ::java::io::BufferedReader(c1);
                ::java::lang::String* filename = nullptr;
                while ((filename = npc(r)->readLine()) != nullptr) {
                    auto a2 = ::java::lang::ClassLoader::getSystemResource(filename);
                    auto b2 = npc(a2)->openStream();
                    auto cert = readFromStream(b2);
                    if(npc(cert)->verify(caPublic)) {
                        if((getCertificate(npc(cert)->getId()) == nullptr) || (npc(getCertificate(npc(cert)->getId()))->getVersion() < npc(cert)->getVersion())) {
                            npc(cert)->refresh();
                            npc(CERTIFICATES_)->put(static_cast< ::java::lang::Object* >(npc(cert)->getId()), static_cast< ::java::lang::Object* >(cert));
                        }
                    } else {
                        npc(::java::lang::System::err())->println(::java::lang::StringBuilder().append(u"RINGCERT: Could not verify ring certificate "_j)->append(static_cast< ::java::lang::Object* >(cert))
                            ->append(u" ignoring."_j)->toString());
                    }
                }
            } catch (::java::lang::Exception* e) {
                npc(::java::lang::System::err())->println(::java::lang::StringBuilder().append(u"RINGCERT: ERROR: Found exception "_j)->append(static_cast< ::java::lang::Object* >(e))
                    ->append(u" while reading in ring certificates!"_j)->toString());
                npc(e)->printStackTrace();
            }
        }
    }
};

    if(!in_cl_init) {
        static clinit_ clinit_instance;
    }
}

java::lang::Class* rice::p2p::multiring::RingCertificate::getClass0()
{
    return class_();
}

