import pandas as pd
import numpy as np

# criando dados simulados da empresa de consultoria medica

dados = {
    "consultor": np.random.choice(
        ["Ana", "Bruno", "Carla", "Daniel", "Eduarda"], 200
    ),
    "tipo_servico": np.random.choice(
        ["consultoria_clinica", "auditoria_hospitalar", "gestao_em_saude"], 200
    ),
    "horas_trabalhadas": np.random.randint(2, 10, 200),
    "valor_hora": np.random.choice([180, 220, 250, 300], 200),
    "custo_operacional": np.random.randint(150, 600, 200),
    "satisfacao_cliente": np.random.randint(6, 10, 200)
}

df = pd.DataFrame(dados)

# calculando metricas financeiras

df["faturamento"] = df["horas_trabalhadas"] * df["valor_hora"]
df["lucro"] = df["faturamento"] - df["custo_operacional"]
df["margem_lucro"] = df["lucro"] / df["faturamento"]

# analise de desempenho por tipo de servico

analise_servico = (
    df.groupby("tipo_servico")
    .agg(
        faturamento_total=("faturamento", "sum"),
        lucro_total=("lucro", "sum"),
        margem_media=("margem_lucro", "mean"),
        satisfacao_media=("satisfacao_cliente", "mean")
    )
    .sort_values("lucro_total", ascending=False)
)

# analise de desempenho por consultor

analise_consultor = (
    df.groupby("consultor")
    .agg(
        projetos=("consultor", "count"),
        faturamento_total=("faturamento", "sum"),
        lucro_total=("lucro", "sum"),
        satisfacao_media=("satisfacao_cliente", "mean")
    )
    .sort_values("lucro_total", ascending=False)
)

# construindo kpis executivos

kpis = {
    "faturamento_total": df["faturamento"].sum(),
    "lucro_total": df["lucro"].sum(),
    "margem_media": df["margem_lucro"].mean(),
    "satisfacao_media_geral": df["satisfacao_cliente"].mean()
}

df_kpis = pd.DataFrame.from_dict(
    kpis, orient="index", columns=["valor"]
)

# exibindo resultados

print("analise por tipo de servico")
print(analise_servico)

print("\nanalise por consultor")
print(analise_consultor)

print("\nkpis executivos")
print(df_kpis)

print("\ninsights principais")
print(f"servico mais lucrativo: {analise_servico.index[0]}")
print(f"consultor com maior lucro: {analise_consultor.index[0]}")
