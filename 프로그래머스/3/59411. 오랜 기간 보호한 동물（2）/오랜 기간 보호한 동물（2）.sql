SELECT o.animal_id
      ,o.name
from animal_outs as o
join animal_ins as i
on i.animal_id = o.animal_id
order by datediff(o.datetime,i.datetime) desc
limit 2