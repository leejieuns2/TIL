## 📌 Selinux
  - Security Enhanced Linux의 약자로 소스코드가 공개되어 있기 때문에 보안에 취약한 리눅스의 시스템 액세스 권한을 제어하기 위해
미국 국가안보국 (NAS)에서 개발한 보안 아키텍쳐
  - 사용자의 편리성과 보안은 반비례하여 보안을 강화하면 편리성이 감소하고, 보안이 취약해지면 사용자의 편리성이 증가한다.

## 📌 Selinux 동작 모드
1. Enforcing
   - SELinux의 기본값으로 활성화되어 보안 정책이 실행되어 로그 기록과 보호를 모두 수행하는 상태
2. Permissive
   - SELinux가 보안 정책에 대하여 로그는 기록하지만 실제 차단하지 않는 상태
3. Disabled
   - SELinux를 비활성화하여 동작하지 않도록 함.

## 📌 Selinux 상태 확인
```shell
$ sestatus
SELinux status:                 disabled

$ getenforce
Disabled
```

## 📌 Selinux 모드 변경
```shell
### 일시 적용
### (주의) setenforce 명령어로 변경한 동작모드는 재부팅을 수행하면 초기화됨.
$ setenforce [Enforcing | Permissive | 1 | 0]
$ setenforce 1
$ getenforce
Enforcing

### 영구 적용 (적용 후 reboot 필요)
$ vi /etc/selinux/config
SELINUX=enforcing
$ reboot
```

## 📌 부팅 시 SELinux 모드 변경
1. 부팅 파라미터 추가
- `enforcing=0` : 이 매개 변수를 설정하면 시스템이 허용 모드로 시작되므로 문제를 해결할 때 유용.
  파일 시스템이 너무 손상된 경우 허용 모드를 사용하는 것이 문제를 감지하는 유일한 옵션일 수 있습니다. 또한 허용 모드에서 시스템은 라벨을 올바르게 만듭니다.

- `selinux=0` : 이 매개 변수를 사용하면 커널이 SELinux 인프라의 일부를 로드하지 않음. 
  init 스크립트는 시스템이 selinux=0 매개 변수로 부팅되었으며 /.autorelabel 파일을 생성합니다. 이로 인해 SELinux를 활성화한 다음 부팅할 때 시스템이 자동으로 레이블을 다시 지정.

2. autorelabel
8)	selinux 디버깅 (포트 추가하여 다시 enforcing으로 변경)

# vi /var/log/audit/audit.log
# semanage port -l | grep http_port_t
# semanage port -a -t http_port_t -p tcp 82
# systemctl restart httpd
# systemctl enable httpd

$ firewall-cmd –-add-port=82/tcp –permanent
$ firewall-cmd --reload
$ firewall-cmd --list-all
firewalld가 enable인지 확인
재부팅했는데 httpd 실행되고 있는지 확인
===============================================================
새 웹을 구성 80/TCP, 1001/TCP 수신대기
ssh 액세스를 위해 포트 22/TCP 도 사용하고 재부팅해도 유지

workstation에서 http://serverb.lab.example.com 에 있는 기본 웹서버 및
http://serverb.lab.example.com:1001 가상호스트 액세스 권한 테스트

$ curl http://serverb.lab.example.com
$ curl http://server.lac.example.com:1001
→ 실패

$ ssh student@serverb
$ sudo -i
yum install httpd* -y
exit

$ systemctl status httpd
$ systemctl enable --now httpd 	→ 에러 발생

$ sudo -i
root 계정으로
$ semanage port -a -t http_port_t -p tcp 1001  ( → 1001/TCP 포트를 http_port_t유형에 바인딩)
$ semanage port -l | grep http_port_t
$ systemctl enable --now httpd
exit

workstation에서 권한 테스트
$ curl http://serverb.lab.example.com  → 성공
$ curl http://serverb.lab.example.com:1001 → 실패

ssh student@serverb
$ firewall-cmd -–get-default-zone 	→ public(공개)

sudo -i : root 로 전환
$ firewall-cmd –permanent --zone=public --add-port=1001/tcp
$ firewall-cmd --reload

workstation에서 권한 테스트
$ curl http://serverb.lab.example.com
$ curl http://serverb.lab.example.com:1001

__
9)	SELinux 파일 컨텍스트 제어
# mkdir /custom
# vi /custom/index.html
# vi /ect/httpd/conf/httpd.conf
Diretory DocumentRoot /custom으로 변경
# systemctl enable - -now httpd
# curl http://servera/index.html
# semanage fcontext -a -t httpd_sys_content_t ‘/custom(/.*)?’
man semanage fcontext 하면 위에 구문 그대로 있음
# restorecon -Rv /custom
$ http://servera/index.html 방문해서 “This is SERVERA” 메시지 정상 출력 확인
