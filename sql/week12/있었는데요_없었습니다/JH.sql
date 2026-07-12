/********************************************************************************/
/* File Name         : JH.sql                                                   */
/* By                : jaehoon                                 KK  KK   BBBBB   */
/* Algorithm         : Join                                    KK KK    BB  BB  */
/* Time Complexity   :                                         KKKKK    BBBBB   */
/* Space Complexity  :                                         KK KK    BB  BB  */
/* Note              : Date 타입에 조건 설정                   KK  KK   BBBBB   */
/*                                                                              */
/********************************************************************************/
SELECT
    ai.animal_id AS ANIMAL_ID,
    ai.name AS NAME
FROM
    animal_ins ai
    INNER JOIN animal_outs ao ON ai.animal_id = ao.animal_id
WHERE
    ai.DATETIME > ao.DATETIME
ORDER BY
    ai.DATETIME;