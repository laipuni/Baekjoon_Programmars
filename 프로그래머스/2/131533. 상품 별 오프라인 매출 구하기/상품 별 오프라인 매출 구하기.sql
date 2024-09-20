SELECT p.product_code as PRODUCT_CODE
      ,(sum(s.SALES_AMOUNT) * p.price) as SALES
from OFFLINE_SALE as s
join PRODUCT as p
on p.PRODUCT_ID = s.PRODUCT_ID
group by PRODUCT_CODE
order by (sum(s.SALES_AMOUNT) * p.price) desc,p.PRODUCT_CODE