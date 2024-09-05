SELECT member_id
      ,member_name
      ,gender,date_format(date_of_birth,"%Y-%m-%d") 
      as DATE_OF_BIRTH
from member_profile as m
where month(m.date_of_birth) = 3 and m.tlno is not NULL and m.gender = 'W'
order by member_id