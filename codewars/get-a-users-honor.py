'''
https://www.codewars.com/kata/get-a-users-honor/train/python

If you want/don't want your username to be in the tests, ask me in the discourse area. There can't be too many though because the server may time out.

Example:
>>> get_honor('dpleshkov')
4418
>>> get_honor('jhoffner')
21949
F# examples
>>> GetHonor('dpleshkov')
4418
>>> GetHonor('jhoffner')
21949
¹ Honor may or may not be current to the user

Libraries/Recommendations:

Fsharp:
open System.Net: use this namespace for opening a webpage(It's just a suggestion).
open System.Text.RegularExpressions: this namepsace will give you access to Regex.

Python:
urllib.request.urlopen: Opens up a webpage.
re: The RegEx library for Python.
bs4(BeautifulSoup): A tool for scraping HTML and XML.

Notes:
While this kata is in beta, please vote on it and give your rank assessment.
Feel free to voice your comments and concerns in the discourse area.
There is no example tests. Sorry, the honor may vary from time to time. I apologize for the inconvenience.
'''
import urllib
import re
import bs4

def get_honor(username):
    response = urllib.urlopen('https://www.codewars.com/users/' + username)
    html = response.read()
    soup = bs4.BeautifulSoup(html, 'html.parser')
    fs = soup.findAll(text='Honor:')[0]
    honor = []
    while not honor:
        fs = fs.parent
        honor = re.findall('\d+(?:,?\d*)', str(fs.contents))
    return int(honor[0].replace(',', ''))

if __name__ == '__main__':
    print(get_honor('dpleshkov'))
    print(get_honor('jubnzv'))
