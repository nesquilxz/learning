import pandas as pd
import numpy as np

# geracao de dados de clientes
n_clientes = 500

clientes = pd.DataFrame({
    "cliente_id": range(1, n_clientes + 1),
    "segmento": np.random.choice(
        ["small business", "mid market", "enterprise"],
        size=n_clientes,
        p=[0.5, 0.3, 0.2]
    ),
    "regiao": np.random.choice(
        ["sudeste", "sul", "nordeste", "centro-oeste", "norte"],
        size=n_clientes
    ),
    "data_aquisicao": pd.to_datetime("2021-01-01") +
                      pd.to_timedelta(
                          np.random.randint(0, 365 * 3, n_clientes),
                          unit="D"
                      )
})

# criacao da base de faturamento mensal
meses = pd.date_range("2023-01-01", "2024-12-01", freq="MS")

faturamento = (
    clientes[["cliente_id", "segmento"]]
    .assign(key=1)
    .merge(pd.DataFrame({"mes": meses, "key": 1}), on="key")
    .drop("key", axis=1)
)

base_receita = {
    "small business": 300,
    "mid market": 1200,
    "enterprise": 5000
}

faturamento["receita"] = faturamento["segmento"].map(base_receita)
faturamento["receita"] *= np.random.normal(1.0, 0.25, len(faturamento))
faturamento["receita"] = faturamento["receita"].clip(lower=50).round(2)

# simulacao de churn e status de cliente ativo
prob_churn = {
    "small business": 0.015,
    "mid market": 0.01,
    "enterprise": 0.005
}

faturamento["churn"] = (
    np.random.rand(len(faturamento)) <
    faturamento["segmento"].map(prob_churn)
)

faturamento["ativo"] = ~faturamento.groupby("cliente_id")["churn"].cumsum().astype(bool)
faturamento.loc[~faturamento["ativo"], "receita"] = 0

# calculo das metricas principais
metricas_mensais = (
    faturamento
    .groupby("mes")
    .agg(
        receita_total=("receita", "sum"),
        clientes_ativos=("ativo", "sum"),
        churns=("churn", "sum")
    )
    .reset_index()
)

metricas_mensais["arpu"] = (
    metricas_mensais["receita_total"] /
    metricas_mensais["clientes_ativos"]
)

metricas_mensais["crescimento_receita_%"] = (
    metricas_mensais["receita_total"]
    .pct_change()
    .fillna(0) * 100
)

# calculo de ltv medio por segmento
ltv = (
    faturamento
    .groupby(["cliente_id", "segmento"])["receita"]
    .sum()
    .reset_index()
    .groupby("segmento")["receita"]
    .mean()
    .reset_index(name="ltv_medio")
)

# ranking de clientes enterprise por receita
top_enterprise = (
    faturamento
    .merge(clientes[["cliente_id", "regiao"]], on="cliente_id")
    .query("segmento == 'enterprise'")
    .groupby(["cliente_id", "regiao"])["receita"]
    .sum()
    .reset_index()
    .sort_values("receita", ascending=False)
    .head(10)
)

print("\nmetricas mensais (ultimos 6 meses)")
print(metricas_mensais.tail(6))

print("\nltv medio por segmento")
print(ltv)

print("\ntop 10 clientes enterprise")
print(top_enterprise)
