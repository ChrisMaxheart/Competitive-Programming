/*
case k = 2 -> if n = 2^m + k and 0 <= k < 2^m, then f(n) =
2k+1
general case (0-based) -> f(n, k) = (f(n - 1, k) + k) mod n,
f(1, k) = 0
*/
