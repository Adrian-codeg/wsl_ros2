// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from part4_services:srv/MyNumberGame.idl
// generated code does not contain a copyright notice
#include "part4_services/srv/detail/my_number_game__rosidl_typesupport_fastrtps_cpp.hpp"
#include "part4_services/srv/detail/my_number_game__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace part4_services
{

namespace srv
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_part4_services
cdr_serialize(
  const part4_services::srv::MyNumberGame_Request & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: guess
  cdr << ros_message.guess;
  // Member: cheat
  cdr << (ros_message.cheat ? true : false);
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_part4_services
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  part4_services::srv::MyNumberGame_Request & ros_message)
{
  // Member: guess
  cdr >> ros_message.guess;

  // Member: cheat
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.cheat = tmp ? true : false;
  }

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_part4_services
get_serialized_size(
  const part4_services::srv::MyNumberGame_Request & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: guess
  {
    size_t item_size = sizeof(ros_message.guess);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: cheat
  {
    size_t item_size = sizeof(ros_message.cheat);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_part4_services
max_serialized_size_MyNumberGame_Request(
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


  // Member: guess
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: cheat
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
    using DataType = part4_services::srv::MyNumberGame_Request;
    is_plain =
      (
      offsetof(DataType, cheat) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _MyNumberGame_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const part4_services::srv::MyNumberGame_Request *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _MyNumberGame_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<part4_services::srv::MyNumberGame_Request *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _MyNumberGame_Request__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const part4_services::srv::MyNumberGame_Request *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _MyNumberGame_Request__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_MyNumberGame_Request(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _MyNumberGame_Request__callbacks = {
  "part4_services::srv",
  "MyNumberGame_Request",
  _MyNumberGame_Request__cdr_serialize,
  _MyNumberGame_Request__cdr_deserialize,
  _MyNumberGame_Request__get_serialized_size,
  _MyNumberGame_Request__max_serialized_size
};

static rosidl_message_type_support_t _MyNumberGame_Request__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_MyNumberGame_Request__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace part4_services

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_part4_services
const rosidl_message_type_support_t *
get_message_type_support_handle<part4_services::srv::MyNumberGame_Request>()
{
  return &part4_services::srv::typesupport_fastrtps_cpp::_MyNumberGame_Request__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, part4_services, srv, MyNumberGame_Request)() {
  return &part4_services::srv::typesupport_fastrtps_cpp::_MyNumberGame_Request__handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include <limits>
// already included above
// #include <stdexcept>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
// already included above
// #include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace part4_services
{

namespace srv
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_part4_services
cdr_serialize(
  const part4_services::srv::MyNumberGame_Response & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: num_guesses
  cdr << ros_message.num_guesses;
  // Member: hint
  cdr << ros_message.hint;
  // Member: correct
  cdr << (ros_message.correct ? true : false);
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_part4_services
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  part4_services::srv::MyNumberGame_Response & ros_message)
{
  // Member: num_guesses
  cdr >> ros_message.num_guesses;

  // Member: hint
  cdr >> ros_message.hint;

  // Member: correct
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.correct = tmp ? true : false;
  }

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_part4_services
get_serialized_size(
  const part4_services::srv::MyNumberGame_Response & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: num_guesses
  {
    size_t item_size = sizeof(ros_message.num_guesses);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: hint
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.hint.size() + 1);
  // Member: correct
  {
    size_t item_size = sizeof(ros_message.correct);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_part4_services
max_serialized_size_MyNumberGame_Response(
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


  // Member: num_guesses
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: hint
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

  // Member: correct
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
    using DataType = part4_services::srv::MyNumberGame_Response;
    is_plain =
      (
      offsetof(DataType, correct) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _MyNumberGame_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const part4_services::srv::MyNumberGame_Response *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _MyNumberGame_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<part4_services::srv::MyNumberGame_Response *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _MyNumberGame_Response__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const part4_services::srv::MyNumberGame_Response *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _MyNumberGame_Response__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_MyNumberGame_Response(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _MyNumberGame_Response__callbacks = {
  "part4_services::srv",
  "MyNumberGame_Response",
  _MyNumberGame_Response__cdr_serialize,
  _MyNumberGame_Response__cdr_deserialize,
  _MyNumberGame_Response__get_serialized_size,
  _MyNumberGame_Response__max_serialized_size
};

static rosidl_message_type_support_t _MyNumberGame_Response__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_MyNumberGame_Response__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace part4_services

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_part4_services
const rosidl_message_type_support_t *
get_message_type_support_handle<part4_services::srv::MyNumberGame_Response>()
{
  return &part4_services::srv::typesupport_fastrtps_cpp::_MyNumberGame_Response__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, part4_services, srv, MyNumberGame_Response)() {
  return &part4_services::srv::typesupport_fastrtps_cpp::_MyNumberGame_Response__handle;
}

#ifdef __cplusplus
}
#endif

#include "rmw/error_handling.h"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/service_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/service_type_support_decl.hpp"

namespace part4_services
{

namespace srv
{

namespace typesupport_fastrtps_cpp
{

static service_type_support_callbacks_t _MyNumberGame__callbacks = {
  "part4_services::srv",
  "MyNumberGame",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, part4_services, srv, MyNumberGame_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, part4_services, srv, MyNumberGame_Response)(),
};

static rosidl_service_type_support_t _MyNumberGame__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_MyNumberGame__callbacks,
  get_service_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace part4_services

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_part4_services
const rosidl_service_type_support_t *
get_service_type_support_handle<part4_services::srv::MyNumberGame>()
{
  return &part4_services::srv::typesupport_fastrtps_cpp::_MyNumberGame__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, part4_services, srv, MyNumberGame)() {
  return &part4_services::srv::typesupport_fastrtps_cpp::_MyNumberGame__handle;
}

#ifdef __cplusplus
}
#endif
