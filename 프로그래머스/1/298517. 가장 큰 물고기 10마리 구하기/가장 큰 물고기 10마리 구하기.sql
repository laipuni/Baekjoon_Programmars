select id,
       length
from FISH_INFO as i
order by length desc, id asc
limit 10