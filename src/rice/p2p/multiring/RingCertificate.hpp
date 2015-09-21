// Generated from /pastry-2.1/src/rice/p2p/multiring/RingCertificate.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/net/fwd-pastry-2.1.hpp>
#include <java/security/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/multiring/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <java/io/Serializable.hpp>

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

struct default_init_tag;

class rice::p2p::multiring::RingCertificate
    : public virtual ::java::lang::Object
    , public virtual ::java::io::Serializable
{

public:
    typedef ::java::lang::Object super;

private:
    static constexpr int64_t serialVersionUID { int64_t(5915358246762577456LL) };
    static ::java::util::HashMap* CERTIFICATES_;

public:
    static RingCertificate* getCertificate(::rice::p2p::commonapi::Id* ringId);

private:
    void refresh();
    ::java::net::InetSocketAddress* refreshAddress(::java::net::InetSocketAddress* address);

public: /* protected */
    ::java::lang::String* name {  };
    ::rice::p2p::commonapi::Id* id {  };
    ::java::lang::Integer* protocol {  };
    ::java::net::InetSocketAddressArray* bootstraps {  };
    ::java::lang::Integer* port {  };
    ::java::net::InetSocketAddress* logServer {  };
    ::java::security::PublicKey* key {  };
    ::java::lang::Long* version {  };
    ::int8_tArray* signature {  };
protected:
    void ctor(::java::lang::String* name, ::rice::p2p::commonapi::Id* id, int32_t protocol, ::java::net::InetSocketAddressArray* bootstraps, int32_t port, ::java::security::PublicKey* key, ::java::net::InetSocketAddress* logServer);

public:
    virtual ::java::lang::String* getName();
    virtual ::rice::p2p::commonapi::Id* getId();
    virtual int32_t getProtocol();
    virtual int64_t getVersion();
    virtual ::java::net::InetSocketAddressArray* getBootstraps();
    virtual int32_t getPort();
    virtual ::java::security::PublicKey* getKey();
    virtual ::java::net::InetSocketAddress* getLogServer();

private:
    void sign(::java::security::PrivateKey* priv);
    bool verify(::java::security::PublicKey* pub);

public:
    ::java::lang::String* toString() override;

private:
    void writeToFile(::java::io::File* file) /* throws(IOException) */;
    static RingCertificate* readFromStream(::java::io::InputStream* stream) /* throws(IOException) */;
    static void writeKeyPair(::java::security::KeyPair* pair, ::java::lang::String* pass, ::java::lang::String* ring) /* throws(IOException) */;

public:
    static ::java::security::KeyPair* readKeyPair(::java::lang::String* ring, ::java::lang::String* pass) /* throws(IOException, ClassNotFoundException) */;

private:
    ::java::lang::Object* getIdentifier();

public:
    static void main(::java::lang::StringArray* args) /* throws(Exception) */;

private:
    static ::java::lang::String* prompt(::java::io::BufferedReader* r, ::java::io::BufferedWriter* w, ::java::lang::String* prompt) /* throws(IOException) */;
    static ::java::net::InetSocketAddress* toInetSocketAddress(::java::lang::String* s) /* throws(IOException) */;
    static ::rice::p2p::commonapi::Id* generateId(::java::lang::String* s, ::rice::environment::Environment* env);

    // Generated

public:
    RingCertificate(::java::lang::String* name, ::rice::p2p::commonapi::Id* id, int32_t protocol, ::java::net::InetSocketAddressArray* bootstraps, int32_t port, ::java::security::PublicKey* key, ::java::net::InetSocketAddress* logServer);
protected:
    RingCertificate(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    static void clinit();

public: /* protected */
    static ::java::util::HashMap*& CERTIFICATES();

private:
    virtual ::java::lang::Class* getClass0();
};
