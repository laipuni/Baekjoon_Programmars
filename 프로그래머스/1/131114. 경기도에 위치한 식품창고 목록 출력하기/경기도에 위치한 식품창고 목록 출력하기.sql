SELECT WAREHOUSE_ID,
       WAREHOUSE_NAME,	
       ADDRESS,	
       IFNULL(FREEZER_YN,'N') as FREEZER_YN
from food_warehouse 
where warehouse_name like "창고_경기%"
order by warehouse_id