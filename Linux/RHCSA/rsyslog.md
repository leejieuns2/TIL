## 📌 System Logging
- 대부분의 시스템들은 /var/log에 이벤트 로그를 기록
- Syslog 프로토콜 기반의 표준 로깅 시스템 : `systemd-journaid`, `rsyslog`

1. systemd-journald
   - 운영 체제 이벤트 로깅 아키텍쳐의 핵심
   - 커널, 부팅 프로세스 초기 단계의 출력, 시작 및 실행 시 데몬의 표준 출력 및 표준 오류, syslog 이벤트를 포함하는 많은 리소스에서 Log 수집.
   - 재부팅 후 유지되지 않는 파일 시스템에 저장됨.
    
2. rsyslog
   - systemd-journald에서 받은 syslog 메세지를 읽어 이벤트를 처리하고, 로그 파일에 기록하거나 자체 구성에 따라 다른 서비스에 전달.
   - /var/log에서 재부팅 시 지속되는 로그 파일에 syslog 메세지를 정렬하고, 각 syslog 메세지의 우선 순위로 로그 메세지를 정렬함.

## 📌 System Log files
- `/var/log/messages`
  - 대부분의 syslog 메세지가 여기에 기록됨. 다만 인증 및 이메일 처리와 관련된 메세지, 예약된 작업 실행 및 순수하게 디버깅에 관련한 메세지는 예외.
- `/var/log/secure`
  - 보안 및 인증 이벤트와 관련된 syslog 메세지
- `/var/log/maillog`
  - 메일 서버와 관련된 Syslog 메세지
- `/var/log/cron`
  - 예약된 작업 실행과 관련된 Syslog 메세지
- `/var/log/boot.log`
  - 시스템 시작과 관련된 비 Syslog 콘솔 메세지
    
## 📌 rsyslog
1. 표준 syslog 우선 순위
| code | 우선순위 | 심각도 |
|------|--------|---------|
| 0 | emerg | 시스템을 사용할 수 없음|
| 1 | alert | 즉각적인 조치 필요 | 
| 2 | crit | 심각한 상태 | 
| 3 | err | 심각하지 않은 오류 상태 | 
| 4 | warning | 경고 상태 | 
| 5 | notice | 정상이지만 중요한 이벤트 | 
| 6 | info | 정보 이벤트 |
| 7 | debug | 디버깅 수준의 메시지 |
 
2. 규칙 설정 및 확인
- /etc/rsyslog.conf
- /etc/rsyslog.d 디렉터리의 .conf 파일들
- 소프트웨어 패키지들은 /etc/rsyslog.d 디렉터리에 파일을 설치하여 규칙 추가 가능.
- 규칙 설정 방법
    [service name].*    [file path]
  ex) authpriv.*        /var/log/secure
  --> authpriv 기능에 전송된 모든 메세지를 /var/log/secure에 기록
  
- *(와일드카드)는 모든 값 의미, none은 지정된 기능에 대한 메세지는 저장X
    ex) mail.none은 mail과 관련한 메세지는 해당 파일에 저장하지 않는다는 의미
  
3. Rsyslog 규칙의 예
```shell 
### 추후 추가

```

4. 수동으로 syslog 메세지 보내기
- -p 옵션을 주면 우선순위를 지정한 서비스에 메세지를 전송할 수 있음.
- rsyslog 서비스로 메세지를 전송할 때 변경사항을 테스트하기 유용한 명령어

```shell 
$ logger -p [보내려는 서비스 이름] [로그 내용]
$ logger -p local7.notice "Log entry created on host"
```

```shell

### rsyslog 규칙 추가
$ vi /etc/rsyslog.d
$ touch debug.conf
*.debug /var/log/message-debug

$ systemctl restart rsyslog

### 변경 사항 테스트
$ logger -p test.debug "Debug Message Test"
$ tail /var/log/message-debug

```