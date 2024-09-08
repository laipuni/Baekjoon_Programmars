select round(avg(IFNULL(f.LENGTH,10)),2) as AVERAGE_LENGTH
from FISH_INFO as f