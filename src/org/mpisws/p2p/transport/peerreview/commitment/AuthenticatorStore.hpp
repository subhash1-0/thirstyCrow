// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/commitment/AuthenticatorStore.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/commitment/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct org::mpisws::p2p::transport::peerreview::commitment::AuthenticatorStore
    : public virtual ::java::lang::Object
{
    virtual void setFilename(::java::io::File* file) /* throws(IOException) */ = 0;
    virtual Authenticator* getMostRecentAuthenticator(::java::lang::Object* id) = 0;
    virtual Authenticator* getOldestAuthenticator(::java::lang::Object* id) = 0;
    virtual Authenticator* getLastAuthenticatorBefore(::java::lang::Object* id, int64_t seq) = 0;
    virtual void disableMemoryBuffer() = 0;
    virtual void addAuthenticator(::java::lang::Object* id, Authenticator* authenticator) = 0;
    virtual void garbageCollect() /* throws(IOException) */ = 0;
    virtual int32_t numAuthenticatorsFor(::java::lang::Object* id) = 0;
    virtual int32_t numAuthenticatorsFor(::java::lang::Object* id, int64_t minseq, int64_t maxseq) = 0;
    virtual void flushAuthenticatorsFor(::java::lang::Object* id, int64_t minseq, int64_t maxseq) = 0;
    virtual void flushAuthenticatorsFor(::java::lang::Object* id) = 0;
    virtual Authenticator* statAuthenticator(::java::lang::Object* id, int64_t seq) = 0;
    virtual ::java::util::List* getAuthenticators(::java::lang::Object* id, int64_t minseq, int64_t maxseq) = 0;
    virtual ::java::util::List* getAuthenticators(::java::lang::Object* id) = 0;
    virtual ::java::util::List* getSubjects() = 0;
    virtual int32_t getNumSubjects() = 0;
    virtual int32_t getAuthenticatorSizeBytes() = 0;
    virtual void flush(::java::lang::Object* id) = 0;
    virtual void flushAll() = 0;

    // Generated
    static ::java::lang::Class *class_();
};
