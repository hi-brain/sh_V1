// This file is generated by omniidl (C++ backend) - omniORB_4_1. Do not edit.

#include "shmodel_type.hh"

OMNI_USING_NAMESPACE(omni)

static const char* _0RL_dyn_library_version = omniORB_4_1_dyn;

static ::CORBA::TypeCode::_Tracker _0RL_tcTrack(__FILE__);

static CORBA::PR_structMember _0RL_structmember_shmodel__type[] = {
  {"length", CORBA::TypeCode::PR_long_tc()},
  {"width", CORBA::TypeCode::PR_long_tc()},
  {"time", CORBA::TypeCode::PR_long_tc()},
  {"pop_length", CORBA::TypeCode::PR_long_tc()},
  {"pop_width", CORBA::TypeCode::PR_long_tc()},
  {"ind_length", CORBA::TypeCode::PR_long_tc()},
  {"ind_width", CORBA::TypeCode::PR_long_tc()},
  {"s_data", CORBA::TypeCode::PR_sequence_tc(0, CORBA::TypeCode::PR_double_tc(), &_0RL_tcTrack)},
  {"pop", CORBA::TypeCode::PR_sequence_tc(0, CORBA::TypeCode::PR_double_tc(), &_0RL_tcTrack)},
  {"ind", CORBA::TypeCode::PR_sequence_tc(0, CORBA::TypeCode::PR_double_tc(), &_0RL_tcTrack)},
  {"nume", CORBA::TypeCode::PR_sequence_tc(0, CORBA::TypeCode::PR_double_tc(), &_0RL_tcTrack)},
  {"deno", CORBA::TypeCode::PR_sequence_tc(0, CORBA::TypeCode::PR_double_tc(), &_0RL_tcTrack)}
};

#ifdef _0RL_tc_shmodel__type
#  undef _0RL_tc_shmodel__type
#endif
static CORBA::TypeCode_ptr _0RL_tc_shmodel__type = CORBA::TypeCode::PR_struct_tc("IDL:shmodel_type:1.0", "shmodel_type", _0RL_structmember_shmodel__type, 12, &_0RL_tcTrack);

const CORBA::TypeCode_ptr _tc_shmodel_type = _0RL_tc_shmodel__type;


static void _0RL_shmodel__type_marshal_fn(cdrStream& _s, void* _v)
{
  shmodel_type* _p = (shmodel_type*)_v;
  *_p >>= _s;
}
static void _0RL_shmodel__type_unmarshal_fn(cdrStream& _s, void*& _v)
{
  shmodel_type* _p = new shmodel_type;
  *_p <<= _s;
  _v = _p;
}
static void _0RL_shmodel__type_destructor_fn(void* _v)
{
  shmodel_type* _p = (shmodel_type*)_v;
  delete _p;
}

void operator<<=(::CORBA::Any& _a, const shmodel_type& _s)
{
  shmodel_type* _p = new shmodel_type(_s);
  _a.PR_insert(_0RL_tc_shmodel__type,
               _0RL_shmodel__type_marshal_fn,
               _0RL_shmodel__type_destructor_fn,
               _p);
}
void operator<<=(::CORBA::Any& _a, shmodel_type* _sp)
{
  _a.PR_insert(_0RL_tc_shmodel__type,
               _0RL_shmodel__type_marshal_fn,
               _0RL_shmodel__type_destructor_fn,
               _sp);
}

::CORBA::Boolean operator>>=(const ::CORBA::Any& _a, shmodel_type*& _sp)
{
  return _a >>= (const shmodel_type*&) _sp;
}
::CORBA::Boolean operator>>=(const ::CORBA::Any& _a, const shmodel_type*& _sp)
{
  void* _v;
  if (_a.PR_extract(_0RL_tc_shmodel__type,
                    _0RL_shmodel__type_unmarshal_fn,
                    _0RL_shmodel__type_marshal_fn,
                    _0RL_shmodel__type_destructor_fn,
                    _v)) {
    _sp = (const shmodel_type*)_v;
    return 1;
  }
  return 0;
}

