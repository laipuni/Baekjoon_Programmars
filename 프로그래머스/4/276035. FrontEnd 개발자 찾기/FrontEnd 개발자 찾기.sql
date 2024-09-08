select distinct ID,
                EMAIL,
                FIRST_NAME,
                LAST_NAME
from DEVELOPERS as d
join SKILLCODES as s
on d.skill_code & s.code and s.category = "Front End"
order by id asc