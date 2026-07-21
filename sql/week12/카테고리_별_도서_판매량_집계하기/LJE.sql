/*
category, total_sales
*/
select CATEGORY, sum(SALES) as TOTAL_SALES
from BOOK as b join BOOK_SALES as bs on b.BOOK_ID = bs.BOOK_ID
where SALES_DATE >= '2022-01-01' and SALES_DATE <= '2022-01-31'
group by CATEGORY
order by CATEGORY;
