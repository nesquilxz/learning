# %%

# Obtenha a última linha de transacao de cada cliente
# Obtenha a primeira

import pandas as pd

df = pd.read_csv("../../data/transacoes.csv")
df.head()

# %%

# ultima
ultima_transacao = (df.sort_values(by="dtCriacao")
                      .drop_duplicates(subset=['idCliente'], keep='last'))

# %%
primeira_transacao = (df.sort_values(by="dtCriacao")
                        .drop_duplicates(subset=['idCliente'], keep='first'))
