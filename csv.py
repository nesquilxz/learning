#%%
import pandas as pd

#read csv retorna um df

df = pd.read_csv("../data/clientes.csv", sep=";")
df
# %%

#salvar diretorio
df.to_csv("clientes.csv", index=False, sep=";")

# %%
#para engenharia de dados (que utilizam parquet)

df.to_parquet("clientes.parquet", index=False)

# %%
df_2 = pd.read_parquet("clientes.parquet")
df_2
# %%

df.to_excel("clientes.xlsx", index=False)

# %%

df_3 = pd.read_excel("clientes.xlsx")
df_3
# %%
df_bobo = pd.read_csv("../data/bobo.csv", sep=";")
df_bobo
# %%
