import pandas as pd

# lendo os dados
df = pd.read_csv("vendas.csv")

# visão geral
print(df.head())
print(df.info())

# removendo linhas sem valor de venda
df = df.dropna(subset=["valor_venda"])

# garantindo tipo numérico
df["valor_venda"] = pd.to_numeric(df["valor_venda"], errors="coerce")

# removendo vendas inválidas
df = df[df["valor_venda"] > 0]

# faturamento total
faturamento_total = df["valor_venda"].sum()
print("faturamento total:", faturamento_total)

# faturamento por categoria
faturamento_categoria = (
    df.groupby("categoria")["valor_venda"]
      .sum()
      .sort_values(ascending=False)
)

print("\nfaturamento por categoria:")
print(faturamento_categoria)

# ticket médio por cliente
ticket_medio_cliente = (
    df.groupby("cliente_id")["valor_venda"]
      .mean()
      .sort_values(ascending=False)
)

print("\nticket médio por cliente:")
print(ticket_medio_cliente.head())

# vendas por mês
df["data"] = pd.to_datetime(df["data"])
vendas_mes = (
    df.groupby(df["data"].dt.to_period("M"))["valor_venda"]
      .sum()
)

print("\nvendas por mês:")
print(vendas_mes)
