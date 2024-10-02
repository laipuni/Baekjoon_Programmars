select i.ITEM_ID,
       i.ITEM_NAME,
       i.RARITY
from ITEM_INFO as i
left join ITEM_TREE as t
on t.parent_item_id = i.item_id
where PARENT_ITEM_ID is null
order by item_id desc