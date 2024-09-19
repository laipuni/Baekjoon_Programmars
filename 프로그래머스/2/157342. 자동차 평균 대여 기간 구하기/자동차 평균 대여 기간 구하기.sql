SELECT car_id
      ,round(avg(datediff(end_date,start_date) + 1),1) as AVERAGE_DURATION
from CAR_RENTAL_COMPANY_RENTAL_HISTORY as c
group by car_id
having round(avg(datediff(end_date,start_date) + 1),1) >= 7
order by round(avg(datediff(end_date,start_date) + 1),1) desc, car_id desc