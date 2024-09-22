SELECT * 
from CAR_RENTAL_COMPANY_CAR as c
where c.options like "%네비게이션%"
order by car_id desc