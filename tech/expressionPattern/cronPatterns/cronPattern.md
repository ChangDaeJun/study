### cron Pattern
* 유닉스 운영체제의 시간 기반 스케쥴링의 파라미터로 사용되는 표현식이다.
* 스프링 스케쥴링에서 사용된다.
* 생성해주는 여러 사이트가 있다. <http://www.cronmaker.com/;jsessionid=node01iwbd6le9c2131r9vu5znuilx41244536.node0?0>

### 패턴
* 공백으로 구분되는 7개의 단위 표현식으로 이루어진다.(스프링의 경우 6자리를 요구한다.)
* 순서대로 초, 분, 시간, 일, 월, 요일, 연도이다.(각, secs, mins, hours, Day of Month, month, day of Week, year)
* 와일드 카드 *는 매 번을 의미한다.
* ?는 설정값 없음을 의미한다. 일, 요일에만 사용 가능하다.
* /는 값 증가를 의미한다. 분 위치에 10/15는 10분부터 시작하여 매 15분마다를 의미한다.
* N\#K은 해당하는 달의 N번째 K요일을 의미한다.
* L 은 마지막을 의미한다. 일에 사용하면 해당 월의 마지막 날을 의미한다. 특정 값 뒤에 사용할 경우에는 이 달의 마지막 날을 의미한다. 6L은 이달의 마지막 금요일을 의미한다.
* W는 해당하는 날로부터 가장 가까운 평일을 의미한다.

### 출처
* https://www.leafcats.com/94