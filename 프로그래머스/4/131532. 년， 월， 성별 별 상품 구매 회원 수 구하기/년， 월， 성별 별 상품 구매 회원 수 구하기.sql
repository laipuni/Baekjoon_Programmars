SELECT year(o.sales_date) as YEAR,
       month(o.sales_date) as MONTH,
       GENDER,
       count(*) as USERS
from USER_INFO as i
join (
    select user_id,
           sales_date
    from ONLINE_SALE as o
    group by year(o.sales_date),month(o.sales_date), user_id
)
as o
on i.user_id = o.user_id
where i.GENDER is not null
group by year(o.sales_date),month(o.sales_date),GENDER
order by year(o.sales_date) asc,month(o.sales_date) asc,GENDER asc