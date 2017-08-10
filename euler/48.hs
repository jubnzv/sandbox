-- https://projecteuler.net/problem=48
--
-- The series, 1^1 + 2^2 + 3^3 + ... + 10^10 = 10405071317.
-- Find the last ten digits of the series, 1^1 + 2^2 + 3^3 + ... + 1000^1000.
import           Debug.Trace

-- digs: representate number as list of digits e.g. 12563 = [1,2,5,6,3]
digs :: Int -> [Int]
digs 0 = []
digs x = digs (div x 10) ++ [mod x 10]

-- lastdigs: last number of elements of list, total n digits.
-- If input integer has less than 10 digits, they are filled by infix zeroes.
lastelems :: [Int] -> Int -> [Int]
lastelems []     n | n > 1     = (lastelems [] (n-1)) ++ [0]
                   | otherwise = [0]
lastelems [x]    n | n > 1     = (lastelems [] (n-1)) ++ [x]
lastelems (x:xs) n | n > 1     = (lastelems (init (x:xs)) (n-1)) ++ [(last (x:xs))]
                   | otherwise = [(last (x:xs))]

shiftLeft :: [Int] -> [Int]
shiftLeft [x]    = [mod x 10]
shiftLeft (x:xs) | dx == 0   = shiftLeft (init (x:xs)) ++ [mx]
                 | otherwise = (shiftLeft (upd (init (x:xs)) dx)) ++ [mx]
                 where mx = mod (last (x:xs)) 10
                       dx = div (last (x:xs)) 10
                       upd :: [Int] -> Int -> [Int]
                       upd [x] n    = [x+n]
                       upd (x:xs) n = init (x:xs) ++ [(last (x:xs)+n)]

sumd :: [[Int]] -> [Int]
sumd [x]    = x
sumd (x:xs) = shiftLeft $ zipWith (+) x (sumd xs)

main = do
  let
    list' = [n^n | n <- [1..1000]]
    list'' = [lastelems (digs x) 10 | x <- list']
    answer = sumd list''
  print answer
