// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <atomic>
#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/nio/channels/fwd-pastry-2.1.hpp>
#include <java/io/OutputStream.hpp>

struct default_init_tag;

class java::io::FileOutputStream
    : public OutputStream
{

public:
    typedef OutputStream super;

private:
    bool append {  };
    ::java::nio::channels::FileChannel* channel {  };
    ::java::lang::Object* closeLock {  };
    std::atomic< bool > closed {  };
    FileDescriptor* fd {  };
    ::java::lang::String* path {  };

protected:
    void ctor(::java::lang::String* arg0);
    void ctor(File* arg0);
    void ctor(FileDescriptor* arg0);
    void ctor(::java::lang::String* arg0, bool arg1);
    void ctor(File* arg0, bool arg1);

public:
    void close() override;
    /*void close0(); (private) */

public: /* protected */
    void finalize() override;

public:
    virtual ::java::nio::channels::FileChannel* getChannel();
    FileDescriptor* getFD();
    /*static void initIDs(); (private) */
    /*void open(::java::lang::String* arg0, bool arg1); (private) */
    /*void open0(::java::lang::String* arg0, bool arg1); (private) */
    void write(int32_t arg0) override;
    void write(::int8_tArray* arg0) override;
    /*void write(int32_t arg0, bool arg1); (private) */
    void write(::int8_tArray* arg0, int32_t arg1, int32_t arg2) override;
    /*void writeBytes(::int8_tArray* arg0, int32_t arg1, int32_t arg2, bool arg3); (private) */

    // Generated
    FileOutputStream(::java::lang::String* arg0);
    FileOutputStream(File* arg0);
    FileOutputStream(FileDescriptor* arg0);
    FileOutputStream(::java::lang::String* arg0, bool arg1);
    FileOutputStream(File* arg0, bool arg1);
protected:
    FileOutputStream(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
