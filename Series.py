# %%

media = sum(idades) / len(idades)
print("Media: ", media)


diffs = 0

for i in idades:
    diffs += (i-media) ** 2

varianca = diffs / (len(idades)-1)

print("Variância:", varianca)

# %%
# #nao vale a pena pois uma lista é uma estrutura muito basica do python


import pandas as pd


idades = [
    32, 38, 30, 30, 31,
    35, 25, 29, 31, 37,
    27, 23, 36, 33, 32,
] #permite tipos diferentes, mas nao tem métodos



seriesIdades = pd.Series(idades) 
#mesma coisa que uma lista vazia
#perimite tipos diferentes, mas converte.
seriesIdades


# %%
#Estatísticas da séries
mediaIdades = seriesIdades.mean()
var_idades = seriesIdades.var()
summaryIdades = seriesIdades.describe()
summaryIdades
# %%
