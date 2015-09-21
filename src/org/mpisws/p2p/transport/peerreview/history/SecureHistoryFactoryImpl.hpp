// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/history/SecureHistoryFactoryImpl.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/history/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/p2p/util/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/peerreview/history/SecureHistoryFactory.hpp>
#include <org/mpisws/p2p/transport/peerreview/history/IndexEntryFactory.hpp>
#include <org/mpisws/p2p/transport/peerreview/PeerReviewConstants.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::peerreview::history::SecureHistoryFactoryImpl
    : public virtual ::java::lang::Object
    , public virtual SecureHistoryFactory
    , public virtual IndexEntryFactory
    , public virtual ::org::mpisws::p2p::transport::peerreview::PeerReviewConstants
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    ::rice::environment::Environment* environment {  };
    HashProvider* hashProv {  };
protected:
    void ctor(HashProvider* hashProv, ::rice::environment::Environment* env);

public:
    SecureHistory* create(::java::lang::String* name, int64_t baseSeq, ::int8_tArray* baseHash) /* throws(IOException) */ override;

public: /* protected */
    virtual SecureHistoryImpl* makeSecureHistory(::rice::p2p::util::RandomAccessFileIOBuffer* indexFile, ::rice::p2p::util::RandomAccessFileIOBuffer* dataFile, bool readOnly, HashProvider* hashProv, IndexEntryFactory* indexFactory, ::rice::environment::logging::Logger* logger) /* throws(IOException) */;

public:
    SecureHistory* open(::java::lang::String* name, ::java::lang::String* mode) /* throws(IOException) */ override;
    IndexEntry* build(::rice::p2p::commonapi::rawserialization::InputBuffer* buf) /* throws(IOException) */ override;
    int32_t getSerializedSize() override;
    SecureHistory* createTemp(int64_t baseSeq, ::int8_tArray* baseHash) /* throws(IOException) */ override;

    // Generated
    SecureHistoryFactoryImpl(HashProvider* hashProv, ::rice::environment::Environment* env);
protected:
    SecureHistoryFactoryImpl(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
