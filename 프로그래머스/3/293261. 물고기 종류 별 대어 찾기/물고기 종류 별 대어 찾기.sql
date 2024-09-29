select id,
       fish_name,
       m.length
from FISH_INFO as f
join (
    select fish_type,max(length) as length
    from FISH_INFO
    group by fish_type
) 
as m
on f.fish_type = m.fish_type and f.LENGTH = m.length
join FISH_NAME_INFO as n
on f.fish_type = n.fish_type