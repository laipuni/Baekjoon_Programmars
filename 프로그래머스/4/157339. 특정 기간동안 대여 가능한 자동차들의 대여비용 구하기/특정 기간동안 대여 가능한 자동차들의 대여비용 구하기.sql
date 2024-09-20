SELECT c.car_id
      ,c.car_type
      ,floor(c.daily_fee * 30 * (1 - p.DISCOUNT_RATE/100)) as FEE
from CAR_RENTAL_COMPANY_CAR as c
join CAR_RENTAL_COMPANY_DISCOUNT_PLAN as p 
on c.car_type = p.car_type and                                               
   p.DURATION_TYPE = "30일 이상"
left join CAR_RENTAL_COMPANY_RENTAL_HISTORY as h 
on  c.car_id = h.car_id and 
   ('2022-11-01' BETWEEN h.START_DATE AND h.END_DATE OR 
    '2022-11-30' BETWEEN h.START_DATE AND h.END_DATE)
where c.car_type in ('세단','SUV') and
      floor(c.daily_fee * 30 * (1 - p.DISCOUNT_RATE/100)) between 500000 and 1999999 and
      h.car_id is null
order by FEE desc,c.car_type,c.car_id desc