# %%

import pandas as pd


df = pd.read_csv("../data/clientes.csv", sep=";")
df
# %%

df["qtdePontos"].astype(float)
# %%

# %%
df = df.rename(columns={"DtCriacao" : "dtCriacao"})
# %%
df
# %%
df["dtCriacao"].replace({"2025-11-13 12:03:56.114":"2028-11-13 12:03:56.114"})

# %%
pd.to_datetime(df["dtCriacao"])
df["dtCriacao"].dt.month
# %%
