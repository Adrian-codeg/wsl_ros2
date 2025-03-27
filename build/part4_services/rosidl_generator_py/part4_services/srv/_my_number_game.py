# generated from rosidl_generator_py/resource/_idl.py.em
# with input from part4_services:srv/MyNumberGame.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_MyNumberGame_Request(type):
    """Metaclass of message 'MyNumberGame_Request'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('part4_services')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'part4_services.srv.MyNumberGame_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__my_number_game__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__my_number_game__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__my_number_game__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__my_number_game__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__my_number_game__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class MyNumberGame_Request(metaclass=Metaclass_MyNumberGame_Request):
    """Message class 'MyNumberGame_Request'."""

    __slots__ = [
        '_guess',
        '_cheat',
    ]

    _fields_and_field_types = {
        'guess': 'int32',
        'cheat': 'boolean',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.guess = kwargs.get('guess', int())
        self.cheat = kwargs.get('cheat', bool())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.guess != other.guess:
            return False
        if self.cheat != other.cheat:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def guess(self):
        """Message field 'guess'."""
        return self._guess

    @guess.setter
    def guess(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'guess' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'guess' field must be an integer in [-2147483648, 2147483647]"
        self._guess = value

    @builtins.property
    def cheat(self):
        """Message field 'cheat'."""
        return self._cheat

    @cheat.setter
    def cheat(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'cheat' field must be of type 'bool'"
        self._cheat = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_MyNumberGame_Response(type):
    """Metaclass of message 'MyNumberGame_Response'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('part4_services')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'part4_services.srv.MyNumberGame_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__my_number_game__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__my_number_game__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__my_number_game__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__my_number_game__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__my_number_game__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class MyNumberGame_Response(metaclass=Metaclass_MyNumberGame_Response):
    """Message class 'MyNumberGame_Response'."""

    __slots__ = [
        '_num_guesses',
        '_hint',
        '_correct',
    ]

    _fields_and_field_types = {
        'num_guesses': 'int32',
        'hint': 'string',
        'correct': 'boolean',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.num_guesses = kwargs.get('num_guesses', int())
        self.hint = kwargs.get('hint', str())
        self.correct = kwargs.get('correct', bool())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.num_guesses != other.num_guesses:
            return False
        if self.hint != other.hint:
            return False
        if self.correct != other.correct:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def num_guesses(self):
        """Message field 'num_guesses'."""
        return self._num_guesses

    @num_guesses.setter
    def num_guesses(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'num_guesses' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'num_guesses' field must be an integer in [-2147483648, 2147483647]"
        self._num_guesses = value

    @builtins.property
    def hint(self):
        """Message field 'hint'."""
        return self._hint

    @hint.setter
    def hint(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'hint' field must be of type 'str'"
        self._hint = value

    @builtins.property
    def correct(self):
        """Message field 'correct'."""
        return self._correct

    @correct.setter
    def correct(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'correct' field must be of type 'bool'"
        self._correct = value


class Metaclass_MyNumberGame(type):
    """Metaclass of service 'MyNumberGame'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('part4_services')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'part4_services.srv.MyNumberGame')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__my_number_game

            from part4_services.srv import _my_number_game
            if _my_number_game.Metaclass_MyNumberGame_Request._TYPE_SUPPORT is None:
                _my_number_game.Metaclass_MyNumberGame_Request.__import_type_support__()
            if _my_number_game.Metaclass_MyNumberGame_Response._TYPE_SUPPORT is None:
                _my_number_game.Metaclass_MyNumberGame_Response.__import_type_support__()


class MyNumberGame(metaclass=Metaclass_MyNumberGame):
    from part4_services.srv._my_number_game import MyNumberGame_Request as Request
    from part4_services.srv._my_number_game import MyNumberGame_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
