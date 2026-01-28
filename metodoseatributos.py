#%%

import pandas as pd

df_clientes = pd.read_csv("../data/clientes.csv", sep=";")
df_clientes
# %%
#10 primeiros

df_clientes.head(10)
# %%
#5 ultimos
df_clientes.tail(5)

# %%
#sortido

df_clientes.sample(10)


df_clientes.info(memory_usage='deep')
# %%

df_clientes.dtypes
# é serie! da pra usar indice

# %%
