## 네트워크 통신

### 유니캐스트(one-to-one)
* 출발지와 목적지가 정해진 통신 방식이다.
* 일반적인 통신 상황에서는 해당 방식을 사용한다.

### 브로드캐스트(one-to-all)
* 출발지는 정해져있지만, 목적지 ip를 1로 적어 보낸다. 네트워크 내 모든 장치에 해당 패킷이 전달되게 된다.
* 주로 DHCP, ARP가 해당 방식을 사용한다.

### 멀티캐스트(one-to-many)
* 목적지 그룹에게 동시에 여러 패킷을 전달한다.
* 한번의 전송으로 여러 그룹에게 패킷을 전달하기 때문에, 서버 부하를 감소시킬 수 있다.
* IPTV, 사내 방송, 증권 시세 방송 등 단뱡향으로 다수에게 같은 내용을 전달할 때 사용한다.


### 애니캐스트(one-to-nearest)
* 가장 가까운(비용이 저렴한) 장치로 패킷을 전달한다.
* DNS, CDN에서 해당 방식을 사용한다.

| 이름                    | 통신방식          | 사례                    |
|-----------------------|---------------|-----------------------|
| 유니캐스트(one-to-one)     | 출발지와 목적지가 정해짐 | 일반적인 통신               |
| 브로드캐스트(one-to-all)    | 목적지가 네트워크 전체  | DHCP, ARP             |
| 멀티캐스트(one-to-many)    | 목적지가 특정 그룹    | IPTV, 사내 방송, 증권 시세 방송 |
| 애니캐스트(one-to-nearest) | 목적지가 가장 가까운 곳 | DNS, CDN              |

### BUM 트래픽
* Broadcast, Unknown unicast, Multicast을 의미한다.
* Unknown unicast는 유니캐스트이지만, 스위치가 목적지 주소를 알지 못해, 패킷을 모든 포트로 전송하는 경우를 의미한다.
* 불필요한 BUM 트래픽은 네트워크 성능을 저하시킨다.
* 이더넷 환경에서는 ARP 브로드캐스트 이후 통신이 시작되게이 BUM 트래픽이 많이 발생하지 않는다.

<br></br>
<br></br>

## MAC 주소
* Media Access Control, 2계층 통신을 위한 네트워크 인터페이스에 할당된 식별자

### MAC 주소 체계
* MAC 주소는 하드웨어에 고정되어 출하되어 변경이 힘들다.
* 각 제조업체가 자체적으로 할당하며, IEEE가 관리한다.
* MAC 주소 = OUI(6자리, 제조사 코드) + UAA(6자리, 제조사 자체 할당)
* MAC 주소는 유일하지 않으며, 동일 네트워크에서 중복되지만 않으면 동작에 문제는 없다.(다른 네트워크로 통신할 때 기존의 출발지 도착지 MAC 주소를 유지하지 않음.)

### MAC 주소 동작
* NIC(네트워크 카드)는 MAC 주소를 가지고 있다가 들어온 전기 신호를 데이터로 변환 후 MAC 주소를 확인한다.
* MAC 주소가 일치하지 않는 패킷은 폐기한다.
* 주소가 일치하거나, 브로드캐스트 주소는 OS나 애플리케이션에서 처리해야하기에 시스템 부하가 작용한다.
* 단말기는 여러 NIC를 통해 여러 MAC 주소를 가질 수 있다.
* 다른 목적지 패킷을 분석하거나 수집하기 위해서는 무차별 모드(promiscuois mode)로 NIC를 구성할 수 있다.

<br></br>
<br></br>

## IP 주소
* IP 주소는 변경 가능하며, 네트워크 주소와 호스트 주소로 구분된다.

### 클래스 기반의 IP 주소 체계
* IP 주소는 호스트 개수에 따라 네트워크 크기를 다르게 할당할 수 있는 클래스 개념을 도입했다. 

| class   | address               | subnet mask   | 호스트 개수  |
|---------|-----------------------|---------------|---------|
| A class | 1.0.0.0 ~ 127.0.0.0   | 255.0.0.0     | 2^24 -2 |
| B class | 128.0.0.0 ~ 191.0.0.0 | 255.255.0.0   | 2^16 -2 |
| C class | 192.0.0.0 ~ 223.0.0.0 | 255.255.255.0 | 2^8 -2  |

* A 클래스의 주소 123.12.43.231을 예로 들면, 123.0.0.0이 네트워크 주소이며, 12.43.231이 호스트 주소이다.
* B 클래스의 주소 174.42.112.33에서는 174.42.0.0이 네트워크 주소이며, 112.33이 호스트 주소이다.
* 서브넷 마스크는 네트워크 주소의 위치를 나타내주는 개념이다. 클래스 기반에서는 클래스 별로 서브넷 마스크가 정해져있다. 이를 통해 클래스 기반에서는 서브넷 마스크를 몰라도, 네트워크 주소와 호스트 주소의 구분이 가능하다.

### 클래스리스 네트워크
* 배경: 인터넷 상용화로 인한 호스트 숫자의 폭발적 증가, IP 주소의 낭비로 인해 3가지 보존, 전환 전략을 세움. 

| 단계  | 내용                                          |
|-----|---------------------------------------------|
| 1단계 | 클래스리스, CIDR(classless inter-domain routing) |
| 2단계 | NAT, 사설 IP 주소                               |
| 3단계 | IPv6                                        |

* 특히 A 클래스를 할당받은 조직에서 주소를 제대로 활용하지 못하는 문제가 발생 -> 클래스 개념 포기 -> 빈 주소를 분할하여 다른 조직에서 사용 가능
* 클래스 기반에서는 서브넷 마스크 없이 네트워크 주소와 호스트 주소의 구분이 가능했지만, 클래스리스에서는 불가능.
* 예를 들어 IP 주소 12.34.56.78, 서브넷 마스크 255.255.16.0인 경우, 비트 연산을 통해 네트워크 주소를 구할 수 있다.
```

     12.34.56.78   : 00001100 . 00100010 . 00111000 . 01001110 (ip 주소)
     255.255.240.0 : 11111111 . 11111111 . 11110000 . 00000000 (서브넷 마스크)
     ---------------------------------------------------------- &&
     12.34.48.0    : 00001100 . 00100010 . 00110000 . 00000000 (네트워크 주소)
     0.0.8.78      : 00000000 . 00000000 . 00001000 . 01001110 (호스트 주소)
     
     12.34.48.1    : 00001100 . 00100010 . 00110000 . 000000001 (첫 번째 주소)
     12.34.63.254  : 00001100 . 00100010 . 00111111 . 111111111 (마지막 주소)
     12.34.63.255  : 00001100 . 00100010 . 00111111 . 111111111 (브로드캐스트 주소)
     사용 가능한 주소 수 : 2^12 - 2 (호스트 주소가 12 비트) - (0, 브로트 캐스트 제외)
     
```

### 서브네팅
* 클래스풀 단위의 네트워크보다 더 쪼개 사용하는 것을 의미한다.
* 위 예시처럼 주소와 서브넷 마스크를 통해 네트워크 주소를 찾고, 브로드 캐스트 주소와 첫 번째 주소, 마지막 주소를 찾을 수 있다.

### 공인 IP, 사설 IP
* IP는 전 세계에서 유일한 실별자이여야 한다.
* 인터넷에 연결하지 않고 개인적으로 네트워크를 구성할 경우에는 IP 할달 없이 사설 ip 주소를 사용할 수 있다.
* 사설 ip를 사용한 상태에서 인터넷에 연결하기 위해서는 NAT(network address translation)를 사용해야 한다.
* 클래스 별로 사설 IP 주소가 1개씩 설정되어 있다.

| 클래스   | 사설 주소                         |
|-------|-------------------------------|
| A 클래스 | 10.0.0.0 ~ 10.255. 255. 255   |
| B 클래스 | 172.16.0.0 ~ 172.31.255.255   |
| C 클래스 | 192.168.0.0 ~ 192.168.255.255 |

* Bogon IP : 사설 IP와 같이 공인 IP로 할당하지 않는 주소를 의미한다.

<br></br>
<br></br>

## TCP & UDP

### TCP(Transmission Control Protocol)
* 세션을 안전하게 연결하고, 데이터를 분할하며, 분할된 패킷이 잘 전송되었는지 확인할 수 있다.
* 패킷에 시퀀스 번호를 부여하고, 전송에 대한 응답을 힌다. 한번에 보낼 데이터 전송 크기(윈도우 사이즈)를 고려한다.
* 데이터 유닛
* ![스크린샷 2023-06-10 오전 10 55 15](https://github.com/ChangDaeJun/study/assets/97227920/b50d0dd6-2152-4a98-97b5-2028ac3bd26b)
* 출처 : https://www.technologyuk.net/telecommunications/internet/transport-layer-protocols.shtml

### TCP 데이터 전달 과정

| 송신자                                                                                           | 수신자                                                                                             |
|-----------------------------------------------------------------------------------------------|-------------------------------------------------------------------------------------------------|
| 출발 포트 : 7924<br/>도착 포트 : 80 <br/> SYN<br/>   * SEQ=m,<br/> * LEN=0                            |                                                                                                 |
|                                                                                               | 출발 포트 : 80 <br/>도착 포트 : 7924 <br/> SYN, ACK<br/>   * SEQ=n,<br/> * LEN=0 <br/>  * ACK=m+1 <br/> |
| 출발 포트 : 7924<br/>도착 포트 : 80 <br/> ACK<br/>   * SEQ=m+1, <br/> * ACK= n+1,<br/> * LEN=0        |                                                                                                 |
| 출발 포트 : 7924<br/>도착 포트 : 80 <br/> GET HTTP<br/>   * SEQ=m+1, <br/> * ACK=n+1, <br/> * LEN=562 |                                                                                                 |
|                                                                                               | 출발 포트 : 80 <br/>도착 포트 : 7924 <br/> ACK<br/>   * SEQ=n+1,<br/> * ACK=(m+1)+562, <br/> * LEN=0    |
|                                                                                               | 출발 포트 : 80 <br/>도착 포트 : 7924 <br/> HTTP<br/>   * SEQ=n+1,<br/> *ACK=(m+1)+562, <br/> * LEN=597  |
| 출발 포트 : 7924<br/>도착 포트 : 80 <br/> ACK<br/>   * SEQ=(m+1)+562, <br/> * ACK=(n+1)+597           |                                                                                                 |

* 두 컴퓨터가 최초 통신을 하기 위해서 LEN =0 인 패킷을 주고 받는다.(3way handshake)
* 3 way handshake을 통해 두 컴퓨터는 각자의 seq 번호를 동기화한다.
* 매 요청 시 SEQ는 자신의 seq 번호를, ACK는 상대방의 seq 번호를 담아 보낸다.

### TCP 슬라이드 윈도우
* 윈도 사이즈를 상황에 따라 조절하는 것을 슬라이드 윈도라고 한다.

<br></br>
<br></br>

## ARP

* IP 주소와 MAC 주소를 연계시키기 위한 프로토콜이다.
* 호스트에서 처음 통신을 시도하면, 도착지 MAC 주소를 알지 못해 캡슐화를 진행할 수 없습니다.
* 도착지 MAC 주소를 알기 위해 ARP 프로토콜은 브로드캐스트를 통해 네트워크 전체에 상대 MAC 주소에 대한 질의를 합니다.
* 해당 MAC 주소와 IP 주소 테이블을 저장하여 유지합니다. 일정 시간동안 사용되지 않으면 삭제됩니다.
* 네트워크 장비에서 ARP는 CPU에서 직접 수행 -> 짧은 시간 많은 요청이 들어오면 큰 부하가 발생한다.

### ARP 동작
* 서버 A에서는 서버 B의 IP주소는 알지만, MAC 주소는 몰라 패킷을 만들 수 없는 상황이다.
* A는 다음과 같은 요청을 네트워크에 브로드캐스드한다.

| 출발지 MAC | 목적지 MAC                   | 전송자 MAC | 전송자 IP  | 대상자 MAC           | 대상자 IP  |
|---------|---------------------------|---------|---------|-------------------|---------|
| AA      | 브로드캐스트(FF-FF-FF-FF-FF-FF) | AA      | 1.1.1.1 | 00-00-00-00-00-00 | 1.1.1.2 |
* 서버 B를 제외한 단말은 해당 브로트캐스트를 버리고, 서버 B만 받아 다음과 같이 ARP 응답을 한다.

| 출발지 MAC | 목적지 MAC | 전송자 MAC | 전송자 IP  | 대상자 MAC | 대상자 IP  |
|---------|---------|---------|---------|---------|---------|
| BB      | AA      | BB      | 1.1.1.2 | AA      | 1.1.1.1 |

* 서버 A는 해당 응답을 받아 자신의 ARP 캐시 테이블을 갱신한다.

### GARP
* ARP 브로트캐스트 요청에서 대상자 IP에 자기 자신의 IP 주소를 넣는다.

| 출발지 MAC | 목적지 MAC                   | 전송자 MAC | 전송자 IP  | 대상자 MAC           | 대상자 IP  |
|---------|---------------------------|---------|---------|-------------------|---------|
| AA      | 브로드캐스트(FF-FF-FF-FF-FF-FF) | AA      | 1.1.1.1 | 00-00-00-00-00-00 | 1.1.1.1 |

* 해당 프로토콜은 자신의 IP와 MAC 주소를 알리는 목적을 갖으며, 다음과 같은 상황에서 사용 가능하다.
```
    1. 동일 네트워크 상의 IP 충돌 감지(브로드캐스트 이후, 응답이 온다면 나와 동일한 IP가 존재한다는 뜻 = IP 충돌)
    2. 상대방의 ARP 테이블 갱신
    3. HA 용도의 클러스터링, VRRP, HSRP
```

## 스위치
* 동일 네트워크 상 여러 장비가 서로 간섭없이 통신할 수 있도록 도와주고, 네트워크 전체의 통신 효율성을 향상시켜주는 장비이다.
* 스위치는 2계층 주소(MAC)을 이해하고, MAC 주소 - 포트 정보인 MAC 주소 테이블을 통해 해당 기능을 구현한다.
* 스위치의 동작에는 크게 플러딩, 어드레스 러닝, 포워딩/필터링 3가지로 구분된다.

### 플러딩
* 최초 스위치가 부팅되면, 어떠한 정보도 없기 때문에 스위치는 허브처럼 동작하게 된다.
* 스위치는 각 포트에 연결된 단말 정보가 없기 때문에 들어온 패킷을 들어온 포트를 제외하고 모든 포트로 전달하는데, 이를 플러딩이라고 한다.
* 이더넷-TCP/IP 네트워크에서는 사전에 ARP 브로드캐스트 이후 데이터가 전달되기 때문에, 데이터가 전달 될 때 플러딩 하지 않는다.

### 어드레스 러닝
* 스위치가 정상적으로 동작하기 위해서는 MAC 주소 테이블을 만들고 유지해야 하는데, 이 과정을 어드레스 러닝이라고 한다. 
* 특정 포트에서 나온 패킷의 출발지 MAC 주소를 통해 해당 포트와 MAC 주소를 획득하여 학습할 수 있다.

### 포워딩/필터링
* 스위치는 들어온 패킷의 목적지 MAC 주소를 확인한 후, 테이블을 찾아 적절한 포트로 패킷을 전달한다.
* 일치하는 포트로 패킷을 전달하는 과정을 포워딩, 일치하지 않는 포트에는 전달하지 않는 것을 필터링이라고 한다.
* BUM 트래픽에 대해서는 플러딩 동작을 한다.

### VLAN
* LAN을 논리적으로 분할하고, 구성하는 기술이다. 이를 통해 네트워크를 분할하여 보안 향상과 과도한 브로드캐스로 인한 성능 저하 방지 등을 기대할 수 있다.
* VLAN에는 포트 기반의 VLAN과 MAC 기반의 VLAN이 있다. 각각 포트와 MAC 주소를 기반으로 가상 LAN을 구성한다.
* 여러 VLAN이 존재하는 스위치를 다른 스위치와 연결하기 위해서는 VLAN 만큼의 포트를 연결해야 하지만, 이런 포트 낭비를 해결하기 위해 하나의 포트에서 여러 VLAN을 함께 전송하는 태그 포트를 사용할 수 있다.

## 참고 자료(Reference)
* 고재성, 이상훈, IT 엔지니어를 위한 네트워크 입문(2020, 길벗)
* 
