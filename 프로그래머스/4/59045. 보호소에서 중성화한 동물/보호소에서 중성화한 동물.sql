SELECT i.animal_id
      ,i.animal_type
      ,i.name
from ANIMAL_INS as i
join ANIMAL_OUTS as o
on i.animal_id = o.animal_id and 
   i.SEX_UPON_INTAKE != o.SEX_UPON_OUTCOME
order by i.animal_id asc