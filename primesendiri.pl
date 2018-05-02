isprime(2).
isprime(3).
isprime(P):-
    integer(P),
    P > 3,
    P mod 2 =\= 0,
    \+ has_factor(P,3).

has_factor(N,L) :- N mod L =:= 0.
has_factor(N,L) :-
    L * L < N,
    L2 is L + 2,
    has_factor(N,L2).
/*
generatePrime(X,Y,Z) :-
    between(X,Y,Z), isprime(Z).
*/

generate_prime(X,Y) :-
    forall(
        (between(X,Y,Z), isprime(Z)),
        ( write(Z), put_char(' '))).
