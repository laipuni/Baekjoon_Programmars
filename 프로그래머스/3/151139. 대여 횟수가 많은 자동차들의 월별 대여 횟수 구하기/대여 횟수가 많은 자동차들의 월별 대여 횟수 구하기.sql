with t (car_id) as (
    SELECT car_id
    from CAR_RENTAL_COMPANY_RENTAL_HISTORY 
    where date_format(start_date,"%Y-%m") between "2022-08" and "2022-10"
    group by car_id
    having count(*) >= 5
    order by car_id
)
select month(start_date)
      ,t.car_id
      ,count(*)
from CAR_RENTAL_COMPANY_RENTAL_HISTORY as c
join t
on t.car_id = c.car_id
where date_format(start_date,"%Y-%m") between "2022-08" and "2022-10"
group by month(start_date),car_id
order by month(start_date),car_id desc