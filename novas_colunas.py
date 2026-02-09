# %%

import pandas as pd
import numpy as np

# ======== numpy utilizamos para operações matemáticas =========

df = pd.read_csv("../data/clientes.csv", sep=";")
df
# %%
filtro = df["qtdePontos"] + 100

df["pontos_100"] = filtro
# %%
df
# %%

df["EmailTwitch"] = df["flEmail"] + df["flTwitch"] 
df.head(30)
# %%

df["qntdSocial"]   = df["flEmail"]	+df["flTwitch"]+	df["flYouTube"]+	df["flBlueSky"]+	df["flInstagram"]
df
# %%

df["logPontos"] = np.log(df["qtdePontos"] +1)

df["logPontos"].describe()
# %%
import matplotlib.pyplot as plt

plt.hist(df["EmailTwitch"])
plt.grid(True)
plt.show()
# %%
