import pandas as pd

# simulando dados de chamados de atendimento
dados_chamados = {
    "id_chamado": [101, 102, 103, 104, 105, 106, 107, 108],
    "area_responsavel": [
        "suporte", "financeiro", "suporte", "produto",
        "financeiro", "suporte", "produto", "suporte"
    ],
    "prioridade": [
        "alta", "media", "baixa", "alta",
        "media", "alta", "baixa", "media"
    ],
    "data_abertura": [
        "2025-01-01 08:30", "2025-01-02 10:15", "2025-01-03 14:00",
        "2025-01-04 09:20", "2025-01-05 11:45", "2025-01-06 16:10",
        "2025-01-07 13:00", "2025-01-08 10:40"
    ],
    "data_fechamento": [
        "2025-01-02 07:00", "2025-01-05 12:30", "2025-01-03 18:00",
        "2025-01-06 10:00", "2025-01-06 15:00", "2025-01-09 09:30",
        "2025-01-07 17:00", "2025-01-10 14:20"
    ]
}

# criando o dataframe
df = pd.DataFrame(dados_chamados)

# convertendo colunas de data para datetime
df["data_abertura"] = pd.to_datetime(df["data_abertura"])
df["data_fechamento"] = pd.to_datetime(df["data_fechamento"])

# calculando tempo de resolução em horas
df["tempo_resolucao_horas"] = (
    df["data_fechamento"] - df["data_abertura"]
).dt.total_seconds() / 3600

# definindo o sla da empresa (em horas)
sla_horas = 48

# verificando se o chamado estourou o sla
df["sla_estourado"] = df["tempo_resolucao_horas"] > sla_horas

print("base de chamados com tempo de resolução e sla:")
print(df)

# quantidade de chamados fora do sla
chamados_fora_sla = df["sla_estourado"].sum()

print("\nquantidade de chamados fora do sla:")
print(chamados_fora_sla)

# percentual de chamados fora do sla
percentual_fora_sla = (chamados_fora_sla / len(df)) * 100

print("\npercentual de chamados fora do sla:")
print(f"{percentual_fora_sla:.1f}%")

# tempo médio de resolução por área
tempo_medio_area = (
    df
    .groupby("area_responsavel")["tempo_resolucao_horas"]
    .mean()
    .reset_index()
    .sort_values(by="tempo_resolucao_horas", ascending=False)
)

print("\ntempo médio de resolução por área:")
print(tempo_medio_area)

# áreas com mais violações de sla
violacoes_por_area = (
    df
    .groupby("area_responsavel")["sla_estourado"]
    .sum()
    .reset_index()
    .sort_values(by="sla_estourado", ascending=False)
)

print("\nviolacoes de sla por area:")
print(violacoes_por_area)
