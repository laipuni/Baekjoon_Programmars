select o.animal_id
      ,o.name
from animal_outs as o
left join animal_ins as i
on o.animal_id = i.animal_id
where i.animal_id is null
order by o.animal_id