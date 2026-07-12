/********************************************************************************/
/* File Name         : JH.sql                                                   */
/* By                : jaehoon                                 KK  KK   BBBBB   */
/* Algorithm         : Group By                                KK KK    BB  BB  */
/* Time Complexity   :                                         KKKKK    BBBBB   */
/* Space Complexity  :                                         KK KK    BB  BB  */
/* Note              : 집계 함수 적용                          KK  KK   BBBBB   */
/*                                                                              */
/********************************************************************************/

-- 인덱스를 적용할 수 없는 쿼리 
SELECT
    b.category AS CATEGORY,
    SUM(bs.sales) AS TOTAL_SALES
FROM
    book b
    INNER JOIN book_sales bs ON b.book_id = bs.book_id
WHERE
    DATE_FORMAT (bs.sales_date, '%Y-%m') = '2022-01'
GROUP BY
    CATEGORY
ORDER BY
    CATEGORY;


-- 인덱스를 적용할 수 있는 쿼리

-- SELECT
--     b.category,
--     SUM(bs.sales) AS total_sales
-- FROM
--     book b
--     JOIN book_sales bs ON b.book_id = bs.book_id
-- WHERE
--     bs.sales_date >= '2022-01-01'
--     AND bs.sales_date < '2022-02-01'
-- GROUP BY
--     b.category
-- ORDER BY
--     b.category;