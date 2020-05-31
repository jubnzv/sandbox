#lang racket
(require racket/trace)
(require racket/fixnum)
(require rackunit rackunit/text-ui)

(define ast1.4 `(- 8))
(define ast1.1 `(+ (read) ,ast1.4))

;; {{{ Utilities
(define assert
  (lambda (msg b)
    (if (not b)
	(begin
	  (display "ERROR: ")
	  (display msg)
	  (newline))
	(void))))
;; }}}

;; {{{ 1.4
(define (exp? sexp)
  (match sexp
    [(? fixnum?) #t]
    [`(read) #t]
    [`(- ,e) (exp? e)]
    [`(+ ,e1 ,e2)
      (and (exp? e1) (exp? e2))]
    [else #f]))

(define (R0? sexp)
  (match sexp
    [`(program ,e) (exp? e)]
    [else #f]))

(R0? `(program (+ (read) (- 8)))) ;; #t
(R0? `(program (- (read) (+ 8)))) ;; #f
;; }}}

;; {{{ 1.5 Interpret exprs
(define (interp-exp e)
  (match e
    [(? fixnum?) e]
    [`(read)
      (let ([r (read)])
        (cond [(fixnum? r) r]
              [else (error `interp-R0 "input not an integer" r)]))]
    [`(- ,e) (fx- e)]
    [`(+ ,e1 ,e2) (fx+ (interp-exp e1) (interp-exp e2))]))

(define (interp-R0 p)
  (match p
    [`(program ,e) (interp-exp e)]))

(interp-exp `(+ 2 40))
(interp-exp `(- 2))
(interp-exp `(+ 4 (- 2)))
(interp-exp `(+ (- 2) 44))
;; }}}

;; {{{ 1.6 A partial evaluator
(define (pe-neg r)
  (cond [(fixnum? r) (fx- 0 r)]
        [else `(- ,r)]))

(define (pe-add r1 r2)
  (cond [(and (fixnum? r1) (fixnum? r2)) (fx+ r1 r2)]
        [else `(+ ,r1 ,r2)]))

(define (pe-arith e)
  (match e
    [(? fixnum?) e]
    [`(read) `(read)]
    [`(- ,e1)
      (pe-neg (pe-arith e1))]
    [`(+ ,e1 ,e2)
      (pe-add (pe-arith e1) (pe-arith e2))]))

(define (test-pe p)
  (assert "testing pe-arith"
    (equal? (interp-R0 p) (interp-R0 (pe-arith p)))))

;; {{{ test-pe doesn't work
(trace pe-arith)
(trace test-pe)
(pe-arith `(+ 1 2))
(interp-exp `(+ 1 2))
(equal? (pe-arith `(+ 1 2)) (interp-exp `(+ 1 2)))
(interp-exp (pe-arith `(+ 1 2)))
(+ (interp-exp (pe-arith `(+ 1 2))) (interp-exp `(+ 1 2)))
(let ([p `(+ 1 2)]) (equal? (interp-R0 p) (interp-R0 (pe-arith p))))
;; }}}

(test-pe `(1))
(test-pe `(+ (read) (- (+ 5 3))))
(test-pe `(+ 1 + (+ (read) 1)))
(test-pe `(+ 1 + (+ 2 1)))
(test-pe `(- (+ (read) (-5))))

;; {{{ Ex.1
;; {{{
;; Exercise 1. We challenge the reader to improve on the simple partial eval-
;; uator in Figure 1.3 by replacing the pe-neg and pe-add helper functions
;; with functions that know more about arithmetic. For example, your partial
;; evaluator should translate
;; (+ 1 (+ (read) 1))
;; into
;; (+ 2 (read))
;; }}}
(define (exp? sexp)
  (match sexp
    [`(read) #t]
    [`(- (read)) #t]
    [`(+ ,e1 ,e2) (and (exp? e1) (exp? e2))]
    [else #f]))

(define (res? sexp)
  (match sexp
    [(? fixnum?) #t]
    [`(+ ,i ,e) (fixnum? i)]
    [`(exp? ,e) #t]
    [else #f]))
(equal? (res? 1) #t)
(equal? (res? `(read)) #f)

(define (pe-neg r)
  (cond [(fixnum? r) (fx- 0 r)]
        [else `(- ,r)]))

; Non-working pe-add variant.
; It somewhat strange to modify this function, because we need to "see back",
; at parameter of previous expression. So, I implement it right in [pe-arith].
; (define (pe-add-ex r1 r2)
;   (cond [(and (fixnum? r1) (fixnum? r2)) (fx+ r1 r2)]
;         [(and (res? r1) (exp? r2)
;           (match r2
;            [`(+ ,e1 ,e2)
;               #:when (and (res? e2) (fixnum? e2) (fixnum? r1))
;              `(+ (fx+ r1 e2) e1)]
;            [else `(+ ,r1 ,r2)]))]
;         [else `(+ ,r1 ,r2)]))

(define (pe-add r1 r2)
  (cond [(and (fixnum? r1) (fixnum? r2)) (fx+ r1 r2)]
        [else `(+ ,r1 ,r2)]))

(define (pe-arith e)
  (match e
    [(? fixnum?) e]
    [`(read) `(read)]
    [`(- ,e1)
      (pe-neg (pe-arith e1))]
    [`(+ ,e1 ,e2)
      ; Can we reduce this expr?
      (cond [(fixnum? e1)
      (match e2
      ; Found '+' expression in expressions nested in [e2]
      [; Can be reduced
       `(+ ,es1 ,es2) #:when (fixnum? es2)
         (pe-add (pe-add e1 es2) (pe-arith es1))]
      [else ; Can't be reduced
       (pe-add (pe-arith e1) (pe-arith e2))])]
      [else ; e1 is not fixnum
       (pe-add (pe-arith e1) (pe-arith e2))])]))

(trace pe-add)
(trace pe-arith)
(trace exp?)
(trace res?)

(pe-arith `(+ 1 (+ (read) 1))) ; (+ 2 (read))
;; }}}
;; }}}

;; vim:fdm=marker:fen:sw=2:tw=120
