-- 코드를 입력하세요
SELECT count(*) as USERS from user_info as u where u.age >= 20 and u.age <= 29 and year(joined) = 2021