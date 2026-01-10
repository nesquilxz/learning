-- cria a tabela de batalhas do universo bleach
create table batalhas_bleach (
    id_batalha integer primary key,
    data_batalha date,
    personagem varchar(50),
    faccao varchar(30),
    inimigo varchar(50),
    resultado varchar(20),
    nivel_poder integer,
    local_batalha varchar(50)
);

-- insere dados fictícios de batalhas
insert into batalhas_bleach values
(1, '2025-01-01', 'ichigo', 'shinigami', 'byakuya', 'vitoria', 85, 'seireitei'),
(2, '2025-01-02', 'rukia', 'shinigami', 'aaroniero', 'vitoria', 70, 'las noches'),
(3, '2025-01-03', 'renji', 'shinigami', 'szayel', 'derrota', 68, 'las noches'),
(4, '2025-01-03', 'ichigo', 'shinigami', 'ulquiorra', 'vitoria', 95, 'hueco mundo'),
(5, '2025-01-04', 'aizen', 'arrancar', 'gotei 13', 'vitoria', 100, 'karakura'),
(6, '2025-01-05', 'kenpachi', 'shinigami', 'nnoitra', 'vitoria', 92, 'hueco mundo'),
(7, '2025-01-06', 'uryu', 'quincy', 'mayuri', 'derrota', 65, 'seireitei');

-- visualiza todas as batalhas
select *
from batalhas_bleach;

-- total de batalhas registradas
select
    count(*) as total_batalhas
from batalhas_bleach;

-- taxa de vitoria por faccao
select
    faccao,
    count(*) as batalhas,
    sum(case when resultado = 'vitoria' then 1 else 0 end) as vitorias,
    round(
        sum(case when resultado = 'vitoria' then 1 else 0 end) * 1.0 /
        count(*),
        2
    ) as taxa_vitoria
from batalhas_bleach
group by faccao;

-- nivel medio de poder por personagem
select
    personagem,
    avg(nivel_poder) as poder_medio
from batalhas_bleach
group by personagem
order by poder_medio desc;

-- batalhas ocorridas em hueco mundo
select
    personagem,
    inimigo,
    resultado,
    nivel_poder
from batalhas_bleach
where local_batalha = 'hueco mundo';

-- ranking das batalhas com maior nivel de poder
select
    personagem,
    inimigo,
    nivel_poder
from batalhas_bleach
order by nivel_poder desc
limit 5;

-- participacao de cada batalha no total de poder registrado
select
    id_batalha,
    personagem,
    nivel_poder,
    round(
        nivel_poder * 1.0 /
        sum(nivel_poder) over (),
        4
    ) as participacao_poder
from batalhas_bleach;
