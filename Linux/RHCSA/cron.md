## 📌 cron
- 반복 실행 작업은 /etc/crontab과 /etc/cron.d/ 디렉터리 내 파일들에서 정의됨.
- /etc/cron.hourly/ /etc/cron.daily/ /etc/cron.weekly/ /etc/cron.monthly/ 에도 스크립트 포함되어 있음. (각각 매시간, 매일, 매주, 매월 실행해야 하는 스크립트 저장됨.)

> 💡 /etc/crontab 주석에 있는 구문 다이어그램

** TODO: 추후 추가

-----------------------------------------------------------
매분 실행 : * * * * *
매주 일요일 오전 0시 0분에 실행 : 0 0 * * 0
매일, 매시간, 0분, 20분, 40분에 실행 : 0,20,40 * * * *
매일 1시 0분부터 30분까지 매분 실행 : 0-30, 1 * * *
매 10분마다 실행 : */10 * * * *
-----------------------------------------------------------

<br>

## 📌 cron 작업 생성 및 확인
```shell
$ su - (user)
$ crontab -e
23 14 * * * echo hello > /tmp/a.txt
$ crontab -l //crontab -r (remove)

$ crontab -el peter
23 14 * * * /bin/echo hiya
$ crontab -ul peter

$ systemctl restart crond
$ systemctl enable crond
$ su - root
$ cd /var/spool/cron
$ ls (user check!)

$ systemctl enable crond
$ crontab -u natash -e
*/2 * * * * logger RH199 exam 
$ crontab -l (natash 계정으로)

```

<br>

## 📌 Systemd 타이머
- 타이머 장치를 사용하면 다른 장치를 타이머 기반으로 활성화 가능.
- 편리한 디버깅을 위해 systemd는 시스템 저널에 타이머 이벤트를 기록함.