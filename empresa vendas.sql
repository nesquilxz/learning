-- cria a tabela de vendas
create table vendas (
    id_venda integer primary key,
    data_venda date,
    produto varchar(50),
    categoria varchar(50),
    quantidade integer,
    preco_unitario decimal(10,2),
    regiao varchar(30)
);

-- insere dados fictícios de vendas
insert into vendas values
(1, '2025-01-01', 'notebook', 'eletronicos', 2, 3500.00, 'sudeste'),
(2, '2025-01-02', 'mouse', 'eletronicos', 10, 80.00, 'sudeste'),
(3, '2025-01-03', 'cadeira', 'moveis', 3, 900.00, 'sul'),
(4, '2025-01-03', 'mesa', 'moveis', 1, 1500.00, 'sul'),
(5, '2025-01-04', 'teclado', 'eletronicos', 5, 200.00, 'nordeste'),
(6, '2025-01-05', 'monitor', 'eletronicos', 4, 1200.00, 'sudeste');

-- visualiza os dados brutos
select *
from vendas;

-- calcula o faturamento total
select
    sum(quantidade * preco_unitario) as faturamento_total
from vendas;

-- faturamento por categoria
select
    categoria,
    sum(quantidade * preco_unitario) as faturamento
from vendas
group by categoria
order by faturamento desc;

-- faturamento por regiao
select
    regiao,
    sum(quantidade * preco_unitario) as faturamento
from vendas
group by regiao;

-- faturamento diario
select
    data_venda,
    sum(quantidade * preco_unitario) as faturamento_diario
from vendas
group by data_venda
order by data_venda;

-- ranking de produtos por faturamento
select
    produto,
    sum(quantidade * preco_unitario) as faturamento
from vendas
group by produto
order by faturamento desc
limit 3;

-- participacao de cada venda no faturamento total
select
    id_venda,
    produto,
    quantidade * preco_unitario as faturamento,
    round(
        (quantidade * preco_unitario) /
        sum(quantidade * preco_unitario) over (),
        4
    ) as participacao
from vendas;
