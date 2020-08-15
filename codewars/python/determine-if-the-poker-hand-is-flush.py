# https://www.codewars.com/kata/determine-if-the-poker-hand-is-flush/

# Determine if the poker hand is flush, meaning if the five cards are of the same suit.
# Your function will be passed a list/array of 5 strings, each representing a poker card in the format "5H" (5 of hearts), meaning the value of the card followed by the initial of its suit (Hearts, Spades, Diamonds or Clubs). No jokers included.
# Your function should return true if the hand is a flush, false otherwise.
# The possible card values are 2, 3, 4, 5, 6, 7, 8, 9, 10, J, Q, K, A

def is_flush(cards):
    return 1 == len(set([c[-1] for c in cards]))

if __name__ == '__main__':
    assert is_flush(["AS", "3S", "9S", "KS", "4S"]) == True
    assert is_flush(["AD", "4S", "7H", "KC", "5S"]) == False
    assert is_flush(["AD", "4S", "10H", "KC", "5S"]) == False
    assert is_flush(["QD", "4D", "10D", "KD", "5D"]) == True