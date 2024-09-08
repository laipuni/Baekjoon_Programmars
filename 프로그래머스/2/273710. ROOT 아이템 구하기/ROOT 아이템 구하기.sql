select i.ITEM_ID,
       i.ITEM_NAME
from ITEM_INFO as i
join ITEM_TREE as t
on t.parent_item_id is NULL and t.item_id = i.item_id
order by i.item_id asc