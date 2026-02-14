# %%

import pandas as pd

df_geral = pd.read_csv("../data/ipea/homicidios.csv", sep=";")

df_geral = df_geral.rename(columns={"valor":"homicidios"})

df_geral.head()
# %%
df_negros = pd.read_csv("../data/ipea/homicidios-negros.csv", sep=";")


# %%
df_negros.head()
# %%

df_negros = df_negros.rename(columns={"valor":"homicidios-negros"})
df_negros.head()
# %%


#percebeu como nós estamos repetindo sempre a mesma coisa pra cada csv? vamos criar uma função e testar isto

import pandas as pd
import os


def read_file(file_name:str):

 df = (pd.read_csv(f"../data/ipea/{file_name}.csv", sep=";")
            .rename(columns={"valor":file_name})
            .set_index(["nome", "período"]))
 
 return df
 
#%%


files_names = os.listdir("../data/ipea")

dfs = []

for i in files_names:
 file_name = i.split(".")[0]
 dfs.append(read_file(file_name))

#coisa linda.



#%%

pd.concat(dfs, axis=1)

# %%
