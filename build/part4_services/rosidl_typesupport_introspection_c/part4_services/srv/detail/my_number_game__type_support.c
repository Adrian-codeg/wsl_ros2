// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from part4_services:srv/MyNumberGame.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "part4_services/srv/detail/my_number_game__rosidl_typesupport_introspection_c.h"
#include "part4_services/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "part4_services/srv/detail/my_number_game__functions.h"
#include "part4_services/srv/detail/my_number_game__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void part4_services__srv__MyNumberGame_Request__rosidl_typesupport_introspection_c__MyNumberGame_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  part4_services__srv__MyNumberGame_Request__init(message_memory);
}

void part4_services__srv__MyNumberGame_Request__rosidl_typesupport_introspection_c__MyNumberGame_Request_fini_function(void * message_memory)
{
  part4_services__srv__MyNumberGame_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember part4_services__srv__MyNumberGame_Request__rosidl_typesupport_introspection_c__MyNumberGame_Request_message_member_array[2] = {
  {
    "guess",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(part4_services__srv__MyNumberGame_Request, guess),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "cheat",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(part4_services__srv__MyNumberGame_Request, cheat),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers part4_services__srv__MyNumberGame_Request__rosidl_typesupport_introspection_c__MyNumberGame_Request_message_members = {
  "part4_services__srv",  // message namespace
  "MyNumberGame_Request",  // message name
  2,  // number of fields
  sizeof(part4_services__srv__MyNumberGame_Request),
  part4_services__srv__MyNumberGame_Request__rosidl_typesupport_introspection_c__MyNumberGame_Request_message_member_array,  // message members
  part4_services__srv__MyNumberGame_Request__rosidl_typesupport_introspection_c__MyNumberGame_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  part4_services__srv__MyNumberGame_Request__rosidl_typesupport_introspection_c__MyNumberGame_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t part4_services__srv__MyNumberGame_Request__rosidl_typesupport_introspection_c__MyNumberGame_Request_message_type_support_handle = {
  0,
  &part4_services__srv__MyNumberGame_Request__rosidl_typesupport_introspection_c__MyNumberGame_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_part4_services
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, part4_services, srv, MyNumberGame_Request)() {
  if (!part4_services__srv__MyNumberGame_Request__rosidl_typesupport_introspection_c__MyNumberGame_Request_message_type_support_handle.typesupport_identifier) {
    part4_services__srv__MyNumberGame_Request__rosidl_typesupport_introspection_c__MyNumberGame_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &part4_services__srv__MyNumberGame_Request__rosidl_typesupport_introspection_c__MyNumberGame_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "part4_services/srv/detail/my_number_game__rosidl_typesupport_introspection_c.h"
// already included above
// #include "part4_services/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "part4_services/srv/detail/my_number_game__functions.h"
// already included above
// #include "part4_services/srv/detail/my_number_game__struct.h"


// Include directives for member types
// Member `hint`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void part4_services__srv__MyNumberGame_Response__rosidl_typesupport_introspection_c__MyNumberGame_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  part4_services__srv__MyNumberGame_Response__init(message_memory);
}

void part4_services__srv__MyNumberGame_Response__rosidl_typesupport_introspection_c__MyNumberGame_Response_fini_function(void * message_memory)
{
  part4_services__srv__MyNumberGame_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember part4_services__srv__MyNumberGame_Response__rosidl_typesupport_introspection_c__MyNumberGame_Response_message_member_array[3] = {
  {
    "num_guesses",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(part4_services__srv__MyNumberGame_Response, num_guesses),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "hint",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(part4_services__srv__MyNumberGame_Response, hint),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "correct",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(part4_services__srv__MyNumberGame_Response, correct),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers part4_services__srv__MyNumberGame_Response__rosidl_typesupport_introspection_c__MyNumberGame_Response_message_members = {
  "part4_services__srv",  // message namespace
  "MyNumberGame_Response",  // message name
  3,  // number of fields
  sizeof(part4_services__srv__MyNumberGame_Response),
  part4_services__srv__MyNumberGame_Response__rosidl_typesupport_introspection_c__MyNumberGame_Response_message_member_array,  // message members
  part4_services__srv__MyNumberGame_Response__rosidl_typesupport_introspection_c__MyNumberGame_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  part4_services__srv__MyNumberGame_Response__rosidl_typesupport_introspection_c__MyNumberGame_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t part4_services__srv__MyNumberGame_Response__rosidl_typesupport_introspection_c__MyNumberGame_Response_message_type_support_handle = {
  0,
  &part4_services__srv__MyNumberGame_Response__rosidl_typesupport_introspection_c__MyNumberGame_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_part4_services
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, part4_services, srv, MyNumberGame_Response)() {
  if (!part4_services__srv__MyNumberGame_Response__rosidl_typesupport_introspection_c__MyNumberGame_Response_message_type_support_handle.typesupport_identifier) {
    part4_services__srv__MyNumberGame_Response__rosidl_typesupport_introspection_c__MyNumberGame_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &part4_services__srv__MyNumberGame_Response__rosidl_typesupport_introspection_c__MyNumberGame_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "part4_services/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "part4_services/srv/detail/my_number_game__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers part4_services__srv__detail__my_number_game__rosidl_typesupport_introspection_c__MyNumberGame_service_members = {
  "part4_services__srv",  // service namespace
  "MyNumberGame",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // part4_services__srv__detail__my_number_game__rosidl_typesupport_introspection_c__MyNumberGame_Request_message_type_support_handle,
  NULL  // response message
  // part4_services__srv__detail__my_number_game__rosidl_typesupport_introspection_c__MyNumberGame_Response_message_type_support_handle
};

static rosidl_service_type_support_t part4_services__srv__detail__my_number_game__rosidl_typesupport_introspection_c__MyNumberGame_service_type_support_handle = {
  0,
  &part4_services__srv__detail__my_number_game__rosidl_typesupport_introspection_c__MyNumberGame_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, part4_services, srv, MyNumberGame_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, part4_services, srv, MyNumberGame_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_part4_services
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, part4_services, srv, MyNumberGame)() {
  if (!part4_services__srv__detail__my_number_game__rosidl_typesupport_introspection_c__MyNumberGame_service_type_support_handle.typesupport_identifier) {
    part4_services__srv__detail__my_number_game__rosidl_typesupport_introspection_c__MyNumberGame_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)part4_services__srv__detail__my_number_game__rosidl_typesupport_introspection_c__MyNumberGame_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, part4_services, srv, MyNumberGame_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, part4_services, srv, MyNumberGame_Response)()->data;
  }

  return &part4_services__srv__detail__my_number_game__rosidl_typesupport_introspection_c__MyNumberGame_service_type_support_handle;
}
