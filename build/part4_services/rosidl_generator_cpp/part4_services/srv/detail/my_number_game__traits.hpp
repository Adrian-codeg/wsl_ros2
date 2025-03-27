// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from part4_services:srv/MyNumberGame.idl
// generated code does not contain a copyright notice

#ifndef PART4_SERVICES__SRV__DETAIL__MY_NUMBER_GAME__TRAITS_HPP_
#define PART4_SERVICES__SRV__DETAIL__MY_NUMBER_GAME__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "part4_services/srv/detail/my_number_game__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace part4_services
{

namespace srv
{

inline void to_flow_style_yaml(
  const MyNumberGame_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: guess
  {
    out << "guess: ";
    rosidl_generator_traits::value_to_yaml(msg.guess, out);
    out << ", ";
  }

  // member: cheat
  {
    out << "cheat: ";
    rosidl_generator_traits::value_to_yaml(msg.cheat, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const MyNumberGame_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: guess
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "guess: ";
    rosidl_generator_traits::value_to_yaml(msg.guess, out);
    out << "\n";
  }

  // member: cheat
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "cheat: ";
    rosidl_generator_traits::value_to_yaml(msg.cheat, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const MyNumberGame_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace part4_services

namespace rosidl_generator_traits
{

[[deprecated("use part4_services::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const part4_services::srv::MyNumberGame_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  part4_services::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use part4_services::srv::to_yaml() instead")]]
inline std::string to_yaml(const part4_services::srv::MyNumberGame_Request & msg)
{
  return part4_services::srv::to_yaml(msg);
}

template<>
inline const char * data_type<part4_services::srv::MyNumberGame_Request>()
{
  return "part4_services::srv::MyNumberGame_Request";
}

template<>
inline const char * name<part4_services::srv::MyNumberGame_Request>()
{
  return "part4_services/srv/MyNumberGame_Request";
}

template<>
struct has_fixed_size<part4_services::srv::MyNumberGame_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<part4_services::srv::MyNumberGame_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<part4_services::srv::MyNumberGame_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace part4_services
{

namespace srv
{

inline void to_flow_style_yaml(
  const MyNumberGame_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: num_guesses
  {
    out << "num_guesses: ";
    rosidl_generator_traits::value_to_yaml(msg.num_guesses, out);
    out << ", ";
  }

  // member: hint
  {
    out << "hint: ";
    rosidl_generator_traits::value_to_yaml(msg.hint, out);
    out << ", ";
  }

  // member: correct
  {
    out << "correct: ";
    rosidl_generator_traits::value_to_yaml(msg.correct, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const MyNumberGame_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: num_guesses
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "num_guesses: ";
    rosidl_generator_traits::value_to_yaml(msg.num_guesses, out);
    out << "\n";
  }

  // member: hint
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "hint: ";
    rosidl_generator_traits::value_to_yaml(msg.hint, out);
    out << "\n";
  }

  // member: correct
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "correct: ";
    rosidl_generator_traits::value_to_yaml(msg.correct, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const MyNumberGame_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace part4_services

namespace rosidl_generator_traits
{

[[deprecated("use part4_services::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const part4_services::srv::MyNumberGame_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  part4_services::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use part4_services::srv::to_yaml() instead")]]
inline std::string to_yaml(const part4_services::srv::MyNumberGame_Response & msg)
{
  return part4_services::srv::to_yaml(msg);
}

template<>
inline const char * data_type<part4_services::srv::MyNumberGame_Response>()
{
  return "part4_services::srv::MyNumberGame_Response";
}

template<>
inline const char * name<part4_services::srv::MyNumberGame_Response>()
{
  return "part4_services/srv/MyNumberGame_Response";
}

template<>
struct has_fixed_size<part4_services::srv::MyNumberGame_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<part4_services::srv::MyNumberGame_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<part4_services::srv::MyNumberGame_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<part4_services::srv::MyNumberGame>()
{
  return "part4_services::srv::MyNumberGame";
}

template<>
inline const char * name<part4_services::srv::MyNumberGame>()
{
  return "part4_services/srv/MyNumberGame";
}

template<>
struct has_fixed_size<part4_services::srv::MyNumberGame>
  : std::integral_constant<
    bool,
    has_fixed_size<part4_services::srv::MyNumberGame_Request>::value &&
    has_fixed_size<part4_services::srv::MyNumberGame_Response>::value
  >
{
};

template<>
struct has_bounded_size<part4_services::srv::MyNumberGame>
  : std::integral_constant<
    bool,
    has_bounded_size<part4_services::srv::MyNumberGame_Request>::value &&
    has_bounded_size<part4_services::srv::MyNumberGame_Response>::value
  >
{
};

template<>
struct is_service<part4_services::srv::MyNumberGame>
  : std::true_type
{
};

template<>
struct is_service_request<part4_services::srv::MyNumberGame_Request>
  : std::true_type
{
};

template<>
struct is_service_response<part4_services::srv::MyNumberGame_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // PART4_SERVICES__SRV__DETAIL__MY_NUMBER_GAME__TRAITS_HPP_
