28)	autofs
       mount	-t nfs	serverb.lab.example:/shares/public	/public
-	2G짜리 임의파일 만들기
     dd if=/dev/urandom of=/stratisvol/file2 bs=1M count=2048

추가) stratis 파일시스템에 labfs에 2G의 파일을 만들어라
$ dd if=/dev/urandom of=/labstratisvol/labfile2 bs=1M count=2048
bs=1M 블락사이즈 count=2048 이니까 2G
=====================================================================
# yum install -y autofs
# mount -t nfs serverb.lab.~~~ :/shares/direct/…external /mnt           // test
-	autouser 사용자가 로그인하면 /exports/home 디렉터리 아래 자신의 홈 디렉터리에 접근되도록 설정, autouser는 자신의 홈 디렉터리에 파일 쓰기 가능

vim /etc/auto.master.d/direct.autofs
-> /- /etc/auto.direct
vim /etc/auto.direct
=> /exports/home -rw,sync,fstype=nfs4 serverb:/exports/home/autousers

demo.autofs +  auto.demo=> /shares/* -rw,sync,fstype=nfs4 serverb:/shares/&
-	serverb 는 NFS 공유로 west, central, east 하위 디렉터리가 차례로 포함된 /shares/indirect 디렉터리를 내보냄,
     → /shares/indirect/west, central, east -> /internal에 간접 매핑해서 자동마운트
     serverb 는 NFS 공유로 /shares/direct/external 디렉터리를 내보냄
     → /shares/direct/external -> /external에 직접 매핑해서 자동마운트

servera의 operators 그룹은 /shares/indirect/west, central, east 에 대한 읽기/쓰기 권한 있음
servera의 contrators 그룹은 /shares/direct/external 에 대한 읽기/쓰기 권한 있음
servera의 마운트 지점은 /external , /internal

$ mount -t nfs serverb.lab.example.com:/shares/direct/external /mnt
$ ls -l /mnt
$ umount /mnt

$ yum install *autofs* -y
$ systemctl enable --now autofs

$ vim /etc/auto.master.d/direct.autofs
/- /etc/auto.direct
$ vim /etc/auto.direct
/external -rw,sync,fstype=nfs4 serverb.lab.example.com:/shares/direct/external
