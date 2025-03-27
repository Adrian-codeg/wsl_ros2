// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from part5_actions:action/ExploreForward.idl
// generated code does not contain a copyright notice
#include "part5_actions/action/detail/explore_forward__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
part5_actions__action__ExploreForward_Goal__init(part5_actions__action__ExploreForward_Goal * msg)
{
  if (!msg) {
    return false;
  }
  // fwd_velocity
  // stopping_distance
  return true;
}

void
part5_actions__action__ExploreForward_Goal__fini(part5_actions__action__ExploreForward_Goal * msg)
{
  if (!msg) {
    return;
  }
  // fwd_velocity
  // stopping_distance
}

bool
part5_actions__action__ExploreForward_Goal__are_equal(const part5_actions__action__ExploreForward_Goal * lhs, const part5_actions__action__ExploreForward_Goal * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // fwd_velocity
  if (lhs->fwd_velocity != rhs->fwd_velocity) {
    return false;
  }
  // stopping_distance
  if (lhs->stopping_distance != rhs->stopping_distance) {
    return false;
  }
  return true;
}

bool
part5_actions__action__ExploreForward_Goal__copy(
  const part5_actions__action__ExploreForward_Goal * input,
  part5_actions__action__ExploreForward_Goal * output)
{
  if (!input || !output) {
    return false;
  }
  // fwd_velocity
  output->fwd_velocity = input->fwd_velocity;
  // stopping_distance
  output->stopping_distance = input->stopping_distance;
  return true;
}

part5_actions__action__ExploreForward_Goal *
part5_actions__action__ExploreForward_Goal__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  part5_actions__action__ExploreForward_Goal * msg = (part5_actions__action__ExploreForward_Goal *)allocator.allocate(sizeof(part5_actions__action__ExploreForward_Goal), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(part5_actions__action__ExploreForward_Goal));
  bool success = part5_actions__action__ExploreForward_Goal__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
part5_actions__action__ExploreForward_Goal__destroy(part5_actions__action__ExploreForward_Goal * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    part5_actions__action__ExploreForward_Goal__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
part5_actions__action__ExploreForward_Goal__Sequence__init(part5_actions__action__ExploreForward_Goal__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  part5_actions__action__ExploreForward_Goal * data = NULL;

  if (size) {
    data = (part5_actions__action__ExploreForward_Goal *)allocator.zero_allocate(size, sizeof(part5_actions__action__ExploreForward_Goal), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = part5_actions__action__ExploreForward_Goal__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        part5_actions__action__ExploreForward_Goal__fini(&data[i - 1]);
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
part5_actions__action__ExploreForward_Goal__Sequence__fini(part5_actions__action__ExploreForward_Goal__Sequence * array)
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
      part5_actions__action__ExploreForward_Goal__fini(&array->data[i]);
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

part5_actions__action__ExploreForward_Goal__Sequence *
part5_actions__action__ExploreForward_Goal__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  part5_actions__action__ExploreForward_Goal__Sequence * array = (part5_actions__action__ExploreForward_Goal__Sequence *)allocator.allocate(sizeof(part5_actions__action__ExploreForward_Goal__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = part5_actions__action__ExploreForward_Goal__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
part5_actions__action__ExploreForward_Goal__Sequence__destroy(part5_actions__action__ExploreForward_Goal__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    part5_actions__action__ExploreForward_Goal__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
part5_actions__action__ExploreForward_Goal__Sequence__are_equal(const part5_actions__action__ExploreForward_Goal__Sequence * lhs, const part5_actions__action__ExploreForward_Goal__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!part5_actions__action__ExploreForward_Goal__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
part5_actions__action__ExploreForward_Goal__Sequence__copy(
  const part5_actions__action__ExploreForward_Goal__Sequence * input,
  part5_actions__action__ExploreForward_Goal__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(part5_actions__action__ExploreForward_Goal);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    part5_actions__action__ExploreForward_Goal * data =
      (part5_actions__action__ExploreForward_Goal *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!part5_actions__action__ExploreForward_Goal__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          part5_actions__action__ExploreForward_Goal__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!part5_actions__action__ExploreForward_Goal__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
part5_actions__action__ExploreForward_Result__init(part5_actions__action__ExploreForward_Result * msg)
{
  if (!msg) {
    return false;
  }
  // total_distance_travelled
  // closest_obstacle
  return true;
}

void
part5_actions__action__ExploreForward_Result__fini(part5_actions__action__ExploreForward_Result * msg)
{
  if (!msg) {
    return;
  }
  // total_distance_travelled
  // closest_obstacle
}

bool
part5_actions__action__ExploreForward_Result__are_equal(const part5_actions__action__ExploreForward_Result * lhs, const part5_actions__action__ExploreForward_Result * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // total_distance_travelled
  if (lhs->total_distance_travelled != rhs->total_distance_travelled) {
    return false;
  }
  // closest_obstacle
  if (lhs->closest_obstacle != rhs->closest_obstacle) {
    return false;
  }
  return true;
}

bool
part5_actions__action__ExploreForward_Result__copy(
  const part5_actions__action__ExploreForward_Result * input,
  part5_actions__action__ExploreForward_Result * output)
{
  if (!input || !output) {
    return false;
  }
  // total_distance_travelled
  output->total_distance_travelled = input->total_distance_travelled;
  // closest_obstacle
  output->closest_obstacle = input->closest_obstacle;
  return true;
}

part5_actions__action__ExploreForward_Result *
part5_actions__action__ExploreForward_Result__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  part5_actions__action__ExploreForward_Result * msg = (part5_actions__action__ExploreForward_Result *)allocator.allocate(sizeof(part5_actions__action__ExploreForward_Result), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(part5_actions__action__ExploreForward_Result));
  bool success = part5_actions__action__ExploreForward_Result__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
part5_actions__action__ExploreForward_Result__destroy(part5_actions__action__ExploreForward_Result * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    part5_actions__action__ExploreForward_Result__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
part5_actions__action__ExploreForward_Result__Sequence__init(part5_actions__action__ExploreForward_Result__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  part5_actions__action__ExploreForward_Result * data = NULL;

  if (size) {
    data = (part5_actions__action__ExploreForward_Result *)allocator.zero_allocate(size, sizeof(part5_actions__action__ExploreForward_Result), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = part5_actions__action__ExploreForward_Result__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        part5_actions__action__ExploreForward_Result__fini(&data[i - 1]);
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
part5_actions__action__ExploreForward_Result__Sequence__fini(part5_actions__action__ExploreForward_Result__Sequence * array)
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
      part5_actions__action__ExploreForward_Result__fini(&array->data[i]);
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

part5_actions__action__ExploreForward_Result__Sequence *
part5_actions__action__ExploreForward_Result__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  part5_actions__action__ExploreForward_Result__Sequence * array = (part5_actions__action__ExploreForward_Result__Sequence *)allocator.allocate(sizeof(part5_actions__action__ExploreForward_Result__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = part5_actions__action__ExploreForward_Result__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
part5_actions__action__ExploreForward_Result__Sequence__destroy(part5_actions__action__ExploreForward_Result__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    part5_actions__action__ExploreForward_Result__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
part5_actions__action__ExploreForward_Result__Sequence__are_equal(const part5_actions__action__ExploreForward_Result__Sequence * lhs, const part5_actions__action__ExploreForward_Result__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!part5_actions__action__ExploreForward_Result__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
part5_actions__action__ExploreForward_Result__Sequence__copy(
  const part5_actions__action__ExploreForward_Result__Sequence * input,
  part5_actions__action__ExploreForward_Result__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(part5_actions__action__ExploreForward_Result);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    part5_actions__action__ExploreForward_Result * data =
      (part5_actions__action__ExploreForward_Result *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!part5_actions__action__ExploreForward_Result__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          part5_actions__action__ExploreForward_Result__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!part5_actions__action__ExploreForward_Result__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
part5_actions__action__ExploreForward_Feedback__init(part5_actions__action__ExploreForward_Feedback * msg)
{
  if (!msg) {
    return false;
  }
  // current_distance_travelled
  return true;
}

void
part5_actions__action__ExploreForward_Feedback__fini(part5_actions__action__ExploreForward_Feedback * msg)
{
  if (!msg) {
    return;
  }
  // current_distance_travelled
}

bool
part5_actions__action__ExploreForward_Feedback__are_equal(const part5_actions__action__ExploreForward_Feedback * lhs, const part5_actions__action__ExploreForward_Feedback * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // current_distance_travelled
  if (lhs->current_distance_travelled != rhs->current_distance_travelled) {
    return false;
  }
  return true;
}

bool
part5_actions__action__ExploreForward_Feedback__copy(
  const part5_actions__action__ExploreForward_Feedback * input,
  part5_actions__action__ExploreForward_Feedback * output)
{
  if (!input || !output) {
    return false;
  }
  // current_distance_travelled
  output->current_distance_travelled = input->current_distance_travelled;
  return true;
}

part5_actions__action__ExploreForward_Feedback *
part5_actions__action__ExploreForward_Feedback__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  part5_actions__action__ExploreForward_Feedback * msg = (part5_actions__action__ExploreForward_Feedback *)allocator.allocate(sizeof(part5_actions__action__ExploreForward_Feedback), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(part5_actions__action__ExploreForward_Feedback));
  bool success = part5_actions__action__ExploreForward_Feedback__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
part5_actions__action__ExploreForward_Feedback__destroy(part5_actions__action__ExploreForward_Feedback * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    part5_actions__action__ExploreForward_Feedback__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
part5_actions__action__ExploreForward_Feedback__Sequence__init(part5_actions__action__ExploreForward_Feedback__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  part5_actions__action__ExploreForward_Feedback * data = NULL;

  if (size) {
    data = (part5_actions__action__ExploreForward_Feedback *)allocator.zero_allocate(size, sizeof(part5_actions__action__ExploreForward_Feedback), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = part5_actions__action__ExploreForward_Feedback__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        part5_actions__action__ExploreForward_Feedback__fini(&data[i - 1]);
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
part5_actions__action__ExploreForward_Feedback__Sequence__fini(part5_actions__action__ExploreForward_Feedback__Sequence * array)
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
      part5_actions__action__ExploreForward_Feedback__fini(&array->data[i]);
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

part5_actions__action__ExploreForward_Feedback__Sequence *
part5_actions__action__ExploreForward_Feedback__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  part5_actions__action__ExploreForward_Feedback__Sequence * array = (part5_actions__action__ExploreForward_Feedback__Sequence *)allocator.allocate(sizeof(part5_actions__action__ExploreForward_Feedback__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = part5_actions__action__ExploreForward_Feedback__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
part5_actions__action__ExploreForward_Feedback__Sequence__destroy(part5_actions__action__ExploreForward_Feedback__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    part5_actions__action__ExploreForward_Feedback__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
part5_actions__action__ExploreForward_Feedback__Sequence__are_equal(const part5_actions__action__ExploreForward_Feedback__Sequence * lhs, const part5_actions__action__ExploreForward_Feedback__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!part5_actions__action__ExploreForward_Feedback__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
part5_actions__action__ExploreForward_Feedback__Sequence__copy(
  const part5_actions__action__ExploreForward_Feedback__Sequence * input,
  part5_actions__action__ExploreForward_Feedback__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(part5_actions__action__ExploreForward_Feedback);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    part5_actions__action__ExploreForward_Feedback * data =
      (part5_actions__action__ExploreForward_Feedback *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!part5_actions__action__ExploreForward_Feedback__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          part5_actions__action__ExploreForward_Feedback__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!part5_actions__action__ExploreForward_Feedback__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
#include "unique_identifier_msgs/msg/detail/uuid__functions.h"
// Member `goal`
// already included above
// #include "part5_actions/action/detail/explore_forward__functions.h"

bool
part5_actions__action__ExploreForward_SendGoal_Request__init(part5_actions__action__ExploreForward_SendGoal_Request * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    part5_actions__action__ExploreForward_SendGoal_Request__fini(msg);
    return false;
  }
  // goal
  if (!part5_actions__action__ExploreForward_Goal__init(&msg->goal)) {
    part5_actions__action__ExploreForward_SendGoal_Request__fini(msg);
    return false;
  }
  return true;
}

void
part5_actions__action__ExploreForward_SendGoal_Request__fini(part5_actions__action__ExploreForward_SendGoal_Request * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
  // goal
  part5_actions__action__ExploreForward_Goal__fini(&msg->goal);
}

bool
part5_actions__action__ExploreForward_SendGoal_Request__are_equal(const part5_actions__action__ExploreForward_SendGoal_Request * lhs, const part5_actions__action__ExploreForward_SendGoal_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  // goal
  if (!part5_actions__action__ExploreForward_Goal__are_equal(
      &(lhs->goal), &(rhs->goal)))
  {
    return false;
  }
  return true;
}

bool
part5_actions__action__ExploreForward_SendGoal_Request__copy(
  const part5_actions__action__ExploreForward_SendGoal_Request * input,
  part5_actions__action__ExploreForward_SendGoal_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  // goal
  if (!part5_actions__action__ExploreForward_Goal__copy(
      &(input->goal), &(output->goal)))
  {
    return false;
  }
  return true;
}

part5_actions__action__ExploreForward_SendGoal_Request *
part5_actions__action__ExploreForward_SendGoal_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  part5_actions__action__ExploreForward_SendGoal_Request * msg = (part5_actions__action__ExploreForward_SendGoal_Request *)allocator.allocate(sizeof(part5_actions__action__ExploreForward_SendGoal_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(part5_actions__action__ExploreForward_SendGoal_Request));
  bool success = part5_actions__action__ExploreForward_SendGoal_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
part5_actions__action__ExploreForward_SendGoal_Request__destroy(part5_actions__action__ExploreForward_SendGoal_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    part5_actions__action__ExploreForward_SendGoal_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
part5_actions__action__ExploreForward_SendGoal_Request__Sequence__init(part5_actions__action__ExploreForward_SendGoal_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  part5_actions__action__ExploreForward_SendGoal_Request * data = NULL;

  if (size) {
    data = (part5_actions__action__ExploreForward_SendGoal_Request *)allocator.zero_allocate(size, sizeof(part5_actions__action__ExploreForward_SendGoal_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = part5_actions__action__ExploreForward_SendGoal_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        part5_actions__action__ExploreForward_SendGoal_Request__fini(&data[i - 1]);
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
part5_actions__action__ExploreForward_SendGoal_Request__Sequence__fini(part5_actions__action__ExploreForward_SendGoal_Request__Sequence * array)
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
      part5_actions__action__ExploreForward_SendGoal_Request__fini(&array->data[i]);
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

part5_actions__action__ExploreForward_SendGoal_Request__Sequence *
part5_actions__action__ExploreForward_SendGoal_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  part5_actions__action__ExploreForward_SendGoal_Request__Sequence * array = (part5_actions__action__ExploreForward_SendGoal_Request__Sequence *)allocator.allocate(sizeof(part5_actions__action__ExploreForward_SendGoal_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = part5_actions__action__ExploreForward_SendGoal_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
part5_actions__action__ExploreForward_SendGoal_Request__Sequence__destroy(part5_actions__action__ExploreForward_SendGoal_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    part5_actions__action__ExploreForward_SendGoal_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
part5_actions__action__ExploreForward_SendGoal_Request__Sequence__are_equal(const part5_actions__action__ExploreForward_SendGoal_Request__Sequence * lhs, const part5_actions__action__ExploreForward_SendGoal_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!part5_actions__action__ExploreForward_SendGoal_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
part5_actions__action__ExploreForward_SendGoal_Request__Sequence__copy(
  const part5_actions__action__ExploreForward_SendGoal_Request__Sequence * input,
  part5_actions__action__ExploreForward_SendGoal_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(part5_actions__action__ExploreForward_SendGoal_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    part5_actions__action__ExploreForward_SendGoal_Request * data =
      (part5_actions__action__ExploreForward_SendGoal_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!part5_actions__action__ExploreForward_SendGoal_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          part5_actions__action__ExploreForward_SendGoal_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!part5_actions__action__ExploreForward_SendGoal_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `stamp`
#include "builtin_interfaces/msg/detail/time__functions.h"

bool
part5_actions__action__ExploreForward_SendGoal_Response__init(part5_actions__action__ExploreForward_SendGoal_Response * msg)
{
  if (!msg) {
    return false;
  }
  // accepted
  // stamp
  if (!builtin_interfaces__msg__Time__init(&msg->stamp)) {
    part5_actions__action__ExploreForward_SendGoal_Response__fini(msg);
    return false;
  }
  return true;
}

void
part5_actions__action__ExploreForward_SendGoal_Response__fini(part5_actions__action__ExploreForward_SendGoal_Response * msg)
{
  if (!msg) {
    return;
  }
  // accepted
  // stamp
  builtin_interfaces__msg__Time__fini(&msg->stamp);
}

bool
part5_actions__action__ExploreForward_SendGoal_Response__are_equal(const part5_actions__action__ExploreForward_SendGoal_Response * lhs, const part5_actions__action__ExploreForward_SendGoal_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // accepted
  if (lhs->accepted != rhs->accepted) {
    return false;
  }
  // stamp
  if (!builtin_interfaces__msg__Time__are_equal(
      &(lhs->stamp), &(rhs->stamp)))
  {
    return false;
  }
  return true;
}

bool
part5_actions__action__ExploreForward_SendGoal_Response__copy(
  const part5_actions__action__ExploreForward_SendGoal_Response * input,
  part5_actions__action__ExploreForward_SendGoal_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // accepted
  output->accepted = input->accepted;
  // stamp
  if (!builtin_interfaces__msg__Time__copy(
      &(input->stamp), &(output->stamp)))
  {
    return false;
  }
  return true;
}

part5_actions__action__ExploreForward_SendGoal_Response *
part5_actions__action__ExploreForward_SendGoal_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  part5_actions__action__ExploreForward_SendGoal_Response * msg = (part5_actions__action__ExploreForward_SendGoal_Response *)allocator.allocate(sizeof(part5_actions__action__ExploreForward_SendGoal_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(part5_actions__action__ExploreForward_SendGoal_Response));
  bool success = part5_actions__action__ExploreForward_SendGoal_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
part5_actions__action__ExploreForward_SendGoal_Response__destroy(part5_actions__action__ExploreForward_SendGoal_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    part5_actions__action__ExploreForward_SendGoal_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
part5_actions__action__ExploreForward_SendGoal_Response__Sequence__init(part5_actions__action__ExploreForward_SendGoal_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  part5_actions__action__ExploreForward_SendGoal_Response * data = NULL;

  if (size) {
    data = (part5_actions__action__ExploreForward_SendGoal_Response *)allocator.zero_allocate(size, sizeof(part5_actions__action__ExploreForward_SendGoal_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = part5_actions__action__ExploreForward_SendGoal_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        part5_actions__action__ExploreForward_SendGoal_Response__fini(&data[i - 1]);
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
part5_actions__action__ExploreForward_SendGoal_Response__Sequence__fini(part5_actions__action__ExploreForward_SendGoal_Response__Sequence * array)
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
      part5_actions__action__ExploreForward_SendGoal_Response__fini(&array->data[i]);
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

part5_actions__action__ExploreForward_SendGoal_Response__Sequence *
part5_actions__action__ExploreForward_SendGoal_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  part5_actions__action__ExploreForward_SendGoal_Response__Sequence * array = (part5_actions__action__ExploreForward_SendGoal_Response__Sequence *)allocator.allocate(sizeof(part5_actions__action__ExploreForward_SendGoal_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = part5_actions__action__ExploreForward_SendGoal_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
part5_actions__action__ExploreForward_SendGoal_Response__Sequence__destroy(part5_actions__action__ExploreForward_SendGoal_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    part5_actions__action__ExploreForward_SendGoal_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
part5_actions__action__ExploreForward_SendGoal_Response__Sequence__are_equal(const part5_actions__action__ExploreForward_SendGoal_Response__Sequence * lhs, const part5_actions__action__ExploreForward_SendGoal_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!part5_actions__action__ExploreForward_SendGoal_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
part5_actions__action__ExploreForward_SendGoal_Response__Sequence__copy(
  const part5_actions__action__ExploreForward_SendGoal_Response__Sequence * input,
  part5_actions__action__ExploreForward_SendGoal_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(part5_actions__action__ExploreForward_SendGoal_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    part5_actions__action__ExploreForward_SendGoal_Response * data =
      (part5_actions__action__ExploreForward_SendGoal_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!part5_actions__action__ExploreForward_SendGoal_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          part5_actions__action__ExploreForward_SendGoal_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!part5_actions__action__ExploreForward_SendGoal_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__functions.h"

bool
part5_actions__action__ExploreForward_GetResult_Request__init(part5_actions__action__ExploreForward_GetResult_Request * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    part5_actions__action__ExploreForward_GetResult_Request__fini(msg);
    return false;
  }
  return true;
}

void
part5_actions__action__ExploreForward_GetResult_Request__fini(part5_actions__action__ExploreForward_GetResult_Request * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
}

bool
part5_actions__action__ExploreForward_GetResult_Request__are_equal(const part5_actions__action__ExploreForward_GetResult_Request * lhs, const part5_actions__action__ExploreForward_GetResult_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  return true;
}

bool
part5_actions__action__ExploreForward_GetResult_Request__copy(
  const part5_actions__action__ExploreForward_GetResult_Request * input,
  part5_actions__action__ExploreForward_GetResult_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  return true;
}

part5_actions__action__ExploreForward_GetResult_Request *
part5_actions__action__ExploreForward_GetResult_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  part5_actions__action__ExploreForward_GetResult_Request * msg = (part5_actions__action__ExploreForward_GetResult_Request *)allocator.allocate(sizeof(part5_actions__action__ExploreForward_GetResult_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(part5_actions__action__ExploreForward_GetResult_Request));
  bool success = part5_actions__action__ExploreForward_GetResult_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
part5_actions__action__ExploreForward_GetResult_Request__destroy(part5_actions__action__ExploreForward_GetResult_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    part5_actions__action__ExploreForward_GetResult_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
part5_actions__action__ExploreForward_GetResult_Request__Sequence__init(part5_actions__action__ExploreForward_GetResult_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  part5_actions__action__ExploreForward_GetResult_Request * data = NULL;

  if (size) {
    data = (part5_actions__action__ExploreForward_GetResult_Request *)allocator.zero_allocate(size, sizeof(part5_actions__action__ExploreForward_GetResult_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = part5_actions__action__ExploreForward_GetResult_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        part5_actions__action__ExploreForward_GetResult_Request__fini(&data[i - 1]);
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
part5_actions__action__ExploreForward_GetResult_Request__Sequence__fini(part5_actions__action__ExploreForward_GetResult_Request__Sequence * array)
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
      part5_actions__action__ExploreForward_GetResult_Request__fini(&array->data[i]);
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

part5_actions__action__ExploreForward_GetResult_Request__Sequence *
part5_actions__action__ExploreForward_GetResult_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  part5_actions__action__ExploreForward_GetResult_Request__Sequence * array = (part5_actions__action__ExploreForward_GetResult_Request__Sequence *)allocator.allocate(sizeof(part5_actions__action__ExploreForward_GetResult_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = part5_actions__action__ExploreForward_GetResult_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
part5_actions__action__ExploreForward_GetResult_Request__Sequence__destroy(part5_actions__action__ExploreForward_GetResult_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    part5_actions__action__ExploreForward_GetResult_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
part5_actions__action__ExploreForward_GetResult_Request__Sequence__are_equal(const part5_actions__action__ExploreForward_GetResult_Request__Sequence * lhs, const part5_actions__action__ExploreForward_GetResult_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!part5_actions__action__ExploreForward_GetResult_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
part5_actions__action__ExploreForward_GetResult_Request__Sequence__copy(
  const part5_actions__action__ExploreForward_GetResult_Request__Sequence * input,
  part5_actions__action__ExploreForward_GetResult_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(part5_actions__action__ExploreForward_GetResult_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    part5_actions__action__ExploreForward_GetResult_Request * data =
      (part5_actions__action__ExploreForward_GetResult_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!part5_actions__action__ExploreForward_GetResult_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          part5_actions__action__ExploreForward_GetResult_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!part5_actions__action__ExploreForward_GetResult_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `result`
// already included above
// #include "part5_actions/action/detail/explore_forward__functions.h"

bool
part5_actions__action__ExploreForward_GetResult_Response__init(part5_actions__action__ExploreForward_GetResult_Response * msg)
{
  if (!msg) {
    return false;
  }
  // status
  // result
  if (!part5_actions__action__ExploreForward_Result__init(&msg->result)) {
    part5_actions__action__ExploreForward_GetResult_Response__fini(msg);
    return false;
  }
  return true;
}

void
part5_actions__action__ExploreForward_GetResult_Response__fini(part5_actions__action__ExploreForward_GetResult_Response * msg)
{
  if (!msg) {
    return;
  }
  // status
  // result
  part5_actions__action__ExploreForward_Result__fini(&msg->result);
}

bool
part5_actions__action__ExploreForward_GetResult_Response__are_equal(const part5_actions__action__ExploreForward_GetResult_Response * lhs, const part5_actions__action__ExploreForward_GetResult_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // status
  if (lhs->status != rhs->status) {
    return false;
  }
  // result
  if (!part5_actions__action__ExploreForward_Result__are_equal(
      &(lhs->result), &(rhs->result)))
  {
    return false;
  }
  return true;
}

bool
part5_actions__action__ExploreForward_GetResult_Response__copy(
  const part5_actions__action__ExploreForward_GetResult_Response * input,
  part5_actions__action__ExploreForward_GetResult_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // status
  output->status = input->status;
  // result
  if (!part5_actions__action__ExploreForward_Result__copy(
      &(input->result), &(output->result)))
  {
    return false;
  }
  return true;
}

part5_actions__action__ExploreForward_GetResult_Response *
part5_actions__action__ExploreForward_GetResult_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  part5_actions__action__ExploreForward_GetResult_Response * msg = (part5_actions__action__ExploreForward_GetResult_Response *)allocator.allocate(sizeof(part5_actions__action__ExploreForward_GetResult_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(part5_actions__action__ExploreForward_GetResult_Response));
  bool success = part5_actions__action__ExploreForward_GetResult_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
part5_actions__action__ExploreForward_GetResult_Response__destroy(part5_actions__action__ExploreForward_GetResult_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    part5_actions__action__ExploreForward_GetResult_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
part5_actions__action__ExploreForward_GetResult_Response__Sequence__init(part5_actions__action__ExploreForward_GetResult_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  part5_actions__action__ExploreForward_GetResult_Response * data = NULL;

  if (size) {
    data = (part5_actions__action__ExploreForward_GetResult_Response *)allocator.zero_allocate(size, sizeof(part5_actions__action__ExploreForward_GetResult_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = part5_actions__action__ExploreForward_GetResult_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        part5_actions__action__ExploreForward_GetResult_Response__fini(&data[i - 1]);
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
part5_actions__action__ExploreForward_GetResult_Response__Sequence__fini(part5_actions__action__ExploreForward_GetResult_Response__Sequence * array)
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
      part5_actions__action__ExploreForward_GetResult_Response__fini(&array->data[i]);
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

part5_actions__action__ExploreForward_GetResult_Response__Sequence *
part5_actions__action__ExploreForward_GetResult_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  part5_actions__action__ExploreForward_GetResult_Response__Sequence * array = (part5_actions__action__ExploreForward_GetResult_Response__Sequence *)allocator.allocate(sizeof(part5_actions__action__ExploreForward_GetResult_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = part5_actions__action__ExploreForward_GetResult_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
part5_actions__action__ExploreForward_GetResult_Response__Sequence__destroy(part5_actions__action__ExploreForward_GetResult_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    part5_actions__action__ExploreForward_GetResult_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
part5_actions__action__ExploreForward_GetResult_Response__Sequence__are_equal(const part5_actions__action__ExploreForward_GetResult_Response__Sequence * lhs, const part5_actions__action__ExploreForward_GetResult_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!part5_actions__action__ExploreForward_GetResult_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
part5_actions__action__ExploreForward_GetResult_Response__Sequence__copy(
  const part5_actions__action__ExploreForward_GetResult_Response__Sequence * input,
  part5_actions__action__ExploreForward_GetResult_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(part5_actions__action__ExploreForward_GetResult_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    part5_actions__action__ExploreForward_GetResult_Response * data =
      (part5_actions__action__ExploreForward_GetResult_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!part5_actions__action__ExploreForward_GetResult_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          part5_actions__action__ExploreForward_GetResult_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!part5_actions__action__ExploreForward_GetResult_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__functions.h"
// Member `feedback`
// already included above
// #include "part5_actions/action/detail/explore_forward__functions.h"

bool
part5_actions__action__ExploreForward_FeedbackMessage__init(part5_actions__action__ExploreForward_FeedbackMessage * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    part5_actions__action__ExploreForward_FeedbackMessage__fini(msg);
    return false;
  }
  // feedback
  if (!part5_actions__action__ExploreForward_Feedback__init(&msg->feedback)) {
    part5_actions__action__ExploreForward_FeedbackMessage__fini(msg);
    return false;
  }
  return true;
}

void
part5_actions__action__ExploreForward_FeedbackMessage__fini(part5_actions__action__ExploreForward_FeedbackMessage * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
  // feedback
  part5_actions__action__ExploreForward_Feedback__fini(&msg->feedback);
}

bool
part5_actions__action__ExploreForward_FeedbackMessage__are_equal(const part5_actions__action__ExploreForward_FeedbackMessage * lhs, const part5_actions__action__ExploreForward_FeedbackMessage * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  // feedback
  if (!part5_actions__action__ExploreForward_Feedback__are_equal(
      &(lhs->feedback), &(rhs->feedback)))
  {
    return false;
  }
  return true;
}

bool
part5_actions__action__ExploreForward_FeedbackMessage__copy(
  const part5_actions__action__ExploreForward_FeedbackMessage * input,
  part5_actions__action__ExploreForward_FeedbackMessage * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  // feedback
  if (!part5_actions__action__ExploreForward_Feedback__copy(
      &(input->feedback), &(output->feedback)))
  {
    return false;
  }
  return true;
}

part5_actions__action__ExploreForward_FeedbackMessage *
part5_actions__action__ExploreForward_FeedbackMessage__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  part5_actions__action__ExploreForward_FeedbackMessage * msg = (part5_actions__action__ExploreForward_FeedbackMessage *)allocator.allocate(sizeof(part5_actions__action__ExploreForward_FeedbackMessage), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(part5_actions__action__ExploreForward_FeedbackMessage));
  bool success = part5_actions__action__ExploreForward_FeedbackMessage__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
part5_actions__action__ExploreForward_FeedbackMessage__destroy(part5_actions__action__ExploreForward_FeedbackMessage * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    part5_actions__action__ExploreForward_FeedbackMessage__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
part5_actions__action__ExploreForward_FeedbackMessage__Sequence__init(part5_actions__action__ExploreForward_FeedbackMessage__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  part5_actions__action__ExploreForward_FeedbackMessage * data = NULL;

  if (size) {
    data = (part5_actions__action__ExploreForward_FeedbackMessage *)allocator.zero_allocate(size, sizeof(part5_actions__action__ExploreForward_FeedbackMessage), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = part5_actions__action__ExploreForward_FeedbackMessage__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        part5_actions__action__ExploreForward_FeedbackMessage__fini(&data[i - 1]);
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
part5_actions__action__ExploreForward_FeedbackMessage__Sequence__fini(part5_actions__action__ExploreForward_FeedbackMessage__Sequence * array)
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
      part5_actions__action__ExploreForward_FeedbackMessage__fini(&array->data[i]);
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

part5_actions__action__ExploreForward_FeedbackMessage__Sequence *
part5_actions__action__ExploreForward_FeedbackMessage__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  part5_actions__action__ExploreForward_FeedbackMessage__Sequence * array = (part5_actions__action__ExploreForward_FeedbackMessage__Sequence *)allocator.allocate(sizeof(part5_actions__action__ExploreForward_FeedbackMessage__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = part5_actions__action__ExploreForward_FeedbackMessage__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
part5_actions__action__ExploreForward_FeedbackMessage__Sequence__destroy(part5_actions__action__ExploreForward_FeedbackMessage__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    part5_actions__action__ExploreForward_FeedbackMessage__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
part5_actions__action__ExploreForward_FeedbackMessage__Sequence__are_equal(const part5_actions__action__ExploreForward_FeedbackMessage__Sequence * lhs, const part5_actions__action__ExploreForward_FeedbackMessage__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!part5_actions__action__ExploreForward_FeedbackMessage__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
part5_actions__action__ExploreForward_FeedbackMessage__Sequence__copy(
  const part5_actions__action__ExploreForward_FeedbackMessage__Sequence * input,
  part5_actions__action__ExploreForward_FeedbackMessage__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(part5_actions__action__ExploreForward_FeedbackMessage);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    part5_actions__action__ExploreForward_FeedbackMessage * data =
      (part5_actions__action__ExploreForward_FeedbackMessage *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!part5_actions__action__ExploreForward_FeedbackMessage__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          part5_actions__action__ExploreForward_FeedbackMessage__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!part5_actions__action__ExploreForward_FeedbackMessage__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
