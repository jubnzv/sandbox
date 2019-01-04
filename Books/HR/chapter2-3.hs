-- Contains examples and exercies from chapter 2 "Getting started" of "The Haskell Road to Logic, Maths and Programming" textbook.

import           Data.Char
import           Debug.Trace

-- module TAM0 where

-- Logic symbols definitions
--
infix 1 ==>
(==>) :: Bool -> Bool -> Bool
True  ==> x = x
False ==> x = True

infix 1 <=>
(<=>) :: Bool -> Bool -> Bool
x <=> y = x == y

-- Exclusive or
infixr 2 <+>
(<+>) :: Bool -> Bool -> Bool
x <+> y = x /= y

-- Samples of propositional formula and function
--
p = True
q = False
formula1 = (not p) && (p ==> q) <=> not (q && (not p))
formula2 p q = ((not p) && (p ==> q) <=> not (q && (not p)))

-- Validity check functions for propositional function with different number of args
--
valid1 :: (Bool -> Bool) -> Bool
valid1 bf = (bf True) && (bf False)

valid2 :: (Bool -> Bool -> Bool) -> Bool
valid2 bf =   (bf True True)
           && (bf True False)
           && (bf False True)
           && (bf False False)

valid3 :: (Bool -> Bool -> Bool -> Bool) -> Bool
valid3 bf = and [ bf p q r | p <- [True,False],
                             q <- [True,False],
                             r <- [True,False]]

valid4 :: (Bool -> Bool -> Bool -> Bool -> Bool) -> Bool
valid4 bf = and [ bf p q r s | p <- [True,False],
                               q <- [True,False],
                               r <- [True,False],
                               s <- [True,False]]


-- Excluded middle law / tertium non datur
excluded_middle :: Bool -> Bool
excluded_middle p = p || not p

-- P => (Q => P) = (P => Q) => P
form1 p q = p ==> (q ==> p)
form2 p q = (p ==> q) ==> p

-- Logical equivalence
logEquiv1 :: (Bool -> Bool) -> (Bool -> Bool) -> Bool
logEquiv1 bf1 bf2 =
  (bf1 True <=> bf2 True) && (bf1 False && bf2 False)

logEquiv2 :: (Bool -> Bool -> Bool) ->
             (Bool -> Bool -> Bool) -> Bool
logEquiv2 bf1 bf2 =
  and [(bf1 p q) <=> (bf2 p q) | p <- [True,False],
                                 q <- [True,False]]

logEquiv3 :: (Bool -> Bool -> Bool -> Bool) ->
             (Bool -> Bool -> Bool -> Bool) -> Bool
logEquiv3 bf1 bf2 =
  and [(bf1 p q r) <=> (bf2 p q r) | p <- [True,False],
                                     q <- [True,False],
                                     r <- [True,False]]

formula3 p q = p
formula4 p q = (p <+> q) <+> q
formula5 p q = p <=> ((p <+> q) <+> q)

-- Some userful equivalences writing as lambda expressions
--
-- Double negation
test1 = logEquiv1 id (\ p -> not (not p))
-- Laws of idempotence
test2a = logEquiv1 id (\ p -> p && p)
test2b = logEquiv1 id (\ p -> p || p)

-- 2.29 Summation example
-- $\sum_{i=1}_{5} i
fsum = sum [i | i <- [1..5]]

-- 2.30 Abstraction example
-- {x \in A | P}
-- fabst = [x | x <- list, property x]

-- Lambda abstraction example
square1 :: Integer -> Integer
square1 x = x ^ 2

square2 :: Integer -> Integer
square2 = \ x -> x^2

-- Quadratic equations solver via lambdas
solveQdr :: (Float,Float,Float) -> (Float,Float)
solveQdr = \ (a,b,c) -> if a == 0 then error "not quadratic"
                        else let d = b^2 - 4*a*c in
                        if d < 0 then error "no real solutions"
                        else
                          ((- b + sqrt d) / 2*a,
                           (- b - sqrt d) / 2*a)

-- Quantifiers implementation
any', all' :: (a -> Bool) -> [a] -> Bool
any' p = or . map p
all' p = and . map p

every, some :: [a] -> (a -> Bool) -> Bool
every xs p = all' p xs
some xs p = any' p xs
