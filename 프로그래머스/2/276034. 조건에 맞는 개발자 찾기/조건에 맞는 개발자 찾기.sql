select distinct id,
       email,
       first_name,
       last_name
from DEVELOPERS as d
join SKILLCODES as s
on (s.name like "Python" or s.name like "C#") and s.code & d.skill_code
order by id asc