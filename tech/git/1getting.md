해당 디렉토리의 모든 내용은 책 Pro git과 https://git-scm.com/docs 에서 가져왔습니다.

### git의 특징
* DVCS라는 분산 버전 관리 시스템, 파일 마지막 스냅샷 파일을 체크아웃하는 것이 아닌, 전체 히스토리를 포함하여 저장소 전체를 복사한다. - 데이터 백업에 용이
또한 리모트 저장소를 통해 다양한 방법으로 협업이 가능
* 리눅스 버전관리를 bitKeeper 라는 상용 DVCS사용 중. -> 유료화되어 새롭게 만든 것이 git
git은 저장 시 스냅샷 순간의 모든 파일을 저장. 변경이 없을 시 파일의 링크만 저장
* git checksum 을 통해 데이터 관리. SHA-1 hash를 통해 생성됨. 길이 40, 16진수의 문자열. 파일 내용과 디렉토리 구조를 통해 구해짐.
git은 파일을 이름이 아닌 해당 파일의 해시로 저장함.

### git 3 states
* modified: changed the file but have not committed it to your database yet.
* staged: marked a modified file in its current version to go into your next commit snapshot.
* committed: the data is safely stored in your local database.

### 3 space
* working tree: single checkout go one version.
* git directory: git stores the metadata and object database for your project.
* staging area: stores information about what will go into your next commit.

### git 환경설정 파일
1. [path]/etc/gitconfig file: 시스템의 모든 사용자와 모든 저장소에 적용되는 설정. git config —system으로 설정. 관리자 권한 필요
2. ~/.gitconfig, ~/.config/git/config file : 특정 사용자에게만 적용되는 설정. git config —global 설정.
3. .git/config file: 특정 저장소에만 적용. --local 을 통해 사용
   3 > 2 > 1 순으로 우선순위

### git의 여러가지 환경 설정 명령어
1. 사용자 이름, 이메일 설정 : git config —global user.email, user.name
2. 기본 편집기 설정 : git config —global core.editor [편집기 name]
3. 환경 설정 확인 : git config —list
4. 환경 설정 시 어느 파일에서 설정된 것인지 확인 : git config —show-orgin <Key>