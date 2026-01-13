create table clientes (
    id_cliente integer primary key,
    nome text,
    cidade text,
    estado text,
    data_cadastro date
);

create table produtos (
    id_produto integer primary key,
    nome_produto text,
    categoria text,
    preco numeric(10,2)
);

create table vendas (
    id_venda integer primary key,
    id_cliente integer,
    id_produto integer,
    quantidade integer,
    data_venda date,
    foreign key (id_cliente) references clientes(id_cliente),
    foreign key (id_produto) references produtos(id_produto)
);

insert into clientes values
(1, 'ana', 'são paulo', 'sp', '2023-01-10'),
(2, 'bruno', 'rio de janeiro', 'rj', '2023-02-05'),
(3, 'carla', 'belo horizonte', 'mg', '2023-03-20'),
(4, 'daniel', 'são paulo', 'sp', '2023-04-01');

insert into produtos values
(1, 'camiseta', 'roupas', 50.00),
(2, 'calça', 'roupas', 120.00),
(3, 'tênis', 'calçados', 300.00),
(4, 'mochila', 'acessórios', 180.00);

insert into vendas values
(1, 1, 1, 2, '2024-01-05'),
(2, 1, 3, 1, '2024-01-10'),
(3, 2, 2, 1, '2024-01-15'),
(4, 3, 4, 2, '2024-02-01'),
(5, 4, 3, 1, '2024-02-10'),
(6, 2, 1, 3, '2024-02-15');

select
    sum(v.quantidade * p.preco) as faturamento_total
from vendas v
join produtos p on v.id_produto = p.id_produto;

select
    p.categoria,
    sum(v.quantidade * p.preco) as faturamento_categoria
from vendas v
join produtos p on v.id_produto = p.id_produto
group by p.categoria
order by faturamento_categoria desc;

select
    c.nome,
    sum(v.quantidade * p.preco) as total_gasto
from vendas v
join clientes c on v.id_cliente = c.id_cliente
join produtos p on v.id_produto = p.id_produto
group by c.nome
order by total_gasto desc;

select
    c.nome,
    avg(v.quantidade * p.preco) as ticket_medio
from vendas v
join clientes c on v.id_cliente = c.id_cliente
join produtos p on v.id_produto = p.id_produto
group by c.nome;

select
    strftime('%Y-%m', v.data_venda) as mes,
    sum(v.quantidade * p.preco) as faturamento_mensal
from vendas v
join produtos p on v.id_produto = p.id_produto
group by mes
order by mes;

select
    p.nome_produto,
    sum(v.quantidade) as total_vendido
from vendas v
join produtos p on v.id_produto = p.id_produto
group by p.nome_produto
order by total_vendido desc;
