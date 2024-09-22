SELECT p.CATEGORY,
       m.max_price as MAX_PRICE,
       p.PRODUCT_NAME
from FOOD_PRODUCT as p
join
(
    select max(price) as max_price,
           CATEGORY
    from FOOD_PRODUCT
    where CATEGORY in ('과자','국','김치','식용유')
    group by CATEGORY
) as m
on p.category = m.category and p.price = m.max_price
order by m.max_price desc