import numpy as np
from numba import njit, prange

@njit(parallel=True)
def media(valores):
    soma = 0.0

    for i in prange(len(valores)):
        soma += valores[i]

    return soma / len(valores)

@njit(parallel=True)
def covariancia(x, media_x, y, media_y):
    covar = 0.0

    for i in prange(len(x)):
        covar += (x[i] - media_x) * (y[i] - media_y)

    return covar

@njit(parallel=True)
def variancia(valores, media):
    soma = 0.0

    for i in prange(len(valores)):
        soma += (valores[i] - media) ** 2

    return soma

@njit
def coef_regressao_linear(x, y):
    x_media = media(x)
    y_media = media(y)

    b1 = covariancia(x, x_media, y, y_media) / variancia(x, x_media)
    b0 = y_media - b1 * x_media

    return b0, b1

x = np.array([1, 2, 3, 4, 5], dtype=np.float64)
y = np.array([2, 4, 6, 8, 10], dtype=np.float64)

b0, b1 = coef_regressao_linear(x, y)

print("b0:", b0)
print("b1:", b1)