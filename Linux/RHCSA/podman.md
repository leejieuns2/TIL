33)	컨테이너 실행 - 기본
# sudo yum module list  module list 확인 가능
# sudo yum module install container-tools
# podman login URL
# podman pull URL/rhel/httpd-24:latest
# podman run - -name myweb -it URL/rhel/httpd-24 /bin/bash
# podman run - -rm URL/rhel/httpd-24

34)	컨테이너 실행 - 이미지 찾기 및 관리
# cat /home/student/.config/containers/registries.conf     // 구성된 레지스트리 조회 URL
# podman search URL/ubi
# podman login URL
# skopeo inspect docker://URL /rhel8/httpd-24             // 찾기, 버전 등
# podman pull URL /rhel8/httpd-24
# podman images
# podman rmf URL /rhel8/httpd-24

35)	컨테이너 실행 - 컨테이너에 영구저장장치 연결
# mkdir -p ~/webcontent/html
# echo “test” > ~/webcontent/html/index.html
# podman login URL
# podman run -d - -name myweb -p 8080:8080 -v ~/webcontent:/var/www:Z URL/rhel8/httpd-24:1-98
# curl http://localhost:8080
# podman stop myweb
# podman rm myweb

36)	컨테이너 실행 - 컨테이너를 서비스로 관리 (rootless 컨테이너)
# sudo -i
# useradd consvc
# passwd consvc
# ssh consvc@servera
podman ps 를 확인 후 실행하고 있어야 함
# mkdir ~/.config/systemd/user
# cd ~/.config/systemd/user
# podman generate systemd --name myweb --files - -new
# podman stop myweb
# podman rm myweb
# systemctl - -user daemon-reload
# systemctl - -user enable - -now container-myweb
# loginctl enable-linger          // 서버 시작과 함께
# loginctl show-user contsvc      // 확인

37)	컨테이너 실행 - 고급 컨테이너 관리 수행
# podman login URL
# skopeo inspect docker://URL /rhel8/mariadb-103
# podman run -d ~~~~~ MYSQL_ROOT_PASSWORD=redhat
# podman ps
# mysql -u user1 -p - -port=3306 --host=127.0.0.1
$ show databases;

38)	컨테이너 실행 (mariadb)
# sudo yum module install container-tools
# podman login URL
# skopeo inspect docker:// URL /rhel8/mariadb-103
# mkdir /home/podsvc/db_data
# chmod 777 /home/podsvc/db_data
# ponman run -d --name inventorydb -p 13306:3306 -v /home/podsvc/db_data:/var/lib/mysql/data:Z -e ~~~ 붙여넣기
USER 설정 (pod 실행 된 상태에서)
# mkdir -p ~/.config/systemd/usr
# cd ~/.config/systemd/usr
# podman generate systemd - -name inventorydb - -files - -new
# podman stop inventory
# podman rm  inventory
# systemctl - -user daemon-reload
# systemctl - -user enable - -now container-inventory.service
# podman ps
# loginctl enable-linger
# loginctl show-user podsvc

-------------------------------------------------------------
podman login - register 로그인
podman search - 검색
podman pull - 이미지 다운로드
podman info - 이미지 정보
podman images - 로컬 이미지 리스트
podman run - 이미지 실행
podman rm - 이미지 실행한것 종료
podman rmi - 로컬 이미지 삭제
skopeo inspect 원격or로컬 이미지 검사
podman inspect 로컬이미지 검사

podman run -d --name 이름지정 -e MYSQL방법 -p 포트 레지스트리주소

podman run -d -p 호스트포트:컨테이너포트 이미지
firewall-cmd --permanent --add-port=8000/tcp
firewall-cmd –reload
