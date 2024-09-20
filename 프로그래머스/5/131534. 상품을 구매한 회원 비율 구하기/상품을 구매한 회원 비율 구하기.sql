SELECT year(s.SALES_DATE) as YEAR
      ,month(s.SALES_DATE) as MONTH
      ,count(distinct s.user_id) as PUCHASED_USERS
      ,round(count(distinct s.user_id) / (select count(*)  
                  from USER_INFO as u 
                  where year(u.JOINED) = 2021),1) as PUCHASED_RATIO
from ONLINE_SALE as s
join USER_INFO as i
on year(i.joined) = 2021 and s.user_id = i.user_id
group by year(s.SALES_DATE), month(s.SALES_DATE) 
order by year(s.SALES_DATE) asc , month(s.SALES_DATE) asc