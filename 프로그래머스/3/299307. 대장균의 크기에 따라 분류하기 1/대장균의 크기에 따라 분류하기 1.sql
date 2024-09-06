select id,
       (case
        when size_of_colony > 1000 then "HIGH"
        when size_of_colony > 100 and size_of_colony <= 1000 then "MEDIUM"
        when size_of_colony <= 100 then "LOW"
        end
       ) as SIZE
from ECOLI_DATA
order by id asc