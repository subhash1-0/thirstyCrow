// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/io/File.hpp>

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

extern void unimplemented_(const char16_t* name);
java::io::File::File(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::io::File::File(::java::lang::String* arg0)
    : File(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0);
}

java::io::File::File(::java::net::URI* arg0)
    : File(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0);
}

java::io::File::File(::java::lang::String* arg0, ::java::lang::String* arg1)
    : File(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0, arg1);
}

java::io::File::File(File* arg0, ::java::lang::String* arg1)
    : File(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0, arg1);
}

bool& java::io::File::$assertionsDisabled()
{
    clinit();
    return $assertionsDisabled_;
}
bool java::io::File::$assertionsDisabled_;
int64_t& java::io::File::PATH_OFFSET()
{
    clinit();
    return PATH_OFFSET_;
}
int64_t java::io::File::PATH_OFFSET_;
int64_t& java::io::File::PREFIX_LENGTH_OFFSET()
{
    clinit();
    return PREFIX_LENGTH_OFFSET_;
}
int64_t java::io::File::PREFIX_LENGTH_OFFSET_;
sun::misc::Unsafe*& java::io::File::UNSAFE()
{
    clinit();
    return UNSAFE_;
}
sun::misc::Unsafe* java::io::File::UNSAFE_;
java::io::FileSystem*& java::io::File::fs()
{
    clinit();
    return fs_;
}
java::io::FileSystem* java::io::File::fs_;
java::lang::String*& java::io::File::pathSeparator()
{
    clinit();
    return pathSeparator_;
}
java::lang::String* java::io::File::pathSeparator_;
char16_t& java::io::File::pathSeparatorChar()
{
    clinit();
    return pathSeparatorChar_;
}
char16_t java::io::File::pathSeparatorChar_;
java::lang::String*& java::io::File::separator()
{
    clinit();
    return separator_;
}
java::lang::String* java::io::File::separator_;
char16_t& java::io::File::separatorChar()
{
    clinit();
    return separatorChar_;
}
char16_t java::io::File::separatorChar_;
constexpr int64_t java::io::File::serialVersionUID;

void ::java::io::File::ctor(::java::lang::String* arg0)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::io::File::ctor(::java::lang::String* arg0)");
}

void ::java::io::File::ctor(::java::net::URI* arg0)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::io::File::ctor(::java::net::URI* arg0)");
}

/* private: void ::java::io::File::ctor(::java::lang::String* arg0, int32_t arg1) */
/* private: void ::java::io::File::ctor(::java::lang::String* arg0, File* arg1) */
void ::java::io::File::ctor(::java::lang::String* arg0, ::java::lang::String* arg1)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::io::File::ctor(::java::lang::String* arg0, ::java::lang::String* arg1)");
}

void ::java::io::File::ctor(File* arg0, ::java::lang::String* arg1)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::io::File::ctor(File* arg0, ::java::lang::String* arg1)");
}

bool java::io::File::canExecute()
{ /* stub */
    unimplemented_(u"bool java::io::File::canExecute()");
    return 0;
}

bool java::io::File::canRead()
{ /* stub */
    unimplemented_(u"bool java::io::File::canRead()");
    return 0;
}

bool java::io::File::canWrite()
{ /* stub */
    unimplemented_(u"bool java::io::File::canWrite()");
    return 0;
}

int32_t java::io::File::compareTo(File* arg0)
{ /* stub */
    unimplemented_(u"int32_t java::io::File::compareTo(File* arg0)");
    return 0;
}

int32_t java::io::File::compareTo(::java::lang::Object* o)
{ 
    return compareTo(dynamic_cast< File* >(o));
}

bool java::io::File::createNewFile()
{ /* stub */
    unimplemented_(u"bool java::io::File::createNewFile()");
    return 0;
}

java::io::File* java::io::File::createTempFile(::java::lang::String* arg0, ::java::lang::String* arg1)
{ /* stub */
    clinit();
    unimplemented_(u"java::io::File* java::io::File::createTempFile(::java::lang::String* arg0, ::java::lang::String* arg1)");
    return 0;
}

java::io::File* java::io::File::createTempFile(::java::lang::String* arg0, ::java::lang::String* arg1, File* arg2)
{ /* stub */
    clinit();
    unimplemented_(u"java::io::File* java::io::File::createTempFile(::java::lang::String* arg0, ::java::lang::String* arg1, File* arg2)");
    return 0;
}

bool java::io::File::delete_()
{ /* stub */
    unimplemented_(u"bool java::io::File::delete_()");
    return 0;
}

void java::io::File::deleteOnExit()
{ /* stub */
    unimplemented_(u"void java::io::File::deleteOnExit()");
}

bool java::io::File::equals(::java::lang::Object* arg0)
{ /* stub */
    unimplemented_(u"bool java::io::File::equals(::java::lang::Object* arg0)");
    return 0;
}

bool java::io::File::exists()
{ /* stub */
    unimplemented_(u"bool java::io::File::exists()");
    return 0;
}

java::io::File* java::io::File::getAbsoluteFile()
{ /* stub */
    unimplemented_(u"java::io::File* java::io::File::getAbsoluteFile()");
    return 0;
}

java::lang::String* java::io::File::getAbsolutePath()
{ /* stub */
    unimplemented_(u"java::lang::String* java::io::File::getAbsolutePath()");
    return 0;
}

java::io::File* java::io::File::getCanonicalFile()
{ /* stub */
    unimplemented_(u"java::io::File* java::io::File::getCanonicalFile()");
    return 0;
}

java::lang::String* java::io::File::getCanonicalPath()
{ /* stub */
    unimplemented_(u"java::lang::String* java::io::File::getCanonicalPath()");
    return 0;
}

int64_t java::io::File::getFreeSpace()
{ /* stub */
    unimplemented_(u"int64_t java::io::File::getFreeSpace()");
    return 0;
}

java::lang::String* java::io::File::getName()
{ /* stub */
    unimplemented_(u"java::lang::String* java::io::File::getName()");
    return 0;
}

java::lang::String* java::io::File::getParent()
{ /* stub */
    unimplemented_(u"java::lang::String* java::io::File::getParent()");
    return 0;
}

java::io::File* java::io::File::getParentFile()
{ /* stub */
    unimplemented_(u"java::io::File* java::io::File::getParentFile()");
    return 0;
}

java::lang::String* java::io::File::getPath()
{ /* stub */
return path ; /* getter */
}

int32_t java::io::File::getPrefixLength()
{ /* stub */
return prefixLength ; /* getter */
}

int64_t java::io::File::getTotalSpace()
{ /* stub */
    unimplemented_(u"int64_t java::io::File::getTotalSpace()");
    return 0;
}

int64_t java::io::File::getUsableSpace()
{ /* stub */
    unimplemented_(u"int64_t java::io::File::getUsableSpace()");
    return 0;
}

int32_t java::io::File::hashCode()
{ /* stub */
    unimplemented_(u"int32_t java::io::File::hashCode()");
    return 0;
}

bool java::io::File::isAbsolute()
{ /* stub */
    unimplemented_(u"bool java::io::File::isAbsolute()");
    return 0;
}

bool java::io::File::isDirectory()
{ /* stub */
    unimplemented_(u"bool java::io::File::isDirectory()");
    return 0;
}

bool java::io::File::isFile()
{ /* stub */
    unimplemented_(u"bool java::io::File::isFile()");
    return 0;
}

bool java::io::File::isHidden()
{ /* stub */
    unimplemented_(u"bool java::io::File::isHidden()");
    return 0;
}

bool java::io::File::isInvalid()
{ /* stub */
    unimplemented_(u"bool java::io::File::isInvalid()");
    return 0;
}

int64_t java::io::File::lastModified()
{ /* stub */
    unimplemented_(u"int64_t java::io::File::lastModified()");
    return 0;
}

int64_t java::io::File::length()
{ /* stub */
    unimplemented_(u"int64_t java::io::File::length()");
    return 0;
}

java::lang::StringArray* java::io::File::list()
{ /* stub */
    unimplemented_(u"java::lang::StringArray* java::io::File::list()");
    return 0;
}

java::lang::StringArray* java::io::File::list(FilenameFilter* arg0)
{ /* stub */
    unimplemented_(u"java::lang::StringArray* java::io::File::list(FilenameFilter* arg0)");
    return 0;
}

java::io::FileArray* java::io::File::listFiles()
{ /* stub */
    unimplemented_(u"java::io::FileArray* java::io::File::listFiles()");
    return 0;
}

java::io::FileArray* java::io::File::listFiles(FilenameFilter* arg0)
{ /* stub */
    unimplemented_(u"java::io::FileArray* java::io::File::listFiles(FilenameFilter* arg0)");
    return 0;
}

java::io::FileArray* java::io::File::listFiles(FileFilter* arg0)
{ /* stub */
    unimplemented_(u"java::io::FileArray* java::io::File::listFiles(FileFilter* arg0)");
    return 0;
}

java::io::FileArray* java::io::File::listRoots()
{ /* stub */
    clinit();
    unimplemented_(u"java::io::FileArray* java::io::File::listRoots()");
    return 0;
}

bool java::io::File::mkdir()
{ /* stub */
    unimplemented_(u"bool java::io::File::mkdir()");
    return 0;
}

bool java::io::File::mkdirs()
{ /* stub */
    unimplemented_(u"bool java::io::File::mkdirs()");
    return 0;
}

/* private: void java::io::File::readObject(ObjectInputStream* arg0) */
bool java::io::File::renameTo(File* arg0)
{ /* stub */
    unimplemented_(u"bool java::io::File::renameTo(File* arg0)");
    return 0;
}

bool java::io::File::setExecutable(bool arg0)
{ /* stub */
    unimplemented_(u"bool java::io::File::setExecutable(bool arg0)");
    return 0;
}

bool java::io::File::setExecutable(bool arg0, bool arg1)
{ /* stub */
    unimplemented_(u"bool java::io::File::setExecutable(bool arg0, bool arg1)");
    return 0;
}

bool java::io::File::setLastModified(int64_t arg0)
{ /* stub */
    unimplemented_(u"bool java::io::File::setLastModified(int64_t arg0)");
    return 0;
}

bool java::io::File::setReadOnly()
{ /* stub */
    unimplemented_(u"bool java::io::File::setReadOnly()");
    return 0;
}

bool java::io::File::setReadable(bool arg0)
{ /* stub */
    unimplemented_(u"bool java::io::File::setReadable(bool arg0)");
    return 0;
}

bool java::io::File::setReadable(bool arg0, bool arg1)
{ /* stub */
    unimplemented_(u"bool java::io::File::setReadable(bool arg0, bool arg1)");
    return 0;
}

bool java::io::File::setWritable(bool arg0)
{ /* stub */
    unimplemented_(u"bool java::io::File::setWritable(bool arg0)");
    return 0;
}

bool java::io::File::setWritable(bool arg0, bool arg1)
{ /* stub */
    unimplemented_(u"bool java::io::File::setWritable(bool arg0, bool arg1)");
    return 0;
}

/* private: java::lang::String* java::io::File::slashify(::java::lang::String* arg0, bool arg1) */
java::nio::file::Path* java::io::File::toPath()
{ /* stub */
    unimplemented_(u"java::nio::file::Path* java::io::File::toPath()");
    return 0;
}

java::lang::String* java::io::File::toString()
{ /* stub */
    unimplemented_(u"java::lang::String* java::io::File::toString()");
    return 0;
}

java::net::URI* java::io::File::toURI()
{ /* stub */
    unimplemented_(u"java::net::URI* java::io::File::toURI()");
    return 0;
}

java::net::URL* java::io::File::toURL()
{ /* stub */
    unimplemented_(u"java::net::URL* java::io::File::toURL()");
    return 0;
}

/* private: void java::io::File::writeObject(ObjectOutputStream* arg0) */
extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::io::File::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.io.File", 12);
    return c;
}

java::lang::Class* java::io::File::getClass0()
{
    return class_();
}

