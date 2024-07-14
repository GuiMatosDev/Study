# Tipo da Variável
algo = input('Digite algo: ')
print('Tipo primtivo da variável:', type(algo))

# Validações da Linguagem

print('Numerico?', algo.isnumeric())
print('Alphanumerico?', algo.isalnum())
print('Somente Letras?', algo.isalpha())
print('Somente Maisculas?', algo.isupper())
print('Somente Minusculas?', algo.islower())
print('Somente Espaços?', algo.isspace())
