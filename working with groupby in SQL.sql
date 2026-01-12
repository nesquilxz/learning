create table vendas (
    id integer primary key,
    produto text,
    categoria text,
    preco numeric(10,2),
    quantidade integer,
    data_venda date
);

insert into vendas values
(1, 'camiseta', 'roupa', 50.00, 2, '2025-01-01'),
(2, 'calça', 'roupa', 120.00, 1, '2025-01-01'),
(3, 'tênis', 'calçado', 300.00, 1, '2025-01-02'),
(4, 'camiseta', 'roupa', 50.00, 3, '2025-01-02'),
(5, 'tênis', 'calçado', 300.00, 2, '2025-01-03');

select
    sum(preco * quantidade) as faturamento_total
from vendas;

select
    categoria,
    sum(preco * quantidade) as faturamento
from vendas
group by categoria;

select
    produto,
    sum(quantidade) as total_vendido
from vendas
group by produto
order by total_vendido desc
limit 1;

select
    data_venda,
    sum(preco * quantidade) as faturamento_dia
from vendas
group by data_venda
order by data_venda;
