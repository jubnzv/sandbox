'''
https://www.codewars.com/kata/invert-the-triangle

Each time the function is called it should invert the passed triangle.
Make upside down the given triangle and invert the chars in the triangle.

```
if a char = " ", make it = "#"
if a char = "#", make it = " "
```

```
    # 
   ###   
  #####  
 ####### 
######### // normal


         // inverted
#       #
##     ##
###   ###
#### ####

#### #### 
###   ###
##     ##
#       #
         // normal


######### // inverted
 ####### 
  #####  
   ###   
    #    

```

maketri() is at your disposal.
'''
invert_triangle = lambda t: ''.join([' ' if i == '#' else '#' if i == ' ' else i for i in reversed(t)])

