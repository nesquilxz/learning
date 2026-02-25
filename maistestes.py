# %%
# 03.01 - Quantas linhas há no arquivo clientes.csv ?
import pandas as pd

df_clientes = pd.read_csv("../../data/clientes.csv")
linhas = df_clientes.shape[0]

print(f"O arquivo de clientes.csv tem {linhas} linhas")


# %%
# 03.02 - Quantas colunas do tipo int há no arquivo transacoes.csv ?

df_transacoes = pd.read_csv("../../data/transacoes.csv")
df_transacoes.dtypes

print("O arquivo transacoes.csv tem uma coluna do tipo int (qtdePontos)")


# %%
# 03.03 - Quantas colunas do tipo object há no arquivo produtos.csv ?
df_produtos = pd.read_csv("../../data/produtos.csv")
df_produtos.dtypes

print("O arquivo produtos.csv tem 1 coluna do tipo object (descProduto)")

# %%
# 03.04 - Qual o id do cliente no índice 4 no arquivo clientes.csv ?

# df_clientes['idCliente'][4]
df_clientes.loc[4]["idCliente"]

# %%
# 03.05 - Qual o saldo de pontos do cliente na 10a posição (sem ordenar) do arquivo clientes.csv ?

df_clientes.iloc[9]["qtdePontos"]
