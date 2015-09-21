// Generated from /pastry-2.1/src/rice/pastry/standard/CertifiedNodeIdFactory.java
#include <rice/pastry/standard/CertifiedNodeIdFactory.hpp>

#include <java/io/BufferedInputStream.hpp>
#include <java/io/ByteArrayOutputStream.hpp>
#include <java/io/File.hpp>
#include <java/io/FileInputStream.hpp>
#include <java/io/FileOutputStream.hpp>
#include <java/io/IOException.hpp>
#include <java/io/ObjectInputStream.hpp>
#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/CharSequence.hpp>
#include <java/lang/Class.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/ClassNotFoundException.hpp>
#include <java/lang/Comparable.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/RuntimeException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/Throwable.hpp>
#include <java/security/KeyPair.hpp>
#include <java/util/zip/GZIPInputStream.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/LogManager.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/p2p/util/SecurityUtils.hpp>
#include <rice/p2p/util/XMLObjectInputStream.hpp>
#include <rice/p2p/util/XMLObjectOutputStream.hpp>
#include <rice/pastry/Id.hpp>
#include <rice/pastry/standard/IPNodeIdFactory.hpp>
#include <rice/pastry/standard/RandomNodeIdFactory.hpp>
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
rice::pastry::standard::CertifiedNodeIdFactory::CertifiedNodeIdFactory(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::standard::CertifiedNodeIdFactory::CertifiedNodeIdFactory(::java::net::InetAddress* localIP, int32_t port, ::rice::environment::Environment* env) 
    : CertifiedNodeIdFactory(*static_cast< ::default_init_tag* >(0))
{
    ctor(localIP,port,env);
}

java::lang::String*& rice::pastry::standard::CertifiedNodeIdFactory::NODE_ID_FILENAME()
{
    clinit();
    return NODE_ID_FILENAME_;
}
java::lang::String* rice::pastry::standard::CertifiedNodeIdFactory::NODE_ID_FILENAME_;

void rice::pastry::standard::CertifiedNodeIdFactory::ctor(::java::net::InetAddress* localIP, int32_t port, ::rice::environment::Environment* env)
{
    super::ctor();
    this->environment = env;
    this->port = port;
    this->logger = npc(npc(environment)->getLogManager())->getLogger(CertifiedNodeIdFactory::class_(), nullptr);
    this->realFactory = new IPNodeIdFactory(localIP, port, env);
}

rice::pastry::Id* rice::pastry::standard::CertifiedNodeIdFactory::generateNodeId()
{
    ::rice::p2p::util::XMLObjectInputStream* xois = nullptr;
    {
        auto finally0 = finally([&] {
            try {
                if(xois != nullptr)
                    npc(xois)->close();

            } catch (::java::io::IOException* e) {
                throw new ::java::lang::RuntimeException(static_cast< ::java::lang::Throwable* >(e));
            }
        });
        try {
            auto f = new ::java::io::File(NODE_ID_FILENAME_);
            if(!npc(f)->exists()) {
                auto g = new ::java::io::File(::java::lang::StringBuilder().append(u"."_j)->append(NODE_ID_FILENAME_)
                    ->append(u"-"_j)
                    ->append(port)->toString());
                if(npc(g)->exists())
                    npc(g)->renameTo(f);

            }
            if(npc(f)->exists()) {
                xois = new ::rice::p2p::util::XMLObjectInputStream(new ::java::io::FileInputStream(f));
                return java_cast< ::rice::pastry::Id* >(npc(xois)->readObject());
            } else {
                if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                    npc(logger)->log(u"Unable to find NodeID certificate - exiting."_j);

                throw new ::java::lang::RuntimeException(::java::lang::StringBuilder().append(u"Unable to find NodeID certificate - make sure that the NodeID certificate file '"_j)->append(NODE_ID_FILENAME_)
                    ->append(u"' exists in your ePOST directory."_j)->toString());
            }
        } catch (::java::io::IOException* e) {
            if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                npc(logger)->logException(u""_j, e);

            throw new ::java::lang::RuntimeException(static_cast< ::java::lang::Throwable* >(e));
        } catch (::java::lang::ClassNotFoundException* e) {
            if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                npc(logger)->logException(u""_j, e);

            throw new ::java::lang::RuntimeException(static_cast< ::java::lang::Throwable* >(e));
        }
    }
}

void rice::pastry::standard::CertifiedNodeIdFactory::generateCertificate(::rice::pastry::Id* id, ::java::io::OutputStream* os, ::java::security::PrivateKey* key)
{
    clinit();
    try {
        auto baos = new ::java::io::ByteArrayOutputStream();
        auto xoos = new ::rice::p2p::util::XMLObjectOutputStream(baos);
        npc(xoos)->writeObject(static_cast< ::java::lang::Object* >(id));
        npc(xoos)->close();
        auto xoos2 = new ::rice::p2p::util::XMLObjectOutputStream(os);
        npc(xoos2)->writeObject(static_cast< ::java::lang::Object* >(id));
        npc(xoos2)->write(::rice::p2p::util::SecurityUtils::sign(npc(baos)->toByteArray_(), key));
        npc(xoos2)->close();
    } catch (::java::io::IOException* e) {
        throw new ::java::lang::RuntimeException(static_cast< ::java::lang::Throwable* >(e));
    }
}

void rice::pastry::standard::CertifiedNodeIdFactory::main(::java::lang::StringArray* args) /* throws(Exception) */
{
    clinit();
    auto pw = getArg(args, u"-pw"_j);
    auto caDirectory = getArg(args, u"-ca"_j);
    auto out = getArg(args, u"-out"_j);
    auto f = new ::java::io::File(caDirectory, u"ca.keypair.enc"_j);
    auto fis = new ::java::io::FileInputStream(f);
    ::java::io::ObjectInputStream* ois = new ::rice::p2p::util::XMLObjectInputStream(new ::java::io::BufferedInputStream(new ::java::util::zip::GZIPInputStream(fis)));
    auto cipher = java_cast< ::int8_tArray* >(npc(ois)->readObject());
    auto caPair = java_cast< ::java::security::KeyPair* >(::rice::p2p::util::SecurityUtils::deserialize(::rice::p2p::util::SecurityUtils::decryptSymmetric(cipher, ::rice::p2p::util::SecurityUtils::hash(npc(pw)->getBytes()))));
    auto env = new ::rice::environment::Environment();
    generateCertificate((new RandomNodeIdFactory(env))->generateNodeId(), new ::java::io::FileOutputStream(new ::java::io::File(NODE_ID_FILENAME_)), npc(caPair)->getPrivate());
    npc(env)->destroy();
}

java::lang::String* rice::pastry::standard::CertifiedNodeIdFactory::getArg(::java::lang::StringArray* args, ::java::lang::String* argType)
{
    clinit();
    for (auto i = int32_t(0); i < npc(args)->length; i++) {
        if(npc((*args)[i])->startsWith(argType)) {
            if(npc(args)->length > i + int32_t(1)) {
                auto ret = (*args)[i + int32_t(1)];
                if(!npc(ret)->startsWith(u"-"_j))
                    return ret;

            }
        }
    }
    return nullptr;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::standard::CertifiedNodeIdFactory::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.standard.CertifiedNodeIdFactory", 43);
    return c;
}

void rice::pastry::standard::CertifiedNodeIdFactory::clinit()
{
    super::clinit();
    static bool in_cl_init = false;
struct clinit_ {
    clinit_() {
        in_cl_init = true;
        NODE_ID_FILENAME_ = u"nodeId"_j;
    }
};

    if(!in_cl_init) {
        static clinit_ clinit_instance;
    }
}

java::lang::Class* rice::pastry::standard::CertifiedNodeIdFactory::getClass0()
{
    return class_();
}

