// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from part5_actions:action/ExploreForward.idl
// generated code does not contain a copyright notice

#ifndef PART5_ACTIONS__ACTION__DETAIL__EXPLORE_FORWARD__BUILDER_HPP_
#define PART5_ACTIONS__ACTION__DETAIL__EXPLORE_FORWARD__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "part5_actions/action/detail/explore_forward__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace part5_actions
{

namespace action
{

namespace builder
{

class Init_ExploreForward_Goal_stopping_distance
{
public:
  explicit Init_ExploreForward_Goal_stopping_distance(::part5_actions::action::ExploreForward_Goal & msg)
  : msg_(msg)
  {}
  ::part5_actions::action::ExploreForward_Goal stopping_distance(::part5_actions::action::ExploreForward_Goal::_stopping_distance_type arg)
  {
    msg_.stopping_distance = std::move(arg);
    return std::move(msg_);
  }

private:
  ::part5_actions::action::ExploreForward_Goal msg_;
};

class Init_ExploreForward_Goal_fwd_velocity
{
public:
  Init_ExploreForward_Goal_fwd_velocity()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ExploreForward_Goal_stopping_distance fwd_velocity(::part5_actions::action::ExploreForward_Goal::_fwd_velocity_type arg)
  {
    msg_.fwd_velocity = std::move(arg);
    return Init_ExploreForward_Goal_stopping_distance(msg_);
  }

private:
  ::part5_actions::action::ExploreForward_Goal msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::part5_actions::action::ExploreForward_Goal>()
{
  return part5_actions::action::builder::Init_ExploreForward_Goal_fwd_velocity();
}

}  // namespace part5_actions


namespace part5_actions
{

namespace action
{

namespace builder
{

class Init_ExploreForward_Result_closest_obstacle
{
public:
  explicit Init_ExploreForward_Result_closest_obstacle(::part5_actions::action::ExploreForward_Result & msg)
  : msg_(msg)
  {}
  ::part5_actions::action::ExploreForward_Result closest_obstacle(::part5_actions::action::ExploreForward_Result::_closest_obstacle_type arg)
  {
    msg_.closest_obstacle = std::move(arg);
    return std::move(msg_);
  }

private:
  ::part5_actions::action::ExploreForward_Result msg_;
};

class Init_ExploreForward_Result_total_distance_travelled
{
public:
  Init_ExploreForward_Result_total_distance_travelled()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ExploreForward_Result_closest_obstacle total_distance_travelled(::part5_actions::action::ExploreForward_Result::_total_distance_travelled_type arg)
  {
    msg_.total_distance_travelled = std::move(arg);
    return Init_ExploreForward_Result_closest_obstacle(msg_);
  }

private:
  ::part5_actions::action::ExploreForward_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::part5_actions::action::ExploreForward_Result>()
{
  return part5_actions::action::builder::Init_ExploreForward_Result_total_distance_travelled();
}

}  // namespace part5_actions


namespace part5_actions
{

namespace action
{

namespace builder
{

class Init_ExploreForward_Feedback_current_distance_travelled
{
public:
  Init_ExploreForward_Feedback_current_distance_travelled()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::part5_actions::action::ExploreForward_Feedback current_distance_travelled(::part5_actions::action::ExploreForward_Feedback::_current_distance_travelled_type arg)
  {
    msg_.current_distance_travelled = std::move(arg);
    return std::move(msg_);
  }

private:
  ::part5_actions::action::ExploreForward_Feedback msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::part5_actions::action::ExploreForward_Feedback>()
{
  return part5_actions::action::builder::Init_ExploreForward_Feedback_current_distance_travelled();
}

}  // namespace part5_actions


namespace part5_actions
{

namespace action
{

namespace builder
{

class Init_ExploreForward_SendGoal_Request_goal
{
public:
  explicit Init_ExploreForward_SendGoal_Request_goal(::part5_actions::action::ExploreForward_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::part5_actions::action::ExploreForward_SendGoal_Request goal(::part5_actions::action::ExploreForward_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::part5_actions::action::ExploreForward_SendGoal_Request msg_;
};

class Init_ExploreForward_SendGoal_Request_goal_id
{
public:
  Init_ExploreForward_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ExploreForward_SendGoal_Request_goal goal_id(::part5_actions::action::ExploreForward_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_ExploreForward_SendGoal_Request_goal(msg_);
  }

private:
  ::part5_actions::action::ExploreForward_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::part5_actions::action::ExploreForward_SendGoal_Request>()
{
  return part5_actions::action::builder::Init_ExploreForward_SendGoal_Request_goal_id();
}

}  // namespace part5_actions


namespace part5_actions
{

namespace action
{

namespace builder
{

class Init_ExploreForward_SendGoal_Response_stamp
{
public:
  explicit Init_ExploreForward_SendGoal_Response_stamp(::part5_actions::action::ExploreForward_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::part5_actions::action::ExploreForward_SendGoal_Response stamp(::part5_actions::action::ExploreForward_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::part5_actions::action::ExploreForward_SendGoal_Response msg_;
};

class Init_ExploreForward_SendGoal_Response_accepted
{
public:
  Init_ExploreForward_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ExploreForward_SendGoal_Response_stamp accepted(::part5_actions::action::ExploreForward_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_ExploreForward_SendGoal_Response_stamp(msg_);
  }

private:
  ::part5_actions::action::ExploreForward_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::part5_actions::action::ExploreForward_SendGoal_Response>()
{
  return part5_actions::action::builder::Init_ExploreForward_SendGoal_Response_accepted();
}

}  // namespace part5_actions


namespace part5_actions
{

namespace action
{

namespace builder
{

class Init_ExploreForward_GetResult_Request_goal_id
{
public:
  Init_ExploreForward_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::part5_actions::action::ExploreForward_GetResult_Request goal_id(::part5_actions::action::ExploreForward_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::part5_actions::action::ExploreForward_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::part5_actions::action::ExploreForward_GetResult_Request>()
{
  return part5_actions::action::builder::Init_ExploreForward_GetResult_Request_goal_id();
}

}  // namespace part5_actions


namespace part5_actions
{

namespace action
{

namespace builder
{

class Init_ExploreForward_GetResult_Response_result
{
public:
  explicit Init_ExploreForward_GetResult_Response_result(::part5_actions::action::ExploreForward_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::part5_actions::action::ExploreForward_GetResult_Response result(::part5_actions::action::ExploreForward_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::part5_actions::action::ExploreForward_GetResult_Response msg_;
};

class Init_ExploreForward_GetResult_Response_status
{
public:
  Init_ExploreForward_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ExploreForward_GetResult_Response_result status(::part5_actions::action::ExploreForward_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_ExploreForward_GetResult_Response_result(msg_);
  }

private:
  ::part5_actions::action::ExploreForward_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::part5_actions::action::ExploreForward_GetResult_Response>()
{
  return part5_actions::action::builder::Init_ExploreForward_GetResult_Response_status();
}

}  // namespace part5_actions


namespace part5_actions
{

namespace action
{

namespace builder
{

class Init_ExploreForward_FeedbackMessage_feedback
{
public:
  explicit Init_ExploreForward_FeedbackMessage_feedback(::part5_actions::action::ExploreForward_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::part5_actions::action::ExploreForward_FeedbackMessage feedback(::part5_actions::action::ExploreForward_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::part5_actions::action::ExploreForward_FeedbackMessage msg_;
};

class Init_ExploreForward_FeedbackMessage_goal_id
{
public:
  Init_ExploreForward_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ExploreForward_FeedbackMessage_feedback goal_id(::part5_actions::action::ExploreForward_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_ExploreForward_FeedbackMessage_feedback(msg_);
  }

private:
  ::part5_actions::action::ExploreForward_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::part5_actions::action::ExploreForward_FeedbackMessage>()
{
  return part5_actions::action::builder::Init_ExploreForward_FeedbackMessage_goal_id();
}

}  // namespace part5_actions

#endif  // PART5_ACTIONS__ACTION__DETAIL__EXPLORE_FORWARD__BUILDER_HPP_
