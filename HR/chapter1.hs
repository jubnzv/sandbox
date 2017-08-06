-- Contains examples and exercies from chapter 1 "Getting started" of "The Haskell Road to Logic, Maths and Programming" textbook.

import Debug.Trace
import Data.Char

-- Maximum of the list of integers
mxmInt :: [Int] -> Int
mxmInt [] = error "empty list"
mxmInt [x] = x
mxmInt (x:xs) = max x (mxmInt xs)

-- Minimum of list
mnmInt :: [Int] -> Int
mnmInt [] = error "empty list"
mnmInt [x] = x
mnmInt (x:xs) = min x (mnmInt xs)

-- Ex. 1.10
-- Define a function removeFst that removes the first occurrence of a integer m from a list of integers.
-- If m does not occur in the list, the list remains unchanged.
--
removeFst :: Int -> [Int] -> [Int]
removeFst m [] = []
removeFst m [x]
  | x == m = []
  | otherwise = [x]
removeFst m (x:xs)
  | x == m = xs
  | otherwise = x : removeFst m xs

-- Function that sorts a list of integers in order of increasing size
--
srtInts :: [Int] -> [Int]
srtInts [] = []
srtInts xs = m : (srtInts (removeFst m xs)) where m = mnmInt xs

-- Average of a list of integers
--
average :: [Int] -> Float
average [] = error "empty list"
average xs = fromIntegral (sum xs) / fromIntegral (length xs)

-- Ex. 1.13
-- Write a function count for counting the number of occurrences of a character in a string.
--
count :: Char -> String -> Int
count c [] = 0
count c (x:xs)
  | c == x = 1 + (count c xs)
  | otherwise = count c xs

-- Ex. 1.14
-- A function that transforming strings like a: a1 a2 a3 => a1 a2 a2 a3 a3 a3 ...
--
blowup :: String -> String
blowup [] = []
blowup [c] = [c]
blowup (x:xs) = 
  (blowup (init (x:xs))) ++
  (replicate
      (length (x:xs))
      (last (x:xs))
  )

-- Quicksort: implementation for example
--
-- quicksort :: (Ord a) => [a] -> [a]
-- quicksort [] = []
-- quicksort (x:xs) =
--   let smaller = quicksort [a | a <- xs, a <= x]
--       bigger = quicksort [a | a <- xs, a > x]
--   in smaller ++ [x] ++ bigger

-- Converts string to lower case
strToLower :: String -> String
strToLower [] = []
strToLower s = [Data.Char.toLower x | x <- s]

-- Ex. 1.15
-- Write a function srtString that sorts list of strings in alphabetical order
--
srtString :: [String] -> [String]
srtString [] = []
srtString (x:xs) =
  let
    smaller = srtString [s | s <- xs, strToLower s <= strToLower x]
    bigger = srtString [s | s <- xs, strToLower s > strToLower x]
  in smaller ++ [x] ++ bigger

-- Example 1.16
-- Checks start s1 is prefix to s2
prefix :: String -> String -> Bool
prefix [] ys = True
prefix (x:xs) [] = False
prefix (x:xs) (y:ys) =
  (x == y) && prefix xs ys

-- Ex. 1.17
-- Write a function substring that checks that s1 is substring of s2
substring :: String -> String -> Bool
substring xs ys
  | (length) ys < (length xs) = False
  | prefix xs ys = True
  | trace ("ys = " ++ show ys) $ substring xs ys' = True
  | otherwise = False
  where ys' = (tail ys)
  
divides :: Integer -> Integer -> Bool
divides d n = rem n d == 0

-- ldf :: Integer -> Integer -> Integer
ldf k n | divides k n = k
        | k^2 > n = n
        | otherwise = ldf (k+1) n

ld :: Integer -> Integer
ld n = ldf 2 n

-- Prime factorization example
factors :: Integer -> [Integer]
factors n | n < 1 = error "arg not positive"
          | n == 1 = []
          | otherwise = p : factors (div n p) where p = ld n

-- Ex. 1.20
-- Use map to write a function lengths that takes a list of lists and returns a list of the corresponding list lengths
lengths :: [[Int]] -> [Int]
lengths (x:xs)
  | length xs == 0 = map length [x]
  | otherwise      = (map length [x]) ++ (lengths xs)

-- Ex. 1.21
-- User map to write a function sumLengths that takes a list of lists and returns the sum of their lengths.
sumLengths :: [[Int]] -> Int
sumLengths (x:xs) = sum (map length (x:xs))
  
-- Example 1.22
-- Filter the prime numbers from infinite list [2..] of natural numbers
prime0 :: Integer -> Bool
prime0 n | n < 1 = error "not a positive integer"
         | n == 1 = False
         | otherwise = ld n == n

primes0 :: [Integer]
primes0 = filter prime0 [2..]

-- Example 1.23
-- Another 'primes' implementation
ldp :: Integer -> Integer
ldp n = ldpf primes1 n

ldpf :: [Integer] -> Integer -> Integer
ldpf (p:ps) n | rem n p == 0 = p
              | p^2 > n      = n
              | otherwise    = ldpf ps n

primes1 :: [Integer]
primes1 = 2 : filter prime [3..]

prime :: Integer -> Bool
prime n | n < 1     = error "no a positive integer"
        | n == 1    = False
        | otherwise = ldp n == n
