// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from part4_services:srv/MyNumberGame.idl
// generated code does not contain a copyright notice

#ifndef PART4_SERVICES__SRV__DETAIL__MY_NUMBER_GAME__STRUCT_HPP_
#define PART4_SERVICES__SRV__DETAIL__MY_NUMBER_GAME__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__part4_services__srv__MyNumberGame_Request __attribute__((deprecated))
#else
# define DEPRECATED__part4_services__srv__MyNumberGame_Request __declspec(deprecated)
#endif

namespace part4_services
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct MyNumberGame_Request_
{
  using Type = MyNumberGame_Request_<ContainerAllocator>;

  explicit MyNumberGame_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->guess = 0l;
      this->cheat = false;
    }
  }

  explicit MyNumberGame_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->guess = 0l;
      this->cheat = false;
    }
  }

  // field types and members
  using _guess_type =
    int32_t;
  _guess_type guess;
  using _cheat_type =
    bool;
  _cheat_type cheat;

  // setters for named parameter idiom
  Type & set__guess(
    const int32_t & _arg)
  {
    this->guess = _arg;
    return *this;
  }
  Type & set__cheat(
    const bool & _arg)
  {
    this->cheat = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    part4_services::srv::MyNumberGame_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const part4_services::srv::MyNumberGame_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<part4_services::srv::MyNumberGame_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<part4_services::srv::MyNumberGame_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      part4_services::srv::MyNumberGame_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<part4_services::srv::MyNumberGame_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      part4_services::srv::MyNumberGame_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<part4_services::srv::MyNumberGame_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<part4_services::srv::MyNumberGame_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<part4_services::srv::MyNumberGame_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__part4_services__srv__MyNumberGame_Request
    std::shared_ptr<part4_services::srv::MyNumberGame_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__part4_services__srv__MyNumberGame_Request
    std::shared_ptr<part4_services::srv::MyNumberGame_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MyNumberGame_Request_ & other) const
  {
    if (this->guess != other.guess) {
      return false;
    }
    if (this->cheat != other.cheat) {
      return false;
    }
    return true;
  }
  bool operator!=(const MyNumberGame_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MyNumberGame_Request_

// alias to use template instance with default allocator
using MyNumberGame_Request =
  part4_services::srv::MyNumberGame_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace part4_services


#ifndef _WIN32
# define DEPRECATED__part4_services__srv__MyNumberGame_Response __attribute__((deprecated))
#else
# define DEPRECATED__part4_services__srv__MyNumberGame_Response __declspec(deprecated)
#endif

namespace part4_services
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct MyNumberGame_Response_
{
  using Type = MyNumberGame_Response_<ContainerAllocator>;

  explicit MyNumberGame_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->num_guesses = 0l;
      this->hint = "";
      this->correct = false;
    }
  }

  explicit MyNumberGame_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : hint(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->num_guesses = 0l;
      this->hint = "";
      this->correct = false;
    }
  }

  // field types and members
  using _num_guesses_type =
    int32_t;
  _num_guesses_type num_guesses;
  using _hint_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _hint_type hint;
  using _correct_type =
    bool;
  _correct_type correct;

  // setters for named parameter idiom
  Type & set__num_guesses(
    const int32_t & _arg)
  {
    this->num_guesses = _arg;
    return *this;
  }
  Type & set__hint(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->hint = _arg;
    return *this;
  }
  Type & set__correct(
    const bool & _arg)
  {
    this->correct = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    part4_services::srv::MyNumberGame_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const part4_services::srv::MyNumberGame_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<part4_services::srv::MyNumberGame_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<part4_services::srv::MyNumberGame_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      part4_services::srv::MyNumberGame_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<part4_services::srv::MyNumberGame_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      part4_services::srv::MyNumberGame_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<part4_services::srv::MyNumberGame_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<part4_services::srv::MyNumberGame_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<part4_services::srv::MyNumberGame_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__part4_services__srv__MyNumberGame_Response
    std::shared_ptr<part4_services::srv::MyNumberGame_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__part4_services__srv__MyNumberGame_Response
    std::shared_ptr<part4_services::srv::MyNumberGame_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MyNumberGame_Response_ & other) const
  {
    if (this->num_guesses != other.num_guesses) {
      return false;
    }
    if (this->hint != other.hint) {
      return false;
    }
    if (this->correct != other.correct) {
      return false;
    }
    return true;
  }
  bool operator!=(const MyNumberGame_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MyNumberGame_Response_

// alias to use template instance with default allocator
using MyNumberGame_Response =
  part4_services::srv::MyNumberGame_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace part4_services

namespace part4_services
{

namespace srv
{

struct MyNumberGame
{
  using Request = part4_services::srv::MyNumberGame_Request;
  using Response = part4_services::srv::MyNumberGame_Response;
};

}  // namespace srv

}  // namespace part4_services

#endif  // PART4_SERVICES__SRV__DETAIL__MY_NUMBER_GAME__STRUCT_HPP_
