select user_id
      ,nickname
      ,sum(price)
from used_goods_user as u
join used_goods_board as b
on b.writer_id = u.user_id 
where b.status = "DONE"
group by b.writer_id
having sum(price) >= 700000
order by sum(price)