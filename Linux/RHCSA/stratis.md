32)	고급 스토리지 기능 구현 - stratis
# yum install startisd stratis-cli
$ yum install strati* -y
# systemctl enable --now stsratisd
# stratis pool create pool1 /dev/vdb
# stratis pool list
# stratis pool add-data pool1 /dev/vdc ( stratis pool add-data 풀이름 /dev/vdc , 용량증설)
# stratis pool list  // 숫자가 증가함
# stratis blockdev list
# stratis filesystem create pool1 filesystem1
# mkdir /vol1
# mount /stratis/stratispool1/stratisfilesytem1 /vol1
# stratis filesystem list pool1

# stratis filesystem snapshot pool1 filesystem1 snapshot1
# lsblk - -output=UUID  /stratis/stratispool1/stratisfilesytem1
# vim /etc/fstab (UUID 적어도됨)
/staratis/pool1/filesystem1	/dir1	xfs	defaults, x-systemd.requires=stratisd.service 0 0
# mount -a
