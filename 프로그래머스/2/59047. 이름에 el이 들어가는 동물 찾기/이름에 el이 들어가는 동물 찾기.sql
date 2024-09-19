SELECT animal_id
      ,name
from animal_ins as i
where (i.name like "%el%" or i.name like "El%") and animal_type ="Dog"
order by name asc