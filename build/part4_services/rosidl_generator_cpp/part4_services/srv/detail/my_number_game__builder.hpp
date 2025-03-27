// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from part4_services:srv/MyNumberGame.idl
// generated code does not contain a copyright notice

#ifndef PART4_SERVICES__SRV__DETAIL__MY_NUMBER_GAME__BUILDER_HPP_
#define PART4_SERVICES__SRV__DETAIL__MY_NUMBER_GAME__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "part4_services/srv/detail/my_number_game__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace part4_services
{

namespace srv
{

namespace builder
{

class Init_MyNumberGame_Request_cheat
{
public:
  explicit Init_MyNumberGame_Request_cheat(::part4_services::srv::MyNumberGame_Request & msg)
  : msg_(msg)
  {}
  ::part4_services::srv::MyNumberGame_Request cheat(::part4_services::srv::MyNumberGame_Request::_cheat_type arg)
  {
    msg_.cheat = std::move(arg);
    return std::move(msg_);
  }

private:
  ::part4_services::srv::MyNumberGame_Request msg_;
};

class Init_MyNumberGame_Request_guess
{
public:
  Init_MyNumberGame_Request_guess()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MyNumberGame_Request_cheat guess(::part4_services::srv::MyNumberGame_Request::_guess_type arg)
  {
    msg_.guess = std::move(arg);
    return Init_MyNumberGame_Request_cheat(msg_);
  }

private:
  ::part4_services::srv::MyNumberGame_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::part4_services::srv::MyNumberGame_Request>()
{
  return part4_services::srv::builder::Init_MyNumberGame_Request_guess();
}

}  // namespace part4_services


namespace part4_services
{

namespace srv
{

namespace builder
{

class Init_MyNumberGame_Response_correct
{
public:
  explicit Init_MyNumberGame_Response_correct(::part4_services::srv::MyNumberGame_Response & msg)
  : msg_(msg)
  {}
  ::part4_services::srv::MyNumberGame_Response correct(::part4_services::srv::MyNumberGame_Response::_correct_type arg)
  {
    msg_.correct = std::move(arg);
    return std::move(msg_);
  }

private:
  ::part4_services::srv::MyNumberGame_Response msg_;
};

class Init_MyNumberGame_Response_hint
{
public:
  explicit Init_MyNumberGame_Response_hint(::part4_services::srv::MyNumberGame_Response & msg)
  : msg_(msg)
  {}
  Init_MyNumberGame_Response_correct hint(::part4_services::srv::MyNumberGame_Response::_hint_type arg)
  {
    msg_.hint = std::move(arg);
    return Init_MyNumberGame_Response_correct(msg_);
  }

private:
  ::part4_services::srv::MyNumberGame_Response msg_;
};

class Init_MyNumberGame_Response_num_guesses
{
public:
  Init_MyNumberGame_Response_num_guesses()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MyNumberGame_Response_hint num_guesses(::part4_services::srv::MyNumberGame_Response::_num_guesses_type arg)
  {
    msg_.num_guesses = std::move(arg);
    return Init_MyNumberGame_Response_hint(msg_);
  }

private:
  ::part4_services::srv::MyNumberGame_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::part4_services::srv::MyNumberGame_Response>()
{
  return part4_services::srv::builder::Init_MyNumberGame_Response_num_guesses();
}

}  // namespace part4_services

#endif  // PART4_SERVICES__SRV__DETAIL__MY_NUMBER_GAME__BUILDER_HPP_
