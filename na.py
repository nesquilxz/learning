# %%

import pandas as pd


clientes = pd.read_csv("../data/clientes.csv", sep=";")
clientes
# %%

clientes = clientes.dropna()
# %%
clientes
# %%

df = pd.DataFrame(
    
    {

    "nome": ["Téo", None, "Pedro", "Nah"],
    "idade": [None, None, 43, 52],
    "salario": [3453, 4324, None, 5423],


})

df
#%%

df["idade"] = df["idade"].fillna(0)
df


# %%


df.fillna()

df.dropna(how="all", subset=["nome"])
# %%
