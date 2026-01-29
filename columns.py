#%%

import pandas as pd

df = pd.read_csv("../data/transacoes.csv")
df


# %%
#da rename com dicionario

df = df.rename(columns={"QtdePontos" : "qtPontos"})
# %%

df
# %%
#ler uma coluna de um dataframe (retorna uma série)

df[["idCliente", "qtPontos"]].iloc[1]# dataframe
# %%
df[["idCliente"]] #ver em dataframe.
# %%

df["idCliente"] # serie

# %%

# =============================
#        semelhanças com o SQL
# =============================

#%%

# SELECT * FROM df
df

# %%

#SELECT idCliente FROM df

df[["idCliente"]]
# %%

#SELECT idCliente, qtPontos FROM df LIMIT 5

df[["idCliente", "qtPontos"]].head(5)

#SELECT idCliente, qtPontos, idTransacao FROM df LIMIT 5

df[["idCliente", "idTransacao", "qtPontos"]].head(5)

#%%

#ordenamento

colunas = df.columns.tolist()
colunas.sort()
colunas

df = df[colunas]
df
