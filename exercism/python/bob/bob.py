def hey(phrase: str):
    phrase = phrase.strip()

    if not phrase:
        return 'Fine. Be that way!'

    if phrase.endswith('?'):
        if phrase.isupper():
            return 'Calm down, I know what I\'m doing!'
        else:
            return 'Sure.'

    if phrase.isupper():
        return 'Whoa, chill out!'

    return 'Whatever.'
