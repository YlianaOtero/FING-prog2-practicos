// Implemente un algoritmo recursivo que evalúe un polinomio usando la regla de Horner: P(x) = a0 + x(a1 + x(a2 + · · · + (xan) · · · ))).
// PB) n = 0
// P[0] = a0 · · ·  P[n] = an
typedef unsigned int uint;
float horner(float * p, uint n, float x) {
    return hornerRec(p, 0, n, x);
}
float hornerRec(float * p, uint i, uint n, float x) {
    float res;
    if (n = 1) res = p[i];
    else res = p[i] + x*hornerRec(p, i+1, 0, x); //por el x*hornerRec en vez de solo hornerRec, no es recursion de cola
    return res;
};
