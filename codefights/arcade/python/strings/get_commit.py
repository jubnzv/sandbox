"""
The Abanamama Version System (AVS) is a software versioning and revision control system used in highly secure environments. In this system, each commit is assigned a unique name, the first part of which consists of the username encrypted in the base-4 system using symbols '0', '?', '+', and '!', and the second part consists of symbols of English alphabet.

Given such commit, your task is go remove the username part from it and return the second part as an answer.
"""
def getCommit(commit):
    return ''.join(c for c in commit if c.isalpha())
