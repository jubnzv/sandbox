'''
https://www.codewars.com/kata/convert-string-to-camel-case

Complete the method/function so that it converts dash/underscore delimited words into camel casing. The first word within the output should be capitalized only if the original word was capitalized. 

Examples:

```javascript
// returns "theStealthWarrior"
toCamelCase("the-stealth-warrior") 

// returns "TheStealthWarrior"
toCamelCase("The_Stealth_Warrior") 
```

```coffeescript
# returns "theStealthWarrior"
toCamelCase("the-stealth-warrior") 

# returns "TheStealthWarrior"
toCamelCase("The_Stealth_Warrior") 
```
```ruby
# returns "theStealthWarrior"
to_camel_case("the-stealth-warrior") 

# returns "TheStealthWarrior"
to_camel_case("The_Stealth_Warrior") 
```
```python
# returns "theStealthWarrior"
to_camel_case("the-stealth-warrior") 

# returns "TheStealthWarrior"
to_camel_case("The_Stealth_Warrior") 
```
```elixir
# returns "theStealthWarrior"
to_camel_case("the-stealth-warrior") 

# returns "TheStealthWarrior"
to_camel_case("The_Stealth_Warrior") 
```
```haskell
-- returns "theStealthWarrior"
toCamelCase "the-stealth-warrior"

-- returns "TheStealthWarrior"
toCamelCase "The_Stealth_Warrior"
```
```csharp
// returns "theStealthWarrior"
Kata.ToCamelCase("the-stealth-warrior") 

// returns "TheStealthWarrior"
Kata.ToCamelCase("The_Stealth_Warrior") 
```
```cpp
// returns "theStealthWarrior"
to_camel_case("the-stealth-warrior") 

// returns "TheStealthWarrior"
to_camel_case("The_Stealth_Warrior") 
```
```r
# returns "theStealthWarrior"
to_camel_case("the-stealth-warrior")

# returns "TheStealthWarrior"
to_camel_case("The_Stealth_Warrior")

# returns "mixedSeparatorExample"
to_camel_case("mixed-separator_example")
```


'''
import re
to_camel_case = lambda s: re.sub(r'([-_])([a-zA-Z])', lambda p: p.group(2).upper(), s)


if __name__ == '__main__':
    print(to_camel_case("the_stealth_warrior"))
    print(to_camel_case("theStealth-Warrior"))
