select ANIMAL_TYPE,
       IFNULL(NAME,"No name") as NAME,
       SEX_UPON_INTAKE
from ANIMAL_INS as a
order by a.ANIMAL_ID asc