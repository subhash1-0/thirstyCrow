// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/io/InputStreamReader.hpp>

struct default_init_tag;

class java::io::FileReader
    : public InputStreamReader
{

public:
    typedef InputStreamReader super;

protected:
    void ctor(::java::lang::String* arg0);
    void ctor(File* arg0);
    void ctor(FileDescriptor* arg0);

    // Generated

public:
    FileReader(::java::lang::String* arg0);
    FileReader(File* arg0);
    FileReader(FileDescriptor* arg0);
protected:
    FileReader(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
