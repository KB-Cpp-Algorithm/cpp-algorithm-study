/*
USED_GOODS_BOARD - 중고 거래 게시판 정보
USED_GOODS_USER - 중고 거래 게시판 사용자 정보

완료된 중고 거래의 총 금액이 70만원 이상인 사람의 회원 id, 닉네임, 총거래금액
총거래금액을 기준으로 오름차순
*/
select user.user_id, user.nickname, sum(board.price) as total_sales
from USED_GOODS_BOARD as board join USED_GOODS_USER as user
    on board.writer_id = user.user_id
where board.status = 'DONE' 
group by user.user_id, user.nickname
having sum(board.price) >= 700000
order by total_sales;
