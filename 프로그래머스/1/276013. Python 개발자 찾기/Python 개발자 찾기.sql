select id,
       email,
       first_name,
       last_name
from DEVELOPER_INFOS as d
where d.skill_1 like "Python" or d.skill_2 like "Python" or d.skill_3 like "Python" 
order by id asc