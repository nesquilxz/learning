# %%

#para empilhar, utilizamos o concat!! (interessante)

import pandas as pd


df = pd.DataFrame({

    "cliente": [1,2,3,4,5],
    "nome": ["teo", "pedro", "jirachi", "luh", "mah"]

})


df_02 = pd.DataFrame({

    "cliente": [6, 7, 8],
    "nome": ["kozato", "laura", "dan"],
    "idade": [32, 29, 31],
})

df_02
# %%
df
# %%

pd.concat([df, df_02], ignore_index=True)
# %%

df_03 = pd.DataFrame({
    "idade": [32, 34, 19, 54, 33]
})


pd.concat([df, df_03], axis=1)
# %%

df_03 = df_03.sort_values(by="idade").reset_index(drop=True)
df_03

# %%
