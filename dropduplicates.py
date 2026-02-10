# %%

import pandas as pd

df = pd.DataFrame({

    "nome": ['teo', 'pedro', 'mah', 'lara', 'mah'],
    "sobrenome": ['calvo', 'henriques', 'lima', 'ataide', 'lima'],
    "salario":[4203, 7230, 4032, 2102, 1963]
})

df
# %%
df = df.drop_duplicates(subset=["nome", "sobrenome"])
df
# %%

df = df.sort_values(by=["salario"], ascending=False).head(5)
df



# %%
