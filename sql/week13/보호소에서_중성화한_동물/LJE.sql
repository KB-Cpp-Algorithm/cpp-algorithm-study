/*
animal_ins - 동물 보호소에 들어온 동물의 정보
animal_outs - 동물 보호소에서 입양 보낸 동물의 정보

보호소에서 중성화 수술을 거친 동물 정보를 알아보려고 한다.
보호소에 들어올 당시에는 중성화되지 않았지만, 보호소를 나갈 당시에는 중성화된 동물의
아이디 / 생물 종 / 이름
아이디 순으로 정렬
*/
SELECT ins.animal_id, ins.animal_type, ins.name
FROM animal_ins ins join animal_outs outs on ins.animal_id = outs.animal_id
WHERE ins.sex_upon_intake LIKE 'Intact%' AND   
      (outs.sex_upon_outcome LIKE 'Spayed%' OR 
       outs.sex_upon_outcome LIKE 'Neutered%')
ORDER BY ins.animal_id;
