<h1>Date Type</h1>

<ol>
    <li> Primitive Data Type: boolean, byte, short, int, long, float, double </li>
    <li> Reference Data Type: (객체로 취급하는 타입) - Array, Class, Interface, enum, .연산자 등 </li>
</ol>

<h1>변수</h1>
<ol>
    <li>변수의 의미: 데이터가 저장된 메모리 주소 대신 사용하는 의미 있는 이름</li>
    <li>변수 선언: 타입 변수명</li>
    <li>naming : 숫자 시작 안됨, _, $만 특수기호 사용 가능, </li>
    <li>변수 초기화 : 멤버 변수, 로컬 변수(선언과 동시에 초기화 권장)</li>
</ol>

<h1>연산자</h1>
<ol>
    <li>종류 산술 연산자, 증감 연산자, 논리 연산자, 비트 연산자, shift 연산자</li>
    <li>산술 연산자 : + - * /</li>
    <li>증감 연산자 : ++, --</li>
    <li>논리 연산자 : && || !</li>
    <li>비트 연산자 : &, |, ^</li>
    <li>shift 연산자 : <<, >>, >>> </li>
</ol>

<h1>문장</h1>
<ol>
    <li>조건문: if(조건식) {true 일 때 수행하는 문장}, else - if, else, switch case default 등</li>
    <li>반복문: for(초기화식; 조건식; 증감식), while(조건식), do-while, for-each</li>
</ol>

<h1>사용자로부터 입력받아오는 방법</h1>
<ol>
    <li>Scanner input = new Scanner(System.in) -> i/o는 예외처리를 반드시 해야하지만 예외처리가 되어 있음</li>
    <li>InputStream : 최상위 입력 스트림, 추상 클래스, 키보드 -> 입력버퍼 -> 운영체제 -> 자바 프로그램 이기에 OS별로 별도 구현이 필요 -> System.in</li>
    <li> input -> 여러 반환(nextInt())와 같은 함수를 사용할 수 있다. Scanner의 함수에 예외처리되어있음</li>
    <br/>
    <li>자바의 데이터 처리는 1byte, 2byte, line단위, buffer 단위 설계 -> java.io</li>
    <li>ByteStream</li>
    <li>CharacterStream</li>
    <li>1차 스트림(read, write)</li>
    <li>2차 스트림(변환, 필터, 버터 기능, 선능개선 목적)</li>
    <li>chain ByteStream 1차 2차 / 또는 CharacterStream 1차 2차</li>
    <li>new BufferedReader (new InputStreamReader(System.in)), .readLine() -> 엔터 전까지 입력</li>
    
</ol>