
# [h, s, i]=[i/255.0 for i in ([h, s, i])];
# [h, s, i]=[i/255.0 for i in [h, s, i]];

h = np.array([[1, 2, 95, 55, 25],
    [1, 2, 3, 32, 25],
    [1, 2, 3, 55, 254]])

altura = len(h)
largura = len(h[0])

for idx_linha in range(altura): # para cada linha de h
    for idx_coluna in range(largura): # para cada coluna de h
        h[idx_linha][idx_coluna] /= 255.0
        print(h[idx_linha][idx_coluna])
#        s[idx_linha, idx_coluna] /= 255.0
#        i[idx_linha, idx_coluna] /= 255.0
