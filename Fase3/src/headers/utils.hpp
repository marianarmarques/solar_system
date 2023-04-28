#ifndef UTILS_HPP
#define UTILS_HPP

class utils {
    public:
        static void multMatrixVector(float *m, float *v, float* res) {
            for (int j = 0; j < 4; ++j) {
                res[j] = 0;
                for (int k = 0; k < 4; ++k) {
                    res[j] += v[k] * m[j * 4 + k];
                }
            }
        }

        static void multVectorMatrix(float *v, float *m, float* res) {
            for (int j = 0; j < 4; j++) {
                res[j] = 0;
                for (int k = 0; k < 4; k++) {
                    res[j] += v[k] * m[k * 4 + j];
                }
            }
        }

        static float multVectors(float *v1, float *v2) {
            float res = 0;
            for (int j = 0; j < 4; j++) {
                res += v1[j] * v2[j];
            }
            return res;
        }
};

#endif