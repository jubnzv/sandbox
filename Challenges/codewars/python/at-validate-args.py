'''
https://www.codewars.com/kata/at-validate-args

Implement the validate_args decorator, which raises an error (InvalidArgument) when the decorated function is called with arguments of the wrong type. Validate_args takes in a sequence of argument types as a variable number of arguments. You do not have to check that the number of arguments matches, only their type (number of arguments will not be tested).

Your decorator must be well-behaved, i.e. the returned function must have the same name and docstring as the original, and must be able to handle the same arguments.

Example :

@validate_args(str)
def say_hello(name):
  return "Hello, " + name

say_hello(1) # Raises InvalidArgument
say_hello("Python") # Returns "Hello, Python"
InvalidArgument is preloaded for you. You may use it as if you had defined it in your own code.
'''
class InvalidArgument(Exception):
    pass

def validate_args(*t, **kt):

    def validate_args_inner(f):

        def wrapper(*args, **kwargs):
            wrapper.__name__ = f.__name__
            wrapper.__doc__ = f.__doc__
            for a in args:
                if type(a) not in t:
                    raise InvalidArgument
            return f(*args, **kwargs)
        return wrapper

    return validate_args_inner

@validate_args(str)
def say_hello(name):
    return "Hello, " + name

if __name__ == '__main__':
    print(say_hello("username"))
