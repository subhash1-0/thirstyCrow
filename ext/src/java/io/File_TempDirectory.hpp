// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/security/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct default_init_tag;

class java::io::File_TempDirectory
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;

private:
    static ::java::security::SecureRandom* random_;
    static File* tmpdir_;

    /*void ctor(); (private) */

public: /* package */
    static File* generateFile(::java::lang::String* arg0, ::java::lang::String* arg1, File* arg2);
    static File* location();

    // Generated

public:
    File_TempDirectory();
protected:
    File_TempDirectory(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    static ::java::security::SecureRandom*& random();
    static File*& tmpdir();
    virtual ::java::lang::Class* getClass0();
};
