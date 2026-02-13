# %%
import pandas as pd

idades = [16, 19, 20, 12, 20, 50, 40, 43, 43 ,46, 23, 34, 25, 27, 64, 43, 19, 22, 12, 46]

idades = pd.Series(idades)
idades



# %%

#agregação/sumarização : "expremer dados"

idades.sum()

#%%

idades.min()

#%%

idades.max()

#%%
idades.mean()

#%%

# %%
idades.describe()

# %%


clientes = pd.read_csv("../data/clientes.csv", sep=";")
clientes
# %%

clientes["flTwitch"].sum()



# %%

redesSociais = ["flEmail",	"flTwitch",	"flYouTube",	"flBlueSky",	"flInstagram"]

clientes[redesSociais].mean()
# %%


filtro = clientes.dtypes == "object"

#obter as colunas do tipo numerico
num_coluns = clientes.dtypes[~filtro].index.to_list()

# %%

clientes[num_coluns].mean()
# %%
