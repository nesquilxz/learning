# %%

import pandas as pd
import numpy as np

transacoes = pd.read_csv("../data/transacoes.csv", sep=";")
transacoes.head()
# %%

def diff_amp(x:pd.Series):
    amplitude = x.max() - x.min()
    media = x.mean()
    return np.sqrt((amplitude-media)**2)


def life_time(x:pd.Series):
    dt = pd.to_datetime(x)
    avg = (dt.max() - dt.min()).days
    return avg



idades = pd.Series([21, 32, 10 ,23, 40 ,20 ,23, 14, 18, 19, 42, 34, 25])

diff_amp(idades)


# %%

summary = transacoes.groupby(by=["IdCliente"], as_index=False).agg({

    "IdTransacao" : ["count"],
    "QtdePontos" :  ["sum", "mean", diff_amp],
    "DtCriacao" :    [life_time],


})
# %%

summary.columns = [
    "idCliente",
    "qtdeTransacoes",
    "totalPontos",
    "mediaPontos",
    "amplitude",
    "lifeTime",
]

summary
# %%
