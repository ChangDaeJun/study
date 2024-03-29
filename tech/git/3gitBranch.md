### git의 데이터 저장 방식과 브랜치
* git은 커밋 시 각 파일에 대한 데이터 객체, 파일과 디렉토리 구조가 있는 트리 객체, 메타데이터와 루트 트리를 가리키는 포인터가 담긴 커밋 객체를 생성한다.
* 또한 각 커밋은 이전 커밋에 대한 포인터도 저장한다.
* ![1번 사진](https://user-images.githubusercontent.com/97227920/219311819-18c69c70-ad73-474f-85c7-caaf277c3677.png)

* 깃의 브랜치는 커밋 사이를 이동하는 포인터와 유사하다.

### 브랜치
* 생성 : git branch 브랜치이름
* 지금 작업중인 브랜치는 HEAD 라는 포인터를 사용하여 가리킴.
* 이동 : git checkout 브랜치 이름
* 삭제 : git branch -d 브랜치 이름
* fast-forward : 머지하는 대상이 흐름 상 단순히 앞에 있는 경우, 머지 대상의 브랜치 포인터만 이동하면 됨
* 3-way merge : 각 브랜치의 커밋 2개와 두 브랜치의 공통 커밋을 합쳐 merge 한다.
* ![사진 2](https://user-images.githubusercontent.com/97227920/219311917-1edc61ca-13ee-47e2-96d2-4f1c4539442e.png)


### 브랜치 관리
* 브랜치 전체 조회 : git branch
* 브랜치 마지막 커밋 확인 : git branch -v
* 머지된, 머지안된 브랜치 확인 : git branch --merged, --no-merged
* 머지안된 브랜치는 삭제되지 않는다. 강제 삭제 : git branch -D 브랜치이름

### 브랜치 워크플로우
* Long-Running 브랜치 : 배포할 코드만 main 브랜치에 머지하는 방식. 개발이나 안정화를 위한 브랜치를 둘 수 있음
* 토픽 브랜치 : 주제 별 브랜치를 만들어 적용.

### git push
* git push origin localBranchName: remoteBranchName
* :을 없이 푸쉬할 경우 로컬 브랜치 이름과 동일하게 리모트 저장소에 저장된다.
* 리모트 저장소에서 fetch하는 것은 수정할 수 없는 origin/branch 브랜치 포인터가 생기는 것.
* 리모트 트래킹 브랜치에서 시작하는 새 브랜치 만들기 : git checkout -b newBranchName origin/remoteBranchName

### 브랜치 추적
* 리모트 트래킹 브랜치를 로컬로 checkout 하면 자동으로 트래킹 브랜치가 만들어짐.
* 트래킹 브랜치는 리모트 브랜치와 직접 연결. git pull을 통해 패치, merge 를 자동으로 함.

### Rebase
* 리베이스는 두 브랜치가 나뉘기 전인 공통 커밋으로 이동 후 diff를 차례대로 적용. 이후 main을 ff
* 리베이스는 리모트 브랜치에 커밋을 깔끔하게 적용하기 위해 사용.
* 또는 다른 토픽 브랜치에서 갈라져 나온 토픽 브랜치를 main에 리베이스하여 사용 가능
* [주의] 이미 공개 저장소에 push한 커밋을 rebase하지 말 것****
