/*
car_rental_company_car - 대여 중인 자동차들의 정보
car_rental_company_rental_history - 자동차 대여 기록 정보
*/
select distinct car.car_id
from car_rental_company_car as car join car_rental_company_rental_history as his
     on car.car_id = his.car_id
where car.car_type = '세단' and month(his.start_date) = 10
order by car.car_id desc;
