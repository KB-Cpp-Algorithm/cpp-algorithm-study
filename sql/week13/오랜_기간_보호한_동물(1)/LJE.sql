/*
animal_ins - 동물 보호소에 들어오 동물의 정보
animal_outs - 동물 보호소에서 입양 보낸 동물의 정보

아직 입양을 못 간 동물 중, 가장 오래 보호소에 있었던 동물 3마리의 이름과 보호 시작일을 조회하는 sql문
이때 결과는 보호 시작일 순으로 조회해야함
*/

-- sol 1
with still_in as(
    select * 
    from animal_ins ins
    where not exists(select 1 from animal_outs outs where outs.animal_id 
                     = ins.animal_id)
)
select name, datetime
from still_in
order by datetime
limit 3;


-- sol 2
with still_in as (
    select ai.name, ai.datetime
    from animal_ins as ai left join animal_outs as ao
        on ai.animal_id = ao.animal_id
    where ao.datetime is null
)
select name, datetime
from still_in 
order by datetime 
limit 3;
