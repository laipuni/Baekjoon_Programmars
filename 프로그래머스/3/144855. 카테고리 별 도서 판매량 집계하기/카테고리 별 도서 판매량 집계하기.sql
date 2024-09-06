SELECT category
      ,sum(sales) as TOTAL_SALES
from book_sales as s
join book as b
on s.book_id = b.book_id
where s.sales_date like "2022-01%"
group by category
order by category