# Filtros de imagem

Este projeto visa construir filtros simples para imagens digitais em níveis de cinza, no formato PGM (P2 e P5) com pixels de 8 bits (1 byte).

## Filtro negativo

O filtro negativo consiste em converter cada pixel da imagem em seu complemento. Sendo max o valor máximo para um pixel na imagem, o complemento de um pixel com valor v seria max-v.

Forma de chamada:
```
pgmnega -i input -o output
```

Exemplo de entrada e de saída:

| ![Image 1](https://wiki.inf.ufpr.br/maziero/lib/exe/fetch.php?media=c:lena-original.png) | ![Image 2](https://wiki.inf.ufpr.br/maziero/lib/exe/fetch.php?media=c:lena-negative.png) |
|-------------------------|-------------------------|


## Filtro de rotação simples

O filtro de rotação gira uma imagem em 90° no sentido horário.

Forma de chamada:
```
pgmrotacao -i input -o output
```

Exemplo de entrada e de saída:

| ![Image 1](https://wiki.inf.ufpr.br/maziero/lib/exe/fetch.php?media=c:lena-original.png) | ![Image 2](https://wiki.inf.ufpr.br/maziero/lib/exe/fetch.php?media=c:lena-rotate.png) |
|-------------------------|-------------------------|

## Filtro de rotação livre

O filtro de rotação gira uma imagem em um ângulo θ (>0) no sentido horário, em relação ao seu centro (vide rotação de imagens 2D).

Requisitos:

- O tamanho da imagem de saída deve ser ajustado para não cortar os cantos da imagem.
- Os espaços vazios gerados pela rotação devem ser preenchidas com a cor branca.
- O ângulo de rotação é informado pela opção -a; se não for informado, por default θ = 90º.
Forma de chamada:
```
pgmrotacao -a N -i input -o output
```

Exemplo de entrada e de saída para θ = 30º:

| ![Image 1](https://wiki.inf.ufpr.br/maziero/lib/exe/fetch.php?media=c:lena-original.png) | ![Image 2](https://wiki.inf.ufpr.br/maziero/lib/exe/fetch.php?media=c:lena-rotate-30.png) |
|-------------------------|-------------------------|

## Filtro de limiar

O filtro de limiar (threshold filter) converte uma imagem em tons de cinza em um imagem em preto-e-branco (2 cores). A forma mais simples de fazer isso é comparar o valor de cada pixel com um limiar pré-definido: se o valor do pixel for igual ou superior ao limiar, ele vira branco (v=max), caso contrário ele vira preto (v=0).

Forma de chamada:
```
pgmlimiar -l N -i input -o output
```

onde N é um limiar real entre 0.0 (0% do valor máximo) e 1.0 (100% do valor máximo). Caso o limiar não esteja definido, assume-se que seja 50%.

Exemplo de entrada e de saídas com limiar de 50% e 75%:

| ![Image 1](https://wiki.inf.ufpr.br/maziero/lib/exe/fetch.php?media=c:lena-original.png) | ![Image 2](https://wiki.inf.ufpr.br/maziero/lib/exe/fetch.php?w=200&tok=32f0f6&media=c:lena-threshold-50.png) | ![Image 3](https://wiki.inf.ufpr.br/maziero/lib/exe/fetch.php?w=200&tok=32f0f6&media=c:lena-threshold-50.png) |
|-------------------------|-------------------------|

## Filtro de redução de ruído pela média

O filtro da média é usado para para “limpar” uma imagem, ou seja, reduzir o seu nível de ruído. O algoritmo é básico bem simples: para cada pixel, seu valor deve ser substituído pela média de todos os 9 pixels vizinhos (incluindo ele mesmo).

Deve ser tomado cuidado especial ao tratar os pixels nas primeiras e últimas linhas ou colunas, pois eles não têm todos os vizinhos. Nesses casos, devem ser considerados no cálculo somente os vizinhos existentes.

Forma de chamada:
```
pgmmedia -i input -o output
```

Exemplo de entrada e de saída:

| ![Image 1](https://wiki.inf.ufpr.br/maziero/lib/exe/fetch.php?media=c:ballons-original.png) | ![Image 2](https://wiki.inf.ufpr.br/maziero/lib/exe/fetch.php?media=c:ballons-average.png) |
|-------------------------|-------------------------|

## Filtro da mediana
O filtro da mediana reduz o nível de ruído de uma imagem sem prejudicar muito sua nitidez. Este filtro consiste basicamente em substituir o valor de um pixel pelo valor da mediana de seus pixels vizinhos. O número de vizinhos a considerar é definido por uma máscara, ou seja, a matriz de vizinhos que circunda o pixel a tratar (incluindo ele mesmo):

![Image](https://wiki.inf.ufpr.br/maziero/lib/exe/fetch.php?w=300&tok=4a827b&media=c:mascaras.png)

Requisitos:

- O tamanho da máscara é um inteiro positivo ímpar, que pode ser informado na linha de comando (opção -m); caso não seja informado, o valor default é 3, para uma máscara de 3×3 pixels.
- Os pixels nas bordas da imagem não têm todos os vizinhos e portanto não devem ser filtrados.
- Para ordenar os valores dos pixels deve ser usada a função qsort da biblioteca C (man qsort).

Forma de chamada:
```
pgmmediana -m N -i input -o output
```

Exemplo de entrada e de saída:

| ![Image 1](https://wiki.inf.ufpr.br/maziero/lib/exe/fetch.php?media=c:ballons-original.png) | ![Image 2](https://wiki.inf.ufpr.br/maziero/lib/exe/fetch.php?media=c:ballons-median.png) |
|-------------------------|-------------------------|

