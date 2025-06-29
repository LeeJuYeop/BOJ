# [Silver III] 주식 시장 - 31826 

[문제 링크](https://www.acmicpc.net/problem/31826) 

### 성능 요약

메모리: 2020 KB, 시간: 80 ms

### 분류

구현, 시뮬레이션

### 제출 일자

2025년 6월 19일 21:48:14

### 문제 설명

<blockquote>
<p>첫 번째 규칙은 절대로 잃지 마라. 두 번째 규칙은 첫 번째를 절대로 따라라.</p>

<p>- 워런 버핏(Warren Buffett)</p>
</blockquote>

<p>하루는 최근 주식 시장에 푹 빠져있다. 하루는 주식의 가격이 어떻게 변동되는지 연구하였고, 연구한 자료를 바탕으로 가상 주식 시장을 만들었다.</p>

<p>가상 주식 시장은 아래 내용을 기반으로 운영된다고 한다.</p>

<ul>
	<li>주식의 단위는 $1$주이며, 가격은 $10$원 단위로 변경된다.</li>
	<li>주식의 가격은 항상 $10\,000$원으로 시작하며, 처음에 $10$원 단위의 모든 가격의 구매/판매 물량은 $0$주이다.</li>
	<li>주식을 구매하고 싶거나 판매하고 싶다면 가격 $p_i$에 주문을 넣는 과정을 통해 구매/판매할 수 있다.
	<ul>
		<li>만약 가격 $p_i$의 판매 물량 $s_i$가 $1$ 이상이고, 주문으로 $x_i$주를 구매하고자 한다면 $\min(s_i, x_i)$주가 구매되고, $x_i > s_i$일때 $x_i - \min(s_i, x_i)$주가 구매 물량으로 전환된다.
		<ul>
			<li>이때 판매 물량 $s_i$는 구매된 주식 수 만큼 감소한다.</li>
		</ul>
		</li>
		<li>만약 가격 $p_i$의 구매 물량 $s_i$가 $1$ 이상이고, 주문으로 $x_i$주를 판매하고자 한다면 $\min(s_i, x_i)$주가 판매되고, $x_i > s_i$일때 $x_i - \min(s_i, x_i)$주가 판매 물량으로 전환된다.
		<ul>
			<li>이때 구매 물량 $s_i$는 판매된 주식 수 만큼 감소한다.</li>
		</ul>
		</li>
	</ul>
	</li>
	<li>주식의 가격은 아래 조건에 따라 변경된다.
	<ul>
		<li>주문이 접수될 때, 가격 $p_i$에 대해 구매/판매할 수 있는 주식이 $1$주 이상이라면 주식의 가격이 $p_i$로 변경된다.</li>
		<li>만약 구매할 수 있는 주식이 $0$주라면 주식의 가격은 변하지 않으며, 가격 $p_i$의 구매 물량에 $x_i$주가 추가된다.</li>
		<li>또한 판매할 수 있는 주식이 $0$주라면 주식의 가격은 변하지 않으며, 가격 $p_i$의 판매 물량에 $x_i$주가 추가된다.</li>
	</ul>
	</li>
</ul>

<p>만약 아래 그림에서 현재 가격이 $10\ 000$원이고, $10\ 020$원에 $250$주 구매 주문을 넣는다면 현재 가격은 $10\ 020$원이 되고, $10\ 020$원에서의 판매 물량 $200$주는 구매 물량 $50$주로 변경된다.</p>

<p style="text-align: center;"><img alt="" src="" style="width: 100%; height: 10%;"></p>

<p>가상 주식 시장에서 하루가 만든 HRX 회사의 주식을 거래할 수 있게 되었다.</p>

<p>HRX 회사의 주식에 대한 $N$개의 주문 정보가 차례대로 주어질 때, $N$개의 주문이 처리된 후의 HRX 회사 주식의 현재 가격을 출력하라.</p>

### 입력 

 <p>첫 번째 줄에 주문의 개수 $N$이 주어진다. ($1 \leq N \leq 100\ 000$)</p>

<p>두 번째 줄부터 $N$개의 줄에 걸쳐 각 주문의 정보 $(p_i, x_i, f_i)$의 $p_i$, $x_i$, $f_i$가 공백으로 구분되어 주어진다. ($7\,000 \leq p_i \leq 13\,000$; $p_i$는 $10$의 배수; $1 \leq x_i \leq 1\,000$; $f_i$는 $-1$ 혹은 $1$)</p>

<p>$f_i$가 $-1$이면 판매 주문, $f_i$가 $1$이면 구매 주문임을 나타내며, 주어지는 모든 수는 정수이다.</p>

### 출력 

 <p>$N$개의 주문이 처리된 후의 HRX 회사 주식의 현재 가격을 출력하라.</p>

