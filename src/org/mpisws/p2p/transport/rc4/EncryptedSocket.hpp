// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/rc4/EncryptedSocket.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/nio/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <javax/crypto/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/rc4/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/util/SocketWrapperSocket.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::rc4::EncryptedSocket
    : public ::org::mpisws::p2p::transport::util::SocketWrapperSocket
{

public:
    typedef ::org::mpisws::p2p::transport::util::SocketWrapperSocket super;
    ::javax::crypto::Cipher* encryptCipher {  };
    ::javax::crypto::Cipher* decryptCipher {  };

public: /* package */
    ::javax::crypto::SecretKey* key {  };
    ::int8_tArray* encryptedBytes {  };
    ::java::nio::ByteBuffer* encryptedWriteBuffer {  };
protected:
    void ctor(::java::lang::Object* identifier, ::org::mpisws::p2p::transport::P2PSocket* socket, ::rice::environment::logging::Logger* logger, ::org::mpisws::p2p::transport::ErrorHandler* handler, ::java::util::Map* options, ::javax::crypto::Cipher* encryptCipher, ::javax::crypto::Cipher* decryptCipher, int32_t writeBufferSize);

public:
    int64_t read(::java::nio::ByteBuffer* output) /* throws(IOException) */ override;
    int64_t write(::java::nio::ByteBuffer* srcs) /* throws(IOException) */ override;

public: /* protected */
    virtual int64_t writeHelper(::java::nio::ByteBuffer* srcs) /* throws(IOException) */;

public:
    void receiveSelectResult(::org::mpisws::p2p::transport::P2PSocket* socket, bool canRead, bool canWrite) /* throws(IOException) */ override;

    // Generated
    EncryptedSocket(::java::lang::Object* identifier, ::org::mpisws::p2p::transport::P2PSocket* socket, ::rice::environment::logging::Logger* logger, ::org::mpisws::p2p::transport::ErrorHandler* handler, ::java::util::Map* options, ::javax::crypto::Cipher* encryptCipher, ::javax::crypto::Cipher* decryptCipher, int32_t writeBufferSize);
protected:
    EncryptedSocket(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
