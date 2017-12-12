: '
https://www.codewars.com/kata/bash-basics-check-for-file-existence

Write a BASH script which checks for a given file. If the file exists, print "Found \*fileName\*" to stdout, otherwise print "Cant find \*fileName\*."

If no arguments are supplied, print "Nothing to find"
'
#!/bin/bash
if [ $# -eq 0 ]
then
    echo 'Nothing to find'
elif [ -f $1 ]
then
    echo "Found ${1}"
else
    echo "Can't find ${1}"
fi

