select e.id,
       (select count(*)
        from ECOLI_DATA as d
        where d.parent_id = e.id
       ) as CHILD_COUNT
from ECOLI_DATA as e
