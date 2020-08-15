from threading import Lock


class BankAccount(object):

    lock = Lock()

    def __init__(self):
        self.is_open = True
        self.balance = 0

    def get_balance(self):
        with self.lock:
            if not self.is_open:
                raise ValueError('Account is closed')
            return self.balance

    def open(self):
        with self.lock:
            self.is_open = True

    def deposit(self, amount):
        with self.lock:
            if not self.is_open:
                raise ValueError('Account is closed')
            if amount < 0:
                raise ValueError('Can\'t deposite negative')
            self.balance += amount

    def withdraw(self, amount):
        with self.lock:
            if not self.is_open:
                raise ValueError('Account is closed')
            if amount > self.balance:
                raise ValueError('Can\'t withdraw more than deposited')
            if amount < 0:
                raise ValueError('Can\'t withdraw negative')
            self.balance -= amount

    def close(self):
        with self.lock:
            self.is_open = False
