// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <atomic>
#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/net/fwd-pastry-2.1.hpp>
#include <java/nio/file/fwd-pastry-2.1.hpp>
#include <sun/misc/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <java/io/Serializable.hpp>
#include <java/lang/Comparable.hpp>

template<typename ComponentType, typename... Bases> struct SubArray;
namespace java
{
    namespace io
    {
typedef ::SubArray< ::java::io::Serializable, ::java::lang::ObjectArray > SerializableArray;
    } // io

    namespace lang
    {
typedef ::SubArray< ::java::lang::Comparable, ObjectArray > ComparableArray;
    } // lang

    namespace io
    {
typedef ::SubArray< ::java::io::File, ::java::lang::ObjectArray, SerializableArray, ::java::lang::ComparableArray > FileArray;
    } // io

    namespace lang
    {
typedef ::SubArray< ::java::lang::CharSequence, ObjectArray > CharSequenceArray;
typedef ::SubArray< ::java::lang::String, ObjectArray, ::java::io::SerializableArray, ComparableArray, CharSequenceArray > StringArray;
    } // lang
} // java

struct default_init_tag;

class java::io::File
    : public virtual ::java::lang::Object
    , public virtual Serializable
    , public virtual ::java::lang::Comparable
{

public:
    typedef ::java::lang::Object super;

private:
    static bool $assertionsDisabled_;
    static int64_t PATH_OFFSET_;
    static int64_t PREFIX_LENGTH_OFFSET_;
    static ::sun::misc::Unsafe* UNSAFE_;
    std::atomic< ::java::nio::file::Path* > filePath {  };
    static FileSystem* fs_;
    ::java::lang::String* path {  };
    static ::java::lang::String* pathSeparator_;
    static char16_t pathSeparatorChar_;
    int32_t prefixLength {  };
    static ::java::lang::String* separator_;
    static char16_t separatorChar_;
    static constexpr int64_t serialVersionUID { int64_t(301077366599181567LL) };
    File_PathStatus* status {  };

protected:
    void ctor(::java::lang::String* arg0);
    void ctor(::java::net::URI* arg0);
    /*void ctor(::java::lang::String* arg0, int32_t arg1); (private) */
    /*void ctor(::java::lang::String* arg0, File* arg1); (private) */
    void ctor(::java::lang::String* arg0, ::java::lang::String* arg1);
    void ctor(File* arg0, ::java::lang::String* arg1);

public:
    virtual bool canExecute();
    virtual bool canRead();
    virtual bool canWrite();
    virtual int32_t compareTo(File* arg0);
    virtual bool createNewFile();
    static File* createTempFile(::java::lang::String* arg0, ::java::lang::String* arg1);
    static File* createTempFile(::java::lang::String* arg0, ::java::lang::String* arg1, File* arg2);
    virtual bool delete_();
    virtual void deleteOnExit();
    bool equals(::java::lang::Object* arg0) override;
    virtual bool exists();
    virtual File* getAbsoluteFile();
    virtual ::java::lang::String* getAbsolutePath();
    virtual File* getCanonicalFile();
    virtual ::java::lang::String* getCanonicalPath();
    virtual int64_t getFreeSpace();
    virtual ::java::lang::String* getName();
    virtual ::java::lang::String* getParent();
    virtual File* getParentFile();
    virtual ::java::lang::String* getPath();

public: /* package */
    virtual int32_t getPrefixLength();

public:
    virtual int64_t getTotalSpace();
    virtual int64_t getUsableSpace();
    int32_t hashCode() override;
    virtual bool isAbsolute();
    virtual bool isDirectory();
    virtual bool isFile();
    virtual bool isHidden();

public: /* package */
    bool isInvalid();

public:
    virtual int64_t lastModified();
    virtual int64_t length();
    virtual ::java::lang::StringArray* list();
    virtual ::java::lang::StringArray* list(FilenameFilter* arg0);
    virtual FileArray* listFiles();
    virtual FileArray* listFiles(FilenameFilter* arg0);
    virtual FileArray* listFiles(FileFilter* arg0);
    static FileArray* listRoots();
    virtual bool mkdir();
    virtual bool mkdirs();
    /*void readObject(ObjectInputStream* arg0); (private) */
    virtual bool renameTo(File* arg0);
    virtual bool setExecutable(bool arg0);
    virtual bool setExecutable(bool arg0, bool arg1);
    virtual bool setLastModified(int64_t arg0);
    virtual bool setReadOnly();
    virtual bool setReadable(bool arg0);
    virtual bool setReadable(bool arg0, bool arg1);
    virtual bool setWritable(bool arg0);
    virtual bool setWritable(bool arg0, bool arg1);
    /*static ::java::lang::String* slashify(::java::lang::String* arg0, bool arg1); (private) */
    virtual ::java::nio::file::Path* toPath();
    ::java::lang::String* toString() override;
    virtual ::java::net::URI* toURI();
    virtual ::java::net::URL* toURL();
    /*void writeObject(ObjectOutputStream* arg0); (private) */

    // Generated
    File(::java::lang::String* arg0);
    File(::java::net::URI* arg0);
    File(::java::lang::String* arg0, ::java::lang::String* arg1);
    File(File* arg0, ::java::lang::String* arg1);
protected:
    File(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    virtual int32_t compareTo(::java::lang::Object* o) override;

public: /* package */
    static bool& $assertionsDisabled();

private:
    static int64_t& PATH_OFFSET();
    static int64_t& PREFIX_LENGTH_OFFSET();
    static ::sun::misc::Unsafe*& UNSAFE();
    static FileSystem*& fs();

public:
    static ::java::lang::String*& pathSeparator();
    static char16_t& pathSeparatorChar();
    static ::java::lang::String*& separator();
    static char16_t& separatorChar();

private:
    virtual ::java::lang::Class* getClass0();
};
