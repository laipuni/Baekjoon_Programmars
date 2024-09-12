select sum(price) as TOTAL_PRICE
from ITEM_INFO as i
where i.rarity = "LEGEND"
