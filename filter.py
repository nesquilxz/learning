#%%
import pandas as pd

df = pd.read_csv("../data/transacoes.csv", sep=";")
df.head()
# %%
df = df.rename(columns={"QtdePontos" : "QtdPontos"})
# %%
pontos =[10, 20, 30, 40, 50, 60, 70, 30, 60, 30, 50, 40]
filtro = []

for i in pontos:
    filtro.append(i>=50)

resultado = []
for i in range(len(pontos)):
    if filtro[i]:
        resultado.append(pontos[i])

resultado
# %%

brinquedo = pd.DataFrame( {

    "nome": ["teo", "pedro", "nah"],
    "idade": [32, 19, 14],
    "uf": ["sp", "rj", "mg"],

})

filtro =brinquedo["idade"] >= 18
filtro
# %%
filtro.tolist()

#%%
brinquedo[filtro]

# %%


df = pd.read_csv("../data/transacoes.csv", sep=";")
df.head()
df = df.rename(columns={"QtdePontos" : "QtdPontos"})

#%%
df
# %%

filtro = df["QtdPontos"] >= 50

df[filtro]
# %%
# filtro que tenha mais de uma condição logica
# AND

filtro = (df["QtdPontos"] >= 50) & (df["QtdPontos"] <= 100)
filtro
# %%
df[filtro]
# %%

filtro = (df["QtdPontos"] >= 50) | (df["QtdPontos"] <= 100)
filtro
# %%
df[filtro]
# %%

