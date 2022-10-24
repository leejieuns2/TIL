31)	고급 스토리지 기능 구현 - vdo (빈 파일시스템에다 만들어야하므로 하위 냅두기)
# yum install -y vdo kmod-kvdo
$ yum install *vdo* -y
# systemctl enable --now vdo
# vdo create - -name=vdoubh - -device=/dev/vdb - -vdoLogicalSize=20G
wipefs -af /dev/sdb
# vdo list
# vdo status -n vdough | grep “LogicalSize”
# vdostats - -human-readable
/dev/mapper/vdough
# mkfs.xfs -K /dev/mapper/vdough    (-K옵션: 빠르게 포맷)
# udevadm settle
# mkdir /vdough
# vim /etc/fstab
/dev/mapper/vdough		/vdough	xfs	defaults, x-systemd.requires=vdo.service 0 0
# mount -a

#vdo remove --name=vdo01
