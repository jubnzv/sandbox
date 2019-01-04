class Allergies(object):

    allergens = {
        'eggs': 1,
        'peanuts': 2,
        'shellfish': 4,
        'strawberries': 8,
        'tomatoes': 16,
        'chocolate': 32,
        'pollen': 64,
        'cats': 128}

    def __init__(self, score):
        self.score = score
        self._lst = [k for k in self.allergens.keys()
                     if self.is_allergic_to(k)]

    def is_allergic_to(self, item):
        return 0 != (self.score & self.allergens.get(item, None))

    @property
    def lst(self):
        return self._lst
