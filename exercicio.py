# %%

import pandas as pd
# %%

transacoes = pd.read_csv("../data/transacoes.csv", sep=";")
transacoes
# %%
transaoes = transacoes.sort_values(by=["DtCriacao"])
# %%

# ----primeira transição do usuario: primeiro, ordena o tempo de cada transação. Depois, crie uma nova coluna com apenas a data. Depois, só dropar pelo id e a data
transacoes["data"] = pd.to_datetime(transacoes["DtCriacao"]).dt.date # o .dt.date extrai data, sem hora
transacoes.drop_duplicates(keep="first", subset=["IdCliente", "data"])
# %%
transacoes

# %%
