: '
http://www.codewars.com/kata/bash-basics-while-loop/train/shell

Create a simple while loop in bash that prints the numbers 1-20 to stdout.

It should look like (stdout):

Count: 1
Count: 2
...
Count: 20
'
#!/bin/bash

countToTwenty() {
    var=0
    while [ "$var" -le 20 ]; do
        echo "Count: ${var}"
        var=$[ $var + 1 ]
    done
}

countToTwenty
