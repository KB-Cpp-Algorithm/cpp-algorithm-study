/*
animal_ins - 동물 보호소에 들어온 동물의 정보
animal_outs - 동물 보호소에서 입양 보낸 동물의 정보

보호 시작일 > 입양일 인 동물의 아이디와 이름 조회, 보호 시작일 순 정렬
*/
select ai.animal_id, ai.name
from animal_ins as ai join animal_outs as ao on ai.animal_id = ao.animal_id
where ai.datetime > ao.datetime
order by ai.datetime;
