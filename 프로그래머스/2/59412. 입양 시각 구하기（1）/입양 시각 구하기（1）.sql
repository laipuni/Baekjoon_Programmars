SELECT hour(datetime)
      ,count(*) as COUNT
from animal_outs
where hour(datetime) between 9 and 19
group by hour(datetime)
order by hour(datetime)