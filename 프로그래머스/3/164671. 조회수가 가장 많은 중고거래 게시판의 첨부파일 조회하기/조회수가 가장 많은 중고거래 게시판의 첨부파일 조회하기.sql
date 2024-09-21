SELECT concat("/home/grep/src/",
              f.board_id,
              "/",
              f.file_id,
              f.file_name,
              f.file_ext) as FILE_PATH
from USED_GOODS_FILE as f
where f.board_id = (select board_id from USED_GOODS_BOARD order by views desc limit 1)
order by f.file_id desc