// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/commitment/AuthenticatorStoreImpl.java
#include <org/mpisws/p2p/transport/peerreview/commitment/AuthenticatorStoreImpl.hpp>

#include <java/io/IOException.hpp>
#include <java/lang/Class.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Long.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/RuntimeException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/util/ArrayList.hpp>
#include <java/util/Collection.hpp>
#include <java/util/Collections.hpp>
#include <java/util/HashMap.hpp>
#include <java/util/Iterator.hpp>
#include <java/util/List.hpp>
#include <java/util/Map.hpp>
#include <java/util/Set.hpp>
#include <java/util/SortedSet.hpp>
#include <java/util/TreeSet.hpp>
#include <org/mpisws/p2p/transport/peerreview/PeerReview.hpp>
#include <org/mpisws/p2p/transport/peerreview/commitment/Authenticator.hpp>
#include <org/mpisws/p2p/transport/peerreview/commitment/AuthenticatorSerializer.hpp>
#include <org/mpisws/p2p/transport/util/Serializer.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/LogManager.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/p2p/commonapi/rawserialization/RawSerializable.hpp>
#include <rice/p2p/util/RandomAccessFileIOBuffer.hpp>
#include <Array.hpp>

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
org::mpisws::p2p::transport::peerreview::commitment::AuthenticatorStoreImpl::AuthenticatorStoreImpl(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::transport::peerreview::commitment::AuthenticatorStoreImpl::AuthenticatorStoreImpl(::org::mpisws::p2p::transport::peerreview::PeerReview* peerreview) 
    : AuthenticatorStoreImpl(*static_cast< ::default_init_tag* >(0))
{
    ctor(peerreview);
}

org::mpisws::p2p::transport::peerreview::commitment::AuthenticatorStoreImpl::AuthenticatorStoreImpl(::org::mpisws::p2p::transport::peerreview::PeerReview* peerreview, bool allowDuplicateSeqs) 
    : AuthenticatorStoreImpl(*static_cast< ::default_init_tag* >(0))
{
    ctor(peerreview,allowDuplicateSeqs);
}

void org::mpisws::p2p::transport::peerreview::commitment::AuthenticatorStoreImpl::init()
{
    memoryBufferDisabled = false;
}

void org::mpisws::p2p::transport::peerreview::commitment::AuthenticatorStoreImpl::ctor(::org::mpisws::p2p::transport::peerreview::PeerReview* peerreview)
{
    ctor(peerreview, false);
}

void org::mpisws::p2p::transport::peerreview::commitment::AuthenticatorStoreImpl::ctor(::org::mpisws::p2p::transport::peerreview::PeerReview* peerreview, bool allowDuplicateSeqs)
{
    super::ctor();
    init();
    this->allowDuplicateSeqs = allowDuplicateSeqs;
    this->authenticators = new ::java::util::HashMap();
    this->authFile = nullptr;
    this->numSubjects = 0;
    this->peerreview = peerreview;
    this->authenticatorSerializer = npc(peerreview)->getAuthenticatorSerializer();
    this->idSerializer = npc(peerreview)->getIdSerializer();
    logger = npc(npc(npc(peerreview)->getEnvironment())->getLogManager())->getLogger(AuthenticatorStoreImpl::class_(), nullptr);
}

void org::mpisws::p2p::transport::peerreview::commitment::AuthenticatorStoreImpl::destroy()
{
    npc(authenticators)->clear();
    if(authFile != nullptr) {
        {
            auto finally0 = finally([&] {
                authFile = nullptr;
            });
            try {
                npc(authFile)->close();
            } catch (::java::io::IOException* ioe) {
                npc(logger)->logException(::java::lang::StringBuilder().append(u"Couldn't close authFile "_j)->append(static_cast< ::java::lang::Object* >(authFile))->toString(), ioe);
            }
        }
    }
}

void org::mpisws::p2p::transport::peerreview::commitment::AuthenticatorStoreImpl::setFilename(::java::io::File* file) /* throws(IOException) */
{
    if(authFile != nullptr) {
        npc(authFile)->close();
        authFile = nullptr;
    }
    authFile = new ::rice::p2p::util::RandomAccessFileIOBuffer(file, u"rw"_j);
    auto authenticatorsRead = int32_t(0);
    auto bytesRead = int32_t(0);
    int64_t pos = int32_t(0);
    npc(authFile)->seek(pos);
    while (npc(authFile)->bytesRemaining() > 0) {
        try {
            auto id = java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(idSerializer)->deserialize(authFile));
            auto authenticator = npc(authenticatorSerializer)->deserialize(authFile);
            addAuthenticatorToMemory(id, authenticator);
            authenticatorsRead++;
            pos = npc(authFile)->getFilePointer();
        } catch (::java::io::IOException* ioe) {
            break;
        }
    }
    npc(authFile)->setLength(pos);
    npc(authFile)->seek(npc(authFile)->length());
}

void org::mpisws::p2p::transport::peerreview::commitment::AuthenticatorStoreImpl::addAuthenticatorToMemory(::rice::p2p::commonapi::rawserialization::RawSerializable* id, Authenticator* authenticator)
{
    auto list = java_cast< ::java::util::SortedSet* >(npc(authenticators)->get(id));
    if(list == nullptr) {
        list = new ::java::util::TreeSet();
        npc(authenticators)->put(id, list);
    }
    if(!allowDuplicateSeqs) {
        auto sub = npc(list)->subSet(new Authenticator(npc(authenticator)->getSeq() + int32_t(1), static_cast< ::int8_tArray* >(nullptr), static_cast< ::int8_tArray* >(nullptr)), new Authenticator(npc(authenticator)->getSeq(), static_cast< ::int8_tArray* >(nullptr), static_cast< ::int8_tArray* >(nullptr)));
        if(!npc(sub)->isEmpty()) {
            if(!npc(sub)->contains(static_cast< ::java::lang::Object* >(authenticator))) {
                throw new ::java::lang::RuntimeException(::java::lang::StringBuilder().append(u"Adding duplicate auths for the same sequence number is not allowed for this store old:"_j)->append(static_cast< ::java::lang::Object* >(java_cast< Authenticator* >(npc(sub)->first())))
                    ->append(u" new:"_j)
                    ->append(static_cast< ::java::lang::Object* >(authenticator))->toString());
            }
        }
    }
    npc(list)->add(static_cast< ::java::lang::Object* >(authenticator));
}

void org::mpisws::p2p::transport::peerreview::commitment::AuthenticatorStoreImpl::flushAuthenticatorsFromMemory(::rice::p2p::commonapi::rawserialization::RawSerializable* id, int64_t minseq, int64_t maxseq)
{
    auto list = java_cast< ::java::util::SortedSet* >(npc(authenticators)->get(id));
    if(list != nullptr) {
        npc(list)->removeAll(static_cast< ::java::util::Collection* >(getAuthenticators(id, minseq, maxseq)));
    }
}

java::util::SortedSet* org::mpisws::p2p::transport::peerreview::commitment::AuthenticatorStoreImpl::findSubject(::rice::p2p::commonapi::rawserialization::RawSerializable* id)
{
    return java_cast< ::java::util::SortedSet* >(npc(authenticators)->get(id));
}

void org::mpisws::p2p::transport::peerreview::commitment::AuthenticatorStoreImpl::addAuthenticator(::rice::p2p::commonapi::rawserialization::RawSerializable* id, Authenticator* authenticator)
{
    try {
        if(authFile != nullptr) {
            npc(idSerializer)->serialize(id, authFile);
            npc(authenticator)->serialize(authFile);
        }
        if(!memoryBufferDisabled)
            addAuthenticatorToMemory(id, authenticator);

    } catch (::java::io::IOException* ioe) {
        throw new ::java::lang::RuntimeException(::java::lang::StringBuilder().append(u"Error in addAuthenticator("_j)->append(static_cast< ::java::lang::Object* >(id))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(authenticator))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(authFile))
            ->append(u")"_j)->toString(), ioe);
    }
}

void org::mpisws::p2p::transport::peerreview::commitment::AuthenticatorStoreImpl::addAuthenticator(::java::lang::Object* id, Authenticator* authenticator)
{ 
    addAuthenticator(dynamic_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(id), authenticator);
}

void org::mpisws::p2p::transport::peerreview::commitment::AuthenticatorStoreImpl::flushAuthenticatorsFor(::rice::p2p::commonapi::rawserialization::RawSerializable* id, int64_t minseq, int64_t maxseq)
{
    flushAuthenticatorsFromMemory(id, minseq, maxseq);
}

void org::mpisws::p2p::transport::peerreview::commitment::AuthenticatorStoreImpl::flushAuthenticatorsFor(::java::lang::Object* id, int64_t minseq, int64_t maxseq)
{ 
    flushAuthenticatorsFor(dynamic_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(id), minseq, maxseq);
}

void org::mpisws::p2p::transport::peerreview::commitment::AuthenticatorStoreImpl::flushAuthenticatorsFor(::rice::p2p::commonapi::rawserialization::RawSerializable* id)
{
    flushAuthenticatorsFor(id, ::java::lang::Long::MIN_VALUE, ::java::lang::Long::MAX_VALUE - int32_t(1));
}

void org::mpisws::p2p::transport::peerreview::commitment::AuthenticatorStoreImpl::flushAuthenticatorsFor(::java::lang::Object* id)
{ 
    flushAuthenticatorsFor(dynamic_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(id));
}

void org::mpisws::p2p::transport::peerreview::commitment::AuthenticatorStoreImpl::garbageCollect() /* throws(IOException) */
{
    if(authFile == nullptr)
        return;

    npc(authFile)->setLength(0);
    npc(authFile)->seek(0);
    for (auto _i = npc(npc(authenticators)->keySet())->iterator(); _i->hasNext(); ) {
        ::rice::p2p::commonapi::rawserialization::RawSerializable* i = java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(_i->next());
        {
            auto list = java_cast< ::java::util::SortedSet* >(npc(authenticators)->get(i));
            for (auto _i = npc(list)->iterator(); _i->hasNext(); ) {
                Authenticator* a = java_cast< Authenticator* >(_i->next());
                {
                    npc(idSerializer)->serialize(i, authFile);
                    npc(a)->serialize(authFile);
                }
            }
        }
    }
}

int32_t org::mpisws::p2p::transport::peerreview::commitment::AuthenticatorStoreImpl::getAuthenticatorSizeBytes()
{
    return npc(authenticatorSerializer)->getSerializedSize();
}

java::util::List* org::mpisws::p2p::transport::peerreview::commitment::AuthenticatorStoreImpl::getAuthenticators(::rice::p2p::commonapi::rawserialization::RawSerializable* id, int64_t minseq, int64_t maxseq)
{
    auto list = java_cast< ::java::util::SortedSet* >(npc(authenticators)->get(id));
    if(list != nullptr) {
        auto subList = npc(list)->subSet(new Authenticator(maxseq + int32_t(1), static_cast< ::int8_tArray* >(nullptr), static_cast< ::int8_tArray* >(nullptr)), new Authenticator(minseq, static_cast< ::int8_tArray* >(nullptr), static_cast< ::int8_tArray* >(nullptr)));
        return new ::java::util::ArrayList(static_cast< ::java::util::Collection* >(subList));
    }
    return ::java::util::Collections::emptyList();
}

java::util::List* org::mpisws::p2p::transport::peerreview::commitment::AuthenticatorStoreImpl::getAuthenticators(::java::lang::Object* id, int64_t minseq, int64_t maxseq)
{ 
    return getAuthenticators(dynamic_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(id), minseq, maxseq);
}

java::util::List* org::mpisws::p2p::transport::peerreview::commitment::AuthenticatorStoreImpl::getAuthenticators(::rice::p2p::commonapi::rawserialization::RawSerializable* id)
{
    return getAuthenticators(id, ::java::lang::Long::MIN_VALUE, ::java::lang::Long::MAX_VALUE - int32_t(1));
}

java::util::List* org::mpisws::p2p::transport::peerreview::commitment::AuthenticatorStoreImpl::getAuthenticators(::java::lang::Object* id)
{ 
    return getAuthenticators(dynamic_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(id));
}

org::mpisws::p2p::transport::peerreview::commitment::Authenticator* org::mpisws::p2p::transport::peerreview::commitment::AuthenticatorStoreImpl::getLastAuthenticatorBefore(::rice::p2p::commonapi::rawserialization::RawSerializable* id, int64_t seq)
{
    auto list = getAuthenticators(id, ::java::lang::Long::MIN_VALUE, seq);
    if(npc(list)->isEmpty())
        return nullptr;

    return java_cast< Authenticator* >(npc(list)->get(0));
}

org::mpisws::p2p::transport::peerreview::commitment::Authenticator* org::mpisws::p2p::transport::peerreview::commitment::AuthenticatorStoreImpl::getLastAuthenticatorBefore(::java::lang::Object* id, int64_t seq)
{ 
    return getLastAuthenticatorBefore(dynamic_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(id), seq);
}

org::mpisws::p2p::transport::peerreview::commitment::Authenticator* org::mpisws::p2p::transport::peerreview::commitment::AuthenticatorStoreImpl::getMostRecentAuthenticator(::rice::p2p::commonapi::rawserialization::RawSerializable* id)
{
    auto list = java_cast< ::java::util::SortedSet* >(npc(authenticators)->get(id));
    if(list == nullptr || npc(list)->isEmpty())
        return nullptr;

    return java_cast< Authenticator* >(npc(list)->first());
}

org::mpisws::p2p::transport::peerreview::commitment::Authenticator* org::mpisws::p2p::transport::peerreview::commitment::AuthenticatorStoreImpl::getMostRecentAuthenticator(::java::lang::Object* id)
{ 
    return getMostRecentAuthenticator(dynamic_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(id));
}

int32_t org::mpisws::p2p::transport::peerreview::commitment::AuthenticatorStoreImpl::getNumSubjects()
{
    return npc(authenticators)->size();
}

org::mpisws::p2p::transport::peerreview::commitment::Authenticator* org::mpisws::p2p::transport::peerreview::commitment::AuthenticatorStoreImpl::getOldestAuthenticator(::rice::p2p::commonapi::rawserialization::RawSerializable* id)
{
    auto list = java_cast< ::java::util::SortedSet* >(npc(authenticators)->get(id));
    if(list == nullptr)
        return nullptr;

    return java_cast< Authenticator* >(npc(list)->last());
}

org::mpisws::p2p::transport::peerreview::commitment::Authenticator* org::mpisws::p2p::transport::peerreview::commitment::AuthenticatorStoreImpl::getOldestAuthenticator(::java::lang::Object* id)
{ 
    return getOldestAuthenticator(dynamic_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(id));
}

java::util::List* org::mpisws::p2p::transport::peerreview::commitment::AuthenticatorStoreImpl::getSubjects()
{
    return new ::java::util::ArrayList(static_cast< ::java::util::Collection* >(npc(authenticators)->keySet()));
}

int32_t org::mpisws::p2p::transport::peerreview::commitment::AuthenticatorStoreImpl::numAuthenticatorsFor(::rice::p2p::commonapi::rawserialization::RawSerializable* id)
{
    auto list = java_cast< ::java::util::SortedSet* >(npc(authenticators)->get(id));
    if(list == nullptr)
        return 0;

    return npc(list)->size();
}

int32_t org::mpisws::p2p::transport::peerreview::commitment::AuthenticatorStoreImpl::numAuthenticatorsFor(::java::lang::Object* id)
{ 
    return numAuthenticatorsFor(dynamic_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(id));
}

int32_t org::mpisws::p2p::transport::peerreview::commitment::AuthenticatorStoreImpl::numAuthenticatorsFor(::rice::p2p::commonapi::rawserialization::RawSerializable* id, int64_t minseq, int64_t maxseq)
{
    return npc(getAuthenticators(id, minseq, maxseq))->size();
}

int32_t org::mpisws::p2p::transport::peerreview::commitment::AuthenticatorStoreImpl::numAuthenticatorsFor(::java::lang::Object* id, int64_t minseq, int64_t maxseq)
{ 
    return numAuthenticatorsFor(dynamic_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(id), minseq, maxseq);
}

org::mpisws::p2p::transport::peerreview::commitment::Authenticator* org::mpisws::p2p::transport::peerreview::commitment::AuthenticatorStoreImpl::statAuthenticator(::rice::p2p::commonapi::rawserialization::RawSerializable* id, int64_t seq)
{
    auto ret = getAuthenticators(id, seq, seq);
    if(ret == nullptr || npc(ret)->isEmpty())
        return nullptr;

    return java_cast< Authenticator* >(npc(ret)->get(0));
}

org::mpisws::p2p::transport::peerreview::commitment::Authenticator* org::mpisws::p2p::transport::peerreview::commitment::AuthenticatorStoreImpl::statAuthenticator(::java::lang::Object* id, int64_t seq)
{ 
    return statAuthenticator(dynamic_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(id), seq);
}

void org::mpisws::p2p::transport::peerreview::commitment::AuthenticatorStoreImpl::flush(::rice::p2p::commonapi::rawserialization::RawSerializable* id)
{
    npc(authenticators)->remove(id);
}

void org::mpisws::p2p::transport::peerreview::commitment::AuthenticatorStoreImpl::flush(::java::lang::Object* id)
{ 
    flush(dynamic_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(id));
}

void org::mpisws::p2p::transport::peerreview::commitment::AuthenticatorStoreImpl::flushAll()
{
    npc(authenticators)->clear();
}

void org::mpisws::p2p::transport::peerreview::commitment::AuthenticatorStoreImpl::disableMemoryBuffer()
{
    this->memoryBufferDisabled = true;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::peerreview::commitment::AuthenticatorStoreImpl::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.peerreview.commitment.AuthenticatorStoreImpl", 69);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::peerreview::commitment::AuthenticatorStoreImpl::getClass0()
{
    return class_();
}

