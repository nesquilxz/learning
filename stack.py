# %%

import pandas as pd

df = pd.read_csv("homicidios_consolidado.csv", sep=";")
df.head()

# %%

df_stack = (df.set_index(["nome", "período"])
              .stack())
df_stack = df_stack.reset_index()
df_stack.columns = ["nome", "período", "metrica", "valor"]
df_stack

# %%

df_unstack = (df_stack.set_index(["nome", "período", "metrica"])
                      .unstack()
                      .reset_index())

df_unstack
# %%

df_unstack.columns.droplevel(0).tolist()[2:]

# %%

metricas = df_unstack.columns.droplevel(0)[2:].tolist()
df_unstack.columns = ['nome', 'período'] + metricas
df_unstack
