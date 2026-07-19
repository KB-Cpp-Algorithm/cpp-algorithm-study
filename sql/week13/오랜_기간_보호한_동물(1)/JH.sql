/********************************************************************************/
/* File Name         : JH.sql                                                   */
/* By                : jaehoon                                 KK  KK   BBBBB   */
/* Algorithm         : Join, Limit                             KK KK    BB  BB  */
/* Time Complexity   :                                         KKKKK    BBBBB   */
/* Space Complexity  :                                         KK KK    BB  BB  */
/* Note              :                                         KK  KK   BBBBB   */
/*                                                                              */
/********************************************************************************/

-- 아직 입양을 못 간 동물 중, 가장 오래 보호소에 있었던 동물 3마리의 이름과 보호 시작일을 조회
SELECT 
    ai.name AS NAME,
    ai.datetime AS DATETIME
FROM animal_ins ai
WHERE ai.animal_id NOT IN (
    -- 입양을 간 동물의 아이디를 조회
    SELECT ao.animal_id
    FROM animal_outs ao
)
ORDER BY datetime
LIMIT 3 OFFSET 0;