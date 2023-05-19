### 깃 저장소 만들기
* 기존 디렉토리를 git 저장소 만들기 : git init -> 이는 .git 디렉토리를 생성하는 명령어
* 기존 저장소를 clone 하기 : git clone <url> [directory name]

### 깃 수정 & 저장
* 파일의 상태 : untracked, unmodified, modified, staged 존재
* 파일 상태 확인하기 : git status
* untracked 파일을 추적하기 : git add
* modified 파일을 stage 하기 : git add
* git add 후 파일을 수정하면, 수정 전 파일이 staged인 상태로 남으며, 동시에 수정 후 파일이 unstaged상태로 있게 된다.

### .gitignore
* git이 관리할 필요 없는 파일을 무시하기 위해 필요한 파일. 파일 패턴을 입력하여 관리한다.(표준 glob 패턴)
* .gitignore은 하위 폴더에만 영향을 미침. 최상위 폴더에 하나 사용하거나, 하위 푤더에 여러개 사용 가능

### 변경사항 확인하기
* working directory <-> staging area 비교 : git diff
* commit <-> staging area 비교 : git diff --staged 또는 git diff --cached(동일한 명령어)

### 변경사항 커밋
* git commit 은 staged 파일만 스냅샷한다. 명령어 : git commit -m "메시지 내용"
* staging area 생략 : git commit -ma 사용. -a 옵션이 추적중인 파일을 자동으로 스테이징해준다.

### 파일 삭제하기
* 파일 삭제 : git rm, 워킹 디렉토리 파일 삭제와 staging area을 통해 삭제
* 만일 파일을 단순 삭제할 시 파일 상태가 unstaged하게 된다.
* 이미 파일을 수정하거나 staging area에 추가 한 상태에서의 삭제(강제 삭제) : git rm -f
* 워킹 디렉토리 파일은 남기고, staging area에서만 삭제 : git rm --cached
* file-glob 패턴을 사용하여 여러 파일을 동시 삭제 가능

### 파일 이름 변경하기
* 파일 이름 변경 : git mv file_from file_to
* 이는 mv 명령어와 동일. 다만 mv, rm, add를 동시에 처리해줌.

### 커밋 히스토리 조회
* 커밋 로그 확인하기 : git log
* 각 커밋의 diff 확인 : git log -p
* 최근 결과만 확인 : git log -2 (최근 2개만 보여줌)
* 커밋에 대한 통계 확인 : git log --stat (파일 변경사항, 파일 수정사항, 라인 추가, 라인 삭제 등)
* 커밋 간단하게 확인 : git log --oneline (short, full, fuller 등 존재)
* 커밋 포맷 설정하기 : git log --pretty=format:"포맷 문자열"
* 시간을 기준으로 확인 : git log --since=2.weeks, (after, until, before 등)
* author을 기준으로 확인 : git log --author
* 커밋 메시지 텍스트 검색 : git log -- grep

### 되돌리기
* 커밋 덮어쓰기 : 완료한 커밋을 수정해야 하는 경우나 메시지를 잘못 작성한 경우 : git commit --amend, 커밋의 변경사항을 남기지 않음
* 파일을 unstaged 하기 : git reset HEAD [file name]
* modified 파일 되돌리기 : git checkout -- file //변경점이 아에 사라지니 매우 조심해서 사용

### 리모트 저장소
* 리모트 저장소 확인하기 : git remote, git remote - v(링크 보여주는 옵션)
* 리모트 저장소 추가하기 : git remote add [저장소 이름] [url] 
* 리모트 저장소에서 데이터 가져오기 : git fetch [remote name]
* git pull : 데이터를 가져온 뒤 로컬 브랜치와 머지
* 리모트 저장소에 푸쉬하기 : git puh [리모트 저장소 이름] [브랜치 이름]
* 리모트 저장소 살펴보기 : git remote show [리모트 저장소 이름]
* 리모트 저장소 이름 변경 : git remote rename before after
* 리모드 저장소 삭제 : git remote remove, git remote rm

### 태그
* 태그 조회하기 : git tag, 알파벳 순서로 보여줌
* 태그 검색하기 : git tag -l "검색 내용"
* 태그 종류 : lightweight(단순한 특정 커밋에 대한 포인터), annotated(여러 정보를 담음)
* Annotated 태그 생성 : git tag -a [태그 이름] -m "메시지"
* lightweight 태그 생성 : git tag 태그이름
* 단일 태그 확인하기 : git show 태그이름
* 이전 커밋에 태그 생성 : git tag -a 태그이름 체크섬(일부만 사용 가능)
* 태그 공유하기 : git push origin 태그이름
* 태그 여러개 공유하기 : git push origin --tags
* 태그 체크아웃 하기 : git checkout 태그이름
* 체크아웃 상태에서 작업을 한 뒤 새로 커밋을 만들면, 새 커밋에 도달할 방법이 존재하지 않음.
* 이를 의미있게 하기 위해서는 브랜치를 만들어 작업

### alias
* 명령어를 쉽게 만들어주는 단축키
* 예 1 : git config --global alias.ch checkout : checkout 을 ch로 대체
* 예 2 : git config --global alias.unstage 'reset HEAD --'