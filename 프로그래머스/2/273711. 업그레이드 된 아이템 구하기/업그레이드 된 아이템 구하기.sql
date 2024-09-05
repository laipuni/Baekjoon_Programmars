select ITEM_ID,
       ITEM_NAME,
       RARITY
from ITEM_INFO as i
where i.item_id in (
    select tree.item_id
    from ITEM_INFO as item
    join ITEM_TREE as tree
    on item.item_id = tree.parent_item_id
    where item.rarity like "RARE"
)
order by item_id desc