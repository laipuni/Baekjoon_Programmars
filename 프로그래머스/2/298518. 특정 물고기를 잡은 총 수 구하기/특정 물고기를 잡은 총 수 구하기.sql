select count(*) as FISH_COUNT
from FISH_INFO as f
join FISH_NAME_INFO as i
on i.fish_type = f.fish_type and 
(i.fish_name like "BASS" or i.fish_name like "SNAPPER")
