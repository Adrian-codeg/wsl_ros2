// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from part4_services:srv/MyNumberGame.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "part4_services/srv/detail/my_number_game__struct.h"
#include "part4_services/srv/detail/my_number_game__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool part4_services__srv__my_number_game__request__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[56];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("part4_services.srv._my_number_game.MyNumberGame_Request", full_classname_dest, 55) == 0);
  }
  part4_services__srv__MyNumberGame_Request * ros_message = _ros_message;
  {  // guess
    PyObject * field = PyObject_GetAttrString(_pymsg, "guess");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->guess = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // cheat
    PyObject * field = PyObject_GetAttrString(_pymsg, "cheat");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->cheat = (Py_True == field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * part4_services__srv__my_number_game__request__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of MyNumberGame_Request */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("part4_services.srv._my_number_game");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "MyNumberGame_Request");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  part4_services__srv__MyNumberGame_Request * ros_message = (part4_services__srv__MyNumberGame_Request *)raw_ros_message;
  {  // guess
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->guess);
    {
      int rc = PyObject_SetAttrString(_pymessage, "guess", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // cheat
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->cheat ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "cheat", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}

#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
// already included above
// #include <Python.h>
// already included above
// #include <stdbool.h>
// already included above
// #include "numpy/ndarrayobject.h"
// already included above
// #include "rosidl_runtime_c/visibility_control.h"
// already included above
// #include "part4_services/srv/detail/my_number_game__struct.h"
// already included above
// #include "part4_services/srv/detail/my_number_game__functions.h"

#include "rosidl_runtime_c/string.h"
#include "rosidl_runtime_c/string_functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool part4_services__srv__my_number_game__response__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[57];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("part4_services.srv._my_number_game.MyNumberGame_Response", full_classname_dest, 56) == 0);
  }
  part4_services__srv__MyNumberGame_Response * ros_message = _ros_message;
  {  // num_guesses
    PyObject * field = PyObject_GetAttrString(_pymsg, "num_guesses");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->num_guesses = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // hint
    PyObject * field = PyObject_GetAttrString(_pymsg, "hint");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->hint, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // correct
    PyObject * field = PyObject_GetAttrString(_pymsg, "correct");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->correct = (Py_True == field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * part4_services__srv__my_number_game__response__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of MyNumberGame_Response */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("part4_services.srv._my_number_game");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "MyNumberGame_Response");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  part4_services__srv__MyNumberGame_Response * ros_message = (part4_services__srv__MyNumberGame_Response *)raw_ros_message;
  {  // num_guesses
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->num_guesses);
    {
      int rc = PyObject_SetAttrString(_pymessage, "num_guesses", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // hint
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->hint.data,
      strlen(ros_message->hint.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "hint", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // correct
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->correct ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "correct", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
