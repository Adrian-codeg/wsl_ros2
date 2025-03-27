// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from part4_services:srv/MyNumberGame.idl
// generated code does not contain a copyright notice
#include "part4_services/srv/detail/my_number_game__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

bool
part4_services__srv__MyNumberGame_Request__init(part4_services__srv__MyNumberGame_Request * msg)
{
  if (!msg) {
    return false;
  }
  // guess
  // cheat
  return true;
}

void
part4_services__srv__MyNumberGame_Request__fini(part4_services__srv__MyNumberGame_Request * msg)
{
  if (!msg) {
    return;
  }
  // guess
  // cheat
}

bool
part4_services__srv__MyNumberGame_Request__are_equal(const part4_services__srv__MyNumberGame_Request * lhs, const part4_services__srv__MyNumberGame_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // guess
  if (lhs->guess != rhs->guess) {
    return false;
  }
  // cheat
  if (lhs->cheat != rhs->cheat) {
    return false;
  }
  return true;
}

bool
part4_services__srv__MyNumberGame_Request__copy(
  const part4_services__srv__MyNumberGame_Request * input,
  part4_services__srv__MyNumberGame_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // guess
  output->guess = input->guess;
  // cheat
  output->cheat = input->cheat;
  return true;
}

part4_services__srv__MyNumberGame_Request *
part4_services__srv__MyNumberGame_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  part4_services__srv__MyNumberGame_Request * msg = (part4_services__srv__MyNumberGame_Request *)allocator.allocate(sizeof(part4_services__srv__MyNumberGame_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(part4_services__srv__MyNumberGame_Request));
  bool success = part4_services__srv__MyNumberGame_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
part4_services__srv__MyNumberGame_Request__destroy(part4_services__srv__MyNumberGame_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    part4_services__srv__MyNumberGame_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
part4_services__srv__MyNumberGame_Request__Sequence__init(part4_services__srv__MyNumberGame_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  part4_services__srv__MyNumberGame_Request * data = NULL;

  if (size) {
    data = (part4_services__srv__MyNumberGame_Request *)allocator.zero_allocate(size, sizeof(part4_services__srv__MyNumberGame_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = part4_services__srv__MyNumberGame_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        part4_services__srv__MyNumberGame_Request__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
part4_services__srv__MyNumberGame_Request__Sequence__fini(part4_services__srv__MyNumberGame_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      part4_services__srv__MyNumberGame_Request__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

part4_services__srv__MyNumberGame_Request__Sequence *
part4_services__srv__MyNumberGame_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  part4_services__srv__MyNumberGame_Request__Sequence * array = (part4_services__srv__MyNumberGame_Request__Sequence *)allocator.allocate(sizeof(part4_services__srv__MyNumberGame_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = part4_services__srv__MyNumberGame_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
part4_services__srv__MyNumberGame_Request__Sequence__destroy(part4_services__srv__MyNumberGame_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    part4_services__srv__MyNumberGame_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
part4_services__srv__MyNumberGame_Request__Sequence__are_equal(const part4_services__srv__MyNumberGame_Request__Sequence * lhs, const part4_services__srv__MyNumberGame_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!part4_services__srv__MyNumberGame_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
part4_services__srv__MyNumberGame_Request__Sequence__copy(
  const part4_services__srv__MyNumberGame_Request__Sequence * input,
  part4_services__srv__MyNumberGame_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(part4_services__srv__MyNumberGame_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    part4_services__srv__MyNumberGame_Request * data =
      (part4_services__srv__MyNumberGame_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!part4_services__srv__MyNumberGame_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          part4_services__srv__MyNumberGame_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!part4_services__srv__MyNumberGame_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `hint`
#include "rosidl_runtime_c/string_functions.h"

bool
part4_services__srv__MyNumberGame_Response__init(part4_services__srv__MyNumberGame_Response * msg)
{
  if (!msg) {
    return false;
  }
  // num_guesses
  // hint
  if (!rosidl_runtime_c__String__init(&msg->hint)) {
    part4_services__srv__MyNumberGame_Response__fini(msg);
    return false;
  }
  // correct
  return true;
}

void
part4_services__srv__MyNumberGame_Response__fini(part4_services__srv__MyNumberGame_Response * msg)
{
  if (!msg) {
    return;
  }
  // num_guesses
  // hint
  rosidl_runtime_c__String__fini(&msg->hint);
  // correct
}

bool
part4_services__srv__MyNumberGame_Response__are_equal(const part4_services__srv__MyNumberGame_Response * lhs, const part4_services__srv__MyNumberGame_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // num_guesses
  if (lhs->num_guesses != rhs->num_guesses) {
    return false;
  }
  // hint
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->hint), &(rhs->hint)))
  {
    return false;
  }
  // correct
  if (lhs->correct != rhs->correct) {
    return false;
  }
  return true;
}

bool
part4_services__srv__MyNumberGame_Response__copy(
  const part4_services__srv__MyNumberGame_Response * input,
  part4_services__srv__MyNumberGame_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // num_guesses
  output->num_guesses = input->num_guesses;
  // hint
  if (!rosidl_runtime_c__String__copy(
      &(input->hint), &(output->hint)))
  {
    return false;
  }
  // correct
  output->correct = input->correct;
  return true;
}

part4_services__srv__MyNumberGame_Response *
part4_services__srv__MyNumberGame_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  part4_services__srv__MyNumberGame_Response * msg = (part4_services__srv__MyNumberGame_Response *)allocator.allocate(sizeof(part4_services__srv__MyNumberGame_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(part4_services__srv__MyNumberGame_Response));
  bool success = part4_services__srv__MyNumberGame_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
part4_services__srv__MyNumberGame_Response__destroy(part4_services__srv__MyNumberGame_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    part4_services__srv__MyNumberGame_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
part4_services__srv__MyNumberGame_Response__Sequence__init(part4_services__srv__MyNumberGame_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  part4_services__srv__MyNumberGame_Response * data = NULL;

  if (size) {
    data = (part4_services__srv__MyNumberGame_Response *)allocator.zero_allocate(size, sizeof(part4_services__srv__MyNumberGame_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = part4_services__srv__MyNumberGame_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        part4_services__srv__MyNumberGame_Response__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
part4_services__srv__MyNumberGame_Response__Sequence__fini(part4_services__srv__MyNumberGame_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      part4_services__srv__MyNumberGame_Response__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

part4_services__srv__MyNumberGame_Response__Sequence *
part4_services__srv__MyNumberGame_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  part4_services__srv__MyNumberGame_Response__Sequence * array = (part4_services__srv__MyNumberGame_Response__Sequence *)allocator.allocate(sizeof(part4_services__srv__MyNumberGame_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = part4_services__srv__MyNumberGame_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
part4_services__srv__MyNumberGame_Response__Sequence__destroy(part4_services__srv__MyNumberGame_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    part4_services__srv__MyNumberGame_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
part4_services__srv__MyNumberGame_Response__Sequence__are_equal(const part4_services__srv__MyNumberGame_Response__Sequence * lhs, const part4_services__srv__MyNumberGame_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!part4_services__srv__MyNumberGame_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
part4_services__srv__MyNumberGame_Response__Sequence__copy(
  const part4_services__srv__MyNumberGame_Response__Sequence * input,
  part4_services__srv__MyNumberGame_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(part4_services__srv__MyNumberGame_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    part4_services__srv__MyNumberGame_Response * data =
      (part4_services__srv__MyNumberGame_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!part4_services__srv__MyNumberGame_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          part4_services__srv__MyNumberGame_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!part4_services__srv__MyNumberGame_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
