select count(*)
from USER_INFO as u
where year(u.joined) = 2021 and u.age >= 20 and u.age <= 29