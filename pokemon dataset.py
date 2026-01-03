import pandas as pd

# criando manualmente um pequeno dataset de pokemon
# isso simula dados que poderiam vir de uma api ou banco
data = {
    "name": [
        "Pikachu", "Charizard", "Blastoise", "Venusaur",
        "Mewtwo", "Gyarados", "Dragonite", "Gengar",
        "Snorlax", "Lucario"
    ],
    "type_1": [
        "Electric", "Fire", "Water", "Grass",
        "Psychic", "Water", "Dragon", "Ghost",
        "Normal", "Fighting"
    ],
    "hp": [35, 78, 79, 80, 106, 95, 91, 60, 160, 70],
    "attack": [55, 84, 83, 82, 110, 125, 134, 65, 110, 110],
    "defense": [40, 78, 100, 83, 90, 79, 95, 60, 65, 70],
    "sp_atk": [50, 109, 85, 100, 154, 60, 100, 130, 65, 115],
    "sp_def": [50, 85, 105, 100, 90, 100, 100, 75, 110, 70],
    "speed": [90, 100, 78, 80, 130, 81, 80, 110, 30, 90],
    "generation": [1, 1, 1, 1, 1, 1, 1, 1, 1, 4],
    "legendary": [False, False, False, False, True, False, False, False, False, False]
}

df = pd.DataFrame(data)

# calculando o total de status de cada pokemon
df["total"] = df[
    ["hp", "attack", "defense", "sp_atk", "sp_def", "speed"]
].sum(axis=1)

# criando métricas mais interpretáveis
df["ataque_total"] = df["attack"] + df["sp_atk"]
df["defesa_total"] = df["defense"] + df["sp_def"]

# bulk costuma ser usado para medir o quão tank um pokemon é
df["bulk"] = df["hp"] + df["defesa_total"]

# ordenando os pokemon do mais forte para o mais fraco
ranking_forca = df.sort_values("total", ascending=False)

# analisando a força média por tipo primário
forca_por_tipo = (
    df.groupby("type_1")["total"]
      .mean()
      .sort_values(ascending=False)
)

# comparando estatísticas médias entre lendários e não lendários
comparacao_lendarios = (
    df.groupby("legendary")[["total", "attack", "defense", "speed"]]
      .mean()
)

# olhando se alguma geração tende a ser mais forte que outra
forca_por_geracao = (
    df.groupby("generation")["total"]
      .mean()
)

# correlação simples entre atributos para ver relações básicas
correlacao = df[
    ["hp", "attack", "defense", "sp_atk", "sp_def", "speed", "total"]
].corr()

print("ranking geral de força")
print(ranking_forca[["name", "type_1", "total", "legendary"]])

print("\nforça média por tipo")
print(forca_por_tipo)

print("\ncomparação entre lendários e não lendários")
print(comparacao_lendarios)

print("\nforça média por geração")
print(forca_por_geracao)

print("\ncorrelação entre atributos")
print(correlacao)
