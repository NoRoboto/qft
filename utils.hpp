double iterative_pow(double x, int n) {
    double r = 1.0;

    while(n > 0) {
        r *= x;
        --n;
    }

    return r;
}