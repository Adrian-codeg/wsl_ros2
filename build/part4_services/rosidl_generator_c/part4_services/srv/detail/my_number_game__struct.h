// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from part4_services:srv/MyNumberGame.idl
// generated code does not contain a copyright notice

#ifndef PART4_SERVICES__SRV__DETAIL__MY_NUMBER_GAME__STRUCT_H_
#define PART4_SERVICES__SRV__DETAIL__MY_NUMBER_GAME__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/MyNumberGame in the package part4_services.
typedef struct part4_services__srv__MyNumberGame_Request
{
  int32_t guess;
  bool cheat;
} part4_services__srv__MyNumberGame_Request;

// Struct for a sequence of part4_services__srv__MyNumberGame_Request.
typedef struct part4_services__srv__MyNumberGame_Request__Sequence
{
  part4_services__srv__MyNumberGame_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} part4_services__srv__MyNumberGame_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'hint'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/MyNumberGame in the package part4_services.
typedef struct part4_services__srv__MyNumberGame_Response
{
  int32_t num_guesses;
  rosidl_runtime_c__String hint;
  bool correct;
} part4_services__srv__MyNumberGame_Response;

// Struct for a sequence of part4_services__srv__MyNumberGame_Response.
typedef struct part4_services__srv__MyNumberGame_Response__Sequence
{
  part4_services__srv__MyNumberGame_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} part4_services__srv__MyNumberGame_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // PART4_SERVICES__SRV__DETAIL__MY_NUMBER_GAME__STRUCT_H_
