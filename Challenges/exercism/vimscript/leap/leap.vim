"
" This function takes a year and returns 1 if it's a leap year
" and 0 otherwise.
"
function! IsLeap(n)
    return (a:n % 4 == 0) && ((a:n % 100 != 0) || (a:n % 400 == 0))
endfunction
