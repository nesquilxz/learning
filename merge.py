# %%

import pandas as pd

transacoes = pd.read_csv("../data/transacoes.csv", sep=";")
transacoes.head()
# %%

# as pessoas que tem vinculo com email tem mais ou menos transacoes?

clientes = pd.read_csv("../data/clientes.csv", sep=";")
clientes.head()
# %%

transacoes.merge(right=clientes, how="left", on=["idCliente"]).head(5)
# %%


transacoes.head(5)
# %%
clientes.head(5)
# %%

transacoes = transacoes.rename(columns={"IdCliente" : "idCliente"})
# %%

import pandas as pd


df_1 = pd.DataFrame({
    "transacao": [1, 2, 3, 4, 5],
    "idCliente": [1, 2, 3, 2, 2],
    "valor": [10, 45, 32, 17, 87],
})


df_2 = pd.DataFrame({
    "id": [1, 2, 3, 4],
    "nome": ["teo", "nah", "mah", "jose"],
})


df_resultado = df_1.merge(df_2, left_on=["idCliente"], right_on=["id"], how='left')


print(df_resultado)
# %%

transacoes.merge(clientes, left_on=["IdCliente"], right_on=["idCliente"], how='left')


# PAREI !!! 27:55 MERGE

# %%
