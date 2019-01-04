"""
A new scoring system was introduced in your university: from now on, each test will consist of the predefined list of questions, and for the ith (1-based) question a student either gets i points, or loses p points as a penalty.

Your task is to calculate the number of points a student got for some test. Implement a function that would calculate the number of points received for the test based on the given list of answers.
"""
def getPoints(answers, p):
    questionPoints = lambda i,ans: (-p, i+1)[ans]

    res = 0
    for i, ans in enumerate(answers):
        res += questionPoints(i, ans)
    return res

