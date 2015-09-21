// Generated from /pastry-2.1/src/org/mpisws/p2p/filetransfer/TempFileAllocationStrategy.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/nio/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/filetransfer/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/filetransfer/FileAllocationStrategy.hpp>

struct default_init_tag;

class org::mpisws::p2p::filetransfer::TempFileAllocationStrategy
    : public virtual ::java::lang::Object
    , public virtual FileAllocationStrategy
{

public:
    typedef ::java::lang::Object super;

public: /* protected */
    ::java::lang::String* prefix {  };
    ::java::lang::String* suffix {  };
    ::java::io::File* dir {  };
protected:
    void ctor();
    void ctor(::java::lang::String* prefix, ::java::lang::String* suffix);
    void ctor(::java::lang::String* prefix, ::java::lang::String* suffix, ::java::io::File* directory);

public:
    ::java::io::File* getFile(::java::nio::ByteBuffer* metadata, int64_t offset, int64_t length) /* throws(IOException) */ override;
    void fileCancelled(::java::nio::ByteBuffer* metadata, ::java::io::File* f, int64_t offset, int64_t downloadedLength, int64_t requestedLength, ::java::lang::Exception* reason) override;

    // Generated
    TempFileAllocationStrategy();
    TempFileAllocationStrategy(::java::lang::String* prefix, ::java::lang::String* suffix);
    TempFileAllocationStrategy(::java::lang::String* prefix, ::java::lang::String* suffix, ::java::io::File* directory);
protected:
    TempFileAllocationStrategy(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
