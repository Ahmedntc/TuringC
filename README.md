# Entrada de dados
```
abxy
5
11
1 a x D 2
1 y y D 4
1 - - D 5
2 a a D 2
2 y y D 2
2 b y E 3
3 a a E 3
3 y y E 3
3 x x D 1
4 y y D 4
4 - - D 5
4
aabb
aaabbb
abab
bbaa
```

# Exemplo de retorno

```
Alfabeto de entrada: abxy

Estado de aceitação: 5
Número de transições: 11
Matriz de Transições
1 a x D 2
1 y y D 4
1 - - D 5
2 a a D 2
2 y y D 2
2 b y E 3
3 a a E 3
3 y y E 3
3 x x D 1
4 y y D 4
4 - - D 5
Número de palavras a serem testadas: 4

Palavra 1: aabb


Transicoes feitas
1axD2
2aaD2
2byE3
3aaE3
3xxD1
1axD2
2yyD2
2byE3
3yyE3
3xxD1
1yyD4
4yyD4
4--D5
aabb
 OK

Palavra 2: aaabbb


Transicoes feitas
1axD2
2aaD2
2aaD2
2byE3
3aaE3
3aaE3
3xxD1
1axD2
2aaD2
2yyD2
2byE3
3yyE3
3aaE3
3xxD1
1axD2
2yyD2
2yyD2
2byE3
3yyE3
3yyE3
3xxD1
1yyD4
4yyD4
4yyD4
4--D5
aaabbb
 OK

Palavra 3: abab


Transicoes feitas
1axD2
2byE3
3xxD1
1yyD4
abab
 not OK

Palavra 4: bbaa

Transicoes feitas
bbaa not OK
```
