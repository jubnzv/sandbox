'''
https://www.codewars.com/kata/how-much-will-you-spend

<h1>How much will you spend?</h1>

Given a dictionary of items and their costs and a array specifying the items bought, calculate the total cost of the items plus a given tax.

If item doesn't exist in the given cost values, the item is ignored.

Output should be rounded to two decimal places.

Python:
```python
costs = {'socks':5, 'shoes':60, 'sweater':30}
get_total(costs, ['socks', 'shoes'], 0.09)
#-> 5+60 = 65
#-> 65 + 0.09 of 65 = 70.85
#-> Output: 70.85
```
'''
def get_total_1(costs, items, tax):
    return round(sum([costs[i] for i in items if i in costs.keys()]) * (tax + 1), 2)

def get_total(costs, items, tax):
    return round(sum(costs.get(i, 0) for i in items) * (tax + 1), 2)


if __name__ == '__main__':
    costs1 = {
            '24x Expo Dry-Erase': 30.0,
            'Levis Jeans': 59.49,
            'Ninja Blender': 69.99,
            'Cards Against Humanity': 25.0,
            'Transcend 24GB': 30.0,
            'Beats Headphones': 199.99,
            'Exploding Kittens': 19.99,
            'Raspberry Pi Zero': 5.0,
            'Crayola 24x Crayons': 9.99,
            'Fire Tablet': 69.99,
            'Echo Dot': 39.99,
            'CodeWars Red': 25.0,
            'Fire TV': 39.99
    }
    # items1 = ['Cards Against Humanity', 'CodeWars Red', 'Raspberry Pi Zero', 'Cards Against Humanity']
    items1 = ['Cards Against Humanity', 'foo', 'CodeWars Red', 'Raspberry Pi Zero', 'Cards Against Humanity']
    print(get_total(costs1, items1, 0))
