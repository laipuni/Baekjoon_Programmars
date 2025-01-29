select WAREHOUSE_ID,
       WAREHOUSE_NAME,
       ADDRESS,
       IFNULL(FREEZER_YN,'N') as FREEZER_YN
from FOOD_WAREHOUSE as f
where f.address like "%경기도%"
order by WAREHOUSE_ID asc