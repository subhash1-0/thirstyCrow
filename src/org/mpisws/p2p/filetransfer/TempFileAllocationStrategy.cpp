// Generated from /pastry-2.1/src/org/mpisws/p2p/filetransfer/TempFileAllocationStrategy.java
#include <org/mpisws/p2p/filetransfer/TempFileAllocationStrategy.hpp>

#include <java/io/File.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/String.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::filetransfer::TempFileAllocationStrategy::TempFileAllocationStrategy(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::filetransfer::TempFileAllocationStrategy::TempFileAllocationStrategy() 
    : TempFileAllocationStrategy(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

org::mpisws::p2p::filetransfer::TempFileAllocationStrategy::TempFileAllocationStrategy(::java::lang::String* prefix, ::java::lang::String* suffix) 
    : TempFileAllocationStrategy(*static_cast< ::default_init_tag* >(0))
{
    ctor(prefix,suffix);
}

org::mpisws::p2p::filetransfer::TempFileAllocationStrategy::TempFileAllocationStrategy(::java::lang::String* prefix, ::java::lang::String* suffix, ::java::io::File* directory) 
    : TempFileAllocationStrategy(*static_cast< ::default_init_tag* >(0))
{
    ctor(prefix,suffix,directory);
}

void org::mpisws::p2p::filetransfer::TempFileAllocationStrategy::ctor()
{
    ctor(u"FreePastry"_j, nullptr);
}

void org::mpisws::p2p::filetransfer::TempFileAllocationStrategy::ctor(::java::lang::String* prefix, ::java::lang::String* suffix)
{
    ctor(prefix, suffix, nullptr);
}

void org::mpisws::p2p::filetransfer::TempFileAllocationStrategy::ctor(::java::lang::String* prefix, ::java::lang::String* suffix, ::java::io::File* directory)
{
    super::ctor();
    this->prefix = prefix;
    this->suffix = suffix;
    this->dir = directory;
}

java::io::File* org::mpisws::p2p::filetransfer::TempFileAllocationStrategy::getFile(::java::nio::ByteBuffer* metadata, int64_t offset, int64_t length) /* throws(IOException) */
{
    auto temp = ::java::io::File::createTempFile(prefix, suffix, dir);
    return temp;
}

void org::mpisws::p2p::filetransfer::TempFileAllocationStrategy::fileCancelled(::java::nio::ByteBuffer* metadata, ::java::io::File* f, int64_t offset, int64_t downloadedLength, int64_t requestedLength, ::java::lang::Exception* reason)
{
    npc(f)->delete_();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::filetransfer::TempFileAllocationStrategy::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.filetransfer.TempFileAllocationStrategy", 54);
    return c;
}

java::lang::Class* org::mpisws::p2p::filetransfer::TempFileAllocationStrategy::getClass0()
{
    return class_();
}

