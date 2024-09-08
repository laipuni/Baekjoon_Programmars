SELECT ANIMAL_TYPE
      ,IFNULL(NAME,"No name") 
      ,SEX_UPON_INTAKE
from animal_ins
order by animal_id