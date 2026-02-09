#%%

import pandas as pd

clientes = pd.read_csv("../data/clientes.csv", sep=";")

clientes["qtdePontos"].sort_values()
# %%

max_ponto = clientes["qtdePontos"].max()

filtro = clientes["qtdePontos"] == max_ponto

clientes[filtro]
# %%

clientes.sort_values(by="qtdePontos", ascending=False).head(5)

# %%
