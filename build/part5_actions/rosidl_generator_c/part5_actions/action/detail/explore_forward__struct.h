// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from part5_actions:action/ExploreForward.idl
// generated code does not contain a copyright notice

#ifndef PART5_ACTIONS__ACTION__DETAIL__EXPLORE_FORWARD__STRUCT_H_
#define PART5_ACTIONS__ACTION__DETAIL__EXPLORE_FORWARD__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in action/ExploreForward in the package part5_actions.
typedef struct part5_actions__action__ExploreForward_Goal
{
  /// The speed at which the robot should move forwards (m/s)
  float fwd_velocity;
  /// Minimum distance of an approaching obstacle before the robot stops (meters)
  float stopping_distance;
} part5_actions__action__ExploreForward_Goal;

// Struct for a sequence of part5_actions__action__ExploreForward_Goal.
typedef struct part5_actions__action__ExploreForward_Goal__Sequence
{
  part5_actions__action__ExploreForward_Goal * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} part5_actions__action__ExploreForward_Goal__Sequence;


// Constants defined in the message

/// Struct defined in action/ExploreForward in the package part5_actions.
typedef struct part5_actions__action__ExploreForward_Result
{
  /// Total distance travelled during the action (meters)
  float total_distance_travelled;
  /// LaserScan distance to the closest detected obstacle up ahead (meters)
  float closest_obstacle;
} part5_actions__action__ExploreForward_Result;

// Struct for a sequence of part5_actions__action__ExploreForward_Result.
typedef struct part5_actions__action__ExploreForward_Result__Sequence
{
  part5_actions__action__ExploreForward_Result * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} part5_actions__action__ExploreForward_Result__Sequence;


// Constants defined in the message

/// Struct defined in action/ExploreForward in the package part5_actions.
typedef struct part5_actions__action__ExploreForward_Feedback
{
  /// Distance travelled so far during the action (meters)
  float current_distance_travelled;
} part5_actions__action__ExploreForward_Feedback;

// Struct for a sequence of part5_actions__action__ExploreForward_Feedback.
typedef struct part5_actions__action__ExploreForward_Feedback__Sequence
{
  part5_actions__action__ExploreForward_Feedback * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} part5_actions__action__ExploreForward_Feedback__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'goal'
#include "part5_actions/action/detail/explore_forward__struct.h"

/// Struct defined in action/ExploreForward in the package part5_actions.
typedef struct part5_actions__action__ExploreForward_SendGoal_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
  part5_actions__action__ExploreForward_Goal goal;
} part5_actions__action__ExploreForward_SendGoal_Request;

// Struct for a sequence of part5_actions__action__ExploreForward_SendGoal_Request.
typedef struct part5_actions__action__ExploreForward_SendGoal_Request__Sequence
{
  part5_actions__action__ExploreForward_SendGoal_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} part5_actions__action__ExploreForward_SendGoal_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"

/// Struct defined in action/ExploreForward in the package part5_actions.
typedef struct part5_actions__action__ExploreForward_SendGoal_Response
{
  bool accepted;
  builtin_interfaces__msg__Time stamp;
} part5_actions__action__ExploreForward_SendGoal_Response;

// Struct for a sequence of part5_actions__action__ExploreForward_SendGoal_Response.
typedef struct part5_actions__action__ExploreForward_SendGoal_Response__Sequence
{
  part5_actions__action__ExploreForward_SendGoal_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} part5_actions__action__ExploreForward_SendGoal_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"

/// Struct defined in action/ExploreForward in the package part5_actions.
typedef struct part5_actions__action__ExploreForward_GetResult_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
} part5_actions__action__ExploreForward_GetResult_Request;

// Struct for a sequence of part5_actions__action__ExploreForward_GetResult_Request.
typedef struct part5_actions__action__ExploreForward_GetResult_Request__Sequence
{
  part5_actions__action__ExploreForward_GetResult_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} part5_actions__action__ExploreForward_GetResult_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'result'
// already included above
// #include "part5_actions/action/detail/explore_forward__struct.h"

/// Struct defined in action/ExploreForward in the package part5_actions.
typedef struct part5_actions__action__ExploreForward_GetResult_Response
{
  int8_t status;
  part5_actions__action__ExploreForward_Result result;
} part5_actions__action__ExploreForward_GetResult_Response;

// Struct for a sequence of part5_actions__action__ExploreForward_GetResult_Response.
typedef struct part5_actions__action__ExploreForward_GetResult_Response__Sequence
{
  part5_actions__action__ExploreForward_GetResult_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} part5_actions__action__ExploreForward_GetResult_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'feedback'
// already included above
// #include "part5_actions/action/detail/explore_forward__struct.h"

/// Struct defined in action/ExploreForward in the package part5_actions.
typedef struct part5_actions__action__ExploreForward_FeedbackMessage
{
  unique_identifier_msgs__msg__UUID goal_id;
  part5_actions__action__ExploreForward_Feedback feedback;
} part5_actions__action__ExploreForward_FeedbackMessage;

// Struct for a sequence of part5_actions__action__ExploreForward_FeedbackMessage.
typedef struct part5_actions__action__ExploreForward_FeedbackMessage__Sequence
{
  part5_actions__action__ExploreForward_FeedbackMessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} part5_actions__action__ExploreForward_FeedbackMessage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // PART5_ACTIONS__ACTION__DETAIL__EXPLORE_FORWARD__STRUCT_H_
