#!/usr/bin/python3.7
import bisect

from copy import copy
from itertools import chain


class School(object):
    def __init__(self):
        self.students = dict()

    def add_student(self, name, grade):
        students = copy(self.students.get(grade, list()))
        bisect.insort(students, name)
        self.students[grade] = students

    def roster(self):
        return list(chain.from_iterable([self.students[k]
            for k in sorted(self.students)]))

    def grade(self, grade_number):
        return self.students.get(grade_number, list())

