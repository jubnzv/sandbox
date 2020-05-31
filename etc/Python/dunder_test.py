import unittest


class Foo:
    def __bar__(self):
        return 42
    def __bar(self):
        return 19


class FooTest(unittest.TestCase):
    foo = Foo()

    def test_bar(self):
        self.assertEqual(self.foo.__bar__(), 42)
        self.assertEqual(self.foo._Foo__bar(), 19)
