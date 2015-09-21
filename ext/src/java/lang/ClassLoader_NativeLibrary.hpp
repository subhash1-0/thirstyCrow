// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct default_init_tag;

class java::lang::ClassLoader_NativeLibrary
    : public virtual Object
{

public:
    typedef Object super;

private:
    Class* fromClass {  };

public: /* package */
    int64_t handle {  };
    bool isBuiltin {  };

private:
    int32_t jniVersion {  };

public: /* package */
    bool loaded {  };
    String* name {  };

protected:
    void ctor(Class* arg0, String* arg1, bool arg2);

public: /* protected */
    void finalize() override;

public: /* package */
    virtual int64_t find(String* arg0);
    static String* findBuiltinLib(String* arg0);
    static Class* getFromClass();
    virtual void load(String* arg0, bool arg1);
    virtual void unload(String* arg0, bool arg1);

    // Generated

public:
    ClassLoader_NativeLibrary(Class* arg0, String* arg1, bool arg2);
protected:
    ClassLoader_NativeLibrary(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
