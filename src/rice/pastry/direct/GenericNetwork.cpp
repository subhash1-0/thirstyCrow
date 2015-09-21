// Generated from /pastry-2.1/src/rice/pastry/direct/GenericNetwork.java
#include <rice/pastry/direct/GenericNetwork.hpp>

#include <java/io/File.hpp>
#include <rice/pastry/direct/proximitygenerators/GenericProximityGenerator.hpp>

rice::pastry::direct::GenericNetwork::GenericNetwork(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::direct::GenericNetwork::GenericNetwork(::rice::environment::Environment* env, ::java::lang::String* inFile)  /* throws(IOException) */
    : GenericNetwork(*static_cast< ::default_init_tag* >(0))
{
    ctor(env,inFile);
}

rice::pastry::direct::GenericNetwork::GenericNetwork(::rice::environment::Environment* env)  /* throws(IOException) */
    : GenericNetwork(*static_cast< ::default_init_tag* >(0))
{
    ctor(env);
}

rice::pastry::direct::GenericNetwork::GenericNetwork(::rice::environment::Environment* env, ::java::io::File* inFile)  /* throws(IOException) */
    : GenericNetwork(*static_cast< ::default_init_tag* >(0))
{
    ctor(env,inFile);
}

void rice::pastry::direct::GenericNetwork::ctor(::rice::environment::Environment* env, ::java::lang::String* inFile) /* throws(IOException) */
{
    ctor(env, new ::java::io::File(inFile));
}

void rice::pastry::direct::GenericNetwork::ctor(::rice::environment::Environment* env) /* throws(IOException) */
{
    ctor(env, static_cast< ::java::io::File* >(nullptr));
}

void rice::pastry::direct::GenericNetwork::ctor(::rice::environment::Environment* env, ::java::io::File* inFile) /* throws(IOException) */
{
    super::ctor(env, new ::rice::pastry::direct::proximitygenerators::GenericProximityGenerator(env, inFile));
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::direct::GenericNetwork::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.direct.GenericNetwork", 33);
    return c;
}

java::lang::Class* rice::pastry::direct::GenericNetwork::getClass0()
{
    return class_();
}

