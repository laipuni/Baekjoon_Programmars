select c.car_id,
       c.car_type,
       floor(c.daily_fee * 30 * (1-p.discount_rate/100)) as FEE
from CAR_RENTAL_COMPANY_CAR as c
left join CAR_RENTAL_COMPANY_RENTAL_HISTORY as h
on h.car_id = c.car_id and
   ('2022-11-01' BETWEEN h.START_DATE AND h.END_DATE OR 
    '2022-11-30' BETWEEN h.START_DATE AND h.END_DATE)
join CAR_RENTAL_COMPANY_DISCOUNT_PLAN as p
on p.car_type = c.car_type and p.duration_type = "30일 이상" and
   p.car_type in ("세단","SUV")
where c.car_type in ("세단","SUV") and h.history_id is null and
      floor(c.daily_fee * 30 * (1-p.discount_rate/100)) between 500000 and 1999999
order by FEE desc, c.car_type asc, c.car_id desc