// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from part4_services:srv/MyNumberGame.idl
// generated code does not contain a copyright notice
#include "part4_services/srv/detail/my_number_game__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "part4_services/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "part4_services/srv/detail/my_number_game__struct.h"
#include "part4_services/srv/detail/my_number_game__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif


// forward declare type support functions


using _MyNumberGame_Request__ros_msg_type = part4_services__srv__MyNumberGame_Request;

static bool _MyNumberGame_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _MyNumberGame_Request__ros_msg_type * ros_message = static_cast<const _MyNumberGame_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: guess
  {
    cdr << ros_message->guess;
  }

  // Field name: cheat
  {
    cdr << (ros_message->cheat ? true : false);
  }

  return true;
}

static bool _MyNumberGame_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _MyNumberGame_Request__ros_msg_type * ros_message = static_cast<_MyNumberGame_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: guess
  {
    cdr >> ros_message->guess;
  }

  // Field name: cheat
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->cheat = tmp ? true : false;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_part4_services
size_t get_serialized_size_part4_services__srv__MyNumberGame_Request(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _MyNumberGame_Request__ros_msg_type * ros_message = static_cast<const _MyNumberGame_Request__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name guess
  {
    size_t item_size = sizeof(ros_message->guess);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name cheat
  {
    size_t item_size = sizeof(ros_message->cheat);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _MyNumberGame_Request__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_part4_services__srv__MyNumberGame_Request(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_part4_services
size_t max_serialized_size_part4_services__srv__MyNumberGame_Request(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: guess
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: cheat
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = part4_services__srv__MyNumberGame_Request;
    is_plain =
      (
      offsetof(DataType, cheat) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _MyNumberGame_Request__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_part4_services__srv__MyNumberGame_Request(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_MyNumberGame_Request = {
  "part4_services::srv",
  "MyNumberGame_Request",
  _MyNumberGame_Request__cdr_serialize,
  _MyNumberGame_Request__cdr_deserialize,
  _MyNumberGame_Request__get_serialized_size,
  _MyNumberGame_Request__max_serialized_size
};

static rosidl_message_type_support_t _MyNumberGame_Request__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_MyNumberGame_Request,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, part4_services, srv, MyNumberGame_Request)() {
  return &_MyNumberGame_Request__type_support;
}

#if defined(__cplusplus)
}
#endif

// already included above
// #include <cassert>
// already included above
// #include <limits>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "part4_services/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
// already included above
// #include "part4_services/srv/detail/my_number_game__struct.h"
// already included above
// #include "part4_services/srv/detail/my_number_game__functions.h"
// already included above
// #include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "rosidl_runtime_c/string.h"  // hint
#include "rosidl_runtime_c/string_functions.h"  // hint

// forward declare type support functions


using _MyNumberGame_Response__ros_msg_type = part4_services__srv__MyNumberGame_Response;

static bool _MyNumberGame_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _MyNumberGame_Response__ros_msg_type * ros_message = static_cast<const _MyNumberGame_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: num_guesses
  {
    cdr << ros_message->num_guesses;
  }

  // Field name: hint
  {
    const rosidl_runtime_c__String * str = &ros_message->hint;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: correct
  {
    cdr << (ros_message->correct ? true : false);
  }

  return true;
}

static bool _MyNumberGame_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _MyNumberGame_Response__ros_msg_type * ros_message = static_cast<_MyNumberGame_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: num_guesses
  {
    cdr >> ros_message->num_guesses;
  }

  // Field name: hint
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->hint.data) {
      rosidl_runtime_c__String__init(&ros_message->hint);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->hint,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'hint'\n");
      return false;
    }
  }

  // Field name: correct
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->correct = tmp ? true : false;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_part4_services
size_t get_serialized_size_part4_services__srv__MyNumberGame_Response(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _MyNumberGame_Response__ros_msg_type * ros_message = static_cast<const _MyNumberGame_Response__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name num_guesses
  {
    size_t item_size = sizeof(ros_message->num_guesses);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name hint
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->hint.size + 1);
  // field.name correct
  {
    size_t item_size = sizeof(ros_message->correct);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _MyNumberGame_Response__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_part4_services__srv__MyNumberGame_Response(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_part4_services
size_t max_serialized_size_part4_services__srv__MyNumberGame_Response(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: num_guesses
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: hint
  {
    size_t array_size = 1;

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }
  // member: correct
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = part4_services__srv__MyNumberGame_Response;
    is_plain =
      (
      offsetof(DataType, correct) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _MyNumberGame_Response__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_part4_services__srv__MyNumberGame_Response(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_MyNumberGame_Response = {
  "part4_services::srv",
  "MyNumberGame_Response",
  _MyNumberGame_Response__cdr_serialize,
  _MyNumberGame_Response__cdr_deserialize,
  _MyNumberGame_Response__get_serialized_size,
  _MyNumberGame_Response__max_serialized_size
};

static rosidl_message_type_support_t _MyNumberGame_Response__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_MyNumberGame_Response,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, part4_services, srv, MyNumberGame_Response)() {
  return &_MyNumberGame_Response__type_support;
}

#if defined(__cplusplus)
}
#endif

#include "rosidl_typesupport_fastrtps_cpp/service_type_support.h"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "part4_services/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "part4_services/srv/my_number_game.h"

#if defined(__cplusplus)
extern "C"
{
#endif

static service_type_support_callbacks_t MyNumberGame__callbacks = {
  "part4_services::srv",
  "MyNumberGame",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, part4_services, srv, MyNumberGame_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, part4_services, srv, MyNumberGame_Response)(),
};

static rosidl_service_type_support_t MyNumberGame__handle = {
  rosidl_typesupport_fastrtps_c__identifier,
  &MyNumberGame__callbacks,
  get_service_typesupport_handle_function,
};

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, part4_services, srv, MyNumberGame)() {
  return &MyNumberGame__handle;
}

#if defined(__cplusplus)
}
#endif
