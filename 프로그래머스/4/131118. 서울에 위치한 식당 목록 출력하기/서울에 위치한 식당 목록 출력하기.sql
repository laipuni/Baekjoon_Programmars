select i.rest_id,
       i.rest_name,
       i.food_type,
       i.favorites,
       i.address,
       round(avg(review_score),2) as SCORE
from REST_REVIEW as r 
join REST_INFO as i
on r.rest_id = i.rest_id and i.address like "서울%"
group by r.rest_id
order by SCORE desc, i.favorites desc