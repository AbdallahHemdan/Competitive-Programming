// Powerful Method To Calc nCr
int nCr(int n, int r) {
 if (n < r)
 return 0;
 if (r == 0)
 return 1;
 return n * nCr(n - 1, r - 1) / r;
}
