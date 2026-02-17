# %%
import pandas as pd

#como criar uma conexao do python com um banco de dados? com o sql
# %%
import sqlalchemy

engine = sqlalchemy.create_engine("sqlite:///../data/olist.db")


#%%

clientes = pd.read_sql_table(table_name="tb_customers", con=engine)
# %%
clientes
# %%

#podemos passar uma query!

query = "SELECT * FROM tb_customers LIMIT 100"

df_100 = pd.read_sql_query(query, con=engine)
df_100
# %%
