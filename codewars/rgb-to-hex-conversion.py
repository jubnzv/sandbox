'''
https://www.codewars.com/kata/rgb-to-hex-conversion

The rgb() method is incomplete. Complete the method so that passing in RGB decimal values will result in a hexadecimal representation being returned.  The valid decimal values for RGB are 0 - 255.  Any (r,g,b) argument values that fall out of that range should be rounded to the closest valid value. 

The following are examples of  expected output values:
```javascript
rgb(255, 255, 255) // returns FFFFFF
rgb(255, 255, 300) // returns FFFFFF
rgb(0,0,0) // returns 000000
rgb(148, 0, 211) // returns 9400D3
```
```coffeescript
rgb(255, 255, 255) # returns FFFFFF
rgb(255, 255, 300) # returns FFFFFF
rgb(0,0,0) # returns 000000
rgb(148, 0, 211) # returns 9400D3
```
```ruby
rgb(255, 255, 255) # returns FFFFFF
rgb(255, 255, 300) # returns FFFFFF
rgb(0,0,0) # returns 000000
rgb(148, 0, 211) # returns 9400D3
```
```python
rgb(255, 255, 255) # returns FFFFFF
rgb(255, 255, 300) # returns FFFFFF
rgb(0,0,0) # returns 000000
rgb(148, 0, 211) # returns 9400D3
```
```csharp
Rgb(255, 255, 255) # returns FFFFFF
Rgb(255, 255, 300) # returns FFFFFF
Rgb(0,0,0) # returns 000000
Rgb(148, 0, 211) # returns 9400D3
```
```fsharp
rgb 255  255  255 // returns FFFFFF
rgb 255  255  300 // returns FFFFFF
rgb 0 0 0 // returns 000000
rgb 148  0  211 // returns 9400D3
```
```cpp
rgb(255, 255, 255) # returns FFFFFF
rgb(255, 255, 300) # returns FFFFFF
rgb(0,0,0) # returns 000000
rgb(148, 0, 211) # returns 9400D3
```
```r
rgb(255, 255, 255)
[1] "FFFFFF"

rgb(255, 255, 300)
[1] "FFFFFF"

rgb(0, 0, 0)
[1] "000000"

rgb(148, 0, 211)
[1] "9400D3"
```
```dart
rgb(255, 255, 255) // returns FFFFFF
rgb(255, 255, 300) // returns FFFFFF
rgb(0, 0, 0)       // returns 000000
rgb(148, 0, 211)   // returns 9400D3
```
'''
rgb = lambda r, g, b: ''.join(['{0:02X}'.format(i) if 0 <= i <= 255 else ('00' if i < 0 else 'FF') for i in (r, g, b)])

