SELECT p.product_id
      ,p.product_name
      ,sum(p.price * o.amount) as TOTAL_SALES
from food_product as p
join food_order as o
on o.product_id = p.product_id and o.produce_date like "2022-05%"
group by p.product_id
order by sum(p.price * o.amount) desc, p.product_id asc