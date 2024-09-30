SELECT year(o.sales_date) as YEAR,
       month(o.sales_date) as MONTH,
       GENDER,
       count(distinct (i.user_id)) as USERS
from USER_INFO as i
join ONLINE_SALE as o
on i.user_id = o.user_id
where i.GENDER is not null
group by year(o.sales_date),month(o.sales_date),GENDER
order by year(o.sales_date) asc,month(o.sales_date) asc,GENDER asc