#include "calculator.h"

double calculateFunction(double x, int n) {
    double y = 0.0;

    if (x < -5) {
        double sum = 0.0;

        for (int i = -6; i <= n; i++) {
            sum += (i + x);
        }

        y = 4 * x * sum - 9;
    } else {
        for (int i = 1; i <= n + 1; i++) {
            double p = 1.0;

            for (int j = 0; j <= n - 3; j++) {
                p *= (i - 2 * j) / (4 + x * x);
            }

            y += p;
        }
    }

    return y;
}