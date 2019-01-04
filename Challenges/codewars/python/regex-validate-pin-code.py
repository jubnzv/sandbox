'''
https://www.codewars.com/kata/regex-validate-pin-code

ATM machines allow 4 or 6 digit PIN codes and PIN codes cannot contain anything but exactly 4 digits or exactly 6 digits. 


If the function is passed a valid PIN string, return true, else return false.


eg: 
```javascript
validatePIN("1234") === true
validatePIN("12345") === false
validatePIN("a234") === false
```
```python
validate_pin("1234") == True
validate_pin("12345") == False
validate_pin("a234") == False
```
```csharp
ValidatePin("1234") => true
ValidatePin("12345") => false
ValidatePin("a234") => false
```
'''
# validate_pin = lambda pin: len(pin) in [4, 6] and all([c.isdigit() for c in pin])
validate_pin = lambda pin: len(pin) in [4, 6] and pin.isdigit()
