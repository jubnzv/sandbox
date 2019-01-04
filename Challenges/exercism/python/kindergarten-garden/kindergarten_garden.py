#!/usr/bin/python3.7


class Garden(object):

    _plants = {}

    plant_names = {
        'C': "Clover",
        'R': "Radishes",
        'V': "Violets",
        'G': "Grass",
    }

    default_students = [
            "Alice", "Bob", "Charlie", "David", "Eve", "Fred",
            "Ginny", "Harriet", "Ileana", "Joseph", "Kincaid", "Larry",
    ]

    def __init__(self, diagram, student_names=None):
        if student_names:
            student_names = sorted(student_names)
        else:
            student_names = self.default_students

        r1, r2 = map(iter, diagram.splitlines())
        for name in student_names:
            try:
                self._plants[name] = [self.plant_names.get(v) for v in
                        [next(r1), next(r1), next(r2), next(r2)]]
            except StopIteration:
                break

    def plants(self, name):
        return self._plants.get(name, "....")
