# %%

import pandas as pd

transacoes = pd.read_csv("../data/transacoes.csv", sep=";")
transacoes.head()
# %%

transacoes = transacoes.rename(columns={"IdCliente" : "idCliente"})


# %%
transacoes.groupby(by=["idCliente"]).count()

# %%

transacoes.groupby(by=["idCliente"])[["IdTransacao"]].count()

# %%

#qtde_transacoes, total de pontos e pontos/transacoes

summary = (transacoes.groupby(by=["idCliente"], as_index=False).agg({"IdTransacao": ["count"],
                                                            "QtdePontos" : ["sum", "mean"]
                                                            
                                                            }))
summary
# %%

summary['QtdePontos']['mean']
# %%

summary.columns = ['idCliente', 'qtdeTransacao', 'totalPontos', 'avgPontos']
summary

# %%
